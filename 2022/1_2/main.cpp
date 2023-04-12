#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int main(int argc, char** argv){
	fstream input;
	string test;
	vector<int> container;
	int sum = 0 ;
	int max = 0;
	int second_max = 0;
	int third_max = 0;

	input.open(argv[1],ios::in);
	if(!input.is_open()){
		cerr << "File not found!" << endl;
		return -1;
	}
	else
	{	
		while(getline(input,test)){
			if(test == ""){
				container.push_back(sum);
				sum = 0;

			}
			else
				sum += stoi(test);
		}
		sort(container.begin(),container.end(),greater<int>());
	}
	cout << container[0] << endl << container[1] << endl << container[2] << endl << container[0]+container[1]+container[2] << endl; 
}
