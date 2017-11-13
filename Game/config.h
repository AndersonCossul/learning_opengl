#ifndef HELPER_H
#define HELPER_H

#include <GLFW/glfw3.h>

GLFWwindow* getWindow();

void initAll();

void initGLFW();

int createWindow();

int initGlad();

void setViewport();

void setCallBacks();

void createAndLinkShaders();

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void finishGLFW();

#endif