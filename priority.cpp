#include <iostream>
#include <string>
#include "ParcelQueue.h"  // Include the queue implementation
using namespace std;

const int MAX_SIZE = 100;

struct Parcel {
    int id;
    int priority;
};

Parcel parcels[MAX_SIZE];
int parcelCount = 0;

Node* head = nullptr; // For linked list sorting

// Pulls parcels from queue and adds to array
void transferQueueToArray(ParcelQueue& pq) {
    Node* temp = pq.getFrontNode(); // Get access to front node

    while (temp != nullptr) {
        Parcel newParcel = { temp->id, temp->priority };
        int i = parcelCount - 1;
        while (i >= 0 && parcels[i].priority > newParcel.priority) {
            parcels[i + 1] = parcels[i];
            i--;
        }
        parcels[i + 1] = newParcel;
        parcelCount++;

        temp = temp->next;
    }
}

// Displays sorted array
void displayParcelsArray() {
    cout << "Parcels sorted by priority (Array):\n";
    for (int i = 0; i < parcelCount; i++) {
        cout << "ID: " << parcels[i].id << ", Priority: " << parcels[i].priority << endl;
    }
}

// Pulls from queue and inserts to linked list
void transferQueueToLinkedList(ParcelQueue& pq) {
    Node* temp = pq.getFrontNode();

    while (temp != nullptr) {
        Node* newNode = new Node{ temp->id, "", temp->priority, "", nullptr };

        if (!head || temp->priority < head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->priority <= temp->priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        temp = temp->next;
    }
}

// Displays sorted linked list
void displayParcelsLL() {
    cout << "Parcels sorted by priority (Linked List):\n";
    Node* current = head;
    while (current) {
        cout << "ID: " << current->id << ", Priority: " << current->priority << endl;
        current = current->next;
    }
}
