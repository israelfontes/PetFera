#ifndef _ANIMAL_HPP_

#include "funcionario.hpp"

using std::string;

class Animal{
	private:
		u_int id;
		string classe;
		string nome;
		string cientifico;
		char sexo;
		float tamanho;
		string dieta;
		u_int veterinario;
		u_int tratador;
		string batismo;

		//virtual std::istream& read(std::istream&) const = 0;
		//virtual std::fstream& readf(std::fstream&) const = 0;

		virtual std::ostream& print(std::ostream&) const = 0;
		virtual std::fstream& printf(std::fstream&) const = 0;

	public:

		Animal(){}
		~Animal() = default;
		Animal( int _id, string _classe, string _nome, string _cientifico, char _sexo,
			float _tamanho, string _dieta, u_int _veterinario, u_int _tratador,
			string _batismo ): id(_id), classe(_classe), nome(_nome), cientifico(_cientifico),
			sexo(_sexo), tamanho(_tamanho), dieta(_dieta), veterinario(_veterinario), tratador(_tratador),
			batismo(_batismo){/* Empty */}

		u_int getId(void);
		string getClasse(void);
		string getNome(void);
		string getCientifico(void);
		char getSexo(void);
		float getTamanho(void);
		string getDieta(void);
		u_int getVeterinario(void);
		u_int getTratador(void);
		string getBatismo(void);

		void setId( u_int _id );
		void setClasse( string _classe );
		void setNome( string _nome );
		void setCientifico( string _cientifico );
		void setSexo( char _sexo );
		void setTamanho( float _tamanho );
		void setDieta( string _dieta );
		void setVeterinario( u_int _veterinario );
		void setTratador( u_int _tratador );
		void setBatismo( string _batismo );

		//friend std::istream& operator>> (std::istream &i, Animal animal);
		friend std::ostream& operator<< (std::ostream &o, Animal &animal);
		friend std::fstream& operator<< (std::fstream &f, Animal &animal);  
};

class Anfibio : public Animal{
	private:
		int total_mudas;
		string ultima_muda;
		std::ostream& print(std::ostream &o) const;
		std::fstream& printf(std::fstream&) const;
	
	public:
		Anfibio(){}
		~Anfibio() = default;
		Anfibio(u_int _id, string _classe, string _nome, string _cientifico, char _sexo,
			float _tamanho, string _dieta, u_int _veterinario, u_int _tratador,
			string _batismo, int _total, string _ultima): Animal(_id, _classe, _nome, _cientifico, _sexo,
			_tamanho, _dieta, _veterinario, _tratador, _batismo), total_mudas(_total),
			ultima_muda(_ultima){ /*Empty*/ }

		int getTotalMudas(void) const;
		string getUltimaMuda(void) const;

		void setTotalMudas( int _total );
		void setUltimaMuda( string _ultima );

		friend std::istream& operator>> (std::istream &i, Anfibio & animal);
};

class Mamifero : public Animal{
	private:
		string cor_pelo;
		std::ostream& print(std::ostream &o) const;
		std::fstream& printf(std::fstream&) const;

	public:
		Mamifero(){/* Empty */}
		~Mamifero() = default;

		Mamifero(u_int _id, string _classe, string _nome, string _cientifico, char _sexo,
			float _tamanho, string _dieta, u_int _veterinario, u_int _tratador,
			string _batismo, string _cor): Animal(_id, _classe, _nome, _cientifico, _sexo,
			_tamanho, _dieta, _veterinario, _tratador, _batismo), cor_pelo(_cor){/* Empty */}

		string getCorPelo(void) const;
		void setCorPelo( string _cor );
		friend std::istream& operator>> (std::istream &i, Mamifero &animal);
};

class Reptil : public Animal{
	private:
		bool venenoso;
		string tipo_veneno;
		std::ostream& print(std::ostream &o) const;
		std::fstream& printf(std::fstream&) const;

	public:
		Reptil(){/* Empty */}
		~Reptil() = default;
		
		Reptil(u_int _id, string _classe, string _nome, string _cientifico, char _sexo,
			float _tamanho, string _dieta, u_int _veterinario, u_int _tratador,
			string _batismo, bool _venenoso, string _tipo): Animal(_id, _classe, _nome, _cientifico, _sexo,
			_tamanho, _dieta, _veterinario, _tratador, _batismo), venenoso(_venenoso), tipo_veneno(_tipo){}

