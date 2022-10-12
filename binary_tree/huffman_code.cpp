#include<map>
#include<queue>
#include<vector>
#include<iostream>

using namespace std;

class huffman_tree{
protected:
    class huffman_node{
    public:
        char letter;
        int freq;
        huffman_node * left,* right;
        huffman_node() : letter('*'), freq(0), left(NULL), right(NULL) {}
        huffman_node(char letter,int freq,huffman_node * left,huffman_node * right):
            letter(letter),
            freq(freq),
            left(left),
            right(right)
            {}
        bool is_leaf() {
            return (left == NULL) && (right == NULL);
        }
    };

    class node_comparator{
    public:
        bool operator()(const huffman_node * a, const huffman_node * b){
            return (a->freq) > (b->freq);
        }

    };

protected:
    huffman_node *root;
    void build_tree(vector<huffman_node *> data){
        node_comparator comp;
        priority_queue<huffman_node*,vector<huffman_node*>,node_comparator> pq(comp);
        for(auto * i: data) pq.push(i);
        while(pq.size() >1){
            huffman_node * right = pq.top(); pq.pop();
            huffman_node * left = pq.top(); pq.pop();
            pq.push(new huffman_node('*',left->freq + right->freq,left,right));
        }   
        root = pq.top();
    }
public:
    huffman_tree(string s){
        map<char,int> count;
        for(auto i : s) count[i] ++;
        vector<huffman_node*> nodes;
        for(auto & x: count){
            nodes.push_back(new huffman_node(x.first,x.second,NULL,NULL));
        }
        build_tree(nodes);
    }
    void print_tree_util(huffman_node* node,string s = ""){
        if(node == NULL) return;
        if(node->is_leaf()){
            cout<<node->letter<<":"<<node->freq<<" = "<<s<<'\n';
        }
        print_tree_util(node->left,s+"0");
        print_tree_util(node->right,s+"1");
    }
    void print_tree(){
        print_tree_util(root);
    }
};

int main(){
    huffman_tree huffman("Nanana i am pp nanana");
    huffman.print_tree();
}