#include "animal.hpp"

u_int Animal::getId(void){ return id; }

string Animal::getClasse(void){ return classe; }

string Animal::getNome(void){ return nome; }

string Animal::getCientifico(void){ return cientifico; }

char Animal::getSexo(void){ return sexo; }

float Animal::getTamanho(void){ return tamanho; }

string Animal::getDieta(void){ return dieta; }

u_int Animal::getVeterinario(void){ return veterinario; }

u_int Animal::getTratador(void){ return tratador; }

string Animal::getBatismo(void){ return batismo; }

void Animal::setId( u_int _id ){ id = _id; }

void Animal::setClasse( string _classe ){ classe = _classe; }

void Animal::setNome( string _nome ){ nome = _nome; }

void Animal::setCientifico( string _cientifico ){ cientifico = _cientifico; }

void Animal::setSexo( char _sexo ){ sexo = _sexo; }

void Animal::setTamanho( float _tamanho ){ tamanho = _tamanho; }

void Animal::setDieta( string _dieta ){ dieta = _dieta; }

void Animal::setVeterinario( u_int _veterinario ){ veterinario = _veterinario; }

void Animal::setTratador( u_int _tratador ){ tratador = _tratador; }

void Animal::setBatismo( string _batismo ){ batismo = _batismo; }



int Anfibio::getTotalMudas(void) const{ return total_mudas; }

string Anfibio::getUltimaMuda(void) const{ return ultima_muda; }

void Anfibio::setTotalMudas( int _total ){ total_mudas = _total; }

void Anfibio::setUltimaMuda( string _ultima ){ ultima_muda = _ultima; }



string Mamifero::getCorPelo(void) const{ return cor_pelo; }

void Mamifero::setCorPelo( string _cor ){ cor_pelo = _cor; }


bool Reptil::getVenenoso(void) const{ return venenoso; }

string Reptil::getTipoVeneno(void) const{ return tipo_veneno; }

void Reptil::setVenenoso( bool _venenoso ){ venenoso = _venenoso; }

void Reptil::setTipoVeneno( string _tipo){ tipo_veneno = _tipo; }



int Ave::getTamanhoBico(void) const{ return tamanho_bico; }

int Ave::getEnvergadura(void) const{ return envergadura; }

void Ave::setTamanhoBico( int _tamanho ){ tamanho_bico = _tamanho; }

void Ave::setEnvergadura( int _envergadura ){ envergadura = _envergadura; }



string AnimalSilvestre::getIbama(void) const{ return ibama; }

void AnimalSilvestre::setIbama( string _ibama ){ ibama = _ibama; }



string Nativo::getUfOrigem(void) const{ return uf_origem; }

string Nativo::getAutorizacao(void) const{ return autorizacao; }

void Nativo::setUfOrigem( string _uf ){ uf_origem = _uf; }

void Nativo::setAutorizacao( string _autorizacao ){ autorizacao = _autorizacao; }



string Exotico::getPaisOrigem(void) const{ return pais_origem; }

void Exotico::setPaisOrigem( string _pais ){ pais_origem = _pais; }

std::ostream& operator<<(std::ostream &o, Animal &animal){
	o 	<< "ID: " << animal.getId() << std::endl
		<< "Classe: " << animal.getClasse() << std::endl
		<< "Nome: " << animal.getNome() << std::endl
		<< "Nome cientifico: " << animal.getCientifico() << std::endl
		<< "Sexo: " << animal.getSexo() << std::endl
		<< "Tamanho: " << animal.getTamanho() << "m" << std::endl
		<< "Dieta: " << animal.getDieta() << std::endl
		<< "Cod. veterinario: " << animal.getVeterinario() << std::endl
		<< "Cod. tratador: " << animal.getTratador() << std::endl
		<< "Nome de Batismo: " << animal.getBatismo() << std::endl;
		return animal.print(o);
}

std::ostream& Anfibio::print(std::ostream &o) const{
	o 	<< "Total de mudas: " << this->getTotalMudas() << std::endl
		<< "Ultima muda: " << this->getUltimaMuda() << std::endl;
	return o;
}

std::ostream& Mamifero::print(std::ostream &o) const{
	o << "Cor do pelo: " << this->getCorPelo() << std::endl;
	return o;
}

std::ostream& AveNativa::print(std::ostream &o) const{
	o 	<< "Tamanho do bico: " << this->getTamanhoBico() << "cm" << std::endl
		<< "Envergadura: " << this->getEnvergadura() << "cm" << std::endl
		<< "Ibama: " << this->getIbama() << std::endl
		<< "UF: " << this->getUfOrigem() << std::endl
		<< "Autorizacao: " << this->getAutorizacao() << std::endl;
		return o;
}

