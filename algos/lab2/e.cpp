#include <bits/stdc++.h>
using namespace std;

struct Node{
    string data;
    Node* next;
    Node* prev;

    Node(string  data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

struct LinkedList{
    Node *head,*tail;
    LinkedList(){
        head=NULL;
        tail=NULL;

    }

    void pop_back(){
        if(tail!=NULL){
            tail=tail->prev;
            tail->next = NULL;
        }
    }
    void pop_front(){
        if(head!=NULL){
            head = head->next;
            head->prev=NULL;

        }
    }
    void push_back(string data){
        Node *node = new Node(data);

        if(tail==NULL){
            tail = node;
            head = node;
        }
        else{
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    void push_front(string data){
        Node *node = new Node(data);
        if(head == NULL){
            head = node;
            tail = node;
        }
        else{
            head->prev = node;
            node->next = head;
            head = node;

        }

    }

    void delete_element(Node *node){
        if(node == head){
            pop_front();
        }
        else if(node == tail){
            pop_back();
        }
        else{
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    } 

    void insert(Node *node1 ,Node *node2){
        if(node1 == tail){
            push_back(node2->data);

        }
        else{
            node1->next->prev = node2;
            node2->next = node1->next;
            node1->next = node2;
            node2->prev = node1;
        }
        
    }
    int size(){
        Node *node = head;
        int iter=0;
        while(node != NULL ){
            node = node->next;
            iter++;
        }
        return iter;
    }

    Node* search(string data){
        Node *node = head;
        while(node != NULL && node->data != data){
            node = node->next;
        }
        return node;
    }
    void print(){
        Node *node = tail;
        cout<<"All in all: "<<size()<<endl;
        cout<<"Students: "<<endl;
        while(node != NULL){
            cout<<node->data<<endl;
            node = node->prev;
        }
        cout<<endl;
    }
    
    
   
};
int main(){
    LinkedList *ll = new LinkedList();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(i==0){
            ll->push_back(s);
        }
        else if(ll->tail->data!=s){
            ll->push_back(s);
        }
    }
    ll->print();
   

}