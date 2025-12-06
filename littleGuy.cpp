#include "raylib.h"
#include "littleGuy.h"
#include <vector>

LittleGuy::LittleGuy():
	m_position({300.0f, 300.0f})
{

}

Vector2 LittleGuy::GetPosition() const
{
	return m_position;
}

void LittleGuy::SetPosition(Vector2 newPosition)
{
	m_position = newPosition;
}

int LittleGuy::GetWidth() const
{
	return m_width;
}

int LittleGuy::GetHeight() const
{
	return m_height;
}

Rectangle LittleGuy::GetCollisionBox() const
{
	return { m_position.x, m_position.y, m_width, m_height };
}

void LittleGuy::Draw()
{
	// draw the guy
	DrawRectangle(m_position.x, m_position.y, GetWidth(), GetHeight(), DARKGRAY);
}

// mine
void LittleGuy::Move()
{
	// reset the velocity to zero
	m_velocity = { 0.0f, 0.0f };


	if (IsKeyDown(KEY_RIGHT) && m_canGoRight)
	{
		if((m_position.x + m_width + moveStep) <= GetScreenWidth())
		{
			m_position.x += moveStep;
			//m_velocity.x = 5.0f;
		}

		
	}

	if (IsKeyDown(KEY_LEFT) && m_canGoLeft)
	{
		if ((m_position.x - moveStep) >= m_width)
		{
			m_position.x -= moveStep;
			//m_velocity.x = -5.0f;
		}
		
	}

	if (IsKeyDown(KEY_UP) && m_canGoUp)
	{
		if((m_position.y - moveStep) >= m_height)
		{
			m_position.y -= moveStep;
			//m_velocity.y = -5.0f;
		}
		
	}

	if (IsKeyDown(KEY_DOWN) && m_canGoDown)
	{
		if((m_position.y + m_height + moveStep) <= GetScreenHeight())
		{
			m_position.y += moveStep;
			//m_velocity.y = 5.0f;
		}
		
	}
}

void LittleGuy::SetCanMove(bool left, bool right, bool up, bool down)
{
	m_canGoLeft = left;
	m_canGoRight = right;
	m_canGoUp = up;
	m_canGoDown = down;
}

void LittleGuy::CheckAllCollisions(const std::vector<Rectangle>& walls)
{
	// all four directions
	m_canGoLeft = true;
	m_canGoRight = true;
	m_canGoUp = true;
	m_canGoDown = true;


	
	Rectangle ghostPieceLeft{ m_position.x - 5, m_position.y, (float)m_width, (float)m_height };
	Rectangle ghostPieceRight{ m_position.x + 5, m_position.y, (float)m_width, (float)m_height };
	Rectangle ghostPieceUp{ m_position.x, m_position.y - 5, (float)m_width, (float)m_height };
	Rectangle ghostPieceDown{ m_position.x, m_position.y + 5, (float)m_width, (float)m_height };

	for(const auto& wall : walls )
	{
		if (CheckCollisionRecs(ghostPieceLeft, wall))
		{
			m_canGoLeft = false;
		}

		if (CheckCollisionRecs(ghostPieceRight, wall))
		{
			m_canGoRight = false;
		}

		if(CheckCollisionRecs(ghostPieceUp, wall))
		{
			m_canGoUp = false;
		}

		if(CheckCollisionRecs(ghostPieceDown, wall))
		{
			m_canGoDown = false;
		}
	}
}





