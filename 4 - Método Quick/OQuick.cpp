#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>

/* Implementação do método Quick Sort
   -> A explicação do Quick já está no VÍDEO e no PDF!
*/


int particional(int v[15], int inicio, int fim) {
	int pivo = (v[inicio] + v[fim] + v[(inicio + fim)/2])/3;
	//-> Inicio nunca poderá ser menor que o fim, e os dois outros enquantos é pra fazer as trocas baseado em esquerda e direita | menor e maiores com o pivo sendo nossa mediana
	while(inicio < fim) {
		while(inicio < fim && v[inicio] <= pivo) inicio = inicio + 1;
		while(inicio < fim && v[fim] > pivo) fim = fim - 1;
		//-> Realiza a troca dos 2 elementos
		int tmp = v[inicio];
		v[inicio] = v[fim];
		v[fim] = tmp;
	}
	// -> Retorna o inicio que lá em baixo será usado como nosso elemento do meio
	return inicio;
}

void quickSort(int v[15], int inicio, int fim) {
	if(inicio < fim) {
		//-> Pegou o elemento do MEIO
		int pos = particional(v, inicio, fim);
		/*-> Agora precisamos fazer a chamada recursiva
		-> Para que aconteça o ordenamento dos menores (esquerda) do pos 
		-> e os maiores (direita) do pos */
		quickSort(v, inicio, pos - 1); // ELEMENTOS A ESQUERDA
		quickSort(v, pos, fim); // ELEMENTOS A DIREITA
	}
}

int main() {
  setlocale(LC_ALL, "Portuguese");

	
	int vet[] = {47,35,12,49,56,25,71,83,5,3,1,70,99,10,61}; //15
	for(int i = 0; i < 15; i++) printf("%d ", vet[i]); 
	printf("\n");
	quickSort(vet, 0, 14);
	for(int i = 0; i < 15; i++) printf("%d ", vet[i]);


  return 0;
}


