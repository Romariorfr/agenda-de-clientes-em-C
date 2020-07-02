#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

    //variaveis globais
    const int limit_register = 1;   //limite de cadastros
    int user_code = 0; 
	
    
    // estrutura de registro de clientes
    struct registerClient{
		char Name[50];
		char Tell[20];
		char Email[50];
	};
     
	struct registerClient reg;
	struct registerClient dateBook[limit_register];	//agenda de 5 posicoes
	

//imprime o titulo e menu do programa
void menuApplication(){
	printf("--------------- AGENDA - VERSAO BETA ----------------\n\n");
	printf("1 - Didite 1 para inserir novo cadastro:\n");
	printf("2 - Didite 2 para mostrar clientes cadastrados:\n");
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

int checkLimit(){
	bool check = false;
	if(user_code < limit_register){
		printf("tem vaga");
		check = true;
		system("PAUSE");
	}
	else{
		printf("agenda lotada");
		check = false;
	}
	return check;
	
}



//funcao principal
int main(){
	
	//exibe o titulo da aplicacao
	menuApplication();
	
	
	switch (menuOptions()){
		case 1:
			if(checkLimit() == true){
				cleanScreen(); // limpa a tela
			    getDataClient();  //solicita os dados do cliente
			    saveApointment(reg); //salva os registro na agenda na posicao
			}
			
		break;
		
		case 2:
			if(user_code != 0){
				printf("%s ",dateBook[0].Name);
	            printf("%s ",dateBook[0].Email);
	            printf("%s ",dateBook[0].Tell);
			}
			else{
				cleanScreen();
				printf("Agenda Vazia!");
			}
			
		break;
		
		case 0:
			
		    exit(0);
		    
		break;
		
		default :
			
		     printf("erro;");
				
	} 

	
}


