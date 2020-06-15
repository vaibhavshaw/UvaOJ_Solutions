
/*  author: @golu    */

#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<boost/tokenizer.hpp>
using namespace std;
//using namespace __gnu_pbds;
//using namespace boost;
#define _CRT_SECURE_NO_DEPRECATE
#pragma GCC optimize("Ofast")
#define int long long
#define double long double
#define all(x) x.begin(),x.end()
#define null NULL
#define debug(x)     cout<< #x << '\t' << x << endl
#define VISITED 1
#define UNVISITED -1
#define EXPLORED 2
#define P_INF LLONG_MAX            
#define N_INF LLONG_MIN
#define INF 1000000000  // 1e9
#define mod 1000000007  // 1e9 +7
#define _sieve_size 10000010  // 1e7 +10
#define EPS static_cast<double>(1e-9)
#define sz(a) static_cast<int>(a.size())
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define endl "\n"

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef greater<int> gi;

/*
inline int left(int p){ 
  return 1+ (p<<1);
}
inline int right(int p){
  return 1+ left(p);
}
inline int LSOne(int i){
  return i& (-i);
}
*//*
vs Tokenizer(const string& str,const string& delim){  
  vs tokens;
  auto lPos=str.find_first_not_of(delim,0);
  auto pos=str.find_first_of(delim,lPos);
  while(string::npos!=pos || string::npos!=lPos){  
    tokens.push_back(str.substr(lPos,pos-lPos));
    lPos=str.find_first_not_of(delim,pos);
    pos=str.find_first_of(delim,lPos);
  }
  return tokens;
}
*//*
template<typename T> 
using ordered_set= 
tree<
T,
null_type,
less<T>,
rb_tree_tag,
tree_order_statistics_node_update>;
*/

template<typename... T>
void in(T&... args){
  ((cin>>args), ...);
}

template<typename... T>
void _out(T&&... args){
  ((cout<<args), ...);
}

template<typename... T>
void out(T&&... args){
  ((cout<<args<<endl), ...);
}


const int MAX_N = 10;
ii a[MAX_N]; int n,target;
double d[MAX_N][MAX_N];
double dp[MAX_N][1<<MAX_N];
vii v;

string s1="Cable requirement to connect ";




double solve(int pos,int bitmask){
  if(bitmask==target) return 0.00;
  if(dp[pos][bitmask]!=-1.0) return dp[pos][bitmask];
  double ans=1000000000.0;
  for(int nxt=0;nxt<n;nxt++){
    if(!(bitmask&(1<<nxt)) && nxt!=pos){
      ans=min(ans,d[pos][nxt]+solve(nxt,bitmask|(1<<nxt)));
    }
  }
  return dp[pos][bitmask]=ans;
}




void go(int pos,int bitmask){
  if(bitmask==target) return;
  for(int nxt=0;nxt<n;nxt++){
    if(!(bitmask&(1<<nxt)) && nxt!=pos){
      if(dp[pos][bitmask]==d[pos][nxt]+
        solve(nxt,bitmask|(1<<nxt))){
        v.pb(ii(pos,nxt)); go(nxt,bitmask|(1<<nxt));
        break;
      }
    }
  }
}





signed main(void){

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  #endif // ONLINE_JUDGE
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);std::cout.tie(0);
  int nw=1;
  while(in(n),n){
    int x,y; v.clear();
    for(int i=0;i<n;i++){
      in(x,y); a[i]=ii(x,y);
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        ii X=a[i]; ii Y=a[j];
        d[i][j]=hypot(X.ff-Y.ff,X.ss-Y.ss)+16.0;
      }
    }
    target=(1<<n)-1;
    out("**********************************************************");
    _out("Network #",nw,'\n'); nw+=1;
    for(int i=0;i<=n;i++){
      for(int j=0;j<=(1<<n);j++)
        dp[i][j]=-1.0;
    }
    double ans=1000000000.0;
    double save; int idx;
    for(int i=0;i<n;i++){
      save=solve(i,(1<<i));
      if(ans>save){
        ans=save; idx=i;
      }
    } 
    go(idx,(1<<idx));
    for(int i=0;i<sz(v);i++){
      ii p1=a[v[i].ff],p2=a[v[i].ss];
      _out(s1,'(',p1.ff,',',p1.ss,") to ",
      '(',p2.ff,',',p2.ss,") is ");
      cout<<fixed<<setprecision(2)<<d[v[i].ff][v[i].ss]<<" feet."<<endl;
    }
    _out("Number of feet of cable required is ");
    cout<<fixed<<setprecision(2)<<ans<<'.'<<endl;



    //if(cin.eof()) break;
  }
  

    
    




    
    







  return 0;
}