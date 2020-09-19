#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Movie : public Media {
public:
  Movie();
  char* getDirector();
  int* getDuration();
  float* getRating();
private:
  char director[100];
  int duration;
  float rating;
};
