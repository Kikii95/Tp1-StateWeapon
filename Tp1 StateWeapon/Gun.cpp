#include "Gun.h"

Gun::Gun(int capacity)
    : mAmmo(capacity),
    mMaxAmmo(capacity),
    mReloadTime(200.0f),
    mShootTime(200.0f),
    mCurrentStateType(StateType::Idle),
    mCurrentState()
{
    mStates[0] = new IdleState();
    mStates[1] = new ShootingState();
    mStates[2] = new EmptyState();
    mStates[3] = new ReloadingState();

    mCurrentState = mStates[0];
}

void Gun::Update(float deltaTime) {
    mCurrentState->Update(this, deltaTime);
}

void Gun::TransitionTo(StateType newState) {
    std::cout << "---------------------------------------\n";
    if (!mTransitions[(int)mCurrentStateType][(int)newState]) {
        std::cout << "Transition from " << getStateName()
            << " to " << (newState == StateType::Idle ? "Idle" :
                newState == StateType::Shooting ? "Shooting" :
                newState == StateType::Empty ? "Empty" :
                "Reloading")
            << " is not allowed.\n";
        std::cout << "---------------------------------------\n";
        return;
    }

    mCurrentState->End(this);

    mCurrentStateType = newState;
    mCurrentState = mStates[(int)newState];

    mCurrentState->Start(this);
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
