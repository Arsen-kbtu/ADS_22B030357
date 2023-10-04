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
            cout<<node->data<<"-->";
            node = node->next;
        }
        cout<<endl;
    }
    void nearest(int a,int min,int index){
        int i=0;
        Node *node = head;
        while(node != NULL){
            if(abs((node->data)-a)<min){
            min = abs((node->data)-a);
            index = i;
            }
            ++i;
            node = node->next;
            
        }
        cout<<index;
        
    }
};
int main(){
    int min=INT_MAX;
    int index=0;
    LinkedList *ll = new LinkedList();
    int n,a;
    cin>>n;
    for(int j=0;j<n;j++){
        int b;
        cin>>b;
        ll->push_back(b);
    }
    cin>>a;
    ll->nearest(a,min,index);


}