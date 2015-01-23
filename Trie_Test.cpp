#include<iostream>
#include"Trie.h"

using namespace std;

int main(){
    Trie t;
    vector<string> dict{"the", "a", "there", "answer", "any", "by", "bye", "their"};
    for(auto s:dict)
        t.insert(s);
    string s;
    ////////////////////////////////////////////////////////
    cout<<"Test find function:\n(enter \"over\" to stop)"<<endl;
    while(cin>>s){
        if(s=="over")   break;
        if(t.findWord(s))
            cout<<s<<" is in the trie!"<<endl;
        else
            cout<<s<<" is not in the trie!"<<endl;
    }
    //////////////////////////////////////////////////////////
    cout<<"Test auto complete function:\n(enter \"over\" to stop)"<<endl;
    while(cin>>s){
        if(s=="over")   break;
        vector<string> res=t.listPostfix(s);
        if(res.empty())
            cout<<"No words with prefix "<<s<<"!"<<endl;
        else{
            cout<<"Words with prefix "<<s<<" are:"<<endl;
            for(auto ss:res)
                cout<<s+ss<<" ";
            cout<<endl;
        }
    }
    ////////////////////////////////////////////////////////
    cout<<"Print all the words in the trie:"<<endl;
    vector<string> res=t.allWords();
    for(auto s:res)
        cout<<s<<endl;

}

