//begin linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

using namespace std;

struct node
{
  int data = 0;
  node *next = nullptr;
};

class linkedlist
{
private:
  node *head = nullptr;
  int count(node *temp); // RECURSIVE
  int sum(node *temp);   // RECURSIVE

public:
  linkedlist();
  ~linkedlist(); // RECURSIVE
  void addToFront(int n);
  double average(); // uses sum and count functions
  void writeInorder(string &file);
  void writeReversed(string &file);
  void writeReversedHelper(ofstream &data, node *temp);
  void deleteList(node *temp);
};
#endif // end linkedlist.h