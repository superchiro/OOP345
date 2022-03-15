// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/12/01
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.



#pragma once
#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H
#include "Utilities.h"
#include "Item.h"
#include <memory>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <iomanip>
#include <string>

struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder {
	std::string m_name{};
	std::string m_product{};
	unsigned int m_cntItem{};
	ItemInfo** m_lstItem = nullptr;
	static size_t m_widthField;


public:
	CustomerOrder() = default;
	CustomerOrder(std::string&);
	CustomerOrder(const CustomerOrder&);

	CustomerOrder& operator = (const CustomerOrder&) = delete;
	CustomerOrder(CustomerOrder&&) noexcept;
	CustomerOrder& operator=(CustomerOrder&&) noexcept;

	~CustomerOrder();
	bool getItemFillState(std::string) const;
	bool getOrderFillState() const;
	void fillItem(Item& item, std::ostream&);
	void display(std::ostream&) const;
};


#endif // CUSTOMERORDER_H
