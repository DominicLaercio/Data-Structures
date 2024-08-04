#include "array.cpp"
#include "list.cpp"

#include <iostream>
using namespace std;

void testArray(){
    int arraySize = 5;
    Array<int> intArray(arraySize);

    for(int i = 0; i < 5; i++){
        intArray.set(i, i *2);
    }

    for(int i = 0; i < intArray.getSize(); i++){
        cout << "Value at position " << i << ": " << intArray.get(i) << "\n";
    }
}

void testList(){
    List<char> charList;

    charList.insert('L');
    charList.insert('i');
    charList.insert('s');
    charList.insert('t');
    charList.insert(' ');
    charList.insert('t');
    charList.insert('e');
    charList.insert('s');
    charList.insert('t');

    for(int i = 0; i < charList.getSize(); i++){
        cout << "Value at position " << i << ": " << charList.get(i) << "\n";
    }

    charList.pop();
    charList.remove(0);

    for(int i = 0; i < charList.getSize(); i++){
        cout << "Value at position " << i << ": " << charList.get(i) << "\n";
    }
}

int main(){

    testList();
    

    return 0;
}
