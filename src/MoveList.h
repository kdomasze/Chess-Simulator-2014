/* MoveList.h: header file for lists of move */

#ifndef MOVE_LIST_H
#define MOVE_LIST_H

#include "ChessObj.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct MoveList MLIST;
typedef struct MoveEntry MENTRY;

struct MoveList
{ 	
	int Length;
	MENTRY *First;
	MENTRY *Last;
};

struct MoveEntry
{ 
	MLIST *List;
	MENTRY *Next;
	MENTRY *Prev;
	t_Move *Move;
	t_Piece *Piece;
	t_Piece *Taken;
};
void DeleteMoveEntry(MENTRY *e);
MLIST *NewMoveList(void);

void DeleteMoveList(MLIST *l);

void AddMove(MLIST *l, t_Board Board, t_Move *m);

void RemoveLastMove(MLIST *l);

void DeleteMoveEntry(MENTRY *e);

#endif /* MOVE_LIST_H */
/* EOF */
