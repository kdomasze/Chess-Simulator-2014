/*
 * MovePiece.c: Module for moving piece function
 *
 * 
 */

#include "GUI.h"
#include "MovePiece.h"
#include "ChessPieces.h"
#include <stdio.h>

/*moves piece to spot on board */

void MovePiece (t_Board Board, t_Move Move)
{
	/*t_Piece EmptyPiece = {Empty_Player, Empty_Piece};*/
	Board[8-Move.To.Rank][Move.To.File -1].Player = Board[8-Move.From.Rank][Move.From.File-1].Player;
	Board[8-Move.To.Rank][Move.To.File-1].PieceType = Board[8-Move.From.Rank][Move.From.File-1].PieceType;
	Board[8-Move.From.Rank][Move.From.File-1].Player = EmptyPiece.Player;
	Board[8-Move.From.Rank][Move.From.File-1].PieceType = EmptyPiece.PieceType;
	
/*	return Board;*/
}



void Castling(t_Board Board, t_Move Move)
{
	if(Move.To.File == 7)
	{
		Board[8-Move.To.Rank][5].Player = Board[8-Move.From.Rank][7].Player;
		Board[8-Move.To.Rank][5].PieceType = Board[8-Move.From.Rank][7].PieceType;
		Board[8-Move.From.Rank][7].Player = EmptyPiece.Player;
		Board[8-Move.From.Rank][7].PieceType = EmptyPiece.PieceType;
	}
	else if(Move.To.File == 3)
	{
		Board[8-Move.To.Rank][3].Player = Board[8-Move.From.Rank][0].Player;
		Board[8-Move.To.Rank][3].PieceType = Board[8-Move.From.Rank][0].PieceType;
		Board[8-Move.From.Rank][0].Player = EmptyPiece.Player;
		Board[8-Move.From.Rank][0].PieceType = EmptyPiece.PieceType;
	}
	/*t_Piece EmptyPiece = {Empty_Player, Empty_Piece};*/
	Board[8-Move.To.Rank][Move.To.File -1].Player = Board[8-Move.From.Rank][Move.From.File-1].Player;
	Board[8-Move.To.Rank][Move.To.File-1].PieceType = Board[8-Move.From.Rank][Move.From.File-1].PieceType;
	Board[8-Move.From.Rank][Move.From.File-1].Player = EmptyPiece.Player;
	Board[8-Move.From.Rank][Move.From.File-1].PieceType = EmptyPiece.PieceType;
	
/*	return Board;*/
}

void EnPassant(t_Board Board, t_Move Move)
{
	if(Move.To.Rank == 6)
	{
		Board[8-5][Move.To.File -1].Player = EmptyPiece.Player;
		Board[8-5][Move.To.File -1].Player = EmptyPiece.PieceType;
	}
	else if(Move.To.Rank == 3)
	{
		Board[8-4][Move.To.File -1].Player = EmptyPiece.Player;
		Board[8-4][Move.To.File -1].Player = EmptyPiece.PieceType;
	}	
	Board[8-Move.To.Rank][Move.To.File -1].Player = Board[8-Move.From.Rank][Move.From.File-1].Player;
	Board[8-Move.To.Rank][Move.To.File-1].PieceType = Board[8-Move.From.Rank][Move.From.File-1].PieceType;
	Board[8-Move.From.Rank][Move.From.File-1].Player = EmptyPiece.Player;
	Board[8-Move.From.Rank][Move.From.File-1].PieceType = EmptyPiece.PieceType;
}

void getMove(char input1[3],char input2[3], t_Move *Move)
{	
	/*printf("%s\n", input);*/
	Move->From.File = input1[0] - 96;
	Move->To.File = input2[0] - 96;

	Move->From.Rank = input1[1] - 48;
	Move->To.Rank = input2[1] - 48;
}	
/*	return Move;*/

void Promotion(t_Board Board, t_Move Move, int promote)
{
	Board[8 - Move.To.Rank][Move.To.File -1].PieceType = promote;
}

int PromotionCheck(t_Board Board, t_Move Move, int Player)
{
	int promote = 0;
	t_Piece piece;
	enum {Human, AI};
	
	piece = WhatPiece(Board,Move.To);
	if((Move.To.Rank == 1) || (Move.To.Rank == 8))
	{
		if(piece.PieceType == Pawn)
		{
			if(Player == AI)
			{
				Promotion(Board, Move, 0);
			}
			else
			{
				int displayPromote = 1;
				while(promote == 0)
				{
					if(displayPromote == 1)
					{
						displayPawnPromotion(1);
						displayPromote = 0;
						updateDisplay();
					}
					while(SDL_PollEvent(&event))
					{
						if(mouseClickPiece(265 + 60*3, 700-70, 69, 63))
						{
							promote = 1;
						}
						if(mouseClickPiece(265, 700-70, 50, 61))
						{
							promote = 2;
						}
						if(mouseClickPiece(265 + 65*2, 700-70, 42, 63))
						{
							promote = 3;
						}
						if(mouseClickPiece(265 + 60, 700-70, 63, 62))
						{
							promote = 4;
						}
					}
				}
				Promotion(Board,Move,promote - 1);
				displayPromote = 1;
				promote = 0;
			}
			return 1;
		}
	}
	return 0;
}




void UndoOnce(t_Board Board,MLIST *l)
{
	t_Move *m;
	MENTRY *e;
	
	e = l -> Last;
	m = e -> Move;

        Board[8-m->From.Rank][m->From.File -1].Player = e -> Piece -> Player;
		Board[8-m->From.Rank][m->From.File -1].PieceType = e -> Piece -> PieceType;

        Board[8-m->To.Rank][m->To.File-1].Player = e -> Taken -> Player;
        Board[8-m->To.Rank][m->To.File-1].PieceType = e -> Taken -> PieceType;

	RemoveLastMove(l);

}


void Undo(int x,t_Board Board,MLIST *l)
{
	/* Normal  Move */
	if(x == 0)
	{
		UndoOnce(Board,l);
		UndoOnce(Board,l);
	}
	/* Casr Move */
	else if(x == 1)
	{
		UndoOnce(Board,l);
		UndoOnce(Board,l);
		UndoOnce(Board,l);
	}
	/* During the Frist Move */
	else if(x == 2)
	{
		printf("No undo for the first move/n");
	}
}
