#include "tetris.h"

window::window(){
	del = 51000;
	bgdel = 500000;
	initscr();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	noecho();
	curs_set(0);
	getmaxyx(stdscr, maxheight, maxwidth);
	origin_x = maxwidth/2-11;
	origin_y = maxheight/2-11;
	pixel = "[]";
	blank = " .";
	draw_box(origin_x, origin_y, 21, 21);

}
window::~window(){
	nodelay(stdscr, false);
	//getch();
	endwin();
}
void window::draw_box(int startx, int starty, int width, int height){
	//char hor='-';
	//char ver='|';
	//char cor='+';
	char hor='#';
	char ver='#';
	char cor='#';
	//int startx=20;
	//int starty=1;
	for(int i=startx+1; i<startx+width; i++){
		move(starty,i);
		addch(hor);
	}
	for(int i=startx+1; i<startx+width; i++){
		move(starty+height,i);
		addch(hor);
	}
	for(int i=starty+1; i<starty+height; i++){
		move(i,startx);
		addch(ver);
	}
	for(int i=starty+1; i<starty+height; i++){
		move(i,startx+width);
		addch(ver);
	}
	move(starty,startx);
	addch(cor);
	move(starty,startx+width);
	addch(cor);
	move(starty+height,startx);
	addch(cor);
	move(starty+height,startx+width);
	addch(cor);
	refresh();
}
long long window::time_right_now(){
    auto now = chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto milliseconds = chrono::duration_cast<chrono::milliseconds>(duration).count();
    return milliseconds;
}
void window::print_instructions(){
	if(maxwidth>=45){
		move(origin_y+7,origin_x+24);
		printw("=>:right");
		move(origin_y+10,origin_x+24);
		printw("<=:left");
		move(origin_y+13,origin_x+24);
		printw("/\\:rotate");
		move(origin_y+16,origin_x+24);
		printw("\\/:drop");
		move(origin_y+10,origin_x-9);
		printw("p:pause");
		move(origin_y+13,origin_x-9);
		printw("q:quit ");
	} else if(maxheight>=37){
		move(origin_y+25,origin_x+0);
		printw("<= : left");
		move(origin_y+26,origin_x+0);
		printw("/\\ : rotate");
		move(origin_y+27,origin_x+0);
		printw(" p : pause");
		move(origin_y+25,origin_x+11);
		printw("| => : right");
		move(origin_y+26,origin_x+11);
		printw("| \\/ : drop");
		move(origin_y+27,origin_x+11);
		printw("|  q : quit");
		
	}
	refresh();
}
void window::make_block(){
	srand(time_right_now());
	line.push_back(make_pair(origin_x+0+7,origin_y+0+1));
	line.push_back(make_pair(origin_x+2+7,origin_y+0+1));
	line.push_back(make_pair(origin_x+4+7,origin_y+0+1));
	line.push_back(make_pair(origin_x+6+7,origin_y+0+1));

	square.push_back(make_pair(origin_x+0+9,origin_y+0+1));
	square.push_back(make_pair(origin_x+2+9,origin_y+0+1));
	square.push_back(make_pair(origin_x+0+9,origin_y+1+1));
	square.push_back(make_pair(origin_x+2+9,origin_y+1+1));

	squiggly.push_back(make_pair(origin_x+2+7,origin_y+0+1));
	squiggly.push_back(make_pair(origin_x+4+7,origin_y+0+1));
	squiggly.push_back(make_pair(origin_x+0+7,origin_y+1+1));
	squiggly.push_back(make_pair(origin_x+2+7,origin_y+1+1));

	ell.push_back(make_pair(origin_x+4+7,origin_y+0+1));
	ell.push_back(make_pair(origin_x+0+7,origin_y+1+1));
	ell.push_back(make_pair(origin_x+2+7,origin_y+1+1));
	ell.push_back(make_pair(origin_x+4+7,origin_y+1+1));

	tee.push_back(make_pair(origin_x+2+7,origin_y+0+1));
	tee.push_back(make_pair(origin_x+0+7,origin_y+1+1));
	tee.push_back(make_pair(origin_x+2+7,origin_y+1+1));
	tee.push_back(make_pair(origin_x+4+7,origin_y+1+1));

	reverse_squiggly.push_back(make_pair(origin_x+0+7,origin_y+0+1));
	reverse_squiggly.push_back(make_pair(origin_x+2+7,origin_y+0+1));
	reverse_squiggly.push_back(make_pair(origin_x+2+7,origin_y+1+1));
	reverse_squiggly.push_back(make_pair(origin_x+4+7,origin_y+1+1));

	reverse_ell.push_back(make_pair(origin_x+0+7,origin_y+0+1));
	reverse_ell.push_back(make_pair(origin_x+0+7,origin_y+1+1));
	reverse_ell.push_back(make_pair(origin_x+2+7,origin_y+1+1));
	reverse_ell.push_back(make_pair(origin_x+4+7,origin_y+1+1));

	for(int i = 0; i<22; i++){
		for(int j = 0; j<22; j++){
			bbarr[i][j]=false;
		}
	}
	for(int i = 0; i<22; i++){
		bbarr[i][0]=true;
		bbarr[i][21]=true;
	}
	for(int i = 0; i<22; i++){
		bbarr[0][i]=true;
		bbarr[21][i]=true;
	}

	for(int i = 1; i<21; i+=2){
		for(int j = 1;j<21;j++){
			move(j+origin_y,i+origin_x);
			printw("%s",blank.c_str());
		}
	}
	move(0,0);
	printw("TETRIS");
	refresh();

}
void window::generate_block(){
	score_card+=3;
	int random_number = rand() % 7;
	switch (random_number){
	case 0:
		crblock = line;
		crblock_type = "line";
		crblock_orientation = 0;
		break;
	case 1:
		crblock = square;
		crblock_type = "square";
		crblock_orientation = 0;
		break;
	case 2:
		crblock = squiggly;
		crblock_type = "squiggly";
		crblock_orientation = 0;
		break;
	case 3:
		crblock = ell;
		crblock_type = "ell";
		crblock_orientation = 0;
		break;
	case 4:
		crblock = tee;
		crblock_type = "tee";
		crblock_orientation = 0;
		break;
	case 5:
		crblock = reverse_squiggly;
		crblock_type = "reverse_squiggly";
		crblock_orientation = 0;
		break;
	case 6:
		crblock = reverse_ell;
		crblock_type = "reverse_ell";
		crblock_orientation = 0;
		break;
	default:
		crblock = line;
		crblock_type = "line";
		crblock_orientation = 0;
		break;
	}
	for(auto it : crblock){
		move(it.second,it.first);
		printw("%s",pixel.c_str());
	}
	refresh();
	usleep(bgdel);
}

