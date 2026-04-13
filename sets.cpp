#include <iostream>
using namespace std;

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

void menu()
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

int main()
{
    int choice;
    do{
        menu();
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

