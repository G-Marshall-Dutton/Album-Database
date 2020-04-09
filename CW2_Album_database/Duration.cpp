//
//  Duration.cpp
//  CW2_Album_database
//
//  Copyright © 2019 George Marshall-Dutton. All rights reserved.
//

#include "Duration.hpp"

using namespace std;

Duration::operator int() const {
    int totalSecs = hours*60*60;
    totalSecs += minutes*60;
    totalSecs += seconds;
    
    return totalSecs;
}

istream& operator>>(istream& is, Duration& d){
    char c1, c2;
    int hrs, mins, secs;
    
    if(is >> hrs >> c1 >> mins >> c2 >> secs){
        if (c1 == ':' && c2 == ':')
        {
            d = Duration(hrs, mins, secs);
        }
        else
        {
            cout << "Duration format is incorrect" << endl;
            is.clear(ios_base::failbit);
        }
    }
    return is;
}
