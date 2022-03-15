// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/12/01
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.



#include "CustomerOrder.h"


size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder(std::string& str) {
	Utilities m_util;
	size_t next_pos = 0;
	bool more = false;
	std::vector<ItemInfo*> itemVector;

	m_name = m_util.extractToken(str, next_pos, more);

	m_product = m_util.extractToken(str, next_pos, more);
	
	while (more)
	{
			itemVector.push_back(new ItemInfo(m_util.extractToken(str, next_pos, more)));
	}
	
	m_cntItem = itemVector.size();


	m_lstItem = new ItemInfo* [m_cntItem];


	for (size_t i = 0; i < m_cntItem; i++)
	{
		m_lstItem[i] = std::move(itemVector[i]);
	}

	if (m_widthField < m_util.getFieldWidth()) {
		m_widthField = m_util.getFieldWidth();
	}
}

CustomerOrder::CustomerOrder(const CustomerOrder&) {
	throw std::string("Error: Cannot make copies");
}

CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
	*this = std::move(src);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {

	if (this != &src) {
		delete[] m_lstItem;
		m_lstItem = src.m_lstItem;
		m_name = src.m_name;
		m_product = src.m_product;
		m_cntItem = src.m_cntItem;

		src.m_lstItem = nullptr;
		src.m_name = '\0';
		src.m_product = '\0';
		src.m_cntItem = 0;
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
		os << "[" << std::setfill('0') << std::right << std::setw(6)  <<  m_lstItem[i]->m_serialNumber << "]" << " ";
		os << std::setw(m_widthField) << std::setfill(' ') << m_lstItem[i]->m_itemName << " - " << (getItemFillState(m_lstItem[i]->m_itemName) ? "Filled" : "Missing");
		os << std::endl;
	}
}








