#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;      
    int size;       
    int capacity;   
   
    void resize(int newCapacity) {
        int* newData = new int[newCapacity];

        
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }

        delete[] data; 

        data = newData;
        capacity = newCapacity;
    }

public:
    
    DynamicArray() {
        capacity = 2;
        size = 0;
        data = new int[capacity];
    }

    
    ~DynamicArray() {
        delete[] data;
    }

    
    void push_back(int value) {
        if (size == capacity) {
            resize(capacity * 2);
        }

        data[size] = value;
        size++;
    }

    
    void pop_back() {
        if (size > 0) {
            size--;
        }
    }

    
    int at(int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of range!\n";
            return -1;
        }

        return data[index];
    }

    
    void print() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

   
    int getSize() {
        return size;
    }
};

int main() {
    DynamicArray arr;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);

    cout << "Mang sau push_back: ";
    arr.print();

    cout << "Phan tu tai index 2: ";
    cout << arr.at(2) << endl;

    arr.pop_back();

    cout << "Mang sau pop_back: ";
    arr.print();

    return 0;
}