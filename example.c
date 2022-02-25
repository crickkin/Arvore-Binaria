#include <stdio.h>
#include "arvore_binaria.h"

int main()
{
    arvore_binaria raiz, copia_raiz;
    int dado, opcao;

    raiz = criar_arvore();
    do
    {
        printf("\n\n0 - Sair\n");
        printf("1 - Inclusão\n");
        printf("2 - Listagem em ordem\n");
        printf("3 - Listagem pré-ordem\n");
        printf("4 - Listagem pós-ordem\n");
        printf("5 - Excluir elemento\n");
        printf("6 - Excluir menor\n");
        printf("7 - Verificar se um elemento esta contido na arvore\n");
        printf("8 - Contar elementos na arvore\n");
        printf("9 - Verificar maior valor\n");
        printf("10 - Verificar menor valor\n");
        printf("11 - Somatorio dos elementos da arvore\n");
        printf("12 - Verificar altura da arvore\n");
        printf("13 - Contar numero de folhas\n");
        printf("14 - Calcular Media dos elementos\n");
        printf("15 - Contar Nulls da arvore\n");
        printf("16 - Contar Quantos multiplos de 3 existem\n");
        printf("17 - Verificar se a arvore e extritamente binaria\n");
        printf("18 - Copiar Arvore\n");
        printf("19 - Transforma arvore em nao buscavel\n");
        printf("Entre com a sua opção:");
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1: printf("Entre com o dado:");
                    scanf("%d", &dado);
                    incluir(raiz, dado);
                    break;
            case 2: listagem_em_ordem(raiz);
                    break;
            case 3: listagem_pre_ordem(raiz);
                    break;
            case 4: listagem_pos_ordem(raiz);
                    break;
            case 5: printf("Entre com o dado:");
                    scanf("%d", &dado);
                    excluir(raiz, dado);
                    break;
            case 6: printf("Dado apagado:%d\n", excluir_menor(raiz));
                    break;
            case 7: printf("Entre com o dado:");
                    scanf("%d", &dado);
                    if (verificar_elemento(raiz, dado))
                    {
                      printf("\nElemento Encontrado!");
                    }
                    else
                    {
                      printf("\nElemento nao encontrado!");
                    }
                    break;
            case 8: printf("Numero de elementos na arvore: %d", contar_elementos_arvore(raiz));
                    break;
            case 9: printf("Maior valor da arvore e %d", informar_maior(raiz));
                    break;
            case 10: printf("Menor valor da arvore e %d", informar_menor(raiz));
                     break;
            case 11: printf("Somatorio da arvore = %d", somatorio_arvore(raiz));
                     break;
            case 12: printf("A altura da arvore e %d niveis", altura_arvore(raiz));
                     break;
            case 13: printf("Existem %d folhas nesta raiz", contar_folhas(raiz));
                     break;
            case 14: printf("Media dos valores da arvore = %.1f", media_arvore(raiz));
                     break;
            case 15: printf("Numero de Nulls = %d", contar_nulls(raiz));
                     break;
            case 16: printf("Existem %d multiplos de 3 na arvore", multiplos_tres(raiz));
                     break;
            case 17: if (verificar_extritamente_binaria(raiz))
                     {
                       printf("A arvore e extritamente binaria.");
                     }
                     else
                     {
                       printf("A arvore NAO e extritamente binaria.");
                     }
                     break;
            case 18: copia_raiz = copia_arvore(raiz);
                     printf("Copia Raiz:\n");
                     listagem_pre_ordem(copia_raiz);
                     break;
            case 19: transforma_nao_busca(raiz);
                     printf("A arvore nao e mais de busca.");
                     break;
        }
    } while(opcao != 0);

    excluir_arvore(raiz);
    excluir_arvore(copia_raiz);

    return 0;
}
