#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Game : public Media {
public:
  Game();
  char* getPublisher();
  float* getRating();
private:
  char publisher[100];
  float rating;
};
