cmake_minimum_required( VERSION 3.18 )

project( Prokra )

include_directories( "." )
include_directories( "inc" )

find_package( glfw3 REQUIRED )
find_package( OpenGL REQUIRED )
find_package( GLEW REQUIRED )
find_package( glm CONFIG REQUIRED )

add_subdirectory( prokra )
add_subdirectory( example )

target_sources( prokra PRIVATE inc/glad.c )

