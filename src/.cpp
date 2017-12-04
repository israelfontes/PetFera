#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <map>

#include "../include/animal.hpp"

using namespace std;

string word(ifstream * file){
	string word_return;
	char tmp;	
	while( file->get(tmp) and tmp != '\n' and tmp != ';' ) word_return += tmp;

	return word_return;
}

bool loadAnimals(ifstream * file){
	map<int,Anfibio> anfibios;
	map<int,Reptil> repteis;
	map<int,Mamifero> mamiferos;
	map<int,AveNativa> avesNativas;
	map<int,AveExotica> avesExoticas;

	try{
		while( !file->eof() ){
		int _id = stoi(word(file));
		string classe = word(file);
		switch (classe){
			case "Amphibia":
				Anfibio animal;
			
				animal.setId(_id);
				animal.setClasse(classe);
				animal.setNome(word(file));
				animal.setCientifico(word(file));
				animal.setSexo(word(file));
				animal.setTamanho(stof(word(file)));
				animal.setDieta(word(file));
				animal.setVeterinario(findVet(stoi(word(file))));
				animal.setTratador(findTratador(stoi(word(file))));
				animal.setBatismo(word(file));
				animal.setTotalMudas(stoid(word(file)));
				animal.setUltimaMuda(word(file));

				anfibios.emplace(_id, animal);

				break;
			case "Reptilia":
				Reptil animal;
				
				animal.setId(_id);
				animal.setClasse(classe);
				animal.setNome(word(file));
				animal.setCientifico(word(file));
				animal.setSexo(word(file));
				animal.setTamanho(stof(word(file)));
				animal.setDieta(word(file));
				animal.setVeterinario(findVet(stoi(word(file))));
				animal.setTratador(findTratador(stoi(word(file))));
				animal.setBatismo(word(file));
				animal.setVenenoso(stoid(word(file)));
				animal.setTipoVeneno(word(file));

				repteis.emplace(_id, animal);

				break;
			/*case "Aves":			

				animal.setId(_id);
				animal.setClasse(classe);
				animal.setNome(word(file));
				animal.setCientifico(word(file));
				animal.setSexo(word(file));
				animal.setTamanho(stof(word(file)));
				animal.setDieta(word(file));
				animal.setVeterinario(word(file));
				animal.setTratador(word(file));
				animal.setBatismo(word(file));
				animal.setTamanhoBico(stoid(word(file)));
				animal.setEnvergadura(stoid(word(file)));

				break;*/
			case "Mammalia":
				Mamifero animal;

				animal.setId(_id);
				animal.setClasse(classe);
				animal.setNome(word(file));
				animal.setCientifico(word(file));
				animal.setSexo(word(file));
				animal.setTamanho(stof(word(file)));
				animal.setDieta(word(file));
				animal.setVeterinario(word(file));
				animal.setTratador(word(file));
				animal.setBatismo(word(file));
				animal.setCorPelo(word(file));

				mamiferos.emplace(_id, animal);

				break;
			default:
				break;
		}

		}	
	}catch{

	}
}


map<int,Animal> mymap;

int main(void){

	ifstream file("data.csv");
	if(!file) cout << "erro" << endl;
	while(!file.eof()) cout << "..." << word(&file) << endl;

	//mymap.emplace(1,animal);
	cout << mymap[1] ;
	return 0;
}
