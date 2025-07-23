#include <tools.h>
#include <cmath>
#include "npcstruct.h"
#include <vector>

float getSimilarityBetweenNpcs(std::vector<Npc> npc1, std::vector<Npc> npc2)
{
    float accumD = 0.f;
    float horD1 = 0.f;
    float horD2 = 0.f;
    float v1 = 0.f;
    float v2 = 0.f;

    int len = npc1.size();

    for (int i = 0; i < len; i++)
    {
        v1 += npc1[i].v;
        v2 += npc2[i].v;

        int a1 = npc1[i].a;
        int a2 = npc2[i].a;

        if (a1 == 1)
        {
            horD1 += -34.0;
        } else if (a1 == 2)
        {
            horD1 += 34.0;
        }

        if (a2 == 1)
        {
            horD2 += -34.0;
        } else if (a2 == 2)
        {
            horD2 += 34.0;
        }

        float curED = sqrt(pow(v1 - v2, 2) + pow(horD1 - horD2, 2));
        accumD += curED;
    }

    return accumD;
}

float getSimilarityBetweenScenarios(std::vector<std::vector<Npc>> scenario1, std::vector<std::vector<Npc>> scenario2)
{
    int npcSize = scenario1.size();
    int timeSize = scenario1[0].size();

    float scenarioNpc = 0.f;

    for (int i = 0; i < npcSize; i++)
    {
        std::vector<Npc> npc1 = scenario1[i];
        std::vector<Npc> npc2 = scenario2[i];
        float npcSimi = getSimilarityBetweenNpcs(npc1, npc2);

        scenarioNpc += npcSimi;
    }

    return scenarioNpc / (float) npcSize;
}