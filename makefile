ortho-cube : ./src/orthographic-cube.cpp ./src/matrix.cpp
	g++ ./src/orthographic-cube.cpp ./src/matrix.cpp -o ortho-cube -lsfml-graphics -lsfml-window -lsfml-system

