#include<iostream>
#include<vector>
#include<algorithm>

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
	update(st, 0, 0, v.size()-1, idx, val-v[idx]);
	v[idx]=val;
	test(v, st);
}


/* -------------------------------------------------------------------------------------
Running Result:
0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	
13	2	10	3	1	12	8	20	5	16	19	6	15	14	11	17	7	4	9	18	
210	90	120	29	61	65	55	25	4	40	21	40	25	28	27	15	10	3	1	20	20	5	16	25	15	14	11	24	4	9	18	13	2	0	0	0	0	0	0	12	8	0	0	0	0	0	0	19	6	0	0	0	0	0	0	17	7	0	0	0	0	0	0	
11->16:	70=70
2->4:	14=14
12->13:	29=29
1->2:	12=12
16->18:	20=20
7->15:	123=123
6->11:	74=74
9->18:	118=118
7->12:	81=81
15->19:	55=55
0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	
13	2	10	5	1	12	8	20	5	16	19	6	15	14	11	17	7	4	9	18	
212	92	120	31	61	65	55	25	6	40	21	40	25	28	27	15	10	5	1	20	20	5	16	25	15	14	11	24	4	9	18	13	2	0	0	0	0	0	0	12	8	0	0	0	0	0	0	19	6	0	0	0	0	0	0	17	7	0	0	0	0	0	0	
3->14:	132=132
2->11:	102=102
13->13:	14=14
1->4:	18=18
11->13:	35=35
7->8:	25=25
2->4:	16=16
17->17:	4=4
3->19:	187=187
1->9:	79=79
------------------------------------------------------------------------------------- */
