#include <iostream>

using namespace std;

template<class T>
class Statistics
{
public:
  Statistics();
  Statistics(unsigned int s);
  ~Statistics();
  unsigned int getSize();
  void setSize(unsigned int tempSize);

  T* numbers;
  T average();
  T median();
  T max();

  void print();

private:
  unsigned int size;
};

template<class T>
Statistics<T>::Statistics()
{
  size = 0;
}

template<class T>
Statistics<T>::Statistics(unsigned int s)
{
  size = s;
  numbers  = new T[size];
}

template<class T>
Statistics<T>::~Statistics()
{
  delete numbers;
}

template<class T>
unsigned int Statistics<T>::getSize()
{
  return size;
}

template<class T>
void Statistics<T>::setSize(unsigned int tempSize)
{
  size = tempSize;
}

template<class T>
T Statistics<T>::average()
{
  double sum = 0;
  T average = 0;
  for(int i = 0; i < size; i++)
  {
    sum += numbers[i];
  }
  average = sum/size;
  return average;
}

template<class T>
T Statistics<T>::median()
{
  return numbers[size/2];
}

template<class T>
T Statistics<T>::max()
{
  T max = numbers[0];
  for(int i = 1; i < size; i++)
  {
    if(numbers[i] > max)
    {
      max = numbers[i];
    }
  }
  return max;
}

template<class T>
void Statistics<T>::print()
{
  for(int i = 0; i <  size; i++)
  {
    cout << numbers[i] << endl;
  }
}
