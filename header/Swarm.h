#ifndef SWARM_H
#define SWARM_H

#include "Robot.h"

class Swarm {
    private:
        std::map<std::string, Robot*, std::less<std::string> > robots;

        Robot* getRobot(const std::string);

    public:
        Swarm();
        void addRobot(Robot*, const std::string name);
        bool addSubordinationFromTo(const std::string, const std::string);
        bool removeSubordinationFromTo(const std::string, const std::string);
};

#endif //SWARM_H