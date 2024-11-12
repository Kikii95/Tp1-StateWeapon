#include "Game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

Game::Game() : gun(10), isRunning(true) {}

void Game::run() {
    std::cout << "Let's Start ! 'R' to reload, 'S' to shoot, 'Q' to quit !" << std::endl;
    while (isRunning) {
        if (_kbhit()) {
            char key = _getch();
            processInput(key);
            if (gun.needRender) {
                render();
            }
        }
        update(0.016f);
    }
}

void Game::processInput(char input) {
    std::cout << "--------------------------------------------" << std::endl;
    switch (input) {
    case 's':
        gun.Shoot();
        break;

    case 'r':
        gun.Reload();
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
    std::cout << "Current ammo: " << gun.getAmmo() << "\n";
    std::cout << "Current state: " << gun.getStateName() << "\n";
}
