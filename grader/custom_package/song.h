#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "priority_queue.h"

using namespace std;

class Song {
  public:
    std::string artist,title;
    int count;

    Song() { }
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) { }
    Song(std::string artist,std::string title,int count) :  artist(artist), title(title), count(count) { }

    friend std::ostream& operator<<(std::ostream &out,const Song &s) {
      return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }

};


//  you have to write something below this line 
//  you *MIGHT* have to change the declaration of pq1 and pq2
class comp1{
public:
  bool operator()(const Song & l, const Song & r ){
    if(l.artist ==  r.artist) {
      return l.title > r.title;
    } else return l.artist > r.artist;
  }
};
class comp2{
public:
  bool operator()(const Song & l, const Song & r ){
    if(l.count == r.count){
      if(l.artist ==  r.artist) {
        return l.title > r.title;
      } else return l.artist > r.artist;
    }else return l.count < r.count;
  }
};
comp1 a;
comp2 b;
CP::priority_queue<Song,comp1> pq1(a);
CP::priority_queue<Song,comp2> pq2(b);

#endif
