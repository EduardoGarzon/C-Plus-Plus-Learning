/*
  chaves testadas: 20,40,10,30,15,35,7,26,18,22,5,42,13,46,27,8,32,38,24,45,25
*/
#include <stdio.h>              // Diretiva que define funcoes de entrada e saida.
#include <stdlib.h>             // Diretiva que define funcoes de alocacao e funcoes utilitarias.
#include <malloc.h>             // Diretiva que tambem define funcoes de alocacao.
#include <string.h>             // Diretiva que define funcoes para operacoes com strings.
#define ORDEM 2                 // Constante que define o numero maximo de chaves que uma pagina pode conter.
#define namefile "_arquivo.dat" // Armazena os dados da arvore nesse arquivo.

int cont = -1, count = 0;

// Registro de dados que serao armazenados na arvore.
typedef struct
{
  int chave;     // Chave de identificacao do registro.
  char nome[20]; // Nome do registro.
  int idade;
  int ApPage[2]; // Armazena ponteiros para paginas filhas na arvore.
  int rank;      // Classificacao do registro.
} Registro;

// Estrutura que reprensenta uma página na arvore.
typedef struct Pagina_str *Apontador;
typedef struct Pagina_str
{
  int n;                      // Numero de registros armazenados na pagina.
  int pageNum;                // Numero da pagina.
  int num;                    // Numero da pagina.
  Registro r[2 * ORDEM];      // Armazena os registros presentes na pagina.
  Apontador p[2 * ORDEM + 1]; // Armazena ponteiros para paginas filhas.
} Pagina;

// Estrutura que representa um no de uma lista encadeada.
struct Node
{
  Registro info;     // Informacoes sobre o no da lista.
  struct Node *prox; // Ponteiro para o proximo no da lista.
};
typedef struct Node node;

// ##########################################################
void Antecessor(Apontador Ap, int Ind, Apontador ApPai, int *Diminuiu);
void Busca(Registro Reg, Apontador Ap);
void em_ordem(Apontador raiz);
void buscainFile(Registro Reg, Apontador pagina);
int isleaf(Apontador a);
int file_exists(const char *filename);
void Insere(Registro Reg, Apontador *Ap);
void InsereNaPagina(Apontador Ap, Registro Reg, Apontador ApDir);
void Ins(Registro Reg, Apontador Ap, int *Cresceu, Registro *RegRetorno, Apontador *ApRetorno);
int Imprime2(Apontador p, int Nivel, int aux, int n);
int Imprime(Apontador p, int N, int aux, int n);
void InsertPosFile(Registro Reg, Apontador *Ap);
node *busca(Registro info, node *LISTA);
void InsPosFile(Registro Reg, Apontador Ap, int *Cresceu, Registro *RegRetorno, Apontador *ApRetorno);
void pos_ordem(Apontador raiz);
void Retira(int Ch, Apontador *Ap);
void Ret(int Ch, Apontador *Ap, int *Diminuiu);
void Reconstitui(Apontador ApPag, Apontador ApPai, int PosPai, int *Diminuiu);
void saveAux(Apontador p, int Nivel);
void salvar(Apontador pagina, Registro Reg[]);
void recuperarReg(Apontador *arv, node *LISTA);
void insereInicio(Registro info, node *LISTA);
void execut(Registro info, node *LISTA);
void exibe(node *LISTA);

// Inicializa estruturas arvore B e lista como nulas.
typedef Apontador TipoDicionario;
void Inicializa(TipoDicionario *Dicionario)
{
  *Dicionario = NULL;
} /* Inicializa a estrutura */

void inicia(node *LISTA)
{
  LISTA->prox = NULL;
}

// ############################### Estrutura 1 Btree

/*
  Funcao responsável por encontrar o antecessor de um registro na árvore B+.
  Inicialmente, verifica se o pai tem uma página à direita.
  Se tiver, continua a busca recursivamente pela página mais à direita.
  Se não tiver, encontra o antecessor na página atual e
  realiza as operações necessárias para manter a árvore balanceada.
*/
void Antecessor(Apontador Ap, int Ind, Apontador ApPai, int *Diminuiu)
{
  // Se o pai tiver uma página à direita, continua a busca recursivamente
  if (ApPai->p[ApPai->n] != NULL)
  {
    Antecessor(Ap, Ind, ApPai->p[ApPai->n], Diminuiu);

    if (*Diminuiu)
      Reconstitui(ApPai->p[ApPai->n], ApPai, ApPai->n, Diminuiu); // Reconstitui a árvore se necessário
    return;
  }

  // Se não houver uma página à direita, encontra o antecessor na página atual
  Ap->r[Ind - 1] = ApPai->r[ApPai->n - 1]; // Copia o antecessor para a posição correta
  ApPai->n--;                              // Diminui o número de registros na página pai
  *Diminuiu = ApPai->n < ORDEM;            // Verifica se a página pai tem menos registros do que o mínimo necessário
} /* Antecessor */

