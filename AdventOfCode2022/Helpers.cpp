#include "Helpers.h"
#include <filesystem>
#include <fstream>

std::string GetInputPath(int day)
{
	bool test = false;
	std::filesystem::path p = std::filesystem::current_path().parent_path();
	std::string path = p.string() + "\\input\\day" + std::to_string(day);

	if (test)
	{
		path += "test";
	}
	path += ".txt";

	return path;
}

std::vector<std::string> ProcessInputGeneral(const std::string &inputpath)
{
	std::ifstream input;
	std::string line;
	std::vector<std::string> result;

	input.open(inputpath);
	if (input.is_open())
	{
		while (std::getline(input, line))
		{
			result.push_back(line);
		}
		input.close();
	}

	return result;
}
