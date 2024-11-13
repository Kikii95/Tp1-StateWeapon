#include "Game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

Game::Game() : gun(10), isRunning(true) {}

void Game::run() {
    std::cout << "Let's Start! Press 'S' to shoot, 'R' to reload, 'Q' to quit.\n";
    while (isRunning) {
        if (_kbhit()) {
            char key = _getch();
            processInput(key);
            render();
        }
        update(0.016f);
    }
}

void Game::processInput(char input) {
    switch (input) {
    case 's':
        gun.TransitionTo(Gun::StateType::Shooting);
        break;
    case 'r':
        gun.TransitionTo(Gun::StateType::Reloading);
        break;
    case 'q':
        isRunning = false;
        break;
    default:
        std::cout << "Invalid input. Try again.\n";
        break;
    }
}

void Game::update(float deltaTime) {
    gun.Update(deltaTime);
}

void Game::render() {
    std::cout << "Current state: " << gun.getStateName() << "\n";
}
