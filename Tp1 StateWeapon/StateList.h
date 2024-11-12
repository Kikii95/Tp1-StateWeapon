#pragma once
#include "State.h"   
#include <iostream>

class Gun;

class IdleState : public State {
public:
    void Start(Gun* gun) override;
    void Update(Gun* gun, float deltaTime) override;
};

class ShootingState : public State {
public:
    void Start(Gun* gun) override;
    void Update(Gun* gun, float deltaTime) override;
};

class ReloadingState : public State {
public:
    void Start(Gun* gun) override;
    void Update(Gun* gun, float deltaTime) override;
};

class EmptyState : public State {
public:
    void Start(Gun* gun) override;
    void Update(Gun* gun, float deltaTime) override;
};