/*
  Funcao responsável por procurar uma chave na árvore B+.
  Ela percorre a árvore a partir da raiz até encontrar a página onde a chave pode estar.
  Em seguida, verifica se a chave está presente nessa página.
  Se a chave for encontrada, imprime a chave e realiza a busca no arquivo
  para recuperar os dados associados a essa chave.
  Se a chave não for encontrada na página atual, continua a busca na página filho apropriada,
  dependendo da relação entre a chave buscada e as chaves presentes na página atual.
*/
void Busca(Registro Reg, Apontador Ap)
{
  int i;

  // Verifica se a página é nula
  if (Ap == NULL)
  {
    printf("chave nao encontrada: %d\n", Reg.chave); // Imprime mensagem de chave não encontrada
    return;
  }

  i = 1;
  // Procura a posição onde a chave pode estar na página atual
  while (i < Ap->n && Reg.chave > Ap->r[i - 1].chave)
    i++;

  // Verifica se a chave foi encontrada na página atual
  if (Reg.chave == Ap->r[i - 1].chave)
  {
    printf("chave: %d \n", Reg.chave); // Imprime a chave encontrada
    buscainFile(Ap->r[i - 1], Ap);     // Realiza a busca no arquivo para recuperar os dados
    return;
  }

  // Se a chave não foi encontrada na página atual, continua a busca na página filho apropriada
  if (Reg.chave < Ap->r[i - 1].chave)
    Busca(Reg, Ap->p[i - 1]); // Busca na página filho à esquerda
  else
    Busca(Reg, Ap->p[i]); // Busca na página filho à direita
}

/*
  Funcao responsável por buscar um registro específico no arquivo de dados associado à árvore B+.
  Ela abre o arquivo em modo de leitura binária,
  posiciona o ponteiro do arquivo na posição correspondente à página desejada
  (calculada com base no número da página da página passada como parâmetro),
  lê os registros da página do arquivo para o array reg,
  fecha o arquivo após a leitura e então percorre os registros do array buscando
  pelo registro com a chave específica passada como parâmetro (Reg.chave).
  Se encontrar um registro com a chave correspondente, imprime o nome e a idade desse registro.
*/
void buscainFile(Registro Reg, Apontador pagina)
{
  Registro reg[2 * ORDEM]; // Array para armazenar registros lidos do arquivo
  int i;

  FILE *arq = fopen(namefile, "rb"); // Abre o arquivo para leitura binária

  if (arq == NULL) // Verifica se houve erro na abertura do arquivo
    exit(1);       // Sai do programa se houver erro

  // Posiciona o ponteiro do arquivo na posição correspondente à página desejada
  fseek(arq, pagina->pageNum * (2 * ORDEM * sizeof(Registro)), SEEK_SET);

  // Lê os registros da página do arquivo
  fread(reg, (2 * ORDEM * sizeof(Registro)), 1, arq);

  fclose(arq); // Fecha o arquivo após a leitura dos registros

  // Percorre os registros lidos da página
  for (i = 0; i < 2 * ORDEM; i++)
  {
    // Verifica se a chave do registro corresponde à chave buscada
    if (Reg.chave == reg[i].chave)
      printf("%s%d\n", reg[i].nome, reg[i].idade); // Imprime o nome e a idade do registro
  }
}

/*
  Realiza um percurso em ordem na árvore B+.
  A cada chamada, a função percorre recursivamente as páginas filhas à esquerda do registro atual,
  imprime a chave desse registro e depois percorre a página filha à direita do registro.
  Isso é feito para cada registro da página.
  Assim, a função percorre toda a árvore em ordem crescente de chaves.
*/
void em_ordem(Apontador raiz)
{
  int i;
  // Verifica se a raiz não é nula
  if (raiz != NULL)
  {
    // Percorre os registros da página
    for (i = 0; i < raiz->n; i++)
    {
      // Chama a função recursivamente para as páginas filhas à esquerda do registro
      em_ordem(raiz->p[i]);
      // Imprime a chave do registro
      printf("%d ", raiz->r[i].chave);
      // Quebra de linha para separar os registros
      printf("\n");
    }
    // Chama a função recursivamente para a última página filha à direita do último registro
    em_ordem(raiz->p[i]);
  }
}

// Verifica abertura do arquivo que guarda as informacoes da arvore.
int file_exists(const char *filename)
{
  FILE *arquivo;

  if ((arquivo = fopen(filename, "rb")))
  {
    fclose(arquivo);
    return 1;
  }
  return 0;
}

/*
  Verifica se uma página da árvore B+ é uma folha ou não.
  Ela recebe um ponteiro para a página (Apontador a) como parâmetro
  e verifica se o primeiro ponteiro da página (a->p[0]) é nulo.
  Se for nulo, isso indica que a página não possui filhos,
  ou seja, é uma folha, e então a função retorna 1.
  Caso contrário, a função retorna 0,
  indicando que a página possui filhos e não é uma folha.
*/
int isleaf(Apontador a)
{
  if (a->p[0] == NULL) // Verifica se o primeiro ponteiro da página é nulo
    return 1;          // Retorna 1 se a página é uma folha (não possui filhos)
  else
    return 0; // Retorna 0 se a página não é uma folha (possui filhos)
}

/*
  Insere um novo registro em uma página da árvore B+ mantendo a ordenação dos registros.
  Recebe como parâmetros o ponteiro para a página (Ap),
  o registro a ser inserido (Reg) e o ponteiro para a página à direita do registro inserido (ApDir).
  A função encontra a posição correta para inserir o novo registro na página,
  mantendo a ordem crescente das chaves.
  Após inserir o registro na posição correta, incrementa a quantidade de registros na página.
*/
void InsereNaPagina(Apontador Ap, Registro Reg, Apontador ApDir)
{
  int k;
  int NaoAchouPosicao;

  k = Ap->n;               // Obtém a quantidade atual de registros na página
  NaoAchouPosicao = k > 0; // Inicializa a flag de posição não encontrada como verdadeira se houver registros na página

  // Enquanto não encontrar a posição adequada para inserir o novo registro na página
  while (NaoAchouPosicao)
  {
    // Se a chave do novo registro for maior ou igual à chave do registro na posição k-1 da página
    if (Reg.chave >= Ap->r[k - 1].chave)
    {
      NaoAchouPosicao = 0; // Define a flag como falsa para sair do loop
      break;
    }

    // Move o registro na posição k-1 uma posição para frente na página
    Ap->r[k] = Ap->r[k - 1];

    // Move o ponteiro na posição k uma posição para frente na página
    Ap->p[k + 1] = Ap->p[k];

    k--;                   // Decrementa o índice k
    if (k < 1)             // Se k se tornar menor que 1, significa que não há mais posições anteriores na página
      NaoAchouPosicao = 0; // Define a flag como falsa para sair do loop
  }

  // Insere o novo registro na posição k na página
  Ap->r[k] = Reg;

  // Insere o ponteiro para a direita do novo registro na posição k+1 na página
  Ap->p[k + 1] = ApDir;

  Ap->n++; // Incrementa a quantidade de registros na página
}

