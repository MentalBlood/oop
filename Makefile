oop: *.cpp
	g++ -std=c++11 -Wall -Wextra -g -O0 main.cpp header\Robot.h source\Robot.cpp header\Swarm.h source\Swarm.cpp