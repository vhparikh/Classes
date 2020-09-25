//Created by Vatsal Parikh
//Date 9/24/20
//header file for Media class

//imports
#include <iostream>
#include <cstring>

//header guard
#ifndef MEDIA_H
#define MEDIA_H

using namespace std;

class Media {
public: //public methods and constructors
  Media();
  char* getTitle();
  int* getYear();
  virtual int getType();
private: //private variables
  char title[100];
  int year;
};

#endif
