 
#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>

using namespace std;

void siftDown(vector<int>::iterator b, vector<int>::iterator e, vector<int>::iterator cur){
    if(b>=e || cur>=e)  return;
    while(1){
        auto d=distance(b, cur);
        auto left=next(b,2*d+1), right=next(left);
        auto maxIt=cur;
        if(left<e && *left>*maxIt)  maxIt=left;
        if(right<e && *right>*maxIt)    maxIt=right;
        if(maxIt==cur)  break;
        swap(*cur, *maxIt);
        cur=maxIt;
    }
}

void heapify(vector<int>::iterator b, vector<int>::iterator e){
    auto d=distance(b,e);
    if(d<=2)    return;
    for(auto cur=next(b,(d-2)/2); cur>=b; --cur)
        siftDown(b,e,cur);
}

void heap_sort(vector<int>::iterator b, vector<int>::iterator e){
    if(b==e || next(b)==e)  return;
    heapify(b,e);
    auto it=prev(e);
    while(it>b){
        swap(*b,*it);
        siftDown(b, it--, b);
    }
}

ostream& operator<<(ostream &os, const vector<int> &v){
    for(auto x:v)
        os<<x<<" ";
    return os;
}

int main(){
    srand(time(nullptr));
    vector<int> v;
    for(int i=1; i<=20; ++i)
        v.push_back(i);
    random_shuffle(begin(v), end(v));
    cout<<"origin:\t"<<v<<endl;
    heapify(begin(v), end(v));
    cout<<"heapify:\t"<<v<<endl;
    heap_sort(begin(v), end(v));
    cout<<"heap sort:\t"<<v<<endl;
}
