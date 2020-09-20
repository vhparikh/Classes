#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <iterator>
#include "Game.h"
#include "Music.h"
#include "Movie.h"

using namespace std;

void ADD(vector<Media*>* vec);
void SEARCH(vector<Media*>* vec);
void DELETE(vector<Media*>* vec);

int main()
{

  vector<Media*> media;
  bool quit = false;
  char input[10];
  
  while (quit == false) {
    cin >> input;
    
    if (strcmp(input, "ADD") == 0 || strcmp(input, "add") == 0) {
      ADD(&media);
      //cout << *media.at(0)->getYear() << endl;
    }
    else if (strcmp(input, "SEARCH") == 0 || strcmp(input, "search") == 0) {
      SEARCH(&media);
    }
    else if (strcmp(input, "DELETE") == 0 || strcmp(input, "delete") == 0) {
      DELETE(&media);
    }
    else if (strcmp(input, "QUIT") == 0 || strcmp(input, "quit") == 0) {
      quit = true;
    }
    else {
      cout << "An invalid command was entered" << endl;
    }
  }
}
   
void ADD(vector<Media*>* vec)
{
  char input[10];
  cout << "Would you like to add a GAME, MUSIC or a MOVIE?" << endl;
  cin >> input;
  
  if (strcmp(input, "GAME") == 0 || strcmp(input, "game") == 0) {
    Game* game = new Game();
    cout << "Game Title:" << endl;
    cin >> game->getTitle();
    cout << "Game Year:" << endl;
    cin >> *game->getYear();
    cout << "Game Publisher:"	<< endl;
    cin >> game->getPublisher();
    cout << "Game Rating:" <<	endl;
    cin >> *game->getRating();
    vec->push_back(game);
  }
  else if (strcmp(input, "MUSIC") == 0 || strcmp(input, "music") == 0) {
    Music* music = new Music();
    cout << "Music Title:" << endl;
    cin >> music->getTitle();
    cout << "Music Year:" << endl;
    cin >> *music->getYear();
    cout << "Music Artist:" << endl;
    cin >> music->getArtist();
    cout << "Music Duration:" << endl;
    cin >> *music->getDuration();
    cout << "Music Publisher:" << endl;
    cin >> music->getPublisher();
    vec->push_back(music);
  }
  else if (strcmp(input, "MOVIE") == 0 || strcmp(input, "movie") == 0) {
    Movie* movie = new Movie();
    cout << "Movie Title:" << endl;
    cin >> movie->getTitle();
    cout << "Movie Year:" << endl;
    cin >> *movie->getYear();
    cout << "Movie Director:" << endl;
    cin >> movie->getDirector();
    cout << "Movie Duration:" << endl;
    cin >> *movie->getDuration();
    cout << "Movie Rating:" << endl;
    cin >> *movie->getRating();
    vec->push_back(movie);
  }
  else {
    cout << "Invalid media type entered" << endl;
  }
  
}
	    
