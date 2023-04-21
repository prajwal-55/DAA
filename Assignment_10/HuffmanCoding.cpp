#include <bits/stdc++.h>
using namespace std;

struct Huffman_Node{

    char data;
    unsigned freq;
    Huffman_Node *left, *right;
 
    Huffman_Node(char data, unsigned freq){
 
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct Compare {
    bool operator()(Huffman_Node* l, Huffman_Node* r){
        return (l->freq > r->freq);
    }
};

void print_Tree(struct Huffman_Node* root, string str){
    if (!root)
        return;
    // it means it reached the leaf node and print the code
    if (root->data != '#')
        cout << root->data << "    | " << str << "\n";
    // assign weight to nodes: if left add 0 to code
    // if right adds 1 to the code.
    // recursive calls for left and
    // right sub-tree of the generated tree.
    print_Tree(root->left, str + "0");
    print_Tree(root->right, str + "1");
}

void HuffCodes(char data[], int freq[], int size){
    struct Huffman_Node *left, *right, *top;
 
    priority_queue<Huffman_Node*, vector<Huffman_Node*>, Compare> Min_Heap;
 
    for (int i = 0; i < size; ++i)
        Min_Heap.push(new Huffman_Node(data[i], freq[i]));

    while (Min_Heap.size()!=1){
 
        // Extract the two minimum freq items from min heap
        left = Min_Heap.top();
        Min_Heap.pop();
 
        right = Min_Heap.top();
        Min_Heap.pop();
 
        // Create a new internal node with
        // frequency equal to the sum of the left and right node
        // Add this node to the min heap '#' is a special value
        // for internal nodes, not used
        top = new Huffman_Node('#', left->freq + right->freq);
 
        top->left = left;
        top->right = right;
 
        Min_Heap.push(top);
    }
    cout << "Char | Huffman code ";
    cout << "\n----------------------\n";
    print_Tree(Min_Heap.top(), "");
}

int main(){

    char arr[] = { 'a', 'b', 'c', 'd' , 'e' };
    int freq[] =  { 4, 7, 3, 2, 4 };
    int S = sizeof(arr) / sizeof(arr[0]);

    HuffCodes(arr, freq, S);
    return 0;
}
