#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define soot(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define pb push_back
#define btoe(v) v.begin(),v.end()
#define endl '\n'
#define fmin(v) *min_element(v.begin(),v.end())
#define fmax(v) *max_element(v.begin(),v.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define opt(ans) cout << ans << endl;

void solve(){
    int n,k;
    cin >> n >> k;
   int a[k];
    vector<int>v(k);
    for(int i = 1;i <= k;i++){
        cin >> a[i];
        v.pb(a[i]);
    }
   // soot(v);
    sort(a + 1, a + 1 + k);
    int ans = n;
    ans = ans - a[k];

    for(int i = 1;i < k;i++){
        ans+= (a[i] - 1);
    }
    cout << ans << endl;
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
   //solve();
    return 0;
}
