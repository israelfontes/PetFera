#ifndef _ANIMAL_HPP_
#include <string>
#include "funcionario.hpp"

using std::string;

class Animal{
	private:
		int id;
		string classe;
		string nome;
		string cientifico;
		char sexo;
		float tamanho;
		string dieta;
		Veterinario veterinario;
		Tratador tratador;
		string batismo;
	
	public:

		Animal();
		Animal( int _id, string _classe, string _nome, string _cientifico, char _sexo,
			float _tamanho, string _dieta, Veterinario _veterinario, Tratador _tratador,
			string _batismo ): id(_id), classe(_classe), nome(_nome), cientifico(_cientifico),
			sexo(_sexo), tamanho(_tamanho), dieta(_dieta), veterinario(_veterinario), tratador(_tratador),
			batismo(_batismo){/* Empty */}

		int getId(void);
		string getClasse(void);
		string getNome(void);
		string getCientifico(void);
		char getSexo(void);
		float getTamanho(void);
		string getDieta(void);
		Veterinario getVeterinario(void);
		Tratador getTratador(void);
		string getBatismo(void);

		void setId( int _id );
		void setClasse( string _classe );
		void setNome( string _nome );
		void setCientifco( string _cientifico );
		void setSexo( char _sexo );
		void setTamanho( float _tamanho );
		void setDieta( string _dieta );
		void setVeterinario( Veterinario _veterinario );
		void setTratador( Tratador _tratador );
		void setBatismo( string _batismo );
};

class Anfibio : public Animal{
	private:
		int total_mudas;
		string ultima_muda;
	
	public:
		Anfibio(int _id, string _classe, string _nome, string _cientifico, char _sexo,
			float _tamanho, string _dieta, Veterinario _veterinario, Tratador _tratador,
			string _batismo, int _total, string _ultima): Animal(_id, _classe, _nome, _cientifico, _sexo,
			_tamanho, _dieta, _veterinario, _tratador, _batismo), total_mudas(_total),
			ultima_muda(_ultima){}

		int getTotalMudas(void);
		string getUltimaMuda(void);

		void setTotalMudas( int _total );
		void setUltimaMuda( string _ultima );
};

class Mamifero : public Animal{
	private:
		string cor_pelo;

	public:
		Mamifero(int _id, string _classe, string _nome, string _cientifico, char _sexo,
			float _tamanho, string _dieta, Veterinario _veterinario, Tratador _tratador,
			string _batismo, string _cor): Animal(_id, _classe, _nome, _cientifico, _sexo,
			_tamanho, _dieta, _veterinario, _tratador, _batismo), cor_pelo(_cor){}

		string getCorPelo(void);
		void setCorPelo( string _cor );
};

class Reptil : public Animal{
	private:
		bool venenoso;
		string tipo_veneno;

	public:
		Reptil(int _id, string _classe, string _nome, string _cientifico, char _sexo,
			float _tamanho, string _dieta, Veterinario _veterinario, Tratador _tratador,
			string _batismo, bool _venenoso, string _tipo): Animal(_id, _classe, _nome, _cientifico, _sexo,
			_tamanho, _dieta, _veterinario, _tratador, _batismo), venenoso(_venenoso), tipo_veneno(_tipo){}

		bool getVenenoso(void);
		string getTipoVeneno(void);

		void setVenenoso( bool _venenoso );
		void setTipoVeneno( string _tipo );
};

class Ave : public Animal{
	private:
		int tamanho_bico;
		int envergadura;
	public:
		Ave(int _id, string _classe, string _nome, string _cientifico, char _sexo,
			float _tamanho, string _dieta, Veterinario _veterinario, Tratador _tratador,
			string _batismo, int _tamanho_bico, int _envergadura) : Animal(_id, _classe, _nome,
			 _cientifico, _sexo, _tamanho, _dieta, _veterinario, _tratador, _batismo),
			tamanho_bico(_tamanho_bico), envergadura(_envergadura){}

		int getTamanhoBico(void);
		int getEnvergadura(void);

		void setTamanhoBico( int _tamanho );
		void setEnvergadura( int _envergadura );
};

class AnimalSilvestre{
	private:
		string ibama;
	public:
		AnimalSilvestre(string _ibama): ibama(_ibama){}
		string getIbama(void);
		void setIbama( string _ibama );
};

class Nativo : public AnimalSilvestre{
	private:
		string uf_origem;
		string autorizacao;
	public:
		Nativo(string _ibama, string _uf_origem, string _autorizacao): AnimalSilvestre(_ibama), 
			uf_origem(_uf_origem), autorizacao(_autorizacao){}

		string getUfOrigem(void);
		string getAutorizacao(void);

		void setUfOirigem( string _uf );
		void setAutorizacao( string _autorizacao ); 
};

class Exotico : public AnimalSilvestre{
	private:
		string pais_origem;
	
	public:
		Exotico(string _ibama, string _pais_origem): AnimalSilvestre(_ibama), pais_origem(_pais_origem){}
		string getPaisOrigem(void);
		void setPaisOrigem( string _pais );
};

class AveNativa : public Ave, public Nativo{
	public:
		AveNativa(int _id, string _classe, string _nome, string _cientifico, char _sexo,
			float _tamanho, string _dieta, Veterinario _veterinario, Tratador _tratador,
			string _batismo, int _tamanho_bico, int _envergadura, string _ibama, 
			string _uf_origem, string _autorizacao): Ave(id, _classe, _nome, _cientifico, _sexo,
			_tamanho, _dieta, _veterinario, _tratador, _batismo, _tamanho_bico, _envergadura), Nativo(_ibama,
			_uf_origem, _autorizacao){}

};

class AveExotica : public Ave, public Exotico{
	public:
		AveExotica(int _id, string _classe, string _nome, string _cientifico, char _sexo,
			float _tamanho, string _dieta, Veterinario _veterinario, Tratador _tratador,
			string _batismo, int _tamanho_bico, int _envergadura, string _ibama, string _pais_origem): 
			Ave(id, _classe, _nome, _cientifico, _sexo, _tamanho, _dieta, _veterinario, 
			_tratador, _batismo, _tamanho_bico, _envergadura), Exotico(_ibama, _pais_origem){}

};

#endif