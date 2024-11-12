#pragma once

class Gun;

class State {
public:
    virtual void Start(Gun* gun) = 0;
    virtual void Update(Gun* gun, float deltaTime) = 0;
    virtual ~State() = default;
};
