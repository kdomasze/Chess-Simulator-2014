#ifndef AI_H
#define AI_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "MovePiece.h"
#include "rules.h"

t_Move Easy(int Color, t_Board Board, MLIST *List);

t_Move Medium(int Color, t_Board Board, MLIST *List);

t_Move Hard(int Color, t_Board Board, MLIST *List);

int Random(int Limit);

/* Gives a Ranking to each Chess Piece*/
int Rank(int Piece);

/* t_Move Opening(int Color, t_Move Move, int Count);
 */
/* int FutureAIMove(int Color, t_Board TempBoard, int MoveValue, MLIST *PossibleMoveList, MLIST *List);

int FutureOpponentMove(int Color, t_Board TempBoard, int MoveValue, MLIST *PossibleMoveList, MLIST *List); */

int DetermineMoveValue(int Color, t_Board, MLIST *List);

#endif
