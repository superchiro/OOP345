// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/11/24
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef INC_3RDSEMESTER_CUSTOMERORDER_H
#define INC_3RDSEMESTER_CUSTOMERORDER_H


#include <iostream>
#include <memory>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include "Utilities.h"
#include "Item.h"


struct ItemInfo
{
    std::string m_itemName;
    unsigned int m_serialNumber = 0;
    bool m_fillState = false;

    ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder{
    std::string m_name;
    std::string m_product;
    unsigned int m_cntItem;
    ItemInfo** m_lstItem = nullptr;
    static size_t m_widthField;

public:
    CustomerOrder() = default;
    CustomerOrder(std::string& is);
    CustomerOrder(const CustomerOrder&);
    CustomerOrder& operator=(const CustomerOrder&) = delete;
    CustomerOrder(CustomerOrder&& cust) noexcept ; //move constractor
    CustomerOrder& operator=(CustomerOrder&& cust) noexcept ; //move ope
    ~CustomerOrder();
    bool getItemFillState(std::string) const;
    bool getOrderFillState() const;
    void fillItem(Item& item, std::ostream& os);
    void display(std::ostream&) const;
};

#endif //INC_3RDSEMESTER_CUSTOMERORDER_H
