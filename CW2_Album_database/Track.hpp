//
//  Track.hpp
//  CW2_Album_database
//
//  Copyright © 2019 George Marshall-Dutton. All rights reserved.
//

#ifndef Track_hpp
#define Track_hpp

#include <stdio.h>
#include <string>
#include "Duration.hpp"

using namespace std;

class Track{
private:
    
    string title;
    Duration d;
    
public:
    Track();
    Track(string title, Duration d);
    string getTitle() const;
    Duration getDuration() const;
    operator int() const;
};


// CONSTRUCTORS ------------------
inline Track::Track(){
    this->title = "Unknown";
    this->d = Duration();
}

inline Track::Track(string title, Duration d){
    this->title = title;
    this->d = d;
}


// ACCESSOR METHODS --------------
inline string Track::getTitle() const{
    return title;
}

inline Duration Track::getDuration() const{
    return d;
}


// OVERLOADED OPERATORS ----------
// Track > Track
inline bool operator>(const Track& t1, const Track& t2){
    return t1.getDuration() > t2.getDuration();
}

// Track < Track
inline bool operator<(const Track& t1, const Track& t2){
    return t1.getDuration() < t2.getDuration();
}

// Track == Track
inline bool operator==(const Track& t1, const Track& t2){
    return (t1.getTitle() == t2.getTitle() && t1.getDuration() == t2.getDuration());
}

// Track != Track
inline bool operator!=(const Track& t1, const Track& t2){
    return !(t1==t2);
}

// Track >= Track
inline bool operator>=(const Track& t1, const Track& t2){
    return !(t1<t2);
}

// Track <= Track
inline bool operator<=(const Track& t1, const Track& t2){
    return !(t1>t2);
}

// os << Track
inline std::ostream& operator<<(std::ostream& os, Track& t){
    return os << t.getDuration()    << " - "
              << t.getTitle() << endl;
}

// is >> Track
std::istream& operator>>(std::istream& is, Track& t);
#endif /* Track_hpp */
