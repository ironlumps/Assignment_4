#include <iostream>

using namespace std;

template <class T>
class ListNode
{
  public:
    ListNode();
    ListNode(T d);
    ~ListNode();

    T data;
    ListNode *next;
    ListNode *prev;
};

template <class T>
ListNode<T>::ListNode()
{
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::ListNode(T d)
{
  next = NULL; //null pointer
  prev = NULL; //null pointer
  data = d;
}

template <class T>
ListNode<T>::~ListNode()
{

}
