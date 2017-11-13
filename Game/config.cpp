#include <iostream>
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include "config.h"
#include "shader.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
GLFWwindow* window;

GLFWwindow* getWindow()
{
	return window;
}



void initAll()
{
	initGLFW();
	createWindow();
	initGlad();
	setViewport();
	setCallBacks();
	createAndLinkShaders();
}

void initGLFW()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

int createWindow()
{
	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
}

int initGlad()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
}

void setViewport()
{
	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
}

void setCallBacks()
{
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void createAndLinkShaders()
{
	Shader ourShader("3.3.shader.vs", "3.3.shader.fs");
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void finishGLFW()
{
	glfwTerminate();
}