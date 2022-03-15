#include "Item.h"


size_t Item::m_widthField = 0;

Item::Item(const std::string& str) {

	Utilities m_util;
	size_t next_pos = 0;
	bool more = false;

	m_name = m_util.extractToken(str, next_pos, more);
	if (next_pos != std::string::npos)
	{
		std::string temp = m_util.extractToken(str, next_pos, more);
		m_serialNumber = stoi(temp);
	}

	if (next_pos != std::string::npos)
	{
		std::string temp = m_util.extractToken(str, next_pos, more);
		m_quantity = stoi(temp);
	}

	if (next_pos != std::string::npos)
	{
		m_description = m_util.extractToken(str, next_pos, more);
	}

	if (m_widthField < m_util.getFieldWidth()) {
		m_widthField = m_util.getFieldWidth();
	}
}

const std::string& Item::getName() const {
	return m_name;
}

const unsigned int Item::getSerialNumber() {
	unsigned int nextSerial = m_serialNumber;
	m_serialNumber++;
	return nextSerial;

}

const unsigned int Item::getQuantity() {
	return m_quantity;
}

void Item::updateQuantity() {
	if (m_quantity > 0) {
		m_quantity--;
	}
}

void Item::display(std::ostream& os, bool full) const {

	if (full) {
		os << std::setw(m_widthField) << std::setfill(' ') << std::left << m_name << " " << "[" << std::setfill('0') << std::right << std::setw(6) << m_serialNumber << "]"
			<< " " << "Quantity: " << std::setw(m_widthField) << std::setfill(' ') << std::left << m_quantity << " " << "Description: " << m_description;
	}
	else {
		os << std::setw(m_widthField) << std::setfill(' ') << std::left << m_name << " " << "[" << std::setfill('0') << std::right << std::setw(6) << m_serialNumber << "]";
	}
	os << std::endl;
}


