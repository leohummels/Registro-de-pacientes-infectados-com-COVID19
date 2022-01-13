#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#define SIZE 200


struct pessoa {
char login;
char senha;
char quais[SIZE][60];
char cidade[SIZE][60];
char nome[SIZE][60];
char resultado[SIZE][20];
char email[SIZE][60];
char RG[SIZE][60];
char CEP[SIZE][60];
char sexo;
char CPF[SIZE][60];
char telefone[SIZE][60];
char residencia[SIZE][60];
char nascimento[SIZE][60];
};

struct user {

char *login;
char *senha;
};

struct user user;
struct pessoa pessoa;
//GLOBAIS
char login[16];
char senha[16];
char comorbidade;
char iniciar[1];
char novamente;
int dia, mes, ano, validacao, compLogin, compSenha;
int funcaoDeLogin();
void cadastro();

//FUNCAO PRINCIPAL
int main(void){
       setlocale(LC_ALL, "Portuguese");

        if (funcaoDeLogin()==1) {
        fflush(stdin);

        printf("Seja bem vindo ao nosso site!\n");
        printf("Deseja iniciar sessão?(s ou n):\n");
        fgets(iniciar, 3, stdin);
        fflush(stdin);

        if (iniciar == "s" || iniciar == "S");{
            do {cadastro();
        printf("\n\n Deseja iniciar o formulario novamente? (s ou n)");
        fflush(stdin);
        scanf("%c", &novamente);

        if (novamente == 'n'||novamente == 'N');{
        printf("Finalizando formulario!\n\n");}

        fflush(stdin);
        }while(novamente == 's'||novamente == 'S');
        }
    }
}
       //FUNCAO DE LOGIN
