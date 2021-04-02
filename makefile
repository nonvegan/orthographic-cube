ortho-cube : ./src/orthographic-cube.cpp ./src/matrix.h ./src/matrix.cpp
	g++ ./src/orthographic-cube.cpp ./src/matrix.cpp -o orthographic-cube -lsfml-graphics -lsfml-window -lsfml-system