void window::update_score(){
	move(origin_y+22,origin_x);
	printw("Score: %d",score_card);
	refresh();
	usleep(del);
}

void window::move_block(){
	while(true){
		update_score();
		move_sideways();
		if (quit){
			break;
		}
		if (pause){
			goto MOVE_END;
		}
		if(time_right_now()-last_falltime>=555){
			if (further()){
				space_time = 0;
				last_falltime = time_right_now();
				for(auto it : crblock){
					if(bbarr[it.first-origin_x][it.second-origin_y]==false){
						move(it.second,it.first);
						printw("%s",blank.c_str());
					}
				}
				for (int i=0;i<4;i++){
					crblock[i].second+=1;
				}
			} else {
				for ( auto it : crblock){
					bbarr[it.first-origin_x][it.second-origin_y]=true;
				}
				break;
			}
		}
		MOVE_END:
		for(auto it : crblock){
			move(it.second,it.first);
			printw("%s",pixel.c_str());
		}
		refresh();
	}

}

void window::drop_block(){
	score_card+=1;
	vector<int> drop_list;
	for(auto it : crblock){
		int i = 0;
		while(1){
			if(bbarr[it.first-origin_x][it.second+i-origin_y]==true){
				drop_list.push_back(i);
				break;
			}
			i++;
		}
	}
	int min_drop_dist = *std::min_element(drop_list.begin(), drop_list.end())-1;
	for(auto it : crblock){
		move(it.second,it.first);
		printw("%s",blank.c_str());
	}
	for (int i=0;i<4;i++){
		crblock[i].second+=min_drop_dist;
	}
	for(auto it : crblock){
		move(it.second,it.first);
		printw("%s",pixel.c_str());
	}
	for ( auto it : crblock){
		bbarr[it.first-origin_x][it.second-origin_y]=true;
	}
	refresh();
	//usleep(bgdel);
}

