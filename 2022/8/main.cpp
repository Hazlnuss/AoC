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
	int count = 0;
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
			int visible_sites = 4;
			for(int k = 0; k < i;k++){
				if(grid[k][j] >= grid[i][j]){
					visible_sites--;
					break;
				}
			}
			for(int k = i+1; k < grid.size();k++){
				if(grid[k][j] >= grid[i][j]){
					visible_sites--;
					break;
				}
			}
			for(int k = 0; k < j;k++){
				if(grid[i][k] >= grid[i][j]){
					visible_sites--;
					break;
				}
			}
			for(int k = j+1;k < grid[0].size();k++){
				if(grid[i][k] >= grid[i][j]){
					visible_sites--;
					break;
				}
			}
			if(visible_sites > 0){
				count++;
			}
		}
	}
	cout << "Lösung: " << count << endl;

	return 0;
}
