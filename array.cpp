#include <iostream>
using namespace std;

template<class T>
class Array{
    private:
        int size;
        T* arrayAdrress;

    public:
        Array(int iSize){
            size = iSize;
            arrayAdrress = (T*) malloc(size * sizeof(T));
        }
        ~Array(){
            free(arrayAdrress);
        }

        void set(int position, T value){
            if(position >= 0 && position < size){
                *(arrayAdrress +position) = value;
            }
            else{
                cout << "ERROR: Position tried to be written is out of array bounds.\n";
                exit(0);
            }
        }

        T get(int position){
            if(position >= 0 && position < size){
                return *(arrayAdrress +position);
            }
            else{
                cout << "ERROR: Position tried to be read is out of array bounds.\n";
                exit(0);
            }
        }

        int getSize(){
            return size;
        }
};
