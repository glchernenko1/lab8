#include <iostream>
#include "dyn_array.h"
#include "test.h"
#include <fstream>

using namespace std;
/*
dyn_array File(ifstream& is)
{
	return  is >> dyn_array();
}
*/

int main()
{
	setlocale(LC_ALL, "Russian");
	dyn_array t;
	ifstream Data_file("Data.txt");
	Data_file >> t;
	t[1];
	testAll();
	Data_file.close();
	
	
	system("Pause");
	return 0;
}