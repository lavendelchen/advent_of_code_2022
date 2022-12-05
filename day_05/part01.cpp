#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <algorithm>


typedef std::vector<std::vector<char>>::iterator crates_iter_t;

int main(void)
{
	std::ifstream					stream("input.txt");
	std::string						buffer;
	std::vector<std::vector<char>>	crates;

	int	stack_count = 0;
	int	num_of_stacks;
	for (int i = 0; getline(stream, buffer); i++)
	{
		if (buffer[1] == '1')
			break ;
		if (i == 0)
		{
			num_of_stacks = (buffer.size() + 1) / 4;
			for (int i = 0; i < num_of_stacks; i++) {
				crates.push_back(std::vector<char>());
			}
		}
		for (crates_iter_t stack = crates.begin(); stack != crates.end(); stack++) {
			if (buffer[1 + (stack_count * 4)] != ' ')
				stack->push_back(buffer[1 + (stack_count * 4)]);
			stack_count++;
		}
		stack_count = 0;
	}
	for (crates_iter_t stack = crates.begin(); stack != crates.end(); stack++)
	{
		std::reverse(stack->begin(), stack->end());
	}
	getline(stream, buffer);
	int	crates_to_move;
	int	from_stack;
	int	to_stack;
	while (getline(stream, buffer))
	{
		crates_to_move = std::stoi(buffer.substr(buffer.find("move")+5));
		from_stack = std::stoi(buffer.substr(buffer.find("from")+5))-1;
		to_stack = std::stoi(buffer.substr(buffer.find("to")+3))-1;
		for (int i = 0; i < crates_to_move; i++)
		{
			crates[to_stack].push_back(crates[from_stack].back());
			crates[from_stack].pop_back();
		}
	}
	for (auto stack : crates)
	{
		std::cout << stack.back();
	}
	std::cout << '\n';
}