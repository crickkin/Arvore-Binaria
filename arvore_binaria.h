typedef struct reg_no tipo_no;
typedef tipo_no **arvore_binaria;

arvore_binaria criar_arvore();
void incluir(arvore_binaria sub_raiz, int dado);
void listagem_em_ordem(arvore_binaria sub_raiz);
void listagem_pre_ordem(arvore_binaria sub_raiz);
void listagem_pos_ordem(arvore_binaria sub_raiz);
void excluir(arvore_binaria sub_raiz, int dado);
int excluir_menor(arvore_binaria sub_raiz);
/*Exercícios*/
void desalocar_nos_da_arvore(arvore_binaria raiz);
arvore_binaria excluir_arvore(arvore_binaria raiz);
int verificar_elemento(arvore_binaria raiz, int dado);
int contar_elementos_arvore(arvore_binaria raiz);
int informar_maior(arvore_binaria raiz);
int informar_menor(arvore_binaria raiz);
int somatorio_arvore(arvore_binaria raiz);
int altura_arvore(arvore_binaria raiz);
int contar_folhas(arvore_binaria raiz);
/*Lista*/
float media_arvore(arvore_binaria raiz);
int contar_nulls(arvore_binaria raiz);
int multiplos_tres(arvore_binaria raiz);
int verificar_extritamente_binaria(arvore_binaria raiz);
arvore_binaria copia_arvore(arvore_binaria raiz);
void transforma_nao_busca(arvore_binaria raiz);
