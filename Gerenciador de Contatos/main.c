#include <stdio.h>
#include <string.h>

struct Contato {
    char nome[50];
    char numero[25];
    char email[50];
};

void adicionar(struct Contato contatos[100], int *numContatos);
int buscar(struct Contato contatos[100], int l, int r, char alvo[25]);
void ordenar(struct Contato contatos[100], int *numContatos);
void remover(struct Contato contatos[100], int *numContatos);
void listar(struct Contato contatos[100], int *numContatos);

int main(void)
{
    struct Contato contatos[100];
    int numContatos = 0;
    int escolha;
    char nome[25];
    int index;

    do
    {   
        printf("\n");
        printf("O que deseja fazer hoje?\n");
        printf("1. Adicionar Contato.\n");
        printf("2. Buscar Contato.\n");
        printf("3. Remover Contato.\n");
        printf("4. Exibir Todos os Contatos.\n");
        printf("5. Sair.\n");
        scanf("%d", &escolha);
        printf("\n");

        switch (escolha)
        {
        case 1:
            adicionar(contatos, &numContatos);
            break;
        case 2:
            ordenar(contatos, &numContatos);
            printf("Qual contato deseja buscar? ");
            scanf("%s", nome);
            index = buscar(contatos, 0, numContatos, nome);
            if (index != -1) {
                printf("Nome:\t %-20s", contatos[index].nome);
                printf("Numero:\t %-15s", contatos[index].numero);
                printf("E-mail:\t %-25s", contatos[index].email);
                printf("\n");
            } else
                printf("Contato nao encontrado!\n");            
            break;
        case 3:
            remover(contatos, &numContatos);
            break;
        case 4:
            ordenar(contatos, &numContatos);
            listar(contatos, &numContatos);
            break;
        case 5:
            printf("Finalizando o programa...\n");
            return 0;
            break;
        
        default:
            printf("Escolha invalida!\n");
            break;
        }
    } while (escolha != 5);
    
}

void adicionar(struct Contato contatos[], int *numContatos)
{
    printf("Digite o nome do Contato: ");
    scanf(" %[^\n]", contatos[*numContatos].nome);
    printf("Digite o numero do contato: ");
    scanf("%s", contatos[*numContatos].numero);
    printf("Digite o email do Contato: ");
    scanf("%s", contatos[*numContatos].email);
    for (int i = 0; i < *numContatos; i++) {
    if (strcmp(contatos[i].nome, contatos[*numContatos].nome) == 0 &&
        strcmp(contatos[i].numero, contatos[*numContatos].numero) == 0 &&
        strcmp(contatos[i].email, contatos[*numContatos].email) == 0) {
        printf("Contato ja Existente!\n");
        return;
    }
}
    printf("Contato registrado com sucesso!\n");
    (*numContatos)++;
}

void ordenar(struct Contato contatos[], int *numContatos)
{
    struct Contato temp;

    for (int i = 0; i < *numContatos - 1; i++) {
        for (int j = 0; j < *numContatos - i - 1; j++) {
            if (strcmp(contatos[j].nome, contatos[j + 1].nome) > 0) {
                temp = contatos[j];
                contatos[j] = contatos[j + 1];
                contatos[j + 1] = temp;
            }
        }
    }
}

int buscar(struct Contato contatos[], int l, int r, char alvo[25])
{
    if (l > r) return -1;
    int meio = l + (r - l) / 2;
    if (strcmp(contatos[meio].nome, alvo) == 0) 
        return meio;
    
    if (strcmp(contatos[meio].nome, alvo) > 0)
        return buscar(contatos, l, meio - 1, alvo);
    else 
        return buscar(contatos, meio + 1, r, alvo);
}

void remover(struct Contato contatos[], int *numContatos)
{   
    char nome[25];
    printf("Digite o nome do contato que deseja apagar: ");
    scanf("%s", nome);

    for (int i = 0; i < *numContatos; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            for (int j = i; j < *numContatos - 1; j++)
            {
                strcpy(contatos[j].nome, contatos[j + 1].nome);
                strcpy(contatos[j].numero, contatos[j + 1].numero);
                strcpy(contatos[j].email, contatos[j + 1].email);
            }
            printf("Contato removido com sucesso\n");
            (*numContatos)--;
            return;
        }
        
    }
    printf("Contato nao encontrado!\n");
}

void listar(struct Contato contatos[], int *numContatos)
{
    if(*numContatos == 0) {
        printf("Desculpe, nenhum contato registrado!\n");
        return;
    }
    
    for (int i = 0; i < *numContatos; i++) {
        printf("Nome:\t %-20s", contatos[i].nome);
        printf("Numero:\t %-15s", contatos[i].numero);
        printf("E-mail:\t %-25s", contatos[i].email);
        printf("\n");
    }
}