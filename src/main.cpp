#include <gl3w.h>
#include <iostream>
#include <glfw3.h>
#include "imgui.h"
#include <imgui_internal.h>

#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "stdio.h"
#include "GLFW/glfw3.h"

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

static void glfw_error_callback(int error, const char *description) {
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

bool LoadTextureFromFile(const char *filename, GLuint *out_texture, int *out_width, int *out_height) {

    // Reading the image into a GL_TEXTURE_2D
    int image_width = 0;
    int image_height = 0;
    unsigned char *image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
        return false;

    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    stbi_image_free(image_data);
    glBindTexture(GL_TEXTURE_2D, 0);

    *out_texture = image_texture;
    *out_width = image_width;
    *out_height = image_height;

    return true;
}

ImVec4 readPixelFromImage(ImVec2 mousePosition) {
    int imageWidth(0);
    int imageHeight(0);
    unsigned char *image_data = stbi_load("../lena.jpg", &imageWidth, &imageHeight, NULL, 4);
    unsigned char *pixels = image_data + (int(mousePosition.y) * imageWidth * 4) + (int(mousePosition.x) * 4);

    return ImVec4(static_cast<int>(pixels[0]) / 255.0f, static_cast<int>(pixels[1]) / 255.0f,
                  static_cast<int>(pixels[2]) / 255.0f,
                  static_cast<int>(pixels[3]) / 255.0f);
}

int main() {

    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


    // Window creation
    GLFWwindow *window = glfwCreateWindow(1280, 1000, "ImGui Task for Grand Color Central", NULL, NULL);
    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    if (gl3wInit() != 0) {
        fprintf(stderr, "Failed to initialize OpenGL loader!\n");
        return 1;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void) io;


    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 460");
    ImVec4 clear_color = ImVec4(30.0f/255.0f, 144.0f/255.0f, 200.0f/255.0f, 1.00f);


    // Loading image
    int imageWidth(0);
    int imageHeight(0);
    GLuint image(0);
    bool ret = LoadTextureFromFile("../lena.jpg", &image, &imageWidth, &imageHeight);
    IM_ASSERT(ret);

    // Declaring dimensions and some vectors

    ImVec2 mouse_pos_in_canvas(0, 0);
    ImVec4 color = ImVec4(0.5f,  0.5f,  0.5f,  0.0f);
    bool clicked = false;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::SetNextWindowSize(ImVec2(530,700),ImGuiCond_Always);
        ImGui::Begin("Color Picker for image");

        ImVec2 canvas_p0 = ImGui::GetCursorScreenPos();

        ImGui::Image((void *) (intptr_t) image, ImVec2(imageWidth, imageHeight));

        // Creating invisible canvas before the loaded image
        ImVec2 canvas_p1 = ImVec2(canvas_p0.x + imageWidth, canvas_p0.y + imageHeight);

        ImGuiIO &io = ImGui::GetIO();
        ImDrawList *draw_list = ImGui::GetWindowDrawList();
        draw_list->AddRectFilled(canvas_p0, canvas_p1, IM_COL32(50, 50, 50, 0));

        bool is_hovered = ImGui::IsItemHovered();

        draw_list->PushClipRect(canvas_p0, canvas_p1, true);
        if (is_hovered && ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {
            mouse_pos_in_canvas = ImVec2(io.MousePos.x - canvas_p0.x, io.MousePos.y - canvas_p0.y);
            color = readPixelFromImage(mouse_pos_in_canvas);
            clicked = true;
        }

        if (clicked) {
            float diff=30;

            ImVec2 startingPoint_H=ImVec2(canvas_p0.x + mouse_pos_in_canvas.x-diff,canvas_p0.y + mouse_pos_in_canvas.y );
            ImVec2 endingPoint_H=ImVec2(canvas_p0.x + mouse_pos_in_canvas.x+diff,canvas_p0.y + mouse_pos_in_canvas.y );
            draw_list->AddLine(startingPoint_H,endingPoint_H,IM_COL32(0, 100, 0, 100),5);

            ImVec2 startingPoint_V=ImVec2(canvas_p0.x + mouse_pos_in_canvas.x,canvas_p0.y + mouse_pos_in_canvas.y-diff );
            ImVec2 endingPoint_V=ImVec2(canvas_p0.x + mouse_pos_in_canvas.x,canvas_p0.y + mouse_pos_in_canvas.y+diff );
            draw_list->AddLine(startingPoint_V,endingPoint_V,IM_COL32(0, 100, 0, 100),5);

        }
        draw_list->PopClipRect();
        ImGui::Dummy(ImVec2(0.0f, 20.0f));
        ImGui::Text("Sampled Color:");

        ImGui::ColorButton("Sampled color", color,ImGuiColorEditFlags_AlphaPreview , ImVec2(87, 87));

        ImGui::SameLine();
        ImGui::BeginGroup();
        ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
           ImGui::SliderFloat("Red", &color.x, 0.0f, 1.0f, "%.1f");
            ImGui::SliderFloat("Green ", &color.y, 0.0f, 1.0f, "%.1f" );
            ImGui::SliderFloat("Blue", &color.z, 0.0f, 1.0f, "%.1f" );
            ImGui::SliderFloat("Alpha", &color.w, 0.0f, 1.0f, "%.1f");
        ImGui::PopItemFlag();
        ImGui::EndGroup();

       /* ImGui::Text("Mouse pos in canvas: (%g, %g)", mouse_pos_in_canvas.x, mouse_pos_in_canvas.y);
        ImGui::Text("Mouse pos in screen: (%g, %g)", io.MousePos.x, io.MousePos.y);*/




//----------------------------------------------------------------------------------------
        ImGui::End();

        ImGui::SetNextWindowSize(ImVec2(530,700),ImGuiCond_Always);
        ImGui::Begin("Color mixer");

        static int e = 0;

        ImGui::Dummy(ImVec2(0.0, 20.0f));
        ImGui::Indent(15.0f);
        ImGui::BeginGroup();
        ImGui::RadioButton(" ###1", &e, 0); ImGui::SameLine();
        ImGui::RadioButton(" ###2", &e, 1); ImGui::SameLine();
        ImGui::RadioButton(" ###3", &e, 2); ImGui::SameLine();
        ImGui::RadioButton(" ###4", &e, 3); ImGui::SameLine();
        ImGui::RadioButton(" ###5", &e, 4); ImGui::SameLine();
        ImGui::RadioButton(" ###6", &e, 5);
        ImGui::EndGroup();





        ImGui::End();


        ImGui::Render();

        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}