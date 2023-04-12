#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv){
	fstream input;
	input.open("input.txt",ios::in);
	string line;
	getline(input,line);
	int chars = 14;
	int repeat_flag = 0;
	int streek = 0;
	for(int i = 0; i < line.size()-14;i++){
		for(int j = 0; j < 13; j++){
			for(int k = j+1; k < 14;k++){
				if(line[i+j]==line[i+k]){
					repeat_flag = 1;
					break;
				}
			}
			if(repeat_flag == 1){
				repeat_flag = 0;
				break;
			}
			streek++;
		}
		if(streek == 13)
			break;
		streek = 0;
		chars++;
	}
	cout << chars << endl;

	return 0;
}
