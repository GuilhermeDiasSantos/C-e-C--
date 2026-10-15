#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#define TAM 50
FILE *lista_clientes;
struct cliente{
    char nome[TAM];
    char cpf [TAM];
    char telefone[TAM];
    char email[TAM];
    char cidade[TAM];
    int codigo;
};
struct cliente cli [1000]={0};
void carregarClientes() {
    lista_clientes = fopen("clientes.txt", "r");
    if (lista_clientes == NULL) return; // Arquivo ainda não foi criado

    memset(cli, 0, sizeof(cli));
    int cod;
    char nome[TAM], cpf[TAM], tel[TAM], email[TAM], cidade[TAM];
}

// Carrega os dados salvos do arquivo
void carregarclientes() {
    lista_clientes = fopen("clientes.txt", "r");
    if (lista_clientes == NULL) return; // Arquivo ainda não foi criado

    memset(cli, 0, sizeof(cli));
    int cod;
    char nome[TAM], cpf[TAM], tel[TAM], email[TAM], cidade[TAM];

    while (fscanf(lista_clientes, "%d;%49[^;];%49[^;];%49[^;];%49[^;];%49[^\n]\n", 
                  &cod, nome, cpf, tel, email, cidade) == 6) {
        if (cod >= 1 && cod <= 1000) {
            cli[cod - 1].codigo = cod;
            strcpy(cli[cod - 1].nome, nome);
            strcpy(cli[cod - 1].cpf, cpf);
            strcpy(cli[cod - 1].telefone, tel);
            strcpy(cli[cod - 1].email, email);
            strcpy(cli[cod - 1].cidade, cidade);
        }
    }
}
// Salva os dados no arquivo
void salvarclientes() {
    lista_clientes = fopen("clientes.txt", "w");
    if (lista_clientes == NULL) return;

    for (int i = 0; i < 1000; i++) {
        if (cli[i].codigo > 0 && strlen(cli[i].nome) > 0) {
            fprintf(lista_clientes, "%d;%s;%s;%s;%s;%s\n", 
                    cli[i].codigo, cli[i].nome, cli[i].cpf, 
                    cli[i].telefone, cli[i].email, cli[i].cidade);
        }
    }
    fclose(lista_clientes);
}

void cabecalho()
{

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||    $$$$$$$$\\ $$$$$$$$\\  $$$$$$\\   $$$$$$\\  $$$$$$$\\  $$$$$$$$\\           ||\n");
    printf("||    $$  _____|$$  _____|$$  __$$\\ $$  __$$\\ $$  __$$\\ $$  _____|          ||\n");
    printf("||    $$ |      $$ |      $$ /  \\__|$$ /  $$ |$$ |  $$ |$$ |                ||\n");
    printf("||    $$$$$\\    $$$$$\\    $$ |      $$ |  $$ |$$$$$$$  |$$$$$\\              ||\n");
    printf("||    $$  __|   $$  __|   $$ |      $$ |  $$ |$$  __$$< $$  __|             ||\n");
    printf("||    $$ |      $$ |      $$ |  $$\\ $$ |  $$ |$$ |  $$ |$$ |                ||\n");
    printf("||    $$ |      $$$$$$$$\\ \\$$$$$$  | $$$$$$  |$$ |  $$ |$$$$$$$$\\           ||\n");
    printf("||    \\__|      \\________| \\______/  \\______/ \\__|  \\__|\\________|          ||\n");
    printf("||                                                                          ||\n");
    printf("||              FERRAMENTA EMPRESARIAL DE CONTROLE E REGISTRO               ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");

}

void menuPrincipal()

