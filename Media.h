#include <iostream>
#include <cstring>

using namespace std;

class Media {
public:
  Media();
  void setTitle(char newTitle[100]);
private:
  char title[100];
}
