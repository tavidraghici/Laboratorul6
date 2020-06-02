#pragma once
#include "Validator.h"
#include<iostream>

bool Validator::validate_id(const string &id, vector<string> ids)
{
	int length = ids.size();
	for (int i = 0; i < length; i++)
		if (id == ids[i]) return false;
	return true;
}

bool Validator::validate_year(const int &year)
{
	return (1887 <= year && year <= 2020); 
}

bool Validator::validate_likes(const int &likes)
{
	return (0 <= likes);
}
