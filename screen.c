//This file contains functions to manipulate screens, such as set foreground
//color, background color, clearscreen, restore default settings, etc.
//To enable screen manipulations, we need to use VT100 escape sequences
//see the link: http://www.termsys.demon.co.uk/vtansi.htm
#include <stdio.h>
#include "screen.h"
//function definitions
void setfgcolor(int fg) {
	printf("%c[1;%dm",ESC,fg);
}
void setbgcolor(int bg) {
	printf("%c[1;%dm",ESC,bg);
}
void setcolors(int fg, int bg) {
	setfgcolor(fg);
	setbgcolor(bg);
}
void clearscreen(void) {
	printf("%c[2J",ESC);
}
void resetcolors(void) {
	printf("%c[0m",ESC);
}
void gotoXY(int row, int col) {
	printf("%c[%d;%dH", ESC, row, col);
}
void drawbar(int col, int height) {
	int i;
	for(i=1; i<=height; i++) {
		gotoXY(i, col);
#ifdef UNICODE
		printf("%s",BAR);
#else
		printf("%c",'#');
#endif
	}
}
void drawrect(int row, int col, int height, int width) {
	int i, j;		//loop control variables
	for(i = row; i<row+height; i++) {
		for(j=col; j<col+width; j++) {
			gotoXY(i,j);
#ifdef UNICODE
		printf("%s", BAR);
#else
		printf("%c",'#');
#endif
		}
		printf("\n");
	}
}
Position getscreensize(void) {
//in this function, we will use terminal query cursor position,
//the terminal should return a string back to the program
//if a query string "ESC[6n" is issued to the terminal
	Position p;
	int r,c;					//decoding the report string
	char ret[100] = "\0";		//an empty string to get report
	gotoXY(999,999);			//force the cursor to the bottom right corner
	printf("%c[6n",ESC);		//send the query string for cursor position
	scanf("%s", ret);
#ifdef DEBUG
	printf("%s\n", ret);
#endif
	//we will decode the returned string
#include <string.h>
	if(strlen(ret)>0) {		//we got a cursor position report
		char dum;
		int r,c;
		sscanf(ret,"%c%c%d%c%d%c",&dum,&dum,&r,&dum,&c,&dum);
		p.row = r;
		p.col = c;
	}
	else {
		p.row = 0;
		p.col = 0;
	}
	return p;
}

