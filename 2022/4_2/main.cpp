#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int compare(int a,int b, int c, int d){
	if(b >= c && b <=d)
		return 1;
	if(d >= a && d <= b)
		return 1;
	return 0;	

}




int main(int argc, char** argv){
	fstream input;
	string line;
	int score = 0;
	int array[4];
	input.open("input.txt",ios::in);
	int pos;

	while(getline(input,line)){
		array[0] = stoi(line.substr(0,line.find_first_of('-')));
		array[1] = stoi(line.substr(pos = line.find_first_of('-')+1,line.find_first_of(',')-pos));
		array[2] = stoi(line.substr(pos = line.find_first_of(',')+1,line.find_last_of('-')-pos));
		array[3] = stoi(line.substr(pos = line.find_last_of('-')+1,line.size()-pos));
		
		score += compare(array[0],array[1],array[2],array[3]);	
	}
	cout << score << endl;

	return 0;
}
