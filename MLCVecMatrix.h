#pragma once


typedef std::vector<double> VectorDouble;

class MLCVecMatrix {
private:
	std::vector<VectorDouble> data;
	int rows =1;
	int columns=1;

public:
	MLCVecMatrix(int rows, int cols);

	MLCVecMatrix();

	int getRows() const;

	int getColumns() const;


	double& operator()(int row, int col);

	bool insertRow(const VectorDouble& newRow);

	bool insertRow(int position, const VectorDouble& newRow);

	bool insertRow(int position, VectorDouble& newRow, bool hardInsert);

	void insertRowEmptyRow();

	static bool fromCSV(const std::string& filename, MLCVecMatrix& matrix);

	void setRows(int newRows);

	void setColumns(int newCols);
};