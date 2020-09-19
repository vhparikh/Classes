#include <iostream>
#include <cstring>
#include "Movie.h"

using namespace std;

Movie::Movie() {

}

char* Movie::getDirector() {
  return director;
}

int* Movie::getDuration() {
  return &duration;
}

float* Movie::getRating() {
  return &rating;
}
