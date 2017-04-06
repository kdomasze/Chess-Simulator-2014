/*********************************************************************/
/* Log.c: homework assignment #1, for EECS 22L,	Winter 2014			 */
/* Author: Christine Dao											 */
/* History:															*/
/*                                            						 */
/*********************************************************************/

#include "Log.h"

void SaveLog(char *OutFileName, int Verbose, MLIST *l)
{ 
	assert(l);

	FILE *oFile = stdout;
	MENTRY *e;

	char player,pieceType,frFile,toFile;
	int frRank, toRank;
	int count=0;

	if (Verbose)
	{
		fprintf(stderr, "Writing to file %s...\n",(OutFileName ? OutFileName : "stdout"));
	}

	if (OutFileName)
	{
		oFile = fopen(OutFileName, "w");

		if (!oFile)
		{
			fprintf(stderr, "Cant open file \"%s\""" to write!\n", OutFileName);
			exit(10);
		}
	}

	e = l->First;

	while(e)
	{
	

		count ++;
		if (e->Piece->Player == 1)
		{
			player = 'w';
		}
		else if (e->Piece->Player == 2)
		{
			player = 'b';
		}

		if (e->Piece->PieceType == 0)
		{
			pieceType = 'Q';
		}
		if (e->Piece->PieceType ==1)
		{
			pieceType = 'R';
		}

		if(e->Piece->PieceType==2)
		{
			pieceType = 'B';
		}
		if(e->Piece->PieceType==3)
		{
			pieceType = 'N';
		}
		if(e->Piece->PieceType==4)
		{
			pieceType = 'K';
		}
		if(e->Piece->PieceType==5)
		{
			pieceType = 'P';
		}

		if (e->Move->From.File == 0)
		{
			frFile = 'a';
		}
		if (e->Move->From.File == 1)
		{
			frFile = 'b';
		}
		if (e->Move->From.File == 2)
		{
			frFile = 'c';
		}
		if (e->Move->From.File == 3)
		{
			frFile = 'd';
		}
		if (e->Move->From.File == 4)
		{
			frFile = 'e';
		}
		if (e->Move->From.File == 5)
		{
			frFile = 'f';
		}
		if (e->Move->From.File == 6)
		{
			frFile = 'g';
		}
		if (e->Move->From.File == 7)
		{
			frFile = 'h';
		}

		if (e->Move->To.File == 0)
		{
			toFile = 'a';
		}
		if (e->Move->To.File == 1)
		{
			toFile = 'b';
		}
		if (e->Move->To.File == 2)
		{
			toFile = 'c';
		}
		if (e->Move->To.File == 3)
		{
			toFile = 'd';
		}
		if (e->Move->To.File == 4)
		{
			toFile = 'e';
		}
		if (e->Move->From.File == 5)
		{
			toFile = 'f';
		}
		if (e->Move->To.File == 6)
		{
			toFile = 'g';
		}
		if (e->Move->To.File == 7)
		{
			toFile = 'h';
		}


		frRank = e->Move->From.Rank;
		toRank = e->Move->To.Rank;

		fprintf(oFile, "%c%c %c%d%c%d ", player,pieceType,frFile,frRank,toFile,toRank);

		e = e->Next;
		
	}

	if (oFile != stdout)
	{
		fclose(oFile);
		oFile = NULL;
	}

	if (Verbose)
	{
		fprintf(stderr, "Successfully wrote %d records!\n",count);
	}
} /* end of SaveLog */


MLIST *ReadLog(char *InFileName,t_Board Board, int Verbose)
{ 

	MLIST *l = NULL;
	FILE *iFile = stdin;

	int n;
	int count=0;
	char player;
	char pieceType;
	int frRank;
	char frFile;
	int toRank;
	char toFile;

	t_Move *move=NULL;
	
	if (Verbose)
	{ 
		fprintf(stderr, "Reading from file %s...\n",(InFileName ? InFileName : "stdin"));
	}
	
	if (InFileName)
	{
		iFile = fopen(InFileName, "r");

		if (!iFile)
		{ 
			fprintf(stderr, "Cant open file \"%s\" to read!\n", InFileName);
			exit(10);
		}
	}
	
	l = NewMoveList();
	
	while(1)
	{
		n = fscanf(iFile, "%c%c %c%d%c%d ",&player,&pieceType,&frFile,&frRank,&toFile,&toRank);
	
		if (n == EOF)
		{ 
			break; 
		}

		if (Verbose)
		{
			fprintf(stderr, "Read record %c%c %c%d%c%d",player,pieceType,frFile,frRank,toFile,toRank);
		}
		
		
		move->From.Rank = frRank;
		move->To.Rank = toRank;
/*
		if (player=='w')
		{
			piece->Player = 1;
		}
		else if (player =='b')
		{
			piece->Player = 2;
		}
*/		
		if (frFile == 'a')
		{
			move->From.File = 0;
		}
		if (frFile == 'b')
		{
			move->From.File = 1;
		}
		if (frFile == 'c')
		{
			move->From.File = 2;
		}
		if (frFile == 'd')
		{
			move->From.File = 3;
		}
		if (frFile == 'e')
		{
			move->From.File = 4;
		}
		if (frFile == 'f')
		{
			move->From.File = 5;
		}
		if (frFile == 'g')
		{
			move->From.File = 6;
		}
		if (frFile == 'h')
		{
			move->From.File = 7;
		}

		if (toFile == 'a')
		{
			move->To.File = 0;
		}
		if (toFile == 'b')
		{
			move->To.File = 1;
		}
		if (toFile == 'c')
		{
			move->To.File = 2;
		}
		if (toFile == 'd')
		{
			move->To.File = 3;
		}
		if (toFile == 'e')
		{
			move->To.File = 4;
		}
		if (toFile == 'f')
		{
			move->To.File = 5;
		}
		if (toFile == 'g')
		{
			move->To.File = 6;
		}
		if (toFile == 'h')
		{
			move->To.File = 7;
		}

/*
		if (pieceType =='Q')
		{
			piece->PieceType = 0;
		}
		if (pieceType =='R')
		{
			piece->PieceType = 1;
		}
		if (pieceType =='B')
		{
			piece->PieceType = 2;
		}
		if (pieceType =='N')
		{
			piece->PieceType = 3;
		}
		if (pieceType =='K')
		{
			piece->PieceType = 4;
		}
		if (pieceType =='P')
		{
			piece->PieceType = 5;
		}

	
	*/
	
		AddMove(l,Board,move);	
		count++;
		
	}

	if (iFile != stdin)
	{
		fclose(iFile);
		iFile = NULL;
	}
	
	if (Verbose)
	{
		fprintf(stderr, "Successfully read %d move records!\n", count-1);
	}
	
	return(l);
	
} /* end of ReadLog */
