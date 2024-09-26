#include "pch.h"
#include "MLCVector.h"

void MLCVector::resize(int newCapacity)
{
	if (newCapacity <= capacity) return;

	double* newData = new double[newCapacity];
	for (int i = 0; i < size; i++) {
		newData[i] = vec[i];
	}

	delete[] vec;

	vec = newData;
	capacity = newCapacity;
}



MLCVector::MLCVector(int index)
{
	vec = new double[index];
	size = index;
	capacity = index;
}

MLCVector::MLCVector()
{
	vec = new double[0];
}

MLCVector::~MLCVector()
{
	delete vec;
}

double& MLCVector::getElement(int index)
{
	return vec[index];
}

bool MLCVector::insert(int index, const double element)
{
	if (index < 0|| index>size+1) {
		return 0;
	}
	if (size + 1 < capacity) {
		this->resize((size + 1) * 2);
	}

	for (int i = index; i < size; i++) {
		vec[i + 1] = vec[i];
	}
	vec[index] = element;
	size++;

	return 1;
}

void MLCVector::pushBack(const double element)
{
	if (size == capacity) {
		resize(capacity*2);
	}

	vec[size] = element;
	size++;
}

bool MLCVector::insertVector(int index,  AbctractVector* newveñ)
{
	if (index < 0 || index>size + 1) {
		return 0;
	}

	while(size+ newveñ->size() >= capacity) {
		resize((capacity+1) * 2);
	}

	for (int i = index; i < size + newveñ->size(); i++) {
		vec[i+index] = vec[i];

	}

	for (int i = 0; i < newveñ->size(); i++) {
		vec[i + index] = newveñ->getElement(i);
	}

	size += newveñ->size();
	return 1;

}
