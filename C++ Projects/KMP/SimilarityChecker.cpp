#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <unordered_map>

void openArchives(std::string &first_archive, std::string &second_archive);
void showArchiveContent(std::string &first_archive, std::string &second_archive);
void handleKMP(std::string &first_archive, std::string &second_archive, std::string patterns);
std::vector<std::string> split(const std::string &patterns, char separador);
void kmp(const std::string &texto, const std::string &padrao, const std::vector<int> &aux, std::unordered_map<std::string, int> &pattern_count);
void prefix(std::string padrao, std::vector<int> &aux);

int main(int argc, char *argv[])
{
    std::string first_archive, second_archive, patterns;

    // Abertura dos arquivos e inicializacao das strings.
    openArchives(first_archive, second_archive);

    // Exibindo o conteudo dos arquivos.
    showArchiveContent(first_archive, second_archive);

    // Preparo do processo de comparacao;
    handleKMP(first_archive, second_archive, patterns);

    return 0;
}

// Metodo que inicializa os arquivos e strings para comparacao.
void openArchives(std::string &first_archive, std::string &second_archive)
{
    std::string arq_name1, arq_name2;

    // LEITURA DO PRIMEIRO ARQUIVO.
    std::cout << "Informe o nome do primeiro arquivo: ";
    std::cin >> arq_name1;

    // Cria um objeto ifstream para ler o arquivo.
    std::ifstream archiveOne(arq_name1);

    if (!archiveOne.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return;
    }

    // Usa stringstream para ler todo o conteúdo do arquivo.
    std::stringstream buffer;
    buffer << archiveOne.rdbuf();

    // Converte o conteúdo do buffer para uma string.
    first_archive = buffer.str();

    archiveOne.close();

    // ----------------------------------------------------------

    buffer.clear();
    buffer.str("");

    // LEITURA DO SEGUNDO ARQUIVO.
    std::cout << "Informe o nome do segundo arquivo: ";
    std::cin >> arq_name2;

    std::ifstream archiveTwo(arq_name2);

    if (!archiveTwo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return;
    }

    buffer << archiveTwo.rdbuf();
    second_archive = buffer.str();

    archiveTwo.close();
}

// Metodo que exibe o conteudo dos arquivos.
void showArchiveContent(std::string &first_archive, std::string &second_archive)
{
    std::cout << std::endl
              << std::endl;

    std::cout << "[FIRST ARCHIVE]" << std::endl;
    std::cout << first_archive;

    std::cout << std::endl
              << std::endl;

    std::cout << "[SECOND ARCHIVE]" << std::endl;
    std::cout << second_archive << std::endl;

    std::cout << std::endl
              << std::endl;
}

