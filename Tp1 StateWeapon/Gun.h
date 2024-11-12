#pragma once
#include <string>
#include <iostream>

class Gun {
public:
    enum class State {
        Idle,
        Shooting,
        Empty,
        Reloading,
        StateCount
    };

    Gun(int capacity);

    void Update(float deltaTime);
    bool TransitionTo(State newState);
    
    void Shoot();
    void Reload();

    int getAmmo() const;
    void setAmmo(int newAmmo);

    std::string getStateName() const;
    bool needRender = false;

private:
    int Ammo;
    const int MaxAmmo;

    State mCurrentState;
    float mShootTime;
    float mReloadTime;
    float mShootProgress;
    float mReloadProgress;

    bool mTransitions[(int)State::StateCount][(int)State::StateCount] = {
        // Idle, Shooting, Empty, Reloading
        { 0,      1,       0,       1 },  // Idle
        { 1,      0,       1,       0 },  // Shooting
        { 1,      0,       0,       1 },  // Empty
        { 1,      0,       0,       0 },  // Reloading
    };
};
