#include <bits/stdc++.h>

using namespace std;

class Tarefa{
public:
	int inicio;
	int fim;

	Tarefa(int i, int f){
		inicio = i;
		fim = f;
	}

	bool operator<(const Tarefa &t) const{
		if(fim == t.fim){
			return inicio < t.inicio;
		}
		return fim > t.fim;
	}


};

void limpa_lixo();
int converte_horario(int hora, char am_pm);
int gera_conversor(Tarefa tarefa_inicial);
priority_queue<Tarefa> conversor_de_tarefas(int conversor, priority_queue<Tarefa> tarefas);
queue<Tarefa> desconversor_de_tarefas(int conversor, queue<Tarefa> tarefas);
queue<Tarefa> interval_scheduling_adaptado(priority_queue<Tarefa> tarefas_convertidas);
string print_horario(int hora);

int main(){
	int quantidade_de_servicos;
	cerr << "Insira a quantidade de serviços desejados: ";
	cin >> quantidade_de_servicos;
	priority_queue<Tarefa> tarefas;
	cerr << "Defina os horários do serviço a partir do seguinte formato:\n";
	for(int i = 0; i<quantidade_de_servicos; ++i){
		cerr << "(h X.M. , h X.M. )\n";
		int inicio, fim;
		char am_pm_inicio, am_pm_fim;
		limpa_lixo();
		scanf("(%d %c.%*c. , %d %c.%*c. )", &inicio, &am_pm_inicio, &fim, &am_pm_fim);
		tarefas.push(Tarefa(converte_horario(inicio, am_pm_inicio),
			converte_horario(fim, am_pm_fim)));
	}

	int conversor = gera_conversor(tarefas.top());
	priority_queue<Tarefa> tarefas_convertidas = conversor_de_tarefas(conversor, tarefas);
	/*while(!tarefas_convertidas.empty()){
		cout << tarefas_convertidas.top().inicio << " - " << tarefas_convertidas.top().fim << endl;
		tarefas_convertidas.pop();
	}*/
	
	queue<Tarefa> tarefas_organizadas_convertidas = interval_scheduling_adaptado(tarefas_convertidas);
	queue<Tarefa> tarefas_organizadas = desconversor_de_tarefas(conversor, tarefas_organizadas_convertidas);
	
	cout << "Serviços escolhidos:\n";
	while(!tarefas_organizadas.empty()){
		cout << "(" << print_horario(tarefas_organizadas.front().inicio)
			 << ", " << print_horario(tarefas_organizadas.front().fim) << ")" << endl;
		tarefas_organizadas.pop();
	}

	return 0;
}

queue<Tarefa> interval_scheduling_adaptado(priority_queue<Tarefa> tarefas_convertidas){
	queue<Tarefa> tarefas_organizadas;
	tarefas_organizadas.push(tarefas_convertidas.top());
	tarefas_convertidas.pop();

	while(!tarefas_convertidas.empty()){
		while(tarefas_convertidas.top().inicio > tarefas_convertidas.top().fim){
			tarefas_convertidas.pop();
		}

		if(tarefas_convertidas.top().inicio >= tarefas_organizadas.back().fim &&
			tarefas_convertidas.top().fim <= 24){
			tarefas_organizadas.push(tarefas_convertidas.top());
		}
		tarefas_convertidas.pop();
	}

	return tarefas_organizadas;
}

void limpa_lixo(){
	char lixo;
	scanf("%c", &lixo);
}

int converte_horario(int hora, char am_pm){
	int horario_convertido;
	if((am_pm == 'A' || am_pm == 'a')&& hora == 12){
		horario_convertido = 24;
	}
	else if(am_pm == 'P' || am_pm == 'p'){
		if(hora == 12){
			horario_convertido = 12;
		}
		else{
			horario_convertido = hora + 12;
		}
	}
	else{
		horario_convertido = hora;
	}

	return horario_convertido;
}

string print_horario(int hora){
	if(hora == 24){
		string horario = "12 A.M";
		return horario;
	}
	else if(hora == 12){
		string horario = "12 P.M";
		return horario;
	}
	else if(hora > 12){
		string horario = to_string(hora - 12);
		horario.push_back(' ');
		horario.push_back('P');
		horario.push_back('.');
		horario.push_back('M');
		return horario;
	}
	else{
		string horario = to_string(hora);
		horario.push_back(' ');
		horario.push_back('A');
		horario.push_back('.');
		horario.push_back('M');
		return horario;
	}
}

int gera_conversor(Tarefa tarefa_inicial){
	int conversor;
	if(tarefa_inicial.inicio <= 12){
		conversor = -1*(tarefa_inicial.inicio);
	}
	else{
		conversor = 24 - tarefa_inicial.inicio;
	}

	return conversor;
}

priority_queue<Tarefa> conversor_de_tarefas(int conversor, 
												priority_queue<Tarefa> tarefas){
	priority_queue<Tarefa> tarefas_convertidas;
	while(!tarefas.empty()){
		int inicio = tarefas.top().inicio + conversor;
		if(inicio >24){
			inicio -= 24;
		}else if(inicio <= 0){
			inicio = 24 + inicio;
		}

		int fim = tarefas.top().fim + conversor;
		if(fim > 24){
			fim -= 24;
		}else if(fim <= 0){
			fim = 24 + fim;
		}
		tarefas_convertidas.push(Tarefa(inicio, fim));
		tarefas.pop();
	}

	return tarefas_convertidas;
}

queue<Tarefa> desconversor_de_tarefas(int conversor, queue<Tarefa> tarefas){
	queue<Tarefa> tarefas_desconvertidas;
	while(!tarefas.empty()){
		int inicio = tarefas.front().inicio - conversor;
		if(inicio > 24){
			inicio -= 24;
		}else if(inicio <= 0){
			inicio = 24 + inicio;
		}

		int fim = tarefas.front().fim - conversor;
		if(fim > 24){
			fim -= 24;
		}else if(fim <= 0){
			fim = 24 + fim;
		}
		tarefas_desconvertidas.push(Tarefa(inicio, fim));
		tarefas.pop();
	}

	return tarefas_desconvertidas;
}