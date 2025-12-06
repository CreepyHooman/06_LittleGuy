#pragma once
#include "raylib.h"
#include <string>


class TextBubble
{
private:
    int m_width = 165;
    int m_height = 75;
    //char someText = "Nekaj, nekaj, nekaj";
    std::string text = "";
    Vector2 m_position = { 100.0f, 100.0f };

public:
    // constructor
    TextBubble();

    Vector2 GetPosition() const;

    int GetWidth() const;

    int GetHeight() const;

    void Draw(int posX, int posY, const char* someText);

    //void DrawTheText(const char* someText, int posX, int posY, int fontSize);
};

