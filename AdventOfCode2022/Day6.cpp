#include "Day6.h"
#include "Helpers.h"

void Results_Day6()
{
	std::string datasteam = ReadDatastream(GetInputPath(6));

	std::cout << "Day 6 results: " << FindPacketMarker(datasteam, false) << ", " << FindPacketMarker(datasteam, true) << "\n";

}

int FindPacketMarker(const std::string& datastream, bool isMessage)
{
	std::vector<char> slidingWindow = CreateSlidingWindow(isMessage);
	int index = slidingWindow.size() - 1;
	int charactersPassed = 0;

	for (auto& elem : datastream)
	{
		std::rotate(slidingWindow.begin(), slidingWindow.begin() + 1, slidingWindow.end());
		slidingWindow[index] = elem;
		charactersPassed++;

		if (charactersPassed > index && IsSequencePacketMarker(slidingWindow))
		{
			return charactersPassed;
		}
	}

	return 0;
}

bool IsSequencePacketMarker(const std::vector<char>& slidingWindow)
{
	int i = 0;
	int max = slidingWindow.size();

	for (i; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			if (j > i)
			{
				if (slidingWindow[i] == slidingWindow[j])
				{
					return false;
				}
			}
		}
	}

	return true;
}

std::vector<char> CreateSlidingWindow(bool isMessage)
{
	std::vector<char> slidingWindow;
	int length = isMessage ? 14 : 4;

	for (int i = 0; i < length; i++)
	{
		slidingWindow.push_back('0');
	}

	return slidingWindow;
}

std::string ReadDatastream(const std::string& inputpath)
{
	std::ifstream input;
	std::string datastream = "";
	input.open(inputpath);
	if (input.is_open())
	{
		std::string line;
		while (std::getline(input, line))
		{
			datastream += line;
		}
		input.close();
	}

	return datastream;
}
