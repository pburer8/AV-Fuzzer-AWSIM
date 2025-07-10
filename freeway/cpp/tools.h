#ifndef TOOLS_INCL
#define TOOLS_INCL

#include <vector>
#include <npcstruct.h>

float getSimilarityBetweenNpcs(std::vector<Npc> npc1, std::vector<Npc> npc2);
float getSimilarityBetweenScenarios(std::vector<std::vector<Npc>> scenario1, std::vector<std::vector<Npc>> scenario2);

#endif