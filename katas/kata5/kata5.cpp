#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iterator>
#include <stdio.h>
#include <ctype.h>
using namespace std;

void doInfographic(char *source);
void cleanWord(string &word);

int main() {
  string s = "'After beating the eggs, Dana read the next step:'''''' Add milk and eggs, then add flour and sugar.'";
  char source[] = "kata5.txt";
  ofstream myfile;
  myfile.open (source);
  myfile << s;
  myfile.close();
  doInfographic(source);
}

void doInfographic(char *source) {
  ifstream file;
	file.open(source);
	char word[50];
  string wordS;
  map<string, int> wordMap;
  int rep = 0;
	while(!file.eof()) {
		file >> word;
    wordS = word;
    cleanWord(wordS);
    if(wordMap.insert(make_pair(wordS, 1)).second == false) {
      // "Element with key 'wordS' not inserted because already existed"
      rep = wordMap[wordS];
      wordMap[wordS] = rep + 1;
    }
	}

  cout << "Word >> " << "Value" << endl;
  cout << "-------------" << endl;
  // Iterate through all elements in map
  map<string, int>::iterator it = wordMap.begin();
  while(it != wordMap.end()) {
    cout<<it->first<<" >> "<<it->second<<endl;
    it++;
  }
	file.close();
}

void cleanWord(string &word) {
  int i = 0;
  while (isalpha(word[i]) == 0) {
    i++;
  }
  word = word.substr(i,word.size());
  i = word.size();
  while (isalpha(word[i-1]) == 0) {
    i--;
  }
  word = word.substr(0,i);
  transform(word.begin(), word.end(), word.begin(),(int (*)(int))tolower);
}
