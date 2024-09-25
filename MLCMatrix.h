#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

typedef std::vector<double> VectorDouble;

class MLCMatrix {
private:
	std::vector<VectorDouble> data;
	int rows =1;
	int columns=1;

public:
	MLCMatrix(int rows, int cols);

	MLCMatrix();

	int getRows() const;

	int getColumns() const;


	double& operator()(int row, int col);

	bool insertRow(const VectorDouble& newRow);

	bool insertRow(int position, const VectorDouble& newRow);

	bool insertRow(int position, VectorDouble& newRow, bool hardInsert);

	void insertRowEmptyRow();

	static bool fromCSV(const std::string& filename, MLCMatrix& matrix);
};