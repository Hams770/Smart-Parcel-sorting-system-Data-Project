#include <iostream>
using namespace std;

struct TreeNode {
string name;
TreeNode* left;
TreeNode* right;

TreeNode(string n) : name(n), left(nullptr), right(nullptr) {}
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

int main() {
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

return 0;
}