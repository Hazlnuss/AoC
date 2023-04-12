#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "rope.h"
using namespace std;

int main(int argc, char** argv){
	fstream input;
	input.open("text.txt",ios::in);
	string line;
	rope test;
	if(!input.is_open())
		return -1;
	while(getline(input,line)){
		int a = line[2] - 48;
		test.move_head(line[0],a);		
	}
	cout << "Lösung: " << test.visited_places.size() << endl;
	return 0;
}
