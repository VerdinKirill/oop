#include "Randomizer.h"

Randomizer::Randomizer(int start, int end)
    : gen(std::chrono::steady_clock::now().time_since_epoch().count()),
    distr(start, end){};

int Randomizer::getRandomInt()
{
	return distr(gen);
}