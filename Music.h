#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Music : public Media {
public:
  Music();
  char* getArtist();
  int* getDuration();
  char* getPublisher();
private:
  char artist[100];
  int duration;
  char publisher[100];
};
