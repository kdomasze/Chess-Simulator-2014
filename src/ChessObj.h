/* ChessObj.h
 * Header file holding the prototypes and data
 * structures for the chess objects
 *
 * Written by: Kyle Domaszewicz
 * Created on: 1/21/14
 *
 * Rev. history:
 * 1/21/14 12:16PM:	Initial Creation(KD)
 * 1/21/14 02:21PM:	Added Chess Pieces(KD)
 * 1/21/14 04:28PM:	Added Move Structure(CB)
 * Chess Simulator 2014 is licensed under a Creative
 * Commons Attribution-Noncommercial 4.0 
 * International License.
 */

#ifndef CHESSOBJ_H
#define CHESSOBJ_H

typedef enum Player 
{
	Empty_Player,
	White, 
	Black
} t_Player;

typedef enum PieceType 
{
	Queen, 
	Rook, 
	Bishop, 
	Knight, 
	King, 
	Pawn,
	Empty_Piece
} t_PieceType;

typedef struct Piece
{
	t_Player Player;
	t_PieceType PieceType;
} t_Piece;

typedef t_Piece t_Board[8][8];

typedef struct Coords
{
	int Rank;
	int File;
}t_Coords;

typedef struct Move
{

	t_Coords From;
	t_Coords To;
}t_Move;




#endif
