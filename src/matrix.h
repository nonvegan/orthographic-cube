#pragma once
#include <vector>
#include <iostream>
#include <math.h>

struct Matrix {
	int rows;
	int cols;
	std::vector<std::vector<double>> array;
	Matrix(int rows, int cols, std::vector<std::vector<double>> array);
};

Matrix multMatrix(Matrix& projectedMatrixA, Matrix& projectedMatrixB);

void printMatrix(Matrix& projectedMatrix);

void rotateMatrixX(Matrix& projectedMatrix, double angle);

void rotateMatrixY(Matrix& projectedMatrix, double angle);

void rotateMatrixZ(Matrix& projectedMatrix, double angle);
