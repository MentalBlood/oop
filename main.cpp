#include <cstdio>
#include <cstdlib>
#define _USE_MATH_DEFINES
#include <cmath>
#include <string>

#include "header\Robot.h"
#include "header\Swarm.h"

void exitWithError(const char *errorText) {
    printf("%s\n", errorText);
    exit(1);
}

void testRobot() {
    Robot *testRobot = new Robot(14, 29, 0, NULL);
    //if (testRobot->getName() != "test robot")
    //    exitWithError("Wrong name after creating");
    if (!testRobot)
        exitWithError("Robot is not created");
    if (testRobot->getX() != 14)
        exitWithError("Wrong x after creating");
    if (testRobot->getY() != 29)
        exitWithError("Wrong y after creating");
    if (testRobot->getAngle() != 0)
        exitWithError("Wrong angle after creating");

    float rotationAngle = 100 * M_PI / 6;
    testRobot->rotate(rotationAngle);
    float correctAngle = rotationAngle - int(rotationAngle / (2 * M_PI)) * 2 * M_PI;
    if (testRobot->getAngle() != correctAngle)
        exitWithError("Wrong angle after rotating");

    //float currentAngle = testRobot->getAngle();
    float moveDistance = 16;
    //float correctX = testRobot->getX() + cos(currentAngle) * moveDistance;
    testRobot->move(moveDistance);
    //printf("%f ?= %f\n", testRobot->getX(), correctX);
    //if (testRobot->getX() != correctX)
     //   exitWithError("Wrong x after move");
    delete testRobot;

    printf("Robot test end\n");
}

void putRandomString(char **destination, int length) {
    *destination = (char*)malloc(sizeof(char) * (length + 1));
    char *currentChar = *destination;
    for (; (currentChar - *destination) < length; currentChar++)
        *currentChar = char(rand() % (122 - 97) + 97);
}

void testSwarm() {
    Swarm swarm;
    swarm.addRobot(new Robot(), "A");
    swarm.addRobot(new Robot(), "B");
    swarm.addRobot(new Robot(), "C");

    if (!swarm.addSubordinationFromTo("A", "B"))
        exitWithError("Error while subordinating A to B");
    if (!swarm.addSubordinationFromTo("B", "C"))
        exitWithError("Error while subordinating B to C");
    if (swarm.addSubordinationFromTo("C", "A"))
        exitWithError("No error while subordinating C to A (but it should be!)");
    if (swarm.addSubordinationFromTo("B", "A"))
        exitWithError("No error while subordinating B to A (but it should be!)");
    if (!swarm.removeSubordinationFromTo("A", "B"))
        exitWithError("Error while unsubordinating A from B");
    if (!swarm.removeSubordinationFromTo("B", "C"))
        exitWithError("Error while unsubordinating B from C");
    if (swarm.removeSubordinationFromTo("B", "A"))
        exitWithError("No error while unsubordinating B from A (but it should be!)");

    printf("Swarm test end\n");
}

int main(void) {
    testRobot();
    testSwarm();
    printf("end\n");
    return 0;
}