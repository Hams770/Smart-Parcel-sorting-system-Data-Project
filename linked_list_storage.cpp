#include <iostream>
using namespace std;

struct Parcel {
    int id;
    int priority;
};

struct Node {
    Parcel parcel;
    Node* next;
};

Node* head = nullptr;

void insertParcel(Parcel newParcel) {
    Node* newNode = new Node{newParcel, nullptr};

    if (!head || newParcel.priority < head->parcel.priority) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next && current->next->parcel.priority <= newParcel.priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void displayParcels() 
{
    if (!head) 
    {
        cout << "No parcels to display!" << endl;
        return;
    }

    Node* temp = head;
    cout << "Parcels in Priority Order:\n";
    while (temp != nullptr) 
    {
        cout << "Parcel ID: " << temp->parcel.id << ", Priority: " << temp->parcel.priority << endl;
        temp = temp->next;
    }
}

int main() {
    Parcel p1 = {201, 2};
    Parcel p2 = {202, 1};
    Parcel p3 = {203, 3};

    insertParcel(p1);
    insertParcel(p2);
    insertParcel(p3);

    displayParcels();

    return 0;
}
