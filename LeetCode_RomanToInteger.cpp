// LeetCode_RomanToInteger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <regex>

using namespace std;

/*
I             1
IV		      4
V             5
IX            9
X             10
XL            40
L             50
XC            90
C             100
CD            400
D             500
CM            900
M             1000
*/

int romanToInt(string s) {

	int result = 0;
	char previous = '-';
	char next = '+';
	bool double_continue = false;

	for (size_t c = 0; c < s.length(); c++)
	{
		char current = s[c];

		int p = c - 1;
		if (p > 0) {
			previous = s[p];
		}

		int n = c + 1;
		if (n < s.length()) {
			next = s[n];
		}

		//cout << " cur: " << current << " c: " << c << " p: " << p << " n: " << n << "\n";

		// ¦A¦¸ continue
		if (double_continue) {
			double_continue = false;
			continue;
		}
		else if (current == 'I' && next == 'V') {
			result += 4;
			double_continue = true;
			continue;
		}
		else if (current == 'I' && next == 'X') {
			result += 9;
			double_continue = true;
			continue;
		}
		else if (current == 'X' && next == 'L') {
			result += 40;
			double_continue = true;
			continue;
		}
		else if (current == 'X' && next == 'C') {
			result += 90;
			double_continue = true;
			continue;
		}
		else if (current == 'C' && next == 'D') {
			result += 400;
			double_continue = true;
			continue;
		}
		else if (current == 'C' && next == 'M') {
			result += 900;
			double_continue = true;
			continue;
		}
		else if (current == 'I') {
			result += 1;
			continue;
		}
		else if (current == 'V') {
			result += 5;
			continue;
		}
		else if (current == 'X') {
			result += 10;
			continue;
		}
		else if (current == 'L') {
			result += 50;
			continue;
		}
		else if (current == 'C') {
			result += 100;
			continue;
		}
		else if (current == 'D') {
			result += 500;
			continue;
		}
		else if (current == 'M') {
			result += 1000;
			continue;
		}
	}

	return result;
}

int main()
{
	string input = "MCMXCIV";
	//getline(cin, input);;
	cout << "Hello World! Roman: " << input << " To Int: " << romanToInt(input);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
