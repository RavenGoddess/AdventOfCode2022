#include "Day4.h"
#include "Helpers.h"

void Results_Day4()
{
	std::vector<CleaningDuty> assignments = ReadCleaningAssignments(GetInputPath(4));

	std::cout << "Day 4 results: " << GetFullyOverlappingAssignments(assignments) << ", " << GetPartiallyOverlappingAssignments(assignments) << "\n";
}

int GetFullyOverlappingAssignments(const std::vector<CleaningDuty>& assignments)
{
	int overlappingPairs = 0;

	for (auto& pair : assignments)
	{
		if (pair.elf1.sectorStart >= pair.elf2.sectorStart && pair.elf1.sectorEnd <= pair.elf2.sectorEnd)
		{
			overlappingPairs++;
		}
		else if (pair.elf1.sectorStart <= pair.elf2.sectorStart && pair.elf1.sectorEnd >= pair.elf2.sectorEnd)
		{
			overlappingPairs++;
		}
	}

	return overlappingPairs;
}

int GetPartiallyOverlappingAssignments(const std::vector<CleaningDuty>& assignments)
{
	int overlappingPairs = 0;

	for (auto& pair : assignments)
	{
		if (pair.elf2.sectorStart < pair.elf1.sectorStart && pair.elf2.sectorEnd >= pair.elf1.sectorStart)
		{
			overlappingPairs++;
		}
		else if (pair.elf2.sectorStart >= pair.elf1.sectorStart && pair.elf1.sectorEnd >= pair.elf2.sectorStart)
		{
			overlappingPairs++;
		}
	}

	return overlappingPairs;
}

std::vector<CleaningDuty> ReadCleaningAssignments(const std::string& inputpath)
{
	std::vector<CleaningDuty> assignments;
	CleaningDuty duty;

	std::ifstream input;
	input.open(inputpath);
	if (input.is_open())
	{
		std::string line;
		while (std::getline(input, line))
		{
			duty = GetCleaningDuty(line);
			assignments.push_back(duty);
		}
		input.close();
	}

	return assignments;
}

CleaningDuty GetCleaningDuty(const std::string& assignment)
{
	size_t pos = assignment.find_first_of(',');
	std::string elf1_short = assignment.substr(0, pos);
	std::string elf2_short = assignment.substr(pos+1);

	CleaningDuty parsedDuty;
	CleaningSector elfAssignment;

	pos = elf1_short.find_first_of('-');
	elfAssignment.sectorStart = std::stoi(elf1_short.substr(0, pos));
	elfAssignment.sectorEnd = std::stoi(elf1_short.substr(pos + 1));
	parsedDuty.elf1 = elfAssignment;

	pos = elf2_short.find_first_of('-');
	elfAssignment.sectorStart = std::stoi(elf2_short.substr(0, pos));
	elfAssignment.sectorEnd = std::stoi(elf2_short.substr(pos + 1));
	parsedDuty.elf2 = elfAssignment;

	return parsedDuty;
}
