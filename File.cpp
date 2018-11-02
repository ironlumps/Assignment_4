#include "File.h"

using namespace std;

FileInput::FileInput()
{
  fileInput = "";
  fileName = "";
  lines = 0;

}

FileInput::FileInput(string file)
{
  FileInput();
  fileName = file;
  setString();
}

FileInput::~FileInput()
{
  myFile.close();
}

void FileInput::setString()
{
  myFile.open(fileName.c_str());
  string line;

  if (myFile.is_open())
  {
    while (getline (myFile,line))
    {
      fileInput += line;
      lines++;
    }
  }
  else
  {
    cout << "Unable to open file";
  }
}

void FileInput::addFile(string file)
{
  fileName = file;
  getString();
}

string FileInput::getString()
{
  return fileInput;
}

int FileInput::getLines()
{
  return lines;
}
