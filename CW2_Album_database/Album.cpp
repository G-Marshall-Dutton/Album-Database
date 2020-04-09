//
//  Album.cpp
//  CW2_Album_database
//
//  Copyright © 2019 George Marshall-Dutton. All rights reserved.
//

#include "Album.hpp"

using namespace std;

// Add Track
void Album::addTrack(Track* track){
    trackList.push_back(track);
}

// DESTRUCTOR ------------------------
Album::~Album(){
    
    for(Track* track : trackList){
        delete track;
    }
    
    trackList.clear();
}

// COPY CONSTRUCTOR ------------------
Album::Album(const Album& album) {
    
    // Copy artist and title ---
    title = album.title;
    artist = album.artist;
    
    
    //Copy tracklist ---
    // Allocate memory for deep copy
    trackList = vector<Track*>();
    
    // Make deep copy
    for(Track* track : album.trackList){
        Track* t = new Track(*track);
        trackList.push_back(t);
    }
}



// 
ostream& operator<<(std::ostream& os, const Album& a){
    os << a.getArtist() << ":"<< a.getTitle() << endl;
    
    for (int i =0; i<a.getTrackList().size(); i++) {
        os << *a.getTrackList().at(i);
    }
    
    os << endl;
    return os;
}


istream& operator>>(std::istream& is, Album& a){
    // artist, : ,title, each track;
    char artist[256];
    char title[256];

    is.getline(artist, 256, ':');
    a.setArtist(artist);

    is.getline(title,  256);
    a.setTitle(title);
    
    while(!is.eof()){
        Track* track = new Track();
        
        if(is >> *track){
            a.addTrack(track);
        }
        else{
            is.clear();
            return is;
        }
    }
    
    return is;
}
