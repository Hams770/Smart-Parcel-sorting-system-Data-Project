#ifndef PARCELQUEUE_H
#define PARCELQUEUE_H

#include <string>
using namespace std;

struct Node {
    int id;
    string address;
    int priority;
    string parcel;
    Node* next;
};

class ParcelQueue {
private:
    Node* front, * rear;

public:
    ParcelQueue();

    void enqueue(int id, string address, int priority);
    void dequeue();
    void display();
    bool isEmpty();
    int getFrontID();
    int getRearID();
    int getSize();
    Node* getFrontNode();  // <-- Add this so others can access the queue
};

#endif
