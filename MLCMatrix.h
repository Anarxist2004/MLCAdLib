#pragma once
#include <iostream>
#include <vector>
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

	bool insertRowEmptyRow() {
		VectorDouble emptyRow(columns, 0.0);
		data.push_back(emptyRow);
		rows++;
	}


};