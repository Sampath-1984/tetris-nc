#include "tetris.h"

void window::rotate_block(){
	chblock.clear();
	int x,y;
	if (crblock_type=="square"){
		// empty
		chblock = crblock;
	} else if (crblock_type=="line"){
		if (crblock_orientation==0){
			x=crblock[0].first;
			y=crblock[0].second;
			chblock.push_back(make_pair(x+2,y-1));
			chblock.push_back(make_pair(x+2,y+0));
			chblock.push_back(make_pair(x+2,y+1));
			chblock.push_back(make_pair(x+2,y+2));
			if(check_rotate()){crblock_orientation=1;}
		} else if (crblock_orientation==1){
			x=crblock[0].first;
			y=crblock[0].second;
			chblock.push_back(make_pair(x-2,y+1));
			chblock.push_back(make_pair(x+0,y+1));
			chblock.push_back(make_pair(x+2,y+1));
			chblock.push_back(make_pair(x+4,y+1));
			if(check_rotate()){crblock_orientation=0;}
		}
	} else if (crblock_type=="squiggly"){
		if (crblock_orientation==0){
			x=crblock[0].first;
			y=crblock[0].second;
			chblock.push_back(make_pair(x-2,y+0));
			chblock.push_back(make_pair(x-2,y+1));
			chblock.push_back(make_pair(x-0,y+1));
			chblock.push_back(make_pair(x-0,y+2));
			if(check_rotate()){crblock_orientation=1;}
		} else if (crblock_orientation==1){
			x=crblock[0].first;
			y=crblock[0].second;
			chblock.push_back(make_pair(x+2,y+0));
			chblock.push_back(make_pair(x+4,y+0));
			chblock.push_back(make_pair(x+0,y+1));
			chblock.push_back(make_pair(x+2,y+1));
			if(check_rotate()){crblock_orientation=0;}
		}
	} else if (crblock_type=="reverse_squiggly"){
		if (crblock_orientation==0){
			x=crblock[0].first;
			y=crblock[0].second;
			chblock.push_back(make_pair(x+2,y+0));
			chblock.push_back(make_pair(x+0,y+1));
			chblock.push_back(make_pair(x+2,y+1));
			chblock.push_back(make_pair(x+0,y+2));
			if(check_rotate()){crblock_orientation=1;}
		} else if (crblock_orientation==1){
			x=crblock[0].first;
			y=crblock[0].second;
			chblock.push_back(make_pair(x-2,y+0));
			chblock.push_back(make_pair(x+0,y+0));
			chblock.push_back(make_pair(x+0,y+1));
			chblock.push_back(make_pair(x+2,y+1));
			if(check_rotate()){crblock_orientation=0;}
		}
	} else if (crblock_type=="tee"){
		if (crblock_orientation==0){
			x=crblock[0].first;
			y=crblock[0].second;
			chblock.push_back(make_pair(x+0,y+0));
			chblock.push_back(make_pair(x-2,y+1));
			chblock.push_back(make_pair(x+0,y+1));
			chblock.push_back(make_pair(x+0,y+2));
			if(check_rotate()){crblock_orientation=1;}
		} else if (crblock_orientation==1){
			x=crblock[0].first;
			y=crblock[0].second;
			chblock.push_back(make_pair(x-2,y+1));
			chblock.push_back(make_pair(x+0,y+1));
			chblock.push_back(make_pair(x+2,y+1));
			chblock.push_back(make_pair(x+0,y+2));
			if(check_rotate()){crblock_orientation=2;}
		} else if (crblock_orientation==2){
			x=crblock[0].first;
			y=crblock[0].second;
			chblock.push_back(make_pair(x+2,y-1));
			chblock.push_back(make_pair(x+2,y+0));
			chblock.push_back(make_pair(x+2,y+1));
			chblock.push_back(make_pair(x+4,y+0));
			if(check_rotate()){crblock_orientation=3;}
		} else if (crblock_orientation==3){
			x=crblock[0].first;
			y=crblock[0].second;
			chblock.push_back(make_pair(x+0,y+0));
			chblock.push_back(make_pair(x-2,y+1));
			chblock.push_back(make_pair(x+0,y+1));
			chblock.push_back(make_pair(x+2,y+1));
			if(check_rotate()){crblock_orientation=0;}
		}
	} else if (crblock_type=="ell"){
		if (crblock_orientation==0){
			x=crblock[0].first;
			y=crblock[0].second;
			chblock.push_back(make_pair(x-4,y+0));
			chblock.push_back(make_pair(x-2,y+0));
			chblock.push_back(make_pair(x-2,y+1));
			chblock.push_back(make_pair(x-2,y+2));
			if(check_rotate()){crblock_orientation=1;}
		} else if (crblock_orientation==1){
			x=crblock[0].first;
			y=crblock[0].second;
			chblock.push_back(make_pair(x+0,y+1));
			chblock.push_back(make_pair(x+2,y+1));
			chblock.push_back(make_pair(x+4,y+1));
			chblock.push_back(make_pair(x+0,y+2));
			if(check_rotate()){crblock_orientation=2;}
		} else if (crblock_orientation==2){
			x=crblock[0].first;
			y=crblock[0].second;
			chblock.push_back(make_pair(x+2,y-1));
			chblock.push_back(make_pair(x+2,y+0));
			chblock.push_back(make_pair(x+2,y+1));
			chblock.push_back(make_pair(x+4,y+1));
			if(check_rotate()){crblock_orientation=3;}
		} else if (crblock_orientation==3){
			x=crblock[0].first;
			y=crblock[0].second;
			chblock.push_back(make_pair(x+2,y+0));
			chblock.push_back(make_pair(x-2,y+1));
			chblock.push_back(make_pair(x+0,y+1));
			chblock.push_back(make_pair(x+2,y+1));
			if(check_rotate()){crblock_orientation=0;}
		}
	} else if (crblock_type=="reverse_ell"){
		if (crblock_orientation==0){
			x=crblock[0].first;
			y=crblock[0].second;
			chblock.push_back(make_pair(x+2,y+0));
			chblock.push_back(make_pair(x+2,y+1));
			chblock.push_back(make_pair(x+2,y+2));
			chblock.push_back(make_pair(x+0,y+2));
			if(check_rotate()){crblock_orientation=1;}
		} else if (crblock_orientation==1){
			x=crblock[0].first;
			y=crblock[0].second;
			chblock.push_back(make_pair(x-2,y+1));
			chblock.push_back(make_pair(x+0,y+1));
			chblock.push_back(make_pair(x+2,y+1));
			chblock.push_back(make_pair(x+2,y+2));
			if(check_rotate()){crblock_orientation=2;}
		} else if (crblock_orientation==2){
			x=crblock[0].first;
			y=crblock[0].second;
			chblock.push_back(make_pair(x+2,y-1));
			chblock.push_back(make_pair(x+4,y-1));
			chblock.push_back(make_pair(x+2,y+0));
			chblock.push_back(make_pair(x+2,y+1));
			if(check_rotate()){crblock_orientation=3;}
		} else if (crblock_orientation==3){
			x=crblock[0].first;
			y=crblock[0].second;
			chblock.push_back(make_pair(x-2,y+0));
			chblock.push_back(make_pair(x-2,y+1));
			chblock.push_back(make_pair(x+0,y+1));
			chblock.push_back(make_pair(x+2,y+1));
			if(check_rotate()){crblock_orientation=0;}
		}
	}

	if (check_rotate()){
		//move_block_equiv.
		for(auto it:crblock){
			move(it.second,it.first);
			printw("%s",blank.c_str());
		}
		crblock=chblock;
		for(auto it:crblock){
			move(it.second,it.first);
			printw("%s",pixel.c_str());
		}
		refresh();
	}
}

bool window::check_rotate(){
	for (auto it : chblock){
		if ((it.first-origin_x<=0)||bbarr[it.first-origin_x][it.second-origin_y]==true){return false;}
	}
	return true;
}
