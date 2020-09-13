#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<int>vi;
typedef vector<ll>VI;
typedef pair<int,int>pii;
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define dep(i,a,b) for (int i=a;i>=b;i--)
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
const int N=5e3+10;
const int M=2e6+10;
const int maxn=60;
const double pi=acos(-1);
const ll mod=998244353;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll qpow(ll a,ll b){ll s=1;while(b>0){if(b&1)s=s*a%mod;a=a*a%mod;b>>=1;}return s;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

unordered_map<string,ll>namenum,totnum,personnum;

void init() {
	ios::sync_with_stdio(false);cin.tie(0);
	string s;
	while (getline(cin,s)) {
		bool f=0; string name="";	string person=""; string type="";
		rep(i,0,sz(s)-1) if (s[i]=='\"') {
			i++;  string now="";
			while (s[i]!='\"') {
				now+=s[i++];
			}
			i++;
			if (now=="type" && !f) { int t=0; 
				while (t<2) { if (t==1 && s[i]!='\"') type+=s[i]; if (s[i]=='\"') t++; i++; } f=1;
			}
			if (now=="name") { int t=0;
				while (t<2) { if (t==1 && s[i]!='\"') name+=s[i]; if (s[i]=='\"') t++; i++; }
			}
			if (now=="login") { int t=0;
				while (t<2) { if (t==1 && s[i]!='\"') person+=s[i]; if (s[i]=='\"') t++; i++; }
			}
		}
		if (type!="PushEvent" && type!="IssueCommentEvent" && type!="IssuesEvent" && type!="PullRequestEvent") continue;
		dd(person); dd(type); de(name);
		personnum[person+'+'+type]++;
		namenum[name+'+'+type]++;
		totnum[person+'+'+name+'/'+type]++;
	//	dd((string)person+'/'+type); dd((string)name+'/'+type); de((string)person+'/'+name+'/'+type);
	} 
} 

int main(){
	//freopen("shuju.json","r",stdin);
	init();
	string s;	 
	return 0;
}

