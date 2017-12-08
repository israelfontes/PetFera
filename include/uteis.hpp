#ifndef _UTEIS_HPP_
#define	_UTEIS_HPP_

#include <fstream>
#include <iostream>
#include <map>
#include "animal.hpp"

using namespace std;

	u_int findTratador(int o);
	u_int findVet(int o);
	template<typename T >
	void write(fstream *file, map<int,T> *objeto);
	template<typename T >
	void cadastrar(map<int,T> * map);
	template<typename T >
	bool excluir(map<int, T> * map);
	template<typename T >
	bool consultar(map<int, T> * map);
	string word(fstream * file);

	bool loadFuncionarios(fstream *file, map<int,Tratador> *tratadores, map<int,Veterinario> *veterinarios);
	bool loadAnimals(fstream *file, map<int,Anfibio> *anfibios, map<int,Reptil> *repteis,
			map<int,Mamifero> *mamiferos, map<int,AveNativa> *avesNativas, map<int,AveExotica> *avesExoticas);

#include "uteis.inl"
#endif