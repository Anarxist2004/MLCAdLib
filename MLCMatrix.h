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
	MLCMatrix(int rows, int cols) {
		data.resize(rows, VectorDouble(cols, 0.0));
		rows =this-> rows;
		columns = cols;
	}

	MLCMatrix() {
		data.resize(1, VectorDouble(1, 0.0));
	}

	int getRows() const {
		return rows;
	}

	int getColumns() const {
		return columns;
	}


	double& operator()(int row, int col) {
		return data[row][col];
	}

	bool insertRow(const VectorDouble& newRow) {
		if (newRow.size() != columns) {
			return 0;
		}
		data.push_back(newRow);
		rows++;  
		return 1;
	}

	bool insertRow(int position, const VectorDouble& newRow) {
		if (newRow.size() != columns) {
			return 0;
		}

		if (position < 0 || position > rows) {
			return 0;
		}

		data.insert(data.begin() + position, newRow);
		rows++; 
	}

	bool insertRow(int position, VectorDouble& newRow, bool hardInsert) {
		if (position < 0 || position > rows) {
			return 0;
		}

		if (!hardInsert) {
			return this->insertRow(position, newRow);
		}

		if (newRow.size() < columns) {
			newRow.resize(columns, 0.0);  
		}
		else{
			columns = newRow.size();  
			for (VectorDouble& row : data) {
				row.resize(columns, 0.0);  
			}
		}

		data.insert(data.begin() + position, newRow);
		rows++;

	}

	void insertRowEmptyRow() {
		VectorDouble emptyRow(columns, 0.0);
		data.push_back(emptyRow);
		rows++;
	}

	static MLCMatrix* fromCSV(const std::string& filename) {
		MLCMatrix matrix;
		std::ifstream file(filename);

		if (!file.is_open()) {
			
			return &matrix; 
		}

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
				matrix.columns = row.size();  
			}
			else if (row.size() != matrix.columns) {
				return &MLCMatrix();  
			}

			matrix.data.push_back(row);  
			matrix.rows++;
		}

		file.close();
		return &matrix;
	}
};