{   printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                                                                          ||\n");
    printf("||                         MENU PRINCIPAL                                   ||\n");
    printf("||                                                                          ||\n");
    printf("||  Selecione uma opção:                                                    ||\n");
    printf("||                                                                          ||\n");
    printf("||        [1] CLIENTES                    [2] PRODUTOS                      ||\n");
    printf("||                                                                          ||\n");
    printf("||        [3] ESTATÍSTICAS                [0] SAIR                          ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||  SISTEMA: ONLINE                                      FECORE BETA v1.0   ||\n");
    printf("==============================================================================\n");

}
void clientes(){
   int opc;  int c;
do{ 
    system("cls");
    carregarclientes();
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                         MENU CLIENTES                                    ||\n");
    printf("||                                                                          ||\n");
    printf("||  Selecione uma opção:                                                    ||\n");
    printf("||                                                                          ||\n");
    printf("||        [1] CADASTRAR                   [2] LISTAR                        ||\n");
    printf("||                                                                          ||\n");
    printf("||        [3] BUSCAR POR CÓDIGO           [4] ALTERAR                       ||\n");
    printf("||                                                                          ||\n");
    printf("||        [5] EXCLUIR                     [0] VOLTAR                        ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||  SISTEMA: ONLINE                                      FECORE BETA v1.0   ||\n");
    printf("==============================================================================\n");
   scanf("%d",&opc);
        if (opc==1){

        // OPÇÃO CADASTRAR

        system("cls");
        lista_clientes = fopen("clientes.txt","a");
        // Cria o File txt para armazenar os dados dos clientes em CSV.
        printf("Digite o código do cliente para cadastro: (de 1 a 1000) \n");
        scanf("%d",&c);
            while(c<1 || c>1000){
                printf("Código inválido, digite um código entre 1 e 1000\n");
                scanf("%d",&c);
            }
            cli[c - 1].codigo = c;
            if(strlen(cli[c-1].nome)>0){
                printf("Cliente já cadastrado, pressione qualquer tecla para voltar ao menu clientes\n");
                system("pause");
            }
            else{
            fflush(stdin);
            printf("Digite o nome do cliente para cadastro: \n");
                gets(cli[c-1].nome);
            printf("Digite o CPF do cliente para cadastro (somente números): \n");
                gets(cli[c-1].cpf);
            printf("Digite o telefone do cliente para cadastro (somente números): \n");
                gets(cli[c-1].telefone);
            printf("Digite o email do cliente para cadastro: \n");
                gets(cli[c-1].email);
            printf("Digite a cidade do cliente para cadastro: \n");
                gets(cli[c-1].cidade);
                fprintf(lista_clientes,"%d;%s;%s;%s;%s;%s\n",cli[c-1].codigo,cli[c-1].nome,cli[c-1].cpf,cli[c-1].telefone,cli[c-1].email,cli[c-1].cidade);
            salvarclientes();
            //salva os dados do cliente no arquivo.
            printf("CLIENTE CADASTRADO COM SUCESSO DIGITE ENTER PARA VOLTAR AO MENU CLIENTES\n");
        system("pause");}
            
    }
        else if (opc==2) 

        // OPÇÃO LISTAR
    {
        system("cls");
        int cad=0;
        printf("LISTA DE CLIENTES CADASTRADOS:\n");
            for(int i=0;i<1000;i++){
                if(strlen(cli[i].nome)>0){
                    printf("Código: %d\t ||",i+1);
                    printf("Nome: %s\t ||",cli[i].nome);
                    printf("CPF: %s\t ||",cli[i].cpf);
                    printf("Telefone: %s\t ||",cli[i].telefone);
                    printf("Email: %s\t ||",cli[i].email);
                    printf("Cidade: %s\n",cli[i].cidade);
                    printf("\n");
                    cad++;
                }
                
            }
            salvarclientes();
    printf("FOI ENCONTRADO O TOTAL %d DE CLIENTES CADASTRADOS PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU CLIENTES \n",cad);
   
        system("pause");
        
    }

        else if (opc==3){system("cls");

     //OPÇÃO BUSCAR       
    printf("Digite o código para busca: \n");
    scanf("%d",&c);
        if(c<1 || c>1000){
                printf("Código inválido, digite um código entre 1 e 1000\n");
                scanf("%d",&c);}
        else if(strlen(cli[c-1].nome)==0){
            printf("Cliente não encontrado, pressione qualquer tecla para voltar ao menu clientes\n");
            system("pause");
        }printf("Código: %d\t ||",c+1);
                    printf("Nome: %s\t ||",cli[c-1].nome);
                    printf("CPF: %s\t ||",cli[c-1].cpf);
                    printf("Telefone: %s\t ||",cli[c-1].telefone);
                    printf("Email: %s\t ||",cli[c-1].email);
                    printf("Cidade: %s\n",cli[c-1].cidade);
                    printf("\n");
                printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU CLIENTES \n");
                system("pause");
    }
        else if (opc==4){system("cls"); 
            // OPÇÃO ALTERAR
    printf("Digite o código do cliente para alteração: \n");
    scanf("%d",&c);
    lista_clientes=fopen("clientes.txt","a");
             if(c<1 || c>1000){
                printf("Código inválido, digite um código entre 1 e 1000\n");
                scanf("%d",&c);}
            else if(strlen(cli[c-1].nome)>0){
            cli[c - 1].codigo = c;
            fflush(stdin);
            printf("Digite o novo nome do cliente: \n");
                gets(cli[c-1].nome);
            printf("Digite o novo CPF do cliente (somente números): \n");
                gets(cli[c-1].cpf);
            printf("Digite o novo telefone do cliente (somente números): \n");
                gets(cli[c-1].telefone);
            printf("Digite o novo email do cliente: \n");
                gets(cli[c-1].email);
            printf("Digite a nova cidade do cliente: \n");
                gets(cli[c-1].cidade);
            printf("CLIENTE ALTERADO COM SUCESSO DIGITE ENTER PARA VOLTAR AO MENU CLIENTES\n");
        system("pause");}
            else{printf("CLIENTE NÃO ENCONTRADO, PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU CLIENTES \n");}
            system("pause");
    }
        else if (opc==5){system("cls");
        
            //OPÇÃO EXCLUIR

    printf("Digite o código do cliente que deseja excluir:\n");
    scanf("%d",&c);
    if(c<1 || c>1000){
                printf("Código inválido, digite um código entre 1 e 1000\n");
                scanf("%d",&c);}
            else if(strlen(cli[c-1].nome)>0){
            cli[c - 1].codigo = 0;
            strcpy(cli[c-1].nome,"");
            strcpy(cli[c-1].cpf,"");
            strcpy(cli[c-1].telefone,"");
            strcpy(cli[c-1].email,"");
            strcpy(cli[c-1].cidade,"");
            salvarclientes();
            printf("CLIENTE EXCLUÍDO COM SUCESSO DIGITE ENTER PARA VOLTAR AO MENU CLIENTES\n");}
            else if (strlen(cli[c-1].nome)==0){printf("CLIENTE NÃO ENCONTRADO, PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU CLIENTES \n");}
            system("pause");
    }

        else if (opc==0){system("cls");
    printf("VOLTANDO AO MENU PRINCIPAL\n");
    break;
    }
        else{system("cls");
    printf("OPÇÃO INVÁLIDA\n\n");
} 
}while (opc!=0);

}
    
