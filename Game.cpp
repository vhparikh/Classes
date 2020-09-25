//Created by Vatsal Parikh
//Date 9/24/20
//cpp file for game class

//imports
#include <iostream>
#include <cstring>
#include "Game.h"

using namespace std;

Game::Game() { //constructor

}

char* Game::getPublisher() { //returns pointer to publisher
  return publisher;
}

float* Game::getRating() { //returns memory location rating
  return &rating;
}

int Game::getType() { //returns type of object
  return 0;
}
