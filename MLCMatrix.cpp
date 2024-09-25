#include "pch.h"
#include "MLCMatrix.h"

MLCMatrix::MLCMatrix(int rows, int cols)
{
	data.resize(rows, VectorDouble(cols, 0.0));
	rows = this->rows;
	columns = cols;
}

MLCMatrix::MLCMatrix()
{
	data.resize(1, VectorDouble(1, 0.0));
}

int MLCMatrix::getRows() const
{
	return rows;
}

int MLCMatrix::getColumns() const
{
	return columns;
}

double& MLCMatrix::operator()(int row, int col)
{
	return data[row][col];
}

bool MLCMatrix::insertRow(const VectorDouble& newRow)
{
	if (newRow.size() != columns) {
		return 0;
	}
	data.push_back(newRow);
	rows++;
	return 1;
}

bool MLCMatrix::insertRow(int position, const VectorDouble& newRow)
{
	if (newRow.size() != columns) {
		return 0;
	}

	if (position < 0 || position > rows) {
		return 0;
	}

	data.insert(data.begin() + position, newRow);
	rows++;
	return 1;
}

bool MLCMatrix::insertRow(int position, VectorDouble& newRow, bool hardInsert)
{
	if (position < 0 || position > rows) {
		return 0;
	}

	if (!hardInsert) {
		return this->insertRow(position, newRow);
	}

	if (newRow.size() < columns) {
		newRow.resize(columns, 0.0);
	}
	else {
		columns = (int)(newRow.size());
		for (VectorDouble& row : data) {
			row.resize(columns, 0.0);
		}
	}

	data.insert(data.begin() + position, newRow);
	rows++;
	return 1;

}

void MLCMatrix::insertRowEmptyRow()
{
	VectorDouble emptyRow(columns, 0.0);
	data.push_back(emptyRow);
	rows++;
}

bool MLCMatrix::fromCSV(const std::string& filename, MLCMatrix& matrix)
{

	std::ifstream file(filename);

	if (!file.is_open()) {

		return 0;
	}
	matrix.setColumns(0);
	matrix.setRows(0);
	std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string cell;
		VectorDouble row;
		
		while (std::getline(ss, cell, ';')) {

			try {
				row.push_back(std::stod(cell));  // ������������ ������ � �����
			}
			catch (const std::invalid_argument&) {
				row.push_back(0.0);  // � ������ ������ ���������� 0.0
			}
			catch (const std::out_of_range&) {
				row.push_back(0.0);
			}
		}

		if (matrix.columns == 0) {
			matrix.columns = (int)(row.size());
		}
		matrix.setColumns((int)row.size());
		matrix.data.push_back(row);
		matrix.rows++;
	}

	file.close();
	return 1;
}

void MLCMatrix::setRows(int newRows)
{
	if (newRows < rows) {
		data.resize(newRows);
	}
	else if (newRows > rows) {
		
		for (int i = rows; i < newRows; ++i) {
			data.push_back(VectorDouble(columns, 0.0));  
		}
	}
	rows = newRows;  
}

void MLCMatrix::setColumns(int newCols)
{
	
	for (VectorDouble& row : data) {
		row.resize(newCols, 0.0);  
	}
	columns = newCols;  
}
