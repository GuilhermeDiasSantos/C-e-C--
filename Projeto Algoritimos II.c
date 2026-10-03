#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#define TAM 50

struct cliente{
    char nome[TAM];
    char cpf [TAM];
    char telefone[TAM];
    char email[TAM];
    char cidade[TAM];
    int codigo;
};
typedef struct cliente cli;

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
   int opc; struct cliente cli [100] ={0}; int c;
do{ 
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
        if (opc==1)
    {
        system("cls");
        printf("Digite o código do cliente para cadastro: (de 1 a 100) \n");
        scanf("%d",&c);
            while(c<1 || c>100){
                printf("Código inválido, digite um código entre 1 e 100\n");
                scanf("%d",&c);
            }
            cli[c - 1].codigo = c;
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
            printf("CLIENTE CADASTRADO COM SUCESSO DIGITE ENTER PARA VOLTAR AO MENU CLIENTES\n");
        system("pause");
        
            
    }
        else if (opc==2)
    {
        system("cls");
        int cad=0;
        printf("LISTA DE CLIENTES CADASTRADOS:\n");
            for(int i=0;i<100;i++){
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
    printf("FOI ENCONTRADO O TOTAL %d DE CLIENTES CADASTRADOS PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU CLIENTES \n",cad);
   
        system("pause");
        
    }

        else if (opc==3){system("cls");
            
    printf("Digite o código para busca: \n");
    scanf("%d",&c);
        if(c<1 || c>100){
                printf("Código inválido, digite um código entre 1 e 100\n");
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
    }
        else if (opc==4){system("cls");
    printf("AQUI FICA A ALTERAÇÃO DE CLIENTES\n");
    }
        else if (opc==5){system("cls");
    printf("AQUI FICA A EXCLUSÃO DE CLIENTES\n");
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