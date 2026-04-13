#include <iostream>
using namespace std;

class fraction{
    private :
    int numeratorNumber;
    int denominatorNumber;
    int greatest_common_divisor(int num1, int num2)
    {
        if(num2 == 0)
            return num1;
        return greatest_common_divisor(num2, num1 % num2);
    }
    public:
    void input_fraction()
    {
        cout << "enter numerator : ";
        cin >> numeratorNumber;
        cout << "enter denominator : ";
        cin >> denominatorNumber;
        simplification_fraction();
    }
    fraction(int numerator = 0, int denominator = 1)
    {
        numeratorNumber = numerator;
        denominatorNumber = denominator;
        simplification_fraction();
    }
    //copy constructoor
    fraction(const fraction& other)
    {
        numeratorNumber = other.numeratorNumber;
        denominatorNumber = other.denominatorNumber;
    }
    // fucntion we will use for addition of fraction
    fraction addition_factraction(const fraction& frac) const
    {
        int numerator = numeratorNumber * frac.denominatorNumber + frac.numeratorNumber * denominatorNumber;
        int denominator = denominatorNumber * frac.denominatorNumber;
        return fraction(numerator, denominator);
    }
    //function to subtract two fractions
    fraction subtraction_factraction(const fraction& frac) const
    {
        int numerator = numeratorNumber * frac.denominatorNumber - frac.numeratorNumber * denominatorNumber;
        int denominator = denominatorNumber * frac.denominatorNumber;
        return fraction(numerator, denominator);
    }
    //function to multiply two fractions
    fraction multiplication_factraction(const fraction& frac) const
    {
        int numerator = numeratorNumber * frac.numeratorNumber;
        int denominator = denominatorNumber * frac.denominatorNumber;
        return fraction(numerator, denominator);
    }
    //function for division of two fractions
    fraction divison_factraction(const fraction& frac) const
    {
        int numerator = numeratorNumber * frac.denominatorNumber;
        int denominator = denominatorNumber * frac.numeratorNumber;
        return fraction(numerator, denominator);
    }
    void simplification_fraction()
    {
        int greatestCommonDivider = greatest_common_divisor(abs(numeratorNumber), abs(denominatorNumber));
        numeratorNumber = numeratorNumber / greatestCommonDivider;
        denominatorNumber = denominatorNumber / greatestCommonDivider;
        if(denominatorNumber < 0)
        {
            numeratorNumber = -numeratorNumber;
            denominatorNumber = -denominatorNumber;
        }
    }
    bool is_equal(const fraction& frac) const
    {
        fraction frac1 = *this, frac2 = frac;
        frac1.simplification_fraction();
        frac2.simplification_fraction();
        return(frac1.numeratorNumber == frac2.numeratorNumber && frac1.denominatorNumber == frac2.denominatorNumber);
    }
    void displaying_fraction()
    {
        cout << numeratorNumber << " / " << denominatorNumber << endl;
    }
    
    //operator overloading
    fraction& operator=(const fraction& other)
    {
        if(this == &other)
            return *this;
        numeratorNumber = other.numeratorNumber;
        denominatorNumber = other.denominatorNumber;
        return *this;
    }
    
    fraction operator+(const fraction& frac) const
    {
        return addition_factraction(frac);
    }

    fraction operator-(const fraction& frac) const
    {
        return subtraction_factraction(frac);
    }

    fraction operator*(const fraction& frac) const
    {
        return multiplication_factraction(frac);
    }

    fraction operator/(const fraction& frac) const
    {
        return divison_factraction(frac);
    }
    
    bool operator==(const fraction& frac) const
    {
        return is_equal(frac);
    }

    bool operator!=(const fraction& frac) const
    {
        return !is_equal(frac);
    }
    
    friend istream& operator>>(istream& in, fraction& frac)
    {
        in >> frac.numeratorNumber >> frac.denominatorNumber;
        frac.simplification_fraction();
        return in;
    }

    friend ostream& operator<<(ostream& out, const fraction& frac)
    {
        out << frac.numeratorNumber << " / " << frac.denominatorNumber;
        return out;
    }
    
};

void menu()
{
    cout << "====MENU====" << endl;
    cout << "1. fraction addition" << endl;
    cout << "2. fraction subtraction" << endl;
    cout << "3. fraction product" << endl;
    cout << "4. fraction divison" << endl;
    cout << "5. copy of frac" << endl;
    cout << "6. eqaulity check" << endl;
    cout << "0. to exit" << endl;
    cout << "enter your choice : ";
}

int main()
{
    int choice;
    do{
        menu();
        cin >> choice;
        if(choice == 1)
        {
            fraction frac1, frac2;
            cout << "fraction number 01" << endl;
            cin >> frac1;
            cout << "fraction number 02" << endl;
            cin >> frac2;
            cout << "addition of fraction" << endl;
            fraction fracSum = frac1 + frac2;
            cout << fracSum << endl;
        }
        else if(choice == 2)
        {
            fraction frac1, frac2;
            cout << "fraction number 01" << endl;
            cin >> frac1;
            cout << "fraction number 02" << endl;
            cin >> frac2;
            cout << "subtraction of fraction" << endl;
            fraction fracDiff = frac1 - frac2;
            cout << fracDiff << endl;
        }
        else if(choice == 3)
        {
            fraction frac1, frac2;
            cout << "fraction number 01" << endl;
            cin >> frac1;
            cout << "fraction number 02" << endl;
            cin >> frac2;
            cout << "product of fraction" << endl;
            fraction fracProd = frac1 * frac2;
            cout << fracProd << endl;
        }
        else if(choice == 4)
        {
            fraction frac1, frac2;
            cout << "fraction number 01" << endl;
            cin >> frac1;
            cout << "fraction number 02" << endl;
            cin >> frac2;
            cout << "division of fraction" << endl;
            fraction fracDiv = frac1 / frac2;
            cout << fracDiv;
        }
        else if(choice == 5)
        {
            fraction frac1;
            cout << "copy fraction" << endl;
            cout << "fraction input" << endl;
            cin >> frac1;
            fraction frac;
            frac = frac1;
            cout << frac << endl;
        }
        else if(choice == 6)
        {
            fraction frac1, frac2;
            cout << "fraction number 01" << endl;
            cin >> frac1;
            cout << "fraction number 02" << endl;
            cin >> frac2;
            if(frac1 == frac2)
                cout << "both are same" << endl;
            else
                cout << "both aint same" << endl;
        }
    }while(choice != 0);
    
    return 0;
}
