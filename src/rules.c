#include "rules.h"
#include <stdio.h>
#include "MovePiece.h"


int PieceAttack(t_Board Board, t_Move Move)
{
	t_Piece attack;
	t_Piece defend;
	int x,y;

	x = Move.From.File;
	y = Move.From.Rank;
	attack.Player = (Board[8-y][x-1]).Player;

	x = Move.To.File;
	y = Move.To.Rank;
	defend.Player = Board[8-y][x-1].Player;

	return(attack.Player != defend.Player);
	
}

/* Rules for Pawn */
int RulePawn(t_Board Board, t_Move Move, MLIST *List)
{
	int x1, x2, y1, y2, x, y, p2x1,p2y1, p2x2,p2y2;
	int lastPiece;
	t_Move Move2;
	x1 = Move.From.File;	
	y1 = Move.From.Rank;
	x2 = Move.To.File;
	y2 = Move.To.Rank;
	y = abs(y1-y2);
	x = abs(x1-x2);

	/*printf("Made it inside Pawn rule\n");
	printf("x = %d and y = %d x1= %d, x2 = %d, y1 = %d, y2 = %d",x, y,x1,x2,y1,y2);
	printf("Enter any key to continue...");
	scanf("%c",&test);*/
	if(Board[8-y1][x1-1].Player == Black && y1 < y2)
	{
		/*printf("Trying to move Black pawn up\n");*/
		return 0;
	}
	else if(Board[8-y1][x1-1].Player == White && y1 > y2)
	{
		/*printf("Trying to move White Pawn downn");*/
		return 0;	
	}
	
	if(x == 1 && y == 1)
	{	/*printf("Pawn attack\n");*/
		if(Board[8-y2][x2-1].Player == Empty_Player)
		{	
			if((y1 == 5 || y1 ==4)  && List->First != NULL)
			{
				lastPiece = List->Last->Piece->PieceType;
				/*printf("PieceType = %d\n", lastPiece);*/
				if(lastPiece == Pawn)
				{	
					Move2 = *(List->Last->Move);
					p2x1 = Move2.From.File;	
					p2y1 = Move2.From.Rank;
					p2x2 = Move2.To.File;
					p2y2 = Move2.To.Rank;
					if((abs(p2y1 - p2y2) == 2) && (x2 == p2x1))
					{
						return 3;
					}
				}
			
			}
			return 0;
		}
		return PieceAttack(Board, Move);
	}
	else if((y == 1 || y == 2) && x == 0)
	{
		/*printf("Made it here finally\n");*/
		if(y == 1)
		{
			if(Board[8-y2][x2-1].Player == Empty_Player)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if(y1 == 2 || y1 == 7)
		{
			if(Board[8-y2][x2-1].Player == Empty_Player)
			{
				switch(y1)
				{
					case 2:
						if(Board[8-y2+1][x2-1].Player == Empty_Player)
						{
							return 1;	
						}
						else{return 0;}
						break;
					case 7:
						if(Board[8-y2-1][x2-1].Player == Empty_Player)
						{
							return 1;	
						}
						else{return 0;}
						break;
					default:
						return 0;
						break;
				}
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

/* Rules for Knight */
int RuleKnight(t_Board Board, t_Move Move)
{
	int x,y;
	
	y = abs(Move.From.Rank - Move.To.Rank);
	x = abs(Move.From.File - Move.To.File);

	if((x == 1 && y == 2) || (x == 2 && y == 1))
	{
		return(PieceAttack(Board, Move));
	}
	else
	{
		return 0;
	}
}

/* Rules for Rook */
int RuleRook(t_Board Board, t_Move Move)
{
	int x1, x2, y1, y2, x, y;
	x1 = Move.From.File;	
	y1 = Move.From.Rank;
	x2 = Move.To.File;
	y2 = Move.To.Rank;
	y = abs(y1-y2);
	x = abs(x1-x2);
/*	printf("x = %d, y = %d\n", x, y);
*/	
	if((x >= 0 && y == 0) || (y >= 0 && x == 0))
	{
		if(y == 0)
		{
			if(x1 < x2)
			{x1++;
				while( x1 < x2)
				{
					if(Board[8-y1][x1-1].PieceType 
							!= Empty_Piece)
					{
						return 0;
					}
					x1++;
				}
				return PieceAttack(Board, Move);
			}
			else if(x1 > x2)
			{x1--;
				while( x1 > x2)
				{
					if(Board[8-y1][x1-1].PieceType 
							!= Empty_Piece)
					{
						return 0;
					}
					x1--;
				}
				return PieceAttack(Board, Move);
			}
		}
		else
		{
			if(y1 < y2)
			{y1++;
				while( y1 < y2)
				{
					if(Board[8-y1][x1-1].PieceType 
							!= Empty_Piece)
					{
						return 0;
					}
					y1++;
				}
				return PieceAttack(Board, Move);
			}
			else if(y1 > y2)
			{y1--;
				while( y1 > y2)
				{
					if(Board[8-y1][x1-1].PieceType 
							!= Empty_Piece)
					{
						return 0;
					}
					y1--;
				}
				return PieceAttack(Board, Move);
			}
		}
	}
	return 0;
	
}

/* Rules for Bishop */
int RuleBishop(t_Board Board, t_Move Move)
{
	int x1, x2, y1, y2, x, y;
	x1 = Move.From.File;	
	y1 = Move.From.Rank;
	x2 = Move.To.File;
	y2 = Move.To.Rank;
	y = abs(y1-y2);
	x = abs(x1-x2);

/*	printf("x = %d, y = %d\n", x, y);
*/
	if(x == y && y > 0)
	{
		if(x1 < x2)
		{
			if(y1 < y2)
			{
					x1++;
					y1++;
				while( y1 < y2)
				{	
					if(Board[8-y1][x1-1].PieceType 
							!= Empty_Piece)
					{
						return 0;
					}
					x1++;
					y1++;
				}
				return PieceAttack(Board, Move);
			}
			else if(y1 > y2)
			{
					x1++;
					y1--;
				while( y1 > y2)
				{
					if(Board[8-y1][x1-1].PieceType 
							!= Empty_Piece)
					{
						return 0;
					}
					x1++;
					y1--;
				}
				return PieceAttack(Board, Move);
			}
		}
		else if(x1 > x2)
		{
			if(y1 < y2)
			{
					x1--;
					y1++;
				while( y1 < y2)
				{	
					if(Board[8-y1][x1-1].PieceType 
							!= Empty_Piece)
					{
						return 0;
					}
					x1--;
					y1++;
				}
				return PieceAttack(Board, Move);
			}
			else if(y1 > y2)
			{
					x1--;
					y1--;
				while( y1 > y2)
				{
					if(Board[8-y1][x1-1].PieceType 
							!= Empty_Piece)
					{
						return 0;
					}
					x1--;
					y1--;
				}
				return PieceAttack(Board, Move);
			}
		}
	
	
	}
	return 0;
	
}

/* Rules for King */
int RuleKing(t_Board Board, t_Move Move, MLIST *List, int easybreak)
{
	int x1, x2, y1, y2, x, y;
	x1 = Move.From.File;	
	y1 = Move.From.Rank;
	x2 = Move.To.File;
	y2 = Move.To.Rank;
	y = abs(y1-y2);
	x = abs(x1-x2);
	

	if((x <= 1 && y <= 1) && (x == 1 || y ==1))
	{
		return PieceAttack(Board, Move);
	}
	else if(x == 2 && y == 0 && easybreak)
	{
		int lrook, rrook, king;
		MENTRY *entry = NULL;
		entry = List->First;
		lrook = rrook = king = 0;
		if(!RuleRook(Board,Move))
		{
			return 0;
		}
		if(y1 == 1)
		{
			while(entry)
			{
				if((entry->Move->From.File == 1) && (entry->Move->From.Rank == 1))
				{
					lrook = 1;
				}
				else if((entry->Move->From.File == 5) && (entry->Move->From.Rank == 1))
				{
					king = 1;
				}
				else if((entry->Move->From.File == 8) && (entry->Move->From.Rank == 1))
				{
					rrook = 1;
				}
				entry = entry->Next;
			}
		}
	
		else if(y1 == 8)
		{
			while(entry)
			{
				if((entry->Move->From.File == 1) && (entry->Move->From.Rank == 8))
				{
					lrook = 1;
				}
				else if((entry->Move->From.File == 5) && (entry->Move->From.Rank == 8))
				{
					king = 1;
				}
				else if((entry->Move->From.File == 8) && (entry->Move->From.Rank == 8))
				{
					rrook = 1;
				}
				entry = entry->Next;
			}
		}
		
		if(king)
		{
			return 0;
		}
		
		if(Move.To.File == 7 && !rrook)
		{
			t_Move m = {{y1,5},{y1,5}};
		/*	printf("File = %d, Rank = %d", m.From.File, m.From.Rank);*/
			t_Piece p = WhatPiece(Board, Move.From);
			t_Move mRook = {{y1, 8}, {y1, 6}};
			if(!RuleRook(Board,mRook))
			{
				return 0;
			}
			if(Check(Board, m, p.Player, List))
			{
				return 0;
			}
			m.To.File = 6;
			if(Check(Board, m, p.Player, List))
			{
				return 0;
			}
			if(Check(Board, Move, p.Player, List))
			{
				return 0;
			}
		}
		if(Move.To.File == 3 && !lrook)
		{
			t_Move m = {{y1,5},{y1,5}};
			t_Piece p = WhatPiece(Board, Move.From);
			t_Move mRook = {{y1, 1}, {y1, 4}};
			if(!RuleRook(Board,mRook))
			{
				return 0;
			}
			if(Check(Board, m, p.Player, List))
			{
				return 0;
			}
			m.To.File = 4;
			if(Check(Board, m, p.Player, List))
			{
				return 0;
			}
			if(Check(Board, Move, p.Player, List))
			{
				return 0;
			}
		}
		return 2;
	}
	else
	{
		return 0;
	}
}

/* Rules for Queen */
int RuleQueen(t_Board Board, t_Move Move)
{
	return (RuleRook(Board, Move) || RuleBishop(Board, Move));
}	

t_Piece WhatPiece(t_Board Board, t_Coords Coord)
{
	return(Board[8-Coord.Rank][Coord.File -1]);
}

int ValidMove(t_Board Board, t_Move Move, MLIST *List, int Color, int easybreak)
{
	t_Piece piece;
	int x,y;
	x = Move.From.File;
	y = Move.From.Rank;
	piece= Board[8-y][x-1];
	if(piece.Player != Color)
	{
		return 0;
	}
	

	switch(piece.PieceType)
	{
		case Pawn: 
			return(RulePawn(Board, Move, List));
			break;
		case King:
 return(RuleKing(Board, Move, List, easybreak));
			break;
		case Queen: 
return(RuleQueen(Board, Move));
			break;
		case Bishop:
 return(RuleBishop(Board, Move));
			break;
		case Rook: 
return(RuleRook(Board, Move));
			break;
		case Knight: 
return(RuleKnight(Board, Move));
			break;
		default:
			return 0;
			break;
	}
}

/* AI can choose a ramdom move from the list during the white's turn, If player is in white side, then compare the input to every moves in the list */
MLIST *ValidList(int Color, t_Board b, MLIST *ValidMoveList, MLIST *MList)
{
	t_Move m;
	int x, y;
	int i, j;
	/* two for loop to load every piece's location on the board */
	for(x = 1; x < 9 ; x++)
		for(y = 1; y < 9; y++)
		{
			/* check if there a piece on (x,y) location, and check the color of the piece */
			if((b[8-y][x-1].Player) != Empty_Player && (b[8-y][x-1].Player) == Color)
			{
				/* store (x,y) location to t_Move's From */
				m.From.Rank = y;
				m.From.File = x;

				/* two for loop to load every location on the board  */
				for(i = 1; i < 9 ; i++)
					for(j = 1; j < 9; j++)
					{
						/* store the location (i,j) which loaded to t_Move's To */
						m.To.File = i;
						m.To.Rank = j;

						/* call the ValidMove function from the rules.c module to check is this a valid move which from (x,y) to (i,j) */
						if(ValidMove(b, m, MList, Color, 0) == 1)
						{
							/* a if statement to skip the location which (x,y) equal to (i,j) */
							if(x != i || y != j)
							{
								/* Add this t_Move to the MoveList */
								AddMove(ValidMoveList,b,&m);
							}
						}
					}
			}
		}
	return ValidMoveList;
}


/* Copies Current board to a Temp Board */
void CopyBoard(t_Board Board, t_Board TempBoard)
{
	int i, j;
	
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			TempBoard[i][j] = Board[i][j];
		}
	}
}
	
int Check(t_Board Board, t_Move Move, int Color,MLIST *List)
{
	int count=0;
	t_Board tempBoard;
	MLIST *ValidMoveList = NULL;
	ValidMoveList = NewMoveList();
	CopyBoard(Board, tempBoard);
	MovePiece(tempBoard, Move);
	/*printf("Here\n");*/
	ValidList(Color, tempBoard, ValidMoveList,List);
	/*printf("NotHere\n")*/;
	MENTRY *p = ValidMoveList->First;
	
	while(p)
	{
		if(King == p->Taken->PieceType)
		{
			count = 1;
			break;
		}
		p = p->Next;
	}
	DeleteMoveList(ValidMoveList);
	return count;
}

int CheckP(t_Board Board, int Color,MLIST *List)
{
	int count=0;
	MLIST *ValidMoveList = NULL;
	ValidMoveList = NewMoveList();
	ValidList(Color, Board, ValidMoveList,List);
	MENTRY *p = ValidMoveList->First;
	
	while(p)
	{
		if(King == p->Taken->PieceType)
		{
			count = 1;
			break;
		}
		p = p->Next;
	}
	DeleteMoveList(ValidMoveList);
	return count;
}

int CheckMate(t_Board Board, int Color,MLIST *List)
{
	int count = 1;
	t_Board tempBoard;
	MLIST *ValidMoveList = NULL;
	ValidMoveList = NewMoveList();
	CopyBoard(Board, tempBoard);
	ValidList(Color, tempBoard, ValidMoveList, List);
	MENTRY *p = ValidMoveList->First;
	
	while(p)
	{
		if(!Check(tempBoard, *(p->Move), Color == White?Black:White, List))
		{
			count = 0;
			break;
		}
		p = p->Next;
	}
	DeleteMoveList(ValidMoveList);
	return count;
}	
