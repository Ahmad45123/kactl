/**
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: folklore
 * Description: Zero-indexed max-tree. Bounds are inclusive to the left and exclusive to the right.
 * Time: O(\log N)
 * Status: stress-tested
 */
#pragma once


struct node {
    // variables
};
 
struct segtree {
    int size;
    vector<node> tree;
 
    node merge(node a, node b) {
        return {
            // Merge the nodes
        };
    }
 
    node single(ll v) {
        return {/* Value of one item */};
    }
 
    node NEUTRAL_ELEMENT = {/* Identity Value */};
 
    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2*size);
    }
 
    void build(vector<ll> &a, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < a.size()) {
                tree[x] = single(a[lx]);
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        
        tree[x] = merge(tree[2*x+1], tree[2*x+2]);
    }
    void build(vector<ll> &a) {
        build(a, 0, 0, size);
    }
 
    void set(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            tree[x] = single(v);
            return;
        }
        int m = (lx+rx)/2;
        if(i < m) {
            set(i, v, 2*x+1, lx, m);
        } else {
            set(i, v, 2*x+2, m, rx);
        }
        
        tree[x] = merge(tree[2*x+1], tree[2*x+2]);
    }
 
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }
 
    node eval(int l, int r, int x, int lx, int rx) {
        if(lx >= r || rx <= l) return NEUTRAL_ELEMENT;
        if(lx >= l && rx <= r) return tree[x];
        int m = (lx+rx)/2;
        return merge(eval(l, r, 2*x+1, lx, m), eval(l, r, 2*x+2, m, rx));
    }
 
    node eval(int l, int r) {
        return eval(l, r, 0, 0, size);
    }
};
