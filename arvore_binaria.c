#include<stdio.h>
#include<stdlib.h>

struct reg_no
{
    int dado;
    struct reg_no *esquerda;
    struct reg_no *direita;
};

typedef struct reg_no tipo_no;
typedef tipo_no **arvore_binaria;

int excluir_menor(arvore_binaria);

arvore_binaria criar_arvore()
{
    arvore_binaria raiz;
    raiz = (arvore_binaria) malloc(sizeof(tipo_no*));
    *raiz = NULL;
    return raiz;
}

void incluir(arvore_binaria sub_raiz, int dado)
{
    if (*sub_raiz == NULL)
    {
        *sub_raiz = (tipo_no*) malloc(sizeof(tipo_no));
        (*sub_raiz)->dado = dado;
        (*sub_raiz)->esquerda = NULL;
        (*sub_raiz)->direita = NULL;
    }
    else
    {
        if (dado < (*sub_raiz)->dado)
        {
            incluir(&((*sub_raiz)->esquerda), dado);
        }
        else
        {
            incluir(&((*sub_raiz)->direita), dado);
        }
    }
}

void listagem_em_ordem(arvore_binaria sub_raiz)
{
    if (*sub_raiz != NULL)
    {
        listagem_em_ordem((&(*sub_raiz)->esquerda));
        printf("%d ", (*sub_raiz)->dado);
        listagem_em_ordem((&(*sub_raiz)->direita));
    }
}

void listagem_pre_ordem(arvore_binaria sub_raiz)
{
    if (*sub_raiz != NULL)
    {
        printf("%d ", (*sub_raiz)->dado);
        listagem_pre_ordem((&(*sub_raiz)->esquerda));
        listagem_pre_ordem((&(*sub_raiz)->direita));
    }
}

void listagem_pos_ordem(arvore_binaria sub_raiz)
{
    if (*sub_raiz != NULL)
    {
        listagem_pos_ordem((&(*sub_raiz)->esquerda));
        listagem_pos_ordem((&(*sub_raiz)->direita));
        printf("%d ", (*sub_raiz)->dado);
    }
}

void excluir(arvore_binaria sub_raiz, int dado)
{
    tipo_no *auxiliar;
    if (*sub_raiz != NULL)
    {
        if (dado < (*sub_raiz)->dado)
        {
            excluir(&((*sub_raiz)->esquerda), dado);
        }
        else
        {
            if (dado > (*sub_raiz)->dado)
            {
                excluir(&((*sub_raiz)->direita), dado);
            }
            else
            {
                if (((*sub_raiz)->esquerda) == NULL)
                {
                    auxiliar = *sub_raiz;
                    *sub_raiz = (*sub_raiz)->direita;
                    free(auxiliar);
                }
                else
                {
                    if (((*sub_raiz)->direita) == NULL)
                    {
                        auxiliar = *sub_raiz;
                        *sub_raiz = (*sub_raiz)->esquerda;
                        free(auxiliar);
                    }
                    else
                    {
                        (*sub_raiz)->dado = excluir_menor(&((*sub_raiz)->direita));
                    }
                }
            }
        }
    }
}

int excluir_menor(arvore_binaria sub_raiz)
{
    tipo_no *auxiliar;
    int menor_valor;

    if (*sub_raiz != NULL)
    {
        if ((*sub_raiz)->esquerda != NULL)
        {
            return excluir_menor(&((*sub_raiz)->esquerda));
        }
        else
        {
            menor_valor = (*sub_raiz)->dado;
            auxiliar = *sub_raiz;
            *sub_raiz = (*sub_raiz)->direita;
            free(auxiliar);
            return menor_valor;
        }
    }
    return -1;
}

/*2 - Desalocar todos os nós da árvore binária*/
void desalocar_nos_da_arvore(arvore_binaria raiz)
{
  if (raiz != NULL)
  {
    //Caso a raiz esteja vazia apenas exclui a arvore
    if (*raiz != NULL)
    {
      //Esvaziando a árvore antes da exlusão
      if ((*raiz)->esquerda != NULL)
      {
        desalocar_nos_da_arvore(&((*raiz)->esquerda));
      }
      if ((*raiz)->direita != NULL)
      {
        desalocar_nos_da_arvore(&((*raiz)->direita));
      }
      free(*raiz);
      *raiz = NULL;
    }
  }
}

/*1 - Destruir a árvore binária*/
arvore_binaria excluir_arvore(arvore_binaria raiz)
{
  if (raiz == NULL)
  {
    return NULL;
  }
  desalocar_nos_da_arvore(raiz);
  free(raiz);
  return NULL;
}

/*3 - Verificar se um elemento está contido na árvore binária*/
int verificar_elemento(arvore_binaria raiz, int dado)
{
  if (*raiz == NULL) return 0;

  if ((*raiz)->dado == dado) return 1;

  if ((*raiz)->dado > dado)
  {
    if ((*raiz)->esquerda != NULL)
    {
      return verificar_elemento(&((*raiz)->esquerda), dado);
    }
    else
    {
      return 0;
    }
  }
  else
  {
    if ((*raiz)->direita != NULL)
    {
      return verificar_elemento(&((*raiz)->direita), dado);
    }
    else
    {
      return 0;
    }
  }
}

