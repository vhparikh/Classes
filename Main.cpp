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

  vector<Media*> media; //vector of media pointers
  bool quit = false;
  char input[10];

  cout << "Welcome to classes your commands are: ADD, SEARCH, DELETE and QUIT" << endl;
  
  while (quit == false) { //while the user hasn't typed in quit
    cin.get(input, 10); //gets the input
    cin.clear();
    cin.ignore(10000, '\n');
        
    if (strcmp(input, "ADD") == 0 || strcmp(input, "add") == 0) {
      ADD(&media); //call add and pass in location of media vector
    }
    else if (strcmp(input, "SEARCH") == 0 || strcmp(input, "search") == 0) {
      SEARCH(&media); //call search and pass in location of media vector
    }
    else if (strcmp(input, "DELETE") == 0 || strcmp(input, "delete") == 0) {
      DELETE(&media); //call delete and pass in location of media vector
    }
    else if (strcmp(input, "QUIT") == 0 || strcmp(input, "quit") == 0) {
      quit = true; //set quit to true
    }
    else {
      cout << "An invalid command was entered" << endl;
    }
  }
}

//adds a media type to vector parameter is a vector pointer pointing to a vector of media pointers
void ADD(vector<Media*>* vec)
{
  char input[10];
  cout << "Would you like to add a GAME, MUSIC or a MOVIE?" << endl;
  cin.get(input, 10); //get input
  cin.clear();
  cin.ignore(10000, '\n');
  
  if (strcmp(input, "GAME") == 0 || strcmp(input, "game") == 0) {
    Game* game = new Game(); //creates a game and asks user for all info
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
    Music* music = new Music(); //creates music and asks user for all info
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
    Movie* movie = new Movie(); //creates a movie and asks user for all info
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

//searchs for objects parameter is a vector pointer pointing to a vector of media pointers
void SEARCH(vector<Media*>* vec)
{
  char input[10];
  char title[100];
  int year;
  
  cout << "Search by TITLE or YEAR" << endl;
  cin.get(input, 10); //get input
  cin.clear();
  cin.ignore(10000, '\n');

  if (strcmp(input, "TITLE") == 0 || strcmp(input, "title") == 0) {
    cout << "Enter the title:" << endl;
    cin.get(title, 100); //searches by title
    cin.clear();
    cin.ignore(10000, '\n');
    for (vector<Media*>::iterator it = vec->begin(); it != vec->end(); it++) {
      if (strcmp((*it)->getTitle(), title) == 0) { //if title is found find the type of media object
	if ((*it)->getType() == 0) { //game
	  cout << "~" << (*it)->getTitle() << " ";
	  cout << *(*it)->getYear() << " ";
	  cout << ((Game*)(*it))->getPublisher() << " ";
	  cout << *((Game*)(*it))->getRating() << endl;
	}
	else if ((*it)->getType() == 1) { //music
	  cout << "~" << (*it)->getTitle() << " ";
          cout << *(*it)->getYear() << " ";
          cout << ((Music*)(*it))->getArtist() << " ";
          cout << *((Music*)(*it))->getDuration() << " ";
	  cout << ((Music*)(*it))->getPublisher() << endl;
	}
	else { //movie
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
    cin >> year; //searches by year
    cin.clear(); 
    cin.ignore(10000, '\n');
    
    for (vector<Media*>::iterator it = vec->begin(); it != vec->end(); it++) {
      if (*(*it)->getYear() == year) { //if year is found find the type of media object
        if ((*it)->getType() == 0) { //game
          cout << "~" << (*it)->getTitle() << " ";
          cout << *(*it)->getYear() << " ";
          cout << ((Game*)(*it))->getPublisher() << " ";
          cout << *((Game*)(*it))->getRating() << endl;
        }
        else if ((*it)->getType() == 1) { //music
          cout << "~" << (*it)->getTitle() << " ";
          cout << *(*it)->getYear() << " ";
          cout << ((Music*)(*it))->getArtist() << " ";
          cout << *((Music*)(*it))->getDuration() << " ";
          cout << ((Music*)(*it))->getPublisher() << endl;
        }
        else { //movie
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

//deletes media object from vector parameter is a vector pointer pointing to a vector of media pointers
void DELETE(vector<Media*>* vec)
{
  char input[10];
  char title[100];
  int year;
  int size = vec->size();
  int counter = 0;

  cout << "Delete by TITLE or YEAR" << endl;
  cin.get(input, 10); //get input
  cin.clear();
  cin.ignore(10000, '\n');
  
  if (strcmp(input, "TITLE") == 0 || strcmp(input, "title") == 0) {
    cout << "Enter the title:" << endl;
    cin.get(title, 100); //get title
    cin.clear();
    cin.ignore(10000, '\n');
    
    while (size >= counter) { //while the whole vector hasn't been searched
      for (vector<Media*>::iterator it = vec->begin(); it != vec->end(); it++) {
	if (strcmp((*it)->getTitle(), title) == 0) { //if title is found find the type of media object
	  if ((*it)->getType() == 0) { //game
	    cout << "~" << (*it)->getTitle() << " ";
	    cout << *(*it)->getYear() << " ";
	    cout << ((Game*)(*it))->getPublisher() << " ";
	    cout << *((Game*)(*it))->getRating() << endl;
	    cout << "Would you like to delete this game? y/n" << endl;
	    cin >> input; //get confirmation
	    cin.clear();
	    cin.ignore(10000, '\n');
	    if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
	      //	      delete *it;
	      vec->erase(it); //deletes object
	      counter++; //increments counter
	      break; //breaks out of for loop to reset iterator
	      //return;
	    }
	    else {
	      counter++;
	      //break;
	    }
	  }
	  else if ((*it)->getType() == 1) { //music
	    cout << "~" << (*it)->getTitle() << " ";
	    cout << *(*it)->getYear() << " ";
	    cout << ((Music*)(*it))->getArtist() << " ";
	    cout << *((Music*)(*it))->getDuration() << " ";
	    cout << ((Music*)(*it))->getPublisher() << endl;
	    cout << "Would you like to delete this song? y/n" << endl;
	    cin >> input; //get confirmation
	    cin.clear();
	    cin.ignore(10000, '\n');
	    if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
	      //delete *it;
	      vec->erase(it); //deletes objects
	      counter++; //increments counter
	      break; //breaks out of for loop to reset iterator
	    }
	    else {
	      counter++;
	      //break;
	    }
	  }
	  else { //movie
	    cout << "~" << (*it)->getTitle() << " ";
	    cout << *(*it)->getYear() << " ";
	    cout << ((Movie*)(*it))->getDirector() << " ";
	    cout << *((Movie*)(*it))->getDuration() << " ";
	    cout << *((Movie*)(*it))->getRating() << endl;
	    cout << "Would you like to delete this movie? y/n" << endl;
	    cin >> input; //get confirmation
	    cin.clear();
	    cin.ignore(10000, '\n');
	    if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
	      //delete *it;
	      vec->erase(it); //deletes object
	      counter++; //increments counter
	      break; //breaks out of for loop to reset iterator
	    }
	    else {
	      counter++;
	      //break;
	    }
	  }
	} 
      }
    }
  }
  else if (strcmp(input, "YEAR") == 0 || strcmp(input, "year") == 0) {
    cout << "Enter the year:" << endl;
    cin >> year; //gets year
    cin.clear();
    cin.ignore(10000, '\n');
    while (counter != size) { //while the whole vector hasnt been searched
      for (vector<Media*>::iterator it = vec->begin(); it != vec->end(); it++) {
	if (*(*it)->getYear() == year) { //if year is found find type of media object
	  if ((*it)->getType() == 0) { //game
	    cout << "~" << (*it)->getTitle() << " ";
	    cout << *(*it)->getYear() << " ";
	    cout << ((Game*)(*it))->getPublisher() << " ";
	    cout << *((Game*)(*it))->getRating() << endl;
	    cout << "Would you like to delete this game? y/n" << endl;
	    cin >> input; //get confirmation
	    cin.clear();
	    cin.ignore(10000, '\n');
	    if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
	      //delete *it;
	      vec->erase(it); //deletes object
	      counter++; //increments counter
	      break; //breaks out of for loop to reset iterator
	    }
	    else {
	      counter++;
	    }
	  }
	  else if ((*it)->getType() == 1) { //music
            cout << "~" << (*it)->getTitle() << " ";
            cout << *(*it)->getYear() << " ";
            cout << ((Music*)(*it))->getArtist() << " ";
            cout << *((Music*)(*it))->getDuration() << " ";
            cout << ((Music*)(*it))->getPublisher() << endl;
            cout << "Would you like to delete this song? y/n" << endl;
            cin >> input; //get confirmation
	    cin.clear();
	    cin.ignore(10000, '\n');
            if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
	      //delete *it;
	      vec->erase(it); //deletes object
	      counter++; //increments counter
	      break; //breaks out of for loop to reset iterator
            }
	    else {
	      counter++;
	    }
	  }
	  else { //movie
            cout << "~" << (*it)->getTitle() << " ";
            cout << *(*it)->getYear() << " ";
            cout << ((Movie*)(*it))->getDirector() << " ";
            cout << *((Movie*)(*it))->getDuration() << " ";
            cout << *((Movie*)(*it))->getRating() << endl;
            cout << "Would you like to delete this movie? y/n" << endl;
            cin >> input; //get confirmation
	    cin.clear();
	    cin.ignore(10000, '\n');
            if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
	      //delete *it;
	      vec->erase(it); //deletes object
	      counter++; //increments counter
	      break; //breaks out of for loop to reset iterator
            }
	    else {
	      counter++;
	    }
	  }
	}
      }
    }
  }
}
