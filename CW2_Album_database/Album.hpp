//
//  Album.hpp
//  CW2_Album_database
//
//  Copyright © 2019 George Marshall-Dutton. All rights reserved.
//

#ifndef Album_hpp
#define Album_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Track.hpp"

using namespace std;

class Album{
private:
    
    string title;
    string artist;
    vector<Track*> trackList;
    
public:
    
    Album();
    Album(const Album& album);
    Album(string title, string artist, vector<Track*> trackList);
    ~Album();
    
    string getTitle() const;
    string getArtist() const;
    void setTitle(char t[256]);
    void setArtist(char a[256]);
    vector<Track*> getTrackList() const;
    operator int();
    
    void addTrack(Track* track);
    
    Album& operator=(const Album &album);
};


// CONSTRUCTORS ----------------------
inline Album::Album(){
    this->title = "Unknown";
    this->artist = "Unknown";
}

inline Album::Album(string title, string artist, vector<Track*> trackList){
    this->title = title;
    this->artist = artist;
    this->trackList = trackList;
}


// ACCESSOR METHODS ------------------
inline string Album::getTitle() const{
    return title;
}

inline string Album::getArtist() const{
    return artist;
}

inline vector<Track*> Album::getTrackList() const{
    return trackList;
}

// SETTERS ---------------------------
inline void Album::setTitle(char t[256]){
    title = t;
}

inline void Album::setArtist(char a[256]){
    artist = a;
}

// OVERLOADED OPERATORS ---------------
// Album > Album
inline bool operator>(const Album& a1, const Album& a2){
    return a1.getArtist() > a2.getArtist();
}

// Album < Album
inline bool operator<(const Album& a1, const Album& a2){
    return a1.getArtist() < a2.getArtist();
}

// Album == Album
inline bool operator==(const Album& a1, const Album& a2){
    return a1.getArtist() == a2.getArtist();
}

// COPY ASSIGNMENT OPERATOR ----------
inline Album& Album::operator=(const Album &album) {
    
    // Check for self assignment
    if(this != &album){
        
        // Copy artist and title
        title = album.title;
        artist = album.artist;
        
        // Copy tracklist
        // Allocate memory for deep copy
        vector<Track*> tracks;
        string title;
        Duration duration;
        
        for (int i =0; i<album.trackList.size(); i++) {
            
            title = album.trackList.at(i)->getTitle();
            duration = album.trackList.at(i)->getDuration();
            
            tracks.push_back(new Track(title, duration));
        }
        
        // Replace tracklist 
        trackList.clear();
        trackList = tracks;
    }
    
    return *this;
}

// os << Album
std::ostream& operator<<(std::ostream& os, const Album& a);

// is >> Album
std::istream& operator>>(std::istream& is, Album& a);

#endif /* Album_hpp */
