#pragma once
#include <string>
#include <vector>
#include <fstream>

struct Instructions
{
	int amountOfCrates;
	int sourceStack;
	int targetStack;
};

typedef std::vector<char> Stack;

void Results_Day5();

std::string RearrangeCrates9000(const std::vector<Stack>& cratesData, const std::vector<Instructions>& instructions);
std::string RearrangeCrates9001(const std::vector<Stack>& cratesData, const std::vector<Instructions>& instructions);

std::vector<Instructions> ReadInstructions(const std::string& inputpath, std::vector<Stack>& crates);
std::vector<Stack> ReadCrateStacks(const std::vector<std::string>& cratesList);
Instructions ParseInstructions(const std::string& line);