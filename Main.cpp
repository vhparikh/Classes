//Created by Vatsal Parikh
//Date 9/24/20
//users can add search and delete media types

//imports
#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <iterator>
#include "Game.h"
#include "Music.h"
#include "Movie.h"

using namespace std;

//method prototypes
void ADD(vector<Media*>* vec);
void SEARCH(vector<Media*>* vec);
void DELETE(vector<Media*>* vec);

//main method
int main()
{

  vector<Media*> media;
  bool quit = false;
  char input[10];

  while (quit == false) {
    cin.get(input, 10);
    cin.clear();
    cin.ignore(10000, '\n');
        
    if (strcmp(input, "ADD") == 0 || strcmp(input, "add") == 0) {
      ADD(&media);
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
  cin.get(input, 10);
  cin.clear();
  cin.ignore(10000, '\n');
  
  if (strcmp(input, "GAME") == 0 || strcmp(input, "game") == 0) {
    Game* game = new Game();
    cout << "Game Title:" << endl;
    cin.get(game->getTitle(), 100);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Game Year:" << endl;
    cin >> *game->getYear();
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Game Publisher:"	<< endl;
    cin.get(game->getPublisher(), 100);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Game Rating:" <<	endl;
    cin >> *game->getRating();
    cin.clear();
    cin.ignore(10000, '\n');
    vec->push_back(game);
  }
  else if (strcmp(input, "MUSIC") == 0 || strcmp(input, "music") == 0) {
    Music* music = new Music();
    cout << "Music Title:" << endl;
    cin.get(music->getTitle(), 100);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Music Year:" << endl;
    cin >> *music->getYear();
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Music Artist:" << endl;
    cin.get(music->getArtist(), 100);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Music Duration:" << endl;
    cin >> *music->getDuration();
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Music Publisher:" << endl;
    cin.get(music->getPublisher(), 100);
    cin.clear();
    cin.ignore(10000, '\n');
    vec->push_back(music);
  }
  else if (strcmp(input, "MOVIE") == 0 || strcmp(input, "movie") == 0) {
    Movie* movie = new Movie();
    cout << "Movie Title:" << endl;
    cin.get(movie->getTitle(), 100);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Movie Year:" << endl;
    cin >> *movie->getYear();
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Movie Director:" << endl;
    cin.get(movie->getDirector(), 100);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Movie Duration:" << endl;
    cin >> *movie->getDuration();
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Movie Rating:" << endl;
    cin >> *movie->getRating();
    cin.clear();
    cin.ignore(10000, '\n');
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
  cin.get(input, 10);
  cin.clear();
  cin.ignore(10000, '\n');

  if (strcmp(input, "TITLE") == 0 || strcmp(input, "title") == 0) {
    cout << "Enter the title:" << endl;
    cin.get(title, 100);
    cin.clear();
    cin.ignore(10000, '\n');
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
    cin.clear();
    cin.ignore(10000, '\n');
    
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
  int size = vec->size();
  int counter = 0;

  cout << "Delete by TITLE or YEAR" << endl;
  cin.get(input, 10);
  cin.clear();
  cin.ignore(10000, '\n');
  
  if (strcmp(input, "TITLE") == 0 || strcmp(input, "title") == 0) {
    cout << "Enter the title:" << endl;
    cin.get(title, 100);
    cin.clear();
    cin.ignore(10000, '\n');
    
    while (counter != size) {
      for (vector<Media*>::iterator it = vec->begin(); it != vec->end(); it++) {
	if (strcmp((*it)->getTitle(), title) == 0) {
	  if ((*it)->getType() == 0) {
	    cout << "~" << (*it)->getTitle() << " ";
	    cout << *(*it)->getYear() << " ";
	    cout << ((Game*)(*it))->getPublisher() << " ";
	    cout << *((Game*)(*it))->getRating() << endl;
	    cout << "Would you like to delete this game? y/n" << endl;
	    cin >> input;
	    cin.clear();
	    cin.ignore(10000, '\n');
	    if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
	      vec->erase(it);
	      if (vec->size() == 0) {
		return;
	      }
	      counter++;
	      break;
	    }
	  }
	  else if ((*it)->getType() == 1) {
	    cout << "~" << (*it)->getTitle() << " ";
	    cout << *(*it)->getYear() << " ";
	    cout << ((Music*)(*it))->getArtist() << " ";
	    cout << *((Music*)(*it))->getDuration() << " ";
	    cout << ((Music*)(*it))->getPublisher() << endl;
	    cout << "Would you like to delete this song? y/n" << endl;
	    cin >> input;
	    cin.clear();
	    cin.ignore(10000, '\n');
	    if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
	      vec->erase(it);
	      if (vec->size() == 0) {
		return;
	      }
	      counter++;
	      break;
	    }
	  }
	  else {
	    cout << "~" << (*it)->getTitle() << " ";
	    cout << *(*it)->getYear() << " ";
	    cout << ((Movie*)(*it))->getDirector() << " ";
	    cout << *((Movie*)(*it))->getDuration() << " ";
	    cout << *((Movie*)(*it))->getRating() << endl;
	    cout << "Would you like to delete this movie? y/n" << endl;
	    cin >> input;
	    cin.clear();
	    cin.ignore(10000, '\n');
	    if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
	      vec->erase(it);
	      if (vec->size() == 0) {
		return;
	      }
	      counter++;
	      break;
	    }
	  }
	} 
      } 
    }
  }
  else if (strcmp(input, "YEAR") == 0 || strcmp(input, "year") == 0) {
    cout << "Enter the year:" << endl;
    cin >> year;
    cin.clear();
    cin.ignore(10000, '\n');
    while (counter != size) {
      for (vector<Media*>::iterator it = vec->begin(); it != vec->end(); it++) {
	if (*(*it)->getYear() == year) {
	  if ((*it)->getType() == 0) {
	    cout << "~" << (*it)->getTitle() << " ";
	    cout << *(*it)->getYear() << " ";
	    cout << ((Game*)(*it))->getPublisher() << " ";
	    cout << *((Game*)(*it))->getRating() << endl;
	    cout << "Would you like to delete this game? y/n" << endl;
	    cin >> input;
	    cin.clear();
	    cin.ignore(10000, '\n');
	    if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
	      vec->erase(it);
	      if (vec->size() == 0) {
		return;
	      }
	      counter++;
	      break;
	    }
	  }
	  else if ((*it)->getType() == 1) {
            cout << "~" << (*it)->getTitle() << " ";
            cout << *(*it)->getYear() << " ";
            cout << ((Music*)(*it))->getArtist() << " ";
            cout << *((Music*)(*it))->getDuration() << " ";
            cout << ((Music*)(*it))->getPublisher() << endl;
            cout << "Would you like to delete this song? y/n" << endl;
            cin >> input;
	    cin.clear();
	    cin.ignore(10000, '\n');
            if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
              vec->erase(it);
              if (vec->size() == 0) {
                return;
              }
	      counter++;
	      break;
            }
	  }
	  else {
            cout << "~" << (*it)->getTitle() << " ";
            cout << *(*it)->getYear() << " ";
            cout << ((Movie*)(*it))->getDirector() << " ";
            cout << *((Movie*)(*it))->getDuration() << " ";
            cout << *((Movie*)(*it))->getRating() << endl;
            cout << "Would you like to delete this movie? y/n" << endl;
            cin >> input;
	    cin.clear();
	    cin.ignore(10000, '\n');
            if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
              vec->erase(it);
              if (vec->size() == 0) {
                return;
              }
	      counter++;
	      break;
            }
	  }
	}
      }
    }
  }
}
