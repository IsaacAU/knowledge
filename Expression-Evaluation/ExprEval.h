#ifndef EXPREVAL_H_INCLUDED
#define EXPREVAL_H_INCLUDED

#include <string>
#include <unordered_map>

using namespace std;

class ExprEval{
public:
    ExprEval():i(0){}
    ExprEval(const string &ss):s(ss),i(0){}
    void setName(const string &,double);
    double getName(const string &) const;
    void printNames() const;
    void setExpr(const string &);
    string getExpr()    const;
    void clearTable();
    double eval();
private:
    double number();
    double prim();
    double term();
    double expr();
    string s;
    int i;
    unordered_map<string,double> table;
};


#endif // EXPREVAL_H_INCLUDED
