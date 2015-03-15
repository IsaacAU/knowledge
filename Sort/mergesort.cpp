#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

// implement
void merge(vector<int>::iterator b, vector<int>::iterator m, vector<int>::iterator e){
	vector<int> v(distance(b,e));
	auto x=b, y=m;
	int i=0;
	while(x!=m && y!=e){
		if(*x<*y)
			v[i++]=*x++;
		else
			v[i++]=*y++;
	}
	while(x!=m)	v[i++]=*x++;
	while(y!=e)	v[i++]=*y++;
	copy(v.begin(), v.end(), b);
}

void mergeSort(vector<int>::iterator b, vector<int>::iterator e){
	if(b==e || next(b)==e)	return;
	auto m=next(b, distance(b,e)/2);
	mergeSort(b,m);
	mergeSort(m,e);
	merge(b,m,e);
}

// test
ostream& operator<<(ostream &os, const vector<int> &v){
  for(auto x:v) os<<x<<' ';
  return os;
}

int main(){
  vector<int> v(20);
  iota(v.begin(), v.end(), 1);
  random_shuffle(v.begin(), v.end());
  cout<<v<<endl;
  mergeSort(v.begin(), v.end());
  cout<<v<<endl;
}



