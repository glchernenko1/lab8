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
	
	{dyn_array t;
	cout << t.count() << endl;
	ifstream Data_file("Data.txt");
	Data_file >> t;
	cout << t << endl;
	testAll();
	Data_file.close();
	}
	
	system("Pause");
	return 0;
}