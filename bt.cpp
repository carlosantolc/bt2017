#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

const int SIZE = 10;
int amistad[SIZE][SIZE] = {};
int trabajo[SIZE][SIZE] = {};

vector<int> permutaciones;

void generar(int nivel, int s[]) {
	
	if (s[nivel-1] != -1) {
		std::next_permutation(permutaciones.begin(), permutaciones.end());
	}
	s[nivel-1] = permutaciones.at(nivel-1);
}

bool solucion(int nivel, int alumnos) {
	if (nivel == alumnos) {
		return true;
	}
	return false;
}

bool criterio(int nivel, int alumnos) {
	if (nivel < alumnos) {
		return true;
	}
	return false;
}

bool masHermanos(int nivel, int alumnos, int s[]) {
	if (nivel != alumnos) {
		if(s[nivel-1] < permutaciones.at(nivel)) {
			return true;
		}
	}
	return false;
}

void retroceso(int &nivel, int s[]) {
	s[nivel-1] = -1;
	nivel--;
}

void bt(int alumnos) {
	for (int i = 0; i < alumnos; ++i)
	{
		permutaciones.push_back(i);
	}

	int voa = -1; /* valor optimo actual */
	int soa [alumnos];
	int nivel = 1; /* Inicializa el nivel */
	int s [alumnos];
	int temp;
	for (int i = 0; i < alumnos; ++i)
	{
		s[i] = -1;
	}

	do {
		generar(nivel,s);
		if (solucion(nivel,alumnos)) {
			temp=0;
			int si = 0;
			int sj = 0;
			for (int i = 0; i < alumnos-1; i=i+2)
			{
				si = s[i];
				sj = s[i+1];
				temp += (amistad[si][sj]+amistad[sj][si])*(trabajo[si][sj]+trabajo[sj][si]);
			}
			if (temp > voa) {
				for (int i = 0; i < alumnos; ++i)
				{
					soa[i] = s[i];
				}
				voa = temp;
			}
		}
		if (criterio(nivel,alumnos)) {
			nivel++;
		} else {
			while((!masHermanos(nivel,alumnos,s)) && (nivel > 0)) {
				retroceso(nivel,s);
			}
		}
	} while(nivel!=0);

	cout << voa << endl;
	for (int i = 0; i < alumnos; ++i)
	{
		if (i == 0) {
			cout << soa[i];
		} else {
			cout << " " << soa[i];
		}
	}
	cout << endl;

	permutaciones.clear();

}



int main(int argc, char *argv[]) {

	int num_casos;	
	int alumnos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; ++i) {
		cin >> alumnos;
		//int amistad[alumnos][alumnos] = {};
		//int trabajo[alumnos][alumnos] = {};
		for (int j = 0; j < alumnos; ++j)
		{
			for (int k = 0; k < alumnos; ++k) {
				if (k != j) {
					cin >> amistad[j][k];
				}
			}
		}
		for (int j = 0; j < alumnos; ++j)
		{
			for (int k = 0; k < alumnos; ++k) {
				if (k != j) {
					cin >> trabajo[j][k];
				}
			}
		}

		bt(alumnos);
	}
}