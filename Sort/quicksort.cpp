#include<vector>
#include<algorithm>

using namespace std;

// use STL
void quickSort1(vector<int>::iterator b, vector<int>::iterator e){
	if(b==e || next(b)==e)	return;
	auto m=next(b,distance(b,e)/2);
	nth_element(b,m,e);
	quickSort1(b,m);
	quickSort1(m,e);
}

// implement self
vector<int>::iterator partition(vector<int>::iterator b, vector<int>::iterator e){
	auto pivot=next(b,rand()%distance(b,e));
	swap(*pivot, *prev(e));
	auto pos=b;
	int val=*prev(e);
	for(auto it=b; it!=prev(e); ++it)
		if(*it<val)
			swap(*pos++, *it);
	swap(*pos, *prev(e));
	return pos;
}

vector<int>::iterator quickSelect(vector<int>::iterator b, vector<int>::iterator e, int k){
	if(k==0)	return b;
	auto m=partition(b,e);
	while(distance(b,m)!=k){
		if(distance(b,m)<k){
			k-=distance(b,m);
			b=m;
		}else
			e=m;
		m=partition(b,e);
	}
	return m;
}

void quickSort2(vector<int>::iterator b, vector<int>::iterator e){
	if(b==e || next(b)==e)	return;
	auto pivot=quickSelect(b, e, distance(b,e)/2);
	quickSort2(b,pivot);
	quickSort2(pivot,e);
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
  quickSort1(v.begin(), v.end());
  cout<<v<<endl;
  random_shuffle(v.begin(), v.end());
  quickSort2(v.begin(), v.end());
  cout<<v<<endl;
}
