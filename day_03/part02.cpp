#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cctype>

int main(void)
{
	std::ifstream				stream("input.txt");
	std::string					buffer;
	std::vector<std::string>	elves;
	int							sum = 0;

	while (getline(stream, buffer))
		elves.push_back(buffer);
	for (auto i = elves.begin(); i != elves.end(); i += 3)
	{
		for (auto badge : *i)
		{
			if ((i+1)->find(badge) != std::string::npos)
			{
				if ((i+2)->find(badge) != std::string::npos)
				{
					if (islower(badge))
						sum += (badge - 96);
					if (isupper(badge))
						sum += (badge - 38);
					break ;
				}
			}
		}
	}
	std::cout << "SUM OF BADGES: " << sum << '\n';
}