#pragma once
#include "State.h"   
#include <iostream>

class Gun;

class IdleState : public State {
public:
    void Start(Gun* gun) override;
    void Update(Gun* gun, float deltaTime) override;
    void End(Gun* gun) override;
};

class ShootingState : public State {
public:
    void Start(Gun* gun) override;
    void Update(Gun* gun, float deltaTime) override;
    void End(Gun* gun) override;
private:
    float mShootProgress = 0;
};

class ReloadingState : public State {
public:
    void Start(Gun* gun) override;
    void Update(Gun* gun, float deltaTime) override;
    void End(Gun* gun) override;
private:
    float mReloadProgress = 0;
};

class EmptyState : public State {
public:
    void Start(Gun* gun) override;
    void Update(Gun* gun, float deltaTime) override;
    void End(Gun* gun) override;
};
