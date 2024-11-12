#include "StateList.h"
#include "Gun.h"

void IdleState::Start(Gun* gun) {
    std::cout << "Entering Idle State.\n";
}

void IdleState::Update(Gun* gun, float deltaTime) {
}



void ShootingState::Start(Gun* gun) {
    if (gun->getAmmo() > 0) {
        std::cout << "Bang! Ammo left: " << gun->getAmmo() - 1 << "\n";
        gun->setAmmo(gun->getAmmo() - 1);
    }
    else {
        std::cout << "No ammo left! Switching to Empty State.\n";
        gun->TransitionTo(Gun::StateType::Empty);
    }
}

void ShootingState::Update(Gun* gun, float deltaTime) {
    gun->TransitionTo(Gun::StateType::Idle);
}




void ReloadingState::Start(Gun* gun) {
    std::cout << "Reloading...\n";
}

void ReloadingState::Update(Gun* gun, float deltaTime) {
    gun->mReloadProgress += deltaTime;
    if (gun->mReloadProgress >= gun->mReloadTime) {
        gun->setAmmo(gun->MaxAmmo);
        std::cout << "Reload complete. Ammo: " << gun->getAmmo() << "\n";
        gun->TransitionTo(Gun::StateType::Idle);
    }
}




void EmptyState::Start(Gun* gun) {
    std::cout << "No ammo left! Please reload.\n";
}

void EmptyState::Update(Gun* gun, float deltaTime) {
}
