#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

ostream& operator<<(ostream &os, const vector<int> &v){
	for(auto x:v)	os<<x<<' ';
	return os;
}

void build(vector<int> &v, int s, int e, vector<int> &st, int i){
	if(s>e)	return;
	if(s==e){
		st[i]=v[s];
		return;
	}
	int m=s+(e-s)/2;
	build(v, s, m, st, 2*i+1);
	build(v, m+1, e, st, 2*i+2);
	st[i]=st[2*i+1]+st[2*i+2];
}

vector<int> buildST(vector<int> &v){
	int n=v.size();
	int x=ceil(log2(n));
	int m=(1<<(x+1))-1;
	vector<int> st(m);
	build(v, 0, n-1, st, 0);
	return st;
}

int query(vector<int> &st, int i, int s, int e, int qs, int qe){
	if(qs<=s && qe>=e)
		return st[i];
	if(s>qe || e<qs)	return 0;
	int m=s+(e-s)/2;
	int left=query(st, 2*i+1, s, m, qs, qe), right=query(st, 2*i+2, m+1, e, qs, qe);
	return left+right;
}

void update(vector<int> &st, int i, int s, int e, int idx, int dif){
	if(idx<s || idx>e)	return;
	st[i]+=dif;
	if(s==e)	return;
	int m=s+(e-s)/2;
	update(st, 2*i+1, s, m, idx, dif);
	update(st, 2*i+2, m+1, e, idx, dif);
}

int calc_true(vector<int> &v, int s, int e){
	int res=0;
	for(int i=s; i<=e; ++i)
		res+=v[i];
	return res;
}

void test(vector<int> &v, vector<int> &st){
	vector<int> idx(v.size());
	iota(idx.begin(), idx.end(), 0);
	cout<<idx<<endl<<v<<endl<<st<<endl;
	for(int i=0; i<10; ++i){
		int x=rand()%v.size(), y=rand()%v.size();
		int s=min(x,y), e=max(x,y);
		cout<<s<<"->"<<e<<": "<<query(st, 0, 0, v.size()-1, s, e)<<"="<<calc_true(v, s, e)<<endl;
	}
}


int main() {
	vector<int> v(10);
	iota(v.begin(), v.end(), 1);
	random_shuffle(v.begin(), v.end());
	vector<int> st=buildST(v);
	test(v,st);
	int idx=3, val=5;
	update(st, 0, 0, v.size()-1, idx, val-v[idx]);
	v[idx]=val;
	test(v, st);
}