		bool getVenenoso(void) const;
		string getTipoVeneno(void) const;

		void setVenenoso( bool _venenoso );
		void setTipoVeneno( string _tipo );
		friend std::istream& operator>> (std::istream &i, Reptil &animal);
};

class Ave : public Animal{
	private:
		int tamanho_bico;
		int envergadura;

	public:
		Ave(){/* Empty */}
		~Ave() = default;
		Ave(u_int _id, string _classe, string _nome, string _cientifico, char _sexo,
			float _tamanho, string _dieta, u_int _veterinario, u_int _tratador,
			string _batismo, int _tamanho_bico, int _envergadura) : Animal(_id, _classe, _nome,
			 _cientifico, _sexo, _tamanho, _dieta, _veterinario, _tratador, _batismo),
			tamanho_bico(_tamanho_bico), envergadura(_envergadura){/* Empty */}

		int getTamanhoBico(void) const;
		int getEnvergadura(void) const;

		void setTamanhoBico( int _tamanho );
		void setEnvergadura( int _envergadura );
};

class AnimalSilvestre{
	private:
		string ibama;

	public:
		AnimalSilvestre(){ /* Empty */ }
		~AnimalSilvestre() = default;
		AnimalSilvestre(string _ibama): ibama(_ibama){}
		string getIbama(void) const;
		void setIbama( string _ibama );
};

class Nativo : public AnimalSilvestre{
	private:
		string uf_origem;
		string autorizacao;
	
	public:
		Nativo(){/* Empty */}
		~Nativo() = default;
		Nativo(string _ibama, string _uf_origem, string _autorizacao): AnimalSilvestre(_ibama), 
			uf_origem(_uf_origem), autorizacao(_autorizacao){}

		string getUfOrigem(void) const;
		string getAutorizacao(void) const;

		void setUfOrigem( string _uf );
		void setAutorizacao( string _autorizacao ); 
};

class Exotico : public AnimalSilvestre{
	private:
		string pais_origem;

	public:
		Exotico(){/* Empty */}
		~Exotico() = default;
		Exotico(string _ibama, string _pais_origem): AnimalSilvestre(_ibama), pais_origem(_pais_origem){}
		string getPaisOrigem(void) const;
		void setPaisOrigem( string _pais );
};

class AveNativa : public Ave, public Nativo{
	private:
		std::ostream& print(std::ostream &o) const;
		std::fstream& printf(std::fstream&) const;
	public:
		AveNativa(){/* Empty */}

		~AveNativa() = default;
		
		AveNativa(u_int _id, string _classe, string _nome, string _cientifico, char _sexo,
			float _tamanho, string _dieta, u_int _veterinario, u_int _tratador,
			string _batismo, int _tamanho_bico, int _envergadura, string _ibama, 
			string _uf_origem, string _autorizacao): 
			Ave(_id, _classe, _nome, _cientifico, _sexo, _tamanho, _dieta, _veterinario, _tratador, 
			_batismo, _tamanho_bico, _envergadura), Nativo(_ibama, _uf_origem, _autorizacao){/* Empty */}

		friend std::istream& operator>> (std::istream &i, AveNativa &animal);

};

class AveExotica : public Ave, public Exotico{
	private:
		std::ostream& print(std::ostream &o) const;
		std::fstream& printf(std::fstream&) const;
	public:
		AveExotica(){/* Empty */}

		~AveExotica() = default;
		
		AveExotica(u_int _id, string _classe, string _nome, string _cientifico, char _sexo,
			float _tamanho, string _dieta, u_int _veterinario, u_int _tratador,
			string _batismo, int _tamanho_bico, int _envergadura, string _tipo, string _ibama, string _pais_origem): 
			Ave(_id, _classe, _nome, _cientifico, _sexo, _tamanho, _dieta, _veterinario, 
			_tratador, _batismo, _tamanho_bico, _envergadura), Exotico(_ibama, _pais_origem){/* Empty */}

		friend std::istream& operator>> (std::istream &i, AveExotica &animal);
};

#endif