// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: João Victor Oliveira de Lima
//  email: 20241160026@ifba.edu.br
//  Matrícula: 20241160026
//  Semestre: 2°

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "JoaoLima20241160026.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[]){
  DataQuebrada dataquebrada =  quebraData(data);
  int anoBissexto();

  if (dataquebrada.valido != 1){
    return 0;
  }

  if (dataquebrada.iDia > 31 && dataquebrada.iDia < 1){
    return 0;
  }

  int meses30dias;
  meses30dias = dataquebrada.iMes == 4 || dataquebrada.iMes == 6 || dataquebrada.iMes == 9 || dataquebrada.iMes == 11;
  if (dataquebrada.iMes == meses30dias){
    if (dataquebrada.iDia >=1 && dataquebrada.iDia <= 30){
      return 1;
    }else{
      return 0;
    }
  }
  
  if (dataquebrada.iMes > 12 && dataquebrada.iMes < 1){
    return 0;
  }else{
    return 1;
  }

  if(dataquebrada.iMes == 2 && dataquebrada.iDia == 29){
    return anoBissexto(dataquebrada.iAno);
  }else if (dataquebrada.iMes == 2 && dataquebrada.iDia > 29){
    return 0;
  }

  if(dataquebrada.iAno < 0){
    return 0;
  }
  //printf("%s\n", data);

}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
      
      //calcule a distancia entre as datas


      //se tudo der certo
      dma.retorno = 1;
      return dma;
      
    }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = -1;

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = -1;

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{

    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias;
    return qtdOcorrencias;
}


int anoBissexto(int ano){
  if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
    return 1;
  }
  return 0;
}

DataQuebrada quebraData(char data[]) {
    DataQuebrada dq;
    char sDia[3] = "", sMes[3] = "", sAno[5] = ""; // Inicializa strings vazias
    int i, j;

    // Inicializa como inválido por padrão
    dq.valido = 0;

    // Extrai o dia
    for (i = 0; data[i] != '/' && data[i] != '\0'; i++) {
        sDia[i] = data[i];
    }
    sDia[i] = '\0'; // Finaliza a string do dia
    if (i == 0 || i > 2) { // Verifica se o dia está vazio ou tem mais de 2 dígitos
        return dq; // Retorna imediatamente
    }

    // Extrai o mês
    j = i + 1; // Pula o '/'
    i = 0;
    for (; data[j] != '/' && data[j] != '\0'; j++) {
        sMes[i++] = data[j];
    }
    sMes[i] = '\0'; // Finaliza a string do mês
    if (i == 0 || i > 2) { // Verifica se o mês está vazio ou tem mais de 2 dígitos
        return dq; // Retorna imediatamente
    }

    // Extrai o ano
    j = j + 1; // Pula o '/'
    i = 0;
    for (; data[j] != '\0'; j++) {
        sAno[i++] = data[j];
    }
    sAno[i] = '\0'; // Finaliza a string do ano
    if (i != 2 && i != 4) { // Verifica se o ano tem 2 ou 4 dígitos
        return dq; // Retorna imediatamente
    }

    // Converte os valores para inteiros
    dq.iDia = atoi(sDia);
    dq.iMes = atoi(sMes);
    dq.iAno = atoi(sAno);

    // Define como válida, pois passou por todas as verificações
    dq.valido = 1;
    return dq;
}

/*DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3] = "";
	char sMes[3] = "";
	char sAno[5] = "";
	int i; 
  dq.valido = 0;

	for (i = 0; data[i] != '/' && data[i] != '\0'; i++){
		sDia[i] = data[i];	
	}
  
  sDia[i] = '\0';
  printf("Dia extraído: '%s' (tamanho: %d)\n", sDia, i);
	if(i == 0 || i > 2){ // testa se tem 1 ou dois digitos
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/' && data[j] != '\0'; j++){
		sMes[i] = data[j];
		i++;
	}
  sMes[i] = '\0';  // coloca o barra zero no final
  printf("Mês extraído: '%s' (tamanho: %d)\n", sMes, i);
	if(i == 0 || i > 2){ // testa se tem 1 ou dois digitos

		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	

  for (; data[j] != '\0'; j++) {
      sAno[i] = data[j];
      i++;
  }
  sAno[i] = '\0'; // Finaliza a string do ano
  printf("Ano extraído: '%s' (tamanho: %d)\n", sAno, i);
  if (i != 2 && i != 4) { // Verifica se o ano tem 2 ou 4 dígitos
      dq.valido = 0;
      return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}*/
