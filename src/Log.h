#ifndef LOG_H
#define LOG_H

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "MoveList.h"

void SaveLog(char *OutFileName, int Verbose, MLIST *l);
MLIST *ReadLog(char *InFileName, t_Board Board, int Verbose);


#endif
