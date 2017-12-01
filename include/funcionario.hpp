#ifndef _FUNCIONARIO_HPP_
#include <string>

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
		Funcionario(int _id, string _nome, string _cpf, short _idade, short _tipo 
			char _fator, string _especialidade): id(_id), nome(_nome), cpf(_cpf), 
		idade(_idade), tipo_sanguineo(_tipo), fatorRH(_fator), especialidade(_especialidade){}
		
		int getId(void);
		string getNome(void);
		string getCpf(void);
		short getIdade(void);
		short getTipoSanguineo(void);
		char getFatorRH(void);
		string getEspecialidade(void);

		void setId( int _id );
		void setNome( string _nome );
		void setCpf( string _cpf );
		void setIdade( short _idade );
		void setTipoSanguineo( short _tipo );
		void setFatorRH( char _fator );
		void setEspecialidade( string _especialidade );		
};

class Veterinario : public Funcionario{

};

class Tratador : public	Funcionario{

};

#endif