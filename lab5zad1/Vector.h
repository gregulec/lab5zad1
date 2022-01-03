#pragma once
using namespace std;
template <typename T>
class Vector {
private:
	size_t dimensions;
	T* data;

public:
	Vector<T>(size_t dimensions) :
		dimensions(dimensions), data(new T[dimensions]()) {}
	Vector<T>(const Vector<T>&other) : dimensions(other.dimensions), data(other.data){
		data = new T[dimensions];
		for (size_t i = 0; i < dimensions; i++){
			this->data = other.data[i];
		}
	}

	virtual ~Vector<T>() {
		if (data) delete data;
	}

	size_t size() const {
		return dimensions;
	}

	T& operator[](size_t index) {
		return data[index];
	}

	T operator[](size_t index) const {
		return data[index];
	}

	
};

template<typename T>
Vector<T> operator+(const Vector<T>& a, const Vector<T>& b) {
	Vector<T> c(a.size());
	for (size_t i = 0; i < a.size(); i++) {
		c[i] = a[i] + b[i];
	}
	return c;
}

template<typename T>
Vector<T> operator-(const Vector<T>& a, const Vector<T>& b) {
	Vector<T> c(a.size());
	for (size_t i = 0; i < a.size(); i++) {
		c[i] = a[i] - b[i];
	}
	return c;
}

template<typename T>
bool operator==(const Vector<T>& a, const Vector<T>& b) {
	if (&a == &b) return true;
	if (a.size() != b.size())
		return false;
	for (size_t i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

template<typename T>
bool operator!=(const Vector<T>& a, const Vector<T>& b) {
	if (&a != &b) return true;
	if (a.size() == b.size())
		return false;
	for (size_t i = 0; i < a.size(); i++) {
		if (a[i] == b[i]) return false;
	}
	return true;
}

template<typename T>
ostream& operator<<(ostream& stream, const Vector<T>&a){
	for (size_t i = 0; i < a.size(); i++){
		stream << a[i] << " ";
	}
	return stream;
}