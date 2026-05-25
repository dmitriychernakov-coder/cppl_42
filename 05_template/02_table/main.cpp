#include<iostream>

struct TableSize {
    size_t rows;
    size_t cols;
};


template <typename T>
class ConstRow {

   const T* __data;

public:
    ConstRow(const T* data) : __data(data) {}

    const T& operator[](size_t col) const {
        return __data[col];
    }
};

template <typename T>
class Row {

   T* __data;

public:
    Row(T* data) : __data(data) {}

    T& operator[](size_t col) {
        return __data[col];
    }

    const T& operator[](size_t col) const {
        return __data[col];
    }
};



template <typename T>
class Table {

    T* __data;
    size_t __row;
    size_t __col;

public:



    Table(size_t row, size_t column) : __row(row), __col(column) {

        __data = new T[row * column];
        

        for (size_t i = 0; i < row * column; ++i) {
            __data[i] = T();
        }
    }

    ~Table() {
        delete[] __data;
        __data = nullptr;
    }



    Row<T> operator[](size_t row) {

        return Row<T>(&__data[row * __col]);
    }

    ConstRow<T> operator[](size_t row) const {
        return ConstRow<T>(const_cast<T*>(&__data[row * __col]));
    }

    TableSize Size() const {
        return {__row, __col};
    }
};

int main() {
 
  
    auto test = Table<int>(2,3);
    test[0][0] = 4;
    std::cout << test[0][0] << std::endl;
    TableSize size_table = test.Size();
    std::cout << "Rows: " << size_table.rows << ", Columns: " << size_table.cols << std::endl;
    return 0;
}