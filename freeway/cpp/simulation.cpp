#include <string>
#include <cmath>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

class AuAwSimulation
{
    public:
        int totalSimTime;
        //??? sim;
        //??? ego;
        geometry_msgs::msg::PoseStamped initEvPos;
        //std::vector<???> npcList;
        bool isEgoFault;
        bool isHit;
        int maxInt;
        float egoFaultDeltaD;

        //void setNpcSpeed(??? npc, float speed);
        //void setNpcChangeLane(??? npc, std::string direction);
        //void setEvThrottle(??? throttle);

        float brakeDist(float speed);

        //float findCollisionDeltaD(??? npc);
        //float findDeltaD(??? npc);
        //float findFitness(std::vector<std::vector<int>> deltaDlist, std::vector<std::vector<int>> dList, bool egoFault, bool hit, int hitTime);
        //void runSimulation(??? scenarioObj);

        AuAwSimulation()
        {
            totalSimTime = 0;
            initEvPos.header.stamp = rclcpp::Clock().now();
            initEvPos.header.frame_id = "nishishinjuku";

            initEvPos.pose.position.x = 81377.359;
            initEvPos.pose.position.y = 49916.910;
            initEvPos.pose.position.z = 41.171;

            initEvPos.pose.orientation.x = 0.001;
            initEvPos.pose.orientation.y = -0.007;
            initEvPos.pose.orientation.z = 0.300;
            initEvPos.pose.orientation.w = 0.954;

            isEgoFault = false;
            isHit = false;
            maxInt = 130;
            egoFaultDeltaD = 0;
        }
};

/*
void AuAwSimulation::setNpcSpeed(??? npc, float speed)
{
    Send ROS2 message to set the NPC speed
}*/

/*
Direction is either "LEFT" or "RIGHT"
void AuAwSimulation::setNpcChangeLane(??? npc, std::string direction)
{
    Send ROS2 message to change NPC lane
}*/

/*
void AuAwSimulation::setEvThrottle(??? throttle)
{
    Send ROS2 message to initalize ego throttle
}*/

float AuAwSimulation::brakeDist(float speed)
{
    float dBrake = 0.0467 * pow(speed, 2.0) + 0.4116 * speed - 1.9913 + 0.5;
    if (dBrake < 0)
    {
        dBrake = 0;
    }
    return dBrake;
}

/*
void AuAwSimulation::findCollisionDeltaD(??? npc)
{
    Find the (d) distance between self ego and npc, subtract the length of a car 
    return d - brakeDist(ego.speed);
}*/

/*
void AuAwSimulation::findDeltaD(??? npc)
{
    Find the distance between self ego and npc, subtract the length of a car

    float deltaD = (float) maxInt;
    float deltaDFront = deltaD;
    float deltaDSide = deltaD;

    If the npc is in front
    {
        And within some distance of ego
        {
            deltaDFront = d - brakeDist(ego.speed);
            print_debug(" --- Delta D Front: " + std::to_string(deltaDFront));
        }
    }

    If ego is changing line to npc's front
    {
        And within some distance of ego
        {
            deltaDSide = d - brakeDist(ego.speed);
            print_debug(" --- Delta D Side: " + std::to_string(deltaDSide));
        }
    }
    deltaD = min(deltaDSide, deltaDFront);

    return deltaD;
}*/

/*
void findFitness(std::vector<std::vector<int>> deltaDList, std::vector<std::vector<int>> dList, bool egoFault, bool hit, int hitTime)
{
    float minDeltaD = (float) maxInt;

    for (std::vector<int> npc : deltaDList)
    {
        int hitCounter = 0;
        for (int deltaD : npc)
        {
            if (isHit && hitCounter == hitTime)
            {
                break;
            }
            if (deltaD < minDeltaD)
            {
                minDeltaD = deltaD;
            }
            hitCounter += 1;
        }
    }

    print_debug(deltaDList);
    print_debug(" *** minDeltaD is " + std::to_string(minDeltaD) + " *** ");

    float minD = (float) maxInt;
    for (std::vector<int> npc : dList)
    {
        int hitCounter = 0;
        for (int d : npc)
        {
            if (isHit && hitCounter == hitTime)
            {
                break;
            }
            if (d < minD)
            {
                minD = d;
            }
            hitCounter += 1;
        }
    }

    print_debug(dList);
    print_debug(" *** minD is " + std::to_string(minD) + " *** ");

    float fitness = 0.5 * minD + 0.5 * minDeltaD;

    return fitness * -1;
}*/