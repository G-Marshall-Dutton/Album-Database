//
//  Collection.cpp
//  CW2_Album_database
//
//  Copyright © 2019 George Marshall-Dutton. All rights reserved.
//
//
#include "Collection.hpp"

using namespace std;



// DESTRUCTOR ------------------------
Collection::~Collection(){
    
    for(int i =0; i<albums.size(); i++){
        delete albums.at(i);
    }
    
    albums.clear();
}


// Sort
void Collection::sortCollection(){
    
    u_long n = albums.size();
    bool swapped;
  
    for (int i = 0; i< n-1; i++) {
        swapped = false;
        for (int j = 0; j < (n-1) -i; j++) {
            
            // If same artist
            if(*albums.at(j) == *albums.at(j+1)){
                // Compare titles
                if(albums.at(j)->getTitle() > albums.at(j+1)->getTitle()){
                    // Swap
                    Album* temp = albums.at(j);
                    albums.at(j) = albums.at(j+1);
                    albums.at(j+1) = temp;
                }
            }
            
            // If different artists
            else if(*albums.at(j) > *albums.at(j+1)){
                // Swap
                Album* temp = albums.at(j);
                albums.at(j) = albums.at(j+1);
                albums.at(j+1) = temp;
                
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }
}

// Get total play time
Duration Collection::getTotalPlayTime(string artist){
    
    int totalSeconds =0;
    
    for (int i =0; i<albums.size(); i++) {
        if(albums.at(i)->getArtist() == artist){
            for(int j =0; j < albums.at(i)->getTrackList().size(); j++){
                totalSeconds += int(albums.at(i)->getTrackList().at(j)->getDuration());
            }
        }
    }
    
    return Duration(totalSeconds);
}

// Get longest album
Album Collection::getLongestAlbum(){
    
    Album* mostTracks = albums.at(0);
    
    for (int i =1; i<albums.size(); i++) {
        if(albums.at(i)->getTrackList().size() > mostTracks->getTrackList().size()){
            mostTracks = albums.at(i);
        }
    }
    return Album(*mostTracks);
}

// Get longest Track
Track* Collection::getLongestTrack(){
    Track* longestTrack = albums.at(0)->getTrackList().at(0);

    for (Album* album : albums) {
        for (Track* track : album->getTrackList()) {
            if(*track > *longestTrack){
                longestTrack = track;
            }
        }
    }

    return longestTrack;
}

// OVERLOADED OPERATORS --------------
ostream& operator<<(ostream& os, const Collection& c){
    
    for (int i= 0; i<c.getAlbums().size(); i++) {
        os << *c.getAlbums().at(i);
    }
    
    return os;
}


istream& operator>>(istream& is, Collection& c) {

    while(!is.eof()){
        Album* album = new Album();

        if(is >> *album){
            c.addAlbum(album);
        }
        else{
            is.clear();
            return is;
        }
    }

    return is;
}
