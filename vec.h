#ifndef _vec_cpp
#define _vec_cpp

#include<iostream>

template<typename> class vec;

template<typename T> const vec<T> operator+(const vec<T>& , const vec<T>&);
template<typename T> const vec<T> operator-(const vec<T>& , const vec<T>&);
template<typename T> const vec<T> operator*(const vec<T>& , const vec<T>&);

template<typename T> const vec<T> operator+(const vec<T>&, const T&);
template<typename T> const vec<T> operator-(const vec<T>&, const T&);
template<typename T> const vec<T> operator*(const vec<T>&, const T&);
template<typename T> const vec<T> operator/(const vec<T>&, const T&);

template<typename T> const vec<T> operator+(const T&, const vec<T>&);
template<typename T> const vec<T> operator-(const T&, const vec<T>&);
template<typename T> const vec<T> operator*(const T&, const vec<T>&);
template<typename T> const vec<T> operator/(const T&, const vec<T>&);

template<typename T> const vec<T> operator+(const vec<T>&, T&&);
template<typename T> const vec<T> operator-(const vec<T>&, T&&);
template<typename T> const vec<T> operator*(const vec<T>&, T&&);
template<typename T> const vec<T> operator/(const vec<T>&, T&&);

template<typename T> const vec<T> operator+(T&&, const vec<T>&);
template<typename T> const vec<T> operator-(T&&, const vec<T>&);
template<typename T> const vec<T> operator*(T&&, const vec<T>&);
template<typename T> const vec<T> operator/(T&&, const vec<T>&);


template<typename T> std::ostream& operator<<(std::ostream&, const vec<T>&);
template<typename T> std::istream& operator>>(std::istream&, const vec<T>&);


template<typename T>
class vec
{
	private:
		int _size;
		T* elem;

	public:
		vec();
		vec(int n);
		vec(const vec<T>& );
		vec(vec<T>&&);
		~vec();

		// Overloading the operators
		const int size()const {return _size;}
		T& operator()(int i);
		const T& operator[](int i) const;

		// Friend Overloaded operators
		friend const vec<T> operator+ <T>(const vec<T>&, const vec<T>& );
		friend const vec<T> operator- <T>(const vec<T>&, const vec<T>& );
		friend const vec<T> operator* <T>(const vec<T>&, const vec<T>& );

		friend const vec<T> operator+ <T>(const vec<T>&, const T&);
		friend const vec<T> operator- <T>(const vec<T>&, const T&);
		friend const vec<T> operator* <T>(const vec<T>&, const T&);
		friend const vec<T> operator/ <T>(const vec<T>&, const T&);

		friend const vec<T> operator+ <T>(const T&, const vec<T>&);
		friend const vec<T> operator- <T>(const T&, const vec<T>&);
		friend const vec<T> operator* <T>(const T&, const vec<T>&);
		friend const vec<T> operator/ <T>(const T&, const vec<T>&);

		friend const vec<T> operator+ <T>(const vec<T>&, T&&);
		friend const vec<T> operator- <T>(const vec<T>&, T&&);
		friend const vec<T> operator* <T>(const vec<T>&, T&&);
		friend const vec<T> operator/ <T>(const vec<T>&, T&&);

		friend const vec<T> operator+ <T>(T&&, const vec<T>&);
		friend const vec<T> operator- <T>(T&&, const vec<T>&);
		friend const vec<T> operator* <T>(T&&, const vec<T>&);
		friend const vec<T> operator/ <T>(T&&, const vec<T>&);


		friend std::ostream& operator<< <T>(std::ostream&, const vec<T>&);
		friend std::istream& operator>> <T>(std::istream&, const vec<T>&);

};




#endif