int funcaoDeLogin() {

       user.login = "carol";
       user.senha = "123";

       printf("\nLOGIN DE USUARIO: ");
       //fgets(login, 15, stdin);
       scanf("%s", &login);
       printf("\n");

       printf("\nINSIRA A SENHA: ");
       fgets(senha, 15, stdin);
       scanf("%s",&senha);

       compLogin = strcmp(user.login,login);
       compSenha = strcmp(user.senha, senha);

       if((compLogin ==0)&&( compSenha == 0)){

        printf("\n\n");
        printf("USUARIO LOGADO COM SUCESSO!");
        printf("\n\n");
        return validacao = 1;}

        else{
        printf("login e/ou senha incorretos");
        return validacao = 0;
   }

};
//FUNCAO DE CADASTRO
void cadastro(){
       static int linha;

       //DE CALCULAR IDADE
       time_t tempo = time(NULL);
       struct tm tm = *localtime(&tempo);
       int diaAtual, mesAtual, anoAtual;

       diaAtual = tm.tm_mday;
       mesAtual = tm.tm_mon + 1;
       anoAtual = tm.tm_year + 1900;

 int idade;
 int calMes = mesAtual - mes;
 int calDia = diaAtual - dia;


        printf("Iniciando sessão....\n\n");


        printf("Nome: ");
        fgets(pessoa.nome[linha], 60, stdin);
        printf("\n\n");

        printf("Data de nascimento(DD/MM/YYYY): ");
        scanf("%d/%d/%d", &dia, &mes, &ano);
        //fgets(pessoa.nascimento[linha], 19, stdin);
        printf("\n\n");
        idade = anoAtual - ano;
        //calular idade
        if (mesAtual - mes < 0) {
        idade -= 1;
        }

        fflush(stdin);

        printf("Data de diagnostico de covid-19 : ");
        fgets(pessoa.resultado[linha], 20, stdin);

        //fgets(pessoa.resultado[linha], 60, stdin);
        printf("\n\n");

        printf("Apresenta algum tipo de comorbidade (S ou N)?");
        //fgets(comorbidade, 10, stdin);
        scanf("%c%*c", &comorbidade);
        printf ("\n\n");

        if (comorbidade == 's'|| comorbidade == 'S'){
        printf("Quais?");
        fgets(pessoa.quais[linha], 60, stdin);}
        printf ("\n\n");

        printf("Cidade e Estado: ");
        fgets(pessoa.cidade[linha], 60, stdin);
        printf("\n\n");

        printf("Endereço: ");
        fgets(pessoa.residencia[linha], 60, stdin);
        printf("\n\n");

        printf("CEP: ");
        fgets( pessoa.CEP[linha], 60, stdin);
        printf("\n\n");

        printf("E-mail: ");
        fgets(pessoa.email[linha], 60, stdin);
        printf ("\n\n");

        printf("CPF: ");
        fgets(pessoa.CPF[linha], 60, stdin);
        printf("\n\n");

        printf("RG: ");
        fgets(pessoa.RG[linha], 60, stdin);
        printf("\n\n");

        printf("Telefone: ");
        fgets(pessoa.telefone[linha], 60, stdin);
        printf("\n\n");

        //Sexo
        printf( "Qual o seu sexo:(F ou M)");
        do {
        //fgets(pessoa.sexo, 2, stdin);
        scanf("%c", &pessoa.sexo);}
        while(!(pessoa.sexo=='M' || !(pessoa.sexo=='m'))&&!(pessoa.sexo== 'F'||!(pessoa.sexo== 'f')));
        printf ("\n\n");

        printf("Dados respondidos pelo usuario\n");

        printf("\n Nome: %s", pessoa.nome[linha]);
        printf("\n Idade: %d", idade);
        printf("\n");
        printf("\n RG: %s", pessoa.RG[linha]);
        printf("\n CPF: %s", pessoa.CPF[linha]);
        printf("\n Telefone: %s", pessoa.telefone[linha]);
        printf("\n E-mail: %s", pessoa.email[linha]);
        printf("\n Comorbidade: %s", pessoa.quais[linha]);
        printf("\n CEP: %s", pessoa.CEP[linha]);
        printf("\n Cidade,estado: %s",pessoa.cidade[linha]);
        printf("\n Bairro, residencia: %s", pessoa.residencia[linha]);

        //Pacientes sem comorbidade

        FILE *point;

        point = fopen("ArquivoPacientes.txt", "a");
        fprintf(point,"Paciente: "); //Paciente
        fputs(pessoa.nome[linha], point);
        fprintf(point,"CPF: "); //CPF
        fputs(pessoa.CPF[linha], point);
        fprintf(point,"Telefone: "); //Telefone
        fputs(pessoa.telefone[linha], point);
        fprintf(point,"Endereço: "); //Endereço
        fputs(pessoa.residencia[linha], point);
        fprintf(point,"Cidade: ");
        fputs(pessoa.cidade[linha], point);
        fprintf(point,"CEP: ");
        fputs(pessoa.CEP[linha], point);
        fprintf(point,"Data de Nascimento: "); //Nascimento
        fprintf(point,"%d/%d/%d" , dia, mes, ano);
        fprintf(point,"\n");
        fprintf(point,"E-mail: "); //E-mail
        fputs(pessoa.email[linha], point);
        fprintf(point,"Data de diagnóstico: "); //Diagnóstico
        fputs(pessoa.CEP[linha], point);
        fprintf(point,"Comorbidade: ");
        fputs(pessoa.CEP[linha], point);
        fprintf(point,"\n");
        fclose(point);


        //Pacientes com comorbidade

        if ((comorbidade == 's'|| comorbidade == 'S')||(idade>65)){

        FILE *ponteiro;

        ponteiro = fopen("arquivoPacientesComorbidade.txt", "a");
        fprintf(ponteiro,"Paciente: ");
        fputs(pessoa.nome[linha], ponteiro);
        fprintf(ponteiro,"Idade: ");
        fprintf(ponteiro,"%d" ,idade);
        fprintf(ponteiro,"\n");
        fprintf(ponteiro,"CEP: ");
        fputs(pessoa.CEP[linha], ponteiro);
        fprintf(ponteiro,"\n");
        fclose(ponteiro);
        linha++;
        }
}

int calcularIdade() {
        time_t tempo = time(NULL);
        struct tm tm = *localtime(&tempo);
        int diaAtual, mesAtual, anoAtual;
        //int dia, mes, ano;

        diaAtual = tm.tm_mday;
        mesAtual = tm.tm_mon + 1;
        anoAtual = tm.tm_year + 1900;

 int idade = anoAtual - ano;
 int calMes = mesAtual - mes;
 int calDia = diaAtual - dia;

        if (mesAtual - mes < 0) {
        idade -= 1;
        //printf("%d\n", idade);
        } else {
        //printf("%d\n", idade);
 }
        printf("Data: %d/%d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
        //printf("%d", idade);
        return 0;
 }