/*
  Função é responsável por inserir um registro em uma página da árvore B.
  Ela realiza a inserção recursivamente, buscando a posição correta para inserir o registro na página.
  Se a página não tem espaço suficiente para a inserção, ela realiza um split, dividindo a página em duas.
  Os registros são redistribuídos entre as duas páginas e o registro de retorno é atualizado.
  Ao final, a função limpa a página original para reutilização.
*/
void Ins(Registro Reg, Apontador Ap, int *Cresceu, Registro *RegRetorno, Apontador *ApRetorno)
{
  Apontador ApTemp;
  Registro Aux;
  int i, j;

  // Verifica se a página é nula
  if (Ap == NULL)
  {
    *Cresceu = 1;
    *RegRetorno = Reg;
    *ApRetorno = NULL;
    return;
  }

  // Busca a posição correta para inserir o registro na página
  i = 1;
  while (i < Ap->n && Reg.chave > Ap->r[i - 1].chave)
    i++;

  // Verifica se a chave já existe na página
  if (Reg.chave == Ap->r[i - 1].chave)
  {
    printf("chave ja existente: %d \n", Reg.chave);
    *Cresceu = 0;
    return;
  }

  // Realiza a inserção recursiva na página apropriada
  if (Reg.chave < Ap->r[i - 1].chave)
    Ins(Reg, Ap->p[i - 1], Cresceu, RegRetorno, ApRetorno);
  else
    Ins(Reg, Ap->p[i], Cresceu, RegRetorno, ApRetorno);

  // Verifica se houve crescimento na página
  if (!*Cresceu)
    return;

  // Verifica se a página tem espaço para inserção
  if (Ap->n < 2 * ORDEM)
  { /* Verificando se a pagina tem espaco */
    // Insere o registro na página atual
    InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
    *Cresceu = 0;
    return;
  }

  /* Split: Pagina tem que ser dividida */
  ApTemp = (Apontador)malloc(sizeof(Pagina));
  ApTemp->n = 0;
  ApTemp->p[0] = NULL;
  cont++;
  ApTemp->pageNum = cont;

  // Divide a página em duas
  if (i <= ORDEM + 1)
  {
    InsereNaPagina(ApTemp, Ap->r[2 * ORDEM - 1], Ap->p[2 * ORDEM]);
    Ap->n--;
    InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
  }
  else
  {
    InsereNaPagina(ApTemp, *RegRetorno, *ApRetorno);
  }
  for (j = ORDEM + 2; j <= 2 * ORDEM; j++)
    InsereNaPagina(ApTemp, Ap->r[j - 1], Ap->p[j]);

  Ap->n = ORDEM;
  ApTemp->p[0] = Ap->p[ORDEM + 1];
  *RegRetorno = Ap->r[ORDEM];
  *ApRetorno = ApTemp;

  // Limpa a página original
  for (j = ORDEM; j < Ap->n + 2; j++)
  {
    Aux.chave = 0;
    Aux.rank = 0;
    Ap->r[j] = Aux;
  }
} /*Ins*/

// Procedimento para inserir um registro na estrutura de dados
void Insere(Registro Reg, Apontador *Ap)
{
  int Cresceu;

  Registro RegRetorno;
  Apontador ApRetorno;
  Apontador ApTemp;

  // Chama a função 'Ins' para realizar a inserção do registro
  Ins(Reg, *Ap, &Cresceu, &RegRetorno, &ApRetorno);

  // Verifica se houve crescimento na árvore durante a inserção
  if (Cresceu)
  { /* Se arvore cresce na altura pela raiz */

    // Aloca memória para um novo nó que será inserido na raiz
    ApTemp = (Apontador)malloc(sizeof(Pagina));

    // Configura o novo nó com um registro e um ponteiro de retorno
    ApTemp->n = 1;
    ApTemp->r[0] = RegRetorno;
    ApTemp->p[1] = ApRetorno;

    // Incrementa o contador de páginas
    cont++;
    ApTemp->pageNum = cont;

    // Configura os ponteiros do novo nó para apontar para o antigo nó raiz e para o novo nó de retorno
    ApTemp->p[0] = *Ap;
    *Ap = ApTemp;
    // save in file
  }

  // Salva a estrutura de dados atualizada no arquivo
  saveAux(*Ap, 2 * ORDEM);
} /*Insercao*/

