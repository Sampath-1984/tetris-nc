#include <iostream>
#include <vector>
#include <curses.h>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>
#include <ctime>
#include <chrono>
#ifndef TETRIS_H
#define TETRIS_H

using namespace std;


class window{
	protected:
	string pixel, blank;
	int origin_x, origin_y, del, bgdel;
	long long last_falltime=0, space_time=0;
	// SHAPES
	vector<pair<int,int>> line;
	vector<pair<int,int>> square;
	vector<pair<int,int>> squiggly;
	vector<pair<int,int>> ell;
	vector<pair<int,int>> tee;
	vector<pair<int,int>> reverse_squiggly;
	vector<pair<int,int>> reverse_ell;
	
	vector<pair<int,int>> crblock;
	vector<pair<int,int>> chblock;
	bool bbarr[22][22];

	private:
	long long time_right_now();
	void update_score();
	void print_instructions();
	void draw_box(int startx, int starty, int width, int height);
	void make_block();
	void generate_block();
	void move_block();
	void move_sideways();
	void move_right();
	void move_left();
	void rotate_block();
	void drop_block();
	void check_pause();
	void check_line_complete();
	bool check_rotate();
	void chunk_drop(int i);
	bool game_over();
	bool further();
	bool pause=false;
	bool quit=false;
	string crblock_type;
	int crblock_orientation;

	public:
	window();
	~window();
	void start();
	int maxheight, maxwidth;
	int score_card=0;
};


#endif
