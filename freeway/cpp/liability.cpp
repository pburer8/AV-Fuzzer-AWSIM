#include <cstdio>
#include <cmath>

/*
bool isHitEdge(??? ego, ??? sim, float init_degree)
{
    https://autowarefoundation.github.io/autoware-documentation/main/design/autoware-interfaces/components/localization/#vehicle-pose

    ??? lane_center = (Take ego position, find closest lane)

    float ego_x = (Take ego x coordinate)
    float ego_y = (Take ego y coordinate)
    float ego_z = (Take ego z coordinate)

    float mp_x = lane_center x coordinate
    float mp_y = lane_center y coordinate
    float mp_z = lane_center z coordinate

    https://autowarefoundation.github.io/autoware-documentation/main/design/autoware-interfaces/components/vehicle-dimensions/#vehicle_length
    float diagonal_length = sqrt(pow(length (x), 2), pow(width (y), 2));

    https://autowarefoundation.github.io/autoware-documentation/main/design/autoware-interfaces/components/localization/#vehicle-pose
    float rotate_degree = abs(ego z rotation - init_degree) + 23.86;
    float ego_size_y = (diagonal_length / 2.0)* sin(radians(rotate_degree));

    Calculate if the size of the car extends outside of the lane boundaries. If so, return True. Otherwise return False
}
*/

/*
bool isHitYellowLine(??? ego, ??? sim, float init_degree)
{
    https://autowarefoundation.github.io/autoware-documentation/main/design/autoware-interfaces/components/localization/#vehicle-pose

    ??? lane_center = (Take ego position, find closest lane)

    float ego_x = (Take ego x coordinate)
    float ego_y = (Take ego y coordinate)
    float ego_z = (Take ego z coordinate)

    float mp_x = lane_center x coordinate
    float mp_y = lane_center y coordinate
    float mp_z = lane_center z coordinate

    https://autowarefoundation.github.io/autoware-documentation/main/design/autoware-interfaces/components/vehicle-dimensions/#vehicle_length
    float diagonal_length = sqrt(pow(length (x), 2), pow(width (y), 2));

    https://autowarefoundation.github.io/autoware-documentation/main/design/autoware-interfaces/components/localization/#vehicle-pose
    float rotate_degree = abs(ego z rotation - init_degree) + 23.86;
    float ego_size_y = (diagonal_length / 2.0)* sin(radians(rotate_degree));

    Calculate the dimensions of the yellow line
    Calculate if the size of the car extends onto the yellow line. If so, return True. Otherwise return False
}
*/

/*
bool isCrossedLine(??? ego, ??? sim, float init_degree)
{
    https://autowarefoundation.github.io/autoware-documentation/main/design/autoware-interfaces/components/localization/#vehicle-pose

    ??? lane_center = (Take ego position, find closest lane)

    float right_y = lane_center.position.y - 2.34
    float left_y = lane_center.position.y + 2.34

    https://autowarefoundation.github.io/autoware-documentation/main/design/autoware-interfaces/components/localization/#vehicle-pose
    float rotate_degree = abs(ego z rotation - init_degree) + 23.86;
    float ego_size_y = (diagonal_length / 2.0)* sin(radians(rotate_degree));

    Calculate if the size of the car extends over the lines. If so, return True. Otherwise return False
}
*/

/*
void debugPos(??? ego, ??? npc)
{
    https://autowarefoundation.github.io/autoware-documentation/main/design/autoware-interfaces/components/map/
    
    float ego_x = (Take ego x coordinate)
    float ego_y = (Take ego y coordinate)
    float ego_z = (Take ego z coordinate)
    float ego_rotation = (Take ego z rotation)

    float npc_x = (Take npc x coordinate)
    float npc_y = (Take npc y coordinate)
    float npc_z = (Take npc z coordinate)
    float npc_rotation = (Take npc z rotation)

    printf(" ^^^^^^^ Ego Rotation: %f, NPC rotation: %f ^^^^^^^", ego_rotation, npc_rotation);
    printf("Ego: %f, %f, %f", ego_x, ego_y, ego_z);
    printf("NPC: %f, %f, %f", npc_x, npc_y, npc_z);
}*/

/*
float findDistance(??? ego, ??? npc)
{
    https://autowarefoundation.github.io/autoware-documentation/main/design/autoware-interfaces/components/map/

    float ego_x = (Take ego x coordinate)
    float ego_y = (Take ego y coordinate)
    float ego_z = (Take ego z coordinate)
    float npc_x = (Take npc x coordinate)
    float npc_y = (Take npc y coordinate)
    float npc_z = (Take npc z coordinate)

    float distance = pow(npc_x - ego_x, 2) + pow(npc_y - ego_y, 2) + pow(npc_z - ego_z, 2);
    distance = sqrt(distance);
    return distance;
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

    https://autowarefoundation.github.io/autoware-documentation/main/design/autoware-interfaces/components/map/

    float ego_x = (Take ego x coordinate)
    float ego_y = (Take ego y coordinate)
    float ego_z = (Take ego z coordinate)
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