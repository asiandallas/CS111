#include <string>
using namespace std;

struct Spotify{ // only top 10 songs
  string song_title,artist;
  int minute,second;
  char colon; // for min:sec
  int plays_a_month[4]; // number of times song played in jan-april 
};

bool collect_data(Spotify arr[], int& n);
void collect_one_song(ifstream& input, Spotify& s);

void display_data(const Spotify arr[], int n);

void sort_by_plays_january(Spotify arr[], int n);
void sort_by_artist(Spotify arr[], int n);

int total_plays(Spotify s);
double average_month(Spotify s);
void display_total_plays(const Spotify arr[], int n);

string most_played(Spotify arr[], int n, int x);
string least_played(const Spotify arr[], int n, int x);
void display_most_least_played(const Spotify arr[], int n);

void error_message(string song);
void remove_song(Spotify arr[], int& n, string song);

void display_artist(Spotify arr[], int n, string artist);
