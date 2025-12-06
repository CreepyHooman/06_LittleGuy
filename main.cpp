// IT'S A PROTOTYPE
// MISTAKES AND NONSENSE INCLUDED
// MUCH CLEANING TO DO
//   -_/\_-

#include <raylib.h>
#include "littleGuy.h"
#include "textBubble.h"
#include <vector>
#include <string>

enum GameScreen {TITLE, INTRO, GAMEPLAY, YOUDIED, ENDGAME};

int main(void)
{
	const int SCREEN_WIDTH = 1080;
	const int SCREEN_HEIGHT = 1350;

	const int LEVEL_WIDTH = 36;
	const int LEVEL_HEIGHT = 45;

	const int TILE_SIZE = 30;



	// grid array walls
	const int MAP_GRID[LEVEL_HEIGHT][LEVEL_WIDTH] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 1
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 2
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 3
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 4
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 5
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 6
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 7
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 8
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 9
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 10
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 11
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 12
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 13
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 14
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 15
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 16
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 17
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 18
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 19
	{1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 20
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 21
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 22
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 23
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 24
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 25
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1}, // 26
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 27
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 28
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 29
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 30
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 31
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 32
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 33
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 34
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 35
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 36
	{1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 37
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 38
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 39
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 40
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1}, // 41
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 42
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 43
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 44
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 45
	};
//   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36



	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Little Guy");
	SetTargetFPS(60);


	// current window
	GameScreen currentScreen = TITLE;

	// instantiate
	LittleGuy littleGuy;

	// cube04
	LittleGuy cube04;

	// cube05
	LittleGuy cube05;


	// Set initial position of the littleGuy (Tile 2 at [2][5])
	float startX = 2.0f * TILE_SIZE;
	float startY = 2.0f * TILE_SIZE;
	littleGuy.SetPosition({ startX, startY });
	cube04.SetPosition({ 30, 270 });
	cube05.SetPosition({ 180, 810 });
	
	// text bubble instance
	TextBubble textBubble;

	// add 1-s to a vector as wall collisions
	std::vector <Rectangle> wallCollisions{};

	for (int i = 0; i < LEVEL_HEIGHT; i++)
	{
		for (int j = 0; j < LEVEL_WIDTH; j++)
		{
			if (MAP_GRID[i][j] == 1)
			{
				wallCollisions.push_back(Rectangle{ (float)j * TILE_SIZE, (float)i * TILE_SIZE, TILE_SIZE, TILE_SIZE });
			}
		}
	}


	//SetExitKey(KEY_NULL);  

	bool exitWindow = false;  
	bool endOfTheGame = false;
	bool youDied = false;
	bool newEndGame = false;
	bool passageRoom01 = true;
	bool passageRoom02 = true;
	bool room02CubeB = false;
	bool room03text = false;
	bool room04Guy = false;
	bool room04EntryWall = true;
	bool room04Text = false;
	bool room04Wall = false;
	bool room04ExitWall = true;
	bool room05Text = false;
	bool room06Text01 = false;
	bool room06Text02 = false;
	bool room06Text03 = false;
	bool room06Text04 = false;
	bool room06Text05 = false;
	bool room06Text06 = false;
	

	// title text
	std::string titleText01 = "LITTLE GUY";
	std::string titleText02 = "A GAME PROTOTYPE";
	std::string titleText03 = "Press space to continue...";

	// intro text
	std::string introText = R"(
