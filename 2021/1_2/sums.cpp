#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

int main(int argc, char **argv){

	if(argc != 2){
		std::cerr << "Wrong Argument count!" << std::endl;
		return -1;
	}

	std::ifstream infile(argv[1]);
	std::string input;
	std::vector<int> container;
	int counter = 0;
	
	if(!infile.is_open()){
		std::cerr << "File is not open!" << std::endl;
		return -1;
	}

	while(getline(infile,input))
		container.push_back(atoi(input.c_str()));
	
	std::cout << "Container size: " << container.size() << std::endl;
	std::cout << "Last Container int to meassure: " << container[1997] << std::endl;
	int sum1 = container[0] + container[1] + container[2];
	int sum2 = 0;
	for(int i = 1; i < 1998;i++){
		sum2 = container[i] + container[i+1] + container[i+2];
	 	if(sum1 < sum2)
			counter++;
		sum1 = sum2;
	}
	std::cout << counter << std::endl;


	return 0;
}
