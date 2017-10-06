#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Fraction
{
private:
	int deno;//·ÖÄ¸
	int nume;//·Ö×Ó
public:
	int getDeno() { return deno; }
	int getNume() { return nume; }
	Fraction():deno(1),nume(0){}
	Fraction(Fraction &X)
	{
		deno = X.getDeno();
		nume = X.getNume();
		Simplify();
	}
	Fraction(int N, int D) 
	{ 
		if(D==0)
		{
			cout << "The denominator can't be zero!" << endl;
			cout << "The fraction will be made 0/1!" << endl;
			deno = 1; nume = 0;
		}
		else
		{
			deno = D;
			nume = N;
			Simplify();
		}
	}
	~Fraction(){}

	friend Fraction operator +(Fraction a, Fraction b);
	friend Fraction operator -(Fraction a, Fraction b);
	friend Fraction operator *(Fraction a, Fraction b);
	friend Fraction operator /(Fraction a, Fraction b);
	friend bool operator <(Fraction a, Fraction b);
	friend bool operator <=(Fraction a, Fraction b);
	friend bool operator ==(Fraction a, Fraction b);
	friend bool operator !=(Fraction a, Fraction b);
	friend bool operator >=(Fraction a, Fraction b);
	friend bool operator >(Fraction a, Fraction b);
	friend istream & operator >> (istream &, Fraction &);
	friend ostream & operator << (ostream &, Fraction &);
	char* ToString();
	double ToDouble();
	void Simplify();

};

istream & operator >> (istream &input, Fraction &a)
{
	cout << "input real part and imaginary part of complex number:";
	input >> a.nume >> a.deno;
	return input;
}

ostream & operator << (ostream &output, Fraction &a)
{
	output << a.nume << "/" << a.deno << endl;
	return output;
}
char* Fraction::ToString()
{
	Simplify();
	int i = 0,j=0;
	char* tmp1 = new char[10];
	sprintf(tmp1, "%d", nume);
	char *tmp2 = new char[10];
	sprintf(tmp2, "%d", deno);

	for (i = 0; tmp1[i] != '\0'; i++);
	tmp1[i] = '/';
	for (j = 0; tmp2[j] != '\0'; j++)
	{
		tmp1[i + 1 + j] = tmp2[j];
	}
	tmp1[i + 1 + j] = '\0';
	return tmp1;
}

double Fraction::ToDouble()
{
	return (double)(nume) / (double)(deno);
}
void Fraction::Simplify()
{
	int a = deno, b = nume;
	int temp;
	if (a<b) 
	{		/*½»»»Á½¸öÊý£¬Ê¹´óÊý·ÅÔÚaÉÏ*/
		temp = a;
		a = b;
		b = temp;
	}
	while (b != 0) 
	{/*ÀûÓÃÕ·³ý·¨£¬Ö±µ½bÎª0ÎªÖ¹*/
		temp = a%b;
		a = b;
		b = temp;
	}
	deno /= a;
	nume /= a;
}

Fraction operator +(Fraction a, Fraction b)
{
	int resd, resn;
	resd = a.getDeno() * b.getDeno();
	resn = a.getNume()*b.getDeno() + a.getDeno()*b.getNume();
	Fraction res(resn,resd);
	res.Simplify();
	return res;
}

Fraction operator -(Fraction a, Fraction b)
{
	int resd, resn;
	resd = a.getDeno() * b.getDeno();
	resn = a.getNume()*b.getDeno() - a.getDeno()*b.getNume();
	Fraction res(resn, resd);
	res.Simplify();
	return res;
}

Fraction operator *(Fraction a, Fraction b)
{
	int resd, resn;
	resd = a.getDeno() * b.getDeno();
	resn = a.getNume() * b.getNume();
	Fraction res(resn, resd);
	res.Simplify();
	return res;
}

Fraction operator /(Fraction a, Fraction b)
{
	int resd, resn;
	resd = a.getDeno() * b.getNume();
	resn = a.getNume() * b.getDeno();
	Fraction res(resn, resd);
	res.Simplify();
	return res;
}

bool operator <(Fraction a, Fraction b)
{
	return ((a.getNume()*b.getDeno()- a.getDeno()*b.getNume())<0?true:false);
}

bool operator <=(Fraction a, Fraction b)
{
	return ((a.getNume()*b.getDeno() - a.getDeno()*b.getNume())<=0 ? true : false);
}

bool operator ==(Fraction a, Fraction b)
{
	return ((a.getNume()*b.getDeno() - a.getDeno()*b.getNume()) == 0 ? true : false);
}

bool operator !=(Fraction a, Fraction b)
{
	return ((a.getNume()*b.getDeno() - a.getDeno()*b.getNume()) != 0 ? true : false);
}

bool operator >=(Fraction a, Fraction b)
{
	return ((a.getNume()*b.getDeno() - a.getDeno()*b.getNume()) >= 0 ? true : false);
}

bool operator >(Fraction a, Fraction b)
{
	return ((a.getNume()*b.getDeno() - a.getDeno()*b.getNume()) > 0 ? true : false);
}

void pause()
{
	getchar();
}

int main()
{

		cout << "The following are some operations!" << endl;

		cout << "[1] Default ctor" << endl;
		Fraction A;
		cout << "The result is " << A << endl;
		cout << endl;

		cout << "[2] Ctor takes two integers as parameters"<<endl;
		cout << "If we input 30 and 50" << endl;
		Fraction B(30, 50);
		cout << "The result is " <<  B << endl;

		cout << "If we input 30 and 0, which is illegal" << endl;
		Fraction E(30, 0);
		cout << "The result is " << E << endl;

		cout << "[3] Copy ctor" << endl;
		cout << "If we copy B(30,50) to C " << endl;
		Fraction C(B);
		cout << "The result is " << C << endl;

		cout << "[4] Arithmetical operators: " << endl;
		cout << "Let's make the two operands are X(3/7) and Y(8/11)" << endl;
		Fraction X(3, 7);
		Fraction Y(8, 11);
		cout << "X + Y =  " << X + Y << endl;
		cout << "X - Y =  " << X - Y << endl;
		cout << "X * Y =  " << X * Y << endl;
		cout << "X / Y =  " << X / Y << endl;

		cout << endl;
		cout << "[5] Relational operators: " << endl;
		cout << "Let's make the two operands are X(3/7) and Y(8/11)" << endl;
		cout << "X < Y =  " << (X < Y) << endl;
		cout << "X <= Y =  " << (X <= Y) << endl;
		cout << "X == Y =  " << (X == Y) << endl;
		cout << "X != Y =  " << (X != Y) << endl;
		cout << "X >= Y =  " << (X >= Y) << endl;

		cout << endl;
		cout << "[6] Type cast to double: " << endl;
		cout << "Let's try two fractions, X(3/7) and Z(4/8)" << endl;
		Fraction Z(4, 8);
		cout <<"Cast X(3/7) to double we get "<< X.ToDouble() << endl;
		cout << "Cast Z(4/8) to double we get " << Z.ToDouble() << endl;

		cout << endl;
		cout << "[7] Type cast to string: " << endl;
		cout << "Let's try two fractions, X(3/7) and Z(4/8)" << endl;
		cout << "Cast X(3/7) to string we get " << X.ToString() << endl;
		cout << "Cast Z(4/8) to string we get " << Z.ToString() << endl;

		pause();
		return 0;
}
