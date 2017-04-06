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

int main()
{
	enum {Human, AI};
	/*int x, y;*/
	int GameType, AIType, AIType2, PlayerColor;
	int Player1, Player2;
	int turn = 1;
	int castling = 0;
	char LogName;

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

	MLIST *PList;
	MLIST *MList;
	
	PList = NewMoveList();
	MList = NewMoveList();

	t_Move M;

	/* Display opponent menu and prompt for player choice */
	DisplayOpponentMenu();
	scanf("%d", &GameType);
	
	/* Display menu for choosing color */
	DisplayColorMenu();
	scanf("%d", &PlayerColor);
	while(PlayerColor != 1 && PlayerColor != 2)
	{
		printf("\nInvalid Value. Please enter 1 or 2: ");
		scanf("%d", &PlayerColor);
	}
	
	switch (GameType)
	{
		case 1:
			switch (PlayerColor)
			{
				case 1:
					Player1 = Human;
					Player2 = AI;
					DisplayDifficultyMenu(Player2);
					scanf("%d", &AIType2);
					break;
				case 2:
					Player1 = AI;
					DisplayDifficultyMenu(Player1);
					scanf("%d", &AIType);
					Player2 = Human;
					break;
			}
			break;
		case 2:
			Player1 = Player2 = Human;
			break;
		case 3:
			Player1 = Player2 = AI;
			DisplayDifficultyMenu(Player1);
			scanf("%d", &AIType);
			DisplayDifficultyMenu(Player2);
			scanf("%d", &AIType2);
			break;
	}

	DisplayGameStart();
	DisplayBoard(Board);
	while(1)
	{	
		/* switch from one string to two because scanf doesn't support whitespace */
		char input1[3];
		char input2[3];

		/* First Player's Turn */
		DisplayTurn(White, Player1);
		printf("Turn %d \n", turn++);
		switch (Player1)
		{
			case Human:
				/*while((test = getchar())!= EOF && test != '\n');
				fgets(input,6, stdin);*/
				scanf("%s %s",input1, input2);
				getMove(input1, input2, &M);

				/*printf("input = %s\n", input);*/
				/*printf("Enter any key to continue...");
				scanf("%c",&test);
				*/			
				/*scanf("%s", input);*/

				while(!(castling =ValidMove(Board, M, MList, White)))
				{
					printf("Invalid move. Try again: ");
					/*while((test = getchar())!= EOF && test != '\n');*/
				/*	fgets(input,6, stdin);*/
					scanf("%s %s",input1, input2);
					getMove(input1,input2, &M);
				}
				break;
			case AI:
				switch (AIType)
				{
					case 1:
						M = Easy(White, Board, MList);
						break;
					case 2:
				/*		Medium();
						break;
					case 3:
						Hard;
						break;
				*/
					default:
						M = Easy(White, Board, MList);
						break;
				}
				break;
		}
		if(Check(Board, M, Black, MList))
		{
			if(CheckMate(Board,Black,MList))
			{
				printf("CHECKMATE\n");
			}
			printf("CHECK\n");
		}
		AddMove(MList, Board, &M);
		if(castling ==1)
		{
			MovePiece(Board, M);
		}
		else if(castling == 2)
		{
			Castling(Board,M);
		}
		DisplayBoard(Board);
		PromotionCheck(Board, M);
		DisplayTurn(Black, Player2);
		printf("Turn %d\n", turn++);
			
		switch (Player2)
		{
			case Human:
				/*while((test = getchar())!= EOF && test != '\n');
				fgets(input,6, stdin);*/
				
				scanf("%s %s",input1, input2);
				getMove(input1,input2, &M);
				while(!ValidMove(Board, M, MList, Black))
				{
					printf("Invalid move. Try again: ");
					/*while((test = getchar())!= EOF && test != '\n');
					fgets(input,6, stdin);*/
					scanf("%s %s",input1, input2);
					getMove(input1,input2, &M);
				}
				break;
			case AI:
				switch (AIType2)
				{
					case 1:
						do
						{
							M = Easy(Black, Board, MList);
						}while(Check(Board, M, White,MList));
						break;
					case 2:
						do{
						M = Medium(Black, Board, MList);
						}while(Check(Board,M,White,MList));
						break;
				/*	case 3:
						Hard;
						break;
				*/
					default:
						do{
						M = Easy(Black, Board, MList);
						}while(Check(Board,M,White,MList));
						break;
				}
		}

		/* Record and Move the piece on the board */
		AddMove(MList, Board, &M);
		if(Check(Board, M, White, MList))
		{
			if(CheckMate(Board,White,MList))
			{
				printf("CHECKMATE\n");
			}
			printf("CHECK\n");
		}
		if(castling ==1)
		{
			MovePiece(Board, M);
		}
		else if(castling == 2)
		{
			Castling(Board,M);
		}	
		DisplayBoard(Board);
		PromotionCheck(Board, M);
		
		/* If Player2 is checked, check if checkmate */
	/*	if (isCheck(Board, Color2))
		{
			if (isCheckmate(Board, Color2))/
				break;
		}
	*/

		/* 
<<<<<<< Chess.c

=======
		
		MENTRY *e = NULL;
		e = MList->First;
		while(e)
		{
			printf("Player = %d, Piece = %d\n", e->Piece->Player, e->Piece->PieceType);
			e = e->Next;
		}
>>>>>>> 1.8
	*/
	
	/*If Player1 is checked, check if checkmate  */
	/*	if (isCheck(Board, Color))
		{
			if (isCheckmate(Board, Color))
	 			break;
		}
	*/
	}
	/*printf("Please enter a name to save log: ");
	scanf("%s",&LogName);
	SaveLog(LogName, 1, l);*/
	
	printf ("Enter a file name for the log: ");
	scanf("%s", &LogName);
	/*SaveLog(LogName, 1, MList);*/
	DeleteMoveList(PList);
	DeleteMoveList(MList);
	
	return 0;
}
