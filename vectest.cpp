#include "vec.cpp"

int main()
{
	vec<double> v(10);
	double D = 2.0;
	for(int i=0;i<v.size();i++)
		v(i) = i;
	std::cout<<v(11);
}