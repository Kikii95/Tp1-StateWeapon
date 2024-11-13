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

    friend class ReloadingState;
    friend class ShootingState;

    Gun(int capacity);
    void Update(float deltaTime);
    void TransitionTo(StateType newState);
    std::string getStateName() const;

private:
    int mAmmo;
    const int mMaxAmmo;
    float mReloadTime;
    float mShootTime;

    StateType mCurrentStateType;
    State* mCurrentState;

    State* mStates[(int)StateType::StateCount];



    bool mTransitions[(int)StateType::StateCount][(int)StateType::StateCount] = {
        // Idle, Shooting, Empty, Reloading
        { 0,      1,       0,       1 },  // Idle
        { 1,      0,       1,       0 },  // Shooting
        { 1,      0,       0,       1 },  // Empty
        { 1,      0,       0,       0 },  // Reloading
    };
};
