//Created by Vatsal Parikh
//Date 9/24/20
//Header for Game class

//imports
#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Game : public Media { //Game class extends Media
public: //Public constructor and methods
  Game();
  char* getPublisher();
  float* getRating();
  virtual int getType();
private: //private variables
  char publisher[100];
  float rating;
};
