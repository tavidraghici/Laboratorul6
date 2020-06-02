#include <iostream>
#include <exception>
#include <windows.h>

#include "UI.h"

using std::cin;
using std::cout;
using std::cerr;
using std::exception;

UI::UI(Controller c)
{
	contr = c;
}

Controller& UI::getController()
{
	return contr;
}


void UI::ask_get(string mesaj, int &value)
{
	cout << '\n';
	cout << mesaj << ": ";
	cin >> value; 
	cin.get(); //golesc bufferul 
}

void UI::ask_get(string mesaj, char& value)
{
	cout << '\n';
	cout << mesaj << ": ";
	cin >> value; 
	cin.get();//golesc bufferul
}

void UI::ask_get(string mesaj, string& value)
{
	cout << '\n';
	cout << mesaj << ": "; 
	getline(cin, value);
}
void UI::wrong_option()
{
	cout << "Introduceti o valoare corespunzatoare optiunilor\n";
}
void UI::error_msg(exception& e)
{
	cout << "ERORR\n";
	cerr << e.what();
	cout << "----\n";
	cout << '\n';
}
void UI::select_mode_screen()
{
	cout << "1.Administrator\n" << "2.User\n" << "0.Exit\n";
}
void UI::run()
{
	int mode;
	vector<Movie> watchlist;
	
	while (true)
	{
		select_mode_screen();
		ask_get("mod", mode);
		switch (mode)
		{
			case 1:
			{
				admin();
				break;
			}
			case 2:
			{
				user(watchlist);
				break;
			}
			case 0:
			{
				return;
			}
			default: { 
				wrong_option(); 
				break;
			}
		}
	}
}	
void UI::ask_get_movie(string &id, string &title, string &genre, int &year, int &likes, string &trailer)
{
	ask_get("id", id);
	ask_get("title", title);
	ask_get("genre", genre);
	ask_get("year", year);
	ask_get("likes", likes); 
	ask_get("trailer", trailer);
}
void UI::invalid_input(const string &entity, const string & l, const string& h)
{
	cout << "Valoarea pentru  "<< entity.c_str() << " trebuie sa fie intre: "<< l << " si " << h << '\n';
}
void UI::invalid_input(const string& entity, const int& low)
{
	cout << "Valoarea pentru "<< entity.c_str() << " trebuie sa fie minim: "<< low << '\n';
}
void UI::invalid_input(const string& entity)
{
	cout << "Valoare invalida "<< entity.c_str();
}


void UI::validation_data(int& year, int& likes)
{
	cout << "Validarea datelor...\n";

	while (!validator.validate_year(year))
	{
		invalid_input("year", "1887", "2020");
		cout << "Reintroducere!\n";
		ask_get("year", year);
	}
	
	while (!validator.validate_likes(likes))
	{
		invalid_input("likes", 0);
		cout << "Reintroducere!\n";
		ask_get("likes", likes);
	}

	cout << "Valori valide.\n";
}

void UI::validation_data(string &id, int &year, int &likes)
{
	cout << "Validare date...\n";

	const vector<string> ids = contr.getRepo().getIds();
	int length = ids.size();
	
	while (!validator.validate_id(id, ids))
	{
		invalid_input("id", ids[0], ids[length - 1]);
		cout << "Reintroducere!\n";
		ask_get("id", id);
	}

	while (!validator.validate_year(year))
	{
		invalid_input("year", "1887", "2020");
		cout << "Reintroducere!\n";
		ask_get("year", year);
	}

	while (!validator.validate_likes(likes))
	{
		cout << "likes = " << likes << '\n';
		invalid_input("likes", 0);
		cout << "Reintroducere!\n";
		ask_get("likes", likes);
	}
	cout << "Valori valide!\n";
}

void UI::admin()
{
	string id, title, genre, trailer;
	int year, likes;
	int option;
	while (true)
	{
		admin_options();
		ask_get("Optiune", option);
		switch (option)
		{
			case 1:
			{
				ask_get_movie(id, title, genre, year, likes, trailer);
				validation_data(id, year, likes);
				try 
				{ 
					contr.getRepo().add(Movie(id, title, genre, year, likes, trailer)); 
					cout << "Film adaugat cu succes\n";
				}
				catch (exception& e)
				{
					error_msg(e);
					admin_options();
				}
				break;
			}
			case 2:
			{
				string id1;
				ask_get("id (filmului pe care doriti sa il inlocuiti)", id1);
				ask_get_movie(id, title, genre, year, likes, trailer);
				validation_data(year, likes);
				try
				{
					contr.getRepo().edit(id1, Movie(id, title, genre, year, likes, trailer));
					cout << "Film editat cu succes\n";
				}
				catch (exception& e)
				{
					error_msg(e);
				}
				break;
			}
			case 3:
			{
				string id1;
				ask_get("id (filmului pe care doriti sa il stergeti)", id1);
				try
				{
					contr.getRepo().del(id1);
					cout << "Film sters cu succes\n";
				}
				catch (exception& e)
				{
					error_msg(e);
				}
				break;
			}
			case 4:
			{
				contr.getRepo().toString();
				break;
			}
			case 0:
			{
				go_back();
				return;
			}
			default:
			{
				wrong_option();
				break;
			}
		}
	}
}
	
