#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


int numeros[50];
char nome[100];
int teclaEnter = 13;
int setaBaixo = 80;
int setaCima = 72;
int setaEsquerda = 75;
int setaDireita = 77;


// -> Reutilizei meu código da AEP pra montar um menuzinho 
void tiraCursor();
void gotoxy(int x, int y);
void setColor(int color);
void gerarVetor(int vetor[], int tamanho);
void mostrarVetor(int vetor[]);
void ordenarSelection(int vetor[], int tamanho);
void ordenarInsertion(int vetor[], int tamanho);
int particional(int v[], int inicio, int fim);
void quickSort(int v[], int inicio, int fim);
void ordenarQuick(int vetor[], int inicio, int fim);
void menu();


int main() {
  setlocale(LC_ALL, "Portuguese");
  setColor(4);
  printf("                 -> AVISO <-\n");
  printf("-> Ao terminar um método de ordenação gere o vetor novamente!\n-> Para que ele perca a ordem de novo!!!!\n");
  printf("                 -> AVISO <-\n");
	setColor(15);
	printf("\n\n\nQual seu nome? \n");
  printf("R: ");
  gets(nome);
  system("cls");
  srand(time(NULL));
	tiraCursor();
	menu();


  return 0;
}

void tiraCursor() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}


void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	/*
CORES:
0	Preto
1	Azul
2	Verde
3	Azul claro
4	Vermelho
5	Roxo
6	Amarelo
7	Branco claro
8	Cinza
9	Azul claro
10	Verde claro
11	Azul piscina
12	Vermelho claro
13	Rosa
14	Amarelo claro
15	Branco
*/
}

void gerarVetor(int vetor[], int tamanho) {
    int num;
    bool repetido;
    for (int i = 0; i < tamanho; i++) {
        do {
            repetido = false;
            num = rand() % 100 + 1; 
            
            for (int j = 0; j < i; j++) {
                if (numeros[j] == num) repetido = true;  
            }
        } while (repetido);  

        numeros[i] = num;
    }

    setColor(12);
    printf("O VETOR FOI GERADO COM SUCESSO!!!");
    setColor(15);
		printf("\nVOLTARÁ PARA O MENU EM: ");
    for (int i = 5; i >= 0; i--) {
        gotoxy(23, 1);
        setColor(2);
        printf("%d", i);
        Sleep(1000);
    }
}


void mostrarVetor(int vetor[]) {
	setColor(5);
	printf("                           -> ELEMENTOS DO VETOR <-\n\n");
	setColor(6);
	printf("                         ");
	for(int i = 0; i < 10; i++) {
		printf("%d ", vetor[i]);
	}
	printf("\n\n");
	printf("                         ");
	for(int i = 10; i < 20; i++) {
		printf("%d ", vetor[i]);
	}
	printf("\n\n");
	printf("                         ");
	for(int i = 20; i < 30; i++) {
		printf("%d ", vetor[i]);
	}
	printf("\n\n");
	printf("                         ");
	for(int i = 30; i < 40; i++) {
		printf("%d ", vetor[i]);
	}
	printf("\n\n");
	printf("                         ");
	for(int i = 40; i < 50; i++) {
		printf("%d ", vetor[i]);
	}
	
	setColor(12);
	printf("\nOBS:");
	setColor(15);
	printf(" Caso esteja ordenado, antes de testar outro método recomendo gerar o vetor novamente\npara que seja visualizado de forma correta a nova ordenação!!!");
	
}

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
	
	//Aqui é só a exibação
	setColor(2);
	printf("O VETOR FOI ORDENADO COM SELECTION SORT!!!");
	setColor(12);
	printf("\nOBS: ");
	gotoxy(5,1);
	setColor(15);
	printf("PARA VER ELE ORDENADO LISTE O VETOR NO MENU!");
	printf("\nVOLTARÁ PARA O MENU EM: ");
	for(int i = 5; i >= 0; i--) {
		gotoxy(23,2);
		setColor(2);
		printf("%d", i);
		Sleep(1000);
	}
} 

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
	
	setColor(2);
	printf("O VETOR FOI ORDENADO COM INSERTION SORT!!!");
	setColor(4);
	printf("\nOBS: ");
	gotoxy(5,1);
	setColor(15);
	printf("PARA VER ELE ORDENADO LISTE O VETOR NO MENU!");
	printf("\nVOLTARÁ PARA O MENU EM: ");
	for(int i = 5; i >= 0; i--) {
		gotoxy(23,2);
		setColor(12);
		printf("%d", i);
		Sleep(1000);
	}
}

