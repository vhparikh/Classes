//Created by Vatsal Parikh
//Date 9/24/20
//header file for movie class

//imports
#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Movie : public Media { //movie class extends media class
public: //public constructor and methods
  Movie();
  char* getDirector();
  int* getDuration();
  float* getRating();
  virtual int getType();
private: //private variables
  char director[100];
  int duration;
  float rating;
};
