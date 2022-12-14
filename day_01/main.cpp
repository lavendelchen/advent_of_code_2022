#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main(void)
{
	fstream	stream("input.txt");
	string	buffer;

	int	curr_elf_calories = 0;
	vector<int>	elves;
	while (getline(stream, buffer))
	{
		if (buffer.empty())
		{
			elves.push_back(curr_elf_calories);
			curr_elf_calories = 0;
		}
		else
		{
			curr_elf_calories += stoi(buffer);
			//cout << curr_elf_calories << '\n';
		}
	}
	vector<int>::iterator max = max_element(elves.begin(), elves.end());
	std::cout << "MAX ELEMENT: " << *max << '\n';

	elves.erase(max);
	max = max_element(elves.begin(), elves.end());
	std::cout << "SECOND MAX ELEMENT: " << *max << '\n';

	elves.erase(max);
	max = max_element(elves.begin(), elves.end());
	std::cout << "THIRD MAX ELEMENT: " << *max << '\n';
}

//and then use a calculator to add the three top elements together lol
