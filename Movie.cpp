//Created by Vatsal Parikh
//Date 9/24/20
//cpp file for movie class

//imports
#include <iostream>
#include <cstring>
#include "Movie.h"

using namespace std;

Movie::Movie() { //constructor for movie

}

char* Movie::getDirector() { //returns pointer to director
  return director;
}

int* Movie::getDuration() { //returns memory location of duration
  return &duration;
}

float* Movie::getRating() { //returns memory location of rating
  return &rating;
}

int Movie::getType() { //returns type of object
  return 2;
}
