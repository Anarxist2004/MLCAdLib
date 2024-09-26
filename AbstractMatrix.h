#pragma once
#include "AbctractVector.h"
class AbctractMatrix {

public:
	AbctractMatrix(int rows, int cols);

	AbctractMatrix();

	virtual int getRows() const;

	virtual int getColumns() const;


	virtual double& operator()(int row, int col);

	virtual bool insertRow(const AbctractVector* data);

	virtual bool insertRow(int position, const AbctractVector* newRow);

	virtual bool insertRow(int position, AbctractVector* data, bool hardInsert);

	virtual void insertRowEmptyRow();

	//static bool fromCSV(const std::string& filename, MLCVecMatrix& matrix);

	virtual void setRows(int newRows);

	virtual void setColumns(int newCols);
};