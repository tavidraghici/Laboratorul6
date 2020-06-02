#include <string>
#include "Movie.h"

using std::string;

Movie::Movie(string id, string title, string genre, int year, int likes, string trailer) {
	this->id = id;
	this->title = title;
	this->genre = genre;
	this->year = year;
	this->likes = likes;
	this->trailer = trailer;
}

string Movie::getID() const { 
	return id; 
}
void Movie::setID(string value) { 
	id = value; 
}

string Movie::getTitle() const { 
	return title; 
}
void Movie::setTitle(string value) { 
	title = title;
}

string Movie::getGenre() const { 
	return genre;
}
void Movie::setGenre(string value) {
	genre = value;
}

int Movie::getYear() const { 
	return year;
}
void Movie::setYear(int value) {
	year = value; 
}

int Movie::getLikes() const {
	return likes;
}
void Movie::setLikes(int value) {
	likes = value;
}

string Movie::getTrailer() const {
	return trailer; 
}
void Movie::setTrailer(string value) {
	trailer = value;
}

bool operator==(const Movie& m1, const Movie& m2)
{
	return m1.getID() == m2.getID();
}

ostream& operator<<(ostream& os, const Movie& m) //str pentru obiect
{
	os << "id = " << m.getID() <<"\n" << m.getTitle() << "\n" << m.getGenre() << "\n" << m.getYear() << " \n" << m.getLikes();
	return os;
}