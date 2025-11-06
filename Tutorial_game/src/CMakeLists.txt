add_executable(Tutorial_game
    main.cpp
    game.cpp
    shader.cpp
    texture.cpp
    resource_manager.cpp
    stbi_impl.cpp
    sprite_renderer.cpp
    game_object.cpp
    game_level.cpp
    ball_object.cpp
    particle_generator.cpp
    post_processor.cpp
    audio.cpp
)

# Copy assets to build directory
add_custom_target(assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:Tutorial_game>/assets
    COMMENT "Copying assets..."
)

# Ensure update of assets
add_dependencies(Tutorial_game assets)

# Link GLFW + GLAD + OpenGL + GLM
target_link_libraries(Tutorial_game PRIVATE glfw glad OpenGL::GL glm)

# Add header
target_include_directories(Tutorial_game PRIVATE
    ${miniaudio_SOURCE_DIR} 
    ${stb_SOURCE_DIR}
)
