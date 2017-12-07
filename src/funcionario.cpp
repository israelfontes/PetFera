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