#include <iostream>
#include <cstring>
#include "PlayList.h"

using namespace std;

playlist::playlist()
{
	//setting size of array to 2
	array_size = 2;

	//declaring array
	Playlist = new Song[array_size];

	//declaring no of songs -1
	no_of_songs = -1;

	song_index = 0;
}

//function to add song
void playlist::AddSong(const Song &s)
{
	//incrementing no of songs
	no_of_songs++;
	//adding song
	Playlist[no_of_songs] = s;
	//checking if array size needs to b adjusted
	if ((no_of_songs + 1) == array_size)
	{
		doubleSize(); // calling double size function
	}
}

//function to delete song
bool playlist::DeleteSong(const Song &s)
{

	bool song_deleted = false;

	//searching song whom we want to delete
	for (int i = 0; i < no_of_songs; i++)
	{
		if (s == Playlist[i])
		{
			for (int j = i; j < no_of_songs; j++)
			{
				Playlist[i] = Playlist[j + 1]; //deleting song
			}

			no_of_songs--; //decrementing no of songs

			break;
		}
	}

	//if no of songs equal to zero
	if (no_of_songs == 0)
	{
		array_size = 2; //settng array size to 2
	}
	if (array_size > 2)
	{
		if (no_of_songs + 1 < array_size / 2) // checking if array size needs to b adjusted
		{
			halfSize(); // calling the half size function
		}
	}

	if (song_deleted == true)
	{
		cout << "Song has been deleted successfuly\n";
	}
	else
	{
		cout << "No such song exists/n";
	}
	return song_deleted;
}

//function to show all songs
void playlist::ShowAll() const
{
	cout << "All the songs present in playlist are as follows" << endl;

	for (int i = 0; i <= no_of_songs; i++)
	{
		cout << Playlist[i] << endl; // printing all songs
	}
}

//function to play specific number of songs
void playlist::play(int num)
{
	for (int i = 0; i < num; i++)
	{
		if (song_index > no_of_songs)
		{
			song_index = 0;
		}
		cout << Playlist[song_index] << endl;

		song_index++;

		if (song_index == (no_of_songs))
		{ //song index becomes more  then no of songs
			song_index = 0;
		}
	}
}

//function to show array size , no of songs and current song index
void playlist::ShowStatus() const
{
	cout << "The total slots allocated for the song list is " << array_size << endl; //printng array size
	cout << "The total songs in the list is " << no_of_songs + 1 << endl;			 //printing no of songs
	cout << "The song Index of current playing song is " << song_index << endl;		 // printing current song index
}

//friend function to  add song using + operator
playlist operator+(playlist list, const Song s)
{

	list.no_of_songs++;
	//adding song
	list.Playlist[list.no_of_songs] = s;
	//adjusting array size
	if ((list.no_of_songs + 1) == list.array_size)
	{
		list.doubleSize();
	}

	return list;
}

//subtracting song
playlist operator-(playlist list, const Song s)
{
	bool song_deleted = false;
	//searching song
	for (int i = 0; i < list.no_of_songs; i++)
	{
		if (s == list.Playlist[i])
		{
			for (int j = i; j < list.no_of_songs; j++)
			{
				list.Playlist[i] = list.Playlist[j + 1]; //deleting song
			}

			list.no_of_songs--;
			break;
		}
	}
	//adjusting array size
	if (list.no_of_songs == 0)
	{
		list.array_size = 2;
	}
	if (list.array_size > 2)
	{
		if (list.no_of_songs + 1 < list.array_size / 2)
		{
			list.halfSize();
		}
	}

	if (song_deleted == true)
	{
		cout << "Song has been deleted successfuly\n";
	}
	else
	{
		cout << "No such song exists/n";
	}
	return list;
}

//function to double size
void playlist::doubleSize()
{
	//pointer to song class
	Song *playtemp;
	//declaring new array
	playtemp = new Song[2 * array_size];
	for (int i = 0; i <= no_of_songs; i++)
	{
		playtemp[i] = Playlist[i]; //storing songs in new array
	}
	delete[] Playlist; //deleting old array
	Playlist = playtemp;
	array_size = array_size * 2;
}

//function to halve size of array
void playlist::halfSize()
{
	//declaring new pointer and array
	Song *Playlist1 = new Song[array_size / 2];
	for (int j = 0; j < no_of_songs; j++)
	{
		Playlist1[j] = Playlist[j]; //storing songs into new array
	}
	array_size = array_size / 2;
	delete[] Playlist;
	Playlist = Playlist1;
}
//destructor to free memory
playlist::~playlist()
{
	delete[] Playlist;
}
