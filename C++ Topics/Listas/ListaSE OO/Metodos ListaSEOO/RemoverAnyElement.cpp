// Funcao para remover qualquer elemento da lista
int IntSLList::deleteNode(int el)
{
    // Verifica se a lista esta vazia
    if (topo == nullptr && resto == nullptr)
    {
        cout << "Lista Vazia" << endl;
        return 0;
    }

    // No temporario
    IntSLLNode *tmp = topo;
    // Armazena o valor a ser removido
    int valorRemovido = topo->info;

    // Verifica se o elemento procurado é o primeiro
    if (el == tmp->info)
    {
        // Verifica se lista possui apenas um elemento
        if (topo == resto)
        {
            topo = resto = nullptr;
            delete tmp;
            return valorRemovido;
        }
        else
        {
            topo = topo->prox;
            delete tmp;
            return valorRemovido;
        }
    }
    else
    {
        // Percorre a lista ate o fim ou ate achar o elemento
        IntSLLNode *anterior = nullptr;
        while (el != tmp->info && tmp)
        {
            anterior = tmp;
            tmp = tmp->prox;
        }

        // Verifica se é o elemento procurado
        if (tmp && el == tmp->info)
        {
            anterior->prox = tmp->prox;
            // Atualiza resto caso seja o ultimo elemento
            if (!tmp->prox)
            {
                resto = anterior;
            }
            valorRemovido = tmp->info;
            delete tmp;
            return valorRemovido;
        }
    }

    // Retorna 0 caso elemento nao encontrado
    return 0;
}