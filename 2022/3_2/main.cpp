#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv){
	fstream input;
	string first_elf;
	string second_elf;
	string third_elf;
	input.open("input.txt",ios::in);
	int score = 0;
	while(getline(input,first_elf) && getline(input,second_elf) && getline(input,third_elf)){
		for(char c : first_elf){
			if(second_elf.contains(c)){
				if(third_elf.contains(c)){
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
	}
		cout << score << endl;

	return 0;
}

