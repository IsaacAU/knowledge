#include<iostream>
#include<vector>
#include<string>
#include<iomanip>

using namespace std;

vector<int> next_arr(const string &p){
    const int n=p.length();
    vector<int> next(n, 0);
    next[0]=-1;
    for(int i=2; i<n; ++i){
        int j=next[i-1];
        while(j>=0 && p[j]!=p[i-1]) j=next[j];
        next[i]=j+1;
    }
    /* display next table */
    cout<<"pattern:\t";
    for(auto c:p)
        cout<<c<<'\t';
    cout<<endl;
    cout<<"next table:\t";
    for(auto x:next)
        cout<<x<<'\t';
    cout<<endl<<endl;
    /**********************/
    return move(next);
}

int kmp(const string &s, const string &p){
    const int m=s.length(), n=p.length();
    vector<int> next=next_arr(p);
    int i=0, j=0;
    while(i<m && j<n){
        /* display matching step */
        cout<<"s:\t"<<s<<"\tj="<<j<<endl;
        cout<<"p:\t"<<setw(i+n-j)<<p<<endl;
        cout<<"i:\t"<<setw(i+1)<<'^'<<endl<<endl;
        /*************************/
        if(j==-1 || s[i]==p[j]){
            ++i;
            ++j;
        }else{
            while(next[j]>=0 && p[j]==p[next[j]]){
                j=next[j];
            }
            j=next[j];
        }
    }
    return j==n?i-j:-1;
}

int main(){
    string s("abacababc");
    string p("abab");
    int match=kmp(s,p);
    /* display match result */
    cout<<"match result:"<<endl;
    cout<<"text:\t\t"<<s<<endl;
    cout<<"pattern:\t"<<setw(match+p.length())<<p<<endl;
    /************************/
}


