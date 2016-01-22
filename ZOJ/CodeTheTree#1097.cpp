#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <list>
#include <queue>
#include <utility>
using namespace std;

struct Node {
    int index;
    Node *parent;
    list<Node*> child;
    Node():index(0),parent(NULL){}
};

typedef pair<int,Node*> MyPair;

bool operator < (const MyPair &a, const MyPair &b){
    return (a.first > b.first) || (a.first == b.first && a.second > b.second);
}

string line;
string str;
vector<int> match;
priority_queue<MyPair> pq;
char buf[4096];

Node* build_tree(int start, int end){
    int num;
    sscanf(str.c_str() + start + 1, "%d", &num);
    Node *node = new Node;
    node->index = num;
    int pos = start + 1;
    while(pos < end){
        while(pos < end && line[pos] != '(') pos++;
        if(pos >= end) break;
        //printf("start %d, end %d, pos %d match %d\n", start, end, pos, match[pos]+1);
        Node *new_node = build_tree(pos, match[pos] + 1);
        new_node->parent = node;
        node->child.push_back(new_node);
        pos = match[pos] + 1;
    }
    return node;
}

void print_tree(Node *node){
    if(!node) return;
    printf("%d ", node->index);
    list<Node*> &child = node->child;
    for(list<Node*>::iterator it = child.begin(); it != child.end(); it++){
        print_tree(*it);
    }
}
void init_traverse(Node *node){
    if(node->child.empty()) {
        pq.push(MyPair(node->index, node));
        return;
    }
    for(list<Node*>::iterator it = node->child.begin(); it != node->child.end(); it++){
        init_traverse(*it);
    }
}

int main(int argc, char const *argv[])
{
    while(getline(cin, line)) {
        str = line;
        int len = line.length();
        match.resize(len, -1);
        list<int> stack;
        for(int i = 0; i < len; i++) {
            if(line[i] == '(') stack.push_back(i);
            else if(line[i] == ')'){
                int id = stack.back();
                match[id] = i;
                stack.pop_back();
            }
            if(str[i]=='(' || str[i]==')') str[i] = ' ';
        }
        Node *root = build_tree(0, len);
        while(!pq.empty()) pq.pop();
        init_traverse(root);
        //print_tree(root);
        //printf("\n");
        int first = 1;
        while(!root->child.empty()){
            Node *node = pq.top().second;
            Node *parent = node->parent;
            if(root->index < node->index && root->child.size() == 1){
                Node *root_child = root->child.front();
                if(first) first = 0;
                else printf(" ");
                printf("%d", root_child->index);
                delete root;
                root = root_child;
                continue;
            }
            pq.pop();
            if(first) first = 0;
            else printf(" ");
            printf("%d", parent->index);
            list<Node*>::iterator it = parent->child.begin();
            for(; it != parent->child.end(); it++){
                if(*it == node) break;
            }
            parent->child.erase(it);
            delete node;
            if(parent->child.empty()){
                pq.push(MyPair(parent->index, parent));
            }
        }
        printf("\n");
    }
    return 0;
}
