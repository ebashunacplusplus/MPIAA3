#include <iostream>
#include "Header.h"


using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	HashTable<Developers, string, int> myTable;
	
	myTable.loadtable("temp.txt");

	//for (int i = 0; i < myTable.get_size(); i++) {
		//cout << myTable.get_HashStr(myTable.get_struct(i), &Developers::firmName) << endl;
	//}

	system("pause");

	return 0;
}