
#ifndef INC_3RDSEMESTER_SONGCOLLECTION_H
#define INC_3RDSEMESTER_SONGCOLLECTION_H

#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>

namespace sdds {

    struct Song {
        std::string m_artist;
        std::string m_title;
        std::string m_album;
        double m_price;
        int m_year;
        int m_length;
    };


    class SongCollection {

        /*struct Song {
            std::string m_artist;
            std::string m_title;
            std::string m_album;
            double m_price;
            int m_year;
            int m_length;
        };
    */

        std::vector<sdds::Song> m_songs;
        std::string& trim(std::string &str);

    public:
        SongCollection(std::string& str);
        void display(std::ostream& out) const;

    };
    std::ostream& operator<<(std::ostream& out, const Song& theSong);

}

#endif //INC_3RDSEMESTER_SONGCOLLECTION_H
