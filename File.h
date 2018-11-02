#include <iostream>
#include <fstream>

using namespace std;

class FileInput
{
  private:
    int lines;
    string fileName;
    string fileInput;
    void setString();
    ifstream myFile;

  public:
    FileInput();
    FileInput(string file);
    ~FileInput();
    void addFile(string file);
    string getString();
    int getLines();
};
