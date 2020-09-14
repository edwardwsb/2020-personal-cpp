#include<bits/stdc++.h>
using namespace std;

unordered_map<string,long long>namenum,totnum,personnum;

void init() {
	freopen("2020-01-01-15.json","r",stdin);
	string s;
	while (getline(cin,s)) {
		bool f1=0; bool f2=0; bool f3=0; string name="";	string person=""; string type="";
		for (int i=0;i<=s.size()-1;i++) if (s[i]=='\"') {
			i++;  string now="";
			while (s[i]!='\"') {
				now+=s[i++];
			}
			i++;
			if (now=="type" && !f1) { int t=0; 
				while (t<2) { if (t==1 && s[i]!='\"') type+=s[i]; if (s[i]=='\"') t++; i++; } f1=1;
			}
			if (now=="name" && !f2) { int t=0;
				while (t<2) { if (t==1 && s[i]!='\"') name+=s[i]; if (s[i]=='\"') t++; i++; } f2=1;
			}
			if (now=="login" && !f3) { int t=0; 
				while (t<2) { if (t==1 && s[i]!='\"') person+=s[i]; if (s[i]=='\"') t++; i++; } f3=1;
			}
		}
		if (type!="PushEvent" && type!="IssueCommentEvent" && type!="IssuesEvent" && type!="PullRequestEvent") continue;
		//dd(person); dd(type); de(name);
		personnum[person+'+'+type]++; 
		namenum[name+'+'+type]++;
		totnum[person+'+'+name+'+'+type]++;
	//	dd((string)person+'/'+type); dd((string)name+'/'+type); de((string)person+'/'+name+'/'+type);
	} 
	freopen("1.json","w",stdout);
	for (auto u:personnum) {
		cout<<u.first<<" "<<u.second<<"\n";
	}
	freopen("2.json","w",stdout);
	for (auto u:namenum) {
		cout<<u.first<<" "<<u.second<<"\n";
	}
	freopen("3.json","w",stdout);
	for (auto u:totnum) {
		cout<<u.first<<" "<<u.second<<"\n";
	}
} 

void getvoid1(string &person,string &type) {
	freopen("1.json","r",stdin);
	string s1;
	long long s2;
	while (cin>>s1) {
		cin>>s2; personnum[s1]=s2;
	}
	//cout<<person<<endl;
	//cout<<type<<endl;
	printf("%lld",personnum[person+'+'+type]);
	return ;
}

void getvoid2(string &name,string &type) {
	freopen("2.json","r",stdin);
	string s1;
	long long s2;
	while (cin>>s1) {
		cin>>s2; namenum[s1]=s2;
	}
	printf("%lld",namenum[name+'+'+type]);
	return ;
}

void getvoid3(string &person,string &name,string &type) {
	freopen("3.json","r",stdin);
	string s1;
	long long s2;
	while (cin>>s1) {
		cin>>s2; personnum[s1]=s2;
	}
	printf("%lld",personnum[person+'+'+name+'+'+type]);
	return ;
}
		

int main(int argc,char *argv[]){
	ios::sync_with_stdio(false);cin.tie(0);
	int p1=0; int p2=0; int p3=0;
	for (int i=0;i<argc;i++) {
		if (strcmp(argv[i],"-i")==0 || strcmp(argv[i],"--init")==0) p3=1; 
		if (strcmp(argv[i],"-u")==0 || strcmp(argv[i],"--user")==0) p1=1;
		if (strcmp(argv[i],"-r")==0 || strcmp(argv[i],"--repo")==0) p2=1;
		//cout<<argv[i]<<"-i"<<endl;
		//cout<<strcmp(argv[i],"-i")<<endl;
	}
	//cout<<p1<<" "<<p2<<" "<<p3<<endl;
	if (p3) init();
	string s1,s2,s3;
	for (int i=0;i<argc;i++) {
		if (strcmp(argv[i],"-u")==0 || strcmp(argv[i],"--user")==0) s1=argv[i+1];
		if (strcmp(argv[i],"-r")==0 || strcmp(argv[i],"--repo")==0) s2=argv[i+1];
		if (strcmp(argv[i],"-e")==0 || strcmp(argv[i],"--event")==0)  s3=argv[i+1];
	}
	//cout<<s1<<" "<<s2<<" "<<s3<<endl;
	if (p1 && p2) getvoid3(s1,s2,s3);
	else if (p1) getvoid1(s1,s3);
	else if (p2) getvoid2(s2,s3); 
	return 0;
}

