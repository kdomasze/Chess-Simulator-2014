

#include <stdio.h>
#include <stdlib.h>
#include "ChessObj.h"
#include "ChessPieces.h"
#include "GUI.h"
#include "rules.h"
#include "MovePiece.h"
#include "MoveList.h"
#include "AI.h"


int main()
{
	
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

		t_Move Move;

		char input1[3];
		char input2[3];
		int option;
		int valid;
		MLIST *empty;
		empty = NewMoveList();

		int count;
		while(1)
		{	
			printf("Test module!\nThe board will be set to initial conditions.\n\n1: Move pieces Freely\n2: Test rules without piece movement of any piece.\n Board will display after every 5 test.\n3: Creates a .txt file with the move you have entered\n4: Any choice besides 1, 2, and 3 exits program\nPlease make your choice: ");
			scanf("%d", &option);
			switch(option)
			{	
				case 1:
					while(1)
					{DisplayBoard(Board);
					printf("Enter move (a2 a3) and enter y to return to previous menu: ");
					scanf("%s",input1);
					if(input1[0] == 'y')
					{
						break;
					}
					scanf("%s",input2);
					getMove(input1, input2, &Move);
					AddMove(empty, &Board[8-Move.From.Rank][Move.From.File-1], &Move);
					MovePiece(Board, Move);
					}
					break;

				case 2:
					while(1)
					{
						DisplayBoard(Board);
						for(count = 0; count <5; count++)
						{
							printf("Enter move (a2 a3) and enter y to return to previous menu: ");
							scanf("%s",input1);
							if(input1[0] == 'y')
							{
							break;
							
							}
							scanf("%s",input2);
							getMove(input1,input2, &Move);
							valid= ValidMove(Board,Move,empty,Board[8-Move.From.Rank][Move.From.File -1].Player);
							if(valid)
							{printf("Valid Move\n");}
							else
							{printf("Invalid Move\n");}
						}
						if(input1[0] == 'y')
						{
							break;
						}
					}
					break;
			case 3:
			  					while(1)
					{DisplayBoard(Board);
					printf("Enter move (a2 a3) and enter y to return to previous menu: ");
					scanf("%s",input1);
					if(input1[0] == 'y')
					{
					
					  break;
					}
					scanf("%s",input2);
					getMove(input1, input2, &Move);
					AddMove(empty, &Board[8-Move.From.Rank][Move.From.File-1], &Move);
					MovePiece(Board, Move);
					}
					SaveLog("SaveFile", 1, empty);
					break;
				default:
					printf("Thank you for testing Board Display\n");
					return 0;
					break;	
		}}
	return 0;	
}