void window::check_pause(){
	if (pause==true){
		pause=false;
		move(0,0);
		printw("TETRIS                ");
	}else{
		pause=true;
		move(0,0);
		printw("paused - press p again");
	}
}

void window::move_left(){
	//check
	bool checkleft=true;
	for (auto it : crblock){
		if ((it.first-2-origin_x)<=0||bbarr[it.first-2-origin_x][it.second-origin_y]==true){checkleft=false;break;}
	}
	//move
	if (checkleft){
		for(auto it : crblock){
			move(it.second,it.first);
			printw("%s",blank.c_str());
		}
		for (int i=0;i<4;i++){
			crblock[i].first-=2;
		}
	}
	for(auto it : crblock){
		move(it.second,it.first);
		printw("%s",pixel.c_str());
	}
	if (checkleft){
		refresh();
		usleep(del);
	}
}
void window::move_right(){
	//check
	bool checkright=true;
	for (auto it : crblock){
		if (bbarr[it.first+2-origin_x][it.second-origin_y]==true){checkright=false;break;}
	}
	//move
	if (checkright){
		for(auto it : crblock){
			move(it.second,it.first);
			printw("%s",blank.c_str());
		}
		for (int i=0;i<4;i++){
			crblock[i].first+=2;
		}
	}
	for(auto it : crblock){
		move(it.second,it.first);
		printw("%s",pixel.c_str());
	}
	if (checkright){
		refresh();
		usleep(del);
	}
}

void window::move_sideways(){
	int direction_var = getch();
	if (direction_var == 'p' ) {
		check_pause();
	} else if (direction_var == 'q'){
		quit = true;
	} else if (direction_var == KEY_RIGHT && !pause){
		move_right();
	} else if (direction_var == KEY_LEFT && !pause){
		move_left();
	} else if (direction_var == KEY_UP && !pause){
		rotate_block();
	} else if (direction_var == KEY_DOWN && !pause){
		if (time_right_now()-space_time>=555){
			drop_block();
		}
		space_time = time_right_now();
	}
}

bool window::further(){
	for (auto it : crblock){
		if (bbarr[it.first-origin_x][it.second+1-origin_y]==true){return false;}
	}
	return true;
}

void window::check_line_complete(){
	int i = 20;
	while(i>1){
		int count =0;
		for(int j=1;j<=19;j+=2){
			if(bbarr[j][i]==true){
				count++;
			}
		}
		if (count == 10){
			chunk_drop(i);
			i = 21;
		}
		i--;
	}
}

void window::chunk_drop(int i){
	score_card+=49;
	int n = i;
	for(int l=1;l<=19;l+=2){
		move(n+origin_y,l+origin_x);
		printw("%s",blank.c_str());
	}
	refresh();
	usleep(bgdel);
	for(int j=i;j>2;j--){
		for(int k=1;k<=19;k+=2){
			if(bbarr[k][j-1]==true){bbarr[k][j]=true;}else{bbarr[k][j]=false;}
			if(bbarr[k][j]==true){move(j+origin_y,k+origin_x);printw("%s",pixel.c_str());}else{move(j+origin_y,k+origin_x);printw("%s",blank.c_str());}
			refresh();
		}
	}
	refresh();
}

bool window::game_over(){
	int over=0;
	for(int i=3;i<=17;i+=2){
		if(bbarr[i][2]==true){over++;}
	}
	if (over>1){return true;}
	return false;
}

void window::start(){
	print_instructions();
	make_block();
	while(!quit){
		generate_block();
		move_block();
		check_line_complete();
		usleep(del);
		if(game_over()){break;}
	}
}
