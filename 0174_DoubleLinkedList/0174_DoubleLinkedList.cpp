#include <iostream>
using namespace std;

//membuat struktur untuk object double linkedList
struct Node
{
    //deklarasi noMhs dan name untuk menampung data
    int noMhs;
    string name;
    //deklarasi pointer next dan pref untuk penunjukan data sebelum dan sesudah
    Node* next;
    Node* prev;
};

//deklarasi pointer START dan pemberian nilai
Node* START = NULL;

//deklarasi prosedur addNode
void addNode()
{

    //pembuatan node dan pemberian value untuk data noMhs dan name
    Node* newNode = new Node(); // step 1 Buat Node baru
    cout << "\nEnter the roll number of the student: ";
    cin >> newNode->noMhs; //Assign value to the data field of the new node
    cout << "\nEnter the name of the student: ";
    cin >> newNode->name;  //Assign value to the data field of th

    // Insert the new node in the list
    //kondisi jika star == null atau noMhs node baru <= noMhs start
    if (START == NULL || newNode->noMhs <= START->noMhs)
    {
        // step 2: insert the new node at the beginning
        //kondisi jika  star tidak kosong dan noMhs node baru sama dengan noMhs start
        if (START != NULL && newNode->noMhs == START->noMhs)
        {
            cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
            return;
        }
        // if the list is empty, make the new node the START
        //jika list kosong, maka node next nya adalah START
        newNode->next = START; // step 3: make the new node point to the frst node
        //kondisi jika start tidak memiliki nilai atau tidak kosong
        if (START != NULL) {
            START->prev = newNode; // step 4: make the first node point to the new node
        }
        //memberi nilai prev = null dan start = node baru
        newNode->prev = NULL; // step 5: make the new node point to NULL 
        START = newNode; // step 6: make the new node the first node
    }
    //kondisi jika semua kondisi if tidak terpenuhi
    else {

        // insert the new node in the middle or at the end
        //set nilai current = start dan nilai previous = null
        Node* current = START; // step 1.a: start from the first node
        Node* previous = NULL; // step 1.b: previous node is Null initially

        //looping selama current != null dan noMhs dari current lebih kecil dari noMhs node baru
        while (current != NULL && current->noMhs < newNode->noMhs)
        {                       // step 1.c: traverse the list to find the correct positionn
            previous = current; // step 1.d: move the previous to the current node
            current = current->next; // step 1.e: move the current to the next node
        }

        //set nilai next node baru = current dan prev node baru = previous
        newNode->next = current;  // step 4: Make the next field of the new node point to current
        newNode->prev = previous; // step 5: Make the previous field of the new node point to previous

        //kondisi jika current tidak sama dengan null
        if (current != NULL)
        {
            current->prev = newNode;  // step 6: Make the previous field of the current node point to the new node
        }

        //kondisi jika previous tidak sama dengan null
        if (previous != NULL)
        {
            previous->next = newNode; // step 7: Make the next field of the previous node point to the new node
        }
        //kondisi jika  if previous samas dengan null
        else {
            // if previous is still NULL, it means newNode is now the first node
            START = newNode;
        }
    }
}

//pembuatan function search untuk mencari data
bool search(int rollNo, Node** previous, Node** current)
{
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

//pembuatan prosedur delete untuk menghapus data
void deleteNode()
{
    Node* previous, * current;
    int rollNo;

    cout << "\nEnter the roll number of the student whose record is to be deleted: ";
    cin >> rollNo; // step 3: get the roll number number to be deleted

    if (START == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    current = START; // step 1: start from the first node
    previous = NULL;

    // locate the node to be deleted
    while (current != NULL && current->noMhs != rollNo)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "\033[31mThe record with roll number " << rollNo << " not found\033[0m" << endl;
        return;
    }

    // node to be deleted in the first node
    if (current = START)
    {
        START = START->next; // step 2: update the START pointer
        if (START != NULL)
        {
            START->prev = NULL;
        }
    }
    else
    {  // node to be deleted is not the first node
        previous->next = current->next;
        if (current->next != NULL)
        {  // if there's a successor, update its prev pointer
            current->next->prev = previous;
        }
    }

    // release the memory of the node marked as current
    delete current;
    cout << "\x1b[32mRecord with roll number " << rollNo << " deleted\x1b[0m" << endl;

}

//method untuk mengecek apakah list kosong
bool listEmpty()
{
    return (START == NULL);
}

//prosedur traverse untuk menampilkan data secara urut
void traverse()
{
    if (listEmpty())
        cout << "\nList is empty" << endl;
    else
    {
        cout << "\nRecords in ascending order of roll number are:" << endl;
        Node* currentNode = START; // step 1
        while (currentNode != NULL) // step 2
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl; // step 3
            currentNode = currentNode->next;                                // step 4
        }
    }
}

//prosedur untuk menampilkan dara secara urutan terbalik
void revtraverse()
{
    if (listEmpty())
        cout << "\nList is empty" << endl;
    else
    {
        cout << "\nRecords in descending order of roll number are:" << endl;
        Node* currentNode = START;
        while (currentNode->next != NULL)
            currentNode = currentNode->next;

        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->prev;
        }
    }
}

int main()
{
    
}
