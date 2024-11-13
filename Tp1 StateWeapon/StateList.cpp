#include "StateList.h"
#include "Gun.h"

void IdleState::Start(Gun* gun) {
    std::cout << "Entering Idle State.\n";
}

void IdleState::Update(Gun* gun, float deltaTime) {
}

void IdleState::End(Gun* gun) {
    std::cout << "Exiting Idle State.\n";
}

void ShootingState::Start(Gun* gun) {
    std::cout << "Entering Shooting State.\n";
    if (gun->mAmmo > 0) {
        std::cout << "Bang! Ammo left : " << gun->mAmmo - 1 << "\n";
        mShootProgress = 0;
    }
    else {
        std::cout << "No ammo left!\n";
        gun->TransitionTo(Gun::StateType::Empty);
    }
}

void ShootingState::Update(Gun* gun, float deltaTime) {
    mShootProgress = mShootProgress + deltaTime;
    if (mShootProgress >= gun->mShootTime) {
        std::cout << "Shoot complete.\n";
        gun->mAmmo--;
        gun->TransitionTo(Gun::StateType::Idle);
    }

}

void ShootingState::End(Gun* gun) {
    std::cout << "Exiting Shooting State.\n";
}

void ReloadingState::Start(Gun* gun) {
    std::cout << "Reloading...\n";
    mReloadProgress = 0;
}

void ReloadingState::Update(Gun* gun, float deltaTime) {
    mReloadProgress = mReloadProgress + deltaTime;
    if (mReloadProgress >= gun->mReloadTime) {
        gun->mAmmo = gun->mMaxAmmo;
        std::cout << "Reload complete.\nCurrent Ammo = " << gun->mAmmo << "\n";
        mReloadProgress = 0;
        gun->TransitionTo(Gun::StateType::Idle);
    }
}

void ReloadingState::End(Gun* gun) {
    std::cout << "Exiting Reloading State.\n";
}


void EmptyState::Start(Gun* gun) {
    std::cout << "No ammo left! Please reload.\n";
}

void EmptyState::Update(Gun* gun, float deltaTime) {
}

void EmptyState::End(Gun* gun) {
    std::cout << "Exiting Empty State.\n";
}
