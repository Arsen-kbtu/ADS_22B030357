#include <bits/stdc++.h>
using namespace std;

struct Node{
    string data;
    Node* next;
    Node* prev;

    Node(string data){
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
    int size(){
        Node *node = head;
        int iter=0;
        while(node != NULL ){
            node = node->next;
            iter++;
        }
        return iter;
    }
    void pop_back(){
        if(tail != NULL){
            if (tail == head) {
                delete tail;
                tail = NULL;
                head = NULL;
            } else {
                tail = tail->prev;
                tail->next = NULL;
            }
        }
    }

    void pop_front(){
        if(head != NULL){
            if (head == tail) {
                delete head;
                head = NULL;
                tail = NULL;
            } else {
                head = head->next;
                head->prev = NULL;
            }
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

    Node* search(string data){
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
    
   
};
int main(){
    LinkedList *ll = new LinkedList();
    string s, output="";
    while(true){
        cin>>s;
        if(s=="add_front"){
            string name;
            cin>>name;
            ll->push_front(name);
            output+="ok\n";

        }
        else if(s=="add_back"){
            string name;
            cin>>name;
            ll->push_back(name);
            output+="ok\n";
        }
        else if(s=="erase_front"){
            if(ll->size()==0){
                output+="error\n";
            }
            else{
                output+=ll->head->data;
                output+="\n";
                ll->pop_front();
            }
            
        }
        else if(s=="erase_back"){
            if(ll->size()==0){
                output+="error\n";
            }
            else{
                output+=ll->tail->data;
                output+="\n";
                ll->pop_back();
            }
            
        }
        else if(s=="front"){
            if(ll->size()==0){
                output+="error\n";
            }
            else{
                output+=ll->head->data;
                output+="\n";
            }
            
        }
        else if(s=="back"){
            if(ll->size()==0){
                output+="error\n";
            }
            else{
                output+=ll->tail->data;
                output+="\n";
            }
            
        }
        else if(s=="clear"){
            while(ll->size()!=0){
                ll->pop_back();
            }
            output+="ok\n";
        }
        else if(s=="exit"){
            output+="goodbye";
            break;
        }
    }
    cout<<output;
}