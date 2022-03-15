#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iomanip>
#include <iostream>
#include "Utilities.h"

class Item {

	std::string m_name{};
	std::string m_description{};
	unsigned int m_serialNumber{};
	unsigned int m_quantity{};
	static size_t m_widthField;

public:
	Item(const std::string&);
	const std::string& getName() const;
	const unsigned int getSerialNumber();
	const unsigned int getQuantity();
	void updateQuantity();
	void display(std::ostream& os, bool full) const;

};



#endif // ITEM_H


