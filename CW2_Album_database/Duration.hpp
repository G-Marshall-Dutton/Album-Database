//
//  Duration.hpp
//  CW2_Album_database
//
//  Copyright © 2019 George Marshall-Dutton. All rights reserved.
//

#ifndef Duration_hpp
#define Duration_hpp

#include <stdio.h>
#include <iomanip>
#include <ostream>
#include <iostream>

class Duration{
private:
    
   int hours, minutes, seconds;
    
public:
    Duration();
    Duration(int seconds);
    Duration(int hrs, int mins, int secs);
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    operator int() const;
};


// CONSTRUCTORS ----------------------
inline Duration::Duration(){

    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
}

inline Duration::Duration(int totalSeconds){
    this->hours = totalSeconds / 3600;
    totalSeconds %= 3600;
    this->minutes = totalSeconds / 60;
    totalSeconds %= 60;
    this->seconds = totalSeconds;
}

inline Duration::Duration(int hrs, int mins, int secs){
    
    // ADD ERROR CHECKING (values cant be < 0)
    
    // Convert to totalSeconds
    int totalSeconds = hrs * 3600;
    totalSeconds += mins * 60;
    totalSeconds += secs;
    
    
    *this = Duration(totalSeconds);
}


// ACCESSOR METHODS ------------------
inline int Duration::getHours() const{
    return hours;
}

inline int Duration::getMinutes() const{
    return minutes;
}

inline int Duration::getSeconds() const{
    return seconds;
}


// OVERLOADED OPERATORS ---------------
// Duration - Duration
inline int operator-(const Duration& d1, const Duration& d2){
    return static_cast<int>(d1) - static_cast<int>(d2);
}

// Duration + Duration
inline int operator+(const Duration& d1, const Duration d2){
    return static_cast<int>(d1) + static_cast<int>(d2);
}

// Duration += Duration
inline void  operator+=(Duration& d1, const Duration d2){
    d1 = Duration(static_cast<int>(d1) + static_cast<int>(d2));
}

// Duration += Duration
inline void  operator-=(Duration& d1, const Duration d2){
    d1 = Duration(static_cast<int>(d1) - static_cast<int>(d2));
}

// Duration > Duration
inline bool operator>(const Duration& d1, const Duration& d2){
    return static_cast<int>(d1) > static_cast<int>(d2);
}

// Duration < Duration
inline bool operator<(const Duration& d1, const Duration& d2){
    return static_cast<int>(d1) < static_cast<int>(d2);
}

// Duration == Duration
inline bool operator==(const Duration& d1, const Duration& d2){
    return static_cast<int>(d1) == static_cast<int>(d2);
}

// Duration != Duration
inline bool operator!=(const Duration& d1, const Duration& d2){
    return !(d1==d2);
}

// Duration >= Duration
inline bool operator>=(const Duration& d1, const Duration& d2){
    return !(d1<d2);
}

// Duration <= Duration
inline bool operator<=(const Duration& d1, const Duration& d2){
    return !(d1>d2);
}

// os << Duration
inline std::ostream& operator<<(std::ostream& os, const Duration& d){
    return os << std::setfill('0')
              << std::setw(1)<< d.getHours()    << ':'
              << std::setw(2) << d.getMinutes() << ':'
              << std::setw(2) << d.getSeconds() ;
}

// is >> Duration
std::istream& operator>>(std::istream& is, Duration& d);

#endif /* Duration_hpp */
