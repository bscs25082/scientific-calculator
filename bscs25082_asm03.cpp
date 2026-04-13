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

void fraction_menu()
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

int fraction_class()
{
    int choice;
    do{
        fraction_menu();
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

void complex_menu()
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

int complex_class()
{
    int choice;
    do{
        complex_menu();
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

class Polynomial{
    private :
    //private members variable used for the polynomial
    int *coeffs;
    int *powers;
    int size;
    
    //function to swap terms
    //it will arrange polynomial in order
    void swap_terms(int p, int q)
    {
        int tempCoffient = coeffs[p];
        coeffs[p] = coeffs[q];
        coeffs[q] = tempCoffient;
        int tempDegree = powers[p];
        powers[p] = powers[q];
        powers[q] = tempDegree;
    }
    
    //using swap terms to arrange the polynomial in high to low degree
    void sorting_degree_by_descending_order()
    {
        for(int p = 0; p < size; p++)
        {
            for(int q = p + 1; q < size; q++)
                if(powers[q] > powers[p])
                    swap_terms(p, q);
        }
    }
    
    //function to simplify the polynomial
    Polynomial simplified() const
    {
        if(size == 0)
            return Polynomial();
        
        int maximumDegree = powers[0];
        int minimumDegree = powers[0];
        for(int p = 1; p < size; p++)
        {
            if(powers[p] > maximumDegree)
                maximumDegree = powers[p];
            if(powers[p] < minimumDegree)
                minimumDegree = powers[p];
        }
        int degreeRange = maximumDegree - minimumDegree + 1;
        int *bucketArray = new int[degreeRange];
        for(int p = 0; p < degreeRange; p++)
            bucketArray[p] = 0;
        for(int p = 0; p < size; p++)
            bucketArray[powers[p] - minimumDegree] = bucketArray[powers[p] - minimumDegree] + coeffs[p];
        
        int newArraySize = 0;
        for(int p = maximumDegree; p >= minimumDegree; p--)
            if(bucketArray[p - minimumDegree] != 0)
                newArraySize++;
        
        if(newArraySize == 0)
        {
            delete[] bucketArray;
            return Polynomial();
        }
        Polynomial result(newArraySize);
        int index = 0;
        for(int p = maximumDegree; p >= minimumDegree; p--)
        {
            int c = bucketArray[p - minimumDegree];
            if (c != 0)
                result.setTerm(index++, c, p);
        }

        delete[] bucketArray;
        return result;
    }
    
    //for finding the highest power in polynomial
    int degree_of_coffiet() const
    {
        if(size == 0)
            return -1;
        int maximumDegree = powers[0];
        for(int p = 1; p < size; p++)
            if(powers[p] > maximumDegree)
                maximumDegree = powers[p];
        return maximumDegree;
    }

    //the coffient with the highest power or degree
    int leading_coffient() const
    {
        if(size == 0)
            return 0;
        int deg = degree_of_coffiet();
        for(int p = 0; p < size; p++)
            if(powers[p] == deg)
                return coeffs[p];
        return 0;
    }
    
    public :
    
    //polynomial constructor basic
    Polynomial()
    {
        coeffs = nullptr;
        powers = nullptr;
        size = 0;
    }
    
    //polynomial constructor paramtererized
    Polynomial(int size)
    {
        this -> size = (size > 0) ? size : 0;
        if(this -> size == 0)
        {
            coeffs = nullptr;
            powers = nullptr;
        }
        else
        {
            coeffs = new int[this -> size];
            powers = new int[this -> size];
            for(int p = 0; p < this -> size; p++)
            {
                coeffs[p] = 0;
                powers[p] = 0;
            }
        }
    }
    
    //copying constructor for the polynomail
    Polynomial(const Polynomial& p)
    {
        size = p.size;
        if(size == 0)
        {
            coeffs = nullptr;
            powers = nullptr;
        }
        else
        {
            coeffs = new int[size];
            powers = new int[size];
            for(int i = 0; i < size; i++)
            {
                coeffs[i] = p.coeffs[i];
                powers[i] = p.powers[i];
            }
        }
    }
    
    Polynomial(double constant)
    {
        if(constant == 0)
        {
            coeffs = nullptr;
            powers = nullptr;
            size = 0;
        }
        else
        {
            size = 1;
            coeffs = new int[size];
            powers = new int[size];
            coeffs[0] = (int)constant;
            powers[0] = 0;
        }
    }
    
    //functionn for operator
    Polynomial& operator=(const Polynomial& p)
    {
         if(this == &p)
             return *this;
         delete[] coeffs;
         delete[] powers;
         size = p.size;
         if(size == 0)
         {
             coeffs = nullptr;
             powers = nullptr;
         }
         else
         {
             coeffs = new int[size];
             powers = new int[size];
             for(int r = 0; r < size; r++)
             {
                 coeffs[r] = p.coeffs[r];
                 powers[r] = p.powers[r];
             }
         }
         return *this;
     }
    
    //polynomial destrcutor
    ~Polynomial()
    {
        delete[] coeffs;
        delete[] powers;
        coeffs = nullptr;
        powers = nullptr;
        size = 0;
    }
    
    //function to set the terms
    void setTerm(int index, int coffient, int degree)
    {
        if(index < 0 || index >= size)
            return;
        coeffs[index] = coffient;
        powers[index] = degree;
    }
    
    //function for input
    Polynomial input_polynomial(int polynomialNumber)
    {
        int noOfTerms;
        cout << "enter number of terms for polynomial " << polynomialNumber << " : ";
        cin >> noOfTerms;
        Polynomial poly(noOfTerms);
        int* usedPolynomial = new int[noOfTerms];
        for(int p = 0; p < noOfTerms; p++)
        {
            int coffient, power = 0;
            cout << endl << "polynomial " << polynomialNumber << " term " << p << " coefficient : ";
            cin >> coffient;
            bool isCorrentInput = false;
            while(isCorrentInput == false)
            {
                cout << "polynomial " << polynomialNumber << " term " << p << " power : ";
                cin >> power;
                isCorrentInput = true;
                for(int q = 0; q < p; q++)
                {
                    if(usedPolynomial[q] == power)
                    {
                        cout << "duplicate power not allowed. enter again." << endl;
                        isCorrentInput = false;
                        break;
                    }
                }
            }
            usedPolynomial[p] = power;
            poly.setTerm(p, coffient, power);
        }
        delete[] usedPolynomial;
        return poly;
    }
    
    //function to show the polynomial
    void display() const
    {
        if(size == 0)
        {
            cout << "0";
            return;
        }
        Polynomial tempPolynomial(*this);
        tempPolynomial.sorting_degree_by_descending_order();
        bool isPrinted = false;
        for(int p = 0; p < tempPolynomial.size; p++)
        {
            int coffient = tempPolynomial.coeffs[p];
            int degree = tempPolynomial.powers[p];
            if(coffient == 0)
                continue;
            if(isPrinted == true)
            {
                if(coffient > 0)
                    cout << " + ";
                else
                {
                    cout << " - ";
                    coffient = -coffient;
                }
            }
            else
            {
                if(coffient < 0)
                {
                    cout << "-";
                    coffient = -coffient;
                }
            }
            if(degree == 0)
                cout << coffient;
            else if(degree == 1)
            {
                if(coffient != 1)
                    cout << coffient;
                cout << "x";
            }
            else
            {
                if(coffient != 1)
                    cout << coffient;
                cout << "x^" << degree;
            }
            isPrinted = true;
        }

        if(isPrinted == false)
            cout << "0";
    }
    
    //function of additioon of two poolys
    Polynomial add(const Polynomial& other) const
    {
        Polynomial combinedPolynomial(size + other.size);
        int index = 0;
        for(int p = 0; p < size; p++)
            combinedPolynomial.setTerm(index++, coeffs[p], powers[p]);
        for(int p = 0; p < other.size; p++)
            combinedPolynomial.setTerm(index++, other.coeffs[p], other.powers[p]);
        return combinedPolynomial.simplified();
    }
    
    //function to subtract one poly from other
    Polynomial subtract(const Polynomial& other) const
    {
        Polynomial combinedPolynomial(size + other.size);
        int index = 0;
        for(int p = 0; p < size; p++)
            combinedPolynomial.setTerm(index++, coeffs[p], powers[p]);
        for(int p = 0; p < other.size; p++)
            combinedPolynomial.setTerm(index++, -other.coeffs[p], other.powers[p]);
        return combinedPolynomial.simplified();
    }

    //function tpo mulitply both polynomail
    Polynomial multiply(const Polynomial& other) const
    {
        if(size == 0 || other.size == 0)
            return Polynomial();
        Polynomial productOfPolynomial(size * other.size);
        int index = 0;
        for(int p = 0; p < size; p++)
        {
            for(int q = 0; q < other.size; q++)
                productOfPolynomial.setTerm(index++, coeffs[p] * other.coeffs[q], powers[p] + other.powers[q]);
        }
        return productOfPolynomial.simplified();
    }
    
    //function to evalute the poly for X value
    int evaluate(int x) const
    {
        long long answer = 0;
        for(int p = 0; p < size; p++)
        {
            int degree = powers[p];
            long long xDegree = 1;
            if(degree >= 0)
            {
                for(int q = 0; q < degree; q++)
                    xDegree = xDegree * x;
                answer = answer + (long long)coeffs[p] * xDegree;
            }
            else
            {
                int position = -degree;
                long long denominator = 1;
                for(int k = 0; k < position; k++)
                    denominator = denominator * x;
                if(denominator == 0)
                    return 0;
                answer = answer + (long long)coeffs[p] / denominator;
            }
        }
        return (int)answer;
    }
    
    //dividing two polynomail
    Polynomial division(const Polynomial& divisor) const
    {
        Polynomial poly1 = this -> simplified();
        Polynomial poly2 = divisor.simplified();
        if(poly2.size == 0)
            return Polynomial();
        if(poly1.size == 0)
            return Polynomial();
        if(poly1.degree_of_coffiet() < poly2.degree_of_coffiet())
            return Polynomial();
        int maximumNumberOfTerms = poly1.degree_of_coffiet() - poly2.degree_of_coffiet() + 1;
        Polynomial polynomialResult(maximumNumberOfTerms);
        int resultPolyCount = 0;
        Polynomial tempPoly = poly1;
        while(tempPoly.size != 0 && tempPoly.degree_of_coffiet() >= poly2.degree_of_coffiet())
        {
            int leadingCoffientTemp = tempPoly.leading_coffient();
            int leadingCoffientPoly2 = poly2.leading_coffient();
            int degreeTemp = tempPoly.degree_of_coffiet();
            int degreePoly2 = poly2.degree_of_coffiet();
            if(leadingCoffientPoly2 == 0)
                break;
            if(leadingCoffientTemp % leadingCoffientPoly2 != 0)
                break;
            int newCoffient = leadingCoffientTemp / leadingCoffientPoly2;
            int newDegree = degreeTemp - degreePoly2;
            polynomialResult.setTerm(resultPolyCount++, newCoffient, newDegree);
            Polynomial quotientPoly(1);
            quotientPoly.setTerm(0, newCoffient, newDegree);
            Polynomial subtractPolyTerm = poly2.multiply(quotientPoly);
            tempPoly = tempPoly.subtract(subtractPolyTerm).simplified();
        }
        if(resultPolyCount == 0)
            return Polynomial();
        Polynomial finalPolynomial(resultPolyCount);
        for(int p = 0; p < resultPolyCount; p++)
            finalPolynomial.setTerm(p, polynomialResult.coeffs[p], polynomialResult.powers[p]);
        return finalPolynomial.simplified();
    }
    
    //function for derivative
    Polynomial derivative() const
    {
        if(size == 0)
            return Polynomial();
        Polynomial tempPoly(size);
        int index = 0;
        for(int p = 0; p < size; p++)
        {
            int coffient = coeffs[p];
            int degree = powers[p];
            if(degree == 0)
                continue;
            tempPoly.setTerm(index++, coffient * degree, degree - 1);
        }
        if(index == 0)
            return Polynomial();
        Polynomial derivativePoly(index);
        for(int p = 0; p < index; p++)
            derivativePoly.setTerm(p, tempPoly.coeffs[p], tempPoly.powers[p]);
        return derivativePoly.simplified();
    }
    
    //function for integration
    Polynomial integration() const
    {
        if(size == 0)
            return Polynomial();
        Polynomial tempPoly(size);
        int index = 0;
        for(int p = 0; p < size; p++)
        {
            int coffient = coeffs[p];
            int degree = powers[p];
            int newDegree = degree + 1;
            if(newDegree == 0)
                continue;
            if(coffient % newDegree != 0)
                continue;
            int newCoffient = coffient / newDegree;
            tempPoly.setTerm(index++, newCoffient, newDegree);
        }
        if(index == 0)
            return Polynomial();
        Polynomial integralPoly(index);
        for(int p = 0; p < index; p++)
            integralPoly.setTerm(p, tempPoly.coeffs[p], tempPoly.powers[p]);
        return integralPoly.simplified();
    }
    
    //function which will display integration in form of fraction
    void display_integration() const
    {
        Polynomial tempPoly(*this);
        tempPoly = tempPoly.simplified();
        tempPoly.sorting_degree_by_descending_order();
        if(tempPoly.size == 0)
        {
            cout << "0";
            return;
        }
        bool isPrinted = false;
        for(int p = 0; p < tempPoly.size; p++)
        {
            int coffient = tempPoly.coeffs[p];
            int degree = tempPoly.powers[p];
            if(coffient == 0)
                continue;
            int newDegree = degree + 1;
            if(newDegree == 0)
            {
                if(isPrinted == true)
                {
                    if(coffient > 0)
                        cout << " + ";
                    else
                    {
                        cout << " - ";
                        coffient = -coffient;
                    }
                }
                else
                {
                    if(coffient < 0)
                    {
                        cout << "-";
                        coffient = -coffient;
                    }
                }
                if(coffient != 1)
                    cout << coffient;
                cout << "ln|x|";
                isPrinted = true;
                continue;
            }
            int numerator = coffient;
            int denominator = newDegree;
            if(isPrinted == true)
            {
                if((long long)numerator * (long long)denominator > 0)
                    cout << " + ";
                else
                    cout << " - ";
            }
            else
            {
                if((long long)numerator * (long long)denominator < 0)
                    cout << "-";
            }
            numerator = abs(numerator);
            denominator = abs(denominator);
            int temp1 = numerator, temp2 = denominator;
            while(temp2 != 0)
            {
                int temp = temp1 % temp2;
                temp1 = temp2;
                temp2 = temp;
            }
            int gcd = (temp1 == 0) ? 1 : temp1;
            numerator = numerator / gcd;
            denominator = denominator / gcd;
            if(newDegree == 0)
            {
                if(denominator == 1)
                    cout << numerator;
                else
                    cout << numerator << "/" << denominator;
            }
            else
            {
                if(!(numerator == 1 && denominator == 1))
                {
                    if(denominator == 1)
                        cout << numerator;
                    else
                        cout << numerator << "/" << denominator;
                }
                if(newDegree == 1)
                    cout << "x";
                else
                    cout << "x^" << newDegree;
            }
            isPrinted = true;
        }
        if(!isPrinted)
            cout << "0";
        cout << " + C";
    }
    
    //finding remainder of division of two poly
    Polynomial remainder(const Polynomial& divisor) const
    {
        Polynomial poly1 = this -> simplified();
        Polynomial poly2 = divisor.simplified();
        if(poly2.size == 0)
            return Polynomial();
        if(poly1.size == 0)
            return Polynomial();
        if(poly1.degree_of_coffiet() < poly2.degree_of_coffiet())
            return poly1;
        Polynomial reminderPolynomial = poly1;
        while(reminderPolynomial.size != 0 && reminderPolynomial.degree_of_coffiet() >= poly2.degree_of_coffiet())
        {
            int leadingCoffientReminderPoly = reminderPolynomial.leading_coffient();
            int leadingCoffientPoly2 = poly2.leading_coffient();
            int degreeReminderPoly = reminderPolynomial.degree_of_coffiet();
            int degreePoly2 = poly2.degree_of_coffiet();
            if(leadingCoffientPoly2 == 0)
                break;
            if(leadingCoffientReminderPoly % leadingCoffientPoly2 != 0)
                break;
            int newCoffient = leadingCoffientReminderPoly / leadingCoffientPoly2;
            int newDegree = degreeReminderPoly - degreePoly2;
            Polynomial quotientPoly(1);
            quotientPoly.setTerm(0, newCoffient, newDegree);
            Polynomial subtractPolyTerm = poly2.multiply(quotientPoly);
            reminderPolynomial = reminderPolynomial.subtract(subtractPolyTerm).simplified();
        }
        return reminderPolynomial.simplified();
    }
    
    //operate overload
    Polynomial operator+(const Polynomial& other) const
    {
        return add(other);
    }

    Polynomial operator-(const Polynomial& other) const
    {
        return subtract(other);
    }

    Polynomial operator*(const Polynomial& other) const
    {
        return multiply(other);
    }
    
    Polynomial operator/(const Polynomial& other) const
    {
        return division(other);
    }
    
    Polynomial operator%(const Polynomial& other) const
    {
        return remainder(other);
    }
    
    bool operator==(const Polynomial& other) const
    {
        Polynomial poly1 = this->simplified();
        Polynomial poly2 = other.simplified();
        if(poly1.size != poly2.size)
            return false;
        poly1.sorting_degree_by_descending_order();
        poly2.sorting_degree_by_descending_order();
        for(int p = 0; p < poly1.size; p++)
            if(poly1.coeffs[p] != poly2.coeffs[p] || poly1.powers[p] != poly2.powers[p])
                return false;
        return true;
    }

    bool operator!=(const Polynomial& other) const
    {
        return !(*this == other);
    }
    
    //friend function
    friend istream& operator>>(istream& in, Polynomial& poly)
    {
        int numberOfTerms;
        cout << "enter number of terms : ";
        in >> numberOfTerms;
        delete[] poly.coeffs;
        delete[] poly.powers;
        poly.coeffs = nullptr;
        poly.powers = nullptr;
        poly.size = (numberOfTerms > 0) ? numberOfTerms : 0;
        if(poly.size == 0)
            return in;
        poly.coeffs = new int[poly.size];
        poly.powers = new int[poly.size];
        cout << "enter " << numberOfTerms << " coffient and power" << endl;
        for(int p = 0; p < poly.size; p++)
        {
            cout << "enter coffient and power of " << p << " term : ";
            in >> poly.coeffs[p] >> poly.powers[p];
        }
        Polynomial s = poly.simplified();
        poly = s;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Polynomial& poly)
    {
        poly.display();
        return out;
    }
};

//to display menu for functions
void polynomial_menu()
{
    cout << "====== MENU =======" << endl;
    cout << " 1. display polynomial 1" << endl;
    cout << " 2. display polynomial 2" << endl;
    cout << " 3. addition of (P1 + P2)" << endl;
    cout << " 4. subtraction of (P1 - P2)" << endl;
    cout << " 5. multiply of (P1 * P2)" << endl;
    cout << " 6. evaluate P1 at x" << endl;
    cout << " 7. divison of (P1 / P2)" << endl;
    cout << " 8. reminder of (P1 % P2)" << endl;
    cout << " 9. copy of polynomial 1" << endl;
    cout << "10. comparison of both polynomail" << endl;
    cout << "11. enter both polynomial again" << endl;
    cout << "12. derivative of polynomial" << endl;
    cout << "13. integral of polynomial" << endl;
    cout << "0. to exit" << endl;
    cout << "enter your choice : ";
}

int polynomial_class()
{
    int choice;
    Polynomial poly1, poly2;
    cout << "enter polynomial 1 : " << endl;
    cin >> poly1;
    cout << "enter polynomial 2 : " << endl;
    cin >> poly2;
    do{
        polynomial_menu();
        cin >> choice;
        if(choice == 1)
            cout << "polynomial 1 : " << poly1 << endl;
        else if(choice == 2)
            cout << "polynomial 2 : " << poly2 << endl;
        else if(choice == 3)
        {
            cout << "sum of polynomial" << endl;
            Polynomial polySum = poly1 + poly2;
            cout << polySum << endl;
        }
        else if(choice == 4)
        {
            cout << "differnce of polynomial" << endl;
            Polynomial polyDiff = poly1 - poly2;
            cout << polyDiff << endl;
        }
        else if(choice == 5)
        {
            cout << "product of polynomial" << endl;
            Polynomial polyProd = poly1 * poly2;
            cout << polyProd << endl;
        }
        else if(choice == 6)
        {
            int x;
            cout << "enter x : ";
            cin >> x;
            cout << "polynomial 1 (" << x << ") : " << poly1.evaluate(x);
        }
        else if(choice == 7)
        {
            cout << "division of polynomial" << endl;
            Polynomial polyDiv = poly1 / poly2;
            cout << polyDiv << endl;
        }
        else if(choice == 8)
        {
            cout << "reminder of polynomial" << endl;
            Polynomial polyRem = poly1 % poly2;
            cout << polyRem << endl;
        }
        else if(choice == 9)
        {
            cout << "copy of polynomial 1" << endl;
            Polynomial polyCopy = poly1;
            cout << polyCopy << endl;
        }
        else if(choice == 10)
        {
            cout << "comparison of polynomial" << endl;
            if(poly1 == poly2)
                cout << "both are same" << endl;
            else
                cout << "both aint same" << endl;
        }
        else if(choice == 11)
        {
            cout << "enter polynomial 1 : ";
            cin >> poly1;
            cout << "enter polynomial 2 : ";
            cin >> poly2;
        }
        else if(choice == 12)
        {
            Polynomial derivative1, derivative2;
            derivative1 = poly1.derivative();
            derivative2 = poly2.derivative();
            cout << "derivative of both polynomial" << endl;
            cout << derivative1 << endl;
            cout << derivative2 << endl;
        }
        else if(choice == 13)
        {
            cout << "integral of both polynomial" << endl;
            poly1.display_integration();
            cout << endl;
            poly2.display_integration();
            cout << endl;
        }
        else if(choice == 0)
            cout << "exiting code" << endl;
        else
            cout << "invalid choice" << endl;
    }while(choice != 0);
    
    return 0;
}

class Set
{
    private :
    int *setData;
    int setSize;
    int setCapacity;
    
    //function to check if set contain x or not
    bool is_containg(int x) const
    {
        for(int p = 0; p < setSize; p++)
            if(setData[p] == x)
                return true;
        return false;
    }
    
    //function to ensure capacity
    void ensuring_capacity(int newCapacity)
    {
        if(newCapacity <= setCapacity)
            return;
        int* newDataSet = new int[newCapacity];
        for(int p = 0; p < setSize; p++)
            newDataSet[p] = setData[p];
        delete[] setData;
        setData = newDataSet;
        setCapacity = newCapacity;
    }
    
    //adding unique
    void add_unique(int x)
    {
        if(is_containg(x))
            return;
        if(setSize == setCapacity)
        {
            int newCapacity = (setCapacity == 0) ? 1 : setCapacity * 2;
            ensuring_capacity(newCapacity);
        }
        setData[setSize++] = x;
    }
     
    public :
    
    //default constructor
    Set()
    {
        setData = nullptr;
        setSize = 0;
        setCapacity = 0;
    }
    
    //parameterized constructor & conversion constructor
    Set(int value)
    {
        setSize = 0;
        setCapacity = value;
        if(setCapacity > 0)
            setData = new int[setCapacity];
        else
            setData = nullptr;
    }

    //copy constructor
    Set(const Set& setElement)
    {
        setSize = setElement.setSize;
        setCapacity = setElement.setCapacity;
        if(setCapacity > 0)
        {
            setData = new int[setCapacity];
            for(int p = 0; p < setSize; p++)
                setData[p] = setElement.setData[p];
        }
        else
            setData = nullptr;
    }
    
    //destructor
    ~Set()
    {
        delete[] setData;
        setData = nullptr;
        setSize = 0;
        setCapacity = 0;
    }
    
    //operator overloading
    Set& operator=(const Set& setElement)
    {
        if(this == &setElement)
            return *this;
        delete[] setData;
        setCapacity = setElement.setCapacity;
        setSize = setElement.setSize;
        setData = (setCapacity > 0) ? new int[setCapacity] : nullptr;
        for(int p = 0; p < setSize; p++)
            setData[p] = setElement.setData[p];
        return *this;
    }
    
    //function for union (+)
    Set operator+(const Set& setElement)
    {
        Set resultSet(setSize + setElement.setSize);
        for(int p = 0; p < setSize; p++)
            resultSet.add_unique(setData[p]);
        for(int p = 0; p < setElement.setSize; p++)
            resultSet.add_unique(setElement.setData[p]);
        return resultSet;
    }
    
    //function to subtract *this from setELement
    Set operator-(const Set& setElement)
    {
        Set resultSet(setSize);
        for(int p = 0; p < setSize; p++)
            if(!setElement.is_containg(setData[p]))
                resultSet.add_unique(setData[p]);
        return resultSet;
    }
    
    //function to find intersection *
    Set operator*(const Set& setELement)
    {
        Set resultSet((setSize < setELement.setSize) ? setSize : setELement.setSize);
        for(int p = 0; p < setSize; p++)
            if(setELement.is_containg(setData[p]))
                resultSet.add_unique(setData[p]);
        return resultSet;
    }
    
    //function to check equality
    friend bool operator==(const Set& setA, const Set& setB)
    {
        if(setA.setSize != setB.setSize)
            return false;
        for(int p = 0; p < setA.setSize; p++)
            if(!setB.is_containg(setA.setData[p]))
                return false;
        return true;
    }
    
    //friend function for equality
    friend bool operator==(int value, const Set& setElement)
    {
        if(setElement.setSize == 1 && setElement.setData[0] == value)
            return true;
        else
            return false;
    }
    
    bool operator<(const Set& setElement)
    {
        if(setSize >= setElement.setSize)
            return false;
        for(int p = 0; p < setSize; p++)
            if(!setElement.is_containg(setData[p]))
                return false;
        return true;
    }
    
    //function for prefix ++
    Set& operator++()
    {
        for(int p = 0; p < setSize; p++)
            setData[p] = setData[p] + 1;
        return *this;
    }
    
    //function for postfix ++
    Set operator++(int)
    {
        Set oldSet(*this);
        for(int p = 0; p < setSize; p++)
            setData[p] = setData[p] + 1;
        return oldSet;
    }
    
    //function for << cout
    friend ostream& operator<<(ostream& out, const Set& setElement)
    {
        out << "{ ";
        for(int p = 0; p < setElement.setSize; p++)
        {
            out << setElement.setData[p];
            if(p != setElement.setSize - 1)
                out << " , ";
        }
        out << " }";
        return out;
    }
    
    //function for << cin
    friend istream& operator>>(istream& in, Set& setElement)
    {
        int noOfELement;
        cout << "enter number of elements : ";
        in >> noOfELement;
        cout << "enter elements of set : ";
        for(int p = 0; p < noOfELement; p++)
        {
            int x;
            in >> x;
            setElement.add_unique(x);
        }
        return in;
    }
};

void set_menu()
{
    cout << "===MENU===" << endl;
    cout << "1. copy of set" << endl;
    cout << "2. union of set" << endl;
    cout << "3. subtraction of set" << endl;
    cout << "4. intersection of set" << endl;
    cout << "5. checking equality of set" << endl;
    cout << "6. pre-fix addition" << endl;
    cout << "7. post-fix addition" << endl;
    cout << "0. to exit" << endl;
    cout << "enter your choice : ";
}

int set_class()
{
    int choice;
    do{
        set_menu();
        cin >> choice;
        if(choice == 1)
        {
            Set setA;
            cout << "enter set A : " << endl;
            cin >> setA;
            Set setCopy = setA;
            cout << "copy of set A" << endl;
            cout << setCopy << endl;
        }
        else if(choice == 2)
        {
            Set setA, setB;
            cout << "enter set A : " << endl;
            cin >> setA;
            cout << "enter set B : " << endl;
            cin >> setB;
            Set setUnion = setA + setB;
            cout << "union of set A and B" << endl;
            cout << setUnion << endl;
        }
        else if(choice == 3)
        {
            Set setA, setB;
            cout << "enter set A : " << endl;
            cin >> setA;
            cout << "enter set B : " << endl;
            cin >> setB;
            Set setDiff = setA - setB;
            cout << "differnce of set A and B" << endl;
            cout << setDiff << endl;
        }
        else if(choice == 4)
        {
            Set setA, setB;
            cout << "enter set A : " << endl;
            cin >> setA;
            cout << "enter set B : " << endl;
            cin >> setB;
            Set setIntersection = setA * setB;
            cout << "intersection of set A and B" << endl;
            cout << setIntersection << endl;
        }
        else if(choice == 5)
        {
            Set setA, setB;
            cout << "enter set A : " << endl;
            cin >> setA;
            cout << "enter set B : " << endl;
            cin >> setB;
            if(setA == setB)
                cout << "both set are same" << endl;
            else
                cout << "both set aint same" << endl;
            if(setA < setB)
                cout << "set A is lesser then set B" << endl;
            else if(setB < setA)
                cout << "set B is lesser" << endl;
            else
                cout << "same" << endl;
        }
        else if(choice == 6)
        {
            Set setA;
            cout << "enter set A : " << endl;
            cin >> setA;
            ++setA;
            cout << "after prefix : " << setA << endl;
        }
        else if(choice == 7)
        {
            Set setA;
            cout << "enter set A : " << endl;
            cin >> setA;
            Set oldSet = setA++;
            cout << "returned value : " << oldSet << endl;
            cout << "after postfix: " << setA << endl;
        }
        else if(choice == 0)
            cout << "exiting code" << endl;
        else
            cout << "invalid choice" << endl;
    }while(choice != 0);
    return 0;
}

class DynamicMatrix
{
    private :
    double **ptr;
    int columns;
    int rows;
    
    //allocating the matrix with null values
    
    void allocate_with_zero(int noOfRows, int noOfColumns)
    {
        rows = noOfRows;
        columns = noOfColumns;
        if(rows <= 0 || columns <= 0)
        {
            rows = columns = 0;
            ptr = nullptr;
            return;
        }
        ptr = new double*[rows];
        for(int p = 0; p < rows; p++)
        {
            ptr[p] = new double[columns];
            for(int q = 0; q < columns; q++)
                ptr[p][q] = 0;
        }
    }
    
    void deleting_memory()
    {
        if(!ptr)
        {
            rows = columns = 0;
            return;
        }
        for(int p = 0; p < rows; p++)
            delete[] ptr[p];
        delete[] ptr;
        ptr = nullptr;
        rows = columns = 0;
    }
    
    public :
    
    //default constructor
    DynamicMatrix()
    {
        ptr = nullptr;
        rows = 0;
        columns = 0;
    }
    
    //parameterized constructor
    DynamicMatrix(int noOfRows, int noOfColumns)
    {
        ptr = nullptr;
        allocate_with_zero(noOfRows, noOfColumns);
    }
    
    //conversation constructor
    explicit DynamicMatrix(int value)
    {
        ptr = nullptr;
        allocate_with_zero(1, 1);
        ptr[0][0] = value;
    }
    
    //copy constructor for class
    DynamicMatrix(const DynamicMatrix &matrix)
    {
        allocate_with_zero(matrix.rows, matrix.columns);
        for(int p = 0; p < rows; p++)
            for(int q = 0; q < columns; q++)
                ptr[p][q] = matrix.ptr[p][q];
    }
    
    //destructor
    ~DynamicMatrix()
    {
        deleting_memory();
    }
    
    //assigmnet operator
    DynamicMatrix& operator=(const DynamicMatrix& matrix)
    {
        if(this == &matrix)
            return *this;
        deleting_memory();
        allocate_with_zero(matrix.rows, matrix.columns);
        for(int p = 0; p < rows; p++)
            for(int q = 0; q < columns; q++)
                ptr[p][q] = matrix.ptr[p][q];
        return *this;
    }
    
    //overloading + operator
    DynamicMatrix operator+(const DynamicMatrix& matrix) const
    {
        if(rows != matrix.rows || columns != matrix.columns)
            return DynamicMatrix();
        DynamicMatrix matrixSum(rows, columns);
        for(int p = 0; p < rows; p++)
            for(int q = 0; q < columns; q++)
                matrixSum.ptr[p][q] = ptr[p][q] + matrix.ptr[p][q];
        return matrixSum;
    }
    
    //overloading - operator
    DynamicMatrix operator-(const DynamicMatrix& matrix) const
    {
        if(rows != matrix.rows || columns != matrix.columns)
            return DynamicMatrix();
        DynamicMatrix matrixDiff(rows, columns);
        for(int p = 0; p < rows; p++)
            for(int q = 0; q < columns; q++)
                matrixDiff.ptr[p][q] = ptr[p][q] - matrix.ptr[p][q];
        return matrixDiff;
    }
    
    //overloading * operator
    DynamicMatrix operator*(const DynamicMatrix& matrix) const
    {
        if(columns != matrix.rows)
            return DynamicMatrix();
        DynamicMatrix matrixProduct(rows, matrix.columns);
        for(int p = 0; p < rows; p++)
        {
            for(int q = 0; q < matrix.columns; q++)
            {
                double sum = 0.0;
                for(int r = 0; r < columns; r++)
                    sum = sum + (ptr[p][r] * matrix.ptr[r][q]);
                matrixProduct.ptr[p][q] = sum;
            }
        }
        return matrixProduct;
    }
    
    //function for product with scalar
    DynamicMatrix operator*(int scalar) const
    {
        DynamicMatrix productMatrix(rows, columns);
        for(int p = 0; p < rows; p++)
            for(int q = 0; q < columns; q++)
                productMatrix.ptr[p][q] = ptr[p][q] * scalar;
        return productMatrix;
    }
    
    DynamicMatrix operator/(int scalar) const
    {
        if(scalar == 0)
            return DynamicMatrix();
        DynamicMatrix divisionMatrix(rows, columns);
        for(int p = 0; p < rows; p++)
            for(int q = 0; q < columns; q++)
                divisionMatrix.ptr[p][q] = ptr[p][q] / scalar;
        return divisionMatrix;
    }
    
    DynamicMatrix operator-() const
    {
        DynamicMatrix negetiveMatrix(rows, columns);
        for(int p = 0; p < rows; p++)
            for(int q = 0; q < columns; q++)
                negetiveMatrix.ptr[p][q] = -ptr[p][q];
        return negetiveMatrix;
    }
    
    //functions for comparison
    bool operator==(const DynamicMatrix& other) const
    {
        if(rows != other.rows || columns != other.columns)
            return false;
        for(int p = 0; p < rows; p++)
            for(int q = 0; q < columns; q++)
                if(ptr[p][q] != other.ptr[p][q])
                    return false;

        return true;
    }

    bool operator!=(const DynamicMatrix& other) const
    {
        return !(*this == other);
    }
    
    //helper function
    int getting_rows() const
    {
        return rows;
    }
    int getting_columns() const
    {
        return columns;
    }

    void set(int r, int c, double value)
    {
        if(!ptr)
            return;
        if(r < 0 || r >= rows || c < 0 || c >= columns)
            return;
        ptr[r][c] = value;
    }

    double get(int r, int c) const
    {
        if(!ptr)
            return 0.0;
        if(r < 0 || r >= rows || c < 0 || c >= columns)
            return 0.0;
        return ptr[r][c];
    }
    
    //pre-increment (++matrix)
    DynamicMatrix& operator++()
    {
        for(int p = 0; p < rows; p++)
            for(int q = 0; q < columns; q++)
                ++ptr[p][q];
        return *this;
    }

    // post-increment (matrix++)
    DynamicMatrix operator++(int)
    {
        DynamicMatrix oldMatrix(*this);
        ++(*this);
        return oldMatrix;
    }

    //pre-decrement (--matrix)
    DynamicMatrix& operator--()
    {
        for(int p = 0; p < rows; p++)
            for(int q = 0; q < columns; q++)
                --ptr[p][q];
        return *this;
    }

    // post-decrement (matrix--)
    DynamicMatrix operator--(int)
    {
        DynamicMatrix oldMatrix(*this);
        --(*this);
        return oldMatrix;
    }
    
    //functioon to add row
    void adding_row(double* newRow, int rowSize)
    {
        if(rowSize != columns || columns <= 0)
            return;
        int newRows = rows + 1;
        double** newPtr = new double*[newRows];
        
        for(int p = 0; p < newRows; p++)
            newPtr[p] = new double[columns];
        
        for(int p = 0; p < rows; p++)
            for(int q = 0; q < columns; q++)
                newPtr[p][q] = ptr[p][q];
        
        for(int q = 0; q < columns; q++)
            newPtr[newRows - 1][q] = newRow[q];
        for(int p = 0; p < rows; p++)
            delete[] ptr[p];
        delete[] ptr;
        ptr = newPtr;
        rows = newRows;
    }

    //function to add column
    void adding_column(double* newColumn, int columnSize)
    {
        if(columnSize != rows || rows <= 0)
            return;
        int newColumns = columns + 1;
        double** newPtr = new double*[rows];
        for(int p = 0; p < rows; p++)
            newPtr[p] = new double[newColumns];
        for(int p = 0; p < rows; p++)
        {
            for(int q = 0; q < columns; q++)
                newPtr[p][q] = ptr[p][q];
            newPtr[p][newColumns - 1] = newColumn[p];
        }
        for(int p = 0; p < rows; p++)
            delete[] ptr[p];
        delete[] ptr;
        ptr = newPtr;
        columns = newColumns;
    }
    
    //function to delete row
    void removing_row(int rowNumber)
    {
        if(rowNumber < 0 || rowNumber >= rows)
            return;
        int newRows = rows - 1;
        if(newRows == 0)
        {
            deleting_memory();
            return;
        }
        double** newPtr = new double*[newRows];
        for(int p = 0; p < newRows; p++)
            newPtr[p] = new double[columns];
        int row2 = 0;
        for(int p = 0; p < rows; p++)
        {
            if(p == rowNumber)
                continue;
            for(int q = 0; q < columns; q++)
                newPtr[row2][q] = ptr[p][q];
            row2++;
        }
        for(int p = 0; p < rows; p++)
            delete[] ptr[p];
        delete[] ptr;
        ptr = newPtr;
        rows = newRows;
    }
    
    //removing columns
    void removing_column(int columnNumber)
    {
        if(columnNumber < 0 || columnNumber >= columns)
            return;
        int newColumns = columns - 1;
        if(newColumns == 0)
        {
            deleting_memory();
            return;
        }
        double** newPtr = new double*[rows];
        for(int p = 0; p < rows; p++)
            newPtr[p] = new double[newColumns];
        for(int p = 0; p < rows; p++)
        {
            int column2 = 0;
            for(int q = 0; q < columns; q++)
            {
                if(q == columnNumber)
                    continue;
                newPtr[p][column2] = ptr[p][q];
                column2++;
            }
        }
        for(int p = 0; p < rows; p++)
            delete[] ptr[p];
        delete[] ptr;
        ptr = newPtr;
        columns = newColumns;
    }
    
    //transpose function
    DynamicMatrix transpose_of_matrix() const
    {
        DynamicMatrix transpose(columns, rows);
        for(int p = 0; p < rows; p++)
            for(int q = 0; q < columns; q++)
                transpose.ptr[q][p] = ptr[p][q];
        return transpose;
    }
    
    //function for double trace
    double trace_function() const
    {
        if(rows != columns)
            return 0.0;
        double sumOfMatrix = 0.0;
        for(int p = 0; p < rows; p++)
            sumOfMatrix = sumOfMatrix + ptr[p][p];
        return sumOfMatrix;
    }
    
    //function for is square or not
    bool is_sqaure_matrix() const
    {
        if(rows == columns && rows > 0)
            return true;
        else
            return false;
    }
    
    bool is_identity_matrix() const
    {
        if(!is_sqaure_matrix())
            return false;
        for(int p = 0; p < rows; p++)
        {
            for(int q = 0; q < columns; q++)
            {
                if (p == q)
                {
                    if(ptr[p][q] != 1.0)
                        return false;
                }
                else
                {
                    if(ptr[p][q] != 0.0)
                        return false;
                }
            }
        }
        return true;
    }
    
    //function to check matrix symmetry
    bool is_symmetric_matrix() const
    {
        if(!is_sqaure_matrix())
            return false;
        for(int p = 0; p < rows; p++)
            for(int q = p + 1; q < columns; q++)
                if(ptr[p][q] != ptr[q][p])
                    return false;
        return true;
    }
    
    //getting minor function
    DynamicMatrix minor_matrix(int prevRow, int prevColumn) const
    {
        DynamicMatrix matrix(rows - 1, columns - 1);
        int row2 = 0;
        for(int p = 0; p < rows; p++)
        {
            if(p == prevRow)
                continue;
            int column2 = 0;
            for(int q = 0; q < columns; q++)
            {
                if(q == prevColumn)
                    continue;
                matrix.ptr[row2][column2] = ptr[p][q];
                column2++;
            }
            row2++;
        }
        return matrix;
    }
    
    //helper function
    bool is_zero(double x) const
    {
        return(x > -1e-9 && x < 1e-9);
    }
    
    //finding determiniante
    double finding_determinant() const
    {
        if(rows <= 0 || columns <= 0)
            return 0;
        if(rows != columns)
            return 0;
        if(rows == 1)
            return ptr[0][0];
        if(rows == 2)
        {
            double determinant = ptr[0][0] * ptr[1][1] - ptr[0][1] * ptr[1][0];
            return determinant;
        }
        double determinant = 0;
        for(int q = 0; q < columns; q++)
        {
            DynamicMatrix matrix = minor_matrix(0, q);
            int sign = (q % 2 == 0) ? 1 : -1;
            determinant += sign * ptr[0][q] * matrix.finding_determinant();
        }
        return determinant;
    }
    
    //creating identity matrix
    static DynamicMatrix identity_matrix(int number)
    {
        DynamicMatrix identity(number, number);
        for(int p = 0; p < number; p++)
            identity.ptr[p][p] = 1.0;
        return identity;
    }
    
    //zero-matrix
    static DynamicMatrix zero_matrix(int row, int column)
    {
        DynamicMatrix zeroMatrix(row, column);
        return zeroMatrix;
    }
    
    //matrix power
    DynamicMatrix power_matrix(int exponent) const
    {
        if(!is_sqaure_matrix() || exponent < 0)
            return DynamicMatrix();
        if(exponent == 0)
            return DynamicMatrix::identity_matrix(rows);
        DynamicMatrix resultMatrix = DynamicMatrix::identity_matrix(rows);
        DynamicMatrix baseMatrix(*this);
        while(exponent > 0)
        {
            if(exponent % 2 == 1)
                resultMatrix = resultMatrix * baseMatrix;
            baseMatrix = baseMatrix * baseMatrix;
            exponent = exponent / 2;
        }
        return resultMatrix;
    }
    
    //inverse of matrix
    DynamicMatrix inverse_matrix() const
    {
        if(!is_sqaure_matrix())
            return DynamicMatrix();
        double determinant = finding_determinant();
        if(is_zero(determinant))
            return DynamicMatrix();
        if(rows == 1)
        {
            DynamicMatrix inverseMatrix(1, 1);
            inverseMatrix.ptr[0][0] = 1.0 / ptr[0][0];
            return inverseMatrix;
        }
        DynamicMatrix coffient(rows, columns);
        for(int p = 0; p < rows; p++)
        {
            for(int q = 0; q < columns; q++)
            {
                DynamicMatrix mat = minor_matrix(p, q);
                double sign = ((p + q) % 2 == 0) ? 1.0 : -1.0;
                coffient.ptr[p][q] = sign * mat.finding_determinant();
            }
        }
        DynamicMatrix adjustent = coffient.transpose_of_matrix();
        DynamicMatrix inverseMatrix(rows, columns);
        for(int p = 0; p < rows; p++)
            for(int q = 0; q < columns; q++)
                inverseMatrix.ptr[p][q] = adjustent.ptr[p][q] / determinant;
        return inverseMatrix;
    }
        
    //helper function
    void swap_rows(int row1, int row2)
    {
        double* tempRow = ptr[row1];
        ptr[row1] = ptr[row2];
        ptr[row2] = tempRow;
    }
    
    //function to convert to upper triangle
    void converting_to_upper_triangle()
    {
        int n = (rows < columns) ? rows : columns;
        for(int r = 0; r < n - 1; r++)
        {
            if(ptr[r][r] == 0.0)
            {
                int swapRow = -1;
                for(int k = r + 1; k < rows; k++)
                {
                    if(ptr[k][r] != 0.0)
                    {
                        swapRow = k;
                        break;
                    }
                }
                if(swapRow != -1)
                    swap_rows(r, swapRow);
                else
                    continue;
            }
            for(int p = r + 1; p < rows; p++)
            {
                double factor = ptr[p][r] / ptr[r][r];
                for(int q = r; q < columns; q++)
                    ptr[p][q] = ptr[p][q] - factor * ptr[r][q];
            }
        }
    }
    
    //function to convert to lower triangle
    void converting_to_lower_triangle()
    {
        int n = (rows < columns) ? rows : columns;
        
        for(int r = n - 1; r > 0; r--)
        {
            if(ptr[r][r] == 0.0)
            {
                int swapRow = -1;
                for(int k = r - 1; k >= 0; k--)
                {
                    if(ptr[k][r] != 0.0)
                    {
                        swapRow = k;
                        break;
                    }
                }
                if(swapRow != -1)
                    swap_rows(r, swapRow);
                else
                    continue;
            }
            for(int p = r - 1; p >= 0; p--)
            {
                double factor = ptr[p][r] / ptr[r][r];
                for(int q = columns - 1; q >= 0; q--)
                    ptr[p][q] = ptr[p][q] - factor * ptr[r][q];
            }
        }
    }
    
    //stream for <<
    friend ostream& operator<<(ostream& out, const DynamicMatrix& matrix)
    {
        for(int p = 0; p < matrix.rows; p++)
        {
            for(int q = 0; q < matrix.columns; q++)
            {
                out << matrix.ptr[p][q];
                if(q != matrix.columns - 1)
                    out << " ";
            }
            if(p != matrix.rows - 1)
                out << endl;
        }
        return out;
    }


    //stream for >>
    friend istream& operator>>(istream& in, DynamicMatrix& matrix)
    {
        for(int p = 0; p < matrix.rows; p++)
            for(int q = 0; q < matrix.columns; q++)
                in >> matrix.ptr[p][q];
        return in;
    }
    
};

void operator_menu()
{
    cout << "=====MENU=====" << endl;
    cout << " 1. copy operator" << endl;
    cout << " 2. matrix addition" << endl;
    cout << " 3. matrix subtraction" << endl;
    cout << " 4. matrix multiplication" << endl;
    cout << " 5. scalar multiplication" << endl;
    cout << " 6. scalar division" << endl;
    cout << " 7. unary minus" << endl;
    cout << " 8. is equal or not" << endl;
    cout << " 9. increment operator" << endl;
    cout << "10. decrement operator" << endl;
    cout << " 0. to exit" << endl;
    cout << "enter your choice : ";
}

int operator_function()
{
    int choice;
    do{
        operator_menu();
        cin >> choice;
        if(choice == 1)
        {
            int rows, columns;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows >> columns;
            DynamicMatrix mat1(rows, columns);
            cout << "enter matrix one : ";
            cin >> mat1;
            DynamicMatrix matCopy = mat1;
            cout << "matrix copy" << endl;
            cout << matCopy;
            cout << endl;
        }
        else if(choice == 2)
        {
            int rows1, columns1;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows1 >> columns1;
            DynamicMatrix mat1(rows1, columns1);
            cout << "enter matrix one : ";
            cin >> mat1;
            int rows2, columns2;
            cout << "enter number of rows and columns in matrix 2 : ";
            cin >> rows2 >> columns2;
            DynamicMatrix mat2(rows2, columns2);
            cout << "enter matrix two : ";
            cin >> mat2;
            DynamicMatrix matrixSum = mat1 + mat2;
            cout << matrixSum;
            cout << endl;
        }
        else if(choice == 3)
        {
            int rows1, columns1;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows1 >> columns1;
            DynamicMatrix mat1(rows1, columns1);
            cout << "enter matrix one : ";
            cin >> mat1;
            int rows2, columns2;
            cout << "enter number of rows and columns in matrix 2 : ";
            cin >> rows2 >> columns2;
            DynamicMatrix mat2(rows2, columns2);
            cout << "enter matrix two : ";
            cin >> mat2;
            DynamicMatrix matrixDiff = mat1 - mat2;
            cout << matrixDiff;
            cout << endl;
        }
        else if(choice == 4)
        {
            int rows1, columns1;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows1 >> columns1;
            DynamicMatrix mat1(rows1, columns1);
            cout << "enter matrix one : ";
            cin >> mat1;
            int rows2, columns2;
            cout << "enter number of rows and columns in matrix 2 : ";
            cin >> rows2 >> columns2;
            DynamicMatrix mat2(rows2, columns2);
            cout << "enter matrix two : ";
            cin >> mat2;
            DynamicMatrix matrixProd = mat1 * mat2;
            cout << matrixProd;
            cout << endl;
        }
        else if(choice == 5)
        {
            int rows1, columns1;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows1 >> columns1;
            DynamicMatrix mat1(rows1, columns1);
            cout << "enter matrix one : ";
            cin >> mat1;
            int scalar;
            cout << "enter scalar : ";
            cin >> scalar;
            DynamicMatrix matrixProd = mat1 * scalar;
            cout << matrixProd;
            cout << endl;
        }
        else if(choice == 6)
        {
            int rows1, columns1;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows1 >> columns1;
            DynamicMatrix mat1(rows1, columns1);
            cout << "enter matrix one : ";
            cin >> mat1;
            int scalar;
            cout << "enter scalar : ";
            cin >> scalar;
            DynamicMatrix matrixDiv = mat1 / scalar;
            cout << matrixDiv;
            cout << endl;
        }
        else if(choice == 7)
        {
            int rows1, columns1;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows1 >> columns1;
            DynamicMatrix mat1(rows1, columns1);
            cout << "enter matrix one : ";
            cin >> mat1;
            DynamicMatrix matrixMin = -mat1;
            cout << matrixMin;
            cout << endl;
        }
        else if(choice == 8)
        {
            int rows1, columns1;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows1 >> columns1;
            DynamicMatrix mat1(rows1, columns1);
            cout << "enter matrix one : ";
            cin >> mat1;
            int rows2, columns2;
            cout << "enter number of rows and columns in matrix 2 : ";
            cin >> rows2 >> columns2;
            DynamicMatrix mat2(rows2, columns2);
            cout << "enter matrix two : ";
            cin >> mat2;
            if(mat1 == mat2)
                cout << "both matrix are same" << endl;
            else
                cout << "both aint same" << endl;
        }
        else if(choice == 9)
        {
            int ch;
            cout << "enter your choice (1. pre inc, 2. post inc) : ";
            cin >> ch;
            if(ch == 1)
            {
                int rows1, columns1;
                cout << "enter number of rows and columns in matrix 1 : ";
                cin >> rows1 >> columns1;
                DynamicMatrix mat1(rows1, columns1);
                cout << "enter matrix one : ";
                cin >> mat1;
                cout << "pre incremented matrix : " << endl;
                cout << ++mat1 << endl;
            }
            else if(ch == 2)
            {
                int rows1, columns1;
                cout << "enter number of rows and columns in matrix 1 : ";
                cin >> rows1 >> columns1;
                DynamicMatrix mat1(rows1, columns1);
                cout << "enter matrix one : ";
                cin >> mat1;
                DynamicMatrix prevMat = mat1++;
                cout << "matrix before increment : " << endl;
                cout << prevMat << endl;
                cout << "post incremeneted matrix : " << endl;
                cout << mat1 << endl;
            }
            else
                cout << "invalid choice" << endl;
        }
        else if(choice == 10)
        {
            int ch;
            cout << "enter your choice (1. pre dec, 2. post dec) : ";
            cin >> ch;
            if(ch == 1)
            {
                int rows1, columns1;
                cout << "enter number of rows and columns in matrix 1 : ";
                cin >> rows1 >> columns1;
                DynamicMatrix mat1(rows1, columns1);
                cout << "enter matrix one : ";
                cin >> mat1;
                cout << "pre decremented matrix : " << endl;
                cout << --mat1 << endl;
            }
            else if(ch == 2)
            {
                int rows1, columns1;
                cout << "enter number of rows and columns in matrix 1 : ";
                cin >> rows1 >> columns1;
                DynamicMatrix mat1(rows1, columns1);
                cout << "enter matrix one : ";
                cin >> mat1;
                DynamicMatrix prevMat = mat1--;
                cout << "matrix before decrement : " << endl;
                cout << prevMat << endl;
                cout << "post decremeneted matrix : " << endl;
                cout << mat1 << endl;
            }
            else
                cout << "invalid choice" << endl;
        }
        else if(choice == 0)
            cout << "exiting code" << endl;
        else
            cout << "invalid choice" << endl;
    }while(choice != 0);
    return 0;
}

void matrix_add_remove()
{
    cout << "=====MENU=====" << endl;
    cout << "1. add a row" << endl;
    cout << "2. add a column" << endl;
    cout << "3. remove a row" << endl;
    cout << "4. remove a column" << endl;
    cout << "0. to exit" << endl;
    cout << "enter your choice : ";
}

int matrix_add_remove_function()
{
    int choice;
    do{
        matrix_add_remove();
        cin >> choice;
        if(choice == 1)
        {
            int rows1, columns1;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows1 >> columns1;
            DynamicMatrix mat1(rows1, columns1);
            cout << "enter matrix one : ";
            cin >> mat1;
            double* newRows = new double[columns1];
            cout << "enter new row : ";
            for(int p = 0; p < columns1; p++)
                cin >> newRows[p];
            mat1.adding_row(newRows, columns1);
            cout << mat1;
            cout << endl;
            delete[] newRows;
        }
        else if(choice == 2)
        {
            int rows1, columns1;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows1 >> columns1;
            DynamicMatrix mat1(rows1, columns1);
            cout << "enter matrix one : ";
            cin >> mat1;
            double* newColumns = new double[rows1];
            cout << "enter new column : ";
            for(int p = 0; p < rows1; p++)
                cin >> newColumns[p];
            mat1.adding_column(newColumns, rows1);
            cout << mat1;
            cout << endl;
            delete[] newColumns;
        }
        else if(choice == 3)
        {
            int rows1, columns1;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows1 >> columns1;
            DynamicMatrix mat1(rows1, columns1);
            cout << "enter matrix one : ";
            cin >> mat1;
            int numberOfRow;
            cout << "enter number of row to remove : ";
            cin >> numberOfRow;
            mat1.removing_row(numberOfRow);
            cout << mat1;
            cout << endl;
        }
        else if(choice == 4)
        {
            int rows1, columns1;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows1 >> columns1;
            DynamicMatrix mat1(rows1, columns1);
            cout << "enter matrix one : ";
            cin >> mat1;
            int numberOfColumn;
            cout << "enter number of column to remove : ";
            cin >> numberOfColumn;
            mat1.removing_column(numberOfColumn);
            cout << mat1;
            cout << endl;
        }
        else if(choice == 0)
            cout << "exiting code" << endl;
        else
            cout << "invalid choice" << endl;
    }while(choice != 0);
    return 0;
}

void matrix_function_menu()
{
    cout << "=====MENU=====" << endl;
    cout << " 1. matrix transpose" << endl;
    cout << " 2. double trace" << endl;
    cout << " 3. is square matrix" << endl;
    cout << " 4. is identity matrix" << endl;
    cout << " 5. is symmetric matrix" << endl;
    cout << " 6. finding determinant" << endl;
    cout << " 7. matrix inverse" << endl;
    cout << " 8. matrix minor" << endl;
    cout << " 9. matrix power" << endl;
    cout << "10. matrix identity maker" << endl;
    cout << "11. zero matrix maker" << endl;
    cout << "12. convert to upper matrix" << endl;
    cout << "13. convert to lower matrix" << endl;
    cout << "0. to exit" << endl;
    cout << "enter your choice : ";
}

int matrix_functions()
{
    int choice;
    do{
        matrix_function_menu();
        cin >> choice;
        if(choice == 1)
        {
            int rows, columns;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows >> columns;
            DynamicMatrix mat1(rows, columns);
            cout << "enter matrix one : ";
            cin >> mat1;
            DynamicMatrix matTrans = mat1.transpose_of_matrix();
            cout << "matrix transpose : " << endl;
            cout << matTrans << endl;
        }
        else if(choice == 2)
        {
            int rows, columns;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows >> columns;
            DynamicMatrix mat1(rows, columns);
            cout << "enter matrix one : ";
            cin >> mat1;
            double matTrace = mat1.trace_function();
            cout << "matrix trace : " << endl;
            cout << matTrace << endl;
        }
        else if(choice == 3)
        {
            int rows, columns;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows >> columns;
            DynamicMatrix mat1(rows, columns);
            cout << "enter matrix one : ";
            cin >> mat1;
            bool isSquare = mat1.is_sqaure_matrix();
            if(isSquare == true)
                cout << "it is a square matrix" << endl;
            else
                cout << "it is not a square matrix" << endl;
        }
        else if(choice == 4)
        {
            int rows, columns;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows >> columns;
            DynamicMatrix mat1(rows, columns);
            cout << "enter matrix one : ";
            cin >> mat1;
            bool isIdentity = mat1.is_identity_matrix();
            if(isIdentity == true)
                cout << "it is a identity matrix" << endl;
            else
                cout << "it is not a identity matrix" << endl;
        }
        else if(choice == 5)
        {
            int rows, columns;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows >> columns;
            DynamicMatrix mat1(rows, columns);
            cout << "enter matrix one : ";
            cin >> mat1;
            bool isSymmetric = mat1.is_symmetric_matrix();
            if(isSymmetric == true)
                cout << "it is a symmetric matrix" << endl;
            else
                cout << "it is not a symmetric matrix" << endl;
        }
        else if(choice == 6)
        {
            int rows, columns;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows >> columns;
            DynamicMatrix mat1(rows, columns);
            cout << "enter matrix one : ";
            cin >> mat1;
            double determinantOfMat = mat1.finding_determinant();
            cout << "matrix determinant : " << endl;
            cout << determinantOfMat << endl;
        }
        else if(choice == 7)
        {
            int rows, columns;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows >> columns;
            DynamicMatrix mat1(rows, columns);
            cout << "enter matrix one : ";
            cin >> mat1;
            DynamicMatrix matInv = mat1.inverse_matrix();
            cout << "matrix inverse : " << endl;
            cout << matInv << endl;
        }
        else if(choice == 8)
        {
            int rows, columns;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows >> columns;
            DynamicMatrix mat1(rows, columns);
            cout << "enter matrix one : ";
            cin >> mat1;
            int r, c;
            cout << "enter row and column to remove : ";
            cin >> r >> c;
            DynamicMatrix matMinor = mat1.minor_matrix(r, c);
            cout << "matrix minor : " << endl;
            cout << matMinor << endl;
        }
        else if(choice == 9)
        {
            int rows, columns;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows >> columns;
            DynamicMatrix mat1(rows, columns);
            cout << "enter matrix one : ";
            cin >> mat1;
            int exponent;
            cout << "enter exponent : ";
            cin >> exponent;
            DynamicMatrix matrixPower = mat1.power_matrix(exponent);
            cout << "matrix power : " << endl;
            cout << matrixPower << endl;
        }
        else if(choice == 10)
        {
            int n;
            cout << "enter size n for identity : ";
            cin >> n;
            DynamicMatrix matIdentity = DynamicMatrix::identity_matrix(n);
            cout << "matrix identity : " << endl;
            cout << matIdentity << endl;
        }
        else if(choice == 11)
        {
            int rows, columns;
            cout << "enter rows and columns for zero matrix : ";
            cin >> rows >> columns;
            DynamicMatrix matZero = DynamicMatrix::zero_matrix(rows, columns);
            cout << "matrix zero : " << endl;
            cout << matZero << endl;
        }
        else if(choice == 12)
        {
            int rows1, columns1;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows1 >> columns1;
            DynamicMatrix mat1(rows1, columns1);
            cout << "enter matrix one : ";
            cin >> mat1;
            cout << "matrix after row operation : " << endl;
            mat1.converting_to_upper_triangle();
            cout << mat1;
            cout << endl;
        }
        else if(choice == 13)
        {
            int rows1, columns1;
            cout << "enter number of rows and columns in matrix 1 : ";
            cin >> rows1 >> columns1;
            DynamicMatrix mat1(rows1, columns1);
            cout << "enter matrix one : ";
            cin >> mat1;
            cout << "matrix after row operation : " << endl;
            mat1.converting_to_lower_triangle();
            cout << mat1;
            cout << endl;
        }
        else if(choice == 0)
            cout << "exiting code" << endl;
        else
            cout << "invalid choice" << endl;
    }while(choice != 0);
    return 0;
}

void matrix_menu()
{
    cout << "====MENU====" << endl;
    cout << "1. arthimetic operations & comparison" << endl;
    cout << "2. adding & removing function" << endl;
    cout << "3. matrix functions" << endl;
    cout << "0. to exit" << endl;
    cout << "enter your choice : ";
}

int matrix_class()
{
    int choice;
    do{
        matrix_menu();
        cin >> choice;
        switch(choice)
        {
            case 1: operator_function(); break;
            case 2: matrix_add_remove_function(); break;
            case 3: matrix_functions(); break;
            case 0: cout << "exiting code" << endl; break;
            default: cout << "invalid choice" << endl; break;
        }
    }while(choice != 0);
    return 0;
}


class BigInteger
{
    public :
    int *noOfDigits;
    int size;
    bool isNegative;
    
    //initilizing with zero
    void initilizng_with_zero()
    {
        noOfDigits = new int[1];
        noOfDigits[0] = 0;
        size = 1;
        isNegative = false;
    }
    
    //trim function, removing leading zeros, and keeping at least one digit
    void trimming()
    {
        while(size > 1 && noOfDigits[size - 1] == 0)
            size--;
        if(size == 1 && noOfDigits[0] == 0)
            isNegative = false;
    }
    
    //function for string lenght
    static int string_lenght(const char* string)
    {
        int lenght = 0;
        while(string[lenght] != '\0')
            lenght++;
        return lenght;
    }
    
    //function for comparsion
    static int comparison(const BigInteger& bigA, const BigInteger& bigB)
    {
        if(bigA.size != bigB.size)
            return (bigA.size < bigB.size) ? -1 : 1;
        for(int i = bigA.size - 1; i >= 0; --i)
        {
            if(bigA.noOfDigits[i] != bigB.noOfDigits[i])
                return (bigA.noOfDigits[i] < bigB.noOfDigits[i]) ? -1 : 1;
        }
        return 0;
    }
    
    //function for addition
    static BigInteger addition(const BigInteger& bigA, const BigInteger& bigB)
    {
        int maximumLenght = (bigA.size > bigB.size) ? bigA.size : bigB.size;
        BigInteger bigSum;
        delete[] bigSum.noOfDigits;
        bigSum.noOfDigits = new int[maximumLenght + 1];
        bigSum.size = maximumLenght + 1;
        bigSum.isNegative = false;
        int carry = 0;
        for(int p = 0; p < maximumLenght; p++)
        {
            int digitA = (p < bigA.size) ? bigA.noOfDigits[p] : 0;
            int digitB = (p < bigB.size) ? bigB.noOfDigits[p] : 0;
            int tempSum = digitA + digitB + carry;
            bigSum.noOfDigits[p] = tempSum % 10;
            carry = tempSum / 10;
        }
        bigSum.noOfDigits[maximumLenght] = carry;
        bigSum.trimming();
        return bigSum;
    }
    
    //function for subtraction
    static BigInteger subtraction(const BigInteger& bigA, const BigInteger& bigB)
    {
        BigInteger bigDiffernce;
        delete[] bigDiffernce.noOfDigits;
        bigDiffernce.noOfDigits = new int[bigA.size];
        bigDiffernce.size = bigA.size;
        bigDiffernce.isNegative = false;
        int borrow = 0;
        for(int p = 0; p < bigA.size; p++)
        {
            int digitA = bigA.noOfDigits[p];
            int digitB = (p < bigB.size) ? bigB.noOfDigits[p] : 0;
            int tempDiff = digitA - digitB - borrow;
            if(tempDiff < 0)
            {
                tempDiff = tempDiff + 10;
                borrow = 1;
            }
            else
                borrow = 0;
            bigDiffernce.noOfDigits[p] = tempDiff;
        }
        bigDiffernce.trimming();
        return bigDiffernce;
    }
    
    public :
    //default constructor
    BigInteger()
    {
        noOfDigits = nullptr;
        size = 0;
        isNegative = false;
        initilizng_with_zero();
    }
    
    //conversaion constructor
    BigInteger(const char* string)
    {
        noOfDigits = nullptr;
        size = 0;
        isNegative = false;
        if(!string || string[0] == '\0')
        {
            initilizng_with_zero();
            return;
        }
        int length = string_lenght(string);
        int startingIndex = 0;
        if(string[0] == '-')
        {
            isNegative = true;
            startingIndex = 1;
        }
        else if(string[0] == '+')
            startingIndex = 1;
        while(startingIndex < length && string[startingIndex] == '0')
            startingIndex++;
        if(startingIndex == length)
        {
            initilizng_with_zero();
            return;
        }
        int count = length - startingIndex;
        noOfDigits = new int[count];
        size = count;
        for(int p = 0; p < size; p++)
        {
            char character = string[length - 1 - p];
            if(character < '0' || character > '9')
            {
                delete[] noOfDigits;
                initilizng_with_zero();
                return;
            }
            noOfDigits[p] = character - '0';
        }
        trimming();
    }
    
    //long long constructor
    BigInteger(long long value)
    {
        noOfDigits = nullptr;
        size = 0;
        isNegative = false;
        if(value == 0)
        {
            initilizng_with_zero();
            return;
        }
        if(value < 0)
        {
            isNegative = true;
            value = -value;
        }
        long long temp = value;
        int count = 0;
        while(temp > 0)
        {
            count++;
            temp = temp / 10;
        }
        noOfDigits = new int[count];
        size = count;
        for(int p = 0; p < size; p++)
        {
            noOfDigits[p] = (int)(value % 10);
            value = value / 10;
        }
        trimming();
    }
    
    //copy constructor
    BigInteger(const BigInteger& other)
    {
        noOfDigits = nullptr;
        size = other.size;
        isNegative = other.isNegative;
        noOfDigits = new int[size];
        for(int p = 0; p < size; p++)
            noOfDigits[p] = other.noOfDigits[p];
    }
    
    //destructor
    ~BigInteger()
    {
        delete[] noOfDigits;
    }
    
    //assignment operator
    BigInteger &operator=(const BigInteger& other)
    {
        if(this == &other)
            return *this;
        delete[] noOfDigits;
        size = other.size;
        isNegative = other.isNegative;
        noOfDigits = new int[size];
        for(int p = 0; p < size; p++)
            noOfDigits[p] = other.noOfDigits[p];
        return *this;
    }
    
    //comparsion operator
    bool operator==(const BigInteger& other) const
    {
        if(isNegative != other.isNegative || size != other.size)
            return false;
        for(int p = 0; p < size; p++)
            if(noOfDigits[p] != other.noOfDigits[p])
                return false;
        return true;
    }
    
    bool operator<(const BigInteger& other) const
    {
        if(isNegative != other.isNegative)
            return isNegative;
        int cmp = comparison(*this, other);
        if(isNegative == false)
            return cmp < 0;
        return cmp > 0;
    }
    
    //function for addition
    BigInteger operator+(const BigInteger& other) const
    {
        if(isNegative == other.isNegative)
        {
            BigInteger bigSum = addition(*this, other);
            bigSum.isNegative = isNegative;
            bigSum.trimming();
            return bigSum;
        }
        int cmp = comparison(*this, other);
        if(cmp == 0)
            return BigInteger();
        if(cmp > 0)
        {
            BigInteger bigSum = subtraction(*this, other);
            bigSum.isNegative = isNegative;
            bigSum.trimming();
            return bigSum;
        }
        else
        {
            BigInteger bigSum = subtraction(other, *this);
            bigSum.isNegative = other.isNegative;
            bigSum.trimming();
            return bigSum;
        }
    }

    //function for subtraction
    BigInteger operator-(const BigInteger& other) const
    {
        BigInteger negativeB(other);
        if(!(negativeB.size == 1 && negativeB.noOfDigits[0] == 0))
        {
            negativeB.isNegative = !other.isNegative;
        }
        return *this + negativeB;
    }

    //output function
    friend ostream& operator<<(ostream& out, const BigInteger& bigInt)
    {
        if(bigInt.isNegative)
            out << '-';
        for(int p = bigInt.size - 1; p >= 0; --p)
            out << bigInt.noOfDigits[p];
        return out;
    }

    //input function
    friend istream& operator>>(istream& in, BigInteger& bigInt)
    {
        char buffer[2000];
        in >> buffer;
        bigInt = BigInteger(buffer);
        return in;
    }
};

void big_integer_menu()
{
    cout << "===MENU===" << endl;
    cout << "1. addition (A + B)" << endl;
    cout << "2. subtraction(A - B)" << endl;
    cout << "3. copy of big int" << endl;
    cout << "4. comparison" << endl;
    cout << "0. to exit" << endl;
    cout << "enter your choice : ";
}

int big_integer_class()
{
    int choice;
    do{
        big_integer_menu();
        cin >> choice;
        if(choice == 1)
        {
            BigInteger bigIntA, bigIntB;
            cout << "enter big integer A : ";
            cin >> bigIntA;
            cout << "enter big integar B : ";
            cin >> bigIntB;
            BigInteger bigIntSum = bigIntA + bigIntB;
            cout << "sum of big int (A + B) : " << bigIntSum << endl;
        }
        else if(choice == 2)
        {
            BigInteger bigIntA, bigIntB;
            cout << "enter big integer A : ";
            cin >> bigIntA;
            cout << "enter big integar B : ";
            cin >> bigIntB;
            BigInteger bigIntDiff = bigIntA - bigIntB;
            cout << "differnce of big int (A - B) : " << bigIntDiff << endl;
        }
        else if(choice == 3)
        {
            BigInteger bigIntA, bigIntCopy;
            cout << "enter big integer A : ";
            cin >> bigIntA;
            bigIntCopy = bigIntA;
            cout << "copy of big int A : " << bigIntCopy << endl;
        }
        else if(choice == 4)
        {
            BigInteger bigIntA, bigIntB;
            cout << "enter big integer A : ";
            cin >> bigIntA;
            cout << "enter big integar B : ";
            cin >> bigIntB;
            if(bigIntA == bigIntB)
                cout << "both big integer are same" << endl;
            else
                cout << "both aint same" << endl;
            if(bigIntA < bigIntB)
                cout << "big integer A is less then big integer B" << endl;
            else if(bigIntB < bigIntA)
                cout << "big integer B is less then big integer A" << endl;
        }
        else if(choice == 0)
            cout << "exiting code" << endl;
        else
            cout << "invalid choice" << endl;
    }while(choice != 0);
    return 0;
}

void main_menu()
{
    cout << "===SCIENTIFIC CALCULATOR===" << endl;
    cout << "1. fraction function " << endl;
    cout << "2. complex number function" << endl;
    cout << "3. polynomial function" << endl;
    cout << "4. sets function" << endl;
    cout << "5. matrix function" << endl;
    cout << "6. big integer funcxtion" << endl;
    cout << "0. to exit" << endl;
    cout << "enter your choice : ";
}

int main()
{
    int choice;
    do{
        main_menu();
        cin >> choice;
        switch(choice)
        {
            case 1: fraction_class(); break;
            case 2: complex_class(); break;
            case 3: polynomial_class(); break;
            case 4: set_class(); break;
            case 5: matrix_class(); break;
            case 6: big_integer_class(); break;
            case 0: cout << "exiting code...." << endl; break;
            default: cout << "invalid choice" << endl; break;
        }
    }while(choice != 0);
    return 0;
}
