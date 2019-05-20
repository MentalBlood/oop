#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <map>

class Robot {
    private:
        float x, y, 
              angle;
        Robot *commander;
        std::map<std::string, Robot*, std::less<std::string> > subordinatedRobots;

    public:
        Robot(float, float, float, Robot*);
        Robot();
        void move(float);
        void rotate(float);

        float getX() const;
        float getY() const;
        float getAngle() const;
        Robot* getCommander() const;
        void setCommander(Robot*);

        Robot* getSubordinate(const std::string);
        void addSubordinate(Robot*, std::string);
        bool removeSubordinate(const std::string);
        void moveSubordinate(const std::string, float);
        void rotateSubordinate(const std::string, float);
};

#endif //ROBOT_H