#pragma once
#include "AbctractVector.h"
class MLCVector : public AbctractVector {
private:
	double* vec;
	int size=0;
	int capacity=0;

	virtual void resize(int newCapacity) override;

	//virtual void setColumns(int newAmmountCol) override;
public:
	MLCVector(int index);
	
	MLCVector();
	~MLCVector();
	virtual double& getElement(int index) override;

	virtual bool insert(int index, const double) override;

	virtual void pushBack(const double) override;

	virtual bool insertVector(int index,  AbctractVector*) override;
};