/*
  Funcao para imprimir os registros de uma árvore B+ em um determinado nível.
  Ela percorre a árvore de forma recursiva até atingir o nível desejado (definido pela variável Nivel).
  Quando atinge o nível desejado, imprime os registros da página atual, bem como os números das páginas filhas.
  Se o nível atual não for o desejado, continua descendo na árvore até encontrar o nível desejado.
*/
int Imprime2(Apontador p, int Nivel, int aux, int n)
{
  int i;

  // Verifica se a página é nula
  if (p == NULL)
    return 0;

  // Verifica se o nível atual é o nível desejado para impressão
  if (Nivel == aux)
  {
    n++;                             // Incrementa o contador de páginas
    printf("No: %d : ", p->pageNum); // Imprime o número da página
    // Percorre os registros da página
    for (i = 0; i < p->n; i++)
    {
      // Verifica se o apontador para a página filha não é nulo e imprime o número da página filha
      if (p->p[i] != NULL)
        printf("Apontador: %d ", p->p[i]->pageNum);
      else
        printf("Apontador: null ");        // Caso o apontador seja nulo, imprime "null"
      printf("chave: %d ", p->r[i].chave); // Imprime a chave do registro
    }
    printf("\n"); // Quebra de linha para separar as páginas
    return n;     // Retorna o número de páginas impressas
  }
  else
  {
    aux++; // Incrementa o nível auxiliar para continuar descendo na árvore
    // Percorre as páginas filhas da página atual
    for (i = 0; i <= p->n; i++)
      Imprime2(p->p[i], Nivel, aux, n); // Chama recursivamente a função para a página filha
  }
  return 0; // Retorna 0 caso não tenha sido impressa nenhuma página
}

/*
  Imprime é usada para imprimir os números das páginas da árvore B+.
  Ela percorre recursivamente a árvore e atribui o número da página (p->num) para cada nó,
  considerando a ordem de impressão.
  O parâmetro aux é usado para acompanhar o número da página atual durante a recursão.
  Ao encontrar uma nova página (p->pageNum != aux), ela atribui o número da página e atualiza aux.
*/
int Imprime(Apontador p, int N, int aux, int n)
{
  int i;

  if (p == NULL)
    return 0; // Retorna 0 se o ponteiro da página for nulo

  if (p->pageNum != aux)
  {
    p->num = N;       // Atribui o número da página
    aux = p->pageNum; // Atualiza o número da página atual
    return aux;       // Retorna o número da página atual
  }
  else
  {
    aux++; // Incrementa o número da página
    for (i = 0; i <= p->n; i++)
      Imprime(p->p[i], N, aux, n); // Chama recursivamente a função para cada filho da página atual
  }
  return 0; // Retorna 0 no final da função
}

/*
  Responsável por inserir um registro na árvore B+.
  Ela chama a função InsPosFile para inserir o registro na posição correta na árvore.
  Se houver crescimento na altura pela raiz, ou seja, se for necessária uma nova raiz,
  então é criada uma nova página que se torna a nova raiz da árvore.
*/
void InsertPosFile(Registro Reg, Apontador *Ap)
{
  int Cresceu;
  Registro RegRetorno;
  Apontador ApRetorno;
  Apontador ApTemp;

  // Chama a função de inserção na posição correta na árvore
  InsPosFile(Reg, *Ap, &Cresceu, &RegRetorno, &ApRetorno);

  // Se houve crescimento na altura pela raiz, atualiza a raiz da árvore
  if (Cresceu)
  {
    // Cria uma nova página para ser a nova raiz
    ApTemp = (Apontador)malloc(sizeof(Pagina));
    ApTemp->n = 1;
    ApTemp->r[0] = RegRetorno;
    ApTemp->p[1] = ApRetorno;
    cont++;
    ApTemp->pageNum = cont;
    ApTemp->p[0] = *Ap;
    *Ap = ApTemp; // Atualiza a raiz da árvore
  }
}

/*
  Responsável por inserir um registro em uma página da árvore B+.
  Se a página fornecida como argumento for nula, indica que a inserção deve ser feita nesta página.
  Caso contrário, a função procura a posição correta para a inserção na página atual
  e insere recursivamente na próxima página.
  Se não houver espaço para mais uma chave na página,
  é feita a divisão da página (split).
  Após a divisão, a função limpa as chaves da página original e finaliza a inserção
*/
void InsPosFile(Registro Reg, Apontador Ap, int *Cresceu, Registro *RegRetorno, Apontador *ApRetorno)
{
  Apontador ApTemp;
  Registro Aux;
  int i, j;

  // Se a página é nula, indica que a inserção deve ser feita nesta página
  if (Ap == NULL)
  {
    *Cresceu = 1;
    *RegRetorno = Reg;
    *ApRetorno = NULL;
    return;
  }

  // Procura a posição correta para a inserção na página atual
  i = 1;
  while (i < Ap->n && Reg.chave > Ap->r[i - 1].chave)
    i++;

  // Verifica se a chave já existe na página
  if (Reg.chave == Ap->r[i - 1].chave)
  {
    *Cresceu = 0;
    return;
  }

  // Insere recursivamente na próxima página
  if (Reg.chave < Ap->r[i - 1].chave)
    InsPosFile(Reg, Ap->p[i - 1], Cresceu, RegRetorno, ApRetorno);
  else
    InsPosFile(Reg, Ap->p[i], Cresceu, RegRetorno, ApRetorno);

  // Se não houve crescimento na altura, a inserção é concluída
  if (!*Cresceu)
    return;

  // Verifica se a página tem espaço para mais uma chave
  if (Ap->n < 2 * ORDEM)
  {
    // Se tem espaço, insere a chave na página e finaliza a inserção
    InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
    *Cresceu = 0;
    return;
  }

  // Divisão da página (split)
  ApTemp = (Apontador)malloc(sizeof(Pagina));
  ApTemp->n = 0;
  ApTemp->p[0] = NULL;
  cont++;
  ApTemp->pageNum = cont;

  if (i <= ORDEM + 1)
  {
    InsereNaPagina(ApTemp, Ap->r[2 * ORDEM - 1], Ap->p[2 * ORDEM]);
    Ap->n--;
    InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
  }
  else
  {
    InsereNaPagina(ApTemp, *RegRetorno, *ApRetorno);
  }
  for (j = ORDEM + 2; j <= 2 * ORDEM; j++)
    InsereNaPagina(ApTemp, Ap->r[j - 1], Ap->p[j]);

  Ap->n = ORDEM;
  ApTemp->p[0] = Ap->p[ORDEM + 1];
  *RegRetorno = Ap->r[ORDEM];
  *ApRetorno = ApTemp;

  // Limpa as chaves da página original após o split
  for (j = ORDEM; j < Ap->n + 2; j++)
  {
    Aux.chave = 0;
    Aux.rank = 0;
    Ap->r[j] = Aux;
  }
}

