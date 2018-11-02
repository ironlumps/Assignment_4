#include "Student.h"

using namespace std;

Students::Students()
{
  waitTime = 0;
  timeLeft = 0;
  arrivalTime = 0;
}

Students::Students(int at, int timeNeeded)
{
  Students();
  arrivalTime = at;
  timeLeft = timeNeeded;
}

Students::~Students()
{

}
