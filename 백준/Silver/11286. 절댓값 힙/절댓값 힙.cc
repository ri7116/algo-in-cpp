#include <bits/stdc++.h>
using namespace std;

int heap[100000];
int sz = 0;

int front() {
    return heap[1];
}

void push(int x) {
    sz++;
    heap[sz] = x;
    int idx = sz;

    while (idx > 1) {
        int parent = idx / 2;

        if (abs(heap[idx]) < abs(heap[parent]) || 
            (abs(heap[idx]) == abs(heap[parent]) && heap[idx] < heap[parent])) {
            swap(heap[idx], heap[parent]);
            idx = parent;
        } else {
            break;
        }
    }
}

void pop() {
    heap[1] = heap[sz];
    sz--;
    int idx = 1;

    while (2 * idx <= sz) {
        int lc = 2 * idx;
        int rc = 2 * idx + 1;
        int minIdx = lc;

        if (rc <= sz) {
            if (abs(heap[rc]) < abs(heap[lc]) || 
                (abs(heap[rc]) == abs(heap[lc]) && heap[rc] < heap[lc])) {
                minIdx = rc;
            }
        }

        if (abs(heap[idx]) < abs(heap[minIdx]) || 
            (abs(heap[idx]) == abs(heap[minIdx]) && heap[idx] <= heap[minIdx])) {
            break;
        }

        swap(heap[idx], heap[minIdx]);
        idx = minIdx;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            if (sz == 0) {
                cout << 0 << "\n";
            } else {
                cout << front() << "\n";
                pop();
            }
        } else {
            push(t);
        }
    }
}
