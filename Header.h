#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <locale>
#include <Windows.h>
#include <cmath>
#include <algorithm>

struct Developers {

	std::string firmName;
	std::string adres;
	int numhouse;
	int series;
	int yearConstruction;
	int floors;

};

template<typename A, typename two, typename three>

class HashTable {

public:
	HashTable() {}

	void loadtable(std::string namefile) {
		std::ifstream fin;
		A x;
		fin.open(namefile);
		if (fin) {
			while (!fin.eof()) {
				fin >> x.firmName >> x.adres >> x.numhouse >> x.series >> x.yearConstruction >> x.floors;
				Table.push_back(x);
			}
			fin.close();
			int realsize = Table.size() * 1.3;
			RealTable = new A[realsize];
			
			std::cout << "size = " << realsize << endl;
			for (int i = 0; i < realsize; i++) {

				std::cout << "." << std::endl;

			}
		}
		else {
			std::cout << "Ошибка открытия файла" << std::endl;
		}
	}

	int get_HashStr(A t, two(A::*field)) {
		long long hash = 0, p_pow = 1;
		const int p = 53;
		std::string key;
		key = t.*field;

		for (int i = 0; i < key.size(); i++) {

			hash += abs(key[i]) * p_pow;
			hash = abs(hash);
			p_pow *= p;
			
		}
		return hash % int(Table.size() * 1.3);
	}

	A get_struct(int x) {
		return Table[x];
	}

	int get_size() { return Table.size(); }
private:

	std::vector<A> Table;
	A* RealTable;
};
