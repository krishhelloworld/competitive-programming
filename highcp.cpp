
#include <bits/stdc++.h>
using namespace std;

// ---------- Fast IO ----------
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)

// ---------- Type Aliases ----------
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vll = vector<ll>;

// ---------- Constants ----------
const ll INF = 1e18;
const int MOD = 1e9+7;

// ---------- Debugging ----------
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif

// ---------- Stream operators ----------
template <class A, class B> ostream& operator<<(ostream& os, const pair<A, B>& p){ return os << '(' << p.first << ", " << p.second << ')'; }
    template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << '{'; for(auto &x:v) os << x << ','; return os << '}'; }

// ---------- Lambda Recursion Helper ----------
struct Y {
    template <class F> struct wrapper {
        F f;
        template <class... Args> decltype(auto) operator()(Args&&... args) const {
            return f(*this, std::forward<Args>(args)...);
        }
    };
    template <class F> wrapper<F> operator()(F&& f) const {
        return { std::forward<F>(f) };
    }
} ycombinator;

// ---------- Custom Hash ----------
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template<class K,class V> using umap = unordered_map<K,V,custom_hash>;

// ---------- Utility Functions ----------
template<class T> bool chmax(T& a, const T& b){ return (a<b ? a=b,1:0); }
template<class T> bool chmin(T& a, const T& b){ return (b<a ? a=b,1:0); }

// ---------- Loop Macros ----------
#define rep(i,n) for(int i=0; i<(n); ++i)
#define all(x) begin(x), end(x)

void solve_Case(){
int t ;
cin>>t;
string s="lv";
vector<string>arr(t);
for(auto &A :: arr){
cin>> A;
}
for (int i = 0; i < n; i++) {
    
}



}

// ---------- Example Usage ----------
int main() {
    fast;
    int n; 
    cin>>n;
    while(n--){
        solve_Case();
    }


    // Example 1: recursive lambda (Y combinator)
    // auto fact = ycombinator([](auto self, int n) -> ll {
    //     if (n <= 1) return 1;
    //     return n * self(n - 1);
    // });
    // cout << "fact(5) = " << fact(5) << "\n";

    // // Example 2: container output
    // vector<int> v = {1,2,3,4};
    // cout << "v = " << v << "\n";

    // Example 3: unordered_map with custom hash
    // umap<int, string> m;
    // m[1] = "one";
    // m[2] = "two";
    // cout << "map[1] = " << m[1] << "\n";

    return 0;
}
    