#include<iostream>


template <typename T>
T square(const T& value) {
    return value * value;
}

template <typename T>
void print(const T& value ) {
    
    std::cout << value << std::endl;
}

template <typename T, size_t N>
void square_array(T (&arr)[N]) {

    for (size_t i = 0; i < N; ++i) {
        arr[i] = square(arr[i]);
    }
}

template <typename T, size_t N>
void print_array(const T (&arr)[N]) {
    for (size_t i = 0; i < N; ++i) {
        std::cout << arr[i];
        if (i != N - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

int main() {
  
    int value = 4;
    std::cout << "[IN]: ";
    print(value);

    value = square(value);
    std::cout << "[OUT]: ";
    print(value);


    int numbers[] = {-1, 4, 8};
    std::cout << "[IN]: ";
    print_array(numbers);

    square_array(numbers);
    std::cout << "[OUT]: ";
    print_array(numbers);

    return 0;
}