There was once a little guy...
Who found himself in a gray box...
He thought he got lost...
And that he perhaps lost his eyesight...
But he could not see much... 
Only for a tiny bit though...
But then again not many frames elapsed...
As he noticed, that he is not all alone....)";

	int textSize = MeasureText(titleText01.c_str(), 30);

	// die col
	Rectangle dieCol01{ 600, 600, littleGuy.GetWidth(), littleGuy.GetHeight() };

	while (!exitWindow)
	{

		// *** UPDATE SECTION *** //
		
		switch(currentScreen)
		{
			case TITLE:
			{

				if (IsKeyPressed(KEY_SPACE))
				{
					currentScreen = INTRO;
				}

			} break;

			case INTRO:
			{	

				if (IsKeyPressed(KEY_SPACE))
				{
					currentScreen = GAMEPLAY;
				}

			}break;

			case GAMEPLAY:
			{
				// check collision
				littleGuy.CheckAllCollisions(wallCollisions);

				// move
				littleGuy.Move();


				// end of the game
				if (newEndGame == true)
				{
					currentScreen = ENDGAME;
				}


				/*
				// check for death
				if (CheckCollisionRecs(littleGuyCol, dieCol01))
				{
					youDied = true;
				}

				if (youDied == true)
				{
					currentScreen = YOUDIED;
				}

				else if (newEndGame == true)
				{
					currentScreen = ENDGAME;
				}
				*/
				
			}break;

			/*
			case YOUDIED:
			{
				if (IsKeyPressed(KEY_Y))
				{
					exitWindow = true;
				}
			}break;
			*/

			case ENDGAME:
			{

				if (IsKeyPressed(KEY_Y))
				{
					exitWindow = true;
				}

			}break;

			default:break;
		}
	

		// *** DRAWING SECTION *** //
		BeginDrawing();
		ClearBackground(GRAY);

		switch(currentScreen)
		{
			case TITLE:
			{
				// make a logo appearance
				DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLACK);
				DrawText(titleText01.c_str(), 100, 100, 60, WHITE);
				DrawText(titleText02.c_str(), 100, 200, 30, WHITE);
				DrawText(titleText03.c_str(), 100, 800, 30, WHITE);
			} break;

			case INTRO:
			{
				// intro text
				DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLACK);

				DrawText(introText.c_str(), 100, 100, 30, WHITE);
				
			} break;

			case GAMEPLAY:
			{
				// background
				DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLACK);

				// draw grid
				for (int i = 0; i < LEVEL_HEIGHT; i++)
				{
					for (int j = 0; j < LEVEL_WIDTH; j++)
					{
						if (MAP_GRID[i][j] == 1)
						{
							// draw wall
							DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, GRAY);
						}
					}
				}

				// draw death rectangle *** FOR THE NEXT PROJECT ***
				//DrawRectangle(600, 600, littleGuy.GetWidth(), littleGuy.GetHeight(), PINK);

				// draw the guy
				littleGuy.Draw();
				cube04.Draw();
				cube05.Draw();
				
				//***
				// PROMPTS
				//***
				// ROOM 01
				//***

				if (passageRoom01 == true)
				{
					// passageRoom01
					DrawRectangle(420, 30, TILE_SIZE, 60, GRAY);
					
					// room01cube
					DrawRectangle(210, 120, TILE_SIZE, TILE_SIZE, GRAY);
					Rectangle prompt01Col{ 210, 120, TILE_SIZE, TILE_SIZE };

					if (CheckCollisionRecs(littleGuy.GetCollisionBox(), prompt01Col))
					{
						std::string text01 = "Hello, please\ncontinue.\nCya";
						textBubble.Draw(prompt01Col.x + TILE_SIZE + 5, prompt01Col.y + TILE_SIZE + 5, text01.c_str());
						passageRoom01 = false;
					}
				}
				
				else 
				{
					// only the passageRoom01 is not drawn

					DrawRectangle(210, 120, TILE_SIZE, TILE_SIZE, GRAY);
					Rectangle prompt01Col{ 210, 120, TILE_SIZE, TILE_SIZE };

					if (CheckCollisionRecs(littleGuy.GetCollisionBox(), prompt01Col))
					{
						std::string text01 = "Hello, please\ncontinue.\nCya";
						textBubble.Draw(prompt01Col.x + TILE_SIZE + 5, prompt01Col.y + TILE_SIZE + 5, text01.c_str());
					}
				}

				//***
				// ROOM 02
				//***

				if (passageRoom02 == true)
				{
					// passageRoom02
					DrawRectangle(720, 420, TILE_SIZE, TILE_SIZE, GRAY);
					DrawRectangle(750, 420, TILE_SIZE, TILE_SIZE, GRAY);

					// room02cube a
					DrawRectangle(600, 240, TILE_SIZE, TILE_SIZE, DARKBLUE);
					Rectangle prompt02aCol{ 600, 240, TILE_SIZE, TILE_SIZE };

					// room02cube b
					DrawRectangle(800, 240, TILE_SIZE, TILE_SIZE, BLUE);
					Rectangle prompt02bCol{ 800, 240, TILE_SIZE, TILE_SIZE };

					if ((CheckCollisionRecs(littleGuy.GetCollisionBox(), prompt02aCol)) && room02CubeB == true)
					{
						std::string text01 = "Hoooooo..,\nI'll be damned.\nThanks...";
						textBubble.Draw(prompt02aCol.x + TILE_SIZE + 5, prompt02aCol.y + TILE_SIZE + 5, text01.c_str());
						passageRoom02 = false;
					}

					if (CheckCollisionRecs(littleGuy.GetCollisionBox(), prompt02bCol))
					{
						std::string text01 = "Tell him, that\nthe keys are \nin his pocket.";
						textBubble.Draw(prompt02bCol.x + TILE_SIZE + 5, prompt02bCol.y + TILE_SIZE + 5, text01.c_str());
						room02CubeB = true;
					}
				}

				else
				{
					// only the passageRoom02 is not drawn

					// room02cube a
					DrawRectangle(600, 240, TILE_SIZE, TILE_SIZE, DARKBLUE);
					Rectangle prompt02aCol{ 600, 240, TILE_SIZE, TILE_SIZE };

					// room02cube b
					DrawRectangle(800, 240, TILE_SIZE, TILE_SIZE, BLUE);
					Rectangle prompt02bCol{ 800, 240, TILE_SIZE, TILE_SIZE };

					if (CheckCollisionRecs(littleGuy.GetCollisionBox(), prompt02aCol))
					{
						std::string text01 = "Hoooooo..,\nI'll be damned.\nThanks....";
						textBubble.Draw(prompt02aCol.x + TILE_SIZE + 5, prompt02aCol.y + TILE_SIZE + 5, text01.c_str());
						passageRoom02 = false;
					}

					if (CheckCollisionRecs(littleGuy.GetCollisionBox(), prompt02bCol))
					{
						std::string text01 = "Tell him, that\nthe keys are \nin his pocket.";
						textBubble.Draw(prompt02bCol.x + TILE_SIZE + 5, prompt02bCol.y + TILE_SIZE + 5, text01.c_str());
						passageRoom02 = false;
					}
				}
				
				//***
				// ROOM 03
				//***

				// room03col
				//DrawRectangle(720, 450, TILE_SIZE, TILE_SIZE, GRAY);
				//DrawRectangle(750, 450, TILE_SIZE, TILE_SIZE, GRAY);
				
				// entry collisions
				Rectangle room03Col01a{ 720, 450, TILE_SIZE, TILE_SIZE };
				Rectangle room03Col01b{ 750, 450, TILE_SIZE, TILE_SIZE };

				// exit collisions
				Rectangle room03Col02a{ 420, 450, TILE_SIZE, 60};
				//DrawRectangle(450, 450, 30, 60, RED);


				// for the next project implement SWITCH-ing room03text false <--> true


				if (CheckCollisionRecs(littleGuy.GetCollisionBox(), room03Col01a) || CheckCollisionRecs(littleGuy.GetCollisionBox(), room03Col01b))
				{
					room03text = true;
					room04Guy = true;
					room04EntryWall = false;
				}

				if (room04EntryWall == true)
				{
					DrawRectangle(420, 450, TILE_SIZE, 60, GRAY);
				}

				if (room03text == true)
				{
					std::string text01 = "Nothing here,\nonly an empty\nplace.";
					textBubble.Draw(800, 480, text01.c_str());
				}

				if (CheckCollisionRecs(littleGuy.GetCollisionBox(), room03Col02a))
				{
					room03text = false;
				}
				
				//***
				// ROOM 04
				//***

				// entry collision
				Rectangle room04Col01a{ 390, 450, TILE_SIZE, 60 };
				
				// text collision
				//DrawRectangle(30, 270, 280, 200, YELLOW);
				Rectangle room04Col01b{ 30, 270, 310, 230 };

				
				if (CheckCollisionRecs(littleGuy.GetCollisionBox(), room04Col01a))
				{
					room04Text = true;
				}
			
				
				// text
				if (CheckCollisionRecs(littleGuy.GetCollisionBox(), room04Col01b))
				{
					room04ExitWall = false;
				}
				


				if (room04Text == true)
				{
					//
					std::string text04 = "Yeah?\nOh it's you.\nLeave me...";
					textBubble.Draw((cube04.GetPosition().x + TILE_SIZE), (cube04.GetPosition().y +TILE_SIZE), text04.c_str());
				}

				if (room04Wall == true)
				{
					DrawRectangle(240, 270, TILE_SIZE, 150, GRAY);
					DrawRectangle(30, 420, 240, TILE_SIZE, GRAY);
				}

				
				if (room04ExitWall == true)
				{
					DrawRectangle(30, 570, 60, TILE_SIZE, GRAY);
				}
				
				

				//***
				// ROOM 05
				//***

				// entry collision
				Rectangle room05Col01a{ 30, 540, 60, TILE_SIZE };

				// exit collision
				Rectangle room05Col02a{ 420, 570, TILE_SIZE, 60 };

				// text
				std::string text05 = "They think,\nif you go on,\na path awaits.";

				// prompt cube col
				Rectangle room05CubeCol{ cube05.GetPosition().x, cube05.GetPosition().y };

				if (CheckCollisionRecs(littleGuy.GetCollisionBox(), room05Col01a))
				{
					room04Text = false;
				}

				

				if (CheckCollisionRecs(littleGuy.GetCollisionBox(), room05CubeCol))
				{
					room05Text = true;
				}

				

				if (room05Text == true)				
				{
					textBubble.Draw(cube05.GetPosition().x + TILE_SIZE, cube05.GetPosition().y + TILE_SIZE, text05.c_str());
				}
				
				if (CheckCollisionRecs(littleGuy.GetCollisionBox(), room05Col02a))
				{
					room05Text = false;
				}
				
				//***
				// ROOM 06
				//***
				
				
				// text 01
				std::string r06Text01 = "Y? You simply\ntrack your\nfront edge?";

				// text 02
				std::string r06Text02 = "Ages ago a\nrock was cut.\nAn edge. Y?";

				// text 03
				std::string r06Text03 = "You see the\nconnection?\nCube? Walls?";

				// text 04
				std::string r06Text04 = "I'm afraid\nthere is more.\nA lot more.";

				// text 05
				std::string r06Text05 = "It will\nwait for some \nother time.";

				// text 06
				std::string r06Text06 = "Yes,\nalmost there,\ngo on...";

				// prompts positions
				//01
				//DrawRectangle(690, 600, TILE_SIZE, 150, RED);
				Rectangle r06Text01col { 690, 600, TILE_SIZE, 150 };

				if(CheckCollisionRecs(littleGuy.GetCollisionBox(), r06Text01col))
				{
					room06Text01 = true;
				}

				if (room06Text01 == true)
				{
					textBubble.Draw(cube05.GetPosition().x + TILE_SIZE, cube05.GetPosition().y + TILE_SIZE, r06Text01.c_str());
				}

				//02
				//DrawRectangle(720, 780, TILE_SIZE, 150, RED);
				Rectangle r06Text02col{ 720, 780, TILE_SIZE, 150 };

				if (CheckCollisionRecs(littleGuy.GetCollisionBox(), r06Text02col))
				{
					room06Text02 = true;
					room06Text01 = false;
				}

				if (room06Text02 == true)
				{
					textBubble.Draw(cube05.GetPosition().x + TILE_SIZE, cube05.GetPosition().y + TILE_SIZE, r06Text02.c_str());
				}


				//03
				//DrawRectangle(210, 960, TILE_SIZE, 120, RED);
				Rectangle r06Text03col{ 210, 960, TILE_SIZE, 120 };

				if (CheckCollisionRecs(littleGuy.GetCollisionBox(), r06Text03col))
				{
					room06Text03 = true;
					room06Text02 = false;
				}

				if (room06Text03 == true)
				{
					textBubble.Draw(cube05.GetPosition().x + TILE_SIZE, cube05.GetPosition().y + TILE_SIZE, r06Text03.c_str());
				}


				//04
				//DrawRectangle(510, 1110, TILE_SIZE, 90, RED);
				Rectangle r06Text04col{ 510, 1110, TILE_SIZE, 90 };

				if (CheckCollisionRecs(littleGuy.GetCollisionBox(), r06Text04col))
				{
					room06Text04 = true;
					room06Text03 = false;
				}

				if (room06Text04 == true)
				{
					textBubble.Draw(cube05.GetPosition().x + TILE_SIZE, cube05.GetPosition().y + TILE_SIZE, r06Text04.c_str());
				}

				//05
				//DrawRectangle(800, 1230, TILE_SIZE, 90, RED);
				Rectangle r06Text05col{ 800, 1230, TILE_SIZE, 90 };

				if (CheckCollisionRecs(littleGuy.GetCollisionBox(), r06Text05col))
				{
					room06Text05 = true;
					room06Text06 = false;
				}

				if (room06Text05 == true)
				{
					textBubble.Draw(cube05.GetPosition().x + TILE_SIZE, cube05.GetPosition().y + TILE_SIZE, r06Text05.c_str());
				}

				//06
				//DrawRectangle(420, 1230, TILE_SIZE, 90, RED);
				Rectangle r06Text06col{ 420, 1230, TILE_SIZE, 90 };

				if (CheckCollisionRecs(littleGuy.GetCollisionBox(), r06Text06col))
				{
					room06Text06 = true;
					room06Text05 = false;
				}

				if (room06Text06 == true)
				{
					textBubble.Draw(cube05.GetPosition().x + TILE_SIZE, cube05.GetPosition().y + TILE_SIZE, r06Text06.c_str());
				}

				//***
				// FINAL ROOM
				//***
				
				// final col
				//DrawRectangle(30, 1230, 120, 90, RED);
				Rectangle finalRoomCol { 30, 1230, 120, 90 };
				
				if (CheckCollisionRecs(littleGuy.GetCollisionBox(), finalRoomCol ))
				{
					newEndGame = true;
				}


				// die col
				//DrawRectangle(500, 500, TILE_SIZE, TILE_SIZE, GREEN);
				//Rectangle die01Col{ 500, 500, TILE_SIZE, TILE_SIZE };

				/*
				// collision check text bubble
				if (CheckCollisionRecs(littleGuyCol, prompt01Col))
				{
					//textBubble.Draw(littleGuy.GetPosition().x, littleGuy.GetPosition().y, TILE_SIZE * 3, TILE_SIZE * 2, GREEN);
					//textBubble.Draw(prompt01Col.x + TILE_SIZE, prompt01Col.y - 2 * TILE_SIZE, TILE_SIZE * 3, TILE_SIZE * 2, GREEN);
					//textBubble.DrawTheText("HELLO!", prompt01Col.x + TILE_SIZE + 5, prompt01Col.y - 2 * TILE_SIZE + 5, 30);
				}

				*/

				

			} break;

			
			case YOUDIED:
			{
				DrawRectangle(0, 0, 640, 640, BLACK);
				DrawText("exit the game? [Y/N]", 100, 320, 30, WHITE);
			} break;
			

			case ENDGAME:
			{
				DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLACK);
				DrawText("exit the game? [Y/N]", 100, 320, 30, WHITE);
			} break;
		}
		
		EndDrawing();
	}

	
	CloseWindow();
	
	return 0;
}

	

	
