#include "matrix.h"

Matrix::Matrix(int rows, int cols, std::vector<std::vector<double>> array) {
	this->rows = rows;
	this->cols = cols;
	this->array = array;
};

Matrix multMatrix(Matrix& projectedMatrixA, Matrix& projectedMatrixB)
{
	if (projectedMatrixA.cols != projectedMatrixB.rows)
		throw "Number of cols of the 1st projectedMatrix don't match the number of rows of the 2nd projectedMatrix";
	Matrix multipliedMatrix(projectedMatrixA.rows, projectedMatrixB.cols, std::vector<std::vector<double>>(projectedMatrixA.rows, std::vector<double>(projectedMatrixB.cols, 0)));
	for (int i = 0; i < projectedMatrixA.rows; i++)
	{
		for (int j = 0; j < projectedMatrixB.cols; j++)
		{
			multipliedMatrix.array[i][j] = 0;
			for (int k = 0; k < projectedMatrixA.cols; k++) {
				multipliedMatrix.array[i][j] += projectedMatrixA.array[i][k] * projectedMatrixB.array[k][j];
			}
		}
	}
	return multipliedMatrix;
}

void printMatrix(Matrix& projectedMatrix) {
	for (int i = 0; i < projectedMatrix.rows; i++) {
		for (int j = 0; j < projectedMatrix.cols; j++) {
			std::cout << projectedMatrix.array[i][j] << '\t';
		}
		std::cout << '\n';
	}
}

void rotateMatrixX(Matrix& projectedMatrix, double angle) {
	Matrix rotationMatrix(3, 3, { {1,0,0},{0,cos(angle),-sin(angle)},{0,sin(angle),cos(angle)} });
	projectedMatrix = multMatrix(projectedMatrix, rotationMatrix);
}

void rotateMatrixY(Matrix& projectedMatrix, double angle) {
	Matrix rotationMatrix(3, 3, { {cos(angle),0,sin(angle)},{0,1,0},{-sin(angle),0,cos(angle)} });
	projectedMatrix = multMatrix(projectedMatrix, rotationMatrix);
}

void rotateMatrixZ(Matrix& projectedMatrix, double angle) {
	Matrix rotationMatrix(3, 3, { {cos(angle),-sin(angle),0},{sin(angle),cos(angle),0},{0,0,1} });
	projectedMatrix = multMatrix(projectedMatrix, rotationMatrix);
}