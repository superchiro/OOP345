#include "CustomerOrder.h"


size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder(std::string& str) {
    Utilities m_util;
    size_t next_pos = 0;
    bool more = false;
    std::vector<ItemInfo*> itemVec;

    m_name = m_util.extractToken(str, next_pos, more);

    m_product = m_util.extractToken(str, next_pos, more);

    while (more)
    {
        itemVec.push_back(new ItemInfo(m_util.extractToken(str, next_pos, more)));
    }

    m_cntItem = itemVec.size();


    m_lstItem = new ItemInfo* [m_cntItem];


    for (size_t i = 0; i < m_cntItem; i++)
    {
        m_lstItem[i] = std::move(itemVec[i]);
    }

    if (m_widthField < m_util.getFieldWidth()) {
        m_widthField = m_util.getFieldWidth();
    }


    itemVec.clear();
    itemVec.shrink_to_fit();
}

CustomerOrder::CustomerOrder(const CustomerOrder&) {
    throw std::string("Error: Cannot make copies");
}

CustomerOrder::CustomerOrder(CustomerOrder&& obj) noexcept {
    *this = std::move(obj);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& obj) noexcept {

    if (this != &obj) {
        delete[] m_lstItem;
        m_lstItem = obj.m_lstItem;
        m_name = obj.m_name;
        m_product = obj.m_product;
        m_cntItem = obj.m_cntItem;

        obj.m_lstItem = nullptr;
        obj.m_name = '\0';
        obj.m_product = '\0';
        obj.m_cntItem = 0;
    }

    return *this;
}

CustomerOrder::~CustomerOrder() {
    for (size_t i = 0; i < m_cntItem; i++) {
        delete m_lstItem[i];
        m_lstItem[i] = nullptr;
    }
    delete[] m_lstItem;
    m_lstItem = nullptr;
}
bool CustomerOrder::getItemFillState(std::string str) const {
    bool filled = false;
    for (size_t i = 0; i < m_cntItem; i++) {
        if (m_lstItem[i]->m_itemName == str && !m_lstItem[i]->m_fillState) {
            return false;
        }
    }
    return true;

}

bool CustomerOrder::getOrderFillState() const {
    bool filled = false;
    unsigned int cnt = 0;
    for (size_t i = 0; i < m_cntItem; i++) {
        if (m_lstItem[i]->m_fillState) {
            cnt++;
        }
    }
    if (cnt == m_cntItem) {
        filled = true;
    }
    return filled;
}

void CustomerOrder::fillItem(Item& item, std::ostream& os) {
    for (size_t i = 0; i < m_cntItem; i++) {
        if (m_lstItem[i]->m_itemName == item.getName() && item.getQuantity() >= 1) {
            item.updateQuantity();
            m_lstItem[i]->m_serialNumber = item.getSerialNumber();
            m_lstItem[i]->m_fillState = true;
            os << "Filled " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;
        }
        if (m_lstItem[i]->m_itemName == item.getName() && item.getQuantity() == 0) {
            os << "Unable to fill " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;
        }
    }
}

void CustomerOrder::display(std::ostream& os) const {

    os << m_name << " - " << m_product << std::endl;
    for (size_t i = 0; i < m_cntItem; ++i) {
        os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "]" << " ";
        os << std::setw(m_widthField) << std::setfill(' ') << m_lstItem[i]->m_itemName << " - " << (getItemFillState(m_lstItem[i]->m_itemName) ? "Filled" : "Missing");
        os << std::endl;
    }
}








