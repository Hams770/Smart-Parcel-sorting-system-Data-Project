#include "ParcelQueue.h"
#include <iostream>
using namespace std;


ParcelQueue::ParcelQueue() {
    front = rear = nullptr;
}


void ParcelQueue::enqueue(int id, string address, int priority) {
    Node* newNode = new Node();
    newNode->id = id;
    newNode->address = address;
    newNode->priority = priority;
    newNode->parcel = "Parcel_" + to_string(id);  
    newNode->next = nullptr;

    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Parcel " << id << " enqueued. Address: " << address << ", Priority: " << priority << endl;
}


void ParcelQueue::dequeue() {
    if (front == nullptr) {
        cout << "Queue Underflow!" << endl;
        return;
    }

    Node* temp = front;
    cout << "Dequeuing Parcel ID: " << temp->id << endl;
    front = front->next;
    delete temp;

    if (front == nullptr)
        rear = nullptr;
}


void ParcelQueue::display() {
    if (front == nullptr) {
        cout << "Queue is empty!" << endl;
        return;
    }

    Node* temp = front;
    cout << "Queue Parcels:\n";
    while (temp != nullptr) {
        cout << "ID: " << temp->id << ", Address: " << temp->address << ", Priority: " << temp->priority << endl;
        temp = temp->next;
    }
}


bool ParcelQueue::isEmpty() {
    return (front == nullptr);
}


int ParcelQueue::getFrontID() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return front->id;
}


int ParcelQueue::getRearID() {
    if (rear == nullptr) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return rear->id;
}


int ParcelQueue::getSize() {
    int size = 0;
    Node* temp = front;
    while (temp != nullptr) {
        size++;
        temp = temp->next;
    }
    cout << "Queue size: " << size << endl;
    return size;
}


Node* ParcelQueue::getFrontNode() {
    return front;
}
