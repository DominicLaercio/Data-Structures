#include "array.cpp"

#include <iostream>
using namespace std;

int main(){

    // Testing my array implementation.
    int arraySize = 5;
    Array<int> intArray(arraySize);

    for(int i = 0; i < 5; i++){
        intArray.set(i, i *2);
    }

    for(int i = 0; i < intArray.getSize(); i++){
        cout << "Value at position " << i << ": " << intArray.get(i) << "\n";
    }

    return 0;
}