/*4 - Contar quantos elementos tem na árvore binária*/
int contar_elementos_arvore(arvore_binaria raiz)
{
  int contador = 0;

  if (*raiz != NULL)
  {
    contador += contar_elementos_arvore(&((*raiz)->esquerda));
    contador += contar_elementos_arvore(&((*raiz)->direita));
    contador ++;
  }

  return contador;
}

/*5- Informar o maior valor da árvore*/
int informar_maior(arvore_binaria raiz)
{
  if (*raiz == NULL) return 0;

  if ((*raiz)->direita != NULL)
  {
    return informar_maior(&((*raiz)->direita));
  }

  return (*raiz)->dado;
}

/*6 - Informar o menor valor da árvore*/
int informar_menor(arvore_binaria raiz)
{
  if (*raiz == NULL) return 0;

  if ((*raiz)->esquerda != NULL)
  {
    return informar_menor(&((*raiz)->esquerda));
  }

  return (*raiz)->dado;
}

/*7 - Retornar a soma dos valores da árvore*/
int somatorio_arvore(arvore_binaria raiz)
{
  int somatorio = 0;

  if (*raiz != NULL)
  {
    somatorio += somatorio_arvore(&((*raiz)->esquerda));
    somatorio += somatorio_arvore(&((*raiz)->direita));
    somatorio += (*raiz)->dado;
  }

  return somatorio;
}

/*8 - Retornar a altura da árvore*/
int altura_arvore(arvore_binaria raiz)
{
  int soma_direita = 0, soma_esquerda = 0;

  if (*raiz != NULL)
  {
    soma_direita += altura_arvore(&((*raiz)->direita));
    soma_esquerda += altura_arvore(&((*raiz)->esquerda));

    soma_direita ++;
    soma_esquerda ++;

    if (soma_esquerda > soma_direita) return soma_esquerda;

    return soma_direita;
  }

  return 0;
}

/*9 - Contar número de folhas da árvore binária*/
int contar_folhas(arvore_binaria raiz)
{
  int count = 0, folha = 1;

  if (*raiz != NULL)
  {
    if ((*raiz)->esquerda != NULL)
    {
      count += contar_folhas(&((*raiz)->esquerda));
      folha = 0;
    }
    if ((*raiz)->direita != NULL)
    {
      count += contar_folhas(&((*raiz)->direita));
      folha = 0;
    }
    if (folha == 1)
    {
      count++;
    }
  }

  return count;
}

/*171. Construir uma função para retornar a média dos valores presentes em uma
árvore.*/
float media_arvore(arvore_binaria raiz)
{
  int tamanho = contar_elementos_arvore(raiz);
  int somatorio = somatorio_arvore(raiz);

  return somatorio/tamanho;
}

/*172. Construir uma função para retornar o número de NULLs presentes em uma
árvore.*/
int contar_nulls(arvore_binaria raiz)
{
  int count = 0;

  if (*raiz != NULL)
  {
    count += contar_nulls(&((*raiz)->esquerda));
    count += contar_nulls(&((*raiz)->direita));

    return count;
  }

  return 1;
}

/*174. Construir uma função para retornar o número de nós cujos valores são
múltiplos de três.*/
int multiplos_tres(arvore_binaria raiz)
{
  int count = 0;

  if (*raiz != NULL)
  {
    count += multiplos_tres(&((*raiz)->esquerda));
    count += multiplos_tres(&((*raiz)->direita));
    if ((*raiz)->dado % 3 == 0)
    {
      count++;
    }
  }

  return count;
}

/*178. Construir uma função para verificar se uma árvore é estritamente binária
(uma árvore é estritamente binária caso todos os seus nós possuam 2 filhos ou
sejam folhas).*/
int verificar_extritamente_binaria(arvore_binaria raiz)
{
  if (*raiz != NULL)
  {
    if ((*raiz)->esquerda != NULL && (*raiz)->direita != NULL)
    { //Tem dois filhos
      if (!verificar_extritamente_binaria(&((*raiz)->esquerda)))
      {
        return 0;
      }
      if (!verificar_extritamente_binaria(&((*raiz)->direita)))
      {
        return 0;
      }
      return 1;
    }
    else if ((*raiz)->esquerda != NULL || (*raiz)->direita != NULL)
    { //Tem apenas 1 filho
      return 0;
    }
    else //Folha
    {
      return 1;
    }
  }
}

/*179. Construir uma função para criar uma cópia de uma árvore.*/
void clonando_arvore(arvore_binaria raiz, arvore_binaria copia)
{
  if (*raiz != NULL)
  {
    incluir(copia, (*raiz)->dado);
    clonando_arvore(&((*raiz)->esquerda), copia);
    clonando_arvore(&((*raiz)->direita), copia);
  }
}

arvore_binaria copia_arvore(arvore_binaria raiz)
{
  arvore_binaria copia;
  copia = criar_arvore();

  clonando_arvore(raiz, copia);

  return copia;
}

/*182. Escreva uma função que decida se uma dada árvore binária é ou não é de
busca.*/
void transforma_nao_busca(arvore_binaria raiz)
{
  int aux;

  if (*raiz != NULL)
  {
    if ((*raiz)->esquerda != NULL)
    {
      aux = (*raiz)->dado;
      (*raiz)->dado = ((*raiz)->esquerda)->dado;
      ((*raiz)->esquerda)->dado = aux;
    }
    else if ((*raiz)->direita != NULL)
    {
      aux = (*raiz)->dado;
      (*raiz)->dado = ((*raiz)->direita)->dado;
      ((*raiz)->direita)->dado = aux;
    }
  }
}