// Metodo que prepara e inicializa as comparacoes entre os dois arquivos.
void handleKMP(std::string &first_archive, std::string &second_archive, std::string patterns)
{
    std::cout << "Informe os padroes que deseja buscar [Exemplo: <pattern pattern pattern>] :" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, patterns);
    std::cout << std::endl
              << std::endl;

    std::vector<std::string> tokens = split(patterns, ' ');

    // Mapa para contar frequências dos padrões em ambos os arquivos
    std::unordered_map<std::string, int> pattern_count_arq1;
    std::unordered_map<std::string, int> pattern_count_arq2;

    for (size_t i = 0; i < tokens.size(); i++)
    {
        std::vector<int> aux(tokens[i].size());
        prefix(tokens[i], aux);
        kmp(first_archive, tokens[i], aux, pattern_count_arq1);
    }

    for (size_t i = 0; i < tokens.size(); i++)
    {
        std::vector<int> aux(tokens[i].size());
        prefix(tokens[i], aux);
        kmp(second_archive, tokens[i], aux, pattern_count_arq2);
    }

    // Exibir a contagem de padrões em ambos os arquivos
    std::cout << "Frequencia dos padroes no primeiro arquivo:" << std::endl;
    for (const auto &pair : pattern_count_arq1)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << std::endl
              << std::endl;

    std::cout << "Frequencia dos padroes no segundo arquivo:" << std::endl;
    for (const auto &pair : pattern_count_arq2)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Vetor para armazenar os padrões comuns
    std::vector<std::string> common_patterns;

    // Encontrar padrões comuns e calcular similaridade baseada na frequência
    for (const auto &pair : pattern_count_arq1)
    {
        if (pattern_count_arq2.find(pair.first) != pattern_count_arq2.end())
        {
            common_patterns.push_back(pair.first);
        }
    }

    std::cout << std::endl
              << std::endl;

    if (common_patterns.empty())
    {
        std::cout << "Nenhum padrao comum encontrado." << std::endl;
    }
    else
    {
        std::cout << "Padroes comuns encontrados em ambos os arquivos:" << std::endl;
        for (const std::string &pattern : common_patterns)
        {
            std::cout << pattern << std::endl;
        }

        double similarity = 0.0;
        int total_count_arq1 = 0;
        int total_count_arq2 = 0;

        for (const auto &pair : pattern_count_arq1)
        {
            total_count_arq1 += pair.second;
        }

        for (const auto &pair : pattern_count_arq2)
        {
            total_count_arq2 += pair.second;
        }

        for (const std::string &pattern : common_patterns)
        {
            similarity += std::min(pattern_count_arq1[pattern], pattern_count_arq2[pattern]);
        }

        std::cout << std::endl
                  << std::endl;

        similarity /= std::max(total_count_arq1, total_count_arq2);
        std::cout << "Similaridade: " << similarity * 100 << "%" << std::endl;
    }

    // // Encontra a interseção dos dois vetores.
    // std::set_intersection(patterns_arq1.begin(), patterns_arq1.end(),
    //                       patterns_arq2.begin(), patterns_arq2.end(),
    //                       std::back_inserter(common_patterns));

    // std::cout << std::endl
    //           << std::endl;
    // std::cout << "Padroes comuns encontrados em ambos os arquivos:" << std::endl;
    // for (const std::string &pattern : common_patterns)
    // {
    //     std::cout << pattern << std::endl;
    // }

    // std::cout << std::endl
    //           << std::endl;
    // if (common_patterns.empty())
    // {
    //     std::cout << "Nenhum padrao comum encontrado." << std::endl;
    // }
    // else
    // {
    //     double similarity = (double)common_patterns.size() / tokens.size();
    //     std::cout << "Similaridade: " << similarity * 100 << "%" << std::endl;
    // }
}

// Método para dividir a string com base em um delimitador.
std::vector<std::string> split(const std::string &patterns, char separador)
{
    std::vector<std::string> tokens;
    std::istringstream stream(patterns);
    std::string token;

    while (getline(stream, token, separador))
    {
        tokens.push_back(token);
    }

    return tokens;
}

// Método que executa as buscas do padrao no KMP.
void kmp(const std::string &texto, const std::string &padrao, const std::vector<int> &aux, std::unordered_map<std::string, int> &pattern_count)
{
    int idx_texto = 0, idx_padrao = 0;

    while (idx_texto < static_cast<int>(texto.size()))
    {
        if (padrao[idx_padrao] == texto[idx_texto])
        {
            idx_padrao++;
            idx_texto++;
        }

        if (idx_padrao == static_cast<int>(padrao.size()))
        {
            idx_padrao = aux[idx_padrao - 1];
            pattern_count[padrao]++;
        }

        if (idx_texto < static_cast<int>(texto.size()) && padrao[idx_padrao] != texto[idx_texto])
        {
            if (idx_padrao)
                idx_padrao = aux[idx_padrao - 1];
            else
                idx_texto++;
        }
    }
}

// Metodo para inicializar a tabela auxiliar.
void prefix(std::string padrao, std::vector<int> &aux)
{
    aux[0] = 0;
    int j = 0; // prefixo.
    int i = 1; // padrao.

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