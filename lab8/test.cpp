#include "test.h"
#include "dyn_array.h"



bool test_count()
{
	{dyn_array a(6);
	assert(a.count() == 6); }
	dyn_array a(3);
	assert(a.count() == 3);
	std::cout << "Test count OK" << std::endl;
	return true;
}

bool test_resize()
{
	dyn_array a(6);
	a.resize(7);
	assert( a.count() == 7); 
	a.resize(4);
	assert(a.count() == 4);
	std::cout << "Test resize OK" << std::endl;
	return true;
}

bool test_append()
{
	dyn_array a(6);
	
	a.append(7);
		assert(a.count() == 7&& a[6]==7);
	
	std::cout << "Test append OK" << std::endl;
	return true;
}

bool test_insert()
{
	dyn_array a(6);

	a.insert(5, 2);
		assert(a.count() == 7 && a[5] == 2);

	std::cout << "Test insert OK" << std::endl;
	return true;
}


bool test_remove()
{
	dyn_array a(6);
	a[1] = 2;
	a.remove(0);
		assert(a.count() == 5 && a[0] == 2);

	std::cout << "Test remove OK" << std::endl;
	return true;
}

bool test_find()
{
	dyn_array a(6);
	a[1] = 2;
	
		assert(a.find(2) == 1);

	std::cout << "Test find OK" << std::endl;
	return true;
}

void testAll()
{
	if(test_count() && test_resize() && test_append() && test_insert() && test_remove() && test_find())
		std::cout << "Test ALL OK" << std::endl;
}
