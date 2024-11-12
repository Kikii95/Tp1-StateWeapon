#include "Gun.h"

Gun::Gun(int capacity)
    : Ammo(capacity),
    MaxAmmo(capacity),
    mCurrentState(State::Idle),
    mShootTime(250.f),
    mReloadTime(500.0f),
    mShootProgress(0.0f),
    mReloadProgress(0.0f) {}

bool Gun::TransitionTo(State newState) {
    if (!mTransitions[(int)mCurrentState][(int)newState]) {
        std::cout << "Transition from " << getStateName() << " to " << (int)newState << " not allowed.\n";
        std::cout << "--------------------------------------------" << std::endl;
        needRender = false;
        return false;
    }
    else {
        needRender = true;
    }
    mCurrentState = newState;
    mShootProgress = 0.0f;
    mReloadProgress = 0.0f;
    return true;
}

void Gun::Update(float deltaTime) {
    switch (mCurrentState) {
    case State::Shooting:
        mShootProgress += deltaTime;
        if (mShootProgress >= mShootTime) {
            std::cout << "Bang! Ammo left: " << Ammo << "\n";
            mShootProgress = 0.0f;

            if (Ammo == 0) {
                TransitionTo(State::Empty);
            }
            else {
                TransitionTo(State::Idle);
            }
        }
        break;

    case State::Reloading:
        mReloadProgress += deltaTime;
        if (mReloadProgress >= mReloadTime) {
            Ammo = MaxAmmo;
            std::cout << "Reload complete. Ammo: " << Ammo << "\n";
            TransitionTo(State::Idle);
        }
        break;

    default:
        break;
    }
}

int Gun::getAmmo() const {
    return Ammo;
}

void Gun::setAmmo(int newAmmo) {
    Ammo = newAmmo;
}

std::string Gun::getStateName() const {
    switch (mCurrentState) {
    case State::Idle: return "Idle";
    case State::Shooting: return "Shooting";
    case State::Empty: return "Empty";
    case State::Reloading: return "Reloading";
    default: return "Unknown";
    }
}

void Gun::Shoot() {

    if (TransitionTo(Gun::State::Shooting)) {
        std::cout << "Start shooting...\n";
        Ammo--;
    }
}

void Gun::Reload() {
    if (TransitionTo(Gun::State::Reloading)) {
        std::cout << "Reloading...\n";
        mReloadProgress = 0.f;
    }
}