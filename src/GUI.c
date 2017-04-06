#include "GUI.h"

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

/* surfaces used */
SDL_Surface *img_title = NULL;
SDL_Surface *img_credits = NULL;

SDL_Surface *img_exit_btn = NULL;

SDL_Surface *img_promotion_txt = NULL;

SDL_Surface *img_difficulty_txt = NULL;
SDL_Surface *img_difficulty_ones_txt = NULL;
SDL_Surface *img_difficulty_twos_txt = NULL;

SDL_Surface *img_color_txt = NULL;
SDL_Surface *img_color_computer_ones_txt = NULL;

SDL_Surface *img_black_btn = NULL;
SDL_Surface *img_white_btn = NULL;

SDL_Surface *img_chessBoard = NULL;
SDL_Surface *img_rank = NULL;
SDL_Surface *img_file = NULL;

SDL_Surface *img_WhiteKing = NULL;
SDL_Surface *img_WhiteQueen = NULL;
SDL_Surface *img_WhiteRook = NULL;
SDL_Surface *img_WhiteKnight = NULL;
SDL_Surface *img_WhiteBishop = NULL;
SDL_Surface *img_WhitePawn = NULL;

SDL_Surface *img_BlackKing = NULL;
SDL_Surface *img_BlackQueen = NULL;
SDL_Surface *img_BlackRook = NULL;
SDL_Surface *img_BlackKnight = NULL;
SDL_Surface *img_BlackBishop = NULL;
SDL_Surface *img_BlackPawn = NULL;

SDL_Surface *img_humanVsComputer_btn = NULL;
SDL_Surface *img_computerVsComputer_btn = NULL;
SDL_Surface *img_humanVsHuman_btn = NULL;

SDL_Surface *img_easy_btn = NULL;
SDL_Surface *img_medium_btn = NULL;
SDL_Surface *img_hard_btn = NULL;

SDL_Surface *img_WhiteCheckmate_txt = NULL;
SDL_Surface *img_WhiteCheck_txt = NULL;
SDL_Surface *img_BlackCheckmate_txt = NULL;
SDL_Surface *img_BlackCheck_txt = NULL;

SDL_Surface *screen = NULL;

int currentScreen = 1;
int currentScreenDisplayed = 0;

Uint32 clearColor;

/* the event structure that will be used */
SDL_Event event;

char input1[3] = {NULL, NULL, '\0'};
char input2[3] = {NULL, NULL, '\0'};

SDL_Surface *load_image(char filename[])
{
	/* temp. storage for the image that was loaded */
	SDL_Surface *loadedImage = NULL;
	
	/* the optimized image that will be used */
	SDL_Surface *optimizedImage = NULL;

	/* load the image */
	loadedImage = SDL_LoadBMP(filename);

	/* if nothing went wrong in loading the image */
	if(loadedImage != NULL)
	{	
		/* create an optimized image */
		optimizedImage = SDL_DisplayFormat(loadedImage);

		/* free the old image */
		SDL_FreeSurface(loadedImage);
	
		/* if the image was optimized fine */
		if(optimizedImage != NULL)
		{
			/* map the color key */
			Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 255, 0, 240);

			/* set all pixels of color key to be transparent */
			SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
		}
	}
	else
	{
		printf("Failed to load image: %s\n", filename);
		printf("IMG_Load: %s\n", SDL_GetError());
	}

	/* return optimized image */
	return optimizedImage;
}

void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
	/* make a temp. rectangle to hold the offsets */
	SDL_Rect offset;
	
	/* give the offsets to the rectangle */
	offset.x = x;
	offset.y = y;

	/* blit the surface */
	SDL_BlitSurface(source, NULL, destination, &offset);
}

