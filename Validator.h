#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class Validator
{
private:

public:


	bool validate_id(const string&, vector<string>);

	bool validate_likes(const int &); 
	
	bool validate_year(const int &);

};