#pragma once
class AbctractVector {
public:



	virtual int size() const = 0;

	virtual double& getElement(int index) = 0;

	virtual bool insert(int index,const double) = 0;

	virtual void pushBack(const double) = 0;

	virtual bool insertVector(int index,  AbctractVector*)=0;

private:
	//virtual void setColumns(const int newAmmountCol)=0;

	virtual void resize(int newCapacity) = 0;
};