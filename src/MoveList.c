/* MoveList.c: maintaining lists of Move */
#include "MoveList.h"

/* allocate a new Move list */
MLIST *NewMoveList(void)
{ 
	MLIST *l;
	l = malloc(sizeof(MLIST));

	if (! l)
	{ perror("Out of memory! Aborting...");
		exit(10);
	} /* fi */

	l->Length = 0;
	l->First = NULL;
	l->Last = NULL;
	return l;
} /* end of NewMoveList */


/* allocate a new move entry */
static MENTRY *NewMoveEntry(t_Board Board,t_Move *m)
{ 
	MENTRY *e;
	t_Move *move;
	t_Piece *piece;
	t_Piece *taken;
	e = malloc(sizeof(MENTRY));
	
	/* Make Sure to free these two */
	move = malloc(sizeof(t_Move));
	piece = malloc(sizeof(t_Piece));
	taken = malloc(sizeof(t_Piece));
	

	if (! e)
	{ perror("Out of memory! Aborting...");
		exit(10);
	} /* fi */
	move->From= m->From;
	move->To = m->To;
	piece->Player = Board[8-m->From.Rank][m->From.File -1].Player;
	piece->PieceType = Board[8-m->From.Rank][m->From.File -1].PieceType;
	taken->Player = Board[8-m->To.Rank][m->To.File -1].Player;
	taken->PieceType = Board[8-m->To.Rank][m->To.File -1].PieceType;
	e->List = NULL;
	e->Next = NULL;
	e->Prev = NULL;
	e->Piece = piece;
	e->Taken = taken;
/*	printf("Piece.Player = %d, Piece.PieceType = %d\n", (e->Piece->Player), (e->Piece->PieceType));
*/
	e->Move = move;
	return e;
} /* end of NewMoveEntry */


/* delete a Move entry */
void DeleteMoveEntry(MENTRY *e)
{ 
	MENTRY *prev = NULL;
	assert(e);
	if(e->List->Length == 0)
	{
		return;
	}
	else if(e->List->Length == 1)
	{
		e->List->First = NULL;
		e->List->Last = NULL;
	}
	else if(e->List->First == e)
	{
		e->List->First = e->Next;
		e->Next->Prev = NULL;
	}
	else if(e->List->Last == e)
	{
		e->List->Last = e->Prev;
		e->Prev->Next = NULL;
	}
	else
	{
		prev = e->Prev;
		prev->Next = e->Next;
		e->Next->Prev = prev;
	}
	
	e->List->Length -=1;
	free(e->Move);
	free(e->Piece);
	free(e->Taken);
	free(e);
} /* end of DeleteStudentEntry */


/* delete a Move list (and all entries) */
void DeleteMoveList(MLIST *l)
{
	MENTRY *e, *n;
	assert(l);
	e = l->Last;

	while(e)
	{ 
		n = e->Prev;
		DeleteMoveEntry(e);
		e = n;
	}
	
	free(l);
} /* end of DeleteMoveList */


/* append a move at end of list */
void AddMove(MLIST *l,t_Board Board,t_Move *m)
{ 
	MENTRY *e = NULL;
	assert(l);
	e = NewMoveEntry(Board,m);
	if (l->Last)
	{ 
		e->List = l;
		e->Next = NULL;
		e->Prev = l->Last;
		l->Last->Next = e;
		l->Last = e;
	}
	else
	{ 
		e->List = l;
		e->Next = NULL;
		e->Prev = NULL;
		l->First = e;
		l->Last = e;
	}
	l->Length++;
} /* end of AppendMove */


void RemoveLastMove(MLIST *l)
{ 
	MENTRY *e = NULL;
	assert(l);
	e = l->Last;
	e = e->Prev;
	DeleteMoveEntry(e);
} /* end of RemoveLastMove */



