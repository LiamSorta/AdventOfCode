#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
#include <vector>
#include <algorithm>  

//Text to be read
std::ifstream infile("Text.txt");
using namespace std;

int main()
{

	vector<int> nums;
	int total = 0, length = 0, bow = 0;
	string str = "";

	//read all lines of the file
	while (getline(infile, str)){

		string word;
		stringstream stream(str);

		//Split up input text into vectors. Eg: 2x50x4 = nums[0] = 2, nums[1] = 50, nums[2] = 4
		while (getline(stream, word, 'x')){
			nums.push_back(stoi(word));
		}
		//Gift dimension calculation
		bow = nums[0] * nums[1] * nums[2];

		//Sort to get lowest values in [0] and [1]
		sort(nums.begin(), nums.end());
		length = (2 * nums[0])+(2*nums[1]);

		//dimensions + bow size
		total += (length + bow);
		nums.clear();
	}
	cout << total;

	cin.get();
	cin.get();
}