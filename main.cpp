/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream> //i/o library

using namespace std; //instead od prefix std::

int main() //header 

{//begin 
    float a, res; //declaration
    //input values 
    cout<< "a = ";
    cin >> a;
    //calculation 
    res = a - 5;
    //output calculation 
    cout << "a-5 = " << res << endl;
    system("pause");

    return 0; //return to OS
} //end 