#pragma once
#include "Repository.h"
#include "ExportBase.h"

///////////
//html class
///////////

class HTML :public ExportBase
{
public:
	
	HTML();

	
	virtual void write_filmslist_in_file(vector<Movie> v, string filename) override;

	~HTML();
};