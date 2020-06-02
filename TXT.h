#pragma once
#include "ExportBase.h"
#include <fstream>

class TXT :public ExportBase {
public:
	TXT();

	~TXT();

	virtual void write_filmslist_in_file(std::vector<Movie> v, string filename) override;
};