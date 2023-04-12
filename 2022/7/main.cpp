#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct file{
	string name;
	int size;

	file(string name,int size):name(name),size(size){
	}
};

struct dir{
	string name;
	dir* up;
	vector<dir*> childs;
	vector<file*> files;
	long int total_size = 0;

	dir(string name,dir* up):name(name),up(up){}

	~dir(){
		for(auto x : childs)
			delete x;
		for(auto x : files)
			delete x;
	}

	void add_dir(string name){
		dir* directory = new dir(name,this);
		childs.push_back(directory);
	}

	void add_file(string name, int size){
		file* new_file = new file(name,size);
		files.push_back(new_file);
		dir* iterator = this;
		while(iterator != nullptr){
			iterator->total_size += size;
			iterator = iterator->up;
		}
	}

	void print_dir(int level){
		for(int i = 0; i < level;i++)
			cout << " ";
		cout << "- " <<  name << " (dir) " << total_size << endl;
		for(auto x : files){
			if(x != nullptr)
				for(int i = 0;i < level+1; i++)
					cout << " ";
					cout << "- " << x->name << " " << x->size << endl; 
		}	
		level++;	
		for(auto x : childs){
			if(x != nullptr)	
				x->print_dir(level);
		}
	}
	
	unsigned int print_sol(int level){
		int sum = 0;
		if(total_size <= 100000){
			cout << "- " <<  name << " (dir) " << total_size << endl;
			sum+=total_size;
		}
		level++;	
		for(auto x : childs){
			if(x != nullptr)	
				sum += x->print_sol(level);
		}
		return sum;
	}
	
};

int main(int argc, char** argv){
	fstream input;
	input.open("input.txt",ios::in);
	string line;
	dir head("/",nullptr);
	dir* it = &head;
	unsigned int solution;
	while(getline(input,line)){
		if(line[0] == '$'){ 
			if(line.substr(2,2)=="cd"){
				if(line[5] == '/'){
					it = &head;
				}
				else if(line.substr(5,2)== ".."){
					if(it->up != nullptr)	
						it = it->up;
				}
				else{
					string temp = line.substr(5,line.size()-5);
					for(int i = 0; i < it->childs.size();i++){
						if(it->childs[i]->name == temp){
							it = it->childs[i];
							break;
						}
					}				
				}
			}
			else if(line.substr(2,2) == "ls"){
				continue;
			}
		}
		else{
			bool found = false;
			int pos = 0;
			for(;isdigit(line[pos]);pos++);
			if(pos){
				string size = line.substr(0,pos);
				string name = line.substr(pos,line.size()-pos);
				for(int i = 0; i < it->files.size();i++){
					if(it->files[i]->name == name){
						found = true;
						break;
					}
				}
				if(!found){
					it->add_file(name,stoi(size));
				}
			}
			else{
				string name = line.substr(4,line.size()-4);
				for(int i = 0; i < it->childs.size();i++){
					if(it->childs[i]->name == name){
						found = true;
						break;
					}
				}
				if(!found){
					it->add_dir(name);
				}
			}
		
		}
	}
		//solution = head.print_sol(0); 
		//cout << "Lösung: " << solution << endl;
		head.print_dir(0);
	return 0;
}
