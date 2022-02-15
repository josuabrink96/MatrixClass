#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <random>

namespace MatrixN {
	static int matrixCnt;

	class Matrix {
		private:
			int row;
			int col;
			std::vector<std::vector<double>> mat;

		public:
			Matrix();
			Matrix(const int, const int);
			Matrix(const int, const int, const double);
			Matrix(Matrix&);
			~Matrix();
			Matrix& operator=(const Matrix&);
			Matrix& operator+(const Matrix&);

			int printMatrix();
			int getMatrixCount();
			int getRowCount();
			int getColCount();
			double getElement(int, int);

			int setRowCount(const int);
			int setColCount(const int);
			int setRow(const std::vector<double>&, const int);


			std::vector<double> getRow(int);
			std::vector<std::vector<double>> getMatrix();

			int fillRand();
	};
	std::ostream& operator<<(std::ostream&, Matrix&);
}

#endif