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

            if (previouse != NULL)
            {
                previouse->next = newNode;
            }
            else
            {
                START = newNode;
            }
        }
    }
}

bool search(int rollNo, Node ** previous, Node **current)
{
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*previous)->next;
    }
    return (*current != NULL);
}

void deleteNode()
{
    Node *previous, *current;
    int rollNo;

    cout << "\nEnter the roll number of the student whose record is to be delete: ";
    cin >> rollNo;

    if(START == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    current = START;
    previous = NULL;

    while (current != NULL && current->noMhs != rollNo)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
    {
        cout << "\033[31mThe record with roll number " << rollNo << "not found\033[0m" << endl;
        return;
    }

    if (current = START)
    {
        START = START->next;
        if (START != NULL)
        {
            START->prev = NULL;
        }  
    }
    else
    {
        previous->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = previous;
        }
    }

    delete current;
    cout << "\x1b[32mRecord with roll number " << rollNo << " deleted\x1b[0m " << endl;
}

bool listEmpty()
{
    return (START == NULL);
}

void treverse()
{
    if (listEmpty())
    {
        cout << "\nList Kosong\n";
    }
    else
    {
        cout << "\nData didalam list adalah: \n";
        Node *currentNode = START;
        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << endl;
            currentNode = currentNode->next;
        }
        cout << endl;
    }
}


