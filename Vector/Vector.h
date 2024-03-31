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
		Vector() : size(0), data(nullptr) {}

		explicit Vector(int size) : size(size) {
			data = new T[size];
			for (int i = 0; i < size; ++i)
				data[i] = T();
		}

		Vector(const std::initializer_list<T>& array) : size(array.size()) {
			data = new T[size];
			std::copy(array.begin(), array.end(), data);
		}

		Vector(const Vector& other) : size(other.size);


		T* begin() const;
		T* end() const;

		Vector& operator=(const Vector& other);

		T& operator[](const int& index) const;

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

		bool operator==(const Vector& vec);
		bool operator!=(const Vector& vec);

		int lenght() const;

		friend std::ostream& operator<<(std::ostream& os, const Vector& vec);


		~Vector();
	};
}
#endif // !PB_VECTOR
