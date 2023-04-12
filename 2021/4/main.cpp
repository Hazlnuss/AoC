#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class bingo_field{
 	pair<int,bool> Field[5][5];
	
	bingo_field(){
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				Field[i][j]={0,0};
			}		
		}
	}
	~bingo_field(){}


	bool won(){
		for(int i = 0;i < 5;i++){
			int row = 0;
			for(int j; j < 5; j++){
				if(Field[i][j].second==true)
					row++;
			}
			if(row == 5)
				return true;
		}
		for(int j = 0;j < 5; j++){
			int column = 0;
			for(int i = 0;i < 5; i++){
				if(Field[i][j].second==true)
					column++;
			}	
			if(column == 5)
				return true;
		}
		return false;
	}
		

	void new_draw(int bingoball){
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				if(Field[i][j].first==bingoball)
					Field[i][j].second == true;
			}
		}
	}	
};

int main(int argc, char** argv){
	
	// Gültigkeit der Datei prüfen und einlesen
	ifstream input(argv[1]);
	string line;
	vector<string> container;
	
	if(argc != 2)
		return -1;
	
	if(!input.is_open())
		return -1;
	
	while(getline(input,line)){
		container.push_back(line);	
	}

	//Bingo Felder und Ziehreihenfolge abspeichern
	vector<int> ziehung;
	vector<bingo_field> felder;

	return 0;
}
