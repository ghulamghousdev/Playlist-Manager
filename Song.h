#ifndef SONG_H
#define SONG_H

#include <iostream>

using namespace std;

using namespace std;


// Song is a simple class that stores a title and artist as strings
// it just provides i/o operators, == operator, constructors and Set function
class Song
{
	// output the song in the format:
	// title, artist
	friend ostream &operator<<(ostream &os, const Song &song);

	// input the song in the format:
	// title, artist
	friend istream &operator>>(istream &is, Song &song);

	// compare two song objects for equality
	friend bool operator==(const Song &lhs, const Song &rhs);

public:
	// constructors
	Song();
	Song(const char *t, const char *a);

	// set the song
	void Set(const char *t, const char *a);

private:
	static const int MAX_CHARS = 64;

	char title[MAX_CHARS];
	char artist[MAX_CHARS];
};

#endif
