#pragma once 
#include <iostream>
#include <vector>
#include <string>
#include <utility>
struct rope{
	std::pair<int,int> H{0,0};
	std::pair<int,int> T{0,0};
	std::vector<std::pair<int,int>> visited_places{};

	void move_head(char direction,int steps);
	void save_place(std::pair<int,int> place);

	void move_tail();
};
