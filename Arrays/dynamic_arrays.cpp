#include <bits\stdc++.h>
using namespace std;

class MyVector
{
private:
    int *data;
    int sz;
    int cap;

    void resize()
    {
        cap *= 2;
        int *newArray = new int[cap];
        for (int i = 0; i < sz; ++i)
        {
            newArray[i] = data[i];
        }
        delete[] data;
        data = newArray;
    }

public:
    MyVector()
    {
        sz = 0;
        cap = 1;
        data = new int[cap];
    }

    ~MyVector()
    {
        delete[] data;
    }
    void push_back(int val)
    {
        if (sz == cap)
        {
            resize();
        }
        data[sz++] = val;
    }
    int size() const
    {
        return sz;
    }
    int capacity() const
    {
        return cap;
    }
    int operator[](int index) const
    {
        if (index < 0 || index >= sz)
        {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }
    void print() const
    {
        for (int i = 0; i < sz; ++i)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    MyVector vec;

    for (int i = 1; i <= 10; ++i)
    {
        vec.push_back(i);
        cout << "Inserted: " << i<< " | Size: " << vec.size()<< " | Capacity: " << vec.capacity() << endl;
    }

    cout << "\nElements in vector: ";
    vec.print();

    cout << "Element at index 3: " << vec[3] << endl;

    return 0;
}