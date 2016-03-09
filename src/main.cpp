#ifdef _WIN32

#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "GlU32.Lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glfw3.lib")

#endif

#include <stdlib.h>
#include <GL/glfw3.h>

GLubyte	*PixelData = NULL;          // Pointer to bits
const int image_width = 100;
const int image_height = 100;

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(480, 320, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	PixelData = (GLubyte*)malloc(image_width * image_height * 3 * sizeof(GLubyte));

	for (int i = 0; i < image_height; i++)
		for (int j = 0; j < image_width; j++)
		{
		PixelData[(i*image_width + j) * 3] = 0;
		PixelData[(i*image_width + j) * 3 + 1] = 0;
		PixelData[(i*image_width + j) * 3 + 2] = 0;
		}

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		/* Draw a triangle */
		glBegin(GL_TRIANGLES);

		glColor3f(1.0, 0.0, 0.0);    // Red
		glVertex3f(0.0, 1.0, 0.0);

		glColor3f(0.0, 1.0, 0.0);    // Green
		glVertex3f(-1.0, -1.0, 0.0);

		glColor3f(0.0, 0.0, 1.0);    // Blue
		glVertex3f(1.0, -1.0, 0.0);

		glEnd();

		glDrawPixels(image_width, image_height, GL_RGB, GL_UNSIGNED_BYTE, PixelData);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}