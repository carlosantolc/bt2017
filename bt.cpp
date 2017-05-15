#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/*typedef struct{
	int tiempo;
	std::vector<int> tareas;
	std::vector<int> maquinas;
}solucion;*/

bool permutar;
vector<int> permutaciones;

void generar(int nivel, int s[]) {
	
	if (permutar == true) {
		std::next_permutation(permutaciones.begin(), permutaciones.end());
	}
	s[nivel-1] = permutaciones.front();
	permutaciones.erase(permutaciones.begin());
	cout << permutaciones.size() << " " << s[nivel-1] <<  endl;
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
		bool existe = false;
		permutaciones.insert(permutaciones.begin(), s[nivel-1]);
		cout << permutaciones.size() << endl;
		for (size_t i = 0; i < permutaciones.size(); ++i)
		{
			if(permutaciones.at(i) > s[nivel-1]) {
				existe = true;
			}
		}
		return existe;
	}
	return false;
}

void retroceso(int &nivel, int s[]) {
	s[nivel-1] = -1;
	nivel--;
	permutar = true;
}

void bt(int alumnos) {
	for (int i = 0; i < alumnos; ++i)
	{
		permutaciones.push_back(i+1);
	}

	int voa = -1; /* valor optimo actual */
	int *soa = 0; /* Solucion optima actual */
	int nivel = 1; /* Inicializa el nivel */
	int s [alumnos] = {};
	permutar = false;
	for (int i = 0; i < alumnos; ++i)
	{
		s[i] = -1;
	}
	/*do {
    std::cout << permutaciones[0] << ' ' << permutaciones[1] << ' ' << permutaciones[2] << ' ' << permutaciones[3] << '\n';
  } while ( std::next_permutation(permutaciones.begin(), permutaciones.end()));*/
	/*cout << permutaciones[0] << ' ' << permutaciones[1] << ' ' << permutaciones[2] << ' ' << permutaciones[3] << '\n';
	generar(permutaciones);
	cout << permutaciones[0] << ' ' << permutaciones[1] << ' ' << permutaciones[2] << ' ' << permutaciones[3] << '\n';
	permutaciones.erase(permutaciones.begin());
	cout << permutaciones[0] << ' ' << permutaciones[1] << ' ' << permutaciones[2] << ' ' << permutaciones[3] << '\n';
	cout << permutaciones.size() << endl;
	permutaciones.insert(permutaciones.begin(), 0);
	cout << permutaciones[0] << ' ' << permutaciones[1] << ' ' << permutaciones[2] << ' ' << permutaciones[3] << '\n';
	cout << permutaciones.size() << endl;
	permutaciones.clear();*/

	do {
		generar(nivel,s);
		if (solucion(nivel,alumnos)) {
			for (int i = 0; i < alumnos; ++i)
			{
				cout << s[i];
			}
			cout << endl;
		}
		if (criterio(nivel,alumnos)) {
			nivel++;
		} else {
			while((!masHermanos(nivel,alumnos,s)) && (nivel > 0)) {
				retroceso(nivel,s);
			}
		}
	} while(nivel!=0);

	permutaciones.clear();

}



int main(int argc, char *argv[]) {


	string txt;
	txt = argv[1];
	ifstream fichero;
	fichero.open (txt.c_str() );
	int num_casos;	
	int alumnos;
	fichero >> num_casos;
	//cout << num_casos << endl;
	for (int i = 0; i < num_casos; ++i) {
		fichero >> alumnos;
		//cout << alumnos << endl;
		int amistad[alumnos][alumnos] = {};
		int trabajo[alumnos][alumnos] = {};
		for (int j = 0; j < alumnos; ++j)
		{
			for (int k = 0; k < alumnos; ++k) {
				if (k != j) {
					fichero >> amistad[j][k];
				}
				//cout << amistad[j][k];
			}
			//cout << endl;
		}
		for (int j = 0; j < alumnos; ++j)
		{
			for (int k = 0; k < alumnos; ++k) {
				if (k != j) {
					fichero >> trabajo[j][k];
				}
			//	cout << trabajo[j][k];
			}
			//cout << endl;
		}
		bt(alumnos);
	}
}