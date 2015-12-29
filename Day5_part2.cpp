//http://adventofcode.com/day/5
#include<iostream>
#include<fstream>
#include<ostream>
#include<sstream>
#include<vector>

using namespace std;

//Fucntion prototyping for the 2 functions used
bool HasPair(string word);
bool HasRepeat(string word);

int main(){

	//Input file
	ifstream input("input.txt");
	string word = "";
	int niceStrings = 0;
	int o = 0;

	while (getline(input, word)){

		if (HasPair(word) && HasRepeat(word){
			niceStrings++;	
		}
	}
	

	cout << niceStrings;

	cin.get();
	cin.get();


}

bool HasPair(string word){

	//Splits word into combinations of 2
	//e.g Liam becomes ll, li, la, lm, il, ii.. you get the picture.
	
	//Ignores self-made pairs
	//e.g 
	//[ll]  li    la	lm
	//il   [ii]	  ia	im
	//al	ai	 [aa]	am
	//ml	mi	  ma   [mm]


	vector<string> lol;
	for (int i = 0; i < word.length(); i++){
		string group = "";
		group = word[i];
		group += word[i+1];
		lol.push_back(group);
	}

	for (int i = 0; i < lol.size(); i++){
		for (int b = 0; b < lol.size(); b++){
			if (lol[i] == lol[b] && i != b && ((i == 0 || b == 0))){
				if (lol[i] != lol[i + 1] && lol[b] != lol[b + 1]){
					cout << lol[i] << " \t";
					return true;
				}
			}
			else if (lol[i] == lol[b] && i != b && lol[i] != lol[i - 1] && lol[b] != lol[b - 1]){
				cout << lol[i] << " \t";
				return true;
			}
		}
	
	}
	
	return false;
}

bool HasRepeat(string word){
	//Loops through all characters in word, checks itself and the second character ahead if they match. -2 on word.length() to prevent index issues
	for (int i = 0; i < word.length() - 2; i++){
		if (word[i] == word[i + 2])

			return true;
	}
	return false;
}