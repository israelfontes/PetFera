#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <map>

#include "animal.hpp"

using namespace std;

string word(ifstream * file){
	string word_return;
	char tmp;	
	while( file->get(tmp) and tmp != '\n' and tmp != ';' ) word_return += tmp;
	cout << word_return << endl;
	return word_return;
}

Tratador findTratador(int o){
	Tratador tap;
	return tap;
}

Veterinario findVet(int o){
	Veterinario v;
	return v;
}
bool loadFuncionarios(ifstream *file, map<int,Tratador> *tratadores, map<int,Veterinario> *veterinarios){
	while( !file->eof() ){
		int _id = stoi(word(file));
		string funcao = word(file);

		if(funcao == "Veterinario"){
			Veterinario funcionario;

			funcionario.setNome(word(file));
			funcionario.setCpf(word(file));
			funcionario.setIdade(stoi(word(file)));
			funcionario.setTipoSanguineo(stoi(word(file)));
			funcionario.setFatorRH(word(file)[0]);
			funcionario.setEspecialidade(word(file));

			veterinarios->emplace(_id, funcionario);


		}else if(funcao == "Tratador"){
			Tratador funcionario;

			funcionario.setNome(word(file));
			funcionario.setCpf(word(file));
			funcionario.setIdade(stoi(word(file)));
			funcionario.setTipoSanguineo(stoi(word(file)));
			funcionario.setFatorRH(word(file)[0]);
			funcionario.setEspecialidade(word(file));
			
			tratadores->emplace(_id, funcionario);

		}
	}
	return false;
}

bool loadAnimals(ifstream *file, map<int,Anfibio> *anfibios, map<int,Reptil> *repteis,
	map<int,Mamifero> *mamiferos, map<int,AveNativa> *avesNativas, map<int,AveExotica> *avesExoticas){

	while( !file->eof() ){
		
		int _id = stoi(word(file));
		string classe = word(file);

			if(classe == "Amphibia"){
				Anfibio animal;
			
				animal.setId(_id);
				animal.setClasse(classe);
				animal.setNome(word(file));
				animal.setCientifico(word(file));
				animal.setSexo(word(file)[0]);
				animal.setTamanho(stof(word(file)));
				animal.setDieta(word(file));
				animal.setVeterinario(findVet(stoi(word(file))));
				animal.setTratador(findTratador(stoi(word(file))));
				animal.setBatismo(word(file));
				animal.setTotalMudas(stoi(word(file)));
				animal.setUltimaMuda(word(file));

				anfibios->emplace(_id, animal);
			
			}else if(classe == "Reptilia"){

				Reptil animal;
				
				animal.setId(_id);
				animal.setClasse(classe);
				animal.setNome(word(file));
				animal.setCientifico(word(file));
				animal.setSexo(word(file)[0]);
				animal.setTamanho(stof(word(file)));
				animal.setDieta(word(file));
				animal.setVeterinario(findVet(stoi(word(file))));
				animal.setTratador(findTratador(stoi(word(file))));
				animal.setBatismo(word(file));
				animal.setVenenoso(stoi(word(file)));
				animal.setTipoVeneno(word(file));

				repteis->emplace(_id, animal);

			}else if(classe == "AveNativa"){
				AveNativa animal;

				animal.setId(_id);
				animal.setClasse(classe);
				animal.setNome(word(file));
				animal.setCientifico(word(file));
				animal.setSexo(word(file)[0]);
				animal.setTamanho(stof(word(file)));
				animal.setDieta(word(file));
				animal.setVeterinario(findVet(stoi(word(file))));
				animal.setTratador(findTratador(stoi(word(file))));
				animal.setBatismo(word(file));
				animal.setTamanhoBico(stoi(word(file)));
				animal.setEnvergadura(stoi(word(file)));
				animal.setIbama(word(file));
				animal.setUfOrigem(word(file));
				animal.setAutorizacao(word(file));
				
				avesNativas->emplace(_id, animal);

			}else if(classe == "AveExotica"){
				AveExotica animal;

				animal.setId(_id);
				animal.setClasse(classe);
				animal.setNome(word(file));
				animal.setCientifico(word(file));
				animal.setSexo(word(file)[0]);
				animal.setTamanho(stof(word(file)));
				animal.setDieta(word(file));
				animal.setVeterinario(findVet(stoi(word(file))));
				animal.setTratador(findTratador(stoi(word(file))));
				animal.setBatismo(word(file));
				animal.setTamanhoBico(stoi(word(file)));
				animal.setEnvergadura(stoi(word(file)));
				animal.setIbama(word(file));
				animal.setPaisOrigem(word(file));

				avesExoticas->emplace(_id, animal);
			
			}else if(classe == "Mammalia"){
				Mamifero animal;

				animal.setId(_id);
				animal.setClasse(classe);
				animal.setNome(word(file));
				animal.setCientifico(word(file));
				animal.setSexo(word(file)[0]);
				animal.setTamanho(stof(word(file)));
				animal.setDieta(word(file));
				animal.setVeterinario(findVet(stoi(word(file))));
				animal.setTratador(findTratador(stoi(word(file))));
				animal.setBatismo(word(file));
				animal.setCorPelo(word(file));

				mamiferos->emplace(_id, animal);
		}

	}
	return false;	
}


map<int,Anfibio> map_anfibios;
map<int,Reptil> map_repteis;
map<int,Mamifero> map_mamiferos;
map<int,AveNativa> map_avesNativas;
map<int,AveExotica> map_avesExoticas;

map<int,Tratador> map_tratador;
map<int,Veterinario> map_veterinario;

int main(void){

	ifstream file("data/data.csv");
	if(!file){
		cout << "não abriu" << endl;
	}
	//cout<< "abriu" << endl;
	loadAnimals(&file, &map_anfibios, &map_repteis, &map_mamiferos, &map_avesNativas, &map_avesExoticas);
	cout << map_mamiferos.size() << endl;
	cout << map_repteis.size() << endl;
	return 0;
}
