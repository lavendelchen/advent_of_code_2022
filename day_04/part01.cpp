#include <string>
#include <iostream>
#include <vector>
#include <fstream>

struct Elf
{
	int	begin_section;
	int	end_section;
};

struct ElfPair
{
	Elf	first_elf;
	Elf	second_elf;

	bool	secondElfIsInFirstElf() const
	{
		if (second_elf.begin_section >= first_elf.begin_section
			&& second_elf.end_section <= first_elf.end_section)
			return true;
		return false;
	}
	bool	firstElfIsInSecondElf() const
	{
		if (second_elf.begin_section <= first_elf.begin_section
			&& second_elf.end_section >= first_elf.end_section)
			return true;
		return false;
	}

	ElfPair(int first_begin, int first_end, int second_begin, int second_end)
	{
		this->first_elf.begin_section = first_begin;
		this->first_elf.end_section = first_end;
		this->second_elf.begin_section = second_begin;
		this->second_elf.end_section = second_end;
	}
	ElfPair() {}
};

int main(void)
{
	std::ifstream			stream("input.txt");
	std::string				buffer;
	std::vector<ElfPair>	elves;
	int						useless_pairs = 0;
	
	while (getline(stream, buffer))
	{
		elves.push_back(ElfPair());
		elves.back().first_elf.begin_section = std::stoi(buffer.substr(0));
		elves.back().first_elf.end_section = std::stoi(buffer.substr(buffer.find('-')+1));
		elves.back().second_elf.begin_section = std::stoi(buffer.substr(buffer.find(',')+1));
		elves.back().second_elf.end_section = std::stoi(buffer.substr(buffer.rfind('-')+1));
	}
	for (auto elfPair : elves)
	{
		/* std::cout	<< elfPair.first_elf.begin_section << '-' << elfPair.first_elf.end_section << ','
					<< elfPair.second_elf.begin_section << '-' << elfPair.second_elf.end_section << '\n';
 */		if (elfPair.secondElfIsInFirstElf())
			useless_pairs++;
		else if (elfPair.firstElfIsInSecondElf())
			useless_pairs++;
	}
	std::cout << "useless pairs: " << useless_pairs << '\n';
}