#include "Controller.h"
Controller::Controller( Repository repo ) 
{
	mapexports.insert(make_pair("HTML", new HTML));
	mapexports.insert(make_pair("TXT", new TXT));
	mapexports.insert(make_pair("CSV", new CSV));
	this->repo = repo;
}


Repository& Controller::getRepo() {
	return repo;
}

void Controller::setRepo(Repository value) { 
	repo = value;
}