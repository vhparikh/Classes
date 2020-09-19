#include <iostream>
#include <cstring>
#include "Game.h"

using namespace std;

Game::Game() {

}

char* Game::getPublisher() {
  return publisher;
}

float* Game::getRating() {
  return &rating;
}
