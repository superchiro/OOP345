#include "Utilities.h"


char Utilities::m_delimiter;
size_t Utilities::m_widthField = 1;

void Utilities::setFieldWidth(size_t fWidth) {
    m_widthField = fWidth;
}

size_t Utilities::getFieldWidth() const {
    return m_widthField;
}

const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

    std::string token = str.substr(next_pos);
    size_t pos = token.find(m_delimiter);
    if (pos != std::string::npos) {
        token = token.substr(0, pos);

        if (m_widthField < token.length()) {
            setFieldWidth(token.length());
        }
        next_pos += pos + 1;
        more = true;
    }
    else {
        if (token[token.length()-1] == '\r')
            token = token.substr(0, token.length()-1);
        more = false;
    }


    return token;
}


void Utilities::setDelimiter(const char delim) {
    m_delimiter = delim;
}

const char Utilities::getDelimiter() const {
    return m_delimiter;
}



