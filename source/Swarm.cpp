#include "..\header\Swarm.h"
#include <stdio.h>
#include <stdlib.h>

Swarm::Swarm():
robots() {}

Robot* Swarm::getRobot(const std::string name) {
    std::map<std::string, Robot*, std::less<std::string> >::iterator robotIterator = robots.find(name);
    if (robotIterator != robots.end())
        return robotIterator->second;
    return NULL;
}

void Swarm::addRobot(Robot *newRobot, std::string newRobotName) {
    std::map<std::string, Robot*, std::less<std::string> >::iterator robotIterator = robots.find(newRobotName);
    if (robotIterator == robots.end())
        robots[newRobotName] = newRobot;
}

bool Swarm::addSubordinationFromTo(const std::string fromRobotName, const std::string toRobotName) {
    Robot *fromRobot = getRobot(fromRobotName);
    if (!fromRobot)
        return false;
    Robot *toRobot = getRobot(toRobotName);
    if (!toRobot)
        return false;
    
    Robot* currentRobot = toRobot;
    while (currentRobot) {
        if (currentRobot == fromRobot)
            return false;
        currentRobot = currentRobot->getCommander();
    }

    if (fromRobot->getCommander())
        fromRobot->getCommander()->removeSubordinate(fromRobotName);
    fromRobot->setCommander(toRobot);
    toRobot->addSubordinate(fromRobot, fromRobotName);
    return true;
}

bool Swarm::removeSubordinationFromTo(const std::string fromRobotName, const std::string toRobotName) {
    Robot *fromRobot = getRobot(fromRobotName);
    if (!fromRobot)
        return false;
    Robot *toRobot = getRobot(toRobotName);
    if (!toRobot)
        return false;
    
    if (toRobot->removeSubordinate(fromRobotName))
        fromRobot->setCommander(NULL);
    else
        return false;
    return true;
}