void SEARCH(vector<Media*>* vec)
{
  char input[10];
  char title[100];
  int year;
  
  cout << "Search by TITLE or YEAR" << endl;
  cin >> input;

  if (strcmp(input, "TITLE") == 0 || strcmp(input, "title") == 0) {
    cout << "Enter the title:" << endl;
    cin >> title;
    for (vector<Media*>::iterator it = vec->begin(); it != vec->end(); it++) {
      if (strcmp((*it)->getTitle(), title) == 0) {
	if ((*it)->getType() == 0) {
	  cout << "~" << (*it)->getTitle() << " ";
	  cout << *(*it)->getYear() << " ";
	  cout << ((Game*)(*it))->getPublisher() << " ";
	  cout << *((Game*)(*it))->getRating() << endl;
	}
	else if ((*it)->getType() == 1) {
	  cout << "~" << (*it)->getTitle() << " ";
          cout << *(*it)->getYear() << " ";
          cout << ((Music*)(*it))->getArtist() << " ";
          cout << *((Music*)(*it))->getDuration() << " ";
	  cout << ((Music*)(*it))->getPublisher() << endl;
	}
	else {
	  cout << "~" << (*it)->getTitle() << " ";
          cout << *(*it)->getYear() << " ";
          cout << ((Movie*)(*it))->getDirector() << " ";
          cout << *((Movie*)(*it))->getDuration() << " ";
          cout << *((Movie*)(*it))->getRating() << endl;
	}
      }
    }
  }
  else if (strcmp(input, "YEAR") == 0 || strcmp(input, "year") == 0) {
    cout << "Enter the year:" << endl;
    cin >> year;

    for (vector<Media*>::iterator it = vec->begin(); it != vec->end(); it++) {
      if (*(*it)->getYear() == year) {
        if ((*it)->getType() == 0) {
          cout << "~" << (*it)->getTitle() << " ";
          cout << *(*it)->getYear() << " ";
          cout << ((Game*)(*it))->getPublisher() << " ";
          cout << *((Game*)(*it))->getRating() << endl;
        }
        else if ((*it)->getType() == 1) {
          cout << "~" << (*it)->getTitle() << " ";
          cout << *(*it)->getYear() << " ";
          cout << ((Music*)(*it))->getArtist() << " ";
          cout << *((Music*)(*it))->getDuration() << " ";
          cout << ((Music*)(*it))->getPublisher() << endl;
        }
        else {
          cout << "~" << (*it)->getTitle() << " ";
          cout << *(*it)->getYear() << " ";
          cout << ((Movie*)(*it))->getDirector() << " ";
          cout << *((Movie*)(*it))->getDuration() << " ";
          cout << *((Movie*)(*it))->getRating() << endl;
        }
      }
    } 
  } 
}

void DELETE(vector<Media*>* vec)
{
  char input[10];
  char title[100];
  int year;
  
  cout << "Delete by TITLE or YEAR" << endl;
  cin >> input;
  if (strcmp(input, "TITLE") == 0 || strcmp(input, "title") == 0) {
    cout << "Enter the title:" << endl;
    cin >> title;
    for (vector<Media*>::iterator it = vec->begin(); it != vec->end(); it++) {
      if (strcmp((*it)->getTitle(), title) == 0) {
        if ((*it)->getType() == 0) {
          cout << "~" << (*it)->getTitle() << " ";
	  cout << *(*it)->getYear() << " ";
          cout << ((Game*)(*it))->getPublisher() << " ";
          cout << *((Game*)(*it))->getRating() << endl;
	  //cout << "Would you like to delete this game? y/n" << endl;
	  //cin >> input;
        }
	else if ((*it)->getType() == 1) {
          cout << "~" << (*it)->getTitle() << " ";
          cout << *(*it)->getYear() << " ";
          cout << ((Music*)(*it))->getArtist() << " ";
          cout << *((Music*)(*it))->getDuration() << " ";
          cout << ((Music*)(*it))->getPublisher() << endl;
        }
        else {
          cout << "~" << (*it)->getTitle() << " ";
          cout << *(*it)->getYear() << " ";
          cout << ((Movie*)(*it))->getDirector() << " ";
          cout << *((Movie*)(*it))->getDuration() << " ";
          cout << *((Movie*)(*it))->getRating() << endl;
        }
      }
    }
  }
  else if (strcmp(input, "YEAR") == 0 || strcmp(input, "year") == 0) {
    cout << "Enter the year:" << endl;
    cin >> year;
    
    for (vector<Media*>::iterator it = vec->begin(); it != vec->end(); it++) {
      if (*(*it)->getYear() == year) {
        if ((*it)->getType() == 0) {
          cout << "~" << (*it)->getTitle() << " ";
          cout << *(*it)->getYear() << " ";
          cout << ((Game*)(*it))->getPublisher() << " ";
          cout << *((Game*)(*it))->getRating() << endl;
        }
        else if ((*it)->getType() == 1) {
          cout << "~" << (*it)->getTitle() << " ";
          cout << *(*it)->getYear() << " ";
          cout << ((Music*)(*it))->getArtist() << " ";
          cout << *((Music*)(*it))->getDuration() << " ";
          cout << ((Music*)(*it))->getPublisher() << endl;
        }
        else {
          cout << "~" << (*it)->getTitle() << " ";
          cout << *(*it)->getYear() << " ";
          cout << ((Movie*)(*it))->getDirector() << " ";
          cout << *((Movie*)(*it))->getDuration() << " ";
          cout << *((Movie*)(*it))->getRating() << endl;
        }
      }
    }
  }
}
