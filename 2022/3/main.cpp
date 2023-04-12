#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv){
	fstream input;
	string line;
	input.open("input.txt",ios::in);
	int score = 0;
	while(getline(input,line)){
		string first_half = line.substr(0,line.size()/2);
		string second_half = line.substr(line.size()/2,line.size());
		for(char c : first_half){
			if(second_half.contains(c)){
				if(c >= 'a' && c <= 'z'){
					score += c - 96;
				}	
				else{
					score += c - 38;
				}
				break;
			} 
		}
	}
		cout << score << endl;

	return 0;
}

