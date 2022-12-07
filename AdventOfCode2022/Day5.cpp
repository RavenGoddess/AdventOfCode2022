#include "Day5.h"
#include "Helpers.h"

void Results_Day5()
{
	std::vector<Stack> crates;
	std::vector<Instructions> instructions = ReadInstructions(GetInputPath(5), crates);

	std::cout << "Day 5 results: " << "\n";
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
	move.sourceStack = std::stoi(number);

	start = line.find(' ', end + 1) + 1;
	end = line.length();
	number = line.substr(start, end - start);
	move.targetStack = std::stoi(number);

	return Instructions();
}

std::vector<Stack> ReadCrateStacks(const std::vector<std::string>& cratesList)
{
	std::vector<Stack> allStacks;
	Stack currentStack = { 'Z', 'N' };
	allStacks.push_back(currentStack);

	currentStack = { 'M', 'C', 'D' };
	allStacks.push_back(currentStack);

	currentStack = { 'P' };
	allStacks.push_back(currentStack);

	for (int i = 1; i < cratesList.size(); i++)
	{
	}

	return allStacks;
}