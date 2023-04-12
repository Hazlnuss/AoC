#include <fstream>
#include <utility>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char **argv){
	
	if(argc != 2){
		std::cerr << "Argument Error!" << std::endl;
	}
	std::ifstream input(argv[1]);
	std::string line;
	std::vector<std::pair<std::string,int>> container;
	std::stringstream ss;
	int depth = 0;
	int horizontally = 0;
	int aim = 0;

	while(getline(input,line)){
		ss << line;
		std::string pairstring;
		int pairint;
		ss >> pairstring >> pairint;
		std::cout << "(" << pairstring << "," << pairint << ")" << std::endl;
		std::pair<std::string,int> p(pairstring,pairint);
		container.push_back(p);
		ss.clear();
	}
	for(int i = 0; i < container.size(); i++){
		if(container[i].first=="forward"){
			horizontally += container[i].second;
			depth += (aim*container[i].second);
		}
		if(container[i].first=="up")
			aim -= container[i].second;
		if(container[i].first=="down")
			aim += container[i].second;
	}
	std::cout << "Total Depth: " << depth << " Total Horizontal: " << horizontally << std::endl;
	std::cout << "Result: " << (depth*horizontally) << std::endl;
	return 0;
}
