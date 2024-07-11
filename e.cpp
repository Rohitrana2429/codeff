#include<bits/stdc++.h>
using namespace std;
 
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
namespace Random
{
    #define int long long
    int Rand(int l , int r)
    {
        return uniform_int_distribution<int>(l , r)(rng);
    }
    #undef int 
}
 
using i64 = long long;
using ui64 = unsigned long long;
 
#define MASK(x) ((i64)(1) << (x))
#define BIT(mask , x) (((mask) >> (x)) & (1))
#define sz(x) (x).size()
#define all(x) (x).begin() , (x).end()
 
#define FOR(i ,a , b) for (int i = (a); i <= (b); ++i)
#define FORD(i , a , b) for (int i = (b); i >= (a); --i)
#define REP(i , a , b) for (int i = (a); i < (b); ++i)
#define REPD(i , a , b) for (int i = (b) - 1 ; i >= (a); --i)
 
template <class T> 
    void compress(vector<T> &a)
    {
        sort(a.begin() , a.end());
        a.resize(unique(a.begin() , a.end()) - a.begin());
        return;
    }
template<class T>
    void printArr(T& container , string separator = "" , string finish = "\n")
    {
        for (auto& item : container) cout << item << separator;
        cout << finish;
    }
 
template<class T>
    bool maximize(T &a , T b) {if (a < b) return a = b , true; else return false;}
template<class T>
    bool minimize(T &a , T b) {if (a > b) return a = b , true; else return false;}
template<class T>
    T gcd(T x , T y) {while (y) swap(y , x %= y); return x;}
template<class T>
    T lcm(T x , T y) {return (x * y) / gcd(x , y);}
 
//... INPUT
    void INPUT(string name)
    {
        iostream::sync_with_stdio(false); cin.tie(0);
        if (!fopen((name + ".inp").c_str() , "r")) return;
        freopen((name + ".inp").c_str() , "r" , stdin);
        freopen((name + ".out").c_str() , "w+" , stdout);
    }
 
#define int long long
const int maxa = 10000;
const int maxb = 10000;
 
string_to_i64(string x)
{
  i64 tmp = 0;
  for (int i = 0; i < sz(x); ++i)
    tmp = tmp * 10 + x[i] - '0';
  return tmp;
}
 
void solve()
{
  i64 n; cin>>n;
  i64 mx = n * maxa ;
  string s = to_string(n) , st = "";
  i64 xx = 0 , times = 0;
  vector<pair<int,int>> v;
  while (xx <= (i64)1e6)
  {
    FOR(i,1,maxa)
    {
      int j = (i - times) * sz(s);
      if (n * i - j == xx && j >= 1 && xx > 0)
        v.push_back({i , j});
    }
    if (sz(s) == 2)
    {
      string s1 = st + s[0];
      i64 xx1 = string_to_i64(s1);
      FOR(i,1,maxa)
      {
        int j = (i64)(i - times) * sz(s) - 1;
        if (n * i - j == xx1 && j >= 1 && xx1 > 0)
          v.push_back({i , j});
      }
    }
    if (sz(s)==3)
    {
      string s1 = st + s[0] + s[1];
      i64 xx1 = string_to_i64(s1);
      FOR(i,1,maxa)
      {
        int j = (i64)(i - times) * sz(s) - 2;
        if (n * i - j == xx1 && j >= 1 && xx1 > 0)
          v.push_back({i , j});
      }
    }
    st = st + s;
    xx = string_to_i64(st);
    ++times;
  }
  compress(v);
  cout << sz(v) << '\n';
  for (auto& x: v) cout << x.first << ' ' << x.second << '\n';
}
 
int32_t main()
{
    INPUT("main");
      int test; cin >> test;
      while(test--) solve();
    cerr << "\nTIME RUN : " << 1000 * clock()/CLOCKS_PER_SEC << " MS \n";
 
}
