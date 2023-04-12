#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv){
	fstream input;
	input.open("input.txt",ios::in);
	string line;
	getline(input,line);
	int chars = 4;
	for(int i = 0; i < line.size()-4;i++){
		if(line[i] != line[i+1] && line[i] != line[i+2] && line[i] != line[i+3]){
			if(line[i+1] != line[i+2] && line[i+1] != line[i+3]){
				if(line[i+2] != line[i+3]){
					break;
				}
			}
		}
		chars++;
	}
	cout << chars;

	return 0;
}
