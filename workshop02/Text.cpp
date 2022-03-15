// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/09/23
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Text.h"


namespace sdds {


    Text::Text() {
        S = nullptr;
        track = 0;
    }

    Text::Text(const std::string file) {
        std::ifstream f(file.c_str());
        S = nullptr;
        track = 0;
        if(!f) {
            return;
        }

        do {
            char c = f.get();
            if (c == ' ') {
                track++;
            }
        } while(!f.eof());

        f.seekg(std::ios::beg);
        S = new std::string[track];
        for(size_t i = 0; i < track; i++) {
            std::getline(f, S[i], ' ');
        }
    }

    Text::Text(const Text& text) {

        track = text.track;
        if(text.S != nullptr) {
            S = new std::string[track];

            for(int i = 0; i < track; i++) {
                S[i] = text.S[i];
            }
        } else {
            S = nullptr;
        }
    }

    Text &Text::operator=(const Text& text) {

        if (this != &text) {
            delete [] S;
            track = text.track;
            S = new std::string[track];

            for(int i = 0; i < track; i++) {
                S[i] = text.S[i];
            }

        } else {
            S = nullptr;
        }

        return *this;
    }

    Text::~Text() {
        delete [] S;
        S = nullptr;
    }

    size_t Text::size() const {
        return track;
    }


}