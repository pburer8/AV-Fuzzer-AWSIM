#include <vector>
#include <string>
#include <filesystem>
#include <iostream>
#include <fstream>

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
    int popSize = len(prevPopPool[0]);
    int npcSize = len(prevPopPool[0][0].scenario);
}*/