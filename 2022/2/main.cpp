#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv){
	fstream input;
	input.open(argv[1],ios::in);
	string line;
	int score = 0;
	if(!input.is_open()){
		cerr << "File not found" << endl;
		return -1;
	}
	else{
		while(getline(input,line)){
			switch(line[2]){
				case 'X':
					if(line[0]=='A')
						score += 4;
					if(line[0]=='B')
						score += 1;
					if(line[0]=='C')
						score += 7;
					break;
				case 'Y':
					if(line[0]=='A')
						score += 8;
					if(line[0]=='B')
						score += 5;
					if(line[0]=='C')
						score += 2;				
					break;
				case 'Z':
					if(line[0]=='A')
						score += 3;
					if(line[0]=='B')
						score += 9;
					if(line[0]=='C')
						score += 6;
					break;
				default:
					break;
			}
		
		}
		cout << score << endl;
	}		
			
}
