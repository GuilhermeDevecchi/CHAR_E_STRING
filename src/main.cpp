#include <Arduino.h>
#include <string.h> //*strlen, strcat,strcmp,strchr
#include <stdlib.h> //*atoi



void textoChar();
void textoString();



void setup() 
{
  Serial.begin(9600);
  Serial.println();
  textoChar();
  textoString();
}

void loop(){} 

void textoChar()
{
  //*texto literal
  //*use const char* quando o texto nao sera alterado
const char cidade[] = "Sao Paulo";
Serial.println(cidade);

//*Descobrindo o tamnho do texto
//* strlen conta quantos caracteres antes do '\0'
int tamanhoTextoCidade = strlen(cidade);
Serial.print("Comprimento do texto:");
Serial.println(tamanhoTextoCidade);

//*Descobrindo o tamanho ocupado
//*o sizeoff() retornara um byte a mais que o comprimento por causa do'\0'
int tamanhoVariavelCidade = sizeof(cidade);
Serial.print("Espaco utilizado:");
Serial.println(tamanhoVariavelCidade);

//* o caractere \0 é colocado automaticamente quando escrevemos um texto entre " ".
char vetorTexto[7]= {'t', 'h', 'i', 'a','g', 'o','\0'};
Serial.println(vetorTexto);

//*comparar texto 
const char* cidade1 = "Sao caetano";
const char* cidade2 = "Sao caetano";

if(strcmp(cidade1, cidade2) == 0)
Serial.println("Os textos sao iguais");

else 
Serial.println("Os textos sao diferentes");

//*strcmp analiza a ordem lexica das palavras, se a primeira palavra vem antes 
//*que a segunda o valor retornado sera menos que zero, se a primeira vem apos 
//* a segunda o retorno sera mairo que zero

//!======================================
//!TEXTO EDITAVEL COM char[]
//!======================================

char nomeAluno[20] = "Guilhermp";
Serial.println(nomeAluno);

//*alterando caracteres individualmente 
nomeAluno[8]= 'e';
Serial.println(nomeAluno);

//*copiando outro texto para dentro do vetor
//! cuidado: o vetor precisa ter espaco suficiente 

strcpy(nomeAluno, "Felipe");
Serial.println(nomeAluno);

//* concatenando de texto ao final
char frase[40] = "ola ";
strcat(frase, "mundo!");
Serial.println(frase);

//*procurando um caractere no tetxo
//*frase "Ola mundo!"
char* posicaoLetra = strchr(frase, 'm');

if(posicaoLetra != NULL)
{Serial.println("Letra encontarda");
Serial.println(posicaoLetra);
}
else
{
Serial.println("Letra nao encontrada");
}

//* convertendo textom numerico para inteiro
char idadeTexto[] = "45"; //52, 53, \0
int idade = atoi(idadeTexto);
Serial.println(idade);

}

void textoString()
{
//*=================================
//*USANDO String
//*=================================


String nome = "Thiago";
String curso = "Logica de programacao";
String mensagem = "OLa";

//* concatenando String
mensagem = mensagem + "," + nome + "! Bem vindo ao curso de "+curso+ ".";
Serial.println(mensagem);

//* Tamanho da string
int tamanhoMensagem = mensagem.length();
Serial.print("tamanho da string em bytes");
Serial.println(tamanhoMensagem);

//*Acessando um caractere em uma poiscao especifica
char primeiraLetra = mensagem.charAt(0);
Serial.print("Primeira letra");
Serial.println(primeiraLetra);

//* tambem e possivel acessar com colchetes
char segundaLetra = mensagem[1];
Serial.println(segundaLetra);

//*procurando um texto dentro da string 
int posicaoTextoProcurando = mensagem.indexOf("Curso");
Serial.println(posicaoTextoProcurando);

//* extraindo um texto dentro da string
int inicioNomeCurso = posicaoTextoProcurando + 9;
Serial.println(mensagem.substring(inicioNomeCurso, tamanhoMensagem - 1));//* -1 tira o ponto final

//*substituindo um termo dentro da string 
mensagem.replace("Ola," , "Oi, tudo bem?");
Serial.println(mensagem);

//*convertendo para maiusculas
mensagem.toUpperCase();
Serial.println(mensagem);

//*convertendo tudo para minusculo
mensagem.toLowerCase();
Serial.println(mensagem);

//*convertendio texto numerico para inteiro
String textoNumero = "123";
int numero = textoNumero.toInt();
Serial.println(numero * 2);

//*verificando se a string esta vazia
String textovazio = "";
if(textovazio.length() == 0)  Serial.println("O texto esta vazio");

//*convertendo string para const char*
//* isso e util quando alguma bibliotaca espera texto estilo c
const char* textoComoChar = mensagem.c_str();
Serial.println(textoComoChar);



}