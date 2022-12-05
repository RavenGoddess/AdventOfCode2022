#pragma once
#include <map>
#include <string>
#include <vector>

void Results_Day3();

long PrioritizeItemRearrangement(const std::vector<std::string>& rucksacks, const std::map<char, int>& priorityMap);
long GetGroupBadgePriorities(const std::vector<std::string>& rucksacks, const std::map<char, int>& priorityMap);

long FindCommonItems(const std::string& rucksack, const std::map<char, int>& priorityMap);
long GetGroupBadge(const std::string group[3], const std::map<char, int>& priorityMap);

std::map<char, int> CreatePriorityMap();