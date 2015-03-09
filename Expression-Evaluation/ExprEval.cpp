#include "ExprEval.h"
#include <iostream>


void ExprEval::setName(const string &name, double x){
    table[name]=x;
}

double ExprEval::getName(const string &name) const{
    auto it=table.find(name);
    if(it!=table.end())
        return it->second;
    else
        cerr<<name<<" doesn't exist!"<<endl;
}

void ExprEval::printNames() const{
    for(auto &p:table)
        cout<<p.first<<"\t->\t"<<p.second<<endl;
}

void ExprEval::setExpr(const string &ss){
    s=ss;
    i=0;
}

string ExprEval::getExpr() const{
    return s;
}

void ExprEval::clearTable(){
    table.clear();
}

double ExprEval::number(){
    double res=0;
    while(i<s.length() && isdigit(s[i])){
        res=10*res+int(s[i]-'0');
        ++i;
    }
    if(i<s.length() && s[i]=='.'){
        ++i;
        double k=10;
        while(i<s.length() && isdigit(s[i])){
            res+=int(s[i]-'0')/k;
            k*=10;
            ++i;
        }
    }
    return res;
}

double ExprEval::prim(){
    double res=0;
    if(i<s.length()){
        if(isdigit(s[i]))
            res=number();
        else if(s[i]=='-'){
            ++i;
            res=-number();
        }else if(s[i]=='('){
            ++i;
            res=expr();
            ++i;
        }else if(isalpha(s[i])){
            string name;
            while(i<s.length() && isalnum(s[i]))
                name.push_back(s[i++]);
            res=table[name];
        }
    }
    return res;
}

double ExprEval::term(){
    double left=prim();
    while(i<s.length() && (s[i]=='*' || s[i]=='/')){
        if(s[i++]=='*')
            left*=prim();
        else
            left/=prim();
    }
    return left;
}

double ExprEval::expr(){
    double left=term();
    while(i<s.length() && (s[i]=='+' || s[i]=='-')){
        if(s[i++]=='+')
            left+=term();
        else
            left-=term();
    }
    return left;
}

double ExprEval::eval(){
    i=0;
    return expr();
}
