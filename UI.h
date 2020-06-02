#pragma once
#include <exception>
#include "Controller.h"
#include "Validator.h"

using std::exception;

class UI
{
private:
	
	Controller contr;

	Validator validator;

	void select_mode_screen();
	void admin_options();
	void user_options();
	void go_back();
	void openbrowser(vector<Movie>, vector<Movie>&);


	void admin(); //  Admin Menu 
	void user(vector<Movie>& own_list); // User Menu 

	void afis_lista(vector<Movie>&);
	/* Preluare diferit input */
	void ask_get(string mesaj, int& var);
	void ask_get(string mesaj, string& var);
	void ask_get(string mesaj, char &c);
	void ask_get_movie(string& id, string& title, string& genre, int& year, int& likes, string& trailer);

	/* Evidentierea eventualelor input uri eronate */
	void invalid_input(const string&, const string&, const string&);
	void invalid_input(const string&, const int&);
	void invalid_input(const string&);

	void validation_data(int &year, int &likes );
	void validation_data(string &id, int &year, int &likes );
	void wrong_option();
	void error_msg(exception&);
	void show_file(string filename);
	
public:

	/* Constructor */
	UI(Controller c = Controller() );
	Controller& getController();
	void run();
};
