#include<bits/stdc++.h>
using namespace std;

template <typename T, typename Combine = function<T(const T&, const T&)>>
class SegmentTree {
private:
    vector<T> tree;
    int n;
    T neutral;          // Neutral element for the combine operation
    Combine combine;    // The function to combine two elements

    void build(const vector<T>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            build(arr, leftChild, start, mid);
            build(arr, rightChild, mid + 1, end);
            tree[node] = combine(tree[leftChild], tree[rightChild]);
        }
    }

    void update(int node, int start, int end, int idx, const T& value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            if (idx <= mid) {
                update(leftChild, start, mid, idx, value);
            } else {
                update(rightChild, mid + 1, end, idx, value);
            }
            tree[node] = combine(tree[leftChild], tree[rightChild]);
        }
    }

    T query(int node, int start, int end, int l, int r) const {
        if (r < start || end < l) {
            return neutral;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        T leftResult = query(leftChild, start, mid, l, r);
        T rightResult = query(rightChild, mid + 1, end, l, r);
        return combine(leftResult, rightResult);
    }

public:
    SegmentTree(const vector<T>& arr, T neutralElement, Combine combineFunc)
        : n(arr.size()), neutral(neutralElement), combine(combineFunc) {
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void update(int idx, const T& value) {
        update(0, 0, n - 1, idx, value);
    }

    T query(int l, int r) const {
        return query(0, 0, n - 1, l, r);
    }
};

