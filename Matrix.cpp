#include "Matrix.h"

namespace MatrixN 
{
	Matrix::Matrix()
	{
		matrixCnt++;

		row = 1;
		col = 1;

		mat.resize(col);
		mat.at(0).resize(row);
		mat.at(0).at(0) = 0;
	}

	Matrix::Matrix(const int r, const int c)
	{
		matrixCnt++;

		row = r;
		col = c;
		mat.resize(c);
		for (auto& y : mat) {
			y.resize(r);
		}
	}

	Matrix::Matrix(const int r, const int c, const double d)
	{
		matrixCnt++;

		row = r;
		col = c;
		mat.resize(c);
		for (auto& y : mat) {
			y.resize(r);
		}

		for (auto& y : mat) {
			for (auto& x : y) {
				x = d;
			}
		}
	}

	Matrix::Matrix(Matrix& m)
	{
		matrixCnt++;

		row = m.getRowCount();
		col = m.getColCount();

		mat = m.getMatrix();
	}

	Matrix::~Matrix()
	{
		matrixCnt--;
	}

	int Matrix::printMatrix()
	{
		for (auto& y : mat) {
			for (auto& x : y) {
				std::cout << x << " ";
			}
			std::cout << std::endl;
		}

		return 0;
	}

	int Matrix::getMatrixCount()
	{
		return matrixCnt;
	}

	int Matrix::getRowCount()
	{
		return row;
	}

	int Matrix::setRowCount(const int r)
	{
		row = r;
		mat.resize(row);
		for (auto& r : mat) {
			r.resize(col);
		}
		return 0;
	}

	int Matrix::getColCount()
	{
		return col;
	}

	int Matrix::setColCount(const int c)
	{
		col = c;
		for (auto& r : mat) {
			r.resize(c);
		}
		return 0;
	}

	std::vector<double> Matrix::getRow(int r)
	{
		return mat.at(r);
	}

	int Matrix::setRow(const std::vector<double> &r, const int pos)
	{
		mat.at(pos) = r;
		return 0;
	}

	double Matrix::getElement(const int r, const int c)
	{
		double element;
		std::vector<double> row = mat.at(r);
		element = row.at(c);
		return element;
	}

	int Matrix::fillRand()
	{
		static std::default_random_engine engine;
		static std::uniform_real_distribution <double> val(0, 9);

		for (auto& r : mat) {
			for (auto& c : r) {
				c = val(engine);
			}
		}
		return 0;
	}

	std::vector<std::vector<double>> Matrix::getMatrix()
	{
		return mat;
	}

	Matrix& Matrix::operator=(const Matrix& rhs)
	{
		if (&rhs == this) {
			return *this;
		}
		row = rhs.row;
		col = rhs.col;
		mat = rhs.mat;

		return *this;
	}

	Matrix& Matrix::operator+(const Matrix& rhs)
	{
		if (row == rhs.row && col == rhs.col) {
			for (unsigned r = 0; r < mat.size(); r++) {
				for (unsigned c = 0; c < mat.at(r).size(); c++)
				{
					mat.at(r).at(c) += rhs.mat.at(r).at(c);
				}
			}
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& output, Matrix& m)
	{
		for (auto& r : m.getMatrix()) {
			for (auto& c : r) {
				output << c << " ";
			}
			output << std::endl;
		}
		return output;
	}
}