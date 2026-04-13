#include <iostream>
using namespace std;

class DynamicMatrix
{
    private :
    int **ptr;
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
        ptr = new int*[rows];
        for(int p = 0; p < rows; p++)
        {
            ptr[p] = new int[columns];
            for(int q = 0; q < columns; q++)
                ptr[p][q] = 0;
        }
    }
    
    //function to delete dynamic memory
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
    DynamicMatrix operator+(const DynamicMatrix& matrix)
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
    DynamicMatrix operator-(const DynamicMatrix& matrix)
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
    DynamicMatrix operator*(const DynamicMatrix& matrix)
    {
        if(columns != matrix.rows)
            return DynamicMatrix();
        DynamicMatrix matrixProduct(rows, matrix.columns);
        for(int p = 0; p < rows; p++)
        {
            for(int q = 0; q < matrix.columns; q++)
            {
                int sum = 0;
                for(int r = 0; r < columns; r++)
                    sum = sum + ptr[p][r] * matrix.ptr[r][q];
                matrixProduct.ptr[p][q] = sum;
            }
        }
        return matrixProduct;
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
    
    //friend functions for +
    friend DynamicMatrix operator+(int scalar, const DynamicMatrix& matrix)
    {
        DynamicMatrix matrixSum(matrix.rows, matrix.columns);
        for(int p = 0; p < matrix.rows; p++)
            for(int q = 0; q < matrix.columns; q++)
                matrixSum.ptr[p][q] = scalar + matrix.ptr[p][q];
        return matrixSum;
    }

    friend DynamicMatrix operator+(const DynamicMatrix& matrix, int scalar)
    {
        DynamicMatrix matrixSum(matrix.rows, matrix.columns);
        for(int p = 0; p < matrix.rows; p++)
            for(int q = 0; q < matrix.columns; q++)
                matrixSum.ptr[p][q] =  matrix.ptr[p][q] + scalar;
        return matrixSum;
    }
    
    //friend function for *
    friend DynamicMatrix operator*(int scalar, const DynamicMatrix& matrix)
    {
        DynamicMatrix matrixProduct(matrix.rows, matrix.columns);
        for(int p = 0; p < matrix.rows; p++)
            for(int q = 0; q < matrix.columns; q++)
                matrixProduct.ptr[p][q] = scalar * matrix.ptr[p][q];
        return matrixProduct;
    }
    friend DynamicMatrix operator*(const DynamicMatrix& matrix, int scalar)
    {
        return scalar * matrix;
    }
    
    //friend function for /
    friend DynamicMatrix operator/(const DynamicMatrix& matrix, int scalar)
    {
        if(scalar == 0)
            return DynamicMatrix();
        DynamicMatrix matrixDiv(matrix.rows, matrix.columns);
        for(int p = 0; p < matrix.rows; p++)
            for(int q = 0; q < matrix.columns; q++)
                matrixDiv.ptr[p][q] = matrix.ptr[p][q] / scalar;
        return matrixDiv;
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

void menu()
{
    cout << "===MENU===" << endl;
    cout << "1. copying first matrix" << endl;
    cout << "2. sum of matrix" << endl;
    cout << "3. differnce of matrix" << endl;
    cout << "4. product of matrix" << endl;
    cout << "5. compare two matrix" << endl;
    cout << "6. scalar addition" << endl;
    cout << "7. scalar product" << endl;
    cout << "8. scalar division" << endl;
    cout << "0. to exit" << endl;
    cout << "enter your choice : " << endl;
}
int main()
{
    int choice;
    do{
        menu();
        cin >> choice;
        if(choice == 1)
        {
            int rowsA, columnsA;
            cout << "enter rows and columns of matrix A : ";
            cin >> rowsA >> columnsA;
            DynamicMatrix matrixA(rowsA, columnsA);
            cout << "enter matrix A : " << endl;
            cin >> matrixA;
            cout << "copy of matrix A" << endl;
            DynamicMatrix matrixCopy(rowsA, columnsA);
            matrixCopy = matrixA;
            cout << matrixCopy << endl;
        }
        else if(choice == 2)
        {
            int rowsA, columnsA;
            cout << "enter rows and columns of matrix A : ";
            cin >> rowsA >> columnsA;
            DynamicMatrix matrixA(rowsA, columnsA);
            cout << "enter matrix A : " << endl;
            cin >> matrixA;
            int rowsB, columnsB;
            cout << "enter rows and columns of matrix B : ";
            cin >> rowsB >> columnsB;
            DynamicMatrix matrixB(rowsB, columnsB);
            cout << "enter matrix B : " << endl;
            cin >> matrixB;
            cout << "sum of A and B" << endl;
            DynamicMatrix matrixSum(rowsA, columnsA);
            matrixSum = matrixA + matrixB;
            cout << matrixSum << endl;
        }
        else if(choice == 3)
        {
            int rowsA, columnsA;
            cout << "enter rows and columns of matrix A : ";
            cin >> rowsA >> columnsA;
            DynamicMatrix matrixA(rowsA, columnsA);
            cout << "enter matrix A : " << endl;
            cin >> matrixA;
            int rowsB, columnsB;
            cout << "enter rows and columns of matrix B : ";
            cin >> rowsB >> columnsB;
            DynamicMatrix matrixB(rowsB, columnsB);
            cout << "enter matrix B : " << endl;
            cin >> matrixB;
            cout << "differnce of A and B" << endl;
            DynamicMatrix matrixDiff(rowsA, columnsA);
            matrixDiff = matrixA - matrixB;
            cout << matrixDiff << endl;
        }
        else if(choice == 4)
        {
            int rowsA, columnsA;
            cout << "enter rows and columns of matrix A : ";
            cin >> rowsA >> columnsA;
            DynamicMatrix matrixA(rowsA, columnsA);
            cout << "enter matrix A : " << endl;
            cin >> matrixA;
            int rowsB, columnsB;
            cout << "enter rows and columns of matrix B : ";
            cin >> rowsB >> columnsB;
            DynamicMatrix matrixB(rowsB, columnsB);
            cout << "enter matrix B : " << endl;
            cin >> matrixB;
            cout << "product of A and B" << endl;
            DynamicMatrix matrixProduct(rowsA, columnsB);
            matrixProduct = matrixA * matrixB;
            cout << matrixProduct << endl;
        }
        else if(choice == 5)
        {
            int rowsA, columnsA;
            cout << "enter rows and columns of matrix A : ";
            cin >> rowsA >> columnsA;
            DynamicMatrix matrixA(rowsA, columnsA);
            cout << "enter matrix A : " << endl;
            cin >> matrixA;
            int rowsB, columnsB;
            cout << "enter rows and columns of matrix B : ";
            cin >> rowsB >> columnsB;
            DynamicMatrix matrixB(rowsB, columnsB);
            cout << "enter matrix B : " << endl;
            cin >> matrixB;
            cout << "comparison of matrix" << endl;
            if(matrixA == matrixB)
                cout << "matrix is same" << endl;
            else
                cout << "matrix aint same" << endl;
        }
        else if(choice == 6)
        {
            int rowsA, columnsA;
            cout << "enter rows and columns of matrix : ";
            cin >> rowsA >> columnsA;
            DynamicMatrix matrix(rowsA, columnsA);
            cout << "enter matrix : " << endl;
            cin >> matrix;
            int choice1;
            cout << "post or pre addition scalar (1. post, 2. pre) : ";
            cin >> choice1;
            if(choice1 == 1)
            {
                int scalar;
                cout << "enter scalar : ";
                cin >> scalar;
                DynamicMatrix postAdd = matrix + scalar;
                cout << postAdd << endl;
            }
            else if(choice1 == 2)
            {
                int scalar;
                cout << "enter scalar : ";
                cin >> scalar;
                DynamicMatrix preAdd = scalar + matrix;
                cout << preAdd << endl;
            }
            else
                cout << "invalid choice" << endl;
        }
        else if(choice == 7)
        {
            int rowsA, columnsA;
            cout << "enter rows and columns of matrix : ";
            cin >> rowsA >> columnsA;
            DynamicMatrix matrix(rowsA, columnsA);
            cout << "enter matrix : " << endl;
            cin >> matrix;
            int scalar;
            cout << "enter scalar for product : ";
            cin >> scalar;
            DynamicMatrix productM = matrix * scalar;
            cout << productM << endl;
        }
        else if(choice == 8)
        {
            int rowsA, columnsA;
            cout << "enter rows and columns of matrix : ";
            cin >> rowsA >> columnsA;
            DynamicMatrix matrix(rowsA, columnsA);
            cout << "enter matrix : " << endl;
            cin >> matrix;
            int scalar;
            cout << "enter scalar for product : ";
            cin >> scalar;
            DynamicMatrix matrixDiv = matrix / scalar;
            cout << matrixDiv << endl;
        }
        else if(choice == 0)
            cout << "exiting..." << endl;
        else
            cout << "invalid choice" << endl;
    }while(choice != 0);
    
    return 0;
}
