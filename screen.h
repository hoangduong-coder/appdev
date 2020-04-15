// Usually in a header file, following information are included
// function declarations, constant definitions
//constant definitions
#define ESC 0x1B
//not use #define BLACK 30, use enumeration instead
enum FG{BLACK = 30,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE};
#define bg(c) (c + 10) //marco definition
#define UNICODE
#define BAR "\u2590"
//#define DEBUG				//for conditional compilation
typedef struct{			//a compound data, consists of num of col and row
	int row;
	int col;
}Position;

//function declarations
void clearscreen(void);
void setfgcolor(int);
void setbgcolor(int);
void setcolors(int, int);
void resetcolors(void);
void gotoXY(int, int);
void drawbar(int,int);
void drawrect(int, int, int, int);
Position getscreensize(void);
