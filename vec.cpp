#include "vec.h"
#include<iomanip>

template<typename T>
vec<T>::vec():_size{0}, elem{NULL}{}

template<typename T>
vec<T>::vec(int n):_size{n}, elem{new T[n]}
{
	for(int i=0;i<n;i++)
		elem[i] = 0;
}

template<typename T>
vec<T>::vec(const vec<T>& V):_size{V._size}, elem{new T[V._size]}
{
	for(int i=0;i<V._size;i++)
		elem[i] = V.elem[i];
}

template<typename T>
vec<T>::vec(vec<T>&& V):_size{V._size}, elem{new T[V._size]}
{
	for(int i=0;i<V._size;i++)
		elem[i] = std::move(V.elem[i]);
	V._size = 0;
}

template<typename T>
vec<T>::~vec()
{
	_size = 0;
	delete [] elem;
}

// OVERLOADING OPERATOR

template<typename T>
T& vec<T>::operator()(int i)
		{
			try
			{
				if(i>=_size)
					throw i;
			}
			catch(int i)
			{
				std::cout<<"index ("<< i<<") is out of bound"<<std::endl;
				exit(1);
			}
			return elem[i];
		}

template<typename T>
const T& vec<T>::operator[](int i) const 
{
	try
	{
		if(i>=_size)
			throw i;
	}
	catch(int i)
	{
		std::cout<<"index ["<< i<<"] is out of bound"<<std::endl;
		exit(1);
	}
	return elem[i];
}

// Overloading Operator: Friend Functions

template<typename T>
const vec<T> operator+(const vec<T>& v1, const vec<T>& v2)
{
	vec<T> v(v1._size);
	for(int i=0;i<v1._size;i++)
		v.elem[i] = v1.elem[i] + v2.elem[i];
	return v; 
}

template<typename T>
const vec<T> operator-(const vec<T>& v1, const vec<T>& v2)
{
	vec<T> v(v1._size);
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i] - v2[i];
	return v;

}

template<typename T>
const vec<T> operator*(const vec<T>& v1, const vec<T>& v2)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i]*v2[i];
	return v;
}

template<typename T>
const vec<T> operator/(const vec<T>& v1, const vec<T>& v2)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i]/v2[i];
	return v;
}

template<typename T>
const vec<T> operator+(const vec<T>& v1, const T& constant)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i] + constant;
	return v;
}

template<typename T>
const vec<T> operator-(const vec<T>& v1, const T& constant)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i] - constant;
	return v;
}

template<typename T>
const vec<T> operator*(const vec<T>& v1, const T& constant)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v[i]*constant;
	return v;
}


template<typename T>
const vec<T> operator/(const vec<T> v1, const T& constant)
{
	if (constant == 0)
	{
		std::cout<<"Divison by zero"<<std::endl;
		return 0;
	}
	else
	{
		vec<T> v(v1.size());
		for(int i=0;i<v1.size();i++)
			v(i) = v1(i)/constant;
		return v;
	}
	
}

template<typename T>
const vec<T> operator+(const T& constant, const vec<T>& v1)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i] + constant;
	return v;
}

template<typename T>
const vec<T> operator-(const T& constant, const vec<T>& v1)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = constant - v1[i];
	return v;
}

template<typename T>
const vec<T> operator*(const T& constant, const vec<T>& v1)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = v1[i] * constant;
	return v;
}

template<typename T>
const vec<T> operator /(const T& constant, const vec<T>& v1)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
	{
		try
		{
			if(v1.elem[i] != 0)
				v(i) = constant/v1[i];
			else 
				throw(0);
		}
		catch(int)
		{
			std::cout<<"Division by zero element"<<std::endl;
			return 0;
		}
	}
	return v;
}

template<typename T>
const vec<T> operator+(T&& constant, const vec<T>& v1)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = constant + v1[i];
	return v;
}

template<typename T>
const vec<T> operator-(T&& constant, const vec<T>& v1)
{
	vec<T> v(v1.size());
	for(int i=0;i<v1.size();i++)
		v(i) = constant - v1[i];
	return v;
}

template<typename T>
const vec<T> operator*(T&& constant, const vec<T>& v1)
{

}

template<typename T>
const vec<T> operator/( T&& constant, const vec<T>& v1)
{
	vec<T> v(v1.size());
	try{
			for(int i=0;i<v1.size();i++)
			{
				if(v.elem[i] != 0)
					v(i) = constant/v1[i];
				else
					throw(1);
			}
		}
	catch(int)
		{
			std::cout<<"Division by zero element"<<std::endl;
			return 0;
		}
			
	return v;
}




// Overloading Input and Output Operators
template<typename T>
std::ostream& operator<< (std::ostream& out, const vec<T>& v)
{
	for(int i=0;i<v._size;i++)
		out<<std::setprecision(7)<<std::setw(4)<<v.elem[i]<<" "	;
	out<<std::endl;
	return out;
}

template<typename T>
std::istream& operator >>(std::istream& in, vec<T>& v)
{
	for(int i=0;i<v._size;i++)
		in>>v.elem[i];
	return in;
}