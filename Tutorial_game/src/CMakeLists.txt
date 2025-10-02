add_executable(Tutorial_game
    main.cpp
    game.cpp
    shader.cpp
    texture.cpp
    resource_manager.cpp
    stbi_impl.cpp
    sprite_renderer.cpp
)

# Copy assets after every build, into the same folder as the executable
add_custom_command(TARGET Tutorial_game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:Tutorial_game>/assets
)

# Link GLFW + GLAD + OpenGL
target_link_libraries(Tutorial_game PRIVATE glfw glad OpenGL::GL glm)

# Add external headers
target_include_directories(Tutorial_game PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
