#include <memory.h>
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

const int MAX_KEYS = 1024;

struct window
{
    GLFWwindow *glfw_window; 
    bool pressed[ MAX_KEYS ] = { 0 };

    window( glm::vec2 size, const char* name );

    ~window();

    window( const window& other ) = delete;

    window& operator=( const window& other ) = delete;

    void run();
};
