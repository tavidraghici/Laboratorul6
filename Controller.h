#pragma once
#include "Repository.h"
#include "CSV.h"
#include "HTML.h"
#include "TXT.h"
#include "ExportBase.h"
#include <map>
using namespace std;
class Controller
{
private:
	
	Repository repo;

public:
	map <string, ExportBase*> mapexports;
	Controller(Repository r = Repository());

	Repository& getRepo();
	void setRepo(Repository value);
};
