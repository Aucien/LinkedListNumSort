#include "linkedlist.h"
#include "iostream"
#include <fstream>

using namespace std;

linkedlist::linkedlist()
{
}

linkedlist::~linkedlist()
{
    // RECURSIVE
    deleteList(head);
}

void linkedlist::deleteList(node *temp)
{
    if (temp == nullptr)
    {
        free(temp);
        return;
    }
    deleteList(temp->next);
    free(temp);
}

int linkedlist::count(node *temp)
{
    // RECURSIVE
    if (temp == nullptr)
    {
        return 0;
    }
    return 1 + count(temp->next);
}

void linkedlist::addToFront(int n)
{
    node *temp;
    temp = new node;
    temp->data = n;
    temp->next = head;
    head = temp;
}

double linkedlist::average()
{
    // uses sum and count functions
    double totalNodes = count(head);
    double total = sum(head);
    return total / totalNodes;
}

int linkedlist::sum(node *temp)
{
    // RECURSIVE
    if (temp->next == nullptr)
    {
        return temp->data;
    }
    return temp->data + sum(temp->next);
}

void linkedlist::writeInorder(string &file)
{
    node *temp;
    node *trav = head;
    ofstream myFile;
    myFile.open(file);
    int x;
    bool unsorted = true;
    while (unsorted)
    {
        unsorted = false;
        temp = trav;
        while (temp->next != nullptr)
        {
            if (temp->data > temp->next->data)
            {
                x = temp->data;
                temp->data = temp->next->data;
                temp->next->data = x;
                unsorted = true;
            }
            temp = temp->next;
        }
    }

    temp = head;
    myFile << "Sorted: ";
    cout << "\nSorted: ";
    while (temp != nullptr)
    {
        myFile << temp->data << " ";
        cout << temp->data << " ";
        temp = temp->next;
    }
    myFile.close();
}

void linkedlist::writeReversed(string &file)
{
    // RECURSIVE
    ofstream data;
    data.open(file, ios::app);
    data << "\nReversed: ";
    cout << "\nReversed: ";
    writeReversedHelper(data, head);
    data << endl;
    data.close();
}

void linkedlist::writeReversedHelper(ofstream &data, node *temp)
{
    if (temp == nullptr)
    {
        return;
    }
    writeReversedHelper(data, temp->next);
    data << temp->data << " ";
    cout << temp->data << " ";
}
