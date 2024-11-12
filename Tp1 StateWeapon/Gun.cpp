#include "Gun.h"

Gun::Gun(int capacity)
    : Ammo(capacity),
    MaxAmmo(capacity),
    mReloadTime(2.0f),
    mReloadProgress(0.0f),
    mCurrentStateType(StateType::Idle),
    mCurrentState(&mIdleState) {}

void Gun::Update(float deltaTime) {
    if (mCurrentState) {
        mCurrentState->Update(this, deltaTime);
    }
}

void Gun::TransitionTo(StateType newState) {
    switch (newState) {
    case StateType::Idle:
        mCurrentState = &mIdleState;
        break;
    case StateType::Shooting:
        mCurrentState = &mShootingState;
        break;
    case StateType::Empty:
        mCurrentState = &mEmptyState;
        break;
    case StateType::Reloading:
        mCurrentState = &mReloadingState;
        break;
    }
    mCurrentStateType = newState;
    mCurrentState->Start(this);
}

int Gun::getAmmo() const {
    return Ammo;
}

void Gun::setAmmo(int ammo) {
    Ammo = ammo;
}

std::string Gun::getStateName() const {
    switch (mCurrentStateType) {
    case StateType::Idle: return "Idle";
    case StateType::Shooting: return "Shooting";
    case StateType::Empty: return "Empty";
    case StateType::Reloading: return "Reloading";
    default: return "Unknown";
    }
}
