#pragma once
#include <fstream>
#include <string>
#include <vector>

void Results_Day6();

int FindPacketMarker(const std::string& datastream, bool isMessage);

bool IsSequencePacketMarker(const std::vector<char>& slidingWindow);
std::vector<char> CreateSlidingWindow(bool isMessage);
std::string ReadDatastream(const std::string& inputpath);