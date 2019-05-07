#include <bits/stdc++.h>

using namespace std;

class Servico{
public:
	string nome;
	double tempo;
	double peso;

	Servico(string n, double t, double p){
		nome = n;
		tempo = t;
		peso = p;
	}

	// Ordena por maior peso/tempo
	bool operator<(const Servico &s) const {
		if(peso == s.peso){
			return tempo > s.tempo;
		}
		return (peso/tempo) < (s.peso/s.tempo);
	}

};

int main(){
	int quantidade_de_servicos;
	cerr << "Insira a quantidade de serviços desejados: ";
	cin >> quantidade_de_servicos;

	priority_queue<Servico> servicos;
	for(int i=0; i<quantidade_de_servicos; ++i){
		double tempo, peso;
		string nome = "Serviço ";
		nome.push_back(('0' + i + 1));
		cerr << nome << endl;
		cerr << "Tempo de impressão: ";
		cin >> tempo;
		cerr << "Peso do serviço: ";
		cin >> peso;

		servicos.push(Servico(nome, tempo, peso));
	}

	double tempo_de_conclusao = 0;
	double tempo_atual = 0;
	cout << "A ordem de impressão dos serviços1 deve ser a seguinte: " << endl;
	while(!servicos.empty()){
		Servico servico_atual = servicos.top();
		servicos.pop();

		tempo_atual += servico_atual.tempo;
		tempo_de_conclusao += tempo_atual * servico_atual.peso;
		cout << servico_atual.nome << endl << "    Tempo: " << servico_atual.tempo
		<< "; Peso: " << servico_atual.peso << endl << endl;
	}

	cout << endl << "Tempo de conclusão de serviços: " << tempo_de_conclusao << endl;
}

/*
Para utilizar as outras ordenações basta substituir a classe Servico por uma das abaixo.

class Servico{
public:
	string nome;
	int tempo;
	int peso;

	Servico(string n, int t, int p){
		nome = n;
		tempo = t;
		peso = p;
	}
	// Ordena por menor tempo
	bool operator<(const Servico &s) const {
		if(tempo == s.tempo){
			return peso < s.peso;
		}
		return tempo > s.tempo;
	}

};

class Servico{
public:
	string nome;
	int tempo;
	int peso;

	Servico(string n, int t, int p){
		nome = n;
		tempo = t;
		peso = p;
	}

	// Ordena por maior peso
	bool operator<(const Servico &s) const {
		if(peso == s.peso){
			return tempo > s.tempo;
		}
		return peso < s.peso;
	}

};

*/