#include <iostream>
#include <cstring>
#include "Music.h"

using namespace std;

Music::Music() {

}

char* Music::getArtist() {
  return artist;
}

int* Music::getDuration() {
  return &duration;
}

char* Music::getPublisher() {
  return publisher;
}
