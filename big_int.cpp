#include <iostream>
using namespace std;

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
    BigInteger operator=(const BigInteger& other)
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
            return BigInteger(0);
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

void menu()
{
    cout << "===MENU===" << endl;
    cout << "1. addition (A + B)" << endl;
    cout << "2. subtraction(A - B)" << endl;
    cout << "3. copy of big int" << endl;
    cout << "4. comparison" << endl;
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
