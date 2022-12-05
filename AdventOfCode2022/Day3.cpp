#include "Day3.h"
#include "Helpers.h"

void Results_Day3()
{
	std::vector<std::string> rucksacks = ProcessInputGeneral(GetInputPath(3));
	std::map<char, int> priorityMap = CreatePriorityMap();

	std::cout << "Day 3 results: " << PrioritizeItemRearrangement(rucksacks, priorityMap) << ", " << GetGroupBadgePriorities(rucksacks, priorityMap) << "\n";
}

long PrioritizeItemRearrangement(const std::vector<std::string>& rucksacks, const std::map<char, int>& priorityMap)
{
	long sumOfPriorities = 0;

	for (auto rucksack : rucksacks)
	{
		sumOfPriorities += FindCommonItems(rucksack, priorityMap);
	}

	return sumOfPriorities;
}

long GetGroupBadgePriorities(const std::vector<std::string>& rucksacks, const std::map<char, int>& priorityMap)
{
	std::string group[3];
	int groupCounter = 0;
	long sumOfBadges = 0;

	for (auto rucksack : rucksacks)
	{
		if (groupCounter < 3)
		{
			group[groupCounter] = rucksack;
			groupCounter++;

			if (groupCounter == 3)
			{
				sumOfBadges += GetGroupBadge(group, priorityMap);
				groupCounter = 0;
			}
		}
	}

	return sumOfBadges;
}

long FindCommonItems(const std::string& rucksack, const std::map<char, int>& priorityMap)
{
	long sharedItemPriorities = 0;
	std::string compartment1 = rucksack.substr(0, rucksack.length() / 2);
	std::string compartment2 = rucksack.substr(rucksack.length() / 2);
	std::string sharedItems = "";

	for (auto c : compartment1)
	{
		if (compartment2.contains(c) && !sharedItems.contains(c))
		{
			sharedItemPriorities += priorityMap.find(c)->second;
			sharedItems += c;
		}
	}

	return sharedItemPriorities;
}

long GetGroupBadge(const std::string group[3], const std::map<char, int>& priorityMap)
{
	for (auto c : group[0])
	{
		if (group[1].contains(c) && group[2].contains(c))
		{
			return priorityMap.find(c)->second;
		}
	}
	return 0;
}

std::map<char, int> CreatePriorityMap()
{
	std::map<char, int> priorityMap;
	std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int priority = 1;

	for (auto c : alphabet)
	{
		priorityMap.insert(std::pair<char, int>(c, priority));
		priority++;
	}

	return priorityMap; // should I pass a reference?
}