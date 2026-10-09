#include<bits/stdc++.h>
#define N 1000000
using namespace std;

bitset<30> ST[N];

string s;

void build(int SI,int b,int e){
	if(b==e){
		ST[SI][(s[b]-'a')]=1;
		return;
	}

	int left=2*SI;
	int right=(2*SI)+1;
	int mid=(b+e)/2;

	build(left,b,mid);
	build(right,mid+1,e);

	ST[SI]=(ST[left]|ST[right]);
}

void update(int SI,int b,int e,int l,int r,char newChar,char currChar){
	if(l>e or r<b){
		return;
	}
	if(b>=l and e<=r){
		ST[SI][currChar-'a']=0;
		ST[SI][newChar-'a']=1;
		return;
	}

	int left=2*SI;
	int right=(2*SI)+1;
	int mid=(b+e)/2;

	update(left,b,mid,l,r,newChar,currChar);
	update(right,mid+1,e,l,r,newChar,currChar);

	ST[SI]=(ST[left]|ST[right]);
}

bitset<30> query(int SI,int b,int e,int l,int r){
	bitset<30> dummy(0);
	if(l>e or r<b){
		return dummy;
	}
	if(b>=l and e<=r){
		return ST[SI];
	}

	int left=2*SI;
	int right=(2*SI)+1;
	int mid=(b+e)/2;

	bitset<30> L = query(left,b,mid,l,r);
	bitset<30> R = query(right,mid+1,e,l,r);

	return (L|R);
}




int main(){
	cin>>s;
	int n=s.size();
	s="#"+s;
	for(int i=1;i<=n;i++){
		bitset<30> dummy(0);
		ST[i]=dummy;
	}

	build(1,1,n);

	int q;				cin>>q;
	while(q--){
		int type;		cin>>type;
		if(type==1){
			// update
			int pos;
			char c;		cin>>pos>>c;
			update(1,1,n,pos,pos,c,s[pos]);
			s[pos]=c;
		}
		else if(type==2){
			// query
			int l,r;	cin>>l>>r;
			bitset<30> capture = query(1,1,n,l,r);
			cout<<capture.count()<<endl;
		}
	}

	return 0;
}