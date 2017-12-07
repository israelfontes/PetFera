#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <map>

#include "animal.hpp"

using namespace std;

string word(fstream * file){
	string word_return;
	char tmp;
	while( file->peek() != '\n' and file->peek() != ';' and !file->eof() ) {
		file->get(tmp);
		word_return += tmp;
	}
	file->get();
	cout << word_return << endl;
	return word_return;
}

u_int findTratador(int o){
	return 2;
}

u_int findVet(int o){
	return 3;
}


bool loadFuncionarios(fstream *file, map<int,Tratador> *tratadores, map<int,Veterinario> *veterinarios){
	while( !file->eof() ){
		int _id = stoi(word(file));
		string funcao = word(file);

		if(funcao == "Veterinario"){
			Veterinario funcionario;

			funcionario.setId(_id);
			funcionario.setNome(word(file));
			funcionario.setCpf(word(file));
			funcionario.setIdade(stoi(word(file)));
			funcionario.setTipoSanguineo(stoi(word(file)));
			funcionario.setFatorRH(word(file)[0]);
			funcionario.setEspecialidade(word(file));

			veterinarios->emplace(_id, funcionario);


		}else if(funcao == "Tratador"){
			Tratador funcionario;

			funcionario.setId(_id);
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

void writeFuncionarios(fstream *file, map<int,Tratador> *tratadores, map<int,Veterinario> *veterinarios){
	for(map<int,Tratador>::iterator it = tratadores->begin(); it!=tratadores->end(); ++it){
		*file << it->second.getId() << ";" << it->second.getNome() << ";" << it->second.getCpf() << ";" << it->second.getIdade() <<
			";" << it->second.getTipoSanguineo() << ";" << it->second.getFatorRH() << ";" << it->second.getEspecialidade() <<
			std::endl;
	}
	for(map<int,Veterinario>::iterator it = veterinarios->begin(); it!=veterinarios->end(); ++it){
		*file << it->second.getId() << ";" << it->second.getNome() << ";" << it->second.getCpf() << ";" << it->second.getIdade() <<
			";" << it->second.getTipoSanguineo() << ";" << it->second.getFatorRH() << ";" << it->second.getEspecialidade() <<
			std::endl;
	}
}

void writeAnimais(fstream *file, map<int,Anfibio> *anfibios, map<int,Reptil> *repteis,
	map<int,Mamifero> *mamiferos, map<int,AveNativa> *avesNativas, map<int,AveExotica> *avesExoticas){

	for(map<int,Anfibio>::iterator it = anfibios->begin(); it!= anfibios->end(); ++it){
		*file << (*it).second;
	}
	for(map<int,Reptil>::iterator it = repteis->begin(); it!= repteis->end(); ++it){
		*file << (*it).second;
	}
	for(map<int,Mamifero>::iterator it = mamiferos->begin(); it!= mamiferos->end(); ++it){
		*file << (*it).second;
	}
	for(map<int,AveNativa>::iterator it = avesNativas->begin(); it!= avesNativas->end(); ++it){
		*file << (*it).second;
	}
	for(map<int,AveExotica>::iterator it = avesExoticas->begin(); it!= avesExoticas->end(); ++it){
		*file << (*it).second;
	}
}

bool loadAnimals(fstream *file, map<int,Anfibio> *anfibios, map<int,Reptil> *repteis,
	map<int,Mamifero> *mamiferos, map<int,AveNativa> *avesNativas, map<int,AveExotica> *avesExoticas){

	while( !file->eof() and file->peek() != '\n'){
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
	Anfibio anfibio;
	Veterinario vet;
	cin >> vet;
	cout << vet;

	cin >> anfibio;
	cout << anfibio;
	fstream file_animals("data/out.csv", ios::out | ios::in);
	fstream file_funcionarios("data/data.csv", ios::out | ios::in);

	if(!file_animals || !file_funcionarios){
		cout << "não abriu" << endl;
	}
	//cout<< "abriu" << endl;
	loadAnimals(&file_animals, &map_anfibios, &map_repteis, &map_mamiferos, &map_avesNativas, &map_avesExoticas);
	writeAnimais(&file_funcionarios, &map_anfibios, &map_repteis, &map_mamiferos, &map_avesNativas, &map_avesExoticas);
	cout << map_mamiferos[1] << endl;
	cout << map_repteis.size() << endl;
	file_animals.close();
	file_funcionarios.close();
	return 0;
}
