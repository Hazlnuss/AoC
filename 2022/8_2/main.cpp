#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv){
	fstream input;
	input.open("input.txt",ios::in);
	string line;
	int highscore = 0;
	vector<vector<int>> grid; 
	while(getline(input, line)){
		vector<int> trees;
		for(int i = 0; i < line.size();i++){
			trees.push_back(line[i]-48);
		}
		grid.push_back(trees);
	}
	for(int i = 0; i < grid.size();i++){
		for(int j = 0; j < grid[0].size();j++){
			int north = 0;
			int west = 0;
			int south = 0;
			int east = 0;

			for(int k = i-1; k >= 0;k--){
				north++;
				if(grid[k][j] >= grid[i][j]){
					break;
				}
			}
			for(int k = i+1; k < grid.size();k++){
				south++;
				if(grid[k][j] >= grid[i][j]){
					break;
				}
			}
			for(int k = j-1; k >= 0;k--){
				west++;
				if(grid[i][k] >= grid[i][j]){
					break;
				}
			}
			for(int k = j+1;k < grid[0].size();k++){
				east++;
				if(grid[i][k] >= grid[i][j]){
					break;
				}
			}
			int scene = north * south * west * east;
			if(scene > highscore){
				highscore = scene;
			}
		}
	}
	cout << "Lösung: " << highscore << endl;

	return 0;
}
