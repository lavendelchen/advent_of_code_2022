#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <cctype>

int main(void)
{
	std::ifstream										stream("input.txt");
	std::string											buffer;
	std::vector<std::pair<std::string, std::string>>	rucksacks;
	int													sum = 0;

	while (getline(stream, buffer))
	{
		rucksacks.push_back(make_pair(buffer.substr(0, buffer.size()/2), buffer.substr(buffer.size()/2)));
	}
	for (auto rucksack : rucksacks)
	{
		//std::cout << rucksack.first << ' ' << rucksack.second << '\n';
		for (auto item : rucksack.first)
		{
			if (rucksack.second.find(item) != std::string::npos)
			{
				if (islower(item))
					sum += (item - 96);
				if (isupper(item))
					sum += (item - 38);
				break ;
			}
		}
	}
	std::cout << "SUM OF PRIORITIES: " << sum << '\n';
}