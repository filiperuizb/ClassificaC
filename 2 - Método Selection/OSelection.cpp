#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>

/* Implementação do método Selection Sort
   -> A explicação do Selection já está no VÍDEO e no PDF!
*/

void ordenarSelection(int vetor[], int tamanho) {
	int tmp;
	 // -> Percorrer até o penúltimo elemento (n-1)
	for(int i = 0; i < tamanho-1; i++) {
		// -> Encontra o menor elemento (PRA JOGAR A ESQUERDA) a partir da pos atual
		for(int j = i+1; j < tamanho; j++) {
			if(vetor[j] < vetor[i]) {
				// Vai realizar a troca caso o elemento da direita seja menor que o da esquerda
				tmp = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = tmp;
			}
		}
	}
}

int main() {
  setlocale(LC_ALL, "Portuguese");

	
	int vet[] = {47,35,12,49,56,25,71,83,5,3,1,70,99,10,61}; //15
	for(int i = 0; i < 15; i++) printf("%d ", vet[i]);
	printf("\n");
	ordenarSelection(vet, 15);
	for(int i = 0; i < 15; i++) printf("%d ", vet[i]);


  return 0;
}

