#include <iostream>
#include <algorithm>

using namespace std;

struct Heap {
    long long int *a;
    long long int capacity;
    long long int size;

    long long int parent (long long int i) {
        return (i-1)/2;
    }
    long long int left (long long int i) {
        return i*2 + 1;
    }
    long long int right (long long int i) {
        return i*2 + 2;
    }
    void heapUp (long long int i) {
        long long int p = parent(i);
        if (i > 0 && a[i] < a[p]) {
            swap(a[i], a[p]);
            heapUp(p);
        }
    }
    void heapDown (long long int i) {
        long long int l = left(i);
        long long int r = right(i);
        long long int min = i;
        if (l < size && a[l] < a[min]) {
            min = l;
        }
        if (r < size && a[r] < a[min]) {
            min = r;
        }
        if (min != i) {
            swap(a[i], a[min]);
            heapDown(min);
        }
    }
    void add (long long int x) {
        a[size] = x;
        size++;
        heapUp(size-1);
    }

    void cut_min () {
        a[0] = a[size-1];
        size = max((long long)0, size - 1);
        heapDown(0);
    }
    
    Heap (long long int x) {
        this->a = new long long int[x];
        this->size = 0;
        this->capacity = x;
    }
};

int main() {
    long long int n, k;
    cin >> n >>k;
    long long int capacity = n;
    Heap heap(capacity);
    long long int num;
    for(int i = 0; i < n;i++){
        cin >> num;
        heap.add(num);
    }


    for(int i=0; i<n;i++) {
        if(heap.a[0]>k){
            cout<<i;
            return 0;
        }
        long long local = 0;
        local += heap.a[0];
       
        heap.cut_min();
        local += 2*heap.a[0];
        
        heap.cut_min();
        heap.add(local);
        
    }
    cout << -1;
    return 0;
}