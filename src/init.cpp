/*
 * Copyright: Tamás Boros 2020
 *
 * */

#include <gl3w.h>
#include <glfw3.h>
#include "imgui.h"
#include <imgui_internal.h>
#include <iostream>
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "stdio.h"
#include "init.h"


#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

static void glfw_error_callback(int error, const char *description) {
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}


void showMainMenu()
{
    bool open = false, save = false;
    if(ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("Menu"))
        {
            if (ImGui::MenuItem("Open", NULL))
                open = true;
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }

    if(open)
        ImGui::OpenPopup("Open File");


    if(file_dialog.showFileDialog("Open File", imgui_addons::ImGuiFileBrowser::DialogMode::OPEN, ImVec2(700, 310), ".jpg,.png"))
    {
      /*  std::cout << file_dialog.selected_fn << std::endl;
        std::cout << file_dialog.selected_path << std::endl;*/

        filePath=file_dialog.selected_path;
        std::cout << filePath << std::endl;
        opened=true;
    }
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
    unsigned char *image_data = stbi_load(filePath.data(), &imageWidth, &imageHeight, NULL, 4);
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
    GLFWwindow *window = glfwCreateWindow(1280, 1000, "ImGui Task for Color Granding Central - Tamás Boros", NULL, NULL);
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
    ImVec4 clear_color = ImVec4(30.0f / 255.0f, 144.0f / 255.0f, 200.0f / 255.0f, 1.00f);

    // Loading images


    while (!glfwWindowShouldClose(window)) {
        if(opened) {
            ret = LoadTextureFromFile(filePath.data(), &image, &imageWidth, &imageHeight);
            IM_ASSERT(ret);
            opened=false;
        }

        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();


        ImGui::NewFrame();
        ImGui::SetNextWindowSize(ImVec2(530, 700), ImGuiCond_Always);

        showMainMenu();

        ImGui::Begin("Color Picker for image");


        if(ret) {

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
                float diff = 30;

                ImVec2 startingPoint_H = ImVec2(canvas_p0.x + mouse_pos_in_canvas.x - diff,
                                                canvas_p0.y + mouse_pos_in_canvas.y);
                ImVec2 endingPoint_H = ImVec2(canvas_p0.x + mouse_pos_in_canvas.x + diff,
                                              canvas_p0.y + mouse_pos_in_canvas.y);
                draw_list->AddLine(startingPoint_H, endingPoint_H, IM_COL32(0, 100, 0, 100), 5);

                ImVec2 startingPoint_V = ImVec2(canvas_p0.x + mouse_pos_in_canvas.x,
                                                canvas_p0.y + mouse_pos_in_canvas.y - diff);
                ImVec2 endingPoint_V = ImVec2(canvas_p0.x + mouse_pos_in_canvas.x,
                                              canvas_p0.y + mouse_pos_in_canvas.y + diff);
                draw_list->AddLine(startingPoint_V, endingPoint_V, IM_COL32(0, 100, 0, 100), 5);

            }
            draw_list->PopClipRect();

        }
            ImGui::Dummy(ImVec2(0.0f, 20.0f));
            ImGui::Text("Sampled Color:");

            ImGui::ColorButton("Sampled color", color, ImGuiColorEditFlags_AlphaPreview, ImVec2(87, 87));

            ImGui::SameLine();
            ImGui::BeginGroup();
            ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
            ImGui::SliderFloat("Red", &color.x, -180.0f, 18.0f, "%.1f");
            ImGui::SliderFloat("Green ", &color.y, -100.0f, 100.0f, "%.1f");
            ImGui::SliderFloat("Blue", &color.z, -100.0f, 100.0f, "%.1f");
            ImGui::SliderFloat("Alpha", &color.w, 0.0f, 1.0f, "%.1f");
            ImGui::PopItemFlag();
            ImGui::EndGroup();

        ImGui::End();




        ImGui::SetNextWindowSize(ImVec2(400, 390), ImGuiCond_Always);
        ImGui::Begin("Vectors");

        ImGui::Indent(100.0f);
        ImGui::Checkbox("Disable mixer###343", &disabled);

        if (disabled)
        {
            ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
            ImGui::PushStyleVar(ImGuiStyleVar_Alpha, ImGui::GetStyle().Alpha * 0.5f);
        }

        ImGui::Dummy(ImVec2(0.0, 20.0f));
        ImGui::Indent(-50.0f);
        ImGui::BeginGroup();

        static int e = 1;
        ImGui::RadioButton(" ###1", &e, 0, ImGui::GetColorU32(red));
        ImGui::SameLine();
        ImGui::RadioButton(" ###2", &e, 1, ImGui::GetColorU32(green));
        ImGui::SameLine();
        ImGui::RadioButton(" ###3", &e, 2, ImGui::GetColorU32(blue));
        ImGui::SameLine();
        ImGui::RadioButton(" ###4", &e, 3,ImGui::GetColorU32(cyan));
        ImGui::SameLine();
        ImGui::RadioButton(" ###5", &e, 4, ImGui::GetColorU32(magenta));
        ImGui::SameLine();
        ImGui::RadioButton(" ###6", &e, 5,ImGui::GetColorU32( yellow));
        ImGui::EndGroup();
        ImGui::Dummy(ImVec2(0.0, 10.0f));

        switch (e) {
            case 0:
                selectedColor = &red;
                break;
            case 1:
                selectedColor = &green;
                break;
            case 2:
                selectedColor =& blue;
                break;
            case 3:
                selectedColor = &cyan;
                break;
            case 4:
                selectedColor =& magenta;
                break;
            case 5:
                selectedColor =& yellow;
                break;
        }

        ImGui::Indent(-30.0f);
        ImGui::BeginGroup();
        ImGui::SliderFloat("Hue", &selectedColor->x, -180.0f, 180.0f, "%.1f");
        ImGui::SliderFloat("Saturation", &selectedColor->y, -100.0f, 100.0f, "%.1f");
        ImGui::SliderFloat("Luma", &selectedColor->z, -100, 100.0f, "%.1f");
        ImGui::EndGroup();


        ImGui::Dummy(ImVec2(0.0, 20.0f));
        if ( ImGui::Button("Reset")) {
            red = ImColor::HSV(0.0f, 1.0f, 1.0f, 1.0f);
            green = ImColor::HSV(0.382f, 1.0f, 1.0f, 1.0f);
            blue = ImColor::HSV(0.520f, 1.0f, 1.0f, 1.0f);
            cyan = ImColor::HSV(0.5, 1.0f, 1.0f);
            magenta = ImColor::HSV(0.838f, 1.0f, 1.0f);
            yellow = ImColor::HSV(0.162f, 1.0f, 1.0f);
        }


        if (disabled)
        {
            ImGui::PopItemFlag();
            ImGui::PopStyleVar();
        }







        ImGui::Dummy(ImVec2(0.0, 20.0f));
        ImGui::Text("HSV sliders issue information about ImGUI's HSL/RGB\n problem:\n https://github.com/ocornut/imgui/issues/2722");

        ImGui::Dummy(ImVec2(0.0, 20.0f));
        ImGui::Text("Tamás Boros - 2020");


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