#include "window.hpp" 
#include <stdexcept>    
#include <iostream>

///////////////////////////////////////////////////////////////////////////////
// Glad ///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void load_glad()
{
    if ( !gladLoadGLLoader( (GLADloadproc) glfwGetProcAddress ) )
    {
        throw std::runtime_error( "Failed to load GLAD" );
    } 
}


///////////////////////////////////////////////////////////////////////////////
// Keyboard handler ///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void key_callback( GLFWwindow *glfw_window
                 , int key
                 , int scancode
                 , int action
                 , int mods )
{
    window *w = (window*) glfwGetWindowUserPointer( glfw_window );

    if ( action == GLFW_PRESS || action == GLFW_REPEAT )
        w->pressed[ key ] = true;  
    if ( action == GLFW_RELEASE )
        w->pressed[ key ] = false;
}


///////////////////////////////////////////////////////////////////////////////
// Window /////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void setup_keyboard_handler( window *w )
{
    glfwSetKeyCallback( w->glfw_window, key_callback );
}


void frame_buffer_size_callback( GLFWwindow *window, int width, int height )
{
    glViewport( 0, 0, width, height );
}


window::window( glm::vec2 size, const char* name )
{
    glfwInit();

    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

    GLFWwindow* win = glfwCreateWindow( size.x, size.y, name, NULL, NULL );

    if( win == NULL ) 
    {
        glfwTerminate();
        throw std::runtime_error( "Failed to create window" );
    }

    glfwMakeContextCurrent( win );

    load_glad();

    glViewport( 0, 0, size.x, size.y );
    glfwSetFramebufferSizeCallback( win, frame_buffer_size_callback );

    glfw_window = win;
    glfwSetWindowUserPointer( win, this );

    setup_keyboard_handler( this );
}


window::~window()
{
    glfwTerminate();
}


void window::run()
{
    while( !glfwWindowShouldClose( glfw_window ) )
    {
        glfwSwapBuffers( glfw_window );
        glfwPollEvents();    
    }
}
