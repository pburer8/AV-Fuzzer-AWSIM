#include <cstdio>
#include <cmath>
#include <yaml-cpp/yaml.h>
#include <iostream>
#include <fstream>

#include <lanelet2_core/LaneletMap.h>
#include <lanelet2_core/primitives/Point.h>
#include <lanelet2_core/geometry/Lanelet.h>
#include <lanelet2_io/Io.h>
#include <lanelet2_io/io_handlers/Serialize.h>



bool isHitEdge(float init_degree)
{

    std::vector<std::pair<double, lanelet::Lanelet>> nearest_lane = findNearestLanelet();

    lanelet::ConstLineString3d leftBound = nearest_lane[0].second.leftBound();
    lanelet::ConstLineString3d rightBound = nearest_lane[0].second.rightBound();

    std::vector<float> ego_pose = pose();

    if (ego_pose.size() != 3)
    {
        return;
    }

    

    //https://autowarefoundation.github.io/autoware-documentation/main/design/autoware-interfaces/components/vehicle-dimensions/#vehicle_length
    //float diagonal_length = sqrt(pow(length (x), 2), pow(width (y), 2));


    std::vector<float> ego_rot = orientation();

    if (ego_rot.size() != 4)
    {
        return;
    }

    //[2] is the z-coordinate
    float rotate_degree = abs(ego_rot[2] - init_degree) + 23.86;
    //float ego_size_y = (diagonal_length / 2.0)* sin(radians(rotate_degree));

    //Calculate if the size of the car extends outside of the lane boundaries. If so, return True. Otherwise return False

    return false;
}



/*
bool isHitYellowLine(??? ego, ??? sim, float init_degree)
{

    ??? lane_center = (Take ego position, find closest lane)

    std::vector<float> ego_pose = pose();

    if (ego_pose.size() != 3)
    {
        return;
    }

    float mp_x = lane_center x coordinate
    float mp_y = lane_center y coordinate
    float mp_z = lane_center z coordinate

    //https://autowarefoundation.github.io/autoware-documentation/main/design/autoware-interfaces/components/vehicle-dimensions/#vehicle_length
    //float diagonal_length = sqrt(pow(length (x), 2), pow(width (y), 2));

    std::vector<float> ego_rot = orientation();

    if (ego_rot.size() != 4)
    {
        return;
    }

    float rotate_degree = abs(ego_rot[2] - init_degree) + 23.86;
    //float ego_size_y = (diagonal_length / 2.0)* sin(radians(rotate_degree));

    //Calculate the dimensions of the yellow line
    //Calculate if the size of the car extends onto the yellow line. If so, return True. Otherwise return False
}
*/



bool isCrossedLine(float init_degree)
{
    std::vector<std::pair<double, lanelet::Lanelet>> nearest_lane = findNearestLanelet();

    lanelet::ConstLineString3d leftBound = nearest_lane[0].second.leftBound();
    lanelet::ConstLineString3d rightBound = nearest_lane[0].second.rightBound();

    std::vector<float> ego_pose = pose();

    if (ego_pose.size() != 3)
    {
        return;
    }

    std::vector<float> ego_rot = orientation();

    if (ego_rot.size() != 4)
    {
        return;
    }

    //https://autowarefoundation.github.io/autoware-documentation/main/design/autoware-interfaces/components/vehicle-dimensions/#vehicle_length
    //float diagonal_length = sqrt(pow(length (x), 2), pow(width (y), 2));

    float rotate_degree = abs(ego_rot[2] - init_degree) + 23.86;
    //float ego_size_y = (diagonal_length / 2.0)* sin(radians(rotate_degree));

    //Calculate if the size of the car extends over the lines. If so, return True. Otherwise return False

    return false;
}



