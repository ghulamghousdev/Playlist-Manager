// Play_list_manager.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Song.h"
#include "PlayList.h"

using namespace std;

//function to call add song function
void DoAdd(playlist &play_list)
{
  Song s;

  cout << "Enter song\n: ";
  //inputting object
  cin >> s;

  //calling function to add song
  play_list.AddSong(s);

  //calling function to show status
  play_list.ShowStatus();
}

//function to call delete song function
void DoDelete(playlist &s1)
{
  Song s2;

  cout << "Enter song to delete\n: ";

  cin >> s2;
  //calling function to delete song
  s1.DeleteSong(s2);

  //function to show status
  s1.ShowStatus();
}

void Add_by_Addition_operator(playlist list)
{
  Song s;

  cout << "Enter the song to add\n";

  cin >> s;

  list = list + s;

  list.ShowStatus();
}

//function to delete song using - operator
void delete_by_subtraction_operator(playlist list)
{
  Song s;

  cout << "Enter the song to delete\n";

  cin >> s;

  list = list - s;

  list.ShowStatus();
}

//function for selection menu
bool Menu(playlist &play_list)
{
  bool good;
  do
  {
    good = true;

    cout << "\n\nPlayList Program!\n"
         << "\tA - Add a song\n"
         << "\tD - Delete a song\n"
         << "\tP - Play a song\n"
         << "\tS - Show all songs\n"
         << "\ts - Show Status\n"
         << "\t+ - Add song by addition operator\n"
         << "\t- - Delete song by subtraction operator\n"
         << "\tQ - Quit\n: ";

    char choice;
    //inputting  the selection letter
    cin >> choice;

    switch (choice)
    {
      //case to add song
    case 'A':
      DoAdd(play_list);
      break;

    //case to delete song
    case 'D':
      DoDelete(play_list);
      break;

    //case to play songs
    case 'P':
      play_list.play(2);
      break;

      //case to show all songs
    case 'S':
      play_list.ShowAll();
      break;

      //case to show array size , no of songs and current song index
    case 's':
      play_list.ShowStatus();
      break;

    //Case to add song using + operator
    case '+':
      Add_by_Addition_operator(play_list);
      break;

    case '-':
      delete_by_subtraction_operator(play_list);
      break;

    case 'Q':
      return false;

    default:
      good = false;
    }
  } while (!good);

  return true;
}

int main()
{

  //declaring object
  playlist play_list;
  //calling function of menu
  while (Menu(play_list))
    ;

  return 0;
}
