#ifndef GUI_H
#define GUI_H

#include "SDL/SDL.h"
#include "ChessObj.h"
#include <string.h>
#include <stdio.h>

/* screen attributes */

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 700
#define SCREEN_BPP 32
#define BTN_WIDTH 410
#define BTN_HEIGHT 111

/* surfaces used */
extern SDL_Surface *img_title;
extern SDL_Surface *img_credits;

extern SDL_Surface *img_exit_btn;

extern SDL_Surface *img_promotion_txt;

extern SDL_Surface *img_difficulty_txt;
extern SDL_Surface *img_difficulty_ones_txt;
extern SDL_Surface *img_difficulty_twos_txt;

extern SDL_Surface *img_color_txt;
extern SDL_Surface *img_color_computer_ones_txt;

extern SDL_Surface *img_black_btn;
extern SDL_Surface *img_white_btn;

extern SDL_Surface *img_chessBoard;
extern SDL_Surface *img_rank;
extern SDL_Surface *img_file;

extern SDL_Surface *img_WhiteKing;
extern SDL_Surface *img_WhiteQueen;
extern SDL_Surface *img_WhiteRook;
extern SDL_Surface *img_WhiteKnight;
extern SDL_Surface *img_WhiteBishop;
extern SDL_Surface *img_WhitePawn;

extern SDL_Surface *img_BlackKing;
extern SDL_Surface *img_BlackQueen;
extern SDL_Surface *img_BlackRook;
extern SDL_Surface *img_BlackKnight;
extern SDL_Surface *img_BlackBishop;
extern SDL_Surface *img_BlackPawn;

extern SDL_Surface *img_humanVsComputer_btn;
extern SDL_Surface *img_computerVsComputer_btn;
extern SDL_Surface *img_humanVsHuman_btn;

extern SDL_Surface *img_easy_btn;
extern SDL_Surface *img_medium_btn;
extern SDL_Surface *img_hard_btn;

extern SDL_Surface *img_WhiteCheckmate_txt;
extern SDL_Surface *img_WhiteCheck_txt;
extern SDL_Surface *img_BlackCheckmate_txt;
extern SDL_Surface *img_BlackCheck_txt;

extern SDL_Surface *screen;

extern int currentScreen;
extern int currentScreenDisplayed;

extern Uint32 clearColor;

/* the event structure that will be used */
extern SDL_Event event;

extern char input1[3];
extern char input2[3];

SDL_Surface *load_image(char filename[]);

void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination);

void loadImages();

int init();

int updateDisplay();

void displayPawnPromotion();

void displayChessBoard(t_Board Board);

void displayMainMenu();

void displayDifficultyMenu(int computer);

void displayColorMenu(int computer);

SDL_Surface *sys_draw_rect(int w, int h);

int mouseClickPiece(int surfacex, int surfacey, int surfacew, int surfaceh);

int mouseClickBtn(int surfacex, int surfacey, int nextScreen);

int mouseClickBoard(int surfacex, int surfacey, int gridx, int gridy, int state);

void clean_up();

#endif
