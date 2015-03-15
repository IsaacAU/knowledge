#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

// implement
void siftDown(vector<int> &v, int i, int n){
	while(2*i+1<n){
		int next=i;
		if(v[2*i+1]>v[i])
			next=2*i+1;
		if(2*i+2<n && v[2*i+2]>v[next])
			next=2*i+2;
		if(next==i)
			break;
		swap(v[i], v[next]);
		i=next;
	}
}

void heapify(vector<int> &v){
	const int n=v.size();
	for(int i=(n-2)/2; i>=0; --i)
		siftDown(v, i, n);
}

void heapSort(vector<int> &v){
	const int n=v.size();
	heapify(v);
	for(int i=n-1; i>0; --i){
		swap(v[0], v[i]);
		siftDown(v, 0, i);
	}
}

// test
ostream& operator<<(ostream &os, const vector<int> &v){
  for(auto x:v) os<<x<<'\t';
  return os;
}

int main(){
  vector<int> v(20);
  iota(v.begin(), v.end(), 1);
  random_shuffle(v.begin(), v.end());
  cout<<v<<endl;
  heapSort(v);
  cout<<v<<endl;
}
