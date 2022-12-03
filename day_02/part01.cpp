#include <fstream>
#include <iostream>
#include <map>

enum scores {
	LOSE = 0,
	DRAW = 3,
	WIN = 6
};

enum rpss {
	ROCK = 1,
	PAPER = 2,
	SCISSORS = 3
};

typedef std::map<std::pair<char, char>, int> rps_map_t;

auto get_rps()
{
	rps_map_t rps = {
		{{'A', 'X'}, 1},
		{{'B', 'Y'}, 2},
		{{'C', 'Z'}, 3}
	};

	return rps;
}

void	get_input(std::fstream& in_stream, std::multimap<char, char>& rounds)
{
	std::string buffer;

	while (std::getline(in_stream, buffer))
	{
		rounds.emplace(buffer[0], buffer[2]);
	}
}

int	which_score(rps_map_t::iterator ours, rps_map_t::iterator opps)
{
	if (ours->second == ROCK && opps->second == PAPER)
		return LOSE;
	if (ours->second == ROCK && opps->second == SCISSORS)
		return WIN;
	if (ours->second == PAPER && opps->second == ROCK)
		return WIN;
	if (ours->second == PAPER && opps->second == SCISSORS)
		return LOSE;
	if (ours->second == SCISSORS && opps->second == ROCK)
		return LOSE;
	if (ours->second == SCISSORS && opps->second == PAPER)
		return WIN;
	return DRAW;
	return 69;
}

int main()
{
	std::fstream in_stream("input.txt");

	auto rps = get_rps();
	std::multimap<char, char>	rounds;
	get_input(in_stream, rounds);

	int	total_score = 0;

	for (const auto &round : rounds)
	{
		auto ours = rps.find(std::make_pair(round.second -23, round.second));
		auto opps = rps.find(std::make_pair(round.first, round.first + 23));

		total_score += ours->second;
		total_score += which_score(ours, opps);
	}
	std::cout << "TOTAL SCORE: " << total_score << '\n';
}
