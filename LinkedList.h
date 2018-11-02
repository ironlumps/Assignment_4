#include <iostream>
#include "ListNode.h"

using namespace std;
/*
template <class T>
class LinkedList
{
  public:
    virtual void insertFront(T d) = 0;
    virtual void insertBack(T d) = 0;
    virtual T removeFront() = 0;
    virtual T removeBack() = 0;
    virtual bool contains(T value) = 0;
    virtual unsigned int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual bool remove(T key) = 0;
};
*/
template <class T>
class DoubleList
{
  private:
    ListNode<T> *back;
    unsigned int size;

  public:
    DoubleList();
    ~DoubleList();

    void contains();
    void printList();
    void insertFront(T d);
    void insertBack(T d);
    T removeFront();
    T removeBack();
    bool contains(T value);
    int find(T value);
    unsigned int getSize();
    bool isEmpty();
    bool remove(T key);

    ListNode<T> *front;
};

template <class T>
DoubleList<T>::DoubleList()
{
  front = NULL;
  back = NULL;
  size = 0;
}

template <class T>
DoubleList<T>::~DoubleList()
{

}

template <class T>
void DoubleList<T>::printList()
{
  ListNode<T> *current = front;
  while(current != NULL)
  {
    cout << current->data << endl;
    current = current->next;
  }
}

template <class T>
void DoubleList<T>::insertFront(T d)
{
  ListNode<T> *node = new ListNode<T>(d);
  if(size == 0) // empty list
  {
    back = node;
  }
  else // not empty
  {
    front->prev = node;
    node->next = front;
  }

  front = node;
  size++;
}

template <class T>
void DoubleList<T>::insertBack(T d)
{
  ListNode<T> *node = new ListNode<T>(d);
  if(size == 0) // check if empty
  {
    front = node;
  }
  else
  {
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

template <class T>
T DoubleList<T>::removeFront()
{
  ListNode<T> *temp = front;
  if(front->next == NULL) //only node in list
  {
    back = NULL;
  }
  else
  {
    front->next->prev = NULL;
  }
  front->next = front;
  temp->next = NULL;
  T val = temp->data;

  delete temp;
  size--;

  return val;
}

template <class T>
T DoubleList<T>::removeBack()
{
  ListNode<T> *temp = back;
  if(back->prev = NULL) // only node in list
  {
    front = NULL;
  }
  else
  {
    back->prev->next = NULL;
  }
  back->prev = back;
  temp->prev = NULL;
  T val = temp->data;

  delete temp;
  size--;

  return val;
}

template <class T>
bool DoubleList<T>::contains(T value)
{
  ListNode<T> *curr = front;
  while (curr != NULL)
  {
    if (curr->data == value)
    {
      return true;
    }
  }
  return false;
}

template <class T>
bool DoubleList<T>::remove(T key)
{
  ListNode<T> *current = front;
  while(current->data != key)
  {
    current = current->next;
    if(current = NULL)
    {
      return false;
    }
  }
  // We found the value/node that needs to be removed
  if(current == front)
  {
    front = current->next;
  }
  else
  {
    current->prev->next = current->next;
  }

  if(current == back)
  {
    back = current->prev;
  }
  else
  {
    current->next->prev = current->prev;
  }

  current->next = NULL;
  current->prev = NULL;

  --size;

  delete current;
  return true;
}

template <class T>
int DoubleList<T>::find(T value)
{
  int index = -1;
  ListNode<T> *current = front;
  while(current != NULL) // being searching
  {
    ++index;
    if(current->data == value)
    {
      break;
    }
    else // did not find
    {
      current = current->next;
    }
  }
  if(current == NULL)
  {
    index = -1;
  }
  return index;
}

template <class T>
unsigned int DoubleList<T>::getSize()
{
  return size;
}

template <class T>
bool DoubleList<T>::isEmpty()
{
  if (size <= 0)
  {
    return true;
  }
  return false;
};
