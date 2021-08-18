/**
 * Author: Johan Sannemo
 * Date: 2016-12-15
 * License: CC0
 * Description: Flattens a tree.
 */

int n;
int starting [(int)1e5+5] ;
int ending [(int)1e5+5] ;
vector<vector<int>>adj ;
int FAT[(int)1e5+5] ;
int timer =1 ;
void dfs_flating(int node,int par)
{
    FAT[timer]=node ;
    starting[node]=timer ;
    timer++ ;
    for(auto child:adj[node])
    {
        if(par!=child)
        {
            dfs_flating(child,node) ;
 
        }
 
    }
    ending[node]=timer ;
    FAT[timer]=node ;
    timer++ ;
}

int32_t main() {
    iso;
    cin>> n ;
    adj.resize(n+5) ;
    for(int i=0 ;i<n-1 ;i++)
    {
        int u ,v ;
        cin>>u>>v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }
    dfs_flating(1,-1) ;
    /*
    FAT is the new tree , if we wanna to know a subtree of a node , we can traverse from starting time of it
    from FAT to ending time of it from FAT
    Starting and ending are start and end time of each node
    array start  index > Node
        */

}