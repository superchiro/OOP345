

#include "SongCollection.h"
#include "../at_home/SongCollection.h"


void printbar(std::ostream& out = std::cout);

namespace sdds {

    std::string& SongCollection::trim(std::string &str) {

        while(str.length() > 0 && str[0] == ' ') {
            str.erase(0, 1);
        }
        while (str.length() > 0 && str[str.length() - 1] == ' ') {
            str.erase(str.length() - 1, 1);
        }
        return str;
    }


    SongCollection::SongCollection(std::string &str) {

        std::ifstream file(str);
        if (!file) {
            throw "Can not read file";
        }

            while(file) {

                std::string copy;
                std::getline(file, copy);
                Song song;

                if (file) {
                    trim(song.m_title = copy.substr(0, 25));
                    trim(song.m_artist = copy.substr(25, 25));
                    trim(song.m_album = copy.substr(50, 25));

                    try {
                        song.m_year = std::stoi(copy.substr(75, 5));
                    }
                    catch (...)
                    {
                        song.m_year = 0;
                    }
                    song.m_length = std::stoi(copy.substr(80, 5));
                    song.m_price = std::stod(copy.substr(85, 5));

                    m_songs.push_back(song);
                }
            }
            file.close();
    }

    void SongCollection::display(std::ostream &out) const {

        for_each(m_songs.begin(), m_songs.end(), [&out] (const Song& item) {out << item << std::endl;});
        auto totalTime = std::accumulate(m_songs.begin(), m_songs.end(), 0u, [] (const size_t& res, const Song item) {return res + item.m_length;});
        printbar (out);

        std::string str = "Total Listening Time: ";
        str += std::to_string(totalTime/3600);
        str += ":";
        str += std::to_string((totalTime %= 3600) / 60);
        str += ":";
        str += std::to_string(totalTime % 60);
        out << "| " << std::setw(84) << str << " |" << std::endl;

    }

    std::ostream &operator<<(std::ostream &out, const Song &theSong) {

        out << "| " << std::setw(20) << theSong.m_title
            << " | " << std::setw(15) << theSong.m_artist
            << " | " << std::setw(20) << theSong.m_album
            << " | " << std::setw(6) << theSong.m_year
            << " | " << theSong.m_length
            << " | " << theSong.m_price << " | " << std::endl;
        return out;

    }

}