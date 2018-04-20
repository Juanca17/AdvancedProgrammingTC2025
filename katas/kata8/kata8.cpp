#include <cstdio>
#include <vector>
#include <map>
using namespace std;

bool twoMoviesAvailable(int flight_length, int * movie_lengths, int M) {
  map<int, int> movie_lenghts_map;

  for (int i = 0; i < M; i++) {
    if(movie_lengths[i] < flight_length) {
			movie_lenghts_map.insert(make_pair(movie_lengths[i], i+1));
		}
  }

  for (int i = 0; i < sizeof(movie_lengths)/sizeof(int); i++) {
    int remaining = flight_length - movie_lengths[i];

    if (movie_lenghts_map[remaining] && movie_lenghts_map[remaining] - 1 != i) {
      return true;
    }
  }

  return false;
}

int main(int argc, char const *argv[]) {
  int flight_length, M;
  scanf("%d %d", &flight_length, &M);

int movie_lengths[M];
  int ml;
  for (int i = 0; i < M; i++) {
    scanf("%d",&ml);
    movie_lengths[i] = ml;
  }

  printf("%s\n", twoMoviesAvailable(flight_length,  movie_lengths, M) ? "true" : "false");
  return 0;
}
