#pragma once
#ifndef PB_VECTOR
#define PB_VECTOR

#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

namespace PB_C {
    template<typename T>
    class Vector {
    private:
        int size;
        T* data;

    public:
        Vector();
        explicit Vector(int size);
        Vector(const std::initializer_list<T>& array);
        Vector(const Vector& other);
        ~Vector();

        T* begin() const;
        T* end() const;

        Vector& operator=(const Vector& other);
        T& operator[](const int& index);
        const T& operator[](const int& index) const;

        Vector& operator+(const T& k);
        Vector& operator+(const Vector& vec);

        Vector& operator-(const T& k);
        Vector& operator-(const Vector& vec);

        Vector& operator*(const T& k);
        Vector& operator*(const Vector& vec);

        Vector& operator+=(const T& k);
        Vector& operator+=(const Vector& vec);

        Vector& operator-=(const int& k);
        Vector& operator-=(const Vector& vec);

        Vector& operator*=(const int& k);
        Vector& operator*=(const Vector& vec);

        bool operator==(const Vector& vec) const;
        bool operator!=(const Vector& vec) const;

        int length() const;

        template<typename T>
        friend std::ostream& operator<<(std::ostream& os, const Vector<T>& vec);
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
        os << "[ ";
        for (int i = 0; i < vec.length(); ++i) {
            os << vec[i] << " ";
        }
        os << "]";
        return os;
    }
}

#endif // !PB_VECTOR
