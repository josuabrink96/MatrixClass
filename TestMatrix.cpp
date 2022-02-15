#include "TestMatrix.h"

int runTests() 
{
	//testPrint();
	//testCopyConstructor();
	//testOverloadedOperator();
	//testDefaultConstructor();
	//testFillRand();
	//testGetElement();
	//testOutputOperator();
	//testSetRowCount();
	//testSetColCount();
	testAdditionOperator();

	return 0;
}

int testPrint() 
{
	MatrixN::Matrix m(5, 5, 10.5);
	m.printMatrix();
	return 0;
}

int testCopyConstructor()
{
	MatrixN::Matrix m1(5, 5, 10.5);
	MatrixN::Matrix m2(m1);

	m1.printMatrix();

	std::cout << std::endl;

	m2.printMatrix();

	return 0;
}

int testDefaultConstructor()
{
	MatrixN::Matrix m;
	m.printMatrix();

	return 0;
}

int testFillRand()
{
	MatrixN::Matrix m(10, 10);
	m.printMatrix();

	std::cout << std::endl;

	m.fillRand();
	m.printMatrix();

	return 0;
}

int testGetElement()
{
	MatrixN::Matrix m(3, 3, 5);
	std::vector<double> row = m.getRow(0);
	row.at(2) = 2;

	m.setRow(row, 0);
	m.printMatrix();

	std::cout << std::endl << m.getElement(0, 2);

	return 0;
}

int testAssignmentOperator()
{
	MatrixN::Matrix m1(10, 10, 10.5);
	MatrixN::Matrix m2(5, 5, 20.5);

	m1.printMatrix();
	std::cout << std::endl;
	m2.printMatrix();
	std::cout << std::endl;

	m2 = m1;
	m2.printMatrix();
	return 0;
}

int testOutputOperator()
{
	MatrixN::Matrix m(5, 5, 5);
	std::cout << m;

	return 0;
}

int testAdditionOperator()
{
	MatrixN::Matrix m1(5, 5, 5);
	MatrixN::Matrix m2(5, 5, 5);

	std::cout << m1 + m2;
	return 0;
}

int testSetRowCount()
{
	MatrixN::Matrix m(5, 5, 5);
	std::cout << m << std::endl;
	m.setRowCount(10);
	std::cout << m;
	return 0;
}

int testSetColCount()
{
	MatrixN::Matrix m(5, 5, 5);
	std::cout << m << std::endl;
	m.setColCount(10);
	std::cout << m;
	return 0;
}