void produtos(){
int opp;
do{
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                         MENU PRODUTOS                                    ||\n");
    printf("||                                                                          ||\n");
    printf("||  Selecione uma opção:                                                    ||\n");
    printf("||                                                                          ||\n");
    printf("||        [1] CADASTRAR                   [2] LISTAR                        ||\n");
    printf("||                                                                          ||\n");
    printf("||        [3] BUSCAR                      [4] ALTERAR                       ||\n");
    printf("||                                                                          ||\n");
    printf("||        [5] EXCLUIR                     [0] VOLTAR                        ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||  SISTEMA: ONLINE                                      FECORE BETA v1.0   ||\n");
    printf("==============================================================================\n");
scanf("%d",&opp);
        if (opp==1){system("cls");
    printf("AQUI FICA O CADASTRO DE PRODUTOS\n");
    }
        else if (opp==2){system("cls");
    printf("AQUI FICA A LISTA DE PRODUTOS\n");
    }
        else if (opp==3){system("cls");
    printf("AQUI FICA A BUSCA DE PRODUTOS\n");
    }
        else if (opp==4){system("cls");
    printf("AQUI FICA A ALTERAÇÃO DE PRODUTOS\n");
    }
        else if (opp==5){system("cls");
    printf("AQUI FICA A EXCLUSÃO DE PRODUTOS\n");
    }
        else if (opp==0){system("cls");
    printf("VOLTANDO AO MENU PRINCIPAL\n");
    break;
    }
        else{system("cls");
    printf("OPÇÃO INVÁLIDA\n\n");
    }
}while (opp!=0);
}

void estatisticas(){
int ope;
do{
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                         MENU ESTATÍSTICAS                                ||\n");
    printf("||                                                                          ||\n");
    printf("||  Selecione uma opção:                                                    ||\n");
    printf("||                                                                          ||\n");
    printf("||        [1] RELATÓRIO CLIENTES             [2] RELATÓRIO PRODUTOS         ||\n");
    printf("||                                                                          ||\n");
    printf("||        [3] RELATÓRIO ESTOQUE              [4] RELATÓRIO VENDAS           ||\n"); 
    printf("||                                                                          ||\n");
    printf("||        [0] VOLTAR                                                        ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||  SISTEMA: ONLINE                                      FECORE BETA v1.0   ||\n");
    printf("==============================================================================\n");
scanf("%d",&ope);
        if (ope==1){system("cls");
    printf("AQUI FICA O RELATÓRIO DE CLIENTES\n");
    }
        else if (ope==2){system("cls");
    printf("AQUI FICA O RELATÓRIO DE PRODUTOS\n");
    }
        else if (ope==3){system("cls");
    printf("AQUI FICA O RELATÓRIO DE ESTOQUE\n");
    }
        else if (ope==4){system("cls");
    printf("AQUI FICA O RELATÓRIO DE VENDAS\n");
    }
        else if (ope==0){system("cls");
    printf("VOLTANDO AO MENU PRINCIPAL\n");
    break;
    }
        else{system("cls");
    printf("OPÇÃO INVÁLIDA\n\n");
    }
}while (ope!=0);
}

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int op;
do{    cabecalho();
    menuPrincipal();
        scanf("%d",&op);
if(op==1){system("cls");
    clientes();
    }
else if(op==2){system("cls");
    produtos();
    }    
else if(op==3){system("cls");
    estatisticas();
    }
else if(op==0){system("cls");
    printf("\nSAINDO...\n");
    break;
    }
else{system("cls");
    printf("OPÇÃO INVÁLIDA\n\n");
    }
}
while (op!=0);

    return 0;
}