/*
  Realiza um percurso em pós-ordem na árvore B+.
  Se a página fornecida como argumento for uma folha,
  imprime as chaves da página da direita para a esquerda.
  Caso contrário, a função primeiro percorre recursivamente as páginas filhas da direita para a esquerda,
  depois imprime as chaves da página da direita para a esquerda e,
  finalmente, percorre recursivamente as páginas filhas da esquerda para a direita.
  Esse tipo de percurso é útil para liberar a memória ocupada pela árvore na ordem correta.
*/
void pos_ordem(Apontador raiz)
{
  int i;

  // Verifica se a página é uma folha
  if (isleaf(raiz))
  {
    // Se for uma folha, imprime as chaves da direita para a esquerda
    for (i = raiz->n - 1; i >= 0; i--)
    {
      printf("%d\n", raiz->r[i].chave);
    }
  }
  else
  {
    // Se não for uma folha, percorre recursivamente as páginas filhas
    // da direita para a esquerda, depois imprime as chaves da página
    // da direita para a esquerda e percorre recursivamente as páginas
    // filhas da esquerda para a direita
    pos_ordem(raiz->p[raiz->n]);
    for (i = raiz->n - 1; i >= 0; i--)
    {
      printf("%d\n", raiz->r[i].chave);
      pos_ordem(raiz->p[i]);
    }
  }
}

/*
  Realiza a busca de um registro na árvore B+ com base na chave fornecida.
  Recebe como parâmetros um ponteiro para o registro a ser buscado (x)
  e um ponteiro para a página onde a busca será realizada (Ap).
  A função verifica se a página é nula, o que indicaria que o registro não existe na árvore.
  Em seguida, procura a posição onde o registro poderia estar na página
  e compara as chaves para determinar se o registro foi encontrado.
  Se a chave do registro for menor que a chave na posição i-1,
  a busca continua na subárvore à esquerda;
  caso contrário, a busca continua na subárvore à direita.
  Essa busca é realizada recursivamente até encontrar o registro ou percorrer toda a árvore.
*/
void Pesquisa(Registro *x, Apontador Ap)
{
  int i;

  if (Ap == NULL)
  {
    // Se a página for nula, significa que o registro não existe na árvore
    // printf("Erro: Registro nao existe\n");

    return;
  }

  // Procura a posição do registro na página onde poderia estar
  i = 1;
  while (i < Ap->n && x->chave > Ap->r[i - 1].chave)
    i++;

  // Se a chave do registro for igual à chave do registro na posição i-1 da página
  if (x->chave == Ap->r[i - 1].chave)
  {
    // Atualiza o registro x com o registro encontrado
    *x = Ap->r[i - 1];
    return;
  }

  // Se a chave do registro for menor que a chave do registro na posição i-1 da página
  if (x->chave < Ap->r[i - 1].chave)
    // Pesquisa recursivamente na subárvore à esquerda
    Pesquisa(x, Ap->p[i - 1]);
  else
    // Pesquisa recursivamente na subárvore à direita
    Pesquisa(x, Ap->p[i]);
}

