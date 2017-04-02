#include "stdafx.h"

typedef pair<int, int> int_pair;

//typedef tuple<int, int, int> trie;

pair<int, int> sum_and_product(int a, int b)
{
	return pair<int, int>(a + b, a*b);
}

//trie sum_prod_avg(int a, int b, int c)
//{
	//trie t{ a + b + c, a*b*c,(a + b + c) / 3 };

	//return t;
//}

template<typename T1, typename T2, typename T3>
struct triple
{
	typedef T1 result_type;
	
	T1 first;
	T2 second;
	T3 third;

	triple(const T1& first, const T2& second, const T3& third)
		: first(first), second(second),third(third){}
};

typedef triple<int, int, int> trie;

//trie sum_prod_avg(int a, int b, int c)
//{
//	return trie(a + b + c, a*b*c, (a + b + c) / 3);
//}

template<typename T1, typename T2, typename T3>
triple<T1, T2, T3> sum_prod_avg(const T1& a, const T2& b, const T3& c)
{
	return triple<T1, T2, T3>(a + b + c, a*b*c, (a + b + c) / triple<T1,T2,T3>::result_type(3));
}

void consuming_templates()
{
	int a = 2, b = 3;
	auto result = sum_and_product(a, b);
	cout << "sum = " << result.first << " product = " << result.second << endl;

	int c = 4;
	auto res = sum_prod_avg(a, b, c);
	/*cout << "sum = " << get<0>(res) << endl;
	cout << "prod = " << get<1>(res) << endl;
	cout << "avg = " << get<2>(res) << endl;*/

	cout << "sum = " << res.first << endl;
	cout << "prod = " << res.second << endl;
	cout << "avg = " << res.third << endl;
}

void template_functions()
{
	int a = 14;
	double b = 5.0;
	float c = -3.5f;

	auto res = sum_prod_avg(a, b, c);
	cout << "sum = " << res.first << endl;
	cout << "prod = " << res.second << endl;
	cout << "avg = " << res.third << endl;
}

typedef complex<double> cd;
typedef triple<cd, cd, cd> cdt;

template<> cdt sum_prod_avg(const cd& a, const cd& b, const cd& c)
{
	auto res = sum_prod_avg(a.real(), b.real(), c.real());
	return cdt(res.first, res.second, res.third);
	}

void template_specializaton()
{
	cd a(2, 3), b(3, 4), c(4, 5);

	auto res = sum_prod_avg(a, b, c);

	cout << "sum = " << res.first << endl;
	cout << "prod = " << res.second << endl;
	cout << "avg = " << res.third << endl;
}

template<typename T>
T sum(T t) { return t; }

template<typename T, typename ...U>
auto sum(T t, U ...u) -> decltype(t + sum(u...))
{
	return t + sum(u...);
}

void variadic()
{
	cout << sum(1, 2, 3, 4) << endl;
	cout << sum(1, 2.5, 3, 4) << endl;
	cout << sum(string("abra"),string("cadabra")) << endl;
}

template<int n> struct Factorial
{
	enum {value = n * Factorial<n-1>::value};
};

//Stopping condition
template<> struct Factorial<0>
{
	enum {value = 1};
};

void metaprogramming()
{
	int x = Factorial<4>::value;
	int y = Factorial<0>::value;
}

int main()
{
	//consuming_templates();

	//template_functions();

	//template_specializaton();

	variadic();

	//metaprogramming();

	system("pause");
	return 0;
}