#include <iostream>
#include "arithmeticExpression.h"

using namespace std;

int main(){
    string expr1 = "a+b*c";
    arithmeticExpression ex1(expr1);
    ex1.buildTree();
    cout<<"expression 1: "<<expr1<<endl;
    cout<<"infix: "; ex1.infix(); cout<<endl; //cout << "actual: (a+(b*c)) " << endl;
    cout<<"prefix: "; ex1.prefix(); cout<<endl; //cout << "actual: +a*bc " << endl;
    cout<<"postfix: "; ex1.postfix(); cout<<endl; //cout << "actual: abc*+ " << endl;
    ex1.visualizeTree("expr1.dot");
    cout<<endl;

    string expr2 = "(a+b)*(c-d)";
    arithmeticExpression ex2(expr2);
    ex2.buildTree();
    cout<<"expression 2: "<<expr2<<endl;
    cout<<"infix: "; ex2.infix(); cout<<endl; //cout << "actual: ((a+b)*(c-d)) " << endl;
    cout<<"prefix: "; ex2.prefix(); cout<<endl; //cout << "actual: *+ab-cd " << endl;
    cout<<"postfix: "; ex2.postfix(); cout<<endl; //cout << "actual: ab+cd-* " << endl;
    ex2.visualizeTree("expr2.dot");
    cout<<endl;

    string expr3 = "(a+b)*((c–3)+(d–4))";
    arithmeticExpression ex3(expr3);
    ex3.buildTree();
    cout<<"expression 3: "<<expr3<<endl;
    cout<<"infix: "; ex3.infix(); cout<<endl; //cout << "actual: ((a+(b*c))-(((d*e)+f)*g)) " << endl;
    cout<<"prefix: "; ex3.prefix(); cout<<endl; //cout << "actual: -+a*bc*+*defg " << endl;
    cout<<"postfix: "; ex3.postfix(); cout<<endl; //cout << "actual: abc*+de*f+g*- " << endl;
    ex3.visualizeTree("expr3.dot");
    cout<<endl;

    return 0;
}