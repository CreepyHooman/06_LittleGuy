#pragma once
#include "raylib.h"
#include <vector>


class LittleGuy
{
private:
    Vector2 m_position;
    Vector2 m_velocity;

    bool m_canGoLeft = true;
    bool m_canGoRight = true;
    bool m_canGoUp = true;
    bool m_canGoDown = true;

public:
    // consts 
    static const int m_width = 30;
    static const int m_height = 30;
    int moveStep = 5;

    // constructor
    LittleGuy();

    // draw and move
    void Draw();
    void Move();

    // getters
    Vector2 GetPosition() const;
    Vector2 GetVelocity() const;
    int GetWidth() const;
    int GetHeight() const;
    Rectangle GetCollisionBox() const;

    // setters
    void SetPosition(Vector2 newPosition);
    
    //void SetVelocity(Vector2 newVelocity);
    
    void SetCanMove(bool left, bool right, bool up, bool down);


    // function
    void CheckAllCollisions(const std::vector<Rectangle>& walls);

};


