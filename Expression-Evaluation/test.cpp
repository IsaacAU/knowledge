#include "ExprEval.h"
#include <iostream>

using namespace std;

int main(){
    ExprEval e;
    e.setName("x", 1.1);
    e.setName("y", 1.2);
    e.setName("z", 2);
    cout<<"variables:"<<endl;
    e.printNames();
    e.setExpr("x+y*(x-z)+z/x");
    cout<<"expression:\t"<<e.getExpr()<<endl;
    cout<<"evaluation:\t"<<e.eval()<<endl;
}

