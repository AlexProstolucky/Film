#include <iostream>
#include <vector>
using namespace std;

struct Film
{
	string name;
	string director;
	string genre;
	short int rating;
	short int price;
};

void search_name( vector <Film> &films , string name)
{
	for (int i = 0; i < films.size(); i++) 
	{
		Film film = films[i];
		if (film.name == name) 
		{
			cout << "\nThe film found: ";
			cout << "\nName: " << film.name;
			cout << "\nDirector: " << film.director;
			cout << "\nGenre: " << film.genre;
			cout << "\nRating: " << film.rating;
			cout << "\nPrice: " << film.price;
			cout << "\nPosition --> " << i;
			return;
		}
	}
	cout << "\nFilm not found!";
	return;
}

void search_dir(vector <Film> &films, string director)
{
	for (int i = 0; i < films.size(); i++)
	{
		Film film = films[i];
		if (film.director == director)
		{
			cout << "\nThe director of film found: ";
			cout << "\nName: " << film.name;
			cout << "\nDirector: " << film.director;
			cout << "\nGenre: " << film.genre;
			cout << "\nRating: " << film.rating;
			cout << "\nPrice: " << film.price;
			cout << "\nPosition --> " << i;
			return;
		}
	}
	cout << "\nDirector not found!";
	return;
}


void search_genre(vector <Film> &films, string genre)
{
	cout << "\nSearch genre " << genre << "...";
	for (int i = 0; i < films.size(); i++)
	{
		Film film = films[i];
		if (film.genre == genre)
		{
			cout << "\nThe rating of film found: ";
			cout << "\nName: " << film.name;
			cout << "\nDirector: " << film.director;
			cout << "\nGenre: " << film.genre;
			cout << "\nRating: " << film.rating;
			cout << "\nPrice: " << film.price;
			cout << "\nPosition --> " << i;
			return;
		}
	}
	cout << "\nGenre not found!";
	return;
}

void popular(vector <Film>& films, string genre )
{
	int pos = -1;
	int max = -1;
	Film film;
	cout << "\nPopular film of genre " << genre << " found";
	for (int i = 0; i < films.size(); i++)
	{
		film = films[i];
		if (film.genre == genre) {
			if (max < film.rating)
			{
				max = film.rating;
				pos = i;
			}
		}
	}
	if (max != -1) {
		film = films[pos];
		cout << "\nThe best film of gener found: ";
		cout << "\nName: " << film.name;
		cout << "\nDirector: " << film.director;
		cout << "\nRating: " << film.rating;
		cout << "\nGenre: " << film.genre;
		cout << "\nPrice: " << film.price;
		cout << "\nPosition --> " << pos;
	}
	else cout << "\nPopular film not found!";
	return;
}

void get_all(vector <Film>& films) 
{
	cout << "\nAll FIMS: ";
	for (size_t i = 0; i < films.size(); i++)
	{
		Film film = films[i];
		cout << "\nName: " << film.name;
		cout << "\nDirector: " << film.director;
		cout << "\nRating: " << film.rating;
		cout << "\nGenre: " << film.genre;
		cout << "\nPrice: " << film.price;
		cout << "\nPosition --> " << i;
		cout << "\n\n";
	}
}

void add(vector <Film>& films, string name, string director, string genre, short int rating, short int price)
{
	Film film;
	film.name = name;
	film.director = director;
	film.genre = genre;
	film.rating = rating;
	film.price = price;
	films.push_back(film);
}

void create(vector <Film>& films) 
{
	string name, director, genre;
	short int ratting, price;
	cout << "\nCreating film:";
	cout << "\nInput name of film --> ";
	cin >> name;
	cout << "\nInput director of film --> ";
	cin >> director;
	cout << "\nInput genre of film --> ";
	cin >> genre;
	cout << "\nInput ratting of film --> ";
	cin >> ratting;
	cout << "\nInput price of film --> ";
	cin >> price;
	add(films, name, director, genre, ratting, price);
}

int main()
{
	vector <Film> films;
	create(films);
	cout << endl;
	add(films, "Star Wars", "Jony", "Fantasy", 8, 10);
	popular(films, "Fantasy");
	cout << endl << endl;
	search_genre(films, "Romantic");
	cout << endl << endl;
	search_dir(films, "Jony");
	cout << endl << endl;
	search_name(films, "Avatar");
	cout << endl << endl;
	get_all(films);
}