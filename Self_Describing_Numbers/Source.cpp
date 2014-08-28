#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;
using std::atoi;

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line;
	while (getline(ifs, line))
	{
		int self_describing_flag;
		// Cycle through each number in string comparing the digit to the number of times its position number appears
		for (size_t i = 0; i < line.size(); i++)
		{
			// Convert char to int
			int digit = line[i] - '0';
			int number_of_appearances = 0;

			// Cycle through string obtaining number of appearances 
			for (auto c : line)
			{
				// Convert char to int
				c -= '0';
				if (c == i)
				{
					++number_of_appearances;
				}
			}
			// Compare number of appearances to the digit and set flag accordingly
			if (number_of_appearances == digit)
			{
				self_describing_flag = 1;
			}
			else
			{
				self_describing_flag = 0;
				break;
			}
		}
		cout << self_describing_flag << endl;
	}

	return 0;
}