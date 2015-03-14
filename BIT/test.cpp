#include<iostream>
#include<vector>
#include<algorithm>
#include "BIT.h"

using namespace std;

ostream& operator<<(ostream &os, const vector<int> &v){
	for(auto x:v)	os<<x<<'\t';
	return os;
}

int calc_true(vector<int> &v, int s, int e){
	int res=0;
	for(int i=s; i<=e; ++i)
		res+=v[i];
	return res;
}

void test(vector<int> &v, BIT &bit){
	for(int i=0; i<10; ++i){
		int idx=rand()%v.size(), val=rand()%100;
		v[idx]=val;
		bit.update(idx, val);
	}
	cout<<v<<endl<<bit<<endl;
	for(int i=0; i<10; ++i){
		int x=rand()%v.size(), y=rand()%v.size();
		int s=min(x,y), e=max(x,y);
		cout<<s<<"->"<<e<<":\t"<<calc_true(v,s,e)<<"="<<bit.getSum(s,e)<<endl;
	}
}

int main() {
	vector<int> v(20);
	iota(v.begin(), v.end(), 1);
	random_shuffle(v.begin(), v.end());
	BIT bit(v);
	test(v,bit);
}

/* ----------------------------------------------------------------------
Running Result:
13	2	21	3	2	12	71	20	5	16	19	6	67	92	11	47	18	4	69	35	
13	2	21	3	2	12	71	20	5	16	19	6	67	92	11	47	18	4	69	35	
3->14:	324=324
2->11:	175=175
13->13:	92=92
1->4:	28=28
11->13:	165=165
7->8:	25=25
2->4:	26=26
17->17:	4=4
3->19:	497=497
1->9:	152=152
---------------------------------------------------------------------- */
