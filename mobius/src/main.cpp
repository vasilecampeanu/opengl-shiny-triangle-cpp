#include <iostream>

// GLAD must be included before GLFW
// Include GLAD to get all the required OpenGL headers
#include <glad/glad.h>

// Inlcude GLFW for window creation and input handling
#include <GLFW/glfw3.h>

#ifdef __APPLE__
// This is required for MacOS to prevent deprecation warnings
#define GL_SILENCE_DEPRECATION
#endif

void initializeGLFW();
void setWindowHints();
void initalizeGLAD();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main(int argc, char* argv[]) 
{
    // GLFW: initialize and configure
    initializeGLFW();
    setWindowHints();

    // GLFW: Window creation
    GLFWwindow* window = glfwCreateWindow(640, 480, "Mobius 3D CPP", nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        std::cerr << "Failed to create GLFW window!" << std::endl;
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // GLAD: load all OpenGL function pointers
    initalizeGLAD();

    while (!glfwWindowShouldClose(window)) {
        // Input
        processInput(window);

        //region Render

        glClearColor(0.113f, 0.631f, 0.949f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //endregion
        
        // GLFW: Swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // GLFW: terminate, clearing all previously allocated GLFW resources.
    glfwDestroyWindow(window);
    glfwTerminate();

    return EXIT_SUCCESS;
}

void initializeGLFW() 
{
    // Initialize GLFW library
    int success = glfwInit();

    if (!success) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void setWindowHints()
{
    // Set the OpenGL version to 4.1 the latest version supported by MacOS
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    // Set the profile to core
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
    // Forward compatibility with MacOS
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
}

void initalizeGLAD() 
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        exit(EXIT_FAILURE);
    }
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}
