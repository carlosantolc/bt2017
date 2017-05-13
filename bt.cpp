#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct{
	int tiempo;
	std::vector<int> tareas;
	std::vector<int> maquinas;
}solucion;

void generar(vector<int> &completo) {
	std::next_permutation(completo.begin(), completo.end());
}

void bt(int alumnos) {
	vector<int> completo;
	for (int i = 0; i < alumnos; ++i)
	{
		completo.push_back(i);
	}
	vector<int> posibles;
	/*do {
    std::cout << completo[0] << ' ' << completo[1] << ' ' << completo[2] << ' ' << completo[3] << '\n';
  } while ( std::next_permutation(completo.begin(), completo.end()));*/
	cout << completo[0] << ' ' << completo[1] << ' ' << completo[2] << ' ' << completo[3] << '\n';
	generar(completo);
	cout << completo[0] << ' ' << completo[1] << ' ' << completo[2] << ' ' << completo[3] << '\n';
	completo.erase(completo.begin());
	cout << completo[0] << ' ' << completo[1] << ' ' << completo[2] << ' ' << completo[3] << '\n';
	cout << completo.size() << endl;
	completo.insert(completo.begin(), 0);
	cout << completo[0] << ' ' << completo[1] << ' ' << completo[2] << ' ' << completo[3] << '\n';
	cout << completo.size() << endl;

}



int main(int argc, char *argv[]) {


	string txt;
	txt = argv[1];
	ifstream fichero;
	fichero.open (txt.c_str() );
	int num_casos;	
	int alumnos;
	fichero >> num_casos;
	cout << num_casos << endl;
	for (int i = 0; i < num_casos; ++i) {
		fichero >> alumnos;
		cout << alumnos << endl;
		int amistad[alumnos][alumnos] = {};
		int trabajo[alumnos][alumnos] = {};
		for (int j = 0; j < alumnos; ++j)
		{
			for (int k = 0; k < alumnos; ++k) {
				if (k == j) {
					amistad[j][k] == 0;
				} else {
					fichero >> amistad[j][k];
				}
				cout << amistad[j][k];
			}
			cout << endl;
		}
		for (int j = 0; j < alumnos; ++j)
		{
			for (int k = 0; k < alumnos; ++k) {
				if (k == j) {
					trabajo[j][k] == 0;
				} else {
					fichero >> trabajo[j][k];
				}
				cout << trabajo[j][k];
			}
			cout << endl;
		}
		bt(alumnos);
	}
}