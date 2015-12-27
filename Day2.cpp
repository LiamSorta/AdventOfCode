//http://adventofcode.com/day/2
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
	//num vector for storing the intitally read numers
	//post vector for calculating areas
	vector<int> nums, post;
	int total = 0;
	string str = "";

	//read all lines of the file
	while (getline(infile, str)){

		string word;
		stringstream stream(str);
		
		//Split up input text into vectors. Eg: 2x50x4 = nums[0] = 2, nums[1] = 50, nums[2] = 4
		while (getline(stream, word, 'x')){
			nums.push_back(stoi(word));
			//Pad out post vector
			post.push_back(0);
		}
		//Calcs for L*W*H, done via 0, 1 and 2 respectively
		post[0] = nums[0] * nums[1];
		post[1] = nums[1] * nums[2];
		post[2] = nums[2] * nums[0];

		//Total square feet + smallest side
		total += (2*post[0]) + (2*post[1]) + (2*post[2]) + *min_element(post.begin(), post.end());

		nums.clear();
		post.clear();
	}
	cout << total;

	cin.get();
	cin.get();
}
