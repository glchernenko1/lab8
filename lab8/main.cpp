#include <iostream>
#include "dyn_array.h"
#include "test.h"
#include <fstream>

using namespace std;

/*dyn_array File(ifstream& is)
{
	dyn_array a;
	is >> a;
	return  a;
}
*/

int main()
{
	setlocale(LC_ALL, "Russian");
	
	dyn_array t1;
	t1.resize(7);
	ifstream Data_file("Data.txt");
	Data_file >> t1;
	while (!Data_file.eof())
	{

		dyn_array t2;
		Data_file >> t2;
		t1.append(t2);
	}
	Data_file.close();
	t1.sort();
	int size = t1.count();
	t1.unique();
	t1.sort();
	t1.unique();
	ofstream new_array;
	new_array.open("new_array.txt");
	new_array << t1;
	new_array.close();

	testAll();
	dyn_array t(4);
	cout  <<"Количество чисел в файле " <<size<< endl;
	dyn_array t2 = t;
	cout << (t==t2);
	system("Pause");
	return 0;
}