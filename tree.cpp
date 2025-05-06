#include <iostream>
#include <string>
#include "ParcelQueue.h"
using namespace std;

struct TreeNode {
    string name;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string n) : name(n), left(nullptr), right(nullptr) {}
};

void displayHierarchy(TreeNode* root, int level = 0) {
    if (root == nullptr) return;
    for (int i = 0; i < level; i++) cout << "  ";
    cout << "- " << root->name << endl;
    displayHierarchy(root->left, level + 1);
    displayHierarchy(root->right, level + 1);
}

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
    ParcelQueue queue;
    queue.enqueue(201, "Abha", 1);
    queue.enqueue(202, "Tabuk", 2);
    queue.enqueue(203, "Jazan", 1);
    queue.enqueue(204, "Najran", 3);

    TreeNode* root = buildTreeFromQueue(queue);
    
    cout << "\n--- Parcel Hierarchy Tree ---\n";
    displayHierarchy(root);

    return 0;
}
