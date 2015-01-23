#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int ALPHA=26;

struct TrieNode{
    friend class Trie;
    int Nchild;
    bool isWord;
    TrieNode *child[ALPHA];
    TrieNode(int n, bool b): Nchild(n), isWord(b){
        fill_n(child, ALPHA, nullptr);
    }
};

class Trie{
public:
    Trie():root(new TrieNode(0,0)){}
    ~Trie(){  remove(root); }
    void insert(string s){
        TrieNode *nd=root;
        for(int i=0; i<s.length(); ++i){
            int idx=s[i]-'a';
            if(nd->child[idx]){
                if(i==s.length()-1)
                    nd->child[idx]->isWord=true;
                else
                    nd->child[idx]->Nchild++;
            }else{
                if(i==s.length()-1)
                    nd->child[idx]=new TrieNode(0,1);
                else
                    nd->child[idx]=new TrieNode(1,0);
            }
            nd=nd->child[idx];
        }
    }
    bool findWord(string s){
        TrieNode *nd=root;
        for(auto c:s){
            int idx=c-'a';
            if(nd->child[idx]==nullptr)
                return false;
            nd=nd->child[idx];
        }
        return nd->isWord;
    }
    int countPrefix(string s){
        TrieNode *nd=root;
        for(auto c:s){
            int idx=c-'a';
            if(nd->child[idx]==nullptr)
                return 0;
            nd=nd->child[idx];
        }
        return nd->Nchild;
    }
    vector<string> listPostfix(string s){
        TrieNode *nd=root;
        for(auto c:s){
            int idx=c-'a';
            if(nd->child[idx]==nullptr)
                return vector<string>();
            nd=nd->child[idx];
        }
        return allWords(nd);
    }
    vector<string> allWords(){
        return move(allWords(root));
    }
private:
    vector<string> allWords(TrieNode *nd){
        vector<string> res;
        if(nd==nullptr) return res;
        string path;
        traverse(res, path, nd);
        return res;
    }
    void traverse(vector<string> &res, string &path, TrieNode *nd){
        if(nd->isWord)
            res.push_back(path);
        for(int i=0; i<ALPHA; ++i){
            if(nd->child[i]){
                path.push_back(char('a'+i));
                traverse(res, path, nd->child[i]);
                path.pop_back();
            }
        }
    }
    void remove(TrieNode *nd){
        if(nd==nullptr) return;
        for(int i=0; i<ALPHA; ++i){
            if(nd->child[i]==nullptr)   continue;
            remove(nd->child[i]);
            nd->child[i]=nullptr;
        }
        delete nd;
    }
    TrieNode *root;
};



#endif // TRIE_H_INCLUDED
