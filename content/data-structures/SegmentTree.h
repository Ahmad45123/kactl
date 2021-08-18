/**
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: folklore
 * Description: One-indexed max-tree. Bounds are inclusive to the left and inclusive to the right.
 * Time: O(\log N)
 * Status: stress-tested
 */
#pragma once


const int N = 3e5+5;
int ST[N];
int a[N];
int n,q;
int lazy[N];

void buildST(int node=1, int l=1, int r=n){
    if(l == r){
        ST[node]=a[node+1-n];
        return;
    }
    int mid = l + r >> 1;
    int leftChild = node << 1;
    int rightChild = node << 1 | 1;
    buildST(leftChild, l, mid);
    buildST(rightChild, mid+1, r);
    ST[node] = ST[leftChild] + ST[rightChild];
}

void propagate(int node, int l, int r){
    int leftChild = node << 1;
    int rightChild = node << 1 | 1;
    int mid = l + r >> 1;
    ST[leftChild]+=lazy[node]*(mid - l + 1);
    ST[rightChild]+=lazy[node]*(r - mid);
    lazy[leftChild]+=lazy[node];
    lazy[rightChild]+=lazy[node];
    lazy[node]=0;
}

int query(int i, int j, int node=1, int l=1, int r=n){
    if(i <= l && r <= j)
        return ST[node];
    if(r < i || l > j)
        return 0; // neutrlizing agent that doesn't affect the answer.
    propagate(node, l, r);
    int mid = l + r >> 1;
    int leftChild = node << 1;
    int rightChild = node << 1 | 1;
    int left = query(i, j, leftChild, l, mid);
    int right = query(i, j, rightChild, mid+1, r);
    return left + right;
}

void update_point(int i, int val){
    int node = i + n - 1;
    ST[node] += val;
    while(node!=1){
        node>>=1;
        int leftChild = node << 1;
        int rightChild = node << 1 | 1;
        ST[node]=ST[leftChild]+ST[rightChild];
    }
}

void updateRange(int i, int j, int val, int node=1, int l=1, int r=n){
    if(i <= l && r <= j){
        ST[node]+=val*(r-l+1);
        lazy[node]+=val;
        return;
    }
    if(r < i || l > j)return;
    propagate(node, l, r);
    int mid = l + r >> 1;
    int leftChild = node << 1;
    int rightChild = node << 1 | 1;
    updateRange(i, j, val, leftChild, l, mid);
    updateRange(i, j, val, rightChild, mid+1, r);
    ST[node] = ST[leftChild]+ST[rightChild];
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)cin >> a[i];
    int newSize = 1;
    while(newSize<n)newSize<<=1;
    n=newSize;
    buildST();
    cin >> q;
    while(q--){
        int l,r; cin >> l >> r;
        cout << query(l, r) << '\n';
    }
}
