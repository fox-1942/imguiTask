//
// Created by Foxx on 2020. 12. 22..
//

#ifndef IMGUITASK_INIT_H
#define IMGUITASK_INIT_H


ImVec4 red = ImColor::HSV(0.0f, 1.0f, 1.0f, 1.0f);
ImVec4 green = ImColor::HSV(0.382f, 1.0f, 1.0f, 1.0f);
ImVec4 blue = ImColor::HSV(0.520f, 1.0f, 1.0f, 1.0f);
ImVec4 cyan = ImColor::HSV(0.5, 1.0f, 1.0f,1.0f);
ImVec4 magenta = ImColor::HSV(0.838f, 1.0f, 1.0f, 1.0f);
ImVec4 yellow = ImColor::HSV(0.162f, 1.0f, 1.0f,1.0f);

int imageWidth(0), eyeImageWidth(0);
int imageHeight(0), eyeImageHeight(0);
GLuint image(0), eye_image(0);

ImVec2 mouse_pos_in_canvas(0, 0);
ImVec4 color = ImVec4(0.5f, 0.5f, 0.5f, 0.0f);
ImVec4 *selectedColor;
bool clicked = false;
bool clicked2=false;
bool disabled = false;
bool is_hovered2=false;

#endif //IMGUITASK_INIT_H
