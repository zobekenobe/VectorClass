/*
 * vector.h
 * Copyright (C) 2016 zobekenobe <zobekenobe@gmail.com>
 *
 * vector.h is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * vector.h is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */





#ifndef vector_h_
#define vector_h_

template<typename T> class vector;
template<typename T> class matrix;

// Friend functions : Binary Operators :: vector-vector operations
template<typename T> const vector<T> operator+(const vector<T>&, const vector<T>&);
template<typename T> const vector<T> operator-(const vector<T>&, const vector<T>&);
template<typename T> const T         operator*(const vector<T>&, const vector<T>&);
template<typename T> const vector<T> operator,(const vector<T>&, const vector<T>&);

// Friend functions : Binary Operators :: vector-constant operations
template<typename T> const vector<T> operator+(const vector<T>&, const T&);
template<typename T> const vector<T> operator+(const T&, const vector<T>&);
template<typename T> const vector<T> operator-(const vector<T>&, const T&);
template<typename T> const vector<T> operator-(const T&, const vector<T>&);
template<typename T> const vector<T> operator*(const vector<T>&, const T&);
template<typename T> const vector<T> operator*(const T&, const vector<T>&);
template<typename T> const vector<T> operator/(const vector<T>&, const T&);	

// Friend functions: Matrix vector operations
		
//Friend functions: 
template<typename T> T norm(const vector<T>&);		// norm
template<typename T> T norm(const matrix<T>&);
template<typename T> T norminf(const vector<T>&);	// infinite norm
template<typename T> T norminf(const matrix<T>&);

// Friend functions: iostream functions
template<typename T> std::ostream& operator<<(std::ostream&, const vector<T>& );
template<typename T> std::istream& operator>>(std::istream&, const vector<T>& );


template<typename T>
class vector
{
	friend matrix<T>;
	
	private:
		int size;
		T* vec;
	public:
		vector();						// pointing to NULL
		explicit vector(int n); 		// zero based array
		vector(int, const T& a); 		// initialize to a constant value
		vector(int, const T* a);    	// initialize to an array
		vector(const vector& v);		// copy constructor
		~vector();						// destructor
		
		// OPERATOR OVERLOADING
		// Binary Operators
		friend const vector<T> operator+ <T>(const vector<T>&, const vector<T>&);
		friend const vector<T> operator- <T>(const vector<T>&, const vector<T>&);
		friend const T         operator* <T>(const vector<T>&, const vector<T>&);	// scalar dot product
		friend const vector<T> operator, <T>(const vector<T>&, const vector<T>&);	// dot multiplication element wise
		
		friend const vector<T> operator+ <T>(const vector<T>&, const T&);
		friend const vector<T> operator+ <T>(const T&, const vector<T>&);
		friend const vector<T> operator- <T>(const vector<T>&, const T&);
		friend const vector<T> operator- <T>(const T&, const vector<T>&);
		friend const vector<T> operator* <T>(const vector<T>&, const T&);
		friend const vector<T> operator* <T>(const T&, const vector<T>&);
		friend const vector<T> operator/ <T>(const vector<T>&, const T&);
		
		//Unary operators
		const T operator()(int i) const;		// read
		      T& operator[](int i);			// read and write
		const vector& operator+();			// positive values of the vector
		const vector& operator-();			// negative values of the vector
		const vector& operator+=(const vector&);	// addition to self	
		const vector& operator+=(const T&);		// addition to self with constant
		const vector& operator-=(const vector&);	// subtratction from self	
		const vector& operator-=(const T&);		// subtraction from self with constant
		const vector& operator*=(const vector&);	// self multiplication
		const vector& operator*=(const T&);		// self multiplication with constant 
		const vector& operator/=(const T&);		// self division with constant
		const vector& operator=(const vector&);		// assignment operator
		const bool operator==(const vector&);		// comparison operator
		const bool operator!=(const vector&);		// Not equal comparison
		const vector& operator++();			// pre increment operator
		const vector& operator++(int);			// post increment operator
		
		// other functions
		friend T norm<T>(const vector<T>&);		// norm
		friend T norm<T>(const matrix<T>&);
		friend T norminf<T>(const vector<T>&);		// infinite norm
		friend T norminf<T>(const matrix<T>&);
		inline int _l() const {return size;};		// return size	
	

		friend std::ostream& operator<< <T>(std::ostream&, const vector<T>&);
		friend std::istream& operator>> <T>(std::istream&, const vector<T>&);		

};


#endif
