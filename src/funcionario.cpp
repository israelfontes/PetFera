#include "funcionario.hpp"

int Funcionario::getId(void){ return id; }

string Funcionario::getNome(void){ return nome; }

string Funcionario::getCpf(void){ return cpf; }

short Funcionario::getIdade(void){ return idade; }

short Funcionario::getTipoSanguineo(void){ return tipo_sanguineo; }

char Funcionario::getFatorRH(void){ return fatorRH; }

string Funcionario::getEspecialidade(void){ return especialidade; }

void Funcionario::setId( int _id ){ id = _id;}

void Funcionario::setNome( string _nome ){ nome = _nome; }

void Funcionario::setCpf( string _cpf ){ cpf = _cpf; }

void Funcionario::setIdade( short _idade ){ idade = _idade; }

void Funcionario::setTipoSanguineo( short _tipo ){ tipo_sanguineo = _tipo; }

void Funcionario::setFatorRH( char _fator ){ fatorRH = _fator; }

void Funcionario::setEspecialidade( string _especialidade ){ especialidade = _especialidade; }	