std::ostream& AveExotica::print(std::ostream &o) const{
	o 	<< "Tamanho do bico: " << this->getTamanhoBico() << "cm" << std::endl
		<< "Envergadura: " << this->getEnvergadura() << "cm" << std::endl
		<< "Ibama: " << this->getIbama() << std::endl
		<< "Pais: " << this->getPaisOrigem() << std::endl;
		return o;
}

std::ostream& Reptil::print(std::ostream &o) const{
	o 	<< "Venenoso: ";
	if(this->getVenenoso()) {
		o 	<< "Sim" << std::endl
			<< "Tipo do veneno: " << this->getTipoVeneno() << std::endl;
	}else{ o << "Não" << std::endl; }
	return o;
}


std::fstream& operator<<(std::fstream &f, Animal &animal){
	f   << animal.getId() << ";"
		<< animal.getClasse() << ";"
		<< animal.getNome() << ";"
		<< animal.getCientifico() << ";"
		<< animal.getSexo() << ";"
		<< animal.getTamanho() << ";"
		<< animal.getDieta() << ";"
		<< animal.getVeterinario() << ";"
		<< animal.getTratador() << ";"
		<< animal.getBatismo() << ";";

		return animal.printf(f);
}

std::fstream& Anfibio::printf(std::fstream &f) const{
	f 	<< this->getTotalMudas() << ";"
		<< this->getUltimaMuda() << std::endl;
	return f;
}

std::fstream& Mamifero::printf(std::fstream &f) const{
	f << this->getCorPelo() << std::endl;
	return f;
}

std::fstream& AveNativa::printf(std::fstream &f) const{
	f 	<< this->getTamanhoBico() << ";"
		<< this->getEnvergadura() << ";"
		<< this->getIbama() << ";"
		<< this->getUfOrigem() << ";"
		<< this->getAutorizacao() << std::endl;
		return f;
}

std::fstream& AveExotica::printf(std::fstream &f) const{
	f 	<< this->getTamanhoBico() << ";"
		<< this->getEnvergadura() << ";"
		<< this->getIbama() << ";"
		<< this->getPaisOrigem() << std::endl;
		return f;
}

std::fstream& Reptil::printf(std::fstream &f) const{
	f 	<< this->getVenenoso() << ";"
		<< this->getTipoVeneno() << ";" << std::endl;

	return f;
}

std::istream& operator>>(std::istream &i, Anfibio &animal){
	using std::cout;
	using std::getline;

	std::string tmp;
	cout << "ID ? ";
	getline(i, tmp);
	animal.setId(stoi(tmp));
	cout << "Nome ? ";
	getline(i, tmp);
	animal.setNome(tmp);
	cout << "Classe ? ";
	getline(i, tmp);
	animal.setClasse(tmp);
	cout << "Nome cientifico ? ";
	getline(i, tmp);
	animal.setCientifico(tmp);
	cout << "Sexo ? ";
	getline(i, tmp);
	animal.setSexo(tmp[0]);
	cout << "Tamanho ? ";
	getline(i, tmp);
	animal.setTamanho(stof(tmp));
	cout << "Dieta ? ";
	getline(i, tmp);
	animal.setDieta(tmp);
	cout << "Cod. Veterinario ? ";
	getline(i, tmp);
	animal.setVeterinario(stoi(tmp));
	cout << "Cod. Tratador ? ";
	getline(i, tmp);
	animal.setTratador(stoi(tmp));
	cout << "Nome de batismo ? ";
	getline(i, tmp);
	animal.setBatismo(tmp);
	cout << "Total de mudas ? ";
	getline(i, tmp);
	animal.setTotalMudas(stoi(tmp));
	cout << "Data da ultima muda ? ";
	getline(i, tmp);
	animal.setUltimaMuda(tmp);

	return i;
}

std::istream& operator>> (std::istream &i, Mamifero &animal){
	using std::cout;
	using std::getline;

	std::string tmp;
	cout << "ID ? ";
	getline(i, tmp);
	animal.setId(stoi(tmp));
	cout << "Nome ? ";
	getline(i, tmp);
	animal.setNome(tmp);
	cout << "Classe ? ";
	getline(i, tmp);
	animal.setClasse(tmp);
	cout << "Nome cientifico ? ";
	getline(i, tmp);
	animal.setCientifico(tmp);
	cout << "Sexo ? ";
	getline(i, tmp);
	animal.setSexo(tmp[0]);
	cout << "Tamanho ? ";
	getline(i, tmp);
	animal.setTamanho(stof(tmp));
	cout << "Dieta ? ";
	getline(i, tmp);
	animal.setDieta(tmp);
	cout << "Cod. Veterinario ? ";
	getline(i, tmp);
	animal.setVeterinario(stoi(tmp));
	cout << "Cod. Tratador ? ";
	getline(i, tmp);
	animal.setTratador(stoi(tmp));
	cout << "Nome de batismo ? ";
	getline(i, tmp);
	animal.setBatismo(tmp);
	cout << "Cor do Pelo ? ";
	getline(i,tmp);
	animal.setCorPelo(tmp);

	return i;
}


