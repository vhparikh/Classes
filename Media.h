#include <iostream>
#include <cstring>

#ifndef MEDIA_H
#define MEDIA_H

using namespace std;

class Media {
public:
  Media();
  char* getTitle();
  int* getYear();
private:
  char title[100];
  int year;
};

#endif
