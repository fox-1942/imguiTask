//
// Created by Foxx on 2020. 12. 22..
//

#ifndef IMGUITASK_INIT_H
#define IMGUITASK_INIT_H

#include "ImGuiFileBrowser.h"

imgui_addons::ImGuiFileBrowser fileDialog;
ImVec4 red = ImColor::HSV(0.0f, 1.0f, 1.0f, 1.0f);
ImVec4 green = ImColor::HSV(0.382f, 1.0f, 1.0f, 1.0f);
ImVec4 blue = ImColor::HSV(0.520f, 1.0f, 1.0f, 1.0f);
ImVec4 cyan = ImColor::HSV(0.5, 1.0f, 1.0f,1.0f);
ImVec4 magenta = ImColor::HSV(0.838f, 1.0f, 1.0f, 1.0f);
ImVec4 yellow = ImColor::HSV(0.162f, 1.0f, 1.0f,1.0f);

unsigned char *imageData(0);
int imageWidth(0);
int imageHeight(0);
GLuint imageTexture(0);

ImVec2 mousePosInCanvas(0, 0);
ImVec4 color = ImVec4(0.5f, 0.5f, 0.5f, 0.0f);
ImVec4 *selectedColor;
bool clicked = false;
bool disabled = false;
bool opened=false;
bool ret=false;
std::string filePath;

#endif //IMGUITASK_INIT_H
