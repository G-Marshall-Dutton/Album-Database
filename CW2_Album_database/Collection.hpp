//
//  Collection.hpp
//  CW2_Album_database
//
//  Copyright © 2019 George Marshall-Dutton. All rights reserved.
//

#ifndef Collection_hpp
#define Collection_hpp

#include <stdio.h>
#include <vector>
#include "Album.hpp"

class Collection{
private:
    
    vector<Album*> albums;
    
public:
    

    Collection();
    Collection(vector<Album*> albums);
    ~Collection();
    
    vector<Album*> getAlbums() const;
    
    void addAlbum(Album* a);
    
    // Task 2
    void sortCollection();
    
    // Task 3
    Duration getTotalPlayTime(string artist);
    
    // Task 4
    Album getLongestAlbum();
    
    // Task 5
    Track* getLongestTrack();

};

// CONSTRUCTORS -------------------
inline Collection::Collection(){}

inline Collection::Collection(vector<Album*> a){
    albums = a;
}


// GETTERS -----------------------
inline vector<Album*> Collection::getAlbums() const{
    return albums;
}

// Add album
inline void Collection::addAlbum(Album* a){
    albums.push_back(a);
}


// OVERLOADED OPERATORS ----------
// os << Collection
std::ostream& operator<<(std::ostream& os, const Collection& c);

// is >> Collection
std::istream& operator>>(std::istream& is, Collection& c);

#endif /* Collection_hpp */