void loadImages()
{
	/* load the images */
	img_title = load_image("images/menu/title.bmp");
	img_credits = load_image("images/menu/credits.bmp");
	
	img_exit_btn = load_image("images/menu/buttons/exit.bmp");
	
	img_promotion_txt = load_image("images/menu/promotion_txt.bmp");
	
	img_humanVsComputer_btn = load_image("images/menu/buttons/button_01.bmp");
	img_computerVsComputer_btn = load_image("images/menu/buttons/button_03.bmp");
	img_humanVsHuman_btn = load_image("images/menu/buttons/button_05.bmp");
	
	img_difficulty_txt = load_image("images/menu/difficulty_txt.bmp");
	img_difficulty_ones_txt = load_image("images/menu/difficulty_ones_txt.bmp");
	img_difficulty_twos_txt = load_image("images/menu/difficulty_twos_txt.bmp");
	
	img_hard_btn = load_image("images/menu/buttons/button_11.bmp");
	img_medium_btn = load_image("images/menu/buttons/button_13.bmp");
	img_easy_btn = load_image("images/menu/buttons/button_15.bmp");
	
	img_color_txt = load_image("images/menu/color_txt.bmp");
	img_color_computer_ones_txt = load_image("images/menu/color_computer_one_txt.bmp");
	
	img_black_btn = load_image("images/menu/buttons/button_09.bmp");
	img_white_btn = load_image("images/menu/buttons/button_07.bmp");
	
	img_chessBoard = load_image("images/chessBoard.bmp");
	img_rank = load_image("images/chessBoard_Rank.bmp");
	img_file = load_image("images/chessBoard_File.bmp");

	img_WhiteKing = load_image("images/pieces/WhiteKing.bmp");
	img_WhiteQueen = load_image("images/pieces/WhiteQueen.bmp");
	img_WhiteRook = load_image("images/pieces/WhiteRook.bmp");
	img_WhiteKnight = load_image("images/pieces/WhiteKnight.bmp");
	img_WhiteBishop = load_image("images/pieces/WhiteBishop.bmp");
	img_WhitePawn = load_image("images/pieces/WhitePawn.bmp");

	img_BlackKing = load_image("images/pieces/BlackKing.bmp");
	img_BlackQueen = load_image("images/pieces/BlackQueen.bmp");
	img_BlackRook = load_image("images/pieces/BlackRook.bmp");
	img_BlackKnight = load_image("images/pieces/BlackKnight.bmp");
	img_BlackBishop = load_image("images/pieces/BlackBishop.bmp");
	img_BlackPawn = load_image("images/pieces/BlackPawn.bmp");

	img_WhiteCheckmate_txt = load_image("images/menu/WhiteCheckmate.bmp");
	img_WhiteCheck_txt = load_image("images/menu/WhiteCheck.bmp");
	img_BlackCheckmate_txt = load_image("images/menu/BlackCheckmate.bmp");
	img_BlackCheck_txt = load_image("images/menu/BlackCheck.bmp");
}

int init()
{
	/* init all SDL subsystems */
	if(SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		return 0;
	}

	/* setup the screen */
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	
	/* if there was an error in setting up the screen */
	if(screen == NULL)
	{
		return 0;
	}

	/* set the window caption */
	SDL_WM_SetCaption("Chess Simulator 2014", NULL);
	
	/* load images */
	loadImages();

	/* If all is fine */
	return 1;
}

int updateDisplay()
{
	/* update the screen */
	if(SDL_Flip(screen) == -1)
	{
		return 1;
	}
	return 0;
}

void displayPawnPromotion(int player_color)
{
	apply_surface(1, 700-50, img_promotion_txt, screen);
	
	if(player_color == 1)
	{
		apply_surface(265, 700-70, img_WhiteRook, screen);
		apply_surface(265 + 60, 700-70, img_WhiteKnight, screen);
		apply_surface(265 + 65*2, 700-70, img_WhiteBishop, screen);
		apply_surface(265 + 60*3, 700-70, img_WhiteQueen, screen);
	}
	if(player_color == 2)
	{
		apply_surface(265, 700-70, img_BlackRook, screen);
		apply_surface(265 + 60, 700-70, img_BlackKnight, screen);
		apply_surface(265 + 65*2, 700-70, img_BlackBishop, screen);
		apply_surface(265 + 60*3, 700-70, img_BlackQueen, screen);
	}
}

