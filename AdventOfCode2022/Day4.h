#pragma once
#include <fstream>
#include <string>
#include <vector>

struct CleaningSector {
    int sectorStart = 0;
    int sectorEnd = 0;
};

struct CleaningDuty {
    CleaningSector elf1;
    CleaningSector elf2;
};

void Results_Day4();

int GetFullyOverlappingAssignments(const std::vector<CleaningDuty>& assignments);
int GetPartiallyOverlappingAssignments(const std::vector<CleaningDuty>& assignments);

std::vector<CleaningDuty> ReadCleaningAssignments(const std::string& inputpath);
CleaningDuty GetCleaningDuty(const std::string& assignment);