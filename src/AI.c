/*
 * AI.c: Module for AI player for chess program
 *
 * Rev. History:
 * 1/21/14: Initial Creation (AD)
 * 1/22/14: Commenting for clarity (AD)
 * 1/24/14: Added valid Movelist functions(AD)
 * 1/25/14: Edited function to return Move(AD)
 * 1/28/14: Added Medium AI, Made random number generator function (FP)
 *
 */

#include "AI.h"
#include <stdio.h>

t_Move Easy(int Color, t_Board Board, MLIST *List)
{
	t_Move Move;
	MLIST *ValidMoveList;
	ValidMoveList = NewMoveList();
	
	ValidList(Color, Board, ValidMoveList, List);
	
	MENTRY *p;

	int i;
	int randnum;

	int num = -1;

	/* Initiate random function based on time */
	/* Traverse the ValidMoveList using a loop for the chosen random number of times */

	do
	{		
		if(-1 != num)
		{	
			p = ValidMoveList->First;
			for(i=0; i < num; i++)
			{
				p = p->Next;
			}
			DeleteMoveEntry(p);
			p = ValidMoveList->First;
			num = -1;
		}
		p = ValidMoveList->First;
		randnum = Random(ValidMoveList->Length);
		for (i = 0; i < randnum; i++)
		{
			p = p->Next;
		}
		num = i;
		/* Assign chosen move to Move */
		Move.From.File = p->Move->From.File;
		Move.From.Rank = p->Move->From.Rank;
		Move.To.File = p->Move->To.File;
		Move.To.Rank = p->Move->To.Rank;
	
		}while(Check(Board,Move, Color == White?Black:White, List) && -1 != num);
	

	/* printf("Player = %d, PieceType = %d\n", p->Piece->Player, p->Piece->PieceType);*/

	DeleteMoveList(ValidMoveList);
	return Move;
}

t_Move Medium(int Color, t_Board Board, MLIST *List)
{	
	t_Move Move;
	MLIST *ValidMoveList;
	ValidMoveList = NewMoveList();
	
	/* Makes List of Valid Moves for AI*/
	ValidList(Color, Board, ValidMoveList, List);
	
	MENTRY *p = ValidMoveList->First;
	int i;								/* Used to index through list */
	int TempValue = 0; 					/* Used for compare */
	int PieceValue;						/* Stores the value of captured piece*/
	int randnum;
	t_Piece OpPiece;
	int num = -1;
	/* Traverse through ValidMoveList search for high value move */
	do{
		if(-1 != num)
		{p = ValidMoveList->First;
			for(i=0; i < num; i++)
			{
				p = p->Next;
			}
			DeleteMoveEntry(p);
			p = ValidMoveList->First;
			TempValue = 0;
			num = -1;
		}
	for (i = 0; i < ValidMoveList->Length; i++)
	{
		OpPiece = WhatPiece(Board, p->Move->To);
		PieceValue = Rank(OpPiece.PieceType);
		/*printf("Piece Value = %d\n", PieceValue);*/
		
		if (PieceValue > TempValue) 
		{
			TempValue = PieceValue;
			num = i;
			/* Assign chosen move to Move */
			Move.From.File = p->Move->From.File;
			Move.From.Rank = p->Move->From.Rank;
			Move.To.File = p->Move->To.File;
			Move.To.Rank = p->Move->To.Rank;			
		}
		
		p = p->Next;
	
	}
	
	if (TempValue == 0||TempValue == 6) 
	{
		p = ValidMoveList->First;
		
		randnum = Random(ValidMoveList->Length);
		
		for (i = 0; i < randnum; i++)
		{
			p = p->Next;
		}
		
		/* Assign chosen move to Move */
		Move.From.File = p->Move->From.File;
		Move.From.Rank = p->Move->From.Rank;
		Move.To.File = p->Move->To.File;
		Move.To.Rank = p->Move->To.Rank;
		num = i;
	}

	}while(Check(Board,Move, Color == White?Black:White, List) && -1 != num);
	
	DeleteMoveList(ValidMoveList);
	
	return Move;
}

