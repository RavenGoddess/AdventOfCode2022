#include "Day2.h"
#include "Helpers.h"

void Results_Day2()
{
	std::vector<GameRound> strategyGuide = ReadStrategyGuide(GetInputPath(2));
	std::cout << "Day 2 results: " << EvaluateStrategyGuide(strategyGuide, false) << ", " << EvaluateStrategyGuide(strategyGuide, true) << "\n";
}

long EvaluateStrategyGuide(const std::vector<GameRound>& strategyGuide, const bool key)
{
	long sumOfPoints = 0;

	for (auto& round : strategyGuide)
	{
		sumOfPoints += EvaluateGameRound(round, key);
	}

	return sumOfPoints;
}

long EvaluateGameRound(const GameRound& round, const bool key)
{
	long roundScore = 0;

	roundScore += EvaluatePointsForShape(round, key);
	roundScore += EvaluatePointsForOutcome(round, key);

	return roundScore;
}

long EvaluatePointsForShape(const GameRound& round, const bool key)
{
	if (key)
	{
		if (round.ourMove == 'X')
		{
			GivePointsForShape(GetLosingShape(round.opponentMove));
		}
		else if (round.ourMove == 'Y')
		{
			GivePointsForShape(round.opponentMove);
		}
		else if (round.ourMove == 'Z')
		{
			GivePointsForShape(GetWinningShape(round.opponentMove));
		}
	}
	else
	{
		if (round.ourMove == 'X')
		{
			return 1;
		}
		else if (round.ourMove == 'Y')
		{
			return 2;
		}
		else if (round.ourMove == 'Z')
		{
			return 3;
		}
	}

	return 0;
}

long EvaluatePointsForOutcome(const GameRound& round, const bool key)
{
	if (key)
	{
		 if (round.ourMove == 'Y')
		{
			return 3;
		}
		else if (round.ourMove == 'Z')
		{
			return 6;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		GivePointsForOutcome(round);
	}
}

char GetWinningShape(const char move)
{
	if (move == 'A')
	{
		return 'B';
	}
	else if (move == 'B')
	{
		return 'C';
	}
	else if (move == 'C')
	{
		return 'A';
	}

	return '0';
}

char GetLosingShape(const char move)
{
	if (move == 'A')
	{
		return 'C';
	}
	else if (move == 'B')
	{
		return 'A';
	}
	else if (move == 'C')
	{
		return 'B';
	}
	return '0';
}

long GivePointsForShape(const char move)
{
	if (move == 'A')
	{
		return 1;
	}
	else if (move == 'B')
	{
		return 2;
	}
	else if (move == 'C')
	{
		return 3;
	}

	return 0;
}

long GivePointsForOutcome(const GameRound& round)
{
	if (WinningCondition(round))
	{
		return 6;
	}
	else if (DrawCondition(round))
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

bool WinningCondition(const GameRound& round)
{
	if ( round.opponentMove == 'A' && round.ourMove == 'Y')
	{
		return true;
	}
	else if (round.opponentMove == 'B' && round.ourMove == 'Z')
	{
		return true;
	}
	else if (round.opponentMove == 'C' && round.ourMove == 'X')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool DrawCondition(const GameRound& round)
{
	if (round.opponentMove == 'A' && round.ourMove == 'X')
	{
		return true;
	}
	else if (round.opponentMove == 'B' && round.ourMove == 'Y')
	{
		return true;
	}
	else if (round.opponentMove == 'C' && round.ourMove == 'Z')
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::vector<GameRound> ReadStrategyGuide(const std::string& inputpath)
{
	std::vector<GameRound> strategyGuide;
	GameRound currentRound;

	std::ifstream input;	
	input.open(inputpath);
	if (input.is_open())
	{
		std::string line;
		while (std::getline(input, line))
		{
			currentRound.opponentMove = line.at(0);
			currentRound.ourMove = line.at(2);

			strategyGuide.push_back( currentRound );
		}
		input.close();
	}

	return strategyGuide;
}

