#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>

#include "Movie.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"
#include "Tests.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::getline;


using std::string;
using std::vector;


int main()
{	
	Repository repo("Movies.txt");
	Controller ctrl(repo);
	UI ui(ctrl);
	testAll();
	ui.run();
	return 0;
}