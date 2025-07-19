/*
 * A simple clone of tetris made up of nearly 700 lines of code frantically written in a span of 72 hours.
 */

#include "tetris.h"

int main(){
	window win;
	if(win.maxheight>=24&&win.maxwidth>=24){
		win.start();
		endwin();
		cout << "\nTETRIS========================"<< endl;
		cout << "=>  Your Score: "<< win.score_card << endl;
		cout << "=============================="<< endl;
	} else {
		win.~window();
		cout << "ERROR: screen too small (must be atleast 24X24) (recommended: 30x40)"<<endl;
	}
	return 0;
}
