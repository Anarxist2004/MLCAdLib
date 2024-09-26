#pragma once
class MLCDinMatrix {
	double** data;
public:
	MLCDinMatrix(int rows, int cols);

	MLCDinMatrix();

	virtual int getRows() const;

	virtual int getColumns() const;


	virtual double& operator()(int row, int col);

	virtual bool insertRow(const double* data);

	virtual bool insertRow(int position, const double* newRow);

	virtual bool insertRow(int position, double* data, bool hardInsert);

	virtual void insertRowEmptyRow();

	//static bool fromCSV(const std::string& filename, MLCVecMatrix& matrix);

	virtual void setRows(int newRows) ;

	virtual void setColumns(int newCols);
};