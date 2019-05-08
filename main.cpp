#include <iostream>
#include <string>
#include "linkedlist.cpp"
#include <fstream>

using namespace std;

void readFile(linkedlist &list, string &file)
{
    ifstream data;
    data.open(file);
    int num;
    while (data >> num)
    {
        list.addToFront(num);
    }
    data.close();
}

int main()
{
    linkedlist list;
    string file = "list.txt";
    string output = "output.txt";
    readFile(list, file);
    float total = list.average();
    cout << "Average: " << total;
    list.writeInorder(output);
    list.writeReversed(output);
    cout << endl;
    return 0;
}