#include<iostream>
using namespace std;
 
int max_value(int a, int b){
    return a>b ? a : b;
}
int increment(int *a) { *a++; }
int decrease(int &a){ a--; }
 
int main(){
    int x = 3, y=5;
    int &r = y;
    increment(&x);
    cout<<x;
    r++;
    cout<<y;
    decrease(y);
    cout<<y;
    return 0;
}