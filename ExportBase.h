#pragma once
#include <string>
#include "Movie.h"
#include <vector>
#include <windows.h>
#include <shellapi.h>

class ExportBase
{
public:
	ExportBase();
	virtual void write_filmslist_in_file(std::vector<Movie> v, string filename) = 0;

};