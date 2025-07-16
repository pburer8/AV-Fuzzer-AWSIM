#include <vector>
#include <string>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <tools.h>
#include <map>

/*
std::vector<???> getAllCheckpoints(std::string ck_path)
{
    std::vector<???> prevPopPool;

    for (const auto& entry : std::filesystem::directory_iterator(ck_path))
    {
        std::filesystem::path outfilename = entry.path();
        std::string outfilename_str = outfilename.string();
    
        
        if (outfilename_str.find("generation", 0) != std::string::npos)
        {
            Load the file
            prevPopPool.push_back(prevPop);
        }
    }
    
    return prevPopPool;
}*/

/*
std::vector<???> generateRestart(std::string ck_path, int scenarioNum, std::vector<std::vector<int>> bounds)
{
    std::vector<???> prevPopPool = getAllCheckpoints(ck_path);

    std::vector<???> newPopCandidate;
    std::vector<???> newScenarioList;
    int popSize = prevPopPool[0].size();
    int npcSize = prevPopPool[0][0].scenario.size();
    int scenarioSize = prevPopPool[0].size();
    int popPoolSize = prevPopPool.size();
    std::map<int, float> dictScenario;

    Initiate random chromosomes (count: scenarioNum)

    for (int i = 0; i < scenarioNum; i++)
    {
        int similarity = 0;

        for (int j = 0; j < popPoolSize; j++)
        {
            float simiPop = 0.f;
            for (int k = 0; k < scenarioSize; k++)
            {
                ??? scenario1 = newPopCandidate[i].scenario;
                ??? scenario2 = prevPopPool[j][k].scenario;

                float simi = getSimilarityBetweenScenarios(scenario1, scenario2);
                simiPop += simi;
            }
            
            simiPop /= (float) scenarioSize;
            similarity += simiPop;
        }

        similarity /= popPoolSize;
        dictScenario[i] = similarity;
    }
    
    Create a sorted array of dictScenario items based on their float, in reverse.

    Make a sorted dict of this array

    Make an array of the keys of this dict (index)

    int j = 0;

    for (int i : index)
    {
        if (j == popSize)
        {
            break;
        }
        newPopCandidate[i].func();
        newScenarioList.push_back(newPopCanddiate[i]);
        j += 1;
    }

    return newScenarioList;
}*/

/*
bool isDifferenceEnough(std::string ck_path, ??? afterScenario, ??? beforeScenario)
{
    std::vector<???> prevPopPool = getAllCheckpoints(ck_path);
    int popPoolSize = prevPopPool.size();
    int scenarioSize = prevPopPool.size();

    float similarityBefore = 0.f;
    float similarityAfter = 0.f;

    for (int j = 0; j < popPoolSize; j++)
    {
        float simiPopBefore = 0.f;
        float simiPopAfter = 0.f;

        for (int k = 0; k < scenarioSize; k++)
        {
            ??? referScenario = prevPopPool[j][k].scenario;
            float simiBefore = getSimilarityBetweenScenarios(beforeScenario.scenario);
            float simiAfter = getSimilarityBetweenScenarios(afterScenario.scenario);

            simiPopBefore += simiBefore;
            simiPopAfter += simiAfter;
        }

        simiPopBefore /= (float) scenarioSize;
        similarityBefore += simiPopBefore;
        simiPopAfter /= (float) scenarioSize;
        similarityAfter += simiPopAfter;
    }
    
    similarityBefore /= (float) popPoolSize;
    similarityAfter /= (float) popPoolSize;

    return similarityAfter < similarityBefore;
}*/

/*
float getSimilarityOfScenarioVsPrevPop(??? scenario, std::vector<std::vector<???>> prevPopPool)
{
    float similarity = 0.f;
    for (??? i : prevPopPool)
    {
        float popSimilarity = 0.f;
        for (??? j : i)
        {
            float simi = getSimilarityBetweenScenarios(j.scenario, scenario.scenario);
            popSimilarity += simi;
        }
        popSimilarity /= (float) i.size();
        similarity += popSimilarity;
    }

    similarity /= (float) prevPopPool.size();

    return similarity;
}*/