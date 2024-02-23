add_library( prokra )

target_sources( prokra PRIVATE window.cpp )

target_link_libraries( prokra PRIVATE glfw )
target_link_libraries( prokra PRIVATE OpenGL::GL )
target_link_libraries( prokra PRIVATE glm::glm )

