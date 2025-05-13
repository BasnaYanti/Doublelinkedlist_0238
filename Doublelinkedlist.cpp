#include <iostream>
using namespace std;

struct Node
{
    int noMhs;
    string name;
    Node *next;
    Node *prev;
};

Node *START = NULL;

void addNode()
{
    Node *newNode = new Node();
    cout << "\nEnter the roll number of the strudent: ";
    cin >> newNode->noMhs;
    cout << "\nEnter the name of the strudent: ";
    cin >> newNode->name;

    if (START == NULL || newNode->noMhs <= START->noMhs)
    {
        if (START != NULL && newNode->noMhs == START->noMhs)
        {
            cout << "\033[31Duplicate roll numbers not allowed\033" << endl;
            return;
        }

        newNode->next = START;


        if (START != NULL)
        {
            START->prev = newNode;
        }
        else
        {
            Node *current = START;
            Node *previouse = NULL;

            while (current != NULL && current->noMhs < newNode->noMhs)
            {
                previouse = current;
                current = current->next;
            }

            newNode-> next = current;
            newNode->prev = previouse;

            if (current != NULL)
            {
                current->prev = newNode;
            }
        }
    }
}