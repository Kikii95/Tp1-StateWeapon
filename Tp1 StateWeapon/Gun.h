#pragma once
#include <iostream>
#include "StateList.h"

class Gun {
public:
    enum class StateType {
        Idle,
        Shooting,
        Empty,
        Reloading,
        StateCount
    };

    Gun(int capacity);
    void Update(float deltaTime);
    void TransitionTo(StateType newState);

    int getAmmo() const;
    void setAmmo(int ammo);
    std::string getStateName() const;

    const int MaxAmmo;
    float mReloadTime;
    float mReloadProgress;

private:
    int Ammo;

    StateType mCurrentStateType;
    State* mCurrentState;

    IdleState mIdleState;
    ShootingState mShootingState;
    ReloadingState mReloadingState;
    EmptyState mEmptyState;
};