int particional(int v[], int inicio, int fim) {
	int pivo = (v[inicio] + v[fim] + v[(inicio + fim)/2])/3;
	
	//-> Inicio nunca poderá ser menor que o fim, e os dois outros enquantos é pra fazer as trocas baseado em esquerda e direita | menor e maiores com o pivo sendo nossa mediana
	while(inicio < fim) {
		
		// -> Aumenta 1 até que o elemento seja maior que o nosso pivo 
		while(inicio < fim && v[inicio] <= pivo) inicio = inicio + 1;
		
		// -> Decrementa 1 ate que nosso elemento seja menor que o pivo
		while(inicio < fim && v[fim] > pivo) fim = fim - 1;
		
		//-> Realiza a troca dos 2 elementos de lugar (inicio e fim)
		int tmp = v[inicio];
		v[inicio] = v[fim];
		v[fim] = tmp;
	}
	// -> Retorna o inicio que lá em baixo será usado como nosso elemento do meio
	return inicio;
}

void quickSort(int v[], int inicio, int fim) {
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

void ordenarQuick(int vetor[], int inicio, int fim) {
	quickSort(vetor, inicio, fim);
	
	setColor(2);
	printf("O VETOR FOI ORDENADO COM QUICK SORT!!!");
	setColor(12);
	printf("\nOBS: ");
	gotoxy(5,1);
	setColor(15);
	printf("PARA VER ELE ORDENADO LISTE O VETOR NO MENU!");
	printf("\nVOLTARÁ PARA O MENU EM: ");
	for(int i = 5; i >= 0; i--) {
		gotoxy(23,2);
		setColor(2);	
		printf("%d", i);
		Sleep(1000);
	}
}

void menu() {
  bool sair = false;
  int opcaoSelecionada = 0;

  while (!sair) {
    system("cls");

    setColor(6);
    gotoxy(44, 5);
    printf("Seja BEM-VINDO, ");
    gotoxy(60, 5);
    setColor(12);
    printf("%s!!!", nome);
    setColor(6);
    gotoxy(30, 7);
    setColor(15);
    printf("Este é o MENU PRINCIPAL, onde você vai poder escolher");
    gotoxy(37, 8);
    printf("o método de ordenação que quiser!");

    setColor(5);
    gotoxy(45, 10);
    printf("-> MENU PRINCIPAL <-");
    gotoxy(43, 11);
    printf("________________________");

    setColor(7);
    gotoxy(29, 13);
    printf("%s Gerar Nums", opcaoSelecionada == 0 ? ">" : " ");
    gotoxy(49, 13);
    printf("%s Listar Nums", opcaoSelecionada == 1 ? ">" : " ");
    gotoxy(69, 13);
    printf("%s Selection Sort", opcaoSelecionada == 2 ? ">" : " ");
    gotoxy(29, 15);
    printf("%s Insertion Sort", opcaoSelecionada == 3 ? ">" : " ");
    gotoxy(49, 15);
    printf("%s Quick Sort", opcaoSelecionada == 4 ? ">" : " ");
    gotoxy(69, 15);
    printf("%s Sair", opcaoSelecionada == 5 ? ">" : " ");

    int tecla = getch();

    if (tecla == setaCima) {
      if (opcaoSelecionada >= 3) {
        opcaoSelecionada -= 3; 
      }
    } else if (tecla == setaBaixo) {
      if (opcaoSelecionada < 3) {
        opcaoSelecionada += 3; 
      }
    } else if (tecla == setaEsquerda) {
      if (opcaoSelecionada % 3 != 0) {
        opcaoSelecionada -= 1; 
      }
    } else if (tecla == setaDireita) {
      if (opcaoSelecionada % 3 != 2 && opcaoSelecionada < 5) {
        opcaoSelecionada += 1; 
      }
    } else if (tecla == teclaEnter) {
      system("cls"); 
      switch (opcaoSelecionada) {
        case 0:
          gerarVetor(numeros, 50);
          break;
        case 1:
           mostrarVetor(numeros);
          break;
        case 2:
           ordenarSelection(numeros, 50);
          break;
        case 3:
          ordenarInsertion(numeros, 50);
          break;
        case 4:
          ordenarQuick(numeros, 0, 50-1 ); //Chamei com o -1, pois o fim tem que passar -1 pois ele vai de 0 a 49 | Se passar o 50 o quick buga
          break;
        case 5:
          sair = true; 
          break;
      }

      if (!sair) {
        setColor(12);
        printf("\nPressione qualquer tecla para voltar ao menu...");
        getch();
      }
    }
  }
}

