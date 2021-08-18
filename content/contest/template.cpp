#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define mst(x) memset(x,0,sizeof(x))
#define mcpy(a,b) memcpy(a, b, sizeof(a)) //arr copying into, arr copying from
#define lcase(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define ucase(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define getInts(nums,n) for(ll p=0;p<n;p++)cin >> nums[p]

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);


  cerr << "Run time: " << fixed << setprecision(3) << (double)clock() / CLOCKS_PER_SEC << "s" << endl;
  return 0;
}
