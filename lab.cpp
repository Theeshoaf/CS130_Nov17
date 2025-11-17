#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val): data(val), left(nullptr), right(nullptr) {}
};


void printLevel(Node* root, int level){
    if (root == nullptr) return;
    if (level == 0) cout << root -> data << " ";
    else{
        printLevel (root -> left, level -1);
        printLevel (root -> right, level -1);
    }
}
  

Node *constructCBT(vector<int> &tree_values){
    Node *root = new Node(tree_values[0]);
    queue<Node *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i<tree_values.size()){
        Node *current = q.front();
        q.pop();
        if (i < tree_values.size()){
            current -> left = new Node(tree_values[i]);
            q.push(current -> left);
            i++; 
        }
        if (i < tree_values.size()){
            current -> right = new Node(tree_values[i]);
            q.push(current -> right);
            i++; 
        }
    }
    return root;
}


int main()
{
    vector<int> tree_values = {10,15,20,3,5,30,17};
    Node *root = constructCBT(tree_values);
%%writefile main.cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val): data(val), left(nullptr), right(nullptr) {}
};


void printLevel(Node* root, int level){
    if (root == nullptr) return;
    if (level == 0) cout << root -> data << " ";
    else{
        printLevel (root -> left, level -1);
        printLevel (root -> right, level -1);
    }
}


Node *constructCBT(vector<int> &tree_values){
    Node *root = new Node(tree_values[0]);
    queue<Node *> q;
    q.push(root);
    long unsigned int i = 1;
    while (!q.empty() && i< tree_values.size()){
        Node *current = q.front();
        q.pop();
        if (i < tree_values.size()){
            current -> left = new Node(tree_values[i]);
            q.push(current -> left);
            i++;
        }

        if (i < tree_values.size()){
            current -> right = new Node(tree_values[i]);
            q.push(current -> left);
            i++; 
        }
    }
    return root;
}


int main()
{
    vector<int> tree_values = {10,15,20,3,5,30,17};
    Node *root = constructCBT(tree_values);
    if (root == nullptr) cout << "null";
    printLevel (root, 0); cout << endl;
    printLevel (root, 1); cout << endl;
    printLevel (root, 2); cout << endl;
    printLevel (root, 3); cout << endl;
}
