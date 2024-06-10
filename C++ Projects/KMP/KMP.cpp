#include <iostream>
#include <vector>

void kmp(std::string texto, std::string padrao, std::vector<int> aux)
{
    int idx_texto = 0, idx_padrao = 0;

    while ((unsigned)idx_texto < texto.size())
    {
        if (padrao[idx_padrao] == texto[idx_texto])
        {
            idx_padrao++;
            idx_texto++;
        }

        if ((unsigned)idx_padrao == padrao.size())
        {
            std::cout << "Padrao encontrado na posicao: " << (idx_texto - idx_padrao) << std::endl;
            idx_padrao = aux[idx_padrao - 1];
        }

        if ((unsigned)idx_texto < texto.size() &&
            padrao[idx_padrao] != texto[idx_texto])
        {
            if (idx_padrao)
                idx_padrao = aux[idx_padrao - 1];
            else
                idx_texto++;
        }
    }
}

void prefix(std::string padrao, std::vector<int> &aux)
{
    aux[0] = 0;
    int j = 0, i = 1;

    while ((unsigned)i < padrao.size())
    {
        if (padrao[i] == padrao[j])
        {
            j++;
            aux[i] = j;
            i++;
        }
        else
        {
            if (j)
                j = aux[j - 1];
            else
            {
                aux[i] = 0;
                i++;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    std::string texto = "C++ eh mais do que legal, muito legal";
    std::string padrao = "legal";

    std::vector<int> aux(padrao.size());

    prefix(padrao, aux);
    kmp(texto, padrao, aux);

    return 0;
}