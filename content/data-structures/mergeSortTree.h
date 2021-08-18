/**
 * Author: Johan Sannemo
 * Date: 2016-12-15
 * License: CC0
 * Description: Merge Sort Segment Tree
 */

const int maxn = 1e5+10;
class Bit
{
public:
    vector<int> arr ;
    vector<vector<int>> tree ;
    Bit (vector<int> v)
    {
        arr.resize(maxn) ;  tree.resize(4*maxn) ;
        for (int i=0 ; i<v.size() ; i++) arr[i]=v[i] ;
    }
    void build(int node, int l, int r) {
        if(l == r) {
            tree[node].push_back(arr[l]);
            return;
        }
        int mid = (l + r) >> 1,
                left = node << 1, right = left|1;
 
        build(left, l, mid);
        build(right, mid+1, r);
 
        merge(all(tree[left]), all(tree[right]),
              back_inserter(tree[node]));
    }
    int query(int node, int l, int r, int i, int j, int k) {
        if(i > r || l > j) return 0;
        if(i <= l && r <= j) {
            return lower_bound(all(tree[node]), k)
                   - tree[node].begin();
        }
        int mid = (l + r) >> 1,
                left = node << 1, right = left|1;
        return query(left, l, mid, i, j, k) +
               query(right, mid+1, r, i, j, k);
    }
};

int32_t main()
{
    Bit tree2 (red2); tree2.build(1,0,red2.size()-1) ;
    ans+=tree2.query(1,0,red2.size()-1,0,i,red2[i]) ;   
}
