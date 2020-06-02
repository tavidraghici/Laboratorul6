#pragma once
#include "CSV.h"
using namespace std;
CSV::CSV() :ExportBase() {
    
}


void CSV::write_filmslist_in_file(vector<Movie> v, string filename)
{
   
    ofstream fin;
    fin.open(filename, ios::out | ios::trunc);
    for (int i = 0; i < v.size(); i++)
        fin << i << "," << v.at(i).getTitle() << "," << v.at(i).getGenre() << "," << v.at(i).getYear() << "," << v.at(i).getLikes() << "," << v.at(i).getTrailer() << '\n';

    fin.close();
}

CSV::~CSV() {

}