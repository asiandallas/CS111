#include "library.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main() {
 const int CAPACITY = 100;
 Spotify top_songs[CAPACITY];
 int num_songs = 0;

 if(!collect_data(top_songs, num_songs)){
   return 1;
 }

  cout << "Welcome to Kyrstn Hall's Spotify Statistics from January-April!\n";

 char user_choice;
 do{
   string song_remove;
   string artist;

   cout << endl;
   
   cout << "A) Display Top 20 Songs\n" << "B) Sort Data by Most Played in January\n"; 
   cout << "C) Sort Data by Song Title\n";
   cout << "D) Analysis on total times/average song was played through Jan-Apr\n";
   cout << "E) Analysis on most & least played song each month from Jan-Apr\n";
   cout << "F) Remove Data\n" << "G) Filter by Artist\n" << "H) Quit Program\n" << endl; 
   cout << "Choose an option:\t";
   cin >> user_choice;

  switch(user_choice){
    case 'A':

      cout << "Displaying Top 20 songs:" << endl;
      cout << endl;
      display_data(top_songs, num_songs);
      break;

    case 'B':

      cout << "Sorting data by most played in January:" << endl;
      cout << endl;
      sort_by_plays_january(top_songs, num_songs);
      display_data(top_songs, num_songs);
      break;

    case 'C':

      cout << "Sorting data by song title:" << endl;
      cout << endl;
      sort_by_artist(top_songs, num_songs);
      display_data(top_songs, num_songs);
      break;

    case 'D':

      cout << "Analysis on total times/average song was played (Jan-Apr):" << endl;
      cout << endl;
      display_total_plays(top_songs, num_songs);
      break;

    case 'E':
      
      cout << "Analysis on most & least played song each month (Jan-Apr):" << endl;
      cout << endl;
      display_most_least_played(top_songs, num_songs);
      break;

    case 'F':
      display_data(top_songs, num_songs);
      cout << endl;
      cout << "Which song would you like to remove?\t";
      cin.ignore();
      getline(cin,song_remove);
      cout << endl;
      remove_song(top_songs, num_songs, song_remove);

      cout << "Updated data with " << song_remove << " removed:" << endl;
      cout << endl;
      display_data(top_songs, num_songs);
      break;

    case 'G':
      cout << "Enter an artist to view:\t";
      cin.ignore();
      getline(cin, artist);
      cout << endl;
      cout << "Viewing " << artist << ':' << endl;
      cout << endl;
      display_artist(top_songs, num_songs, artist);
      break;

  }
 }while(user_choice=='A' ||  user_choice=='B' || user_choice=='C' || user_choice=='D'|| user_choice=='E'|| user_choice=='F' || user_choice == 'G');

 cout << "Ending program. Thank you." << endl;
 
	return 0;
}