void debugPos(std::vector<float> ego_pose = pose(), std::vector<float> ego_rot = orientation())
{
    /*
    float npc_x = (Take npc x coordinate)
    float npc_y = (Take npc y coordinate)
    float npc_z = (Take npc z coordinate)
    float npc_rotation = (Take npc z rotation)
    */

    printf("======== Ego Pose: ========\n");
    printf("X: %f\nY: %f\nZ: %f\n\n", ego_pose[0], ego_pose[1], ego_pose[2]);
    printf("======== Ego Orientation: ========\n");
    printf("X: %f\nY: %f\nZ: %f\nW: %f\n\n", ego_rot[0], ego_pose[1], ego_pose[2], ego_pose[3]);
}

/*
float findDistance(??? npc)
{
    std::vector<float> ego_pose = pose();

    if (ego_pose.size() != 3)
    {
        return;
    }

    //Get npc position

    //Calculate distance (math.pow(npc_x - ego_x , 2) + math.pow(npc_y - ego_y, 2) + math.pow(npc_z - ego_z, 2) )
    //float distance = pow(npc_pose[0] - ego_pose[0], 2) + pow(npc_pose[1] - ego_pose[1], 2) + pow(npc_pose[2] - ego_pose[2], 2);
    //distance = sqrt(distance)
    //return distance;

    return;
}
*/


/*
bool isEgoFault(??? ego, ??? npc, ??? sim, float init_degree)
{
    if !(npc)
    {
        return true;
    }
    
    bool isCrossed = isCrossedLine(ego, sim, init_degree);

    std::vector<float> ego_pose = pose();

    if (ego_pose.size() != 3)
    {
        return;
    }

    float npc_x = (Take npc x coordinate)
    float npc_y = (Take npc y coordinate)
    float npc_z = (Take npc z coordinate)

    debugPos(ego, npc);

    if (isHitYellowLine(ego, sim, init_degree))
    {
        return false;
    }

    if (isCrossed)
    {
        Check if NPC is behind. If true, NPC fault, otherwise ego fault
    } else
    {
        Check if NPC is in front. If true, ego fault, otherwise NPC fault
    }
}
*/

std::vector<float> pose()
{
    try
    {
        YAML::Node root = YAML::LoadFile("ego_pose.yaml");

        if (!root["pose"]) 
        {
            std::cerr << "Missing 'pose' key in YAML file\n";
        }

        auto pose = root["pose"];

        auto position = pose["position"];

        float ego_x = position["x"].as<float>();
        float ego_y = position["y"].as<float>();
        float ego_z = position["z"].as<float>();
        
        return {ego_x, ego_y, ego_z};
    } catch (const YAML::Exception &e) 
    {
        std::cerr << "YAML error: " << e.what() << "\n";
        return;
    }

    return;
}

std::vector<float> orientation()
{
    try
    {
        YAML::Node root = YAML::LoadFile("ego_pose.yaml");

        if (!root["pose"]) 
        {
            std::cerr << "Missing 'pose' key in YAML file\n";
        }

        auto pose = root["pose"];

        auto orientation = pose["orientation"];

        float ego_x = orientation["x"].as<float>();
        float ego_y = orientation["y"].as<float>();
        float ego_z = orientation["z"].as<float>();
        float ego_w = orientation["w"].as<float>();
        
        return {ego_x, ego_y, ego_z, ego_w};
    } catch (const YAML::Exception &e) 
    {
        std::cerr << "YAML error: " << e.what() << "\n";
        return;
    }

    return;
}

std::vector<std::pair<double, lanelet::Lanelet>> findNearestLanelet()
{
    lanelet::GPSPoint gpsPoint;

    gpsPoint.lat = 81377.359;
    gpsPoint.lon = 49916.910;
    gpsPoint.ele = 41.171;
    lanelet::Origin origin(gpsPoint);
    lanelet::LaneletMapPtr laneletMap = lanelet::load("map.bin", origin);
    
    std::vector<float> ego_pose = pose();

    lanelet::BasicPoint2d point(ego_pose[0], ego_pose[1]);
    double searchRadius = 10.0;

    auto nearestLanelets = lanelet::geometry::findNearest(laneletMap->laneletLayer, point, 1);

    return nearestLanelets;

}