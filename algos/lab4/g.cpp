#include <iostream>

using namespace std;

struct node {
  int val;
  node* left;
  node* right;
  node(int val) {
    this->val = val;
    left = NULL;
    right = NULL;
  }
};

struct bst {
 public:
  int triangles;
  bst() { root = NULL; }
  void add(int val) { root = add(root, val); }
  void print() { print(root); }
  bool find(int val) { return find(root, val) != NULL; }
  void print_sub(int x) { printNonSort(find(root, x)); }
  int getPath() { return getPath(root); }

 private:
  node* root;
  node* add(node* current, int val) {
    if (current == NULL) {
      current = new node(val);
    } else if (val < current->val) {
      current->left = add(current->left, val);
    } else if (val > current->val) {
      current->right = add(current->right, val);
    }
    return current;
  }

  void print(node* current) {
    if (current != NULL) {
      print(current->left);
      cout << current->val << " ";
      print(current->right);
    }
  }

  void printNonSort(node* current) {
    if (current != NULL) {
      cout << current->val << " ";
      printNonSort(current->left);
      printNonSort(current->right);
    }
  }
  node* find(node* current, int val) {
    if (current == NULL) return NULL;
    if (current->val == val) return current;
    if (current->val < val) return find(current->right, val);
    return find(current->left, val);
  }

  node* rightmost(node* current) {
    if (current == NULL) return NULL;
    if (current->right == NULL) return current;
    return rightmost(current->right);
  }
  int height(node* current, int& diameter) {
    if (current == NULL) return 0;
    int lH = height(current->left, diameter);
    int rH = height(current->right, diameter);
    diameter = max(diameter, lH + rH);
    return 1 + max(lH, rH);
  }

  int getPath(node* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
  }
};

int main() {
  int n;
  cin >> n;
  bst* b = new bst();
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    b->add(num);
  }
  int diameter = b->getPath() + 1;
  cout << diameter << endl;
  return 0;
}