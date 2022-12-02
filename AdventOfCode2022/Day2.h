#pragma once
#include <fstream>
#include <vector>

struct GameRound {
    char opponentMove;
    char ourMove;
};

void Results_Day2();

long EvaluateStrategyGuide(const std::vector<GameRound>& strategyGuide, const bool key);
long EvaluateGameRound(const GameRound& round, const bool key);

long EvaluatePointsForShape(const GameRound& round, const bool key);
long EvaluatePointsForOutcome(const GameRound& round, const bool key);
long GivePointsForShape(const char move);
long GivePointsForOutcome(const GameRound& round);

char GetWinningShape(const char move);
char GetLosingShape(const char move);
bool WinningCondition(const GameRound& round);
bool DrawCondition(const GameRound& round);

std::vector<GameRound> ReadStrategyGuide(const std::string& inputpath);
