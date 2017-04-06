# Makefile for Chess Simulator 2014
#
# Team 3: That One Team
#
# EECS22L Winter 2014
#
#
#

CC = gcc

CFLAGS = -ansi -Wall
LFLAGS = -Wall -lm

all: ChessSim2014

test: TestDisplay TestRulesNBoard

#target to generate GUI.o
GUI.o: GUI.h GUI.c
	$(CC) $(CFLAGS) -c GUI.c -o GUI.o -lSDL -g -I./inc/ 

#target to generate GUIascii.o
GUIascii.o: GUIascii.h GUIascii.c
	$(CC) $(CFLAGS) -c GUIascii.c -o GUIascii.o -lSDL -g -I./inc/ 
	
#target to generate AI.o
AI.o: AI.h AI.c
	$(CC) $(CFLAGS) -lm -c AI.c -o AI.o -g -I./inc/ 
	
#target to generate rules.o
rules.o: rules.h rules.c
	$(CC) $(CFLAGS) -c rules.c -o rules.o -g -I./inc/ 

#target to generate MoveList.o
MoveList.o: MoveList.h MoveList.c
	$(CC) $(CFLAGS) -c MoveList.c -o MoveList.o -g -I./inc/ 
	
#target to generate MovePiece.o
MovePiece.o: MovePiece.h MovePiece.c
	$(CC) $(CFLAGS) -c MovePiece.c -o MovePiece.o -g -I./inc/ 

#target to generate Log.o
Log.o: Log.c Log.h
	$(CC) $(CFLAGS) -c Log.c -o Log.o -g -I./inc/ 
	
#target to generate MovePiece.o
Main.o: Main.c
	$(CC) $(CFLAGS) -c Main.c -o Main.o -g -I./inc/ 
	
#target to generate Chess.o
Chess.o: Chess.c
	$(CC) $(CFLAGS) -c Chess.c -o Chess.o -lSDL -g -I./inc/ 

#target to generate program with GUI
ChessSim2014: Chess.o GUI.o AI.o rules.o MoveList.o MovePiece.o Log.o
	$(CC) $(CFLAGS) Chess.o GUI.o AI.o rules.o MoveList.o MovePiece.o Log.o -o ChessSim2014 -lSDL -g

#target to generate ASCII representation of program
ChessASCII: Main.o GUIascii.o AI.o rules.o MoveList.o MovePiece.o Log.o
	$(CC) $(CFLAGS) Main.o GUIascii.o AI.o rules.o MoveList.o MovePiece.o Log.o -o ChessSimASCII -g 
	
test_rulenboard.o: test_rulenboard.c
	$(CC) $(CFLAGS) -c test_rulenboard.c -o test_rulenboard.o

TestRulesNBoard: test_rulenboard.o GUIascii.o MovePiece.o rules.o MoveList.o Log.o MoveList.o
	$(CC) $(CFLAGS) test_rulenboard.o GUIascii.o MovePiece.o rules.o MoveList.o Log.o -o TestRulesNBoard

test_boarddisplay.o: test_boarddisplay.c
	$(CC) $(CFLAGS) -c test_boarddisplay.c -o test_boarddisplay.o	

TestDisplay: test_boarddisplay.o GUIascii.o MovePiece.o MoveList.o rules.o
	$(CC) $(CFLAGS) test_boarddisplay.o MoveList.o GUIascii.o rules.o MovePiece.o -o TestDisplay

#target to clean the directory
clean:
	rm -f *.o ChessSim2014 TestRulesNBoard TestDisplay

