#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"
int main(void) {
	Position cur = getscreensize();
	char postdata[100];
	sprintf(postdata, "row=%d&col=%d&id=e1900281",cur.row, cur.col);
	sendpost(URL, postdata);
	gotoXY(1,1);
	printf("Screen size: row=%d, col=%d\n", cur.row, cur.col);
	printf("Today we will make some animations. Press any key to continue\n");
	getchar();
	getchar();
	int ff,bb;
	float step = (float)cur.col/cur.row;
	for(int i=1; i<=cur.row; i++) {
		ff = (i + 1)%8 + BLACK;
		bb = (i + 2)%8 + BLACK;
		setcolors(ff, bg(bb));
		clearscreen();
		drawrect(10,10,5,30);
		gotoXY(cur.row - i, (i-1)*step+1);
		printf("HELLO!\n");
		usleep(200000);	//sleep(1);
	}
	getchar();
	resetcolors();
    clearscreen();
	printf("Color is set back to default\n");
	getchar();

/*
	setfgcolor(GREEN);
	gotoXY(14,35);
	printf("HELLO, WORLD!\n");
	getchar();
	drawbar(30, 30);
	drawbar(50, 30);
	getchar();			//after drawing bars,
					//wait for a key.
	resetcolor();
	 printf("This text is displayed in default color\n");
*/
}

