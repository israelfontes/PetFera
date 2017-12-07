#include "funcionario.hpp"

int Funcionario::getId(void) const{ return id; }

string Funcionario::getNome(void) const{ return nome; }

string Funcionario::getCpf(void) const{ return cpf; }

short Funcionario::getIdade(void) const{ return idade; }

short Funcionario::getTipoSanguineo(void) const{ return tipo_sanguineo; }

char Funcionario::getFatorRH(void) const{ return fatorRH; }

string Funcionario::getEspecialidade(void) const{ return especialidade; }

void Funcionario::setId( int _id ){ id = _id;}

void Funcionario::setNome( string _nome ){ nome = _nome; }

void Funcionario::setCpf( string _cpf ){ cpf = _cpf; }

void Funcionario::setIdade( short _idade ){ idade = _idade; }

void Funcionario::setTipoSanguineo( short _tipo ){ tipo_sanguineo = _tipo; }

void Funcionario::setFatorRH( char _fator ){ fatorRH = _fator; }

void Funcionario::setEspecialidade( string _especialidade ){ especialidade = _especialidade; }

std::ostream& operator<< (std::ostream &o, Funcionario &funcionario){
	o 	<< "ID: " << funcionario.getId() << std::endl
		<< "Nome: " << funcionario.getNome() << std::endl
		<< "CPF: " << funcionario.getCpf() << std::endl
		<< "Idade: " << funcionario.getIdade() << std::endl
		<< "Tipo Sanguineo: " << funcionario.getTipoSanguineo() << std::endl
		<< "Fator RH: " << funcionario.getFatorRH() << std::endl
		<< "Especialidade: " << funcionario.getEspecialidade() << std::endl;
		return o;
}

std::istream& operator>> (std::istream &i, Funcionario &funcionario){
	using std::cout;
	using std::getline;

	std::string tmp;
	cout << "ID ? ";
	getline(i,tmp);
	funcionario.setId(stoi(tmp));
	cout << "Nome ? ";
	getline(i,tmp);
	funcionario.setNome(tmp);
	cout << "CPF ? ";
	getline(i,tmp);
	funcionario.setCpf(tmp);
	cout << "Idade ? ";
	getline(i,tmp);
	funcionario.setIdade(stoi(tmp));
	cout << "Tipo Sanguineo ? ";
	getline(i,tmp);
	funcionario.setTipoSanguineo(stoi(tmp));
	cout << "Fator RH ? ";
	getline(i,tmp);
	funcionario.setFatorRH(tmp[0]);
	cout << "Especialidade ? ";
	getline(i,tmp);
	funcionario.setEspecialidade(tmp);

	return i;
}