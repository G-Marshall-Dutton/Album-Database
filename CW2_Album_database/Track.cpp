//
//  Track.cpp
//  CW2_Album_database
//
//  Copyright © 2019 George Marshall-Dutton. All rights reserved.
//

#include "Track.hpp"

using namespace std;

istream& operator>>(std::istream& is, Track& t){
    char delim;
    string title;
    Duration d;
    
    if(is >> d >> delim ){
        if (delim == '-')
        {
            getline(is, title);
            
            // Remove white space
            if(title.at(0) == ' '){
                title.erase(0, 1);
            }
            
            t = Track(title, d);
        }
        else
        {
            cout << "Track format is incorrect" << endl;
            is.clear(ios_base::failbit);
        }
    }
    return is;
}


