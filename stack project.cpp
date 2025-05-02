#include <iostream>
using namespace std;

struct Node {
    string parcel;
    Node* next;
};

class ParcelStack {
private:
    Node* top;

public:
    ParcelStack() { top = NULL; }

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

    void display() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Parcels in stack (Top to Bottom): ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->parcel << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverseBatch() {
        cout << "Reversing the batch..." << endl;
        while (!isEmpty()) {
            pop();
        }
        cout << "Batch reversed (stack is now empty)." << endl;
    }
};

int main() {
    ParcelStack stack;

    stack.push("Parcel A");
    stack.push("Parcel B");
    stack.push("Parcel C");

    stack.display();

    cout << "Top parcel is: " << stack.peek() << endl;

    stack.reverseBatch();

    stack.display();

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
