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


int treeHeight(Node *root){
    if (root == nullptr) return -1;
    if ( root -> left = nullptr && root -> right = nullptr) return 0;
    return 1 + max(treeHeight(root-left), treeHeight(root-> right));
}


void printLevel(Node* root, int level){
    if (root == nullptr) return;
    if (level == 0){
        cout << root -> data << " "; saved.push_back(root -> data);
    }
    else{
        printLevel (root -> left, level -1);
        printLevel (root -> right, level -1);
    }
}


void printLevelOrder(Node *root, vector <int> &saved){
    int h = getHeight(root);
    for (int i =0 ; i<=h; i++{
        printLevel(root, i, saved); cout << endl;
    })
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
            q.push(current -> right);
            i++; 
        }
    }
    return root;
}


Node *constructBST(Node *root, int value){
    if (root == nullptr) return new Node(value);
    if (value < root -> data) 
        root -> left = constructBST(root->left, value);
    else 
        root -> right = constructBST(root->right, value);
    return root;
}

int main()
{
    vector<int> tree_values = {10,15,20,3,5,30,17};
    Node *root = constructCBT(tree_values);

    vector<int> tree_values2 = {4,2,1,3,6,5,7,8};
    root = nullptr;
    for (auto element: tree_values2){
        root = constructBST(root, element);
    }
}
