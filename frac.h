#ifndef FRAC_H
#define FRAC_H

class Fraction {
	private:
		int num, denom;

	public:
		Fraction();
		Fraction(int n, int d);
		
		Fraction add(const Fraction& F) const;
		Fraction sub(const Fraction& F) const;
		Fraction mul(const Fraction& F) const;
		Fraction div(const Fraction& F) const;
		Fraction reduce() const;

		bool gt(const Fraction& F) const;		

		void setNum(int n);
		void setDenom(int d);
		void print();

		int getNum() const ;
		int getDenom() const ;
};

int findGCD( int x , int y) ;
Fraction sum(const Fraction A[], int size);
void sort(Fraction A[], int size);

#endif

