#include "stdafx.h"

int main()
{
	ostringstream oss;

	oss << "Width ";
	oss << "Height ";
	oss << "Area";
	string text = oss.str();
	cout << text << endl;
	
	ofstream ofs("info.txt");
	string s;
	while ((cin >> s) && (s != "q"))
	{
		ofs << s << endl;
	}

	system("pause");
	return 0;
}