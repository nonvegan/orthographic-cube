#include <SFML/Graphics.hpp>
#include "matrix.h"
#include <iostream>
#include <vector>

int main()
{
	const int WIDTH = 1280;
	const int HEIGHT = 720;
	double angle = 1;
	double size = 100.0;
	double vertexWidth = 5.0;
	sf::Color backgroundColor = sf::Color(40, 44, 52);
	sf::Clock clock;

	Matrix cubeMatrix(8, 3, {
		{-size,-size,-size},
		{size,-size,-size},
		{size,size,-size},
		{-size,size,-size},
		{-size,-size,size},
		{size,-size,size},
		{size,size,size},
		{-size,size,size},
		});
	Matrix projectionMatrix(3, 2, {
		{1.f,0.f,},
		{0.f,1.f,},
		{0.f,0.f }
		});

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Orthographic Cube");
	window.setView(sf::View(sf::Vector2f(0.f, 0.f), sf::Vector2f(WIDTH, HEIGHT)));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(backgroundColor);

		rotateMatrixX(cubeMatrix, angle);
		rotateMatrixY(cubeMatrix, -angle);
		rotateMatrixZ(cubeMatrix, angle);
		Matrix projectedMatrix = multMatrix(cubeMatrix, projectionMatrix);
		for (int i = 0; i < projectedMatrix.rows; i++) {//Drawing Vertexe
			sf::CircleShape vertex(5);
			vertex.setPosition(sf::Vector2f(projectedMatrix.array[i][0] - vertexWidth / 2.0, projectedMatrix.array[i][1] - vertexWidth / 2.0));
			window.draw(vertex);
		}
		for (int i = 0; i < 4; i++) {//Drawing edges

			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(projectedMatrix.array[i][0] + vertexWidth / 2.0, projectedMatrix.array[i][1] + vertexWidth / 2.0)),
				sf::Vertex(sf::Vector2f(projectedMatrix.array[(i + 1) % 4][0] + vertexWidth / 2.0, projectedMatrix.array[(i + 1) % 4][1] + vertexWidth / 2.0)),
				sf::Vertex(sf::Vector2f(projectedMatrix.array[i][0] + vertexWidth / 2.0, projectedMatrix.array[i][1] + vertexWidth / 2.0)),
				sf::Vertex(sf::Vector2f(projectedMatrix.array[i + 4][0] + vertexWidth / 2.0, projectedMatrix.array[i + 4][1] + vertexWidth / 2.0)),
				sf::Vertex(sf::Vector2f(projectedMatrix.array[i + 4][0] + vertexWidth / 2.0, projectedMatrix.array[i + 4][1] + vertexWidth / 2.0)),
				sf::Vertex(sf::Vector2f(projectedMatrix.array[(i + 1) % 4 + 4][0] + vertexWidth / 2.0, projectedMatrix.array[(i + 1) % 4 + 4][1] + vertexWidth / 2.0)),
			};
			window.draw(line, 6, sf::Lines);
		}
		window.display();
		angle = clock.restart().asSeconds();
	}
}