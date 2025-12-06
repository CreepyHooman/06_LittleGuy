#include "raylib.h"
#include "textBubble.h"
#include "littleGuy.h"

TextBubble::TextBubble()
{
}

void TextBubble::Draw(int posX, int posY, const char* someText)
{
	DrawRectangle(posX, posY, m_width, m_height, GRAY);
	DrawText(someText, posX + 5, posY, 23, WHITE);
}



Vector2 TextBubble::GetPosition() const 
{
	return m_position;
}

int TextBubble::GetWidth() const
{
	return m_width;
}

int TextBubble::GetHeight() const
{
	return m_height;
}

/*
void TextBubble::DrawTheText(const char* someText, int posX, int posY, int fontSize)
{
	DrawText(someText, posX, posY, fontSize, WHITE);
}
*/