#pragma once
#include <iostream>
#include <vector>
class MLCMatrix {
private:
	std::vector<std::vector<double>> data;
	int string=0;
	int column=0;
	MLCMatrix(int rows, int cols) {
		data.resize(rows, std::vector<double>(cols, 0.0));
	}


};