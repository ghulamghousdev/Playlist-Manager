#include <iostream>
#include "song.h"
#include <cstring>
using namespace std;

// ignore any newlines in input
void IgnoreNewLines()
{
	while (cin.peek() == '\n')
		cin.ignore();
}

// default constructor
Song::Song()
{
	strcpy_s(title, "");
	strcpy_s(artist, "");
}

Song::Song(const char *t, const char *a)
{
	Set(t, a);
}

void Song::Set(const char *t, const char *a)
{
	if (strlen(t) < MAX_CHARS)
		strcpy_s(title, t);

	if (strlen(a) < MAX_CHARS)
		strcpy_s(artist, a);
}

// output operator
ostream &operator<<(ostream &os, const Song &song)
{
	os << song.title << ", " << song.artist;

	return os;
}

// input operator
istream &operator>>(istream &is, Song &song)
{
	// ignore any newlines
	IgnoreNewLines();
	cin.getline(song.title, Song::MAX_CHARS, ',');

	// ignore the space in between
	if (cin.peek() == ' ')
		cin.ignore();

	// ignore any newlines
	IgnoreNewLines();

	// read until new line
	cin.getline(song.artist, Song::MAX_CHARS);

	return is;
}

// equality test operator
bool operator==(const Song &lhs, const Song &rhs)
{
	if (strcmp(lhs.title, rhs.title))
		return false;

	if (strcmp(lhs.artist, rhs.artist))
		return false;

	return true;
}
