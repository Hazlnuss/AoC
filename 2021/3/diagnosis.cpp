#include <bitset>
#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char **argv){
	if(argc != 1)
		return -1;

	std::ifstream input("input.txt");
	std::vector<std::bitset<12>> container;
	std::string line;
	std::bitset<12> result;
	unsigned long gamma;
	unsigned long epsilon;
	int finalresult;

	while(getline(input,line)){
		std::bitset<12> b{line};
		container.push_back(b);
	}

	for(int i = 0; i < 12;i++){
		int one = 0;
		int zero = 0;
		for(auto e : container){
			if(e[i]==1)
				one++;
			else
				zero++;
		}
		if(one > zero)
			result[i] = 1;
		else 
			result[i] = 0;	
	}
	
	gamma = result.to_ulong();
	result = result.flip();
	epsilon = result.to_ulong();

	finalresult = gamma * epsilon;
	std::cout << "Das Ergebnis ist: " << finalresult << std::endl;
	return 0;
}
