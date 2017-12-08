/**
* @author Israel Fontes
*/

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <map>

#include "uteis.hpp"

using namespace std;

map<int,Anfibio> map_anfibios;
map<int,Reptil> map_repteis;
map<int,Mamifero> map_mamiferos;
map<int,AveNativa> map_avesNativas;
map<int,AveExotica> map_avesExoticas;
map<int,Tratador> map_tratador;
map<int,Veterinario> map_veterinario;



int main(void){
	fstream file_animals;
	fstream file_funcionarios;
	
	file_animals.exceptions(fstream::failbit | fstream::badbit);
	
	try{
		file_animals.open("data/animais.csv", ios::out | ios::in);
	}catch(fstream::failure e){
		std::cerr << "exception in open file\n";
	}

	loadAnimals(&file_animals, &map_anfibios, &map_repteis, &map_mamiferos, &map_avesNativas, &map_avesExoticas);
	loadFuncionarios(&file_funcionarios, &map_tratador, &map_veterinario);

	int opcao = 99;
	while(opcao != 0){
		cout << "1 - Cadastrar animal" << endl;
		cout << "2 - Cadastrar funcionario" << endl;
		cout << "3 - Consultar animal" << endl;
		cout << "4 - Consultar funcionario" << endl;
		cout << "5 - Excluir animal" << endl;
		cout << "6 - Excluir funcionario" << endl;
		cout << "0 - Sair" << endl;
		cin >> opcao;

		switch (opcao){
			case 1:
				cout << "Qual a classe do animal? ";
				cout << "1 - Mamifero" << endl;
				cout << "2 - Anfibio" << endl;
				cout << "3 - Reptil" << endl;
				cout << "4 - Ave Nativa" << endl;
				cout << "5 - Ave Exotica" << endl;
				cin >> opcao;
				switch(opcao){
					case 1:
						cadastrar(&map_mamiferos);
						break;
					case 2:
						cadastrar(&map_anfibios);
						break;
					case 3:
						cadastrar(&map_repteis);
						break;
					case 4:
						cadastrar(&map_avesNativas);
						break;
					case 5:
						cadastrar(&map_avesExoticas);
						break;
					default:
						cout << "Opcao invalida" << endl;
						opcao = 1;
				}
				break;
			
			case 2:
				cout << "Qual o cargo?" << endl;
				cout << "1 - Veterinario" << endl;
				cout << "2 - Tratador" << endl;
				cin >> opcao;
				switch(opcao){
					case 1:
						cadastrar(&map_veterinario);
						break;
					case 2:
						cadastrar(&map_tratador);
						break;
					default:
						cout << "Opcao invalida" << endl;
						opcao = 2;

				}
				break;

			case 3:
				cout << "Qual a classe do animal? ";
				cout << "1 - Mamifero" << endl;
				cout << "2 - Anfibio" << endl;
				cout << "3 - Reptil" << endl;
				cout << "4 - Ave Nativa" << endl;
				cout << "5 - Ave Exotica" << endl;
				cin >> opcao;
				switch(opcao){
					case 1:
						consultar(&map_mamiferos);
						break;
					case 2:
						consultar(&map_anfibios);
						break;
					case 3:
						consultar(&map_repteis);
						break;
					case 4:
						consultar(&map_avesNativas);
						break;
					case 5:
						consultar(&map_avesExoticas);
						break;
					default:
						cout << "Opcao invalida" << endl;
						opcao = 3;
				}
				break;

			case 4:
				cout << "Qual o cargo?" << endl;
				cout << "1 - Veterinario" << endl;
				cout << "2 - Tratador" << endl;
				cin >> opcao;
				switch(opcao){
					case 1:
						consultar(&map_veterinario);
						break;
					case 2:
						consultar(&map_tratador);
						break;
					default:
						cout << "Opcao invalida" << endl;
						opcao = 4;

				}
				break;
			case 5:
				cout << "Qual a classe do animal? ";
				cout << "1 - Mamifero" << endl;
				cout << "2 - Anfibio" << endl;
				cout << "3 - Reptil" << endl;
				cout << "4 - Ave Nativa" << endl;
				cout << "5 - Ave Exotica" << endl;
				cin >> opcao;
				switch(opcao){
					case 1:
						excluir(&map_mamiferos);
						break;
					case 2:
						excluir(&map_anfibios);
						break;
					case 3:
						excluir(&map_repteis);
						break;
					case 4:
						excluir(&map_avesNativas);
						break;
					case 5:
						excluir(&map_avesExoticas);
						break;
					default:
						cout << "Opcao invalida" << endl;
						opcao = 5;
				}
				break;
			case 6:
				cout << "Qual o cargo?" << endl;
				cout << "1 - Veterinario" << endl;
				cout << "2 - Tratador" << endl;
				cin >> opcao;
				switch(opcao){
					case 1:
						excluir(&map_veterinario);
						break;
					case 2:
						excluir(&map_tratador);
						break;
					default:
						cout << "Opcao invalida" << endl;
						opcao = 4;

				}
				break;
			case 0:
				opcao = 0;
				break;

			default:
				cout << "Opcao invalida" << endl;
				opcao = 99;

		}


	}

	write(&file_animals, &map_anfibios);
	write(&file_animals, &map_repteis);
	write(&file_animals, &map_mamiferos);
	write(&file_animals, &map_avesExoticas);
	write(&file_animals, &map_avesNativas);
	write(&file_funcionarios, &map_veterinario);
	write(&file_funcionarios, &map_tratador);


	file_animals.close();
	file_funcionarios.close();
	return 0;
}
