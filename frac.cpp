#include "frac.h"
#include <iostream>
#include <algorithm>

using namespace std; 

Fraction::Fraction() {
    num = 0 ;
    denom = 1 ;
}

Fraction::Fraction(int n , int d) {
    num = n ;
    denom = d ;
}

void Fraction::setNum(int n) {
    num = n ;
}

void Fraction::setDenom(int d) {
    denom = d ;
}

int Fraction::getNum() const {
    return num ;
}

int Fraction::getDenom() const {
    return denom ;
}

void Fraction::print(){
    cout << num << "/" << denom << endl;
} 

Fraction Fraction::add(const Fraction& F) const{
    Fraction r;
    if(denom == F.denom) {
        r.num = num + F.num;
	    r.denom = denom;	
     }
    else {
        r.num=(num * F.denom) + (F.num * denom);
	    r.denom = denom * F.denom ;
  }
	return r ;
}

Fraction Fraction::sub(const Fraction& F) const{
    Fraction r;
    if(denom == F.denom) {
        r.num = num - F.num;
        r.denom = denom ;
    }
    else {
        r.num = (num * F.denom) - (F.num * denom);
        r.denom = denom * F.denom;
    }
    return r ;
}

Fraction Fraction::mul(const Fraction& F) const{
    Fraction r;
    r.num = num * F.num;
    r.denom = denom * F.denom;
    return r;
}

Fraction Fraction::div(const Fraction& F) const{
    Fraction r;
    r.num = num * F.denom;
    r.denom = denom * F.num;
    return r;
}

bool Fraction::gt(const Fraction& F) const{
    double r1, r2;
    r1 = static_cast<double>(num)/denom;
    r2 = static_cast<double>(F.num)/F.denom;

    if(r1 > r2)
        return true;
    else
        return false;
}
        
Fraction Fraction::reduce() const{
    Fraction r;
    int gcd;

    gcd = findGCD(num , denom);

    r.num = num / gcd ;
    r.denom = denom / gcd ;
    return r;
}

int findGCD(int x, int y) {
    if(y == 0)
        return x ;
    else
        return findGCD(y , x % y) ;
}

Fraction sum(const Fraction A[], int size) {
    Fraction r;


    for(int i = 0; i < size ; i++)
        r = r.add(A[i]) ;

    return r ;
}

void sort(Fraction A[], int size) {
    int tmp;

    for(int i = 0 ; i < size ; i++) {
        int smallest = i ;

        for(int j = i + 1; j < size; j++) 
            if(A[j].gt(A[smallest]) == false)
                smallest = j;

        tmp = A[i].getNum();
        A[i].setNum(A[smallest].getNum());
        A[smallest].setNum(tmp);

        tmp = A[i].getDenom();
        A[i].setDenom(A[smallest].getDenom());
        A[smallest].setDenom(tmp);
    }
}