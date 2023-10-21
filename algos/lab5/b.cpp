#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Heap {
    long long *a; //адрес к массиву с значениями в хипе
    long long capacity; //максимальный размер хипа
    long long size; //размер хипа на данный момент

    long long parent (long long i) {
        return (i - 1)/2;
    }

    long long left (long long i) {
        return i*2 + 1;
    }

    long long right (long long i) {
        return i*2 + 2;
    }

    void add (long long x) {
        a[size] = x;
        size++;
        heapUp(size - 1);
    }

    void heapUp (long long i) {
        if (i > 0) {
            long long p = parent(i);
            if (a[i] > a[p]) {
                swap(a[i], a[p]);
                heapUp(p);
            }
        }
    }

    void heapDown (long long i) {
        long long l = left(i);
        long long r = right(i);
        long long max = i;
        if (l < this->size && a[max] < a[l])
            max = l;
        if (r < this->size && a[max] < a[r])
            max = r;
        if (i != max) {
            swap(a[i], a[max]);
            heapDown(max);
        }
    }

    void cut_max () {
        a[0] = a[size - 1];
        size = max((long long)0, size - 1);
        heapDown(0);
    }

    void print(){
        for(long long i = 0; i < size; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }

    Heap (long long x) {
        this->a = new long long[x];
        this->capacity = x;
        this->size = 0;
    }
};
int main() {
    int n;
    cin >> n;
    int capacity = n;
    Heap heap(capacity);
    int num;
    for(int i = 0; i < n;i++){
        cin >> num;
        heap.add(num);
    }
    int rock1 = 0;
    int rock2 = 0;
    int remainRock = 0;
    while(heap.size>1){
        rock1 = heap.a[0];
        heap.cut_max();
        rock2 = heap.a[0];
        heap.cut_max();
        remainRock = abs(rock1-rock2);
        if(remainRock!=0){
            heap.add(remainRock);
        }
    }
    // while (heap.size > 1) {
    //     int y = heap.a[0];
    //     heap.cut_max();
    //     int x = heap.a[0];
    //     heap.cut_max();
    //     if (x < y) {
    //         y -= x;
    //         heap.add(y);
    //     }
    //     else if (x == y) {
    //         continue;
    //     }
    // }
    if (heap.size!=0){
        cout << heap.a[0];
    }
    else{
        cout << '0';
    }
}