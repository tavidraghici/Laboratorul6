#pragma once
#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Movie
{
private:

	string id;
	string title;
	string genre;
	int year;
	int likes;
	string trailer; 

public:

	/* Constructor */
	Movie(string = "-1", string = "", string = "", int = -1, int = -1, string = "");

	string getID() const;
	void setID(string);

	string getTitle() const;
	void setTitle(string);
	
	string getGenre() const;
	void setGenre(string);
	
	int getYear() const;
	void setYear(int);
	
	int getLikes() const;
	void setLikes(int);
	
	string getTrailer() const;
	void setTrailer(string);
};
bool operator==(const Movie& m1, const Movie& m2);
ostream& operator<<(ostream& os, const Movie& m); 