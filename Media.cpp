#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

Media::Media() {

}

char* Media::getTitle() {
  return title;
}

int* Media::getYear() {
  return &year;
}
