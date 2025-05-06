#include <iostream>
#include <string>
#include "ParcelQueue.h"  
using namespace std;

class ParcelStack {
private:
    Node* top;

public:
    ParcelStack() { top = NULL; }

    void loadFromQueue(ParcelQueue& pq) {
        Node* temp = pq.getFrontNode();
        while (temp != nullptr) {
            push(temp->parcel);
            temp = temp->next;
        }
    }

    void push(string parcelName) {
        Node* newNode = new Node();
        newNode->parcel = parcelName;
        newNode->next = top;
        top = newNode;
        cout << parcelName << " pushed into the stack." << endl;
    }

    string pop() {
        if (top == NULL) {
            cout << "Stack Underflow! No parcels to pop." << endl;
            return "";
        }
        string parcelName = top->parcel;
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << parcelName << " popped from the stack." << endl;
        return parcelName;
    }

    string peek() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
            return "";
        }
        return top->parcel;
    }

    bool isEmpty() {
        return (top == NULL);
    }

    void reverseBatch() {
        cout << "Reversing the batch..." << endl;
        while (!isEmpty()) {
            pop();
        }
        cout << "Batch reversed (stack is now empty)." << endl;
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node* temp = top;
        cout << "Stack Parcels:\n";
        while (temp != nullptr) {
            cout << "Parcel: " << temp->parcel << endl;
            temp = temp->next;
        }
    }
};
