//http://adventofcode.com/day/5
#include<iostream>
#include<fstream>
#include<ostream>
#include<sstream>
#include<vector>

using namespace std;

//Fucntion prototyping for the 3 functions used
bool HasVowels(string word);
bool HasDouble(string word);
bool NoBlacklist(string word);

int main(){

	//Input file
	ifstream input("input.txt");
	string word = "";
	int niceStrings = 0;

	//Loops through all lines in input, checks it contains 3 vowels, a double but not blacklisted
	while (getline(input, word)){
		if (HasVowels(word) && HasDouble(word) && !NoBlacklist(word))
			niceStrings++;
	}
	cout << "Done - Valid words: " << niceStrings;
	cin.get();
	cin.get();


}

bool HasVowels(string word){
	int vowelCount = 0;
	string vowels = "aeiou";

	//Nested loop through all characters in the word and all characters in vowels, checks to see if
	//the current letter is either a,e,i,o, or u. If so, add 1 to the vowelCount. Only return true is count is at least 3
	for (int i = 0; i < word.length(); i++){
		for (int v = 0; v < vowels.length(); v++)
		{
			if (word[i] == vowels[v])
				vowelCount++;
		}
	}
	if (vowelCount >= 3)
		return true;
	else
		return false;
}

bool HasDouble(string word){
	//Loops through all characters in word, checks itself and the next character if they match. -1 on word.length() to prevent index issues
	for (int i = 0; i < word.length()-1; i++){
		if (word[i] == word[i + 1])
			return true;
	}
	return false;
}

bool NoBlacklist(string word){
	//Vector containing blacklisted phrases
	vector<string> blacklist = { "ab", "cd", "pq", "xy" };

	//Once again, nested loop to check if the word contains any of the blacklisted characters
	for (int i = 0; i < blacklist.size(); i++){
		if (word.find(blacklist[i]) != string::npos) {
			cout << word << " contains " << blacklist[i] << "\n";
			return true;
		}
	}
	return false;
}