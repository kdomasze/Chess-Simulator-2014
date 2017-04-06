/*
 *MovePiece.h: header file for MovePiece.c
 *
 */
#ifndef MOVEPIECE_H
#define MOVEPIECE_H

#include <stdio.h>
#include "ChessObj.h"
#include "MoveList.h"
#include "rules.h"

void MovePiece (t_Board Board, t_Move Move);
void getMove(char input1[3],char input2[3], t_Move *Move);
int PromotionCheck(t_Board Board, t_Move Move, int Player);
void Promotion(t_Board Board, t_Move Move, int Promote);
void Castling(t_Board Board, t_Move);
void UndoOnce(t_Board Board,MLIST *l);
void Undo(int x,t_Board Board,MLIST *l);
void EnPassant(t_Board Board, t_Move Move);


#endif
