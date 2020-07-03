#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

    //variaveis globais
    const int limit_register = 5;   //limite de cadastros
    int user_code = 0; //codigo do usuario
	
    
    // estrutura de registro de clientes
    struct registerClient{
		char Name[50];
		char Tell[20];
		char Email[50];
		int code;
	};
     
	struct registerClient reg;
	struct registerClient dateBook[limit_register];	//agenda de 5 posicoes
	

//imprime o titulo e menu do programa
void menuApplication(){
	printf("--------------- AGENDA - VERSAO BETA ----------------\n\n");
	printf("1 - Digite 1 para inserir novo cadastro:\n");
	printf("2 - Digite 2 para mostrar clientes cadastrados:\n");
	printf("0 - Digite 0 para encerrar:\n\n");
}

//retorna a resposta do usuario
int menuOptions(){
	int response;
	scanf("%d",&response);
	fflush(stdin);
	return response;
}

//recebe os dados dos clientes
void getDataClient(){
	
	printf("Insira o nome do Cliente:\n");
	gets(reg.Name);
	printf("\n");
	
	printf("Insira o telefone do Cliente:\n");
	gets(reg.Tell);
	printf("\n");
	
	printf("Insira o e-mail do Cliente:\n");
	gets(reg.Email);
	printf("\n");
	
	reg.code = user_code; 
	
}

//limpa a tela
void cleanScreen(){
	system("cls");
}

//pega o registro do cliente e armazena na agenda
void saveApointment(registerClient r){
	dateBook[user_code] = r;
	user_code++;
}

//verifica se ha espaco na agenda
int checkLimit(){
	bool check = false;
	if(user_code < limit_register){
		check = true;
	}
	else{
		printf("agenda lotada\n");
		system("PAUSE");
		check = false;
	}
	return check;
	
}

//exibe a lista de clientes cadastrados na tela
void show_list_client(){
	int i = 0;
	while( i < user_code){
		printf("***Codigo do cliente %d\n",dateBook[i].code);
		printf("%s\n",dateBook[i].Name);
	    printf("%s\n",dateBook[i].Email);
	    printf("%s\n\n",dateBook[i].Tell);
	    i++;
	}
}

//funcao principal
int main(){
	
	while (true){
		
		cleanScreen();
		menuApplication();
		
			switch (menuOptions()){
		case 1:
			if(checkLimit() == true){
				cleanScreen(); // limpa a tela
			    getDataClient();  //solicita os dados do cliente
			    saveApointment(reg); //salva os registro na agenda
			}
			
		break;
		
		case 2:
			if(user_code != 0){
				cleanScreen(); //limpa a tela
			    show_list_client(); //mostra a lista de clientes cadastrados
	            system("PAUSE");
			}
			else{
				cleanScreen();
				printf("Agenda Vazia!\n");
				system("PAUSE");
			}
			
		break;
		
		case 0:
			
		    exit(0); //finaliza o programa
		    
		break;
		
		default :
			
		     printf("Opcao invalida!\n");
		     system("PAUSE");
				
	        }
	}
}


