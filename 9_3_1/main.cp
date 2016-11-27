#include <iostream>
#include <istream>
using namespace std;

struct complex {
    double Re;
    double Im;
    void read() {
        cout << "Re = ";
        cin >> Re;
        cout <<"Im = ";
        cin >> Im;
    }
    void print() {
        cout << Re << "+" << Im << "i\n";
    }
    friend complex operator+(const complex &a, const complex &b) {
    	complex c;
    	c.Re = a.Re + b.Re;
    	c.Im = a.Im + b.Im;
    	return c;
	}
	friend complex operator-(const complex &a, const complex &b) {
    	complex c;
    	c.Re = a.Re - b.Re;
    	c.Im = a.Im - b.Im;
    	return c;
	}
	friend complex operator*(const complex &a, const complex &b) {
    	complex c;
    	c.Re = a.Re * b.Re - a.Im * b.Im;
		c.Im = a.Im * b.Re + a.Re * b.Im; 
    	return c;
	}
	friend complex operator/(const complex &a, const complex &b) {
    	complex c;
    	c.Re = (a.Re*b.Re + a.Im*b.Im) / (b.Re*b.Re + b.Im*b.Im);
    	c.Im = (a.Im*b.Re - a.Re*b.Im) / (b.Re*b.Re + b.Im*b.Im);
    	return c;
	}
    friend void operator *=(complex &a, complex &b) {
        a = a * b;
    }
    friend void operator /=(complex &a, complex &b) {
        a = a / b;
    }
};

int main(void) {
    complex a, b, c, d;
    
    cout << "Введите a\n";
    a.read();
    
    cout << "Введите b\n";
    b.read();
    
	cout << "Введите c\n";
    c.read();
	
	d = a + c;
    d *= d;
    d = d * (a + b);
	d /= a;
    
    cout << "a = ";
    a.print();
    cout << "b = ";
    b.print();
    cout << "c = ";
    c.print();
    cout << "d = ((a - c)^2 * (a + b)) / a = ";
    d.print();
    
    return 0;
}
