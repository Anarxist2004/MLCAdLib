#include "pch.h"
#include "MLCToolsVector.h"

bool MLCToolsVector::readVectorCSV(std::stringstream& ss, AbctractVector* row)
{
	std::string cell;

	while (std::getline(ss, cell, ',')) {

		try {
			row->pushBack(std::stod(cell));  // ������������ ������ � �����
		}
		catch (const std::invalid_argument&) {
			row->pushBack(0.0);  // � ������ ������ ���������� 0.0
		}
		catch (const std::out_of_range&) {
			row->pushBack(0.0);
		}
	}


    return 1;
}
