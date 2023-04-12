#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>

using namespace std;

//normal 12, test 5 Digitcount

string oxygen_search(vector<string> container,short digitcount){
	int count1,count0;
	vector<string> ones,zeros;
	for(int i = 0; i < digitcount; i++){
		for(auto e : container){
			if(e[i]=='1')
				ones.push_back(e);
			else
				zeros.push_back(e);
		}
		if(ones.size()>zeros.size() || ones.size() == zeros.size()){
			container = move(ones);
			zeros.clear();
		}
		else{
			container = move(zeros);
			ones.clear();
		}
		if(container.size()==1)
			break;		
	}	
	return container[0];	
}

string carbon_search(vector<string> container,short digitcount){
	vector<string> ones,zeros;
	for(int i = 0; i < digitcount; i++){
		for(auto e : container){
			if(e[i]=='1')
				ones.push_back(e);
			else
				zeros.push_back(e);
		}
		if(ones.size()<zeros.size()){
			container = ones;
			zeros.clear();
			ones.clear();
		}
		else{
			container = zeros;
			ones.clear();
			zeros.clear();
		}
		if(container.size()==1)
			break;
		
		/*for(auto e : container){
			cout << e << endl;
		}*/		
	}	
	return container[0];	
}

int main (int argc, char **argv){
	ifstream input(argv[1]);
	string line;
	vector<string> oxygen, carbon;
	
	while(getline(input,line)){
		oxygen.push_back(line);
	}
	carbon = oxygen;
	cout << "Das letzte verbliebene Element von Oxygen " << oxygen_search(oxygen,12) << endl;	
	cout << "Das letzte verbliebene Element von Carbon " << carbon_search(carbon,12) << endl;	
	
	return 0;
}
