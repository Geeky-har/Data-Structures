/* Tower of Hanoi is a very famous and histrical problem having originated from India. 
In this we have three towers and we have to move the pile of discs from tower A to B in
such a way that smaller disc should always lie above the larger disc.
Here I will be writing the code for the classic problem of tower of Hanoi.
*/

/* here in the below function, A represents initial Tower, B represents auxiliary tower, C represents destination tower 
*/

#include<iostream>
using namespace std;

void TOH(int n, string A, string B, string C){

    if(n > 0){
        TOH(n-1, A, C, B);  // move n-1 discs from A to B using C
        cout<<"Move a disc from "<<A<<" to "<<C<<endl;  // move one(and only) disc from A to C
        TOH(n-1, B, A, C);  // move n-1 discs from B to C using A
    }
}

int main(){
    int num;

    cout<<"Enter the number of discs in the Initial Tower: ";
    cin>>num;

    TOH(num, "A", "B", "C");

    return 0;
}