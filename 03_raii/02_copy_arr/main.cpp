#include <iostream>
#include <stdexcept>

class SmartArray {
    int* alloc;
    int volume;
    int size;

    void copy_arr(SmartArray& other) {
        alloc = new int[other.volume];
        for (size_t i = 0; i < other.size; i++)
        {
            /* code */
            alloc[i] = other.alloc[i];

        }
        volume = other.volume;
        size = other.size;
        

    }

public:
    SmartArray(int start_volume) : 
        alloc(new int[start_volume]),
        volume(start_volume),
        size(0) 
        {

        }

    ~SmartArray() {
        delete[] alloc;
    }


    SmartArray(SmartArray& other) {
        copy_arr(other);
    }

    SmartArray& operator = (SmartArray& other) {
        if (this == &other) 
        {
            /* code */
            return *this;
        }
        delete[] alloc;
        copy_arr(other);
        return *this;
    }

    void add_element(int element) {
        if(size >= volume) {
            int new_volume = volume == 0 ? 1 : volume * 2;
            int* new_alloc = new int[new_volume];
            for (size_t i = 0; i < size; i++)
            {
                new_alloc[i] = alloc[i];
            }
            delete[] alloc;
            alloc = new_alloc;
            volume = new_volume;
        }
        alloc[size] = element;
        size++;
    }

    int get_element(int index) {
        if(index >= size || index < 0) {
            throw std::out_of_range("Out of range of array");
        }
        return alloc[index];
    }


};

int main(int argc, char** argv) {
    try {

        // SmartArray arr(5);
        // arr.add_element(1);
        // arr.add_element(4);
        // arr.add_element(155);
        // arr.add_element(14);
        // arr.add_element(15);
        // std::cout << arr.get_element(1) << std::endl; 
        //std::cout << arr.get_element(15) << std::endl;

        SmartArray arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
       
        std::cout << arr.get_element(1) << std::endl; 
        
        SmartArray new_array(2);
        new_array.add_element(44); 
        new_array.add_element(34);

        //std::cout << new_array.get_element(1) << std::endl; 

        arr = new_array;

        std::cout << arr.get_element(1) << std::endl; 
        //std::cout << arr.get_element(15) << std::endl;
        //std::cout << arr.get_element(-1) << std::endl; 
    }
    
    catch(std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
