/********************************************************************
fracClient.coo
------------
By: Jessica Pagan Sanchez       August 20, 2013

The main function and invocations of the functions.
********************************************************************/

#include <iostream>
#include <cstdlib>
#include "frac.h"
using namespace std ;

const int ARRAY_SIZE = 10 ;

int main() {

    Fraction f1(3 , 4) ;
    Fraction f2(1 , 2) ;
    Fraction f3 ;
    Fraction f4(10 , 15);
    bool greatest;

    cout << "\nSuma:\n";
    f3 = f1.add(f2) ;    
    f3.print() ;

    cout << "\nResta:\n";
    f3 = f1.sub(f2) ;
    f3.print() ;

    cout << "\nMultiplication:\n";
    f3 = f1.mul(f2) ;
    f3.print() ;

    cout << "\nDivision:\n";
    f3  = f1.div(f2) ;
    f3.print();

    greatest = f1.gt(f2);
    cout << "\nThe greatest fraction is: \n";
    if(greatest == true)
        f1.print();
    else if (greatest == false)
        f2.print();


    f3 = f4.reduce();
    cout << "\nThe reduce fraction of " ;
    f4.print() ;
    cout << "is " ; 
    f3.print() ;

    Fraction array[ARRAY_SIZE] ;
    srand(time(NULL));

    for(int i = 0; i < ARRAY_SIZE; i++) {
        array[i].setNum(rand() % 9 + 1);
        array[i].setDenom(rand() % 9 + 1);
    }

    f3 = sum(array, ARRAY_SIZE);
    f3 = f3.reduce();
    cout << "\nLa sumatoria de un arreglo con objetos random es: ";
    f3.print() ;

    sort(array, ARRAY_SIZE);
    cout << "\nEl orden ascendente del arreglo es: \n";
    for(int i = 0; i < ARRAY_SIZE; i++)
        array[i].print();

    cout << endl ;

    return 0 ;
}

