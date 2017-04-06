/* ChessPieces.c
 * Function initializing the Chess Piece variables
 *
 * Written by: Anthony Diep
 * Created on: 1/25/14
 *
 * Rev. history:
 * 1/25/14 11:20PM:	Initial Creation(AD)
 * 
 * Chess Simulator 2014 is licensed under a Creative
 * Commons Attribution-Noncommercial 4.0 
 * International License.
 */

#include "ChessPieces.h"

/*static t_Piece BlackRook;
static t_Piece BlackKnight;
static t_Piece BlackBishop;
static t_Piece BlackKing;
static t_Piece BlackQueen;
static t_Piece BlackPawn;

static t_Piece WhiteRook;
static t_Piece WhiteKnight;
static t_Piece WhiteBishop;
static t_Piece WhiteKing;
static t_Piece WhiteQueen;
static t_Piece WhitePawn;

static t_Piece EmptyPiece;

static t_Board InitialBoard[8][8];
*/
t_Board InitializeVariables()
	{
		 t_Piece BlackRook = {Black, Rook};
		 t_Piece BlackKnight = {Black, Knight};
		 t_Piece BlackBishop = {Black, Bishop};
		 t_Piece BlackKing = {Black, King};
		 t_Piece BlackQueen = {Black, Queen};
		 t_Piece BlackPawn = {Black, Pawn};

		 t_Piece WhiteRook = {White, Rook};
		 t_Piece WhiteKnight = {White, Knight};
		 t_Piece WhiteBishop = {White, Bishop};
		 t_Piece WhiteKing = {White, King};
		 t_Piece WhiteQueen = {White, Queen};
		 t_Piece WhitePawn = {White, Pawn};

		 t_Piece EmptyPiece = {Empty_Player, Empty_Piece};

		 t_Board InitialBoard[8][8] = 
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

	return InitialBoard;
	}
