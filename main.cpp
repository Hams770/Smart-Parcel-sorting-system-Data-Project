#include <iostream>
#include "ParcelQueue.h"
#include "stack.cpp"
#include "tree.cpp"
#include "priority.cpp"

using namespace std;


TreeNode* buildTreeFromQueue(ParcelQueue& queue) {
    Node* temp = queue.getFrontNode();
    if (!temp) return nullptr;

    TreeNode* root = new TreeNode(temp->parcel);
    temp = temp->next;

    TreeNode* current = root;
    while (temp) {
        if (!current->left) {
            current->left = new TreeNode(temp->parcel);
        } else if (!current->right) {
            current->right = new TreeNode(temp->parcel);
            current = current->left;  
        }
        temp = temp->next;
    }

    return root;
}

int main() {
    ParcelQueue pq;

    
    pq.enqueue(101, "123 amna St", 2);
    pq.enqueue(102, "456 batarji St", 1);
    pq.enqueue(103, "789 malik Rd", 3);
    pq.enqueue(104, "321 nayeem st ", 2);

    cout << "\n--- Parcel Queue ---\n";
    pq.display();

    
    Node* temp = pq.getFrontNode();
    while (temp) {
        insertParcelArray({ temp->id, temp->priority });
        temp = temp->next;
    }

    cout << "\n--- Sorted by Priority (Array) ---\n";
    displayParcelsArray();

    
    temp = pq.getFrontNode();
    while (temp) {
        insertParcelLL({ temp->id, temp->priority });
        temp = temp->next;
    }

    cout << "\n--- Sorted by Priority (Linked List) ---\n";
    displayParcelsLL();

    
    ParcelStack stack;
    temp = pq.getFrontNode();
    while (temp) {
        stack.push(temp->parcel);
        temp = temp->next;
    }

    cout << "\n--- Reversing Stack ---\n";
    stack.reverseBatch();
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    
    TreeNode* treeRoot = buildTreeFromQueue(pq);
    cout << "\n--- Parcel Hierarchy Tree ---\n";
    displayHierarchy(treeRoot);

    return 0;
}


