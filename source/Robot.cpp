#include "..\header\Robot.h"
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>

Robot::Robot(float xArg, float yArg, float angleArg, Robot *commanderArg):
x(xArg), y(yArg), angle(angleArg), commander(commanderArg) {}

Robot::Robot():
commander(NULL) {}

void Robot::move(float distance) {
    x += cos(angle) * distance;
    y += sin(angle) * distance;
}

void Robot::rotate(float dAngle) {
    angle += dAngle;
    angle -= int(angle / (2 * M_PI)) * 2 * M_PI;
}

float Robot::getX() const {
    return x;
}

float Robot::getY() const {
    return y;
}

float Robot::getAngle() const{
    return angle;
}

Robot* Robot::getCommander() const{
    return commander;
}

void Robot::setCommander(Robot *newCommander) {
    commander = newCommander;
}


Robot* Robot::getSubordinate(const std::string name) {
    std::map<std::string, Robot*, std::less<std::string> >::iterator subordinatedRobotIterator = subordinatedRobots.find(name);
    if (subordinatedRobotIterator != subordinatedRobots.end())
        return subordinatedRobotIterator->second;
    return NULL;
}

void Robot::addSubordinate(Robot *newSubordinate, std::string newSubordinateName) {
    std::map<std::string, Robot*, std::less<std::string> >::iterator subordinatedRobotIterator = subordinatedRobots.find(newSubordinateName);
    if (subordinatedRobotIterator == subordinatedRobots.end())
        subordinatedRobots[newSubordinateName] = newSubordinate;
}

bool Robot::removeSubordinate(const std::string name) {
    std::map<std::string, Robot*, std::less<std::string> >::iterator subordinatedRobotIterator = subordinatedRobots.find(name);
    if (subordinatedRobotIterator != subordinatedRobots.end()) {
        subordinatedRobots.erase(subordinatedRobotIterator);
        return true;
    }
    return false;
}

void Robot::moveSubordinate(const std::string name, float distance) {
    Robot* correspondingSubordinate = getSubordinate(name);
    if (correspondingSubordinate)
        correspondingSubordinate->move(distance);
}

void Robot::rotateSubordinate(const std::string name, float dAngle) {
    Robot* correspondingSubordinate = getSubordinate(name);
    if (correspondingSubordinate)
        correspondingSubordinate->rotate(dAngle);
}