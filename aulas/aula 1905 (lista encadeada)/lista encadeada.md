# LISTA SIMPLESMENTE ENCADEADA (AULA 19/05)

```C
LinkedList *l;
```
ponteiro para o primeiro elemento da lista

- para criar uma lista vazia, alocamos memoria para a estrutura, e o ponteiro "first" será NULL.
- o "first" ser NULL é o indicativo de que a lista está vazia.
- toda vez que for inserir um novo elemento, alocar memoria para ele e adicionar a lista.


## CENARIO 1 INSERÇÃO DE ELEMENTO: LISTA VAZIA (FIRST = NULL)
Criar nó da lista, que contém o valor e seu next é NULL.

First, que era NULL, agora tem que apontar para o nó criado.

## CENARIO 2 INSERÇÃO DE ELEMENTO: LISTA NÃO VAZIA (FIRST != NULL)
Criar nó, colocar valor, apontar o nó para o first, e então fazer o first apontar para o nó criado.
