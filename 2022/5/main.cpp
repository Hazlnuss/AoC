#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>
using namespace std;

void print(vector<char>& container){
	for(char x : container)
		cout << x << " ";
	cout << endl;
}

int main(int argc, char** argv){
	fstream input;
	input.open("input.txt",ios::in);
	string line;
	vector<char> container[9];
	int a,b,c;

	for(int i = 0;i < 8;i++){
		getline(input,line);
		for(int j = 0; j < 9;j++ ){		
			if(line[j*4] != ' ')
				container[j].insert(container[j].begin(),line[j*4+1]);
		}
	}
	getline(input,line);
	getline(input,line);	
	while(getline(input,line)){
		if(isdigit(line[6])){
			a = stoi(line.substr(5,2));
			b = stoi(line.substr(13,1))-1;
			c = stoi(line.substr(18,1))-1;	
		}
		else{
			a = stoi(line.substr(5,1));
			b = stoi(line.substr(12,1))-1;
			c = stoi(line.substr(17,1))-1;
		}
		for(int i = 0; i < a; i++){
			char t;
			t = container[b][container[b].size()-1];
			container[b].pop_back();
			container[c].push_back(t);
		}
	}
		for(auto x : container)
			print(x);

	return 0;
}
