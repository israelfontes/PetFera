#ifndef _FUNCIONARIO_HPP_
#include <string>
#include <fstream>
#include <iostream>

using std::string;

class Funcionario{
	private:
		int id;
		string nome;
		string cpf;
		short idade;
		short tipo_sanguineo;
		char fatorRH;
		string especialidade;

	public:
		Funcionario(){}
		~Funcionario() = default;
		Funcionario(int _id, string _nome, string _cpf, short _idade, short _tipo, 
			char _fator, string _especialidade): id(_id), nome(_nome), cpf(_cpf), 
		idade(_idade), tipo_sanguineo(_tipo), fatorRH(_fator), especialidade(_especialidade){}
		
		int getId(void) const;
		string getNome(void) const;
		string getCpf(void) const;
		short getIdade(void) const;
		short getTipoSanguineo(void) const;
		char getFatorRH(void) const;
		string getEspecialidade(void) const;

		void setId( int _id );
		void setNome( string _nome );
		void setCpf( string _cpf );
		void setIdade( short _idade );
		void setTipoSanguineo( short _tipo );
		void setFatorRH( char _fator );
		void setEspecialidade( string _especialidade );		
		friend std::ostream& operator<< (std::ostream &o, Funcionario &funcionario);
		friend std::istream& operator>> (std::istream &i, Funcionario &funcionario);
};

class Veterinario : public Funcionario{
	public: Veterinario(){}
};

class Tratador : public	Funcionario{
	public: Tratador(){}
};

#endif