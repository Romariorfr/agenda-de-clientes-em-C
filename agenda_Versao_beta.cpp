#include<stdio.h>
#include<stdlib.h>
#include<string.h>

    // estrutura de registro de clientes
    int position_code = 0;
    const int maximoDeClient = 5;
    struct registerClient{
		char Name[50];
		char Tell[20];
		char Email[50];
	};
     
    
	struct registerClient reg;
	struct registerClient dateBook[maximoDeClient];	
	
	
void titleAplication(){
	printf("--------------- AGENDA - VERSAO BETA ----------------\n\n");
}

int menuOptions(){
	int response;
	printf("1 - Didite 1 para inserir novo cadastro:\n");
	printf("2 - Didite 2 para mostrar clientes cadastrados:\n");
	printf("0 - Digite 0 para encerrar:\n\n");
	scanf("%d",&response);
	fflush(stdin);
	return response;
}

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

void cleanScreen(){
	system("cls");
}

void saveApointment(registerClient r){
	dateBook[position_code] = r;
	position_code++;
}



//funcao principal
int main(){
	
	//exibe o titulo da aplicacao
	titleAplication();
	
	//exibe o menu para o usuario e trata a selecao do comando escolhido
	switch (menuOptions()){
		case 1:
			
			cleanScreen(); // limpa a tela
			getDataClient();  //solicita os dados do cliente
			saveApointment(reg); //salva os registro na agenda na posicao
		
			
		break;
		
		case 2:
			
			if(position_code != 0){
				
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


