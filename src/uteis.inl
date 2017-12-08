
#include "uteis.hpp"

u_int findTratador(int o){
	return 2;
}

u_int findVet(int o){
	return 3;
}

string Uteis::word(fstream * file){
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

bool Uteis::loadFuncionarios(fstream *file, map<int,Tratador> *tratadores, map<int,Veterinario> *veterinarios){
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

template <typename T>
void Uteis::write(fstream *file, map<int,T> *objeto){
	for(auto it = objeto->begin(); it!= objeto->end(); ++it){
		*file << it->second;
	}
}

bool Uteis::loadAnimals(fstream *file, map<int,Anfibio> *anfibios, map<int,Reptil> *repteis,
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

template <typename T>
void Uteis::cadastrar(map<int,T> * map){
	T new_cadastro;
	std::cin >> new_cadastro;
	map->emplace(new_cadastro.getId(), new_cadastro);
}

template <typename T>
bool Uteis::excluir(map<int, T> * map){
	int id;
	std::cout << "Digite o ID do objeto a ser excluido: ";
	std::cin >> id;
	auto it = map->find(id);
	if(it == map->end()){
		std::cout << "Não encontrado." << std::endl;
		return false;
	}
	map->erase(it);
	std::cout << "Excluido." << std::endl;
	return true;
}

template<typename T>
bool Uteis::consultar(map<int, T> * map){
	int id;
	std::cout << "Digite o ID a ser procurado: ";
	std::cin >> id;
	auto it = map->find(id);
	if(it == map->end()){
		std::cout << "Não encontrado." << std::endl;
		return false;
	}
	std::cout << it->second;
	return true;
}	