std::istream& operator>> (std::istream &i, Reptil &animal){
	using std::cout;
	using std::getline;

	std::string tmp;
	cout << "ID ? ";
	getline(i, tmp);
	animal.setId(stoi(tmp));
	cout << "Nome ? ";
	getline(i, tmp);
	animal.setNome(tmp);
	cout << "Classe ? ";
	getline(i, tmp);
	animal.setClasse(tmp);
	cout << "Nome cientifico ? ";
	getline(i, tmp);
	animal.setCientifico(tmp);
	cout << "Sexo ? ";
	getline(i, tmp);
	animal.setSexo(tmp[0]);
	cout << "Tamanho ? ";
	getline(i, tmp);
	animal.setTamanho(stof(tmp));
	cout << "Dieta ? ";
	getline(i, tmp);
	animal.setDieta(tmp);
	cout << "Cod. Veterinario ? ";
	getline(i, tmp);
	animal.setVeterinario(stoi(tmp));
	cout << "Cod. Tratador ? ";
	getline(i, tmp);
	animal.setTratador(stoi(tmp));
	cout << "Nome de batismo ? ";
	getline(i, tmp);
	animal.setBatismo(tmp);
	cout << "Venenoso ? (1 ou 0)";
	getline(i, tmp);
	animal.setVenenoso(stoi(tmp));
	cout << "Tipo de veneno ? ";
	getline(i, tmp);
	animal.setTipoVeneno(tmp);

	return i;
}

std::istream& operator>> (std::istream &i, AveNativa &animal){
	using std::cout;
	using std::getline;

	std::string tmp;
	cout << "ID ? ";
	getline(i, tmp);
	animal.setId(stoi(tmp));
	cout << "Nome ? ";
	getline(i, tmp);
	animal.setNome(tmp);
	cout << "Classe ? ";
	getline(i, tmp);
	animal.setClasse(tmp);
	cout << "Nome cientifico ? ";
	getline(i, tmp);
	animal.setCientifico(tmp);
	cout << "Sexo ? ";
	getline(i, tmp);
	animal.setSexo(tmp[0]);
	cout << "Tamanho ? ";
	getline(i, tmp);
	animal.setTamanho(stof(tmp));
	cout << "Dieta ? ";
	getline(i, tmp);
	animal.setDieta(tmp);
	cout << "Cod. Veterinario ? ";
	getline(i, tmp);
	animal.setVeterinario(stoi(tmp));
	cout << "Cod. Tratador ? ";
	getline(i, tmp);
	animal.setTratador(stoi(tmp));
	cout << "Nome de batismo ? ";
	getline(i, tmp);
	animal.setBatismo(tmp);
	cout << "Tamanho do bico ? ";
	getline(i, tmp);
	animal.setTamanhoBico(stof(tmp));
	cout << "Envergadura ? ";
	getline(i, tmp);
	animal.setEnvergadura(stof(tmp));
	cout << "Ibama ? ";
	getline(i, tmp);
	animal.setIbama(tmp);
	cout << "UF ? ";
	getline(i, tmp);
	animal.setUfOrigem(tmp);
	cout << "Autorizacao ? ";
	getline(i, tmp);
	animal.setAutorizacao(tmp);

	return i;
}

std::istream& operator>> (std::istream &i, AveExotica &animal){
	using std::cout;
	using std::getline;

	std::string tmp;
	cout << "ID ? ";
	getline(i, tmp);
	animal.setId(stoi(tmp));
	cout << "Nome ? ";
	getline(i, tmp);
	animal.setNome(tmp);
	cout << "Classe ? ";
	getline(i, tmp);
	animal.setClasse(tmp);
	cout << "Nome cientifico ? ";
	getline(i, tmp);
	animal.setCientifico(tmp);
	cout << "Sexo ? ";
	getline(i, tmp);
	animal.setSexo(tmp[0]);
	cout << "Tamanho ? ";
	getline(i, tmp);
	animal.setTamanho(stof(tmp));
	cout << "Dieta ? ";
	getline(i, tmp);
	animal.setDieta(tmp);
	cout << "Cod. Veterinario ? ";
	getline(i, tmp);
	animal.setVeterinario(stoi(tmp));
	cout << "Cod. Tratador ? ";
	getline(i, tmp);
	animal.setTratador(stoi(tmp));
	cout << "Nome de batismo ? ";
	getline(i, tmp);
	animal.setBatismo(tmp);
	cout << "Tamanho do bico ? ";
	getline(i, tmp);
	animal.setTamanhoBico(stof(tmp));
	cout << "Envergadura ? ";
	getline(i, tmp);
	animal.setEnvergadura(stof(tmp));
	cout << "Ibama ? ";
	getline(i, tmp);
	animal.setIbama(tmp);
	cout << "Pais origem ? ";
	getline(i, tmp);
	animal.setPaisOrigem(tmp);

	return i;
}