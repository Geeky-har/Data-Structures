/* 
    In this program we will check whether the expression have balanced parenthesis or not.
    We are using stack (from STL) to perform the functionality of the problem
    NOTE: This program wont ensure the validity of the expression
*/

#include<bits/stdc++.h>
using namespace std;

bool check(char *e){    // char type pointer
    int i;
    stack<char> st;     // stl stack

    for(i = 0; e[i] != '\0'; ++i){      // loop to traverse the char array
        if(e[i] == '('){            // if ( encountered 
            st.push('(');               // push ( into the stack
        }

        else if(e[i] == ')'){      // if ( encounetered
            if(st.empty()){             // if stack is empty
                return false;       // return false
            }

            else{                   
                st.pop();           // pop top from the stack
            }
        }
    }

    if(st.empty()){                 // after the traversal if stack is empty
        return true;                    // return true
    }

    else{
        return false;
    }
}

int main(){
    char *exp = "(12 + ((34)+)-18";    // char array of expression

    if(check(exp)){     // method to check the whether expression is equal or not
        cout<<"Parenthesis are matched and equal in the equation"<<check(exp)<<endl;
    }

    else{
        cout<<"Parenthesis are not equal in the equation"<<endl;
    }
    
    return 0;
}