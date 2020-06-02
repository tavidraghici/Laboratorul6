#include "HTML.h"
using namespace std;
HTML::HTML() :ExportBase() {

}

void HTML::write_filmslist_in_file(vector<Movie> v, string filename)
{
  
    ofstream fin;
    fin.open(filename, ios::out | ios::trunc);
    fin << "<!DOCTYPE html>\n<html>\n<head>\n<title>Watchliste</title>\n</head>\n<body>\n<table style='background-color:violet' border='5' bordercolor='Lime' align='center'>\n<tr style='font-weight:bold;background-color:#8051E0'>\n<td>Title</td>\n<td>Genre</td>\n<td>Releaseyear</td>\n<td>Likes</td>\n<td>Trailer link</td>\n</tr>\n";
    for (int i = 0; i < v.size(); i++)
        fin << "<tr>\n<td>" << v[i].getTitle() << "</td>\n<td>" << v[i].getGenre() << "</td>\n<td>" << v[i].getYear() << "</td>\n<td>" << v[i].getLikes() << "</td>\n<td><a href=" << v[i].getTrailer() << ">Link</a>\n</td>\n</tr>\n";
    fin << "</table>\n</body>\n</html>\n";
    fin.close();
}

HTML::~HTML() {

}