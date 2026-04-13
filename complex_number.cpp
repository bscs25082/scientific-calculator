#include <iostream>
using namespace std;

class complexNumber{
    private :
    float realNumber;
    float imaginaryNumber;
    public :
    complexNumber(float real = 0, float imaginary = 0)
    {
        realNumber = real;
        imaginaryNumber = imaginary;
    }
    complexNumber(float real)
    {
        realNumber = real;
        imaginaryNumber = 0;
    }
    complexNumber(const complexNumber& other)
    {
        realNumber = other.realNumber;
        imaginaryNumber = other.imaginaryNumber;
    }
    void displaying_complex()
    {
        if(imaginaryNumber >= 0)
            cout << realNumber << " + " << imaginaryNumber << "i";
        else
            cout << realNumber << " - " << -imaginaryNumber << "i";
    }
    complexNumber complex_addition(const complexNumber& complex) const
    {
        return complexNumber(realNumber + complex.realNumber, imaginaryNumber + complex.imaginaryNumber);
    }
    complexNumber complex_subtraction(const complexNumber& complex) const
    {
        return complexNumber(realNumber - complex.realNumber, imaginaryNumber - complex.imaginaryNumber);
    }
    complexNumber multiply_complex(const complexNumber& complex) const
    {
        return complexNumber((realNumber * complex.realNumber) - (imaginaryNumber * complex.imaginaryNumber), (realNumber * complex.imaginaryNumber) + (imaginaryNumber * complex.realNumber));
    }
    bool is_equal(const complexNumber& complex) const
    {
        return(realNumber == complex.realNumber && imaginaryNumber == complex.imaginaryNumber);
    }
    //operator overloading
    complexNumber& operator=(const complexNumber& other)
    {
        if(this == &other)
            return *this;
        realNumber = other.realNumber;
        imaginaryNumber = other.imaginaryNumber;
        return *this;
    }
    complexNumber operator+(const complexNumber& complex) const
    {
        return complex_addition(complex);
    }

    complexNumber operator-(const complexNumber& complex) const
    {
        return complex_subtraction(complex);
    }

    complexNumber operator*(const complexNumber& complex) const
    {
        return multiply_complex(complex);
    }
    
    bool operator==(const complexNumber& complex) const
    {
        return is_equal(complex);
    }

    bool operator!=(const complexNumber& complex) const
    {
        return !is_equal(complex);
    }
    friend istream& operator>>(istream& in, complexNumber& complex)
    {
        in >> complex.realNumber >> complex.imaginaryNumber;
        return in;
    }

    friend ostream& operator<<(ostream& out, const complexNumber& complex)
    {
        if(complex.imaginaryNumber >= 0)
            out << complex.realNumber << " + " << complex.imaginaryNumber << "i";
        else
            out << complex.realNumber << " - " << -complex.imaginaryNumber << "i";
        return out;
    }
};

void menu()
{
    cout << "====MENU====" << endl;
    cout << "1. complex addition" << endl;
    cout << "2. complex subtraction" << endl;
    cout << "3. complex product" << endl;
    cout << "4. copy of complex" << endl;
    cout << "5. eqaulity check" << endl;
    cout << "0. to exit" << endl;
    cout << "enter your choice : ";
}
int question_number01()
{
    int choice;
    do{
        menu();
        cin >> choice;
        if(choice == 1)
        {
            complexNumber complex1, complex2;
            cout << "enter complex 1 (real , imaginary) : ";
            cin >> complex1;
            cout << "enter complex 2 (real , imaginary) : ";
            cin >> complex2;
            complexNumber complexSum = complex1 + complex2;
            cout << "complex sum : " << complexSum << endl;
        }
        else if(choice == 2)
        {
            complexNumber complex1, complex2;
            cout << "enter complex 1 (real , imaginary) : ";
            cin >> complex1;
            cout << "enter complex 2 (real , imaginary) : ";
            cin >> complex2;
            complexNumber complexDiff = complex1 - complex2;
            cout << "complex differnce : " << complexDiff << endl;
        }
        else if(choice == 3)
        {
            complexNumber complex1, complex2;
            cout << "enter complex 1 (real , imaginary) : ";
            cin >> complex1;
            cout << "enter complex 2 (real , imaginary) : ";
            cin >> complex2;
            complexNumber complexProd = complex1 * complex2;
            cout << "complex product : " << complexProd << endl;
        }
        else if(choice == 4)
        {
            complexNumber complex1, complex2;
            cout << "enter complex 1 (real , imaginary) : ";
            cin >> complex1;
            complex2 = complex1;
            cout << "complex copy : " << complex2 << endl;
        }
        else if(choice == 5)
        {
            complexNumber complex1, complex2;
            cout << "enter complex 1 (real , imaginary) : ";
            cin >> complex1;
            cout << "enter complex 2 (real , imaginary) : ";
            cin >> complex2;
            if(complex1 == complex2)
                cout << "both complex are same" << endl;
            else
                cout << "both complex aint same" << endl;
        }
        else if(choice == 0)
            cout << "exiting code" << endl;
        else
            cout << "invalid choice" << endl;
    }while(choice != 0);
    
    return 0;
}
