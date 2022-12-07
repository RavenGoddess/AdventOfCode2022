#include "Day5.h"
#include "Helpers.h"

void Results_Day5()
{
	std::vector<Stack> crates;
	std::vector<Instructions> instructions = ReadInstructions(GetInputPath(5), crates);

	std::cout << "Day 5 results: " << RearrangeCrates9000(crates, instructions) << ", " << RearrangeCrates9001(crates, instructions) << "\n";
}

std::string RearrangeCrates9000(const std::vector<Stack>& cratesData, const std::vector<Instructions>& instructions)
{
	std::vector<Stack> crates = cratesData;
	std::string cratesOnTop = "";
	for (auto& move : instructions)
	{
		for (int i = 0; i < move.amountOfCrates; i++)
		{
			crates[move.targetStack].push_back(crates[move.sourceStack].back());
			crates[move.sourceStack].pop_back();
		}
	}

	for (size_t i = 0; i < crates.size(); i++)
	{
		cratesOnTop += crates[i].back();
	}

	return cratesOnTop;
}

std::string RearrangeCrates9001(const std::vector<Stack>& cratesData, const std::vector<Instructions>& instructions)
{
	std::vector<Stack> crates = cratesData;
	std::string cratesOnTop = "";
	for (auto& move : instructions)
	{
		int index = crates[move.sourceStack].size() - move.amountOfCrates;
		for (int i = 0; i < move.amountOfCrates; i++)
		{
			crates[move.targetStack].push_back(crates[move.sourceStack][index]);
			index++;
		}

		for (int i = 0; i < move.amountOfCrates; i++)
		{
			crates[move.sourceStack].pop_back();
		}
	}

	for (size_t i = 0; i < crates.size(); i++)
	{
		cratesOnTop += crates[i].back();
	}

	return cratesOnTop;
}

std::vector<Instructions> ReadInstructions(const std::string& inputpath, std::vector<Stack>& crates)
{
	std::vector<Instructions> instructions;
	std::vector<std::string> cratesList;
	std::ifstream input;
	std::string line;

	bool instructionStart = false;

	input.open(inputpath);
	if (input.is_open())
	{
		while (std::getline(input, line))
		{
			if (line.empty())
			{
				instructionStart = true;
			}
			else if (instructionStart)
			{
				instructions.push_back(ParseInstructions(line));
			}
			else
			{
				cratesList.push_back(line);
			}
		}
		input.close();
	}

	std::reverse(cratesList.begin(), cratesList.end());
	crates = ReadCrateStacks(cratesList);

	return instructions;
}

Instructions ParseInstructions(const std::string& line)
{
	Instructions move;

	int start = line.find(' ') + 1;
	int end = line.find(' ', start);
	std::string number = line.substr(start, end-start);
	move.amountOfCrates = std::stoi(number);

	start = line.find(' ', end+1) + 1;
	end = line.find(' ', start);
	number = line.substr(start, end - start);
	move.sourceStack = std::stoi(number)-1;		//vector index starting from 0, input starts from 1

	start = line.find(' ', end + 1) + 1;
	end = line.length();
	number = line.substr(start, end - start);
	move.targetStack = std::stoi(number)-1;

	return move;
}

std::vector<Stack> ReadCrateStacks(const std::vector<std::string>& cratesList)
{
	std::vector<Stack> allStacks;

	for (size_t i = 1; i < cratesList.size(); i++)
	{
		size_t found = 0;
		size_t position = 0;
		if (allStacks.size() == 0)
		{
			found = cratesList[i].find('[');
			while (found != std::string::npos)
			{
				position = found + 1;
				Stack currentStack = { cratesList[i].at(position) };
				allStacks.push_back(currentStack);
				found = cratesList[i].find('[', position);
			}
		}
		else
		{
			found = cratesList[i].find('[');
			while (found != std::string::npos)
			{
				position = found + 1;
				int index = found / 4;
				allStacks[index].push_back(cratesList[i].at(position));
				found = cratesList[i].find('[', position);
			}
		}
	}

	return allStacks;
}