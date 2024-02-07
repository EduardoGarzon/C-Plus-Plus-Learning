// Exemplifica funções friends não-membros de classe.
// Sao funcoes declaradas como friends na propria classe mas definidas fora dela.
// Sao uteis para fornecer funcionalidades extras
// que nao fazem parte da interface publica da classe.

// Inclusão das bibliotecas necessárias
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

// definição de constantes
const int STRMAX = 40;

// Definição da classe Pessoa
class Pessoa
{
private:
   char *nome;

   // Assinatura da função "compara" é declarada como
   // uma amiga da classe em que está sendo declarada.

   // A função "compara" pode ser acessada dentro da classe como um método e
   // pode acessar membros privados e
   // protegidos da classe se necessário para sua execução.
   friend int compara(const void *a, const void *b);

public:
   // A função "saida" é um amigo (friend) da classe "Pessoa".
   // O primeiro parâmetro é um ponteiro para o primeiro elemento
   // do array de objetos "Pessoa", que será usado para iterar
   // sobre todos os objetos no array.

   // O segundo parâmetro é um valor inteiro sem sinal
   // que indica o número de objetos "Pessoa" no array.
   friend void saida(Pessoa *&, unsigned);

   Pessoa();

   // O nome da pessoa é impresso usando a variável membro "nome".
   // A impressão do nome é feita diretamente na função "saida",
   // sem necessidade de receber o objeto "Pessoa" como parâmetro ou
   // chamar um método da classe "Pessoa" pois a função "saida" é definida
   // como um amigo (friend) da classe "Pessoa" e tem acesso direto
   // aos membros privados da classe.
   void saida() { cout << "\n\t" << nome; }

   // destrutor
   ~Pessoa() { delete[] nome; }
};

// Declaração dos métodos da classe Pessoa.

// Construtor padrão da classe "Pessoa".
// Inicializar o membro "nome" da classe "Pessoa" com um valor fornecido pelo usuário.
Pessoa::Pessoa()
{
   char inbuf[STRMAX];

   cout << "\tNome: ";
   cin.get();

   // Lê caracteres da entrada padrão e armazena esses caracteres
   // em um array de caracteres chamado "inbuf".
   cin.get(inbuf, STRMAX - 1);

   // É alocado dinamicamente um novo array de caracteres "nome" com tamanho
   // igual ao comprimento da string lida de "inbuf".
   nome = new char[strlen(inbuf) - 1];
   if (!nome) // Testa o sucesso da alocação
   {
      cout << "Erro: Memória insuficiente!\n";
      exit(0);
   }

   // A string lida de "inbuf" é copiada para "nome"
   strcpy(nome, inbuf);
}

// Funções independentes (Não-membros de classe)

// const void *a -> Estamos declarando um ponteiro
// que pode apontar para qualquer tipo de dados,
// mas cujo conteúdo não pode ser modificado pela função que o recebe.
int compara(const void *a, const void *b)
{
   // Para acessar o valor apontado pelo ponteiro "a",
   // é necessário fazer uma conversão explícita de tipo para o tipo de dados correto,
   // para que os dados possam ser interpretados corretamente.
   Pessoa *primeiro = (Pessoa *)a;
   Pessoa *segundo = (Pessoa *)b;
   return (strcmp(primeiro->nome, segundo->nome));
   /*
      strcmp:

      Valor retornado for menor que zero == string apontada por "primeiro->nome"
      vem antes da string apontada por "segundo->nome" na ordem alfabética.

      Valor retornado for maior que zero == a string apontada por "primeiro->nome"
      vem depois da string apontada por "segundo->nome" na ordem alfabética.

      Valor retornado for igual a zero == indica que as duas strings
      são iguais na ordem alfabética.
   */
}

// A função "saida" é responsável por exibir na tela
// os nomes das pessoas ordenados em ordem alfabética crescente.
// A função "saida" recebe como parâmetros um ponteiro
// para um vetor de objetos "Pessoa" e
// um número inteiro que representa o tamanho do vetor
void saida(Pessoa *&povo, unsigned total)
{
   // O vetor de pessoas é ordenado em ordem crescente
   // com base em seus nomes usando a função "qsort".

   // A função "qsort" é usada para ordenar um array de elementos
   // em ordem crescente ou decrescente.
   qsort(povo, total, sizeof(povo[0]), compara);
   for (int i = 0; i < total; i++)
      // O método "saida()" é responsável por imprimir o nome da pessoa na tela.
      povo[i].saida();
}

// Função principal
int main()
{
   int total = 0;
   cout << "Total de pessoas: ";
   cin >> total;
   cout << endl;

   Pessoa *povo = new Pessoa[total]; // Aloca o vetor dinamicamente

   cout << endl
        << "\nVetor ordenado em ordem alfabetica:\n";
   
   // Dispara funcao de ordenacao do vetor de objetos
   saida(povo, total);
   cout << endl
        << "\nExecucao terminada\n"
        << endl;

   delete[] povo;

   return 0;
}
