#include <iostream>

using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    node(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

struct bst{
    public:
        bst(){
            root = NULL;
        }
        void add(int val){
            root = add(root, val);
        }
        void print(){
            print(root);
        }
        bool find(int val){
            return find(root, val) != NULL;
        }
        void del(int val){
            root = del(root, val);
        }
        bool nodeExist(string str){
            return nodeExist(root, str);
        }
        int count(int n){
            node *current = find(root, n);
            return count(current);
        }
        void preorder(int n){
            node* current = find(root, n);
            preorder(current);
        }

    private:
        node * root;
    
        node * add(node * current, int val){
            if(current == NULL){
                current = new node(val);
            }
            else if(val < current->val){
                current->left = add(current->left, val);
            }
            else if(val > current->val){
                current->right = add(current->right, val);
            }
            return current;
        }

        void print(node * current){
            if(current != NULL){
                print(current->left);
                cout << current->val << " ";
                print(current->right);
            }
        }

        node * find(node * current, int val){
            if(current == NULL) return NULL;
            if(current->val == val) return current;
            if(current->val < val) return find(current->right, val);
            return find(current->left, val);
        }

        node * rightmost(node * current){
            if(current == NULL) return NULL;
            if(current->right == NULL) return current;
            return rightmost(current->right);
        }

        node * del(node * current, int val){
            if(current == NULL) return NULL;
            if(current->val == val){
                if(current->left == NULL && current->right == NULL){
                    delete current;
                    return NULL;
                }else if(current->left == NULL && current->right != NULL){
                    node * temp = current->right;
                    delete current;
                    return temp;
                }else if(current->left != NULL && current->right == NULL){
                    node * temp = current->left;
                    delete current;
                    return temp;
                }else if(current->left != NULL && current->right != NULL){
                    node * temp = rightmost(current->left);
                    if(temp != NULL){
                        current->val = temp->val;
                    }
                    current->left = del(current->left, current->val);
                }
            }else if(current->val > val){
                current->left = del(current->left, val);
            }
            else if(current->val < val){
                current->right = del(current->right, val);
            }
            return current;
        }
        bool nodeExist(node * current, string str){
            char a;
            for(int i = 0; i < str.size();i++){
                a = str[i];
                if(a=='L'){
                    if(current->left==NULL){
                        return false;
                    }
                    current = current->left;
                }
                else if(a=='R'){
                    if(current->right==NULL){
                        return false;
                    }
                    current = current->right;
                }
            }
            return true;
        }
        int count(node *current){
            int cnt=1;
            if(current->left!=NULL){
                cnt+=count(current->left);
            }
            if(current->right!=NULL){
                cnt+=count(current->right);
            }
            return cnt;

        }
        void preorder(node *current){
            cout<<current->val<<" ";
            if(current->left!=NULL){
                preorder(current->left);
            }
            if(current->right!=NULL){
                preorder(current->right);
            }
            return;
        }
};

int main() {
    int n, k;
    cin >> n;
    bst* b= new bst();
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        b->add(a);
    }
    cin>>k;
    b->preorder(k);

    
}