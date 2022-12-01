#include "Day1.h"
#include "Helpers.h"

int Day1()
{
	std::vector<long> calorieSummaries = ProcessInput(GetInputPath(1));

	std::cout << "Day 1 results: " << GetCalorieCount(calorieSummaries) << ", " << GetCalorieCountSummary(calorieSummaries) << "\n";
	return 0;
}

long GetCalorieCount(const std::vector<long>& calorieSummaries)
{
	long maxCalorieCount = 0;

	for (auto& elf : calorieSummaries)
	{
		if ( elf > maxCalorieCount )
		{
			maxCalorieCount = elf;
		}
	}

	return maxCalorieCount;
}

long GetCalorieCountSummary(const std::vector<long>& calorieSummaries)
{
	long maxCalories[3] = {0,0,0};

	for (auto& elf : calorieSummaries)
	{
		if ( elf > maxCalories[0] )
		{
			maxCalories[2] = maxCalories[1];
			maxCalories[1] = maxCalories[0];
			maxCalories[0] = elf;
		}
		else if ( elf > maxCalories[1] && elf <= maxCalories[0])
		{
			maxCalories[2] = maxCalories[1];
			maxCalories[1] = elf;
		}
		else if ( elf > maxCalories[2] && elf <= maxCalories[1])
		{
			maxCalories[2] = elf;
		}
	}

	return maxCalories[0] + maxCalories[1] + maxCalories[2];
}

std::vector<long> ProcessInput(const std::string& inputpath)
{
	std::ifstream input;
	std::string line;
	long elfCalorieCount = 0;
	std::vector<long> calorieSummaries;

	input.open(inputpath);
	if (input.is_open())
	{
		while (std::getline(input, line))
		{
			if ( !line.empty() )
			{
				long calories = std::stol(line);
				elfCalorieCount += calories;
			}
			else
			{
				calorieSummaries.push_back(elfCalorieCount);
				elfCalorieCount = 0;
			}
		}
		input.close();
	}

	if (elfCalorieCount != 0)
	{
		calorieSummaries.push_back(elfCalorieCount);
	}

	return calorieSummaries;
}
