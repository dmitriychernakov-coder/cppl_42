#include<iostream>

class simple_functor {
    int __sum{0};
    int __count{0};

public:
  
    void operator()(int num) {
        if (num % 3 == 0) {
            __sum += num;
            ++__count;
        }
    }

    int get_sum() const {
        return __sum;
    }

    int get_count() const {
        return __count;
    }
};

template <typename T, size_t N>
void print_array(const T (&arr)[N]) {
    for (size_t i = 0; i < N; ++i) {
        std::cout << arr[i];
        if (i != N - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main() {

    simple_functor sf;

    int numbers[] = {4, 1, 3, 6, 25, 54};
    std::cout << "[IN]: ";
    print_array(numbers);
    size_t size = sizeof(numbers) / sizeof(numbers[0]);
    for (size_t i = 0; i < size; ++i) {
        sf(numbers[i]);
    }

    std::cout << "[OUT]: get_sum() =  " << sf.get_sum() << std::endl;
    std::cout << "[OUT]: get_count() = " << sf.get_count() << std::endl;

    return 0;
}


