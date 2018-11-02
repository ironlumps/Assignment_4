#include "File.h"
#include "Queue.h"
#include "Window.h"
#include "Statistics.h"

using namespace std;

class Simulation
{
public:
  Simulation();
  Simulation(string fileName);
  ~Simulation();

  void execute(string fileName);

private:
  bool isGood;

  int windowsOpen;
  int time;
  FileInput input;
  string* fileArray;
  Windows* windows;

  Statistics<Students> study;
  Statistics<Windows> windy;
  Queue<Students> students;
  Queue<Students> finished;

  void calculate();
};
