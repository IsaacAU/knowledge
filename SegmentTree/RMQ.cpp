#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

ostream& operator<<(ostream &os, const vector<int> &v){
	for(auto x:v)	os<<x<<'\t';
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
	st[i]=min(st[2*i+1], st[2*i+2]);
}

vector<int> buildST(vector<int> &v){
	int n=v.size();
	int x=ceil(log2(n));
	int m=(1<<(x+1))-1;
	vector<int> st(m, INT_MAX);
	build(v, 0, n-1, st, 0);
	return st;
}

int query(vector<int> &st, int i, int s, int e, int qs, int qe){
	if(qs<=s && qe>=e)
		return st[i];
	if(s>qe || e<qs)	return INT_MAX;
	int m=s+(e-s)/2;
	int left=query(st, 2*i+1, s, m, qs, qe), right=query(st, 2*i+2, m+1, e, qs, qe);
	return min(left, right);
}

void update(vector<int> &st, int i, int s, int e, int idx, int val){
	if(idx<s || idx>e)	return;
	if(s==e){
		st[i]=val;
		return;
	}
	int m=s+(e-s)/2;
	update(st, 2*i+1, s, m, idx, val);
	update(st, 2*i+2, m+1, e, idx, val);
	st[i]=min(st[2*i+1], st[2*i+2]);
}

int calc_true(vector<int> &v, int s, int e){
	int res=INT_MAX;
	for(int i=s; i<=e; ++i)
		res=min(res, v[i]);
	return res;
}

void test(vector<int> &v, vector<int> &st){
	vector<int> idx(v.size());
	iota(idx.begin(), idx.end(), 0);
	cout<<idx<<endl<<v<<endl<<st<<endl;
	for(int i=0; i<20; ++i){
		int x=rand()%v.size(), y=rand()%v.size();
		int s=min(x,y), e=max(x,y);
		cout<<s<<"->"<<e<<":\t"<<query(st, 0, 0, v.size()-1, s, e)<<"="<<calc_true(v, s, e)<<endl;
	}
}


int main() {
	vector<int> v(20);
	iota(v.begin(), v.end(), 1);
	random_shuffle(v.begin(), v.end());
	vector<int> st=buildST(v);
	test(v,st);
	int idx=3, val=5;
	update(st, 0, 0, v.size()-1, idx, val);
	v[idx]=val;
	test(v, st);
}

/* ----------------------------------------------------------------------------------
Running Result:
0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	
13	2	10	3	1	12	8	20	5	16	19	6	15	14	11	17	7	4	9	18	
1	1	4	1	5	6	4	2	1	8	5	6	11	4	9	2	10	3	1	8	20	5	16	6	15	14	11	7	4	9	18	13	2	2147483647	2147483647	2147483647	2147483647	2147483647	2147483647	12	8	2147483647	2147483647	2147483647	2147483647	2147483647	2147483647	19	6	2147483647	2147483647	2147483647	2147483647	2147483647	2147483647	17	7	2147483647	2147483647	2147483647	2147483647	2147483647	2147483647	
11->16:	6=6
2->4:	1=1
12->13:	14=14
1->2:	2=2
16->18:	4=4
7->15:	5=5
6->11:	5=5
9->18:	4=4
7->12:	5=5
15->19:	4=4
3->14:	1=1
2->11:	1=1
13->13:	14=14
1->4:	1=1
11->13:	6=6
7->8:	5=5
2->4:	1=1
17->17:	4=4
3->19:	1=1
1->9:	1=1
0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	
13	2	10	5	1	12	8	20	5	16	19	6	15	14	11	17	7	4	9	18	
1	1	4	1	5	6	4	2	1	8	5	6	11	4	9	2	10	5	1	8	20	5	16	6	15	14	11	7	4	9	18	13	2	2147483647	2147483647	2147483647	2147483647	2147483647	2147483647	12	8	2147483647	2147483647	2147483647	2147483647	2147483647	2147483647	19	6	2147483647	2147483647	2147483647	2147483647	2147483647	2147483647	17	7	2147483647	2147483647	2147483647	2147483647	2147483647	2147483647	
16->18:	4=4
10->15:	6=6
2->8:	1=1
0->6:	1=1
2->4:	1=1
6->8:	5=5
5->10:	5=5
9->10:	16=16
6->10:	5=5
1->13:	1=1
8->9:	5=5
3->4:	1=1
14->16:	7=7
0->6:	1=1
11->16:	6=6
4->8:	1=1
6->19:	4=4
3->17:	1=1
18->18:	9=9
2->9:	1=1
---------------------------------------------------------------------------------- */
