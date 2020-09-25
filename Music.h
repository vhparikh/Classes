//Created by Vatsal Parikh
//Date 9/24/20
//header file for music class

//imports
#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Music : public Media { //music class extends media class
public: //public constructor and methods
  Music();
  char* getArtist();
  int* getDuration();
  char* getPublisher();
  virtual int getType();
private: //private variables
  char artist[100];
  int duration;
  char publisher[100];
};