t_Move Hard (int Color, t_Board Board, MLIST *List)
{	
	t_Move Move;
	t_Move TempMove;
	
	t_Board TempBoard;
	
	MLIST *ValidMoveList;
	MLIST *NoCaptureList;
	MLIST *OpponentMoves;
	
	t_Piece OpPiece;
	t_Piece AIPiece;
	
	ValidMoveList = NewMoveList();
	NoCaptureList = NewMoveList();
	OpponentMoves = NewMoveList();
	
	/* Makes List of Valid Moves for AI*/
	ValidList(Color, Board, ValidMoveList, List);
	
	MENTRY *p = ValidMoveList->First;
	int i, j;								/* Used to index through list */
	int TempValue = 0; 					/* Used for compare */
	int NewTempValue;
	int PieceValue;						/* Stores the value of captured piece*/
	int AIPieceValue;
	int randnum;
	int BestValue = 0;					/* Stores value of best move*/

	int OpColor;
	if (Color == 1)
	{
		OpColor = 2;
	}
	if (Color == 2)
	{
		OpColor = 1;
	}
	
	int num = -1;
	do
	{
		if(-1 != num)
		{
			p = p->Next;
		}
		DeleteMoveEntry(p);
		p = ValidMoveList->First;
		
		num = -1;
	/* Traverse through ValidMoveList search for high value move */
	for (i = 0; i < ValidMoveList->Length; i++)
	{
		OpPiece = WhatPiece(Board, p->Move->To);
		PieceValue = Rank(OpPiece.PieceType);
		
		/* Copy original board to tempboard */
		CopyBoard(Board, TempBoard);
		
		/* Move does not capture a piece */
		if (PieceValue == 0)
		{
			AddMove(NoCaptureList, Board, p->Move);
		}
		
		/* Move captures opponent's piece */
		if (PieceValue > TempValue && PieceValue != 6) 
		{
			TempValue = PieceValue;

			/* Assign chosen move to Move */
			TempMove.From.File = p->Move->From.File;
			TempMove.From.Rank = p->Move->From.Rank;
			TempMove.To.File = p->Move->To.File;
			TempMove.To.Rank = p->Move->To.Rank;
			
			/* Make move on temporary board */
			MovePiece(TempBoard, TempMove);

			/* Check if this is a good move */	
			ValidList(OpColor, TempBoard, OpponentMoves, List);
			
			for (j = 0; j < OpponentMoves->Length; j++)
			{
				AIPiece = WhatPiece(Board, OpponentMoves->First->Move->To);
				AIPieceValue = Rank(OpPiece.PieceType);
				
				NewTempValue = TempValue - AIPieceValue;
				if (NewTempValue > BestValue)
				{
					BestValue = NewTempValue;
					
					/* Assign chosen move to Move */
					Move.From.File = OpponentMoves->First->Move->From.File;
					Move.From.Rank = OpponentMoves->First->Move->From.Rank;
					Move.To.File = OpponentMoves->First->Move->To.File;
					Move.To.Rank = OpponentMoves->First->Move->To.Rank;
				}
			}
			
		}
		
		p = p->Next;
	
	}
	
	/* What to do if none of the moves capture a piece or BestValue == 0 */
	if (BestValue == 0 && BestValue != 6) 
	{
		MENTRY *n = NoCaptureList->First;
		
		randnum = Random(NoCaptureList->Length);
		
		for (i = 0; i < randnum; i++)
		{
			n = n->Next;
		}
		num = i;
		/* Assign chosen move to Move */
		Move.From.File = n->Move->From.File;
		Move.From.Rank = n->Move->From.Rank;
		Move.To.File = n->Move->To.File;
		Move.To.Rank = n->Move->To.Rank;
	}
	} while(Check(Board,Move, Color == White?Black:White, List) && -1 != num);
	
	DeleteMoveList(ValidMoveList);
	DeleteMoveList(NoCaptureList);
	DeleteMoveList(OpponentMoves);
	
	return Move;
}

int Rank(int Piece)
{	
	switch(Piece)
	{
		case 0: /* Queen */
			return 5;
			break;
		case 1: /* Rook */
			return 4;
			break;
		case 2: /* Bishop */
			return 4;
			break;
		case 3: /* Knight */
			return 4;
			break;
		case 4: /* King */
			return 6;
			break;
		case 5: /* Pawn */
			return 1;
			break;
		case 6: /* Empty Piece*/
			return 0;
			break;
		default:
			return 0;
			break;
	}
}

int Random(int Limit)
{
	srand(time(NULL));
	return rand()%(Limit);
}
