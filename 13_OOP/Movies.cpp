
/******************************************************************
 * Section 13 Challenge
 * Movies.h
 * 
 * Models a collection of Movies as a std::vector
 * 
 * ***************************************************************/
#include <iostream>
#include "Movies.h"
#include "Movie.h"
using namespace std;

 /*************************************************************************
    Movies no-args constructor
**************************************************************************/
Movies::Movies() {
}

/*************************************************************************
    Movies destructor
**************************************************************************/
Movies::~Movies() {
}

  /*************************************************************************
    add_movie expects the name of the move, rating and watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    
    If it does then return false since the movie already exists
    Otherwise, create a movie object from the provided information
    and add that movie object to the movies vector and return true
    *********************************************************************/
bool Movies::add_movie(std::string name, std::string rating, int watched)
{
	for (const Movie &movie: movies) //for each element &movie of type Movie (const keyword so we dont change anything) in vector movies contained in this class
	{
        if (movie.get_name() == name) //call each elemnt's get_name() function and compare to name. if true return false below
            return false; //function to return false, meaning not added due to it already being there
    }
	
	Movie movie (name, rating, watched); //create an object called movie of type Movie by calling Movie constructor with 3 args we already have from the function
	movies.push_back(movie); //add this new object movie to movies vector
	return true; //movie successfully added
		
}

 /*************************************************************************
    increment_watched expects the name of the move to increment the
    watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    If it does then increment that objects watched by 1 and return true.

    Otherwise, return false since then no movies object with the movie name
    provided exists to increment
    *********************************************************************/
bool Movies::increment_watched(std::string name)
{
	for (Movie &movie: movies) //each (reference to &)element movie of type Movie in vector movies
	{
		if (movie.get_name() == name) //get each element movie's name and compare to this function's argument. if true, proceed
		{
			movie.increment_watched();
			return true;
		}
		
	}
   
   return false;
}

/*************************************************************************
    display
    
    display all the movie objects in the movies vector.
    for each movie call the movie.display method so the movie
    object displays itself
    *********************************************************************/
void Movies::display() const
{
	if (movies.size() == 0)
	{
		cout << "The list is empty" << endl;
	}
	else
	{
	   for (const auto &movie: movies) //use reference so we aren't passing by value and const so we don't change anything in Movie class
	   {
		   movie.display();
	   }
	}
}

