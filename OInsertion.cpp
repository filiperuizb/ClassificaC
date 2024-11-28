#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>

/* Implementação do método Insertion Sort
   -> A explicação do Insertion já está no VÍDEO e no PDF!
*/

void ordenarInsertion(int vetor[], int tamanho) {
	int i, j, tmp;
	// -> Vai percorrer a partir do segundo elemento {0,1,2,3} = 1 seria o 2° elemento
  for(i = 1; i < tamanho; i++) {
    j = i;
    // -> OBJ: Mover o elemento atual [j] pra sua posição correta no vetor
    while(j > 0 && vetor[j] < vetor[j-1]) {
    	
    	// -> Troca os elementos
      tmp = vetor[j];
      vetor[j] = vetor[j-1];
      vetor[j-1] = tmp;
      
      // -> Move pra posição anterior
      j = j - 1;  
    }
  }
}

int main() {
  setlocale(LC_ALL, "Portuguese");

	
	int vet[] = {47,35,12,49,56,25,71,83,5,3,1,70,99,10,61}; //15
	for(int i = 0; i < 15; i++) printf("%d ", vet[i]);
	printf("\n");
	ordenarInsertion(vet, 15);
	for(int i = 0; i < 15; i++) printf("%d ", vet[i]);


  return 0;
}


