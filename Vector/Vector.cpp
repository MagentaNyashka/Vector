#include "vector.h"


namespace PB_C {

	template<typename T>
	Vector<T>::Vector() : size(0), data(nullptr) {}

	template<typename T>
	Vector<T>::Vector(int size) : size(size) {
		data = new T[size];
		for (int i = 0; i < size; ++i)
			data[i] = T();
	}

	template<typename T>
	Vector<T>::Vector(const std::initializer_list<T>& array) : size(array.size()) {
		data = new T[size];
		std::copy(array.begin(), array.end(), data);
	}

	template<typename T>
	Vector<T>::Vector(const Vector& other) : size(other.size) {
		data = new T[size];
		std::copy_n(other.data, size, data);
	}

	template<typename T>
	Vector<T>::~Vector() {
		delete[] data;
	}

	template<typename T>
	T* Vector<T>::begin() const {
		return data;
	}
	template<typename T>
	T* Vector<T>::end() const {
		return data + size;
	}

	template<typename T>
	int Vector<T>::length() const {
		return size;
	}


	template<typename T>
	Vector<T>& Vector<T>::operator=(const Vector& other) {
		if (this != &other) {
			delete[] data;
			size = other.size;
			data = new T[size];
			std::copy_n(other.begin(), size, data);
		}
		return *this;
	}

	template<typename T>
	T& Vector<T>::operator[](const int& index) {
		assert(index >= 0 && index < size);
		return data[index];
	}
	template<typename T>
	const T& Vector<T>::operator[](const int& index) const {
		assert(index >= 0 && index < size);
		return data[index];
	}


	template<typename T>
	Vector<T>& Vector<T>::operator+(const T& k) {
		for (int i = 0; i < size; i++) {
			data[i] += k;
		}
		return *this;
	}
	template<typename T>
	Vector<T>& Vector<T>::operator+(const Vector& vec) {
		assert(size == vec.size);
		for (int i = 0; i < size; i++) {
			data[i] += vec[i];
		}
		return *this;
	}

	template<typename T>
	Vector<T>& Vector<T>::operator-(const T& k) {
		for (int i = 0; i < size; i++) {
			data[i] -= k;
		}
		return *this;
	}
	template<typename T>
	Vector<T>& Vector<T>::operator-(const Vector& vec) {
		assert(size == vec.size);
		for (int i = 0; i < size; i++) {
			data[i] -= vec[i];
		}
		return *this;
	}

	template<typename T>
	Vector<T>& Vector<T>::operator*(const T& k) {
		for (int i = 0; i < size; i++) {
			data[i] *= k;
		}
		return *this;
	}
	template<typename T>
	Vector<T>& Vector<T>::operator*(const Vector& vec) {
		assert(size == vec.size);
		for (int i = 0; i < size; i++) {
			data[i] *= vec[i];
		}
		return *this;
	}

	template<typename T>
	Vector<T>& Vector<T>::operator+=(const T& k){
		T* temp_data = new T[size + 1];
		std::copy_n(data, size, temp_data);
		temp_data[size] = k;
		delete[] data;
		data = temp_data;
		size += 1;
		return *this;
	}
	template<typename T>
	Vector<T>& Vector<T>::operator+=(const Vector& vec) {
		Vector<T> temp_vec = *this;
		delete[] data;
		data = new T[temp_vec.size + vec.size];
		std::copy(temp_vec.begin(), temp_vec.end(), data);
		std::copy(vec.begin(), vec.end(), data + temp_vec.size);

		return *this;
	}

	template<typename T>
	Vector<T>& Vector<T>::operator-=(const int& k) {
		Vector<T> temp_vec = *this;
		delete[] data;
		size -= k;
		data = new T[size];
		for (int i = 0; i < size; i++) {
			data[i] = temp_vec[i];
		}
		return *this;
	}
	template<typename T>
	Vector<T>& Vector<T>::operator-=(const Vector& vec) {
		Vector<T> temp_vec;
		for (int i = 0; i < this->size; i++) {
			bool found = false;
			for (int j = 0; j < vec.size; j++) {
				if (this->data[i] == vec.data[j]) {
					found = true;
					break;
				}
			}
			if (!found) {
				temp_vec += this->data[i];
			}
		}
		delete[] data;
		size = temp_vec.size;
		data = new T[size];
		std::copy(temp_vec.begin(), temp_vec.end(), data);
		return *this;
	}

	template<typename T>
	Vector<T>& Vector<T>::operator*=(const int& k) {
		Vector<T> temp_vec;
		for (int i = 0; i < k; i++) {
			temp_vec += *this;
		}
		delete[] data;
		size = temp_vec.size;
		data = new T[size];
		std::copy(temp_vec.begin(), temp_vec.end(), data);
		return *this;
	}
	template<typename T>
	Vector<T>& Vector<T>::operator*=(const Vector& vec) {
		Vector<T> temp_vec;
		for (int i = 0; i < vec.size; i++) {
			for (int j = 0; j < size; j++) {
				temp_vec += this->data[j] * vec[i];
			}
		}
		delete[] data;
		size = this->size * vec.size;
		data = new T[size];
		std::copy(temp_vec.begin(), temp_vec.end(), data);

		return *this;
	}

	template<typename T>
	bool Vector<T>::operator==(const Vector& vec) const{
		if (size != vec.size) {
			return false;
		}
		for (int i = 0; i < size; i++) {
			if (this->data[i] != vec[i]) {
				return false;
			}
		}
		return true;
	}
	template<typename T>
	bool Vector<T>::operator!=(const Vector& vec) const {
		if (size != vec.size) {
			return true;
		}
		for (int i = 0; i < size; i++) {
			if (this->data[i] != vec[i]) {
				return true;
			}
		}
		return false;
	}

	/*template<typename T>
	std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
		os << "[ ";
		for (int i = 0; i < vec.length(); ++i) {
			os << vec[i] << " ";
		}
		os << "]";
		return os;
	}*/

}


template class PB_C::Vector<int>;
template class PB_C::Vector<double>;
template class PB_C::Vector<float>;
template class PB_C::Vector<char>;