/*
  Funcao responsável por reconstruir uma página na árvore B+ após uma remoção, se necessário.
  Ele verifica se é possível transferir registros de páginas vizinhas para preencher a página atual
  ou se é necessário realizar uma fusão entre a página atual e uma vizinha.
  Ao final, atualiza o estado da árvore verificando se houve diminuição na altura.
*/
void Reconstitui(Apontador ApPag, Apontador ApPai, int PosPai, int *Diminuiu)
{
  Apontador Aux;
  int DispAux, j;

  // Se a posição do pai for menor que o número de registros na página pai
  if (PosPai < ApPai->n)
  {
    // Aux é a página à direita de ApPag
    Aux = ApPai->p[PosPai + 1];
    DispAux = (Aux->n - ORDEM + 1) / 2;
    ApPag->r[ApPag->n] = ApPai->r[PosPai]; // Copia o registro do pai para a página atual
    ApPag->p[ApPag->n + 1] = Aux->p[0];    // Ajusta os ponteiros da página atual
    ApPag->n++;                            // Incrementa o número de registros na página atual
    if (DispAux > 0)
    {
      // Existe espaço na página Aux: transfere registros para a página atual
      for (j = 1; j < DispAux; j++)
        InsereNaPagina(ApPag, Aux->r[j - 1], Aux->p[j]);
      ApPai->r[PosPai] = Aux->r[DispAux - 1]; // Atualiza o registro do pai
      Aux->n -= DispAux;                      // Atualiza o número de registros em Aux
      for (j = 0; j < Aux->n; j++)
        Aux->r[j] = Aux->r[j + DispAux]; // Remove os registros transferidos de Aux
      for (j = 0; j <= Aux->n; j++)
        Aux->p[j] = Aux->p[j + DispAux]; // Ajusta os ponteiros de Aux
      *Diminuiu = 0;                     // Não houve diminuição na altura da árvore
    }
    else
    {
      // Fusão: intercala Aux em ApPag e libera Aux
      for (j = 1; j <= ORDEM; j++)
        InsereNaPagina(ApPag, Aux->r[j - 1], Aux->p[j]);
      free(Aux); // Libera a memória ocupada por Aux
      for (j = PosPai + 1; j < ApPai->n; j++)
      { // Preenche o espaço vazio no pai
        ApPai->r[j - 1] = ApPai->r[j];
        ApPai->p[j] = ApPai->p[j + 1];
      }
      ApPai->n--;            // Atualiza o número de registros no pai
      if (ApPai->n >= ORDEM) // Verifica se ainda há registros suficientes no pai
        *Diminuiu = 0;       // Não houve diminuição na altura da árvore
    }
  }
  else
  {
    // Aux é a página à esquerda de ApPag
    Aux = ApPai->p[PosPai - 1];
    DispAux = (Aux->n - ORDEM + 1) / 2;
    for (j = ApPag->n; j >= 1; j--)
      ApPag->r[j] = ApPag->r[j - 1];    // Desloca os registros em ApPag
    ApPag->r[0] = ApPai->r[PosPai - 1]; // Copia o registro do pai para ApPag
    for (j = ApPag->n; j >= 0; j--)
      ApPag->p[j + 1] = ApPag->p[j]; // Ajusta os ponteiros em ApPag
    ApPag->n++;                      // Incrementa o número de registros em ApPag
    if (DispAux > 0)
    {
      // Existe espaço na página Aux: transfere registros para ApPag
      for (j = 1; j < DispAux; j++)
        InsereNaPagina(ApPag, Aux->r[Aux->n - j], Aux->p[Aux->n - j + 1]);
      ApPag->p[0] = Aux->p[Aux->n - DispAux + 1];      // Ajusta o ponteiro inicial de ApPag
      ApPai->r[PosPai - 1] = Aux->r[Aux->n - DispAux]; // Atualiza o registro do pai
      Aux->n -= DispAux;                               // Atualiza o número de registros em Aux
      *Diminuiu = 0;                                   // Não houve diminuição na altura da árvore
    }
    else
    {
      // Fusão: intercala ApPag em Aux e libera ApPag
      for (j = 1; j <= ORDEM; j++)
        InsereNaPagina(Aux, ApPag->r[j - 1], ApPag->p[j]);
      free(ApPag);           // Libera a memória ocupada por ApPag
      ApPai->n--;            // Atualiza o número de registros no pai
      if (ApPai->n >= ORDEM) // Verifica se ainda há registros suficientes no pai
        *Diminuiu = 0;       // Não houve diminuição na altura da árvore
    }
  }
} /* Reconstitui */

/*
  Funcao que é responsável por remover um registro com a chave Ch da árvore.
  Inicialmente, verifica se a página atual é nula.
  Se a página não for nula, procura a posição da chave na página e verifica se a chave foi encontrada.
  Se a chave for encontrada, marca o registro como removido e
  realiza as operações necessárias para manter a árvore balanceada.
  Se a chave não estiver na página atual, continua a busca recursivamente nas páginas filhas.
*/
void Ret(int Ch, Apontador *Ap, int *Diminuiu)
{
  int Ind, j;
  Apontador WITH;
  Registro Reg;

  // Verifica se a página atual é nula
  if (*Ap == NULL)
  {
    printf("chave nao encontrada: %i\n", Ch); // Informa que a chave não foi encontrada
    *Diminuiu = 0;                            // Define que não houve diminuição na árvore
    return;
  }

  WITH = *Ap;
  Ind = 1;

  // Encontra a posição da chave na página
  while (Ind < WITH->n && Ch > WITH->r[Ind - 1].chave)
    Ind++;

  // Verifica se a chave foi encontrada na página
  if (Ch == WITH->r[Ind - 1].chave)
  {
    Reg.chave = 0;          // Define a chave como zero, marcando-a como removida
    Reg.rank = 0;           // Define o rank como zero
    WITH->r[Ind - 1] = Reg; // Remove o registro da página

    if (WITH->p[Ind - 1] == NULL)
    {                              /* Pagina folha */
      WITH->n--;                   // Diminui o número de registros na página
      *Diminuiu = WITH->n < ORDEM; // Verifica se a página tem menos registros do que o mínimo necessário

      // Rearranja os registros e os ponteiros após a remoção
      for (j = Ind; j <= WITH->n; j++)
      {
        WITH->r[j - 1] = WITH->r[j];
        WITH->p[j] = WITH->p[j + 1];
      }
      return;
    }

    // Se a página não é uma folha, continua a remoção recursivamente
    Antecessor(*Ap, Ind, WITH->p[Ind - 1], Diminuiu);
    if (*Diminuiu)
      Reconstitui(WITH->p[Ind - 1], *Ap, Ind - 1, Diminuiu); // Reconstitui a árvore se necessário
    return;
  }

  // Se a chave não está na página atual, continua a busca recursivamente
  if (Ch > WITH->r[Ind - 1].chave)
    Ind++;

  Ret(Ch, &WITH->p[Ind - 1], Diminuiu);

  if (*Diminuiu)
    Reconstitui(WITH->p[Ind - 1], *Ap, Ind - 1, Diminuiu); // Reconstitui a árvore se necessário
} /* Ret */

