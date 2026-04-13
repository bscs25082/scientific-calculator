#include <iostream>
using namespace std;

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
            bool hasX = (newDegree != 0);
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
        for(int p = 0; p < poly.size; p++)
            in >> poly.coeffs[p] >> poly.powers[p];
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
void main_menu()
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

int main()
{
    int choice;
    Polynomial poly1, poly2;
    cout << "enter polynomial 1 : ";
    cin >> poly1;
    cout << "enter polynomial 2 : ";
    cin >> poly2;
    do{
        main_menu();
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
