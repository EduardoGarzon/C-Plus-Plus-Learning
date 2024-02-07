#include <iostream>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <random>

using namespace std;

class Individuo
{
private:
	double x;		// ✖️ gene x
	double y;		// 💹️ gene y
	double fitness; // fenotipo
public:
	Individuo();
	double getx();
	double gety();
	double getf();
	void setx(double a);
	void sety(double a);
	void mutax();
	void mutay();
	Individuo cruza(Individuo B);
	void fitnessC();
};

int pop = 100, gen = 100;
Individuo oi[100], f[100]; // oi - populacao atual e f - filhos

double rand_f(double min, double max)
{
	// random double
	double r;
	r = (rand() / (double)RAND_MAX * (max - min)) + min;
	return r;
}

void Individuo::setx(double a)
{
	this->x = a;
}

void Individuo::sety(double a)
{
	this->y = a;
}

Individuo::Individuo()
{
	// constructor que inicia individuo com x e y aleatorios e calcula seu fitness
	this->x = rand_f(-2.5, 2.5);
	this->y = rand_f(-2.5, 2.5);
	this->fitnessC();
}

double Individuo::getx()
{
	return this->x;
}

double Individuo::gety()
{
	return this->y;
}

double Individuo::getf()
{
	return this->fitness;
}

void Individuo::fitnessC()
{
	// calcula o fitness
	this->fitness = pow(this->x, 5) - 10 * pow(this->x, 3) + 30 * this->x - pow(this->y, 2) + 21 * this->y;
}

void Individuo::mutax()
{
	std::random_device rd{};
	std::mt19937 gen{rd()};
	std::normal_distribution<> d{this->x, 1}; // x media, 1 desvio padrao, gera curva da distribuicao normal
	this->x = d(gen);						  // retorna valor aleatorio dentro da curva
}

void Individuo::mutay()
{
	std::random_device rd{};
	std::mt19937 gen{rd()};
	std::normal_distribution<> d{this->y, 1};
	this->y = d(gen);
}

Individuo Individuo::cruza(Individuo B)
{
	// cruzamento heuristico
	Individuo C;
	double r = rand_f(0, 1);
	if (this->fitness > B.fitness)
	{
		C.x = this->x + r * (this->x - B.x);
		C.y = this->y + r * (this->y - B.y);
	}
	else
	{
		C.x = B.x + r * (B.x - this->x);
		C.y = B.y + r * (B.y - this->y);
	}
	// chance de 5% para mutacao
	if (rand() % 100 > 40)
		C.mutax();
	if (rand() % 100 > 40)
		C.mutay();
	// se o retorno da mutacao for maior que o intervalo restrito
	if (C.x > 2.5)
		C.setx(2.5);
	if (C.y > 2.5)
		C.sety(2.5);
	C.fitnessC(); // fitness do novo individuo 
	return C;
}

int compara(const void *a, const void *b)
{
	// função compara para o qsort
	// deixa os individuos com maior fitness primeiro
	Individuo A = *(Individuo *)a;
	Individuo B = *(Individuo *)b;
	if (A.getf() < B.getf())
		return 1;
	else if (A.getf() > B.getf())
		return -1;
	else
		return 0;
}

int roleta(int tamanho)
{
	// seleciona um individuo aleatorio baseado no fitness
	double somat = 0, somaf = 0;
	int neg;

	if (oi[tamanho - 1].getf() < 0) // verifica se o ultimo elemento é negativo
		neg = 1;
	else
		neg = 0;

	for (int i = 1; i < tamanho; i++)
		somat += oi[i].getf() - (oi[tamanho - 1].getf() - 1) * neg; // soma todos fitness

	double rng = rand_f(0, somat); // valor aleatorio entre zero e o total da soma dos fitness
	for (int i = 1; i < tamanho; i++)
	{
		somaf += oi[i].getf() - (oi[tamanho - 1].getf() - 1) * neg; // soma elementos ate passar o rng
		if (somaf > rng)
		{
			neg = i;
			break;
		}
	}
	return neg; // retorna o indice do individuo
}

void next_gen(int tamanho)
{
	// popula o vetor com a proxima geração de Individuos
	int p1, p2; // pais

	for (int i = 1; i < tamanho; i++) // elitismo, i = 1
	{
		p1 = roleta(tamanho); // selecao
		p2 = roleta(tamanho);

		while (p1 == p2)
			p2 = roleta(tamanho);

		f[i] = oi[p1].cruza(oi[p2]); // cruzamento heuristico
	}

	for (int i = 1; i < tamanho; i++) // popula nova geracao, mantem o elitismo
		oi[i] = f[i];
}

int main()
{
	srand(time(0));

	for (int i = 0; i < gen; i++)
	{
		qsort(oi, pop, sizeof(Individuo), compara); // ordena os fitness
		// imprime o melhor individuo de cada geracao
		printf("gen = %d| x = %lf | y = %lf | fit = %.10lf \n", i, oi[1].getx(), oi[1].gety(), oi[1].getf());
		next_gen(pop);
	}

	return 0;
}
