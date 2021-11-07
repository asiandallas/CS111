#include <iostream>
#include <fstream>
#include <iomanip>
#include "library.h"
using namespace std;

void collect_one_song(ifstream& file_input, Spotify& s){
  file_input.ignore(1000,'\n');
  getline(file_input,s.song_title,',');
  getline(file_input,s.artist,',');
  file_input >> s.minute;
  file_input >> s.colon;
  file_input >> s.second;

  for(int i=0; i<4; i++){
    file_input >> s.plays_a_month[i];
  }
}

bool collect_data(Spotify arr[], int& n){
  ifstream file_input("input.dat");
  if(!file_input.is_open()){
    cout << "Error: Cannot open file." << endl;
    return false;
  }
  while(!file_input.eof()){ 
    collect_one_song(file_input,arr[n]);
    n++;
  }
   file_input.close();
   return true;
  }

void display_data(const Spotify arr[], int n){
  cout << left;
  cout << setw(20) << "Song" << setw(20) << "Artist" << setw(15) << "Duration";
  cout << setw(20) << "Total Plays (Jan, Feb, Mar, Apr)" << endl;
  cout << "============================================================================================" << endl; 
  
  for (int j = 0; j < n; j++) {
    cout << setw(20) << arr[j].song_title;
    cout << setw(20) << arr[j].artist;
    cout << arr[j].minute << arr[j].colon<< arr[j].second;
    cout << setw(12) << " ";
      for (int i = 0; i<4; i++) {
        cout << setw(4) << arr[j].plays_a_month[i] << " ";
    }
  cout << endl;
  }
}

void sort_by_plays_january(Spotify arr[], int n){
  for(int j=1; j<n; j++){
    for(int i=j; i>0&& arr[i-1].plays_a_month[0] < arr[i].plays_a_month[0];i--){
      swap(arr[i - 1], arr[i]);
    }
  }
}

void sort_by_artist(Spotify arr[], int n){
  for(int j=1; j<n; j++){
    for(int i=j; i>0&& arr[i-1].song_title > arr[i].song_title;i--){
      swap(arr[i - 1], arr[i]);
    }
  }
}

int total_plays(Spotify s){
  int num_plays = 0;
  for(int i=0; i<4; i++){
    num_plays += s.plays_a_month[i];
  }
  return num_plays;
}

double average_month(Spotify s){
  double total_plays, average = 0;
  for(int i=0; i<4; i++){
    total_plays += s.plays_a_month[i];
  }
  average = total_plays/4;
  return average;
}

void display_total_plays(const Spotify arr[], int n){
  cout << left;
  cout << setw(20) << "Song" << setw(20) << "Artist";
  cout << setw(20) << "Total Plays";
  cout << setw(20) << "Average Plays" << endl;
  cout << "===============================================================================" << endl;

  for (int j = 0; j < n; j++) {
    cout << setw(20) << arr[j].song_title;
    cout << setw(20) << arr[j].artist;
    cout << setw(20) << total_plays(arr[j]);

    cout << fixed << showpoint << setprecision(1); 
    cout << setw(20) << average_month(arr[j]) << endl;
  }
  cout << endl;
}

string most_played(const Spotify arr[], int n, int x){
  int highest = 0;
  string mostPlayed_song;
  for(int j=0; j<n; j++){
    if(highest<arr[j].plays_a_month[x]){
      highest = arr[j].plays_a_month[x];
      mostPlayed_song = arr[j].song_title;
    }
  }
    return mostPlayed_song; 
}

string least_played(const Spotify arr[], int n, int c){ // c for column
  int lowest = 9999;
  string leastPlayed_song;
  for(int j=0; j<n; j++){
    if(lowest>arr[j].plays_a_month[c]){
      lowest = arr[j].plays_a_month[c];
      leastPlayed_song = arr[j].song_title;
    }
  }
  return leastPlayed_song; 
}

void display_most_least_played(const Spotify arr[], int n){
  cout << left;
  cout << setw(10) << "Month" << setw(25) << "Most played song";
  cout << setw(25) << "Least played song" << endl;
  cout << "==========================================================" << endl;
  for (int j = 0; j < 4; j++) {
    cout << setw(10) << j+1;
    cout << setw(25) << most_played(arr,n,j);
    cout << setw(25) << least_played(arr,n,j) << endl;
  }
  cout << endl;
}

void error_message(string song){
  cout << "ERROR: " << song << "  was not found." << endl;
}

void remove_song(Spotify arr[], int& n, string song){
  int pos = n; 
  bool found = false;

  for(int i=0; i<n && !found; i++){ // to find position of song
    if(song == arr[i].song_title){
      found = true;
      pos = i;
    }
  }

  if(found){
    for(int i=pos; i<n-1; i++){ 
      arr[i].song_title = arr[i+1].song_title;
      arr[i].artist = arr[i+1].artist;
      arr[i].minute = arr[i+1].minute;
      arr[i].colon = arr[i+1].colon;
      arr[i].second = arr[i+1].second;
      for(int j=0; j<4; j++){
        arr[i].plays_a_month[j] = arr[i+1].plays_a_month[j];
      }
    }
    n--;
  }
  else{
    error_message(song);
  }
}

void display_artist(Spotify arr[], int n, string artist){
  cout << left;
  cout << setw(20) << "Song" << setw(20) << "Artist" << setw(15) << "Duration";
  cout << setw(20) << "Total Plays (Jan, Feb, Mar, Apr)" << endl;
  cout << "============================================================================================" << endl; 

  for(int j=0; j<n; j++){
    if(arr[j].artist == artist){
      cout << setw(20) << arr[j].song_title;
      cout << setw(20) << arr[j].artist;
      cout << arr[j].minute << arr[j].colon<< arr[j].second;
      cout << setw(12) << " ";

      for(int i=0; i<4; i++){
        cout << setw(4) << arr[j].plays_a_month[i] << " ";
      }
      cout << endl;
    }
  }
}