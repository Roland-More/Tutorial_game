/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <tuple>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game_level.h"
#include "power_up.h"

// Represents the current state of the game
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

// Represents the four possible (collision) directions
enum Direction {
	UP,
	RIGHT,
	DOWN,
	LEFT
};

// Defines a Collision tuple that represents collision data
using Collision = std::tuple<bool, Direction, glm::vec2>;

// Initial size of the player paddle
constexpr glm::vec2 PLAYER_SIZE(100.0f, 20.0f);
// Initial velocity of the player paddle
constexpr float PLAYER_VELOCITY = 500.0f;

constexpr float BALL_RADIUS = 12.5f;
constexpr glm::vec2 INITIAL_BALL_VELOCITY(100.0f, -350.0f);

// Game holds all game-related state and functionality.
// Combines all game-related data into a single class for
// easy access to each of the components and manageability.
class Game
{
public:
    // game state
    bool                    Keys[1024];
    // constructor/destructor
    Game(unsigned int width, unsigned int height);
    ~Game();
    // initialize game state (load all shaders/textures/levels)
    void Init();
    // game loop
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();

private:
    // game state
    GameState               State;
    unsigned int            Width, Height;

    std::vector<PowerUp>  PowerUps;

    // level tracking
    std::vector<GameLevel> Levels;
    unsigned int           Level;
    
    void DoCollisions();

    void ResetLevel();
    void ResetPlayer();

    void SpawnPowerUps(GameObject &block);
    void UpdatePowerUps(float dt);
};

#endif
