
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

		printf("Printing out Initial Board, input Moves as desired to check piece movement and board being modified, rules are not being checked so move as you want.\n\n");
		while(1)
		{	
			DisplayBoard(Board);
			printf("Enter move (a2 a3) and enter y to exit: ");
			scanf("%s",input1);
			if(input1[0] == 'y')
			{
				break;
			}
			scanf("%s",input2);
			getMove(input1, input2, &Move);
			MovePiece(Board, Move);
			
		}
	printf("Thank you for testing Board Display\n");
	return 0;
				
}
