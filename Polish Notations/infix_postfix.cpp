#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    if(c == '^' || c == '/' || c == '*' || c == '+' || c == '-' || c == ')' || c == '(')
        return true;

    else
        return false;
}

int prec(char c){
    if(c == '^')
        return 4;

    else if(c == '/' || c == '*')
        return 3;

    else if(c == '+' || c == '-')
        return 2;

    else
        return 0;
}

string convert(string infix){
    int i;
    string post;
    stack<char> st;
    st.push('N');
    char c;
    int n = infix.length();

    for(i = 0; i < n; ++i){

        if(!isOperator( infix[i] )){
            post += infix[i];
        }

        else if( infix[i] == '('){
            st.push(infix[i]);
        }

        else if( infix[i] == ')' ){
            while (st.top() != '(' && st.top() != 'N')
            {
                c = st.top();
                st.pop();
                post += c;
            }

            if(st.top() == '(')
                st.pop();
        }

        else{
            
            while( st.top() != 'N' &&  prec( st.top() ) >= prec( infix[i] ) ){
                c = st.top();
                st.pop();
                post += c;
            }

            st.push(infix[i]);
        }
    }

    while (st.top() != 'N')
    {
        post += st.top();
        st.pop();
    }

    return post;
    
}

int main(){
    string infix;

    cout<<"Enter the infix expression(operators allowed: +,-,*,?,^): "<<endl;
    cin>>infix;
    
    string post = convert(infix);

    cout<<"The postfix expression is: "<<post<<endl;

    return 0;
}