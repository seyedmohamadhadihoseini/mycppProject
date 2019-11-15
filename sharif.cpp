#include <iostream>
#include "Header.h"
using namespace std;
using namespace ContactBook;
int main()
{
	Person a(937, (char*)"hadi", 20, (char*)"kashan in the library in my heart to schedule!");
	Person b;
	b.Edit(935, (char*)"omid", 18, (char*)"Isfahan");
	a.Show();

	return 0;
}