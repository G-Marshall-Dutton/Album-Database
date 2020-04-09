//
//  main.cpp
//  CW2_Album_database
//
//  Copyright © 2019 George Marshall-Dutton. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Duration.hpp"
#include "Track.hpp"
#include "Album.hpp"
#include "Collection.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
//
//    Duration d1 = Duration(0,0,180);
//    Duration d2 = Duration(150);
//    cout << "d1: " << d1 << endl;
//    cout << "d2: " << d2 << endl;
//
//    Duration d5;
//    d5 = d1+d2;
//    cout << "d5: " << d5 << endl;
//
//    d5 = d5 + d2;
//    cout << "d5: " << d5 << endl;
//
//    cout << d1 + d2 << endl;
//
//
//    if(d2!=d1){
//        cout << "d2 is not equal to d1" << endl;
//    }
//    else{
//        cout << "d2 is equal to d1" << endl;
//    }
//
//
//    cout << endl;
//
//    int n;
//    //cout << "please enter a number" << endl;
//
//    //cin >> n;
//
//    //cout << n << endl;
//
////    Duration d3;
////    cin >> d3;
////
////    cout << d3;
////    cout << d1 << endl;
//    Track t1 = Track("Track a", d1);
//    Track t2 = Track("Track z", d1);
////    cout << t1;
//
//    cout << "Enter track" << endl;
//    Track t3;
//    cin >> t3;
//
//    cout << t3;
//
//    Album a1 = Album();
//    cout << a1.getTitle() << endl;
//    cout << a1.getTrackList().size() << endl;
//
//    string a = "aa";
//    string b = "ab";
//    string z = "zz";
//
//    if(t1 > t2){
//        cout << "t1 > t2" << endl;
//    }
//    else{
//        cout << "t1 < t2" << endl;
//    }
    
    Duration d1(100);
    Duration d2(20);
    
    
    Album album1;
    Collection collection;
    string test;
    ifstream f("/Users/georgemarshall-dutton/Desktop/UNI/Year 2 /Programming2/CW2_Album_database/CW2_Album_database/albums.txt");


    f >> collection;
    
    //Album* a1 = collection.getAlbums().at(0);
   // cout << *a1;
    
    collection.sortCollection();
    
    cout << collection << endl;
    
    cout << collection.getTotalPlayTime("Pink Floyd ") << endl;
    cout << collection.getLongestAlbum().getArtist()
         << " : "
         << collection.getLongestAlbum().getTitle()
         <<endl;
    
   cout << *collection.getLongestTrack() << endl;
    
//    Track t1("1", Duration(120));
//    Track t2("2", Duration(60));
//    
//    cout<< (t1 > t2) << endl;
}
