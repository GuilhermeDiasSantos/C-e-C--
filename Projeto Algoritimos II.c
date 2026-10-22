#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#define TAM 50
FILE *lista_clientes;
FILE *lista_produtos;
FILE *lista_vendas;
struct cliente{
    char nome[TAM];
    char cpf [TAM];
    char telefone[TAM];
    char email[TAM];
    char cidade[TAM];
    int codigo;
};
struct produto{
    char nome[TAM];
    char categoria[TAM];
    int estoque;
    int codigo;
    float preco;
};
struct venda{
    int codigo_venda;
    int codigo_cliente;
    int codigo_produto;
    int quantidade;
    float valor_total;
};
struct venda ven [1000]={0};
struct cliente cli [1000]={0};
struct produto prod [1000]={0};

// Carrega os dados salvos do arquivo
void carregarclientes() {
    lista_clientes = fopen("clientes.txt", "r");
    if (lista_clientes == NULL) return; 

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

void carregarprodutos() {
    lista_produtos = fopen("produtos.txt", "r");
    if (lista_produtos == NULL) return; 

    memset(prod, 0, sizeof(prod));
    int cod;
    char nome[TAM], categoria[TAM];
    int estoque;
    float preco;

    while (fscanf(lista_produtos, "%d;%49[^;];%49[^;];%d;%f\n", 
                  &cod, nome, categoria, &estoque, &preco) == 5) {
        if (cod >= 1 && cod <= 1000) {
            prod[cod - 1].codigo = cod;
            strcpy(prod[cod - 1].nome, nome);
            strcpy(prod[cod - 1].categoria, categoria);
            prod[cod - 1].estoque = estoque;
            prod[cod - 1].preco = preco;
        }
    }
}
void salvarprodutos() {
    lista_produtos = fopen("produtos.txt", "w");
    if (lista_produtos == NULL) return;

    for (int i = 0; i < 1000; i++) {
        if (prod[i].codigo > 0 && strlen(prod[i].nome) > 0) {
            fprintf(lista_produtos, "%d;%s;%s;%d;%.2f\n", 
                    prod[i].codigo, prod[i].nome, prod[i].categoria, 
                    prod[i].estoque, prod[i].preco);
        }
    }
    fclose(lista_produtos);
}
void carregarvendas() {
    lista_vendas = fopen("vendas.txt", "r");
    if (lista_vendas == NULL) return;

    memset(ven, 0, sizeof(ven));
    int cod_v, cod_c, cod_p, qtd;
    float v_total;

    while (fscanf(lista_vendas, "%d;%d;%d;%d;%f\n", &cod_v, &cod_c, &cod_p, &qtd, &v_total) == 5) {
        if (cod_v >= 1 && cod_v <= 1000) {
            ven[cod_v - 1].codigo_venda = cod_v;
            ven[cod_v - 1].codigo_cliente = cod_c;
            ven[cod_v - 1].codigo_produto = cod_p;
            ven[cod_v - 1].quantidade = qtd;
            ven[cod_v - 1].valor_total = v_total;
        }
    }
    fclose(lista_vendas);
}

void salvarvendas() {
    lista_vendas = fopen("vendas.txt", "w");
    if (lista_vendas == NULL) return;

    for (int i = 0; i < 1000; i++) {
        if (ven[i].codigo_venda > 0) {
            fprintf(lista_vendas, "%d;%d;%d;%d;%.2f\n", 
                    ven[i].codigo_venda, ven[i].codigo_cliente, 
                    ven[i].codigo_produto, ven[i].quantidade, ven[i].valor_total);
        }
    }
    fclose(lista_vendas);
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
    printf("||        [3] VENDAS                      [4] RELATÓRIOS                    ||\n");
    printf("||                                                                          ||\n");
    printf("||        [0] SAIR                                                          ||\n");
    printf("||                                                                          ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||  SISTEMA: ONLINE                                      FECORE BETA v1.0   ||\n");
    printf("==============================================================================\n");

}
void clientes(){
   int opc;  int c;
do{ 
    system("cls");
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
        carregarclientes();
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
            salvarclientes();
            //salva os dados do cliente no arquivo.
            printf("CLIENTE CADASTRADO COM SUCESSO DIGITE ENTER PARA VOLTAR AO MENU CLIENTES\n");
        system("pause");}
            
    }
        else if (opc==2) 

        // OPÇÃO LISTAR
    {
        carregarclientes();
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
    printf("FOI ENCONTRADO O TOTAL %d DE CLIENTES CADASTRADOS PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU CLIENTES \n",cad);
   
        system("pause");
        
    }

        else if (opc==3){system("cls");

     //OPÇÃO BUSCAR       
     carregarclientes();
    printf("Digite o código para busca: \n");
    scanf("%d",&c);
        while(c<1 || c>1000){
                printf("Código inválido, digite um código entre 1 e 1000\n");
                scanf("%d",&c);}
        if(strlen(cli[c-1].nome)==0){
            printf("Cliente não encontrado, pressione qualquer tecla para voltar ao menu clientes\n");
           
        }
        else{printf("Código: %d\t ||",c);
                    printf("Nome: %s\t ||",cli[c-1].nome);
                    printf("CPF: %s\t ||",cli[c-1].cpf);
                    printf("Telefone: %s\t ||",cli[c-1].telefone);
                    printf("Email: %s\t ||",cli[c-1].email);
                    printf("Cidade: %s\n",cli[c-1].cidade);
                    printf("\n");}
                printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU CLIENTES \n");
                system("pause");
    }
        else if (opc==4){system("cls"); 
            // OPÇÃO ALTERAR
    printf("Digite o código do cliente para alteração: \n");
    scanf("%d",&c);
    carregarclientes();
             while(c<1 || c>1000){
                printf("Código inválido, digite um código entre 1 e 1000\n");
                scanf("%d",&c);}
            if(strlen(cli[c-1].nome)>0){
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
            salvarclientes();
        }
            else{printf("CLIENTE NÃO ENCONTRADO, PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU CLIENTES \n");}
            
            system("pause");
    }
        else if (opc==5){system("cls");
        
            //OPÇÃO EXCLUIR

    printf("Digite o código do cliente que deseja excluir:\n");
    scanf("%d",&c);
    while(c<1 || c>1000){
                printf("Código inválido, digite um código entre 1 e 1000\n");
                scanf("%d",&c);}
            if(strlen(cli[c-1].nome)>0){
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
int opp, p;
do{system("cls");
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
// OPÇÃO CADASTRAR PRODUTOS
        if (opp==1){system("cls");
            carregarprodutos();
            printf("Digite o código do produto para cadastro: (de 1 a 1000) \n");
            scanf("%d",&p);
     while(p<1 || p>1000){
                printf("Código inválido, digite um código entre 1 e 1000\n");
                scanf("%d",&p);
            }
            prod[p - 1].codigo = p;
            if(strlen(prod[p-1].nome)>0){
                printf("Produto já cadastrado, pressione qualquer tecla para voltar ao menu produtos\n");
                system("pause");
            }
            else{
            fflush(stdin);
            printf("Digite o nome do produto para cadastro: \n");
                gets(prod[p-1].nome);
            printf("Digite a categoria do produto para cadastro: \n"); 
                gets(prod[p-1].categoria);
            printf("Digite o preço do produto para cadastro: \n");
               scanf("%f",&prod[p-1].preco);
            printf("Digite a quantidade do produto para cadastro: \n");
                scanf("%d",&prod[p-1].estoque);
            
            //salva os dados do produto no arquivo.
            printf("PRODUTO CADASTRADO COM SUCESSO DIGITE ENTER PARA VOLTAR AO MENU PRODUTOS\n");
            salvarprodutos();
        system("pause");}



    }
    //OPÇÃO LISTAR PRODUTOS
        else if (opp==2){system("cls");
        carregarprodutos();
        system("cls");
        int cad=0;
        printf("LISTA DE PRODUTOS CADASTRADOS:\n");
            for(int i=0;i<1000;i++){
                if(strlen(prod[i].nome)>0){
                    printf("Código: %d\t ||",i+1);
                    printf("Nome: %s\t ||",prod[i].nome);
                    printf("Categoria: %s\t ||",prod[i].categoria);
                    printf("Preço: %.2f\t ||",prod[i].preco);
                    printf("Estoque: %d\n",prod[i].estoque);
                    printf("\n");
                    cad++;
                }
                
            }
    printf("FOI ENCONTRADO O TOTAL %d DE PRODUTOS CADASTRADOS PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRODUTOS \n",cad);
   
        system("pause");
        
    }
    //OPÇÃO BUSCAR PRODUTOS
        else if (opp==3){system("cls");
            carregarprodutos();
    printf("Digite o código para busca: \n");
    scanf("%d",&p);
        while(p<1 || p>1000){
                printf("Código inválido, digite um código entre 1 e 1000\n");
                scanf("%d",&p);}
        if(strlen(prod[p-1].nome)==0){
            printf("Produto não encontrado, pressione qualquer tecla para voltar ao menu produtos\n");
           
        }
        else{printf("Código: %d\t ||",p);
                    printf("Nome: %s\t ||",prod[p-1].nome);
                    printf("Categoria: %s\t ||",prod[p-1].categoria);
                    printf("Preço: %.2f\t ||",prod[p-1].preco);
                    printf("Estoque: %d\n",prod[p-1].estoque);
                    printf("\n");}
                printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRODUTOS \n");
                system("pause");
    }
        else if (opp==4){system("cls");
    printf("Digite o código do produto para alteração: \n");
    scanf("%d",&p);
    carregarprodutos();
             while(p<1 || p>1000){
                printf("Código inválido, digite um código entre 1 e 1000\n");
                scanf("%d",&p);}
            if(strlen(prod[p-1].nome)>0){
            prod[p - 1].codigo = p;
            fflush(stdin);
            printf("Digite o novo nome do produto: \n");
                gets(prod[p-1].nome);
            printf("Digite a nova categoria do produto: \n");
                gets(prod[p-1].categoria);
            printf("Digite o novo preço do produto: \n");
                scanf("%f",&prod[p-1].preco);
            printf("Digite o novo estoque do produto: \n");
                scanf("%d",&prod[p-1].estoque);            
            printf("PRODUTO ALTERADO COM SUCESSO DIGITE ENTER PARA VOLTAR AO MENU PRODUTOS\n");
            salvarprodutos();
        }
            else{printf("PRODUTO NÃO ENCONTRADO, PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRODUTOS \n");}
            
            system("pause");
    }
        else if(opp==5){system("cls");
            carregarprodutos();
    printf("Digite o código do produto que deseja excluir:\n");
    scanf("%d",&p);
    while(p<1 || p>1000){
                printf("Código inválido, digite um código entre 1 e 1000\n");
                scanf("%d",&p);}
            if(strlen(prod[p-1].nome)>0){
            prod[p - 1].codigo = 0;
            strcpy(prod[p-1].nome,"");
            strcpy(prod[p-1].categoria,"");
            salvarprodutos();
            printf("PRODUTO EXCLUÍDO COM SUCESSO DIGITE ENTER PARA VOLTAR AO MENU PRODUTOS\n");}
            else if (strlen(prod[p-1].nome)==0){
                printf("PRODUTO NÃO ENCONTRADO, PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRODUTOS \n");}
            system("pause");
    }
    
    else if(opp==0){system("cls");

    printf("VOLTANDO AO MENU PRINCIPAL\n");
    break;
    }
        else{system("cls");
    printf("OPÇÃO INVÁLIDA\n\n");
    }
}while (opp!=0);
}
void vendas(){
int opv,v,cod;
do{
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                         MENU VENDAS                                      ||\n");
    printf("||                                                                          ||\n");
    printf("||  Selecione uma opção:                                                    ||\n");
    printf("||                                                                          ||\n");
    printf("||        [1] REGISTRAR VENDA                 [2] LISTAR VENDAS             ||\n");
    printf("||                                                                          ||\n");
    printf("||        [0] VOLTAR                                                        ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||  SISTEMA: ONLINE                                      FECORE BETA v1.0   ||\n");
    printf("==============================================================================\n"); 
scanf("%d",&opv);
    if (opv == 1){system("cls");
        carregarclientes();
        carregarprodutos();
        carregarvendas();
        printf("Digite o código do cliente para a venda:\n");
        scanf("%d", &cod);
        while (cod < 1 || cod > 1000) {
            printf("Código inválido, digite um código entre 1 e 1000\n");
            scanf("%d", &cod);
            }
    if (strlen(cli[cod - 1].nome) == 0) {
            printf("Cliente não encontrado, pressione qualquer tecla para voltar ao menu vendas\n");
            system("pause");
            } 
    else{
        int qtd;
        int num_venda = 1;
        printf("Digite o código do produto para venda:\n");
        scanf("%d", &v);
        while (v < 1 || v > 1000) {
        printf("Código inválido, digite um código entre 1 e 1000\n");
            scanf("%d", &v);}
        if (strlen(prod[v - 1].nome) == 0) {
                    printf("Produto não encontrado, pressione qualquer tecla para voltar ao menu vendas\n");
                    system("pause");
                } 
        else {
            printf("Digite a quantidade desejada:\n");
            scanf("%d", &qtd);

        while (qtd <= 0) {
            printf("Quantidade inválida, digite um valor maior que 0:\n");
            scanf("%d", &qtd);}
        if (qtd > prod[v - 1].estoque) {
        printf("Estoque insuficiente! Estoque atual: %d unidades\n", prod[v - 1].estoque);
        printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU VENDAS\n");
        system("pause");} 
        else{
        prod[v - 1].estoque -= qtd;         
         printf("VENDA REGISTRADA COM SUCESSO, PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU VENDAS\n");
    system("pause");    
        while (ven[num_venda - 1].codigo_venda > 0 && num_venda <= 1000) {num_venda++;}}
                        
        
        salvarprodutos();

                    //substitui os dados

        ven[num_venda - 1].codigo_venda = num_venda;
        ven[num_venda - 1].codigo_cliente = cod;
        ven[num_venda - 1].codigo_produto = v;
        ven[num_venda - 1].quantidade = qtd;
        ven[num_venda - 1].valor_total = qtd * prod[v - 1].preco;

        salvarprodutos();
        salvarvendas();}}
   
    }

else if (opv == 2) {
            // OPÇÃO LISTAR VENDAS
        carregarclientes();
        carregarprodutos();
        carregarvendas();
        system("cls");
        int total_vendas = 0;
        printf("LISTA DE VENDAS REGISTRADAS:\n\n");
            for (int i = 0; i < 1000; i++) {
            if (ven[i].codigo_venda > 0) {
            int c_cod = ven[i].codigo_cliente - 1;
            int p_cod = ven[i].codigo_produto - 1;

            printf("Cód. Venda: %d || ", ven[i].codigo_venda);
            printf("Cliente: %s (Cód %d) || ", cli[c_cod].nome, ven[i].codigo_cliente);
            printf("Produto: %s (Cód %d) || ", prod[p_cod].nome, ven[i].codigo_produto);
            printf("Qtd: %d || ", ven[i].quantidade);
            printf("Total: R$ %.2f\n", ven[i].valor_total);
            total_vendas++;
                }
            }
            printf("\nTOTAL DE VENDAS REALIZADAS: %d\n", total_vendas);
            printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU VENDAS\n");
            system("pause");
        }
        else if (opv == 0) {
            system("cls");
            printf("VOLTANDO AO MENU PRINCIPAL\n");
            break;
        }
        else {
            system("cls");
            printf("OPÇÃO INVÁLIDA\n\n");
            system("pause");
        }


}
while (opv!=0);
}
void relatorios(){
int opr;
do{
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                         MENU RELATÓRIOS                                  ||\n");
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
scanf("%d",&opr);
        if (opr==1){system("cls");
    printf("AQUI FICA O RELATÓRIO DE CLIENTES\n");
    }
        else if (opr==2){system("cls");
    printf("AQUI FICA O RELATÓRIO DE PRODUTOS\n");
    }
        else if (opr==3){system("cls");
    printf("AQUI FICA O RELATÓRIO DE ESTOQUE\n");
    }
        else if (opr==4){system("cls");
    printf("AQUI FICA O RELATÓRIO DE VENDAS\n");
    }
        else if (opr==0){system("cls");
    printf("VOLTANDO AO MENU PRINCIPAL\n");
    break;
    }
        else{system("cls");
    printf("OPÇÃO INVÁLIDA\n\n");
    }
}while (opr!=0);
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
    vendas();
    }
else if(op==4){system("csls");
    relatorios();
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