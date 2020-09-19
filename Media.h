#include <iostream>
#include <cstring>

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