void displayChessBoard(t_Board Board)
{
	/* apply the background to the screen */
	apply_surface(95, 0, img_chessBoard, screen);
	apply_surface(120, 600, img_rank, screen);
	apply_surface(70, 23, img_file, screen);
	apply_surface(700, 23, img_file, screen);
	
	apply_surface(SCREEN_WIDTH - 272, SCREEN_HEIGHT - 66, img_exit_btn, screen);

	int i;
	int j;

	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			t_Piece Piece = Board[i][j];
			t_Player Player = Piece.Player;
			t_PieceType PieceType = Piece.PieceType;

			switch(Player)
			{
				case Black:
					switch(PieceType)
					{
						case Rook:
							apply_surface(108 + 75 * j, 7 + 75 * i, img_BlackRook, screen);
						break;
						case Knight:
							apply_surface(101 + 75 * j, 7 + 75 * i, img_BlackKnight, screen);
						break;
						case Bishop:
							apply_surface(113 + 75 * j, 7 + 75 * i, img_BlackBishop, screen);
						break;
						case King:
							apply_surface(101 + 75 * j, 7 + 75 * i, img_BlackKing, screen);
						break;
						case Queen:
							apply_surface(98 + 75 * j, 7 + 75 * i, img_BlackQueen, screen);
						break;
						case Pawn:
							apply_surface(111 + 75 * j, 7 + 75 * i, img_BlackPawn, screen);
						break;
						case Empty_Piece:
						break;
				}
				break;
				case White:
					switch(PieceType)
					{
						case Rook:
							apply_surface(108 + 75 * j, 7 + 75 * i, img_WhiteRook, screen);
						break;
						case Knight:
							apply_surface(101 + 75 * j, 7 + 75 * i, img_WhiteKnight, screen);
						break;
						case Bishop:
							apply_surface(113 + 75 * j, 7 + 75 * i, img_WhiteBishop, screen);
						break;
						case King:
							apply_surface(101 + 75 * j, 7 + 75 * i, img_WhiteKing, screen);
						break;
						case Queen:
							apply_surface(98 + 75 * j, 7 + 75 * i, img_WhiteQueen, screen);
						break;
						case Pawn:
							apply_surface(111 + 75 * j, 7 + 75 * i, img_WhitePawn, screen);
						break;
						case Empty_Piece:
						break;
					}
				break;
				case Empty_Player:
				break;
			}
		}
	}
}

void displayMainMenu()
{
	apply_surface(0, 0, img_title, screen);

	apply_surface(SCREEN_WIDTH - BTN_WIDTH - 11, 300, img_humanVsHuman_btn, screen); 
	
	apply_surface(SCREEN_WIDTH - BTN_WIDTH - 11, 300 + BTN_HEIGHT + 11, img_computerVsComputer_btn, screen);
	
	apply_surface(SCREEN_WIDTH - BTN_WIDTH - 11, 300 + BTN_HEIGHT + BTN_HEIGHT + 22, img_humanVsComputer_btn, screen);
	
	apply_surface(0, SCREEN_HEIGHT - 27, img_credits, screen);
}

void displayDifficultyMenu(int computer)
{
	apply_surface(0, 0, img_title, screen);
	
	if(computer == 0)
	{
		apply_surface(0, 250, img_difficulty_txt, screen); 
	}
	else if(computer == 1)
	{
		apply_surface(0, 250, img_difficulty_ones_txt, screen); 
	}
	else if(computer == 2)
	{
		apply_surface(0, 250, img_difficulty_twos_txt, screen); 
	}
	
	apply_surface(SCREEN_WIDTH - BTN_WIDTH - 11, 300, img_easy_btn, screen); 
	
	apply_surface(SCREEN_WIDTH - BTN_WIDTH - 11, 300 + BTN_HEIGHT + 11, img_medium_btn, screen);
	
	apply_surface(SCREEN_WIDTH - BTN_WIDTH - 11, 300 + BTN_HEIGHT + BTN_HEIGHT + 22, img_hard_btn, screen);
	
	apply_surface(0, SCREEN_WIDTH - 27, img_credits, screen);
}

void displayColorMenu(int computer)
{
	apply_surface(0, 0, img_title, screen);
	
	if(computer == 0)
	{
		apply_surface(0, 250, img_color_txt, screen); 
	}
	else if(computer == 1)
	{
		apply_surface(0, 250, img_color_computer_ones_txt, screen); 
	}
	
	apply_surface(SCREEN_WIDTH - BTN_WIDTH - 11, 300, img_black_btn, screen); 
	
	apply_surface(SCREEN_WIDTH - BTN_WIDTH - 11, 300 + BTN_HEIGHT + 11, img_white_btn, screen);
	
	apply_surface(0, SCREEN_WIDTH - 27, img_credits, screen);
}

SDL_Surface *sys_draw_rect(int w, int h)
{
	SDL_Surface *sfc, *newImage;
	
	sfc = SDL_CreateRGBSurface(SDL_SWSURFACE, w, h, 32, 255, 0, 0, 128);
	
	newImage = SDL_DisplayFormat(sfc);
	
	SDL_FillRect(newImage, NULL, SDL_MapRGB(newImage->format, 255, 0, 0));
	SDL_SetAlpha(newImage, SDL_SRCALPHA|SDL_RLEACCEL, 128);
	
	SDL_FreeSurface(sfc);
	return newImage;
}

