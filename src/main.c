/*
 * main.c
 *
 *  Created on: 28/02/2015
 *      Author: Marcelo Odir
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int* counter(double valor) {

	int *saida; //index 0 to 1 cent coin, index 1 to 2 cents coin and index 2 to 5 cents coin
	saida  = (int*) calloc(3,sizeof(int));

	if(valor >= 0.05) {
		*(saida+2) = (int) (valor / 0.05); // moedas de 5cents necessarias
		valor = fmod(valor,0.05);
		valor = ceil(valor * 100) / 100; // arredondando 2 casas decimais apenas
	}
	if(valor >= 0.02) {
		*(saida+1) = (int) (valor / 0.02); // moedas de 2cents necessarias
		valor = fmod(valor,0.02);
		valor = ceil(valor * 100) / 100; // arredondando 2 casas decimais apenas
	}
	if(valor != 0) {
		*saida = 1;
	}
	return saida;
}

int main(int argc, char **argv) {
	double valor = 5.68;
	int *saida;

	saida = counter(valor);

	printf("Qte Moedas de 5cents: %d\n",*(saida+2));
	printf("Qte Moedas de 2cents: %d\n",*(saida+1));
	printf("Qte Moedas de 1cents: %d\n",*saida);
	free(saida);
	return EXIT_SUCCESS;
}



