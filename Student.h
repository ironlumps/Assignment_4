#include <iostream>

using namespace std;

class Students
{
public:
  Students();
  Students(int at, int timeNeeded);
  ~Students();
  int waitTime;
  int timeLeft;
  int arrivalTime;
};
