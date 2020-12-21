#include <gl3w.h>
#include <iostream>
#include "imgui.h"
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

void readPixelFromImage(ImVec2 mousePosition) {
    int imageWidth(0);
    int imageHeight(0);

    unsigned char*image_data = stbi_load("../foo.png", &imageWidth, &imageHeight, NULL, 4);

    unsigned char* pixels = image_data +( int(mousePosition.y) * imageWidth * 4 )+ (int(mousePosition.x) * 4);

    std::cout << "r: " << static_cast<int>(pixels[0]) << '\n';
    std::cout << "g: " << static_cast<int>(pixels[1]) << '\n';
    std::cout << "b: " << static_cast<int>(pixels[2]) << '\n';
    std::cout << "a: " << static_cast<int>(pixels[3]) << '\n' << std::endl;
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
    GLFWwindow *window = glfwCreateWindow(1280, 720, "ImGui Task for Grand Color Central", NULL, NULL);
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

    ImGui::StyleColorsLight();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 460");
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Loading image
    int imageWidth(0);
    int imageHeight(0);
    GLuint image(0);
    bool ret = LoadTextureFromFile("../foo.png", &image, &imageWidth, &imageHeight);
    IM_ASSERT(ret);

    // Declaring dimensions and some vectors

    ImVec2 canvas_sz = ImVec2(imageWidth, imageHeight);
    ImVec2 origin(0, 0);
    ImVec2 mouse_pos_in_canvas(0, 0);


    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("OpenGL Texture Text");

        ImVec2 canvas_p0(ImGui::GetCursorScreenPos().x,
                         ImGui::GetCursorScreenPos().y);

        ImGuiIO &io = ImGui::GetIO();

        ImGui::Image((void *) (intptr_t) image, ImVec2(imageWidth, imageHeight));
        const bool is_hovered = ImGui::IsItemHovered();

        ImGui::Text("Sampled Color:");
        static ImVec4 color = ImVec4(114.0f / 255.0f, 144.0f / 255.0f, 154.0f / 255.0f, 200.0f / 255.0f);
        ImGui::ColorButton("MyColor##3c", color, 0, ImVec2(80, 80));


        origin = ImVec2(canvas_p0.x, canvas_p0.y);

        // Add first and second point
        if (is_hovered && ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {
            mouse_pos_in_canvas = ImVec2(io.MousePos.x - origin.x, io.MousePos.y - origin.y);
           readPixelFromImage(mouse_pos_in_canvas);
        }

        ImGui::Text("Mouse pos in canvas: (%g, %g)", mouse_pos_in_canvas.x, mouse_pos_in_canvas.y);
        ImGui::Text("Mouse pos in screen: (%g, %g)", io.MousePos.x, io.MousePos.y);


//----------------------------------------------------------------------------------------

        ImGui::End();

        // Rendering
        ImGui::Render();
        int display_w(0);
        int display_h(0);
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
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
