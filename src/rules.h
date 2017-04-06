/* ---------------------------------------------------- */
/* rules.h - Header file for rules module		*/
/* ---------------------------------------------------- */

#ifndef RULES_H
#define RULES_H

#include <stdlib.h>
#include "ChessObj.h"
#include "MoveList.h"

MLIST *ValidList(int Color, t_Board b, MLIST *ValidMoveList, MLIST *MList);

/* Attacking Piece rule */
int PieceAttack(t_Board Board, t_Move Move);

/* Rules for Pawn */
int RulePawn(t_Board Board, t_Move Move, MLIST *List);

/* Rules for Knight */
int RuleKnight(t_Board Board, t_Move Move);

/* Rules for Rook */
int RuleRook(t_Board Board, t_Move Move);

/* Rules for Bishop */
int RuleBishop(t_Board Board, t_Move Move);

/* Rules for King */
int RuleKing(t_Board Board, t_Move Move, MLIST *List, int easybreak);


/* Rules for Queen */
int RuleQueen(t_Board Board, t_Move Move);

int ValidMove(t_Board Board, t_Move Move, MLIST *List, int Color, int easybreak);

int CheckP(t_Board Board, int Color,MLIST *List);

t_Piece WhatPiece(t_Board Board, t_Coords Coord);

void CopyBoard(t_Board Board, t_Board TempBoard);

int CheckMate(t_Board Board, int Color,MLIST *List);

int Check(t_Board Board, t_Move Move, int Color,MLIST *List);


#endif /* RULES_H */

/* EOF rules.h */
