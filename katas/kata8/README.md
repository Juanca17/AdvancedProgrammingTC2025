# Kata 8
###### Inflight Entertainment System
### Context
You've built an inflight entertainment system with on-demand movie streaming. Users on longer flights like to start a second movie right when their first one ends, but they complain that the plane usually lands before they can see the ending. **So you're building a feature for choosing two movies whose total runtimes will equal the exact flight length.**

Write a function that takes an integer flight_length (in minutes) and a list of integers movie_lengths (in minutes) and returns a boolean indicating whether there are two numbers in movie_lengths whose sum equals flight_length.  

When building your function:
  - Assume your users will watch exactly two movies  
  - Don't make your users watch the same movie twice  
  - Optimize for runtime over memory

### Input
The input consists of two lines. The first contains two space-separated integers **flight_length** and **M** (the number of movies in the list). The second line contains the movie lengths in minutes **movie_lengths<sub>0</sub>**, **movie_lengths<sub>1</sub>**, ..., **movie_lengths<sub>M</sub>**.

### Output
The output is one line containing ```true``` or ```false``` depending on the case.

### Sample
```
170 9
80 180 120 150 90 115 120 110 100
```
```
output  
true
```

### Break Down
The first obvious solution that came into my mind was to compare every movie with the rest to see if there is a pair that meets the requirements. In such a case this could be a very simple implementation but it fails to ```optimize for runtime over memory```. What can it be done? Well, if every movie_length was mapped with itself it can be efficiently compare if there is a remaining time movie that make a pair.

### Solution
```
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
```

### Analysis
This algorithm runs in ```O(log n)``` since thats the complexity of the functions of **map** and they are called in constant time.

### Deployment
To run the **Sample input** test  
```
make test
```
