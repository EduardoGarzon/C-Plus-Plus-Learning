#include <iostream>

int numParametros(int argc, char const *argv[])
{
    // argc   -> Numero de Argumentos
    // argv[] -> Argumentos
    int i = 0;
    int qtdArgumentos = 0;
    for (i = 0; i < argc; i++)
    {
        qtdArgumentos++;
    }
    return qtdArgumentos;
}

void imprimirArgumentos(int argc, char const *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        std::cout << "Argumento " << i << " : " << argv[i] << std::endl;
    }
    
}

int main(int argc, char const *argv[])
{

    int qtdArgumentos = numParametros(argc, argv);
    std::cout << "Total de Argumentos: " << qtdArgumentos << std::endl;

    imprimirArgumentos(argc, argv);
    

    return 0;
}