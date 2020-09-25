//Created by Vatsal Parikh
//Date 9/24/20
//cpp file for music class

//imports
#include <iostream>
#include <cstring>
#include "Music.h"

using namespace std;

Music::Music() { //music constructor

}

char* Music::getArtist() { //returns pointer to artist
  return artist;
}

int* Music::getDuration() { //returns memory location of duration
  return &duration;
}

char* Music::getPublisher() { //returns pointer to publisher
  return publisher;
}

int Music::getType() { //returns type of object
  return 1;
}
