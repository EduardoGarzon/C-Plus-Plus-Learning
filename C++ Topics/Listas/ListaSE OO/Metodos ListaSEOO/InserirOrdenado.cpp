// Procedimento para inserir um elemento ordenado na lista
void IntSLList::addOrdered(int el)
{
    // Verifica se lista vazia ou se o elemento é menor que o do inicio
    if (topo == nullptr || el < topo->info)
    {
        // Inserir no início da lista ou quando a lista está vazia.
        topo = new IntSLLNode(el, topo);
        if (resto == nullptr)
        {
            resto = topo;
        }
    }
    else
    {
        IntSLLNode *tmp = topo;
        IntSLLNode *anterior = nullptr;

        // Percorre a lista até encontrar a posição de inserção.
        while (tmp != nullptr && el >= tmp->info)
        {
            anterior = tmp;
            tmp = tmp->prox;
        }

        // Insere o novo elemento entre anterior e tmp.
        if (anterior != nullptr)
        {
            anterior->prox = new IntSLLNode(el, tmp);
        }
    }
}