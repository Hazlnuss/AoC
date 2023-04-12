SRC = main.cpp rope.cpp
OBJ = $(SRC:%.cpp = %.o)

run.x: $(OBJ)
	g++ -std=c++17 -ggdb3 -O0 $(OBJ) -o $@
%.o: %.cpp rope.h
	g++ -std=c++17 -ggdb3 -O0 -c $< -o $@

