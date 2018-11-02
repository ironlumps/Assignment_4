#include <iostream>
#include "LinkedList.h"

using namespace std;

template <class T>
class Queue
{
  public:
    Queue();
    ~Queue();
    void insert(T data);
    T peek();
    T remove();
    bool isEmpty();
    int getSize();

  private:
    int size;
    DoubleList<T>* myQueue;
};

template <class T>
Queue<T>::Queue()
{
  size = 0;
}

template <class T>
Queue<T>::~Queue()
{

}

template <class T>
void Queue<T>::insert(T data)
{
  myQueue->insertBack(data);
  size++;
}

template <class T>
T Queue<T>::remove()
{
  if (getSize() <= 0)
  {
    cout << "unable to remove" << endl;
  }

  T temp = myQueue->front->data;
  myQueue->removeFront();
  size--;
  return temp;
}

template <class T>
T Queue<T>::peek()
{
  if (getSize() <= 0)
  {
    cout << "unable to peek" << endl;
  }
  return myQueue->front->data;
}

template <class T>
bool Queue<T>::isEmpty()
{
  return (size == 0);
}

template <class T>
int Queue<T>::getSize()
{
  return size;
}
