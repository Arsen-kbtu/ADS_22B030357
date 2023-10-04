#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *next;

    Node(){
        this->val = 0;
        this->next = NULL;
    }
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
    Node(int val, Node *next){
        this->val = val;
        this->next = next;
    }
};

struct LList{
    int size;
    Node *head, *tail;

    LList(){
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    void addHead(int val){
        Node *temp = new Node(val);
        if(this->head == NULL){
            this->head = temp;
            this->tail = temp;
        } else {
            temp->next = this->head;
            this->head = temp;
        }
        size++;
    }

    void addTail(int val){
        Node *temp = new Node(val);
        if(this->tail == NULL){
            this->head = temp;
            this->tail = temp;
        } else {
            this->tail->next = temp;
            this->tail = temp;
        }
        size++;
    }

    void addIndex(int index, int val){
        Node *temp = new Node(val);
        if(index < 0 || index > this-> size) return;
        else if(index == 0) this->addHead(val);
        else if(index == this->size) this->addTail(val);
        else {
            Node *temp = new Node(val);
            Node *cur = this->head;
            for(int i = 1; i < index; i++){
                cur = cur->next;
            }
            temp->next = cur->next;
            cur->next = temp;
            size++;
        }
    }

    int get(int index){
        if(index < 0 || index >= this->size) return -1;
        Node *cur = this->head;
        for(int i = 0; i < index; i++){
            cur = cur->next;
        }
        return cur->val;
    }

    void delIndex(int index){
        Node *cur = this->head;
        if(index == 0){
            this->head = cur->next;
            // size--;
        } else if(index == this->size -1){
            while(cur->next != this->tail){
                cur = cur->next;
            }
            this->tail = cur;
            // size--;
        } else if (index > 0 && index < this->size){
            for(int i = 0; i < index -1; i++){
                cur = cur->next;
            }
            cur->next = cur->next->next;
        }
        size--;
    }

    void Print(){
        Node *cur = this->head;
        while(cur != NULL){
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    int Top(){
        return head->val;
    }
    int Last(){
        return tail->val;
    }

    bool Empty(){
        return size == 0;
    }

    bool notEmpty(){
        return size != 0;
    }

    int Size(){
        return size;
    }
};



int main(){
    LList *ll = new LList();
    LList *ll2 = new LList();
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        arr[i] = t;
        // cout << i << "   "<< n << endl;
    }
    int cnt = 0, cnt1 = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(arr[i] == arr[j]) cnt++;
        }
        if(cnt1 == 0) 
        cnt1 = cnt;
        if(cnt == cnt1){
            ll->addHead(arr[i]);            
        } else if(cnt > cnt1){
            cnt1 = cnt;
            while(ll->notEmpty()){
                ll->delIndex(0);
            }
            ll->addHead(arr[i]);
        }
        // ll->Print();
        cnt = 0;
    }
    int cnt2 = 0, p;
    // ll->Print();
    while(ll->notEmpty()){
        for(int i = 0; i < ll->Size(); i++){
            for(int j = 0; j < ll->Size(); j++){
                if(ll->get(i) >= ll->get(j)) cnt2++;
            }
            // cout << cnt2 << " " << ll->Size() << "   ";
            if(cnt2 == ll->Size()){
                p = i;
                // ll2->addHead(ll->get(i));
            }
            cnt2 = 0;
        } 
        ll2->addTail(ll->get(p));
        ll->delIndex(p);
        // cout << p << "   ";
        
        // ll->Print();
        // ll2->Print();
        // p = 0;
    }

    ll2->Print();

    return 0;
}