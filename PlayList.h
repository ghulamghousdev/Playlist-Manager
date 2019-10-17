#pragma once

#include <iostream>
#include "Song.h"

using namespace std;

//playlist class declaration
class playlist 
{
	//private data members
private:

	//variable to store no of songs
	int no_of_songs;

	//variable to store current playing song index
	int song_index;
	
	//variable to store size of array
	int array_size;
	
	//declaring pointer of song class
	Song *Playlist;

public:
	//default constructor
	playlist();

	//Adding song function
	void AddSong(const Song &s);

	//function to delete song
	bool DeleteSong(const Song &s);

	//function to show all songs
	void ShowAll() const;

	//function to play specific number of songs
	void play(int num);

	//function to double the size of array
	void doubleSize();

	//function to half the size of array
	void halfSize();

	//function to show array size , no of songs and current playing song index
	void ShowStatus() const;

	//friend functio to add song
	friend playlist operator + (playlist list, const Song s);

	//friend function to delete song
	friend playlist operator - (playlist list, const Song s);

	//destructor to free memory
	~playlist();

};
