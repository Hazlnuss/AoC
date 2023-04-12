#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv){
	fstream input;
	string test;
	int sum = 0 ;
	int max_sum = 0;
	vector<string> input_container;

	input.open(argv[1],ios::in);
	if(!input.is_open()){
		cerr << "File not found!" << endl;
		return -1;
	}
	else
	{	
		while(getline(input,test)){
		if(test == ""){
			if(sum > max_sum)
				max_sum = sum;
				sum = 0;
		}
		else
			sum += stoi(test);
		
		}
		cout << max_sum << endl;
	}
}
