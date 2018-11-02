#include "Simulation.h"

int main(int argc, char const* argv[])
{
  if(argc == 2)
  {
    Simulation sim(argv[1]);
  }
  else
  {
    cout << "Invalid File Name Entry" << endl;
  }
}
