#include "Simulation.h"
#include <iostream>

using namespace std;

Simulation::Simulation()
{
  time = 0;
  isGood = true;
}

Simulation::Simulation(string fileName)
{
  time = 0;
  isGood = true;

  execute(fileName);
}

Simulation::~Simulation()
{

}

void Simulation::execute(string fileName)
{
  input.addFile(fileName);

  if(input.getLines() <= 0)
  {
    isGood = false;
  }

  if(isGood == true)
  {
    // gets the amount of lines in file and creates an array with that size
    fileArray = new string[input.getLines()];
    int index = 0;
    // fills file array with each line being its own entry
    for(int i = 0; i < input.getLines(); i++)
    {
      fileArray[i] = "";
      while(input.getLines() != '\n')
      {
        fileArray[i] += input.getString();
        index++;
      }
      index++;
    }
  }

  if(isGood == true)
  {
    if(stoi(fileArray[0]) >= 1)
    {
      // Assigns the first line to an open window array
      windowsOpen = stoi(fileArray[0]);
      windows = new Windows[5];
      if(windowsOpen > 0)
      {
        // Assigns the windows to be open
        for (int i = 0; i < windowsOpen; i++)
        {
          windows[i].isOpen = true;
        }
      }
    }
    else
    {
      isGood = false;
      cout << "Invalid Window Amount" << endl;
    }
  }

  // creating the queue of students
  for(int i = 1; i < input.getLines() - 1; i++)
  {
    int t = stoi(fileArray[i++]);

    int numberStudents = stoi(fileArray[i]);

    //checking for inconsistencies with number of students
    if(numberStudents + i > input.getLines())
    {
      cout << "Invalid Student Amount" << endl;
      i = input.getLines();
      isGood = false;
      break;
    }
    for(int j = 0; j < numberStudents; j++)
    {
      j++;

      if(stoi(fileArray[i]) > 0)
      {
        Students s(t, stoi(fileArray[i]));
        students.insert(s);
      }
      else
      {
        cout << "Invalid Wait Time" << endl;
        isGood = false;
      }
    }
  }

  if(isGood = true)
  {
    time = 0;

    int numberStudents = students.getSize();
    int studentsDone = 0;

    while(isGood == true && (!students.isEmpty() || studentsDone < numberStudents))
    {
      cout << "Time: " << time << endl;
      for(int i = 0; i < windowsOpen; i++)
      {
        // incrementing time for each student at a window
        if(windows[i].isBusy)
        {
          windows[i].student.timeLeft--;
          if(windows[i].student.timeLeft <= 0)
          {
            finished.insert(windows[i].student);
            windows[i].isBusy = false;
            studentsDone++;
            cout << "Student left window " << i + 1 << endl;
          }
        }
        else
        {
          windows[i].idleTime++;
        }
        // simulates arrival of each student
        if(!students.isEmpty() && students.peek().arrivalTime <= time)
        {
          if(windows[i].isOpen == true && windows[i].isBusy == false)
          {
            windows[i].student = students.remove();
            windows[i].isBusy = true;
            // setting wait time for each student
            windows[i].student.waitTime = time - windows[i].student.arrivalTime;
          }
        }
      }

      time++;
    }

    if(isGood == true)
    {
      calculate();
    }

    delete[] fileArray;
  }
}

void Simulation::calculate()
{
  // Calculates Statistics for students wait time
  Statistics<float> studs(finished.getSize());
  int temp = 0;
  studs.setSize(students.getSize());
  for(int i = 0; i < studs.getSize(); i++)
  {
    studs.numbers[i] = (float)finished.remove().waitTime;
    if(studs.numbers[i] > 10)
    {
      temp++;
    }
  }

  cout << "Mean Student Wait Time: " << studs.average() << " minutes" << endl;
  cout << "Median Student Wait Time: " << studs.median() << " minutes" << endl;
  cout << "Longest Student Wait Time: " << studs.max() << " minutes" << endl;
  cout << "Numver of studs Waiting Over 10 Minutes: " << temp << endl;

  Statistics<float> wind(windowsOpen);
  temp = 0;
  for(int i = 0; i < wind.getSize(); i++)
  {
    wind.numbers[i] = (float)windows[i].idleTime;
    if(wind.numbers[i] > 5)
    {
      temp++;
    }
  }

  cout << endl;
  cout << "Mean Window Idle Time: " << wind.average() << " minutes" << endl;
  cout << "Longest Window Wait Time: " << wind.max() << " minutes" << endl;
  cout << "Number of Windows Idle for Over 5 Mintues: " << temp << endl;
}
