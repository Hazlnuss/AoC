#include "rope.h"

	void rope::move_head(char direction,int steps){
		for(int i = 0; i < steps; i++){
			switch(direction){
				case('U'):
					H.first ++;
					break;
				case('D'):
					H.first --;
					break;
				case('R'):
					H.second ++;
					break;
				case('L'):
					H.second --;
					break;
			
			}
		move_tail();
		}
	}
	void rope::save_place(std::pair<int,int> place){
		for(auto x : visited_places){
			if((x.first == place.first) && (x.second == place.second)){
				return;
			}
		}
		visited_places.push_back(place);		
	}
	void rope::move_tail(){
		if(H.second == (T.second+2)){
			T.second++;
			if(H.first == T.first+1)
				T.first++;
		}
		if(H.second == (T.second-2)){
			T.second--;
			if(H.first == T.first-1)
				T.first++;
			}
		if(H.first == (T.first+2)){
			T.first++;
			if(H.second == T.second+1)
				T.second++;
		}
		if(H.first == (T.first-2)){
			T.first--;
			if(H.second == T.second-1)
				T.second--;
		}
		rope::save_place(T);
	}

