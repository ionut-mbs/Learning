#include "stdafx.h"

typedef pair<int, int> int_pair;

typedef tuple<int, int, int> trie;

pair<int, int> sum_and_product(int a, int b)
{
	return pair<int, int>(a + b, a*b);
}

trie sum_prod_avg(int a, int b, int c)
{
	trie t{ a + b + c, a*b*c,(a + b + c) / 3 };

	return t;
}


void consuming_templates()
{
	int a = 2, b = 3;
	auto result = sum_and_product(a, b);
	cout << "sum = " << result.first << " product = " << result.second << endl;

	int c = 4;
	auto res = sum_prod_avg(a, b, c);
	cout << "sum = " << get<0>(res) << endl;
	cout << "prod = " << get<1>(res) << endl;
	cout << "avg = " << get<2>(res) << endl;
}

int main()
{
	consuming_templates();

	system("pause");
	return 0;
}