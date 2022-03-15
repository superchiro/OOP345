// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/11/24
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.



#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField;

/*CustomerOrder::CustomerOrder() {

    m_name = '\0';
    m_product = '\0';
    m_cntItem = 0u;
    m_lstItem = nullptr;
    m_widthField = 0u;

}*/

CustomerOrder::CustomerOrder(std::string &is){

    Utilities utility;
    size_t position = 0;
    bool more = false;
    std::vector<ItemInfo*> v_item;

   m_name = utility.extractToken(is, position, more);
   m_product = utility.extractToken(is, position, more);

   while(more) {
       v_item.push_back(new ItemInfo(utility.extractToken(is, position, more)));
   }

   m_cntItem = v_item.size();
   m_lstItem = new ItemInfo* [m_cntItem];

   for (size_t i = 0; i < m_cntItem; i++) {
       m_lstItem[i] = std::move(v_item[i]);
   }

   if (m_widthField < utility.getFieldWidth()) {
        m_widthField = utility.getFieldWidth();
   }

   // v_item.clear();
  //  v_item.shrink_to_fit();
}

CustomerOrder::CustomerOrder(const CustomerOrder&) {
    throw std::string("Cannot make copy");
}


CustomerOrder::CustomerOrder(CustomerOrder &&cust) noexcept {
    *this = std::move(cust);
}

CustomerOrder &CustomerOrder::operator=(CustomerOrder &&cust) noexcept {

    if(this != &cust) {
       // delete[] m_lstItem;
        m_name = cust.m_name;
        m_product = cust.m_product;
        m_cntItem = cust.m_cntItem;
        //m_widthField = cust.m_widthField;

        m_lstItem = cust.m_lstItem;

        cust.m_lstItem = nullptr;
        cust.m_product = '\0';
        cust.m_cntItem = 0;
        cust.m_name = '\0';

    }
    return *this;
}

CustomerOrder::~CustomerOrder() {
    for (size_t i = 0; i < m_cntItem; i++) {
        delete m_lstItem[i];
        m_lstItem[i] = nullptr;
    }

    delete [] m_lstItem;
    m_lstItem = nullptr;
}

bool CustomerOrder::getItemFillState(std::string str) const {
    bool more = false;
    for(size_t i = 0; i < m_cntItem; i++) {
        if(m_lstItem[i]->m_itemName == str && m_lstItem[i]->m_fillState) {
               more = true;
        }
    }
    return more;
}

bool CustomerOrder::getOrderFillState() const {
    int size = 0;
    for (size_t i = 0; i < m_cntItem; i++) {
        if(m_lstItem[i]->m_fillState) {
            size ++;
        }
    }
    if (size < m_cntItem) {
        return false;
    } else {
        return true;
    }
}


void CustomerOrder::fillItem(Item &item, std::ostream &os) {

    for(size_t i = 0; i < m_cntItem; i++) {
        if (item.getName() == m_lstItem[i]->m_itemName && item.getQuantity() > 0) {
            item.updateQuantity();
            m_lstItem[i]->m_serialNumber = item.getSerialNumber();
            m_lstItem[i]->m_fillState = true;

            os << "Filled " << m_name << "," << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;
        }
        if (item.getName() == m_lstItem[i]->m_itemName && item.getQuantity() == 0) {
            os << "Unable to fill" << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;
        }
    }


}

void CustomerOrder::display(std::ostream &os) const {
    os << m_name << " - " << m_product << std::endl;
    for (size_t i = 0; i < m_cntItem; i++) {
        os << "["  << std::setfill('0') << std::setw(6) << m_lstItem[i]->m_serialNumber << "] "
        << std::setw(m_widthField) << std::setfill(' ') << m_lstItem[i]->m_itemName << " - "
        << (getItemFillState(m_lstItem[i]->m_itemName) ? "Filled" : "Missing");
        os << std::endl;
    }

}
