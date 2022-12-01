#pragma once
#include <string>
#include <vector>
#include <fstream>

int Day1();

long GetCalorieCount(const std::vector<long>& calorieSummaries);
long GetCalorieCountSummary(const std::vector<long>& calorieSummaries);
std::vector<long> ProcessInput(const std::string& inputpath);