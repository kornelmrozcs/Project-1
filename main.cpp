#include<iostream>
#include<glad/glad.h> 
#include<GLFW/glfw3.h> 

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main()
{
	std::cout << "Hello \n";
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // OpenGL version
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Profile

	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window\n";
		glfwTerminate();
		return 10;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD\n";
		return 11;
	}
	
	glViewport(0, 0, 800, 600); //x = 0, y = 0, width = 800, height = 600
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// Render Loop
	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();


	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