void UI::afis_lista(vector<Movie>& aux)
{
	cout << "Lista dumneavoastra este:\n";
	if (!aux.size()) { cout << "Lista dumneavoatra este goala!\n"; return; }

	int length = aux.size();
	for (int i = 0; i < length; i++)
		cout << aux[i] << '\n';
	cout << '\n';
}
void UI::show_file(string filename) {
	ShellExecuteA(0, "open", filename.c_str(), 0, 0, SW_SHOW);
}

void UI::openbrowser(vector<Movie> aux, vector<Movie> &watchlist)
{
	string mesaj = "( \"1\" = Da / \"2\" = Nu / \"3\" = Iesire) Optiuni";
	char com;  
	
	int length = aux.size();
	int i = 0;
	for(i=0;i < length;i++)
	{
		cout << aux[i] << '\n';
		cout << "Vizualizeaza trailerul care se v-a deschide in browser \n";
		string aux1 = '"' + aux[i].getTrailer() + '"';
		ShellExecute(NULL, "open",aux1.c_str(),NULL, NULL, SW_SHOWNORMAL);

		cout << (" Ati dori sa adaugati filmul in lista dumneavoastra ?\n");
		ask_get(mesaj, com);
		
		switch(com)
		{
		case '1':
		{	/*bool ok = TRUE;
			int length2 = watchlist.size();
			for (int j = 0; j < length2; j++)
			if (watchlist[i].getID() == aux[i].getID())
				ok = FALSE;//validam daca nu exista deja filmul in lista de vizionare
			if (ok==TRUE)*/
			watchlist.push_back(aux[i]); 
			break;
		}

		case '2':
			break;
		case '3':
			return ;
		}
	}
}

void UI::user(vector<Movie>& my_list)
{
	int option;
	while (true)
	{
		user_options();
		ask_get("Optiune", option);
		switch (option)
		{
			case 1:
			{
				cout << "Introduceti genul dorit\n";
				string genre;
				cout << " (pentru a vizualiza toata lista de filme nu introduceti nimic)\n";
				ask_get("genre", genre);
				vector<Movie> aux = contr.getRepo().GenreList(genre);

				openbrowser(aux, my_list);
				//afis_lista(my_list);
				break;
			}
			case 2:
			{
				afis_lista(my_list);
				if (!my_list.size()) break;
				
				string id;
				ask_get("id (al filmului pe care doriti sa il stergeti)", id);
				try
				{

					int length = my_list.size();
					for (int i = 0; i < length; i++)
					{
						if (my_list[i].getID() == id)
						{
							my_list.erase(my_list.begin() + i); 
							break;
						}
					}
	
					char com;
					cout << "Ti-a placut filmul?(Raspunsul dumneavoastra in cazul unui feedback pozitiv va afecta numarul de likeuri)\n";
					ask_get("(\"1\" = Da / \"2\" = Nu / \"3\" = Iesire)\n Optiuni",com);
					switch (com)
					{
					case '1':
					{
						int poz = contr.getRepo().search(id);

						vector<Movie>& list = contr.getRepo().getList();

						int nr_likes = list[poz].getLikes();
						list[poz].setLikes(++nr_likes);
						
					}
					case '3': break;
					}
				}
				catch (exception& e)
				{
					cerr << e.what();
				}
				break;
			}
			case 3:
			{
				afis_lista(my_list);
				break;
			}
			case 4:
			{
				cout << "\nAlege modul de export: CSV, HTML, TXT\n";
				string opt;
				cin >> opt;

				if (opt == "CSV") {
					contr.mapexports["CSV"]->write_filmslist_in_file(my_list, "Movies.csv");
					show_file("Movies.csv");
				}

				if (opt == "HTML") {
					contr.mapexports["HTML"]->write_filmslist_in_file(my_list, "Movies.html");
					show_file("Movies.html");
				}

				if (opt == "TXT") {
					contr.mapexports["TXT"]->write_filmslist_in_file(my_list, "Moviesw.txt");
					show_file("Moviesw.txt");
				}
				break;
			}
			case 0:
			{
	
				go_back();
				return;
			}
			default:
			{
				wrong_option();
				break;
			}
		}
	}
}

void UI::admin_options()
{
	cout << "Admin Menu\n";
	cout << "0. Intoarcere la pasul anterior\n"<< "1. Adaugare film\n"<< "2. Update film\n"<< "3. Stergere film\n"<< "4. Afisare filme\n\n";
	
}

void UI::user_options()
{
	cout << "User Menu\n"<< "0. Intoarcere la pasul anterior\n"<< "1. Afisare filme dupa gen\n"<< "2. Stergere film din lista filmelor de vizionat\n"
		<< "3. Afisarea filmelor de vizionat\n"<<"4.CSV, HTML, TXT\n\n";
}

void UI::go_back()
{
	cout << "Intoarcere\n";
	cout << '\n';
}