/*
  Funcao responsável por remover um registro com a chave Ch da árvore.
  Primeiro, chama a função Ret para realizar a remoção do registro e
  atualizar o status Diminuiu indicando se a árvore diminuiu na altura após a remoção.
  Em seguida, verifica se a árvore diminuiu na altura e se a página atual está vazia.
  Se ambos os critérios forem atendidos,
  remove a página atual da árvore e libera a memória alocada para ela.
*/
void Retira(int Ch, Apontador *Ap)
{
  int Diminuiu;
  Apontador Aux;

  // Chama a função 'Ret' para remover o registro com a chave especificada
  // e atualiza o status 'Diminuiu' indicando se a árvore diminuiu na altura
  Ret(Ch, Ap, &Diminuiu);

  // Verifica se a árvore diminuiu na altura e se a página atual está vazia
  if (Diminuiu && (*Ap)->n == 0)
  {
    /* Arvore diminui na altura */
    // Se a árvore diminuiu na altura e a página está vazia, remove a página atual
    Aux = *Ap;
    *Ap = Aux->p[0];
    free(Aux);
  }

} /* Retira */

// Procedimento para recuperar os dados do arquivo na arvore e na lista.
void recuperarReg(Apontador *arv, node *LISTA)
{
  FILE *arq;
  Registro Reg[2 * ORDEM];
  node *tmp;

  int i = 0, j = 0, tam;

  // Abertura do arquivo para leitura
  arq = fopen(namefile, "rb");
  if (arq == NULL)
    exit(1);

  // Determinação do tamanho do arquivo
  fseek(arq, 0, SEEK_END);
  tam = ftell(arq);

  rewind(arq);
  fclose(arq);

  // Leitura dos registros do arquivo e inserção na lista encadeada
  arq = fopen(namefile, "rb");
  if (arq == NULL)
    exit(1);

  while (j * (2 * ORDEM * sizeof(Registro)) < tam)
  {
    fseek(arq, j * (2 * ORDEM * sizeof(Registro)), SEEK_SET);
    fread(Reg, 2 * ORDEM * sizeof(Registro), 1, arq);

    for (i = 0; i < 2 * ORDEM; i++)
    {
      if (Reg[i].chave > 0)
        execut(Reg[i], LISTA);
    }
    j++;
  }

  fclose(arq);

  // Inserção dos registros na árvore B a partir da lista encadeada
  tmp = LISTA->prox;
  while (tmp != NULL)
  {
    InsertPosFile(tmp->info, arv);
    tmp = tmp->prox;
  }

  free(tmp);
  free(LISTA);
  // Imprime(*arv, 2*ORDEM, 0);
}

/*
  Função responsável por salvar a árvore B em um arquivo auxiliar.
  Ela percorre a árvore de forma recursiva, começando da raiz,
  salvando os registros de cada página no arquivo
  e então chamando recursivamente a função para as páginas filhas.
*/
void saveAux(Apontador p, int Nivel)
{
  int i, j;

  // Verifica se a página é nula
  if (p == NULL)
    return;

  // Percorre os registros da página atual e os salva
  for (i = 0; i < p->n; i++)
    salvar(p, p->r);

  // Percorre os ponteiros da página atual e salva recursivamente as páginas filhas
  for (j = 0; j <= p->n; j++)
    saveAux(p->p[j], Nivel + 1);
}

/*
  Rresponsável por salvar uma página no arquivo binário.
  Se o arquivo não existir, ele é criado;
  caso contrário, é aberto em modo de leitura e escrita.
  Em seguida, o ponteiro do arquivo é movido para a posição correta usando fseek,
  e os registros da página são escritos no arquivo usando fwrite.
  Por fim, o arquivo é fechado com fclose.
*/
void salvar(Apontador pagina, Registro Reg[])
{
  FILE *arq;
  if (!file_exists(namefile))
  {
    arq = fopen(namefile, "wb"); // Cria um novo arquivo binário
    if (arq == NULL)
      exit(1);                                                              // Sai do programa se não conseguir abrir o arquivo
    fseek(arq, pagina->pageNum * (2 * ORDEM * sizeof(Registro)), SEEK_SET); // Move o ponteiro do arquivo para a posição correta
    fwrite(Reg, (2 * ORDEM * sizeof(Registro)), 1, arq);                    // Escreve os registros no arquivo
    fclose(arq);                                                            // Fecha o arquivo
  }
  else
  {
    arq = fopen(namefile, "r+b"); // Abre o arquivo binário para leitura e escrita
    if (arq == NULL)
      exit(1);                                                              // Sai do programa se não conseguir abrir o arquivo
    fseek(arq, pagina->pageNum * (2 * ORDEM * sizeof(Registro)), SEEK_SET); // Move o ponteiro do arquivo para a posição correta
    fwrite(Reg, (2 * ORDEM * sizeof(Registro)), 1, arq);                    // Escreve os registros no arquivo
    fclose(arq);                                                            // Fecha o arquivo
  }
}

// ############################### //Estrutura 1 Btree

// ############################### //Estrutura 2 lista encadeada

/*
  Insere um novo nó com a informação info no início da lista encadeada LISTA.
  Primeiro, é alocada memória para o novo nó.
  Em seguida, é realizado uma busca para encontrar o nó onde o novo nó será inserido.
  Se a lista estiver vazia, o novo nó é inserido como o primeiro nó da lista.
  Caso contrário, o novo nó é inserido logo após o nó encontrado pela busca.
*/
void insereInicio(Registro info, node *LISTA)
{
  node *novo = (node *)malloc(sizeof(node)); // Aloca memória para o novo nó
  node *tmp = busca(info, LISTA);            // Busca o nó onde será inserido o novo nó

  if (LISTA->prox == NULL)
  {                           // Se a lista estiver vazia
    novo->info = info;        // Define o campo info do novo nó com o valor passado
    novo->prox = LISTA->prox; // O próximo nó do novo nó aponta para o próximo nó da lista
    LISTA->prox = novo;       // O próximo nó da lista passa a ser o novo nó
  }
  else
  {                         // Se a lista não estiver vazia
    novo->prox = tmp->prox; // O próximo nó do novo nó aponta para o próximo nó do nó encontrado pela busca
    novo->info = info;      // Define o campo info do novo nó com o valor passado
    tmp->prox = novo;       // O próximo nó do nó encontrado pela busca passa a ser o novo nó
  }
  // exibe(LISTA); // Chama a função para exibir a lista (comentada no código original)
}

