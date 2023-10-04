#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int data){
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
    void push_back(int data){
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
    void push_front(int data){
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
    int size(){
        Node *node = head;
        int iter=0;
        while(node != NULL ){
            node = node->next;
            iter++;
        }
        return iter;
    }
    void addIndex(int index, int val){
        if(index < 0 || index > this-> size()) return;
        else if(index == 0) this->push_front(val);
        else if(index == this->size()) this->push_back(val);
        else {
            Node *temp = new Node(val);
            Node *cur = this->head;
            for(int i = 1; i < index; i++){
                cur = cur->next;
            }
            temp->next = cur->next;
            cur->next = temp;
        }
    }
    Node* search(int data){
        Node *node = head;
        while(node != NULL && node->data != data){
            node = node->next;
        }
        return node;
    }
    void print(){
        Node *node = head;
        while(node != NULL){
            cout<<node->data<<" ";
            node = node->next;
        }
        cout<<endl;
    }
    
   
};
int main(){
    LinkedList *ll = new LinkedList();
    int n, k, x;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        ll->push_back(a);
    }
    cin>>k>>x;
    ll->addIndex(x,k);
    ll->print();

}