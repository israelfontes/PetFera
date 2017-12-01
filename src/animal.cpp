#include "animal.hpp"

int Animal::getId(void){ return id; }

string Animal::getClasse(void){ return classe; }

string Animal::getNome(void){ return nome; }

string Animal::getCientifico(void){ return cientifico; }

char Animal::getSexo(void){ return sexo; }

float Animal::getTamanho(void){ return getTamanho; }

string Animal::getDieta(void){ return dieta; }

Veterinario Animal::getVeterinario(void){ return veterinario; }

Tratador Animal::getTratador(void){ return tratador; }

string Animal::getBatismo(void){ return batismo; }

void Animal::setId( int _id ){ id = _id; }

void Animal::setClasse( string _classe ){ classe = _classe; }

void Animal::setNome( string _nome ){ nome = _nome; }

void Animal::setCientifco( string _cientifico ){ cientifico = _cientifico; }

void Animal::setSexo( char _sexo ){ sexo = _sexo; }

void Animal::setTamanho( float _tamanho ){ tamanho = _tamanho; }

void Animal::setDieta( string _dieta ){ dieta = _dieta; }

void Animal::setVeterinario( Veterinario _veterinario ){ veterinario = _veterinario; }

void Animal::setTratador( Tratador _tratador ){ tratador = _tratador; }

void Animal::setBatismo( string _batismo ){ batismo = _batismo; }



int Anfibio::getTotalMudas(void){ return total_mudas; }

string Anfibio::getUltimaMuda(void){ return ultima_muda; }

void Anfibio::setTotalMudas( int _total ){ total_mudas = _total; }

void Anfibio::setUltimaMuda( string _ultima ){ ultima_muda = _ultima; }



string Mamifero::getCorPelo(void){ return cor_pelo; }

void Mamifero::setCorPelo( string _cor ){ cor_pelo = _cor; }



bool Reptil::getVenenoso(void){ return venenoso; }

string Reptil::getTipoVeneno(void){ return tipo_veneno; }

void Reptil::setVenenoso( bool _venenoso ){ venenoso = _venenoso; }

void Reptil::setTipoVeneno( string _tipo){ tipo_veneno = _tipo; }



int Ave::getTamanhoBico(void){ return tamanho_bico; }

int Ave::getEnvergadura(void){ return envergadura; }

void Ave::setTamanhoBico( int _tamanho ){ tamanho_bico = _tamanho; }

void Ave::setEnvergadura( int _envergadura ){ envergadura = _envergadura; }



string AnimalSilvestre::getIbama(void){ return ibama; }

void AnimalSilvestre::setIbama( string _ibama ){ ibama = _ibama; }



string Nativo::getUfOrigem(void){ return uf_origem; }

string Nativo::getAutorizacao(void){ return autorizacao; }

void Nativo::setUfOirigem( string _uf ){ uf_origem = _uf; }

void Nativo::setAutorizacao( string _autorizacao ){ autorizacao = _autorizacao; }



string Exotico::getPaisOrigem(void){ return pais_origem; }

void Exotico::setPaisOrigem( string _pais ){ pais_origem = _pais; }