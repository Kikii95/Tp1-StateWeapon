#pragma once
#include "Gun.h"

class Game {
public:
    Game();
    void run();

private:
    Gun gun;
    bool isRunning;

    void processInput(char input);
    void update(float deltaTime);
    void render();
};