int mouseClickPiece(int surfacex, int surfacey, int surfacew, int surfaceh)
{
	int x = 0;
	int y = 0;

	 /* If a mouse button was released */
    if( event.type == SDL_MOUSEBUTTONUP )
    {
        /* If the left mouse button was released */
        if( event.button.button == SDL_BUTTON_LEFT )
        { 
            /* Get the mouse offsets */
            x = event.button.x;
            y = event.button.y;
        
            /* If the mouse is over the button */
            if( ( x > surfacex ) && ( x < surfacex + surfacew ) && ( y > surfacey ) && ( y < surfacey + surfaceh ) )
            {
				return 1;
            }
        }
    }
	return 0;
}

int mouseClickBtn(int surfacex, int surfacey, int nextScreen)
{
	int x = 0;
	int y = 0;

	 /* If a mouse button was released */
    if( event.type == SDL_MOUSEBUTTONUP )
    {
        /* If the left mouse button was released */
        if( event.button.button == SDL_BUTTON_LEFT )
        { 
            /* Get the mouse offsets */
            x = event.button.x;
            y = event.button.y;
        
            /* If the mouse is over the button */
            if( ( x > surfacex ) && ( x < surfacex + BTN_WIDTH ) && ( y > surfacey ) && ( y < surfacey + BTN_HEIGHT ) )
            {
				currentScreen = nextScreen;
				return 1;
            }
        }
    }
	return 0;
}

int mouseClickBoard(int surfacex, int surfacey, int gridx, int gridy, int state)
{
	int x = 0;
	int y = 0;

	 /* If a mouse button was released */
    if( event.type == SDL_MOUSEBUTTONUP )
    {
        /* If the left mouse button was released */
        if( event.button.button == SDL_BUTTON_LEFT )
        { 
            /* Get the mouse offsets */
            x = event.button.x;
            y = event.button.y;
        
            /* If the mouse is over the button */
            if( ( x > surfacex ) && ( x < surfacex + 75 ) && ( y > surfacey ) && ( y < surfacey + 75 ) )
            {
				if(state == 1)
				{
					apply_surface(95 + 75 * gridy, 75 * (7-gridx), sys_draw_rect(75, 75), screen);
					input1[0] = (char)(gridy+97);
					input1[1] = (char)(((int)'1')+gridx);
					return 2;
				}
				else if(state == 2)
				{
					input2[0] = (char)(gridy+97);
					input2[1] = (char)(((int)'1')+gridx);
					return 3;
				}
            }
        }
    }
	return state;
}

void clean_up()
{
	/* free the images */
	SDL_FreeSurface(img_title);
	SDL_FreeSurface(img_credits);
	
	SDL_FreeSurface(img_exit_btn);
	
	SDL_FreeSurface(img_chessBoard);
	SDL_FreeSurface(img_rank);
	SDL_FreeSurface(img_file);
	
	SDL_FreeSurface(img_WhiteKing);
	SDL_FreeSurface(img_WhiteQueen);
	SDL_FreeSurface(img_WhiteRook);
	SDL_FreeSurface(img_WhiteKnight);
	SDL_FreeSurface(img_WhiteBishop);
	SDL_FreeSurface(img_WhitePawn);

	SDL_FreeSurface(img_BlackKing);
	SDL_FreeSurface(img_BlackQueen);
	SDL_FreeSurface(img_BlackRook);
	SDL_FreeSurface(img_BlackKnight);
	SDL_FreeSurface(img_BlackBishop);
	SDL_FreeSurface(img_BlackPawn);
	
	SDL_FreeSurface(img_humanVsComputer_btn);
	SDL_FreeSurface(img_computerVsComputer_btn);
	SDL_FreeSurface(img_humanVsHuman_btn);
	
	SDL_FreeSurface(img_difficulty_txt);
	SDL_FreeSurface(img_difficulty_ones_txt);
	SDL_FreeSurface(img_difficulty_twos_txt);

	SDL_FreeSurface(img_color_txt);
	SDL_FreeSurface(img_color_computer_ones_txt);

	SDL_FreeSurface(img_easy_btn);
	SDL_FreeSurface(img_medium_btn);
	SDL_FreeSurface(img_hard_btn);

	/* quit SDL */
	SDL_Quit();
}
