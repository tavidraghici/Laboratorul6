#pragma once
#include "Repository.h"
#include "ExportBase.h"


class CSV :public ExportBase
{
public:
	
	CSV();

	
	virtual void write_filmslist_in_file(vector<Movie> v, string filename) override;

	~CSV();
};