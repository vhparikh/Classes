//Created by Vatsal Parikh
//Date 9/24/20
//cpp file for media class

//imports
#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

Media::Media() { //constructor

}

char* Media::getTitle() { //returns title pointer
  return title;
}

int* Media::getYear() { //returns address of year
  return &year;
}

int Media::getType() { //returns type of file
  return -1;
}
