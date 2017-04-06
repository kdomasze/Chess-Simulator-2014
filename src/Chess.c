/*
 * Chess.c: The main module for Chess Simulator 2014
 *
 * EECS22L, Winter 2014
 *
 * Written by: Anthony Diep 
 * Created on: 1/21/14
 *
 * Rev. history:
 * 1/21/14 3:00PM: Initial Creation(AD)
 * 1/23/14 8:00PM: Expanded with available functions(AD) 
 * 1/24/14 7:00PM: Removed redundant/useless code; Incorporated GUI functions(AD)
 * 1/24/14 10:00PM: Commented out AI difficulties/Check/Checkmate for now(AD)
 * 1/25/14 6:00PM: Changed input string to accept 6; Added InitialBoard; Added difficulty option for two computers(AD)
 * 1/25/14 12:00PM: Name changed to Chess.c (AD)
 * 1/28/14 08:00PM: Enabled Human vs Human (AD)
*/

#include "SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include "ChessObj.h"
#include "ChessPieces.h"
#include "GUI.h"
#include "rules.h" 
#include "MovePiece.h"
#include "MoveList.h"
#include "AI.h"
#include "Log.h"

int main(void)
{
	int quit = 0;
	
	int currentState = 1;
	
	int WhiteCheckmate = 0;
	int WhiteCheck = 0;
	int BlackCheckmate = 0;
	int BlackCheck = 0;
	
	int gameStart = 0;
	int turn = 0;

	enum {Human, AI};
	/*int x, y;*/
	int AIType, AIType2;
	int PlayerColor;
	int GameType = 0;
	int Player1, Player2;
	int castling = 0;
	int playerTurn = 1;

	/* Initialized board here to prevent const errors */
	t_Board Board =
			{ 

			{BlackRook, BlackKnight, BlackBishop, BlackQueen, BlackKing, BlackBishop, BlackKnight, BlackRook}, 

			{BlackPawn, BlackPawn, BlackPawn, BlackPawn, BlackPawn, BlackPawn, BlackPawn, BlackPawn}, 

			{EmptyPiece, EmptyPiece, EmptyPiece, EmptyPiece, EmptyPiece, EmptyPiece, EmptyPiece, EmptyPiece}, 

			{EmptyPiece, EmptyPiece, EmptyPiece, EmptyPiece, EmptyPiece, EmptyPiece, EmptyPiece, EmptyPiece}, 

			{EmptyPiece, EmptyPiece, EmptyPiece, EmptyPiece, EmptyPiece, EmptyPiece, EmptyPiece, EmptyPiece}, 

			{EmptyPiece, EmptyPiece, EmptyPiece, EmptyPiece, EmptyPiece, EmptyPiece, EmptyPiece, EmptyPiece}, 

			{WhitePawn, WhitePawn, WhitePawn, WhitePawn, WhitePawn, WhitePawn, WhitePawn, WhitePawn},

			{WhiteRook, WhiteKnight, WhiteBishop, WhiteQueen, WhiteKing, WhiteBishop, WhiteKnight, WhiteRook}

			};

	MLIST *MList = NULL;
	
	MList = NewMoveList();


	
	/* initialize */
	if(init() == 0)
	{
		return 1;
	}
	
	/* create white background */
	SDL_Rect screenRect;
	screenRect.x = screenRect.y = 0;
	screenRect.w = screen->w;
	screenRect.h = screen->h;
	clearColor = SDL_MapRGB(screen->format, 255, 255, 255);
	
	/* begin menu sequence */
	while(quit != 1)
	{
		while(SDL_PollEvent(&event))
		{
			if(currentScreen == 1)
			{
				if(currentScreenDisplayed != 1)
				{
					SDL_FillRect(screen, &screenRect, clearColor);
					displayMainMenu();
					currentScreenDisplayed = 1;
				}
				if(mouseClickBtn(SCREEN_WIDTH - BTN_WIDTH - 11, 300, 2))
				{
					GameType = 1;
				}
				
				if(mouseClickBtn(SCREEN_WIDTH - BTN_WIDTH - 11, 300 + BTN_HEIGHT + 11, 4))
				{
					GameType = 3;
					Player1 = Player2 = AI;
				}
				
				if(mouseClickBtn(SCREEN_WIDTH - BTN_WIDTH - 11, 300 + BTN_HEIGHT + BTN_HEIGHT + 22, 6))
				{
					GameType = 2;
					Player1 = Player2 = Human;
				}
			}
			else if(currentScreen == 2)
			{
				if(currentScreenDisplayed != 2)
				{
					SDL_FillRect(screen, &screenRect, clearColor);
					displayColorMenu(0);
					currentScreenDisplayed = 2;
				}
				if(mouseClickBtn(SCREEN_WIDTH - BTN_WIDTH - 11, 300, 3))
				{
					PlayerColor = 2;
				}
				if(mouseClickBtn(SCREEN_WIDTH - BTN_WIDTH - 11, 300 + BTN_HEIGHT + 11, 3))
				{
					PlayerColor = 1;
				}
			}
			else if(currentScreen == 3)
			{
				if(currentScreenDisplayed != 3)
				{
					SDL_FillRect(screen, &screenRect, clearColor);
					displayDifficultyMenu(0);
					currentScreenDisplayed = 3;
				}
				
				int AITypeSelect = 0;
				
				if(mouseClickBtn(SCREEN_WIDTH - BTN_WIDTH - 11, 300, 6))
				{
					AITypeSelect = 1;
				}
				if(mouseClickBtn(SCREEN_WIDTH - BTN_WIDTH - 11, 300 + BTN_HEIGHT + 11, 6))
				{
					AITypeSelect = 2;
				}
				if(mouseClickBtn(SCREEN_WIDTH - BTN_WIDTH - 11, 300 + BTN_HEIGHT + BTN_HEIGHT + 22, 6))
				{
					AITypeSelect = 3;
				}
				
				switch (PlayerColor)
				{
					case 1:
						AIType2 = AITypeSelect;
						Player1 = Human;
						Player2 = AI;
						break;
					case 2:
						AIType = AITypeSelect;
						Player1 = AI;
						Player2 = Human;
						break;
				}
			}
			else if(currentScreen == 4)
			{
				if(currentScreenDisplayed != 4)
				{
					SDL_FillRect(screen, &screenRect, clearColor);
					displayDifficultyMenu(1);
					currentScreenDisplayed = 4;
				}
				
				if(mouseClickBtn(SCREEN_WIDTH - BTN_WIDTH - 11, 300, 5))
				{
					AIType = 1;
				}
				
				if(mouseClickBtn(SCREEN_WIDTH - BTN_WIDTH - 11, 300 + BTN_HEIGHT + 11, 5))
				{
					AIType = 2;
				}
				if(mouseClickBtn(SCREEN_WIDTH - BTN_WIDTH - 11, 300 + BTN_HEIGHT + BTN_HEIGHT + 22, 5))
				{
					AIType = 3;
				}
			}
			else if(currentScreen == 5)
			{
				if(currentScreenDisplayed != 5)
				{
					SDL_FillRect(screen, &screenRect, clearColor);
					displayDifficultyMenu(2);
					currentScreenDisplayed = 5;
				}
				
				if(mouseClickBtn(SCREEN_WIDTH - BTN_WIDTH - 11, 300, 6))
				{
					AIType2 = 1;
				}
				if(mouseClickBtn(SCREEN_WIDTH - BTN_WIDTH - 11, 300 + BTN_HEIGHT + 11, 6))
				{
					AIType2 = 2;
				}
				if(mouseClickBtn(SCREEN_WIDTH - BTN_WIDTH - 11, 300 + BTN_HEIGHT + BTN_HEIGHT + 22, 6))
				{
					AIType2 = 3;
				}
			}
			else if(currentScreen == 6)
			{
				gameStart = 1;
				if(currentScreenDisplayed != 6)
				{
					SDL_FillRect(screen, &screenRect, clearColor);
					displayChessBoard(Board);
					currentScreenDisplayed = 6;
					
					if(WhiteCheckmate == 1)
					{
						apply_surface(150, 650, img_WhiteCheckmate_txt, screen);
					}
					else if (WhiteCheck == 1)
					{
						apply_surface(150, 650, img_WhiteCheck_txt, screen);
					}
					else if (BlackCheckmate == 1)
					{
						apply_surface(150, 650, img_BlackCheckmate_txt, screen);
					}
					else if (BlackCheck == 1)
					{
						apply_surface(150, 650, img_BlackCheck_txt, screen);
					}
					
					WhiteCheck = 0;
					BlackCheck = 0;
				}
				
				int i;
				int j;
				
				if((GameType != 3 || (playerTurn == 1 && Player1 != AI) || (playerTurn == 2 && Player2 != AI)) && (BlackCheckmate != 1 && WhiteCheckmate != 1)) 
				{
					for(i = 0; i < 8; i++)
					{
						for(j = 0; j < 8; j++)
						{
							currentState = mouseClickBoard(95 + 75 * j, 75 * i, 7-i, j, currentState);
						}
					}
				}
				if(mouseClickBtn(SCREEN_WIDTH - 272, SCREEN_HEIGHT - 66, 1))
				{
					/* SAVE AND QUIT */
					quit = 1;
				}
			}
			
			/* if the user has Xed out the window */
			if(event.type == SDL_QUIT)
			{
				/* quit the program */
				quit = 1;
			}
		}
		
		updateDisplay();
		
		/* logic starts */
		/* switch from one string to two because scanf doesn't support whitespace */
		if(((currentState == 3 || (playerTurn == 1 && Player1 == AI) || (playerTurn == 2 && Player2 == AI)) && gameStart == 1) && (BlackCheckmate != 1 && WhiteCheckmate != 1))
		{
			t_Move M;
			if(playerTurn == 1)
			{
				switch (Player1)
				{
					case Human:
						getMove(input1, input2, &M);
						break;
					case AI:
						switch (AIType)
						{
							case 1:
								do{
									M = Easy(White, Board, MList);
								}while(Check(Board, M, Black, MList));
								break;
							case 2:
									M = Medium(White, Board, MList);
								break;	
							/*case 3:
								M = Hard(White, Board, MList);
								break;*/
							default:
								do{
									M = Medium(White, Board, MList);
								}while(Check(Board, M, Black, MList));
								break;
						}
						break;
				}
				if((castling = ValidMove(Board, M, MList, White, 1)))
				{
					if(Check(Board, M, White, MList))
					{
						BlackCheck = 1;
					}
					AddMove(MList, Board, &M);
					switch (castling)
						{
							case 1:
								MovePiece(Board, M);
								break;
							case 2:
								Castling(Board,M);
								break;
							case 3:
								EnPassant(Board, M);
								break;
						}		
					
					if(CheckMate(Board, Black, MList))
					{
						BlackCheckmate = 1;
					}
					
					if(PromotionCheck(Board, M, Player1))
					{
						if(CheckP(Board, White, MList))
						{
							if(CheckMate(Board, Black, MList))
							{
								BlackCheckmate = 1;
								break;
							}
							BlackCheck = 1;
						}
					}
					playerTurn = 2;
					turn++;
				}
				currentState = 1;
			}
			else if(playerTurn == 2)
			{
				switch (Player2)
				{
					case Human:
						getMove(input1,input2, &M);
						break;
					case AI:
						switch (AIType2)
						{
							case 1:
								do{
									M = Easy(Black, Board, MList);
								}while(Check(Board, M, White, MList));
								break;
							case 2:

								M = Medium(Black, Board, MList);
								break;
							/*case 3:
								M = Hard(Black, Board, MList);
								break;*/
							default:
								do{
									M = Medium(Black, Board, MList);
								}while(Check(Board, M, White, MList));
								break;
						}
				}
				if((castling = ValidMove(Board, M, MList, Black, 1)))
				{
					if(Check(Board, M, White, MList))
					{
						WhiteCheck = 1;
					}
					AddMove(MList, Board, &M);
					switch (castling)
					{
						case 1:
							MovePiece(Board, M);
							break;
						case 2:
							Castling(Board,M);
							break;
						case 3:
							EnPassant(Board, M);
							break;
					}		
					
					if(CheckMate(Board, White, MList))
					{
						WhiteCheckmate = 1;
					}
					
					if(PromotionCheck(Board, M, Player2))
					{
						if(CheckP(Board, Black, MList))
						{
							if(CheckMate(Board, White, MList))
							{
								WhiteCheckmate = 1;
								break;
							}
							WhiteCheck = 1;
						}
					}
					playerTurn = 1;
					turn++;
				}
				currentState = 1;
			}
			currentScreenDisplayed = 0;
		}
		
	}
	
	SaveLog("Log", 0, MList);
	DeleteMoveList(MList);
	
	/* free the surfaces and quit SDL */
	clean_up();

	return 0;
}
