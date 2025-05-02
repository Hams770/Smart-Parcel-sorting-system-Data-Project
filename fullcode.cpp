#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

// Single Node structure used for both ParcelQueue and ParcelStack
struct Node {
    int id; // For ParcelQueue
    string address; // For ParcelQueue
    int priority; // For ParcelQueue
    string parcel; // For ParcelStack
    Node* next;
};

struct TreeNode {
    string name;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string n) : name(n), left(nullptr), right(nullptr) {}
};

class ParcelQueue {
private:
    Node* front, * rear;

public:
    ParcelQueue() {
        front = rear = nullptr;
    }

    void enqueue(int id, string address, int priority) {
        Node* newNode = new Node();
        newNode->id = id;
        newNode->address = address;
        newNode->priority = priority;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Parcel " << id << " enqueued. Address: " << address << ", Priority: " << priority << endl;
    }

    void dequeue() {
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

    void display() {
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

    bool isEmpty() {
        return (front == nullptr);
    }

    int getFrontID() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->id;
    }

    int getSize() {
        int size = 0;
        Node* temp = front;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }
        cout << "Queue size: " << size << endl;
        return size;
    }

    int getRearID() {
        if (rear == nullptr) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return rear->id;
    }
};

void displayHierarchy(TreeNode* root, int level = 0) {
    if (root == nullptr) return;

    for (int i = 0; i < level; i++) {
        cout << " ";
    }
    cout << "- " << root->name << endl;

    displayHierarchy(root->left, level + 1);
    displayHierarchy(root->right, level + 1);
}

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

    void reverseBatch() 
    {
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
    }

};

struct Parcel {
    int id;
    int priority;
};

Parcel parcels[MAX_SIZE];
int parcelCount = 0;

void insertParcelArray(Parcel newParcel) {
    int i = parcelCount - 1;
    while (i >= 0 && parcels[i].priority > newParcel.priority) {
        parcels[i + 1] = parcels[i];
        i--;
    }
    parcels[i + 1] = newParcel;
    parcelCount++;
}

void displayParcelsArray() {
    cout << "Parcels sorted by priority:\n";
    for (int i = 0; i < parcelCount; i++) {
        cout << "ID: " << parcels[i].id << ", Priority: " << parcels[i].priority << endl;
    }
}

Node* head = nullptr;

void insertParcelLL(Parcel newParcel) {
    Node* newNode = new Node{newParcel.id, "", newParcel.priority, "", nullptr};

    if (!head || newParcel.priority < head->priority) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next && current->next->priority <= newParcel.priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void displayParcelsLL() {
    cout << "Parcels sorted by priority:\n";
    Node* current = head;
    while (current) {
        cout << "ID: " << current->id << ", Priority: " << current->priority << endl;
        current = current->next;
    }
}

int main() {
    ParcelQueue pq;

    pq.enqueue(101, "123 Main St", 2);
    pq.enqueue(102, "456 Elm St", 1);
    pq.enqueue(103, "789 Oak Rd", 3);

    cout << "Front Parcel ID: " << pq.getFrontID() << endl;
    pq.getSize();

    pq.display();

    pq.dequeue();
    pq.dequeue();

    cout << "Front Parcel ID: " << pq.getFrontID() << endl;
    cout << "Rear Parcel ID: " << pq.getRearID() << endl;

    pq.dequeue();
    pq.dequeue(); // Underflow test


    TreeNode* root = new TreeNode("Country");

    TreeNode* region1 = new TreeNode("Region A");
    TreeNode* region2 = new TreeNode("Region B");

    TreeNode* city1 = new TreeNode("City X");
    TreeNode* city2 = new TreeNode("City Y");
    TreeNode* city3 = new TreeNode("City Z");

    TreeNode* zone1 = new TreeNode("Zone 1");
    TreeNode* zone2 = new TreeNode("Zone 2");
    TreeNode* zone3 = new TreeNode("Zone 3");

    root->left = region1;
    root->right = region2;

    region1->left = city1;
    region1->right = city2;
    region2->left = city3;

    city1->left = zone1;
    city2->left = zone2;
    city3->left = zone3;

    cout << "Region-City-Zone Hierarchy:\n";
    displayHierarchy(root);

    delete root;
    delete region1;
    delete region2;
    delete city1;
    delete city2;
    delete city3;
    delete zone1;
    delete zone2;
    delete zone3;


    Parcel p1 = {201, 2};
    Parcel p2 = {202, 1};
    Parcel p3 = {203, 3};

    insertParcelArray(p1);
    insertParcelArray(p2);
    insertParcelArray(p3);

    displayParcelsArray();

    ParcelStack stack;

    stack.push("Parcel A");
    stack.push("Parcel B");
    stack.push("Parcel C");

    stack.reverseBatch();

    stack.display();

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    Parcel p4 = {101, 2};
    Parcel p5 = {102, 1};
    Parcel p6 = {103, 3};

    insertParcelLL(p4);
    insertParcelLL(p5);
    insertParcelLL(p6);

    displayParcelsLL();

    return 0;
}
