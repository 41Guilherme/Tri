/* 
PROFESSOR: FLAVIO LUIZ COUTINHO
MATÉRIA: Introdução a Programação (IP)
CURSO: SI - 1º SEMESTRE 
ALUNO: GUILHERME JOSÉ DA SILVA NASCIMENTO 
NºUSP: 12543252
EP: 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int VerificadorEX(float l1, float l2, float l3){ // FUNÇÃO QUE VERIFICA A EXISTENCIA DO TRIANGULO
    int verefica;
    if (l1 > l2 && l1 >l3 ){ // CASO ONDE L1 É O MAIOR LADO
        if (l1 < l2 + l3){
            verefica = 1; //VALIDO
        }else{
            verefica = 0; //INVALIDO
        }    
    }else{
        if (l2 > l1 && l2 >l3 ){ // CASO ONDE L2 É O MAIOR LADO
            if(l2 < l1 + l3){
                verefica = 1; //VALIDO
            }else{
                verefica = 0; //INVALIDO
            }
        }else{ // CASO ONDE L3 É O MAIOR LADO 
            if (l3 < l1 + l2){
                verefica = 1; //VALIDO
            }else{
                verefica = 0; //INVALIDO
            }
        }  
    }
    return verefica; // RETORNA 0 OU 1, SENDO 0 INVALIDO E 1 VALIDO
}

int VerificadorANG(float l1 ,float l2 ,float l3){ // FUNÇÃO QUE VERIFICA O TIPO DE ANGULO INTERNO 
    int verefica;
    if (l1 > l2 && l1 > l3){ // CASO ONDE L1 É O MAIOR LADO 
        if (pow(l1,2) == pow(l2,2) + pow(l3,2)){
            verefica = 1; //RETO
        }else{
            if (pow(l1,2) > pow(l2,2) + pow(l3,2)){
                verefica = 2; //OBTUSO
            }else{
                verefica = 3; //AGUDO
            }
        }
    }else{
        if (l2 > l1 && l2 > l3){ //CASO ONDE L2 É O MAIOR LADO 
            if (pow(l2,2) == pow(l1,2) + pow(l3,2)){
                verefica = 1; //RETO
            }else{
                if (pow(l2,2) > pow(l1,2) + pow(l3,2)){
                    verefica = 2; //OBTUSO
                }else{
                    verefica = 3; //AGUDO
                }
            }
        }else{ // CASO ONDE L3 É O MAIOR LADO 
            if (pow(l3,2) == pow(l1,2) + pow(l2,2)){
                verefica = 1; //RETO
            }else{
                if (pow(l3,2) > pow(l1,2) + pow(l2,2)){
                    verefica = 2; //OBTUSO
                }else{
                    verefica = 3; //AGUDO
                }
            } 
        }  
    }
    return verefica; // RETORNA 1 PARA RETO , 2 PARA OBTUSO E 3 PARA AGUDO
}

int VerificadorLD(float l1 ,float l2 ,float l3){ // FUNÇÃO QUE VERIFICA O TIPO DE TRIANGULO EM RELAÇÃO AOS LADOS 
    int verefica;
    if (l1 == l2 && l1 == l3){ // 3 LADOS IGUAIS
        verefica = 1; //EQUILÁTERO 
    }else{
        if (l1 == l2 || l1 == l3 || l2 == l3){ // 2 LADOS IGUAIS 
            verefica = 2; //ISOSCELES
        }else{ //3 LADOS DIFERENTES 
            verefica = 3; //ESCALENO 
        }
    }
    return verefica; //RETORNA 1 PARA EQUILÁTERO , 2 PARA ISOSCELES E 3 PARA ESCALENO 
}

float Area(float l1, float l2, float l3){ // FUNÇÃO QUE APLICA FORMULA DE HERON PARA CALCULO DA AREA
    float x, area, p;

    p = (l1 + l2 + l3)/2; // SEMIPERIMETRO
    x = p *(p - l1)*(p - l2)*(p - l3);
    area = sqrt(x); // AREA

    return area; // RETORNA O VALOR DA ARÉA 
}

int main(){ // FUNÇÃO PRINCIPAL QUE COLETA OS DADOS E MOSTRA A RESPOSTA AO USUARIO 
    int validez, tipo1, tipo2;
    float l1, l2 ,l3,area;

    printf("Digite o primeiro lado do triangulo: ");    // ENTRADA DO PRIMEIRO LADO
    scanf("%f",&l1);
    printf("Digite o segundo lado do triangulo: ");     // ENTRADA DO SEGUNDO LADO
    scanf("%f",&l2);
    printf("Digite o terceiro lado do triangulo: ");    // ENTRADA DO TERCEIRO LADO 
    scanf("%f",&l3);
    printf("\n\n");

    validez = VerificadorEX(l1,l2,l3); // VERIFICA A EXISTENCIA DO TRIANGULO

    if (validez==1 && l1 > 0 && l2 > 0 && l3 > 0){ 
        printf("Medidas dos lados formam um triangulo VALIDO\n"); // LADOS VALIDOS

        tipo1 = VerificadorLD(l1,l2,l3); // VERIFICA OS LADOS DO TRIANGULO 
        if (tipo1==1){
            printf("Classificacao em funcao dos lados: EQUILATERO\n");
        }else{
            if (tipo1==2){
                printf("Classificacao em funcao dos lados: ISOSCELES\n");
            }else{
                printf("Classificacao em funcao dos lados: ESCALENO\n");
            }
        }

        tipo2 = VerificadorANG(l1,l2,l3); // VERIFICA OS ANGULOS DO TRIANGULO 
        if (tipo2==1){
            printf("Classificacao em funcao dos angulos: RETO\n");
        }else{
            if (tipo2==2){
                printf("Classificacao em funcao dos angulos: OBTUSO\n");
            }else{
                printf("Classificacao em funcao dos angulos: AGUDO\n");
            }
        }

        area = Area(l1,l2,l3);  // CALCULO DA AREA DO TRIANGULO 
        printf("Area do triangulo: %g \n\n\n",area); 

    }else{
        printf("Medidas dos lados formam um triangulo INVALIDO\n\n"); // LADOS INVÁLIDOS 
    }

    system("PAUSE"); // MECANISMO PARA QUE O EXECUTÁVEL(.exe) NÃO SE FECHE APÓS O TÉRMINO DAS OPERAÇÕES
    return 0; // FIM DO PROGRAMA 
}