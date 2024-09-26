#include "pch.h"
#include "MLCVecMatrix.h"

MLCVecMatrix::MLCVecMatrix(int rows, int cols)
{
	data.resize(rows, VectorDouble(cols, 0.0));
	rows = this->rows;
	columns = cols;
}

MLCVecMatrix::MLCVecMatrix()
{
	data.resize(1, VectorDouble(1, 0.0));
}

int MLCVecMatrix::getRows() const
{
	return rows;
}

int MLCVecMatrix::getColumns() const
{
	return columns;
}

double& MLCVecMatrix::operator()(int row, int col)
{
	return data[row][col];
}

bool MLCVecMatrix::insertRow(const VectorDouble& newRow)
{
	if (newRow.size() != columns) {
		return 0;
	}
	data.push_back(newRow);
	rows++;
	return 1;
}

bool MLCVecMatrix::insertRow(int position, const VectorDouble& newRow)
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

bool MLCVecMatrix::insertRow(int position, VectorDouble& newRow, bool hardInsert)
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

void MLCVecMatrix::insertRowEmptyRow()
{
	VectorDouble emptyRow(columns, 0.0);
	data.push_back(emptyRow);
	rows++;
}

bool MLCVecMatrix::fromCSV(const std::string& filename, MLCVecMatrix& matrix)
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
		
		while (std::getline(ss, cell, ',')) {

			try {
				row.push_back(std::stod(cell));  // Конвертируем строку в число
			}
			catch (const std::invalid_argument&) {
				row.push_back(0.0);  // В случае ошибки записываем 0.0
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

void MLCVecMatrix::setRows(int newRows)
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

void MLCVecMatrix::setColumns(int newCols)
{
	
	for (VectorDouble& row : data) {
		row.resize(newCols, 0.0);  
	}
	columns = newCols;  
}
