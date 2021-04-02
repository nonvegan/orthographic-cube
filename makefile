main : ./src/orthographic-cube.cpp
	g++ ./src/orthographic-cube.cpp ./src/matrix.cpp -o orthographic-cube -lsfml-graphics -lsfml-window -lsfml-system

