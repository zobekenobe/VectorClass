/*
 * vector.cpp
 * Copyright (C) 2016 zobekenobe <zobekenobe@gmail.com>
 *
 * vector.cpp is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * vector.cpp is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



template<typename T>
vector<T>::vector():size(0),vec(NULL){}

template<typename T>
vector<T>::~vector()
{delete vec;}

template<typename T>
vector<T>::vector(int s):size(s),vec(new T[s])
{for(int i=0;i<s;i++) vec[i] = {}; }

template<typename T>
vector<T>::vector(int s, const T& a):size(s),vec(new T[s])
{for(int i=0;i<s;i++) vec[i]=a;}

template<typename T>
vector<T>::vector(const vector<T>& V):size(V.size),vec(new T[V.size])
{for(int i=0;i<V.size;i++) vec[i] = V.vec[i];}

template<typename T>
vector<T>::vector(int s, const T* arr):size(s),vec(new T[s])
{for(int i=0;i<s;i++) vec[i] = arr[i];}


// Overloading Read and Write operators
template<typename T>
T& vector<T>::operator[](int i)
{return vec[i];}

template<typename T>
const T vector<T>::operator()(int i) const
{return vec[i];}

// Binary operator overloading
template<typename T>
const vector<T> operator+(const vector<T>& v1, const vector<T>& v2)
{
	vector<T> v(v1.size);
	for(size_t i=0;i<v1.size;i++)
		v.vec[i] = v1.vec[i]+v2.vec[i];
	return v;
}

template<typename T>
const vector<T> operator-(const vector<T>& v1, const vector<T>& v2)
{
	vector<T> v(v1.size);
	for(size_t i=0;i<v1.size;i++)
		v.vec[i] = v1.vec[i]-v2.vec[i];
	return v;
}

template<typename T>
const T operator*(const vector<T>& v1, const vector<T>& v2)
{
	//T sum = T();
	T sum {};
	for(size_t i=0;i<v1.size;i++)
		sum += v1.vec[i]*v2.vec[i];
	return sum;
}

template<typename T>
const vector<T> operator,(const vector<T>& v1, const vector<T>& v2)
{
	vector<T> v(v1.size);
	for(size_t i=0;i<v1.size;i++)
		v.vec[i]=v1.vec[i]*v2.vec[i];
	return v;
}

// Binary Friend Functions: Vector - constant operations
template<typename T>
const vector<T> operator+(const vector<T>& v, const T& k)
{
	vector<T> v1(v.size);
	for(size_t i=0;i<v.size;i++){
		v1.vec[i] = v.vec[i]+k;}
	return v1;
}

template<typename T>
const vector<T> operator+(const T& k, const vector<T>& v)
{return (v+k);}

template<typename T>
const vector<T> operator-(const vector<T>& v, const T& k)
{
	vector<T> v1(v.size);
	for(size_t i=0;i<v.size;i++){
		v1.vec[i] = v.vec[i]-k;}
	return v1;
}

template<typename T>
const vector<T> operator-(const T& k, const vector<T>& v)
{vector<T> v1(v.size);
	for(size_t i=0;i<v.size;i++){
		v1.vec[i] = k-v.vec[i];}
	return v1;
}

template<typename T>
const vector<T> operator*(const vector<T>& v, const T& k)
{
	vector<T> v1(v.size);
	for(size_t i=0;i<v.size;i++)
		v1.vec[i] = v.vec[i]*k;
	return v1;
}

template<typename T>
const vector<T> operator*(const T& k, const vector<T>& v)
{return (v*k);}

template<typename T>
const vector<T> operator/(const vector<T>& v, const T& k)
{return v*(1/k);}


// Unary Operators
template<typename T>
const vector<T>& vector<T>::operator=(const vector<T>& v)
{	
	size = v.size;
	for(size_t i=0;i<v.size;i++)
		vec[i] = v.vec[i];
	return *this;
}

template<typename T>
const vector<T>& vector<T>::operator+=(const vector<T>& v)
{
	for(size_t i=0;i<v.size;i++)
		vec[i]+=v.vec[i];
	return *this;
}

template<typename T>
const vector<T>& vector<T>::operator+=(const T& k)
{
	for(size_t i=0;i<size;i++)
		vec[i]+=k;
	return *this;
}

template<typename T>
const vector<T>& vector<T>::operator-=(const vector<T>& v)
{
	for(size_t i=0;i<v.size;i++)
		vec[i]-=v.vec[i];
	return *this;
}

template<typename T>
const vector<T>& vector<T>::operator-=(const T& k)
{
	for(size_t i=0;i<size;i++)
		vec[i]-=k;
	return *this;
}

template<typename T>
const vector<T>& vector<T>::operator*=(const vector<T>& v)
{
	for(size_t i=0;i<size;i++)
		vec[i]*=v[i];
	return *this;
}

template<typename T>
const vector<T>& vector<T>::operator*=(const T& k)
{
	for(size_t i=0;i<size;i++)
		vec[i]*=k;
	return *this;
}

template<typename T>
const vector<T>& vector<T>::operator/=(const T& k)
{
	for(size_t i=0;i<size;i++)
		vec[i]/=k;
	return *this;
}

template<typename T>
const vector<T>& vector<T>::operator++()
{
	for(size_t i=0;i<size;i++)
		++vec[i];
	return *this;
}

template<typename T>
const vector<T>& vector<T>::operator++(int)
{
	for(size_t i=0;i<size;i++)
		vec[i]++;
	return *this;
}

// Reading and Writing operators0
template<typename T>
std::ostream& operator<<(std::ostream& out, const vector<T>& V)
{
	for(int i=0;i<V.size;i++)
		out<<V.vec[i]<<" ";
	//out<<std::endl;
	return out;
}

template<typename T>
std::istream& operator>>( std::istream& in, const vector<T>& V)
{
	for(int i=0;i<V.size;i++)
		in>>V.vec[i];
	return in;
}

// Other functions

