/* ChessPieces.h
 * Header file for module holding the Chess Piece variables
 *
 * Written by: Kyle Domaszewicz
 * Created on: 1/21/14
 *
 * Rev. history:
 * 1/21/14 03:45PM:	Initial Creation(KD)
 * 1/25/14 04:37PM: Added InitialBoard(AD)
 * 1/25/14 11:49PM: Split into ChessPieces.c and ChessPieces.h
 * Chess Simulator 2014 is licensed under a Creative
 * Commons Attribution-Noncommercial 4.0 
 * International License.
 */

#ifndef CHESSPIECES_H
#define CHESSPIECES_H

#include "ChessObj.h"

		  static t_Piece BlackRook = {Black, Rook};
		  static t_Piece BlackKnight = {Black, Knight};
		  static t_Piece BlackBishop = {Black, Bishop};
		  static t_Piece BlackKing = {Black, King};
		  static t_Piece BlackQueen = {Black, Queen};
		  static t_Piece BlackPawn = {Black, Pawn};

		  static t_Piece WhiteRook = {White, Rook};
		  static t_Piece WhiteKnight = {White, Knight};
		  static t_Piece WhiteBishop = {White, Bishop};
		  static t_Piece WhiteKing = {White, King};
		  static t_Piece WhiteQueen = {White, Queen};
		  static t_Piece WhitePawn = {White, Pawn};

		  static t_Piece EmptyPiece = {Empty_Player, Empty_Piece};

		/*static t_Board InitialBoard = 
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
*/
/*staticstatic t_Piece BlackRook;
staticstatic t_Piece BlackKnight;
staticstatic t_Piece BlackBishop;
staticstatic t_Piece BlackKing;
staticstatic t_Piece BlackQueen;
staticstatic t_Piece BlackPawn;

staticstatic t_Piece WhiteRook;
staticstatic t_Piece WhiteKnight;
staticstatic t_Piece WhiteBishop;
staticstatic t_Piece WhiteKing;
staticstatic t_Piece WhiteQueen;
staticstatic t_Piece WhitePawn;

staticstatic t_Piece EmptyPiece;

static t_Board InitialBoard;
t_Board InitializeVariables();
*/
#endif