/*
  Percorre a lista encadeada LISTA até encontrar o nó onde a informação info deve ser inserida.
  Ela retorna o ponteiro para o nó anterior ao nó onde a inserção deve ser feita.
  Se a lista estiver vazia ou se a chave do nó atual for maior que a chave buscada,
  a função retorna o ponteiro para o nó cabeça da lista.
*/
node *busca(Registro info, node *LISTA)
{
  node *atual, *antNode;
  atual = LISTA->prox; // Inicializa o ponteiro atual apontando para o primeiro nó da lista
  antNode = LISTA;     // Inicializa o ponteiro antNode apontando para o nó cabeça da lista

  // Percorre a lista enquanto o nó atual não for nulo e a chave do nó atual for menor que a chave buscada
  while (atual != NULL && info.rank > atual->info.rank)
  {
    antNode = atual;     // Atualiza o ponteiro antNode para apontar para o nó atual
    atual = atual->prox; // Avança para o próximo nó da lista
  }

  return antNode; // Retorna o ponteiro antNode, que aponta para o nó onde a busca deve ser realizada
}

/*
  Percorre a lista encadeada LISTA e exibe as chaves dos nós.
  Se a lista estiver vazia, a função retorna sem exibir nada.
  Caso contrário, ela percorre a lista utilizando um ponteiro temporário tmp,
  exibindo a chave de cada nó.
  Ao final, imprime uma nova linha para melhor visualização.
*/
void exibe(node *LISTA)
{
  if (!LISTA) // Verifica se a lista está vazia
  {
    return; // Se estiver vazia, retorna sem exibir nada
  }
  node *tmp;
  tmp = LISTA->prox; // Inicializa o ponteiro tmp para apontar para o primeiro nó da lista

  // Percorre a lista exibindo as chaves dos nós
  while (tmp != NULL)
  {
    printf(" %d ", tmp->info.chave); // Exibe a chave do nó atual
    tmp = tmp->prox;                 // Avança para o próximo nó da lista
  }
  printf("\n"); // Após exibir todas as chaves, imprime uma nova linha
}

/*
  Chaa função insereInicio,
  passando a informação info e a lista encadeada LISTA.
  Isso resulta na inserção de um novo nó com a informação fornecida no início da lista.
*/
void execut(Registro info, node *LISTA)
{
  insereInicio(info, LISTA); // Chama a função insereInicio para inserir um novo nó com a informação 'info' no início da lista encadeada 'LISTA'
}

// ############################# //Estrutura 2 lista encadeada

int main()
{
  Apontador *arv; // Ponteiro para um ponteiro de pagina.
  Registro reg;   // Dados que serao inseridos na arvore.

  char tecla; // Tecla pressionada pelo user.
  int chave, i, num = 0;

  arv = (Apontador *)malloc(sizeof(Apontador)); // Ponteiro para a raiz da arvore.
  node *LISTA = (node *)malloc(sizeof(node));   // Aloca memoria para a lista encadeada.

  Inicializa(arv); // Inicializa a arvore com a raiz nula.
  inicia(LISTA);   // Inicia a lista com o primeiro no nulo.

  // Verifica nome do arquivo para recuperar os dados armazenados no arquivo.
  if (file_exists(namefile))
  {
    recuperarReg(arv, LISTA);
  }

  printf("i - insercao \n");
  printf("r - remove \n");
  printf("o - exibir \n");
  printf("c - consultar \n");
  while (1)
  {
    scanf("%c", &tecla);

    if (tecla == 'e')
      break;

    switch (tecla)
    {
    case 'i':
      printf("insercao \n");
      scanf("%d", &chave);

      // Atribui a chave inserida à estrutura 'reg'
      reg.chave = chave;
      // Incrementa a variável 'count' para manter um registro do número total de inserções
      count++;
      // Atribui o valor atual de 'count' ao campo 'rank' da estrutura 'reg'
      reg.rank = count;

      fflush(stdin);
      getchar();

      // Solicita ao usuário que insira o nome do registro e armazena o valor na estrutura 'reg'
      fgets(reg.nome, sizeof(reg.nome), stdin);

      // Solicita ao usuário que insira a idade do registro e armazena o valor na estrutura 'reg'
      scanf("%d", &reg.idade);

      // Verifica se a chave do registro é menor ou igual a zero
      if (reg.chave <= 0)
      {
        count--;
        break;
      }

      // Insere o registro na estrutura de dados utilizando a função 'Insere'
      Insere(reg, arv);

      break;
    case 'r':
      printf("remove \n");
      scanf("%d", &chave);

      // Atribui a chave fornecida à estrutura de registro
      reg.chave = chave;

      // Chama a função 'Retira' para remover o registro com a chave especificada da árvore
      Retira(reg.chave, arv);

      // Remove o arquivo principal que armazena a árvore B
      remove(namefile);

      // Salva a árvore atualizada no arquivo auxiliar
      saveAux(*arv, 2 * ORDEM);

      break;
    case 'o':
      printf("exibir \n");
      em_ordem(*arv);

      break;
    case 'p':
      for (i = 0; i < 2 * ORDEM; i++)
      {
        num = Imprime2(*arv, i, 0, num);
      }
      break;
    case 'c':
      printf("consulta \n");

      getchar();
      scanf("%d", &chave);

      reg.chave = chave;

      Busca(reg, *arv);
      break;
    }

    fflush(stdin);
  }

  return 0;
}
