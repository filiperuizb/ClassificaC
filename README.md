# 📋 Classificação de Algoritmos (Sorting Algorithms)

Bem-vindo(a) a este repositório sobre **algoritmos de ordenação**! 🎉 Aqui exploramos os métodos mais conhecidos de ordenação e aprendemos como funcionam na prática. Todas as implementações foram feitas na linguagem **C**.

## 🧐 Por que classificar?

Para realizar pesquisas (como a busca binária), é essencial que os dados estejam **em ordem crescente**. Para isso, utilizamos algoritmos de **classificação/ordenação**.

---

## 🚀 Métodos abordados

Este repositório explora três métodos de ordenação:

1. **Selection Sort** 🟡
2. **Insertion Sort** 🟢
3. **Quick Sort** 🔵

---

## 📌 Selection Sort

O **Selection Sort** é um algoritmo básico que ordena localizando o menor valor e o movendo para o lugar correto. Esse processo se repete até que todos os elementos estejam ordenados.

### Exemplo:
Dado o vetor: `[5,2,32,20,10]`

**Passos:**

1. Encontrar o menor valor e movê-lo para a primeira posição.
2. Repetir o processo para os valores restantes.

**Resultado final:** `[2,5,10,20,32]`

🟨 **Vantagens:** Simples de implementar e fácil de entender.  
🟥 **Desvantagens:** Ineficiente para listas grandes, pois percorre o vetor inteiro mesmo quando já está parcialmente ordenado.

---

## 📌 Insertion Sort

O **Insertion Sort** constrói a ordem de forma progressiva, posicionando os elementos no lugar correto enquanto percorre a lista. Ele é ideal para listas pequenas ou **parcialmente ordenadas**.

### Exemplo:
Dado o vetor: `[15,3,18,7]`

**Passos:**

1. Dividir a lista em parte organizada (à esquerda) e desorganizada (à direita).  
2. Cada elemento é comparado com os anteriores até ser posicionado no local correto.

**Resultado final:** `[3,7,15,18]`

🟩 **Vantagens:** Melhor que o Selection Sort para listas parcialmente ordenadas.  
🟥 **Desvantagens:** Não é eficiente para listas muito grandes.

---

## 📌 Quick Sort

O **Quick Sort** é um dos algoritmos mais eficientes, usando o paradigma de **dividir e conquistar**. Ele seleciona um **pivô** e organiza os elementos menores à esquerda e os maiores à direita. Após isso, aplica o mesmo processo recursivamente.

### Exemplo:
Dado o vetor: `[8,3,7,4,2,6,5,1]`

**Passos:**

1. Escolher o pivô: `(8+1+4)/3 = 4`  
2. Reorganizar:  
   - Esquerda do pivô: `[1,2,3]`  
   - Direita do pivô: `[5,6,7,8]`  
3. Repetir o processo para as partes esquerda e direita.

**Resultado final:** `[1,2,3,4,5,6,7,8]`

🔵 **Vantagens:** Extremamente eficiente para listas grandes.  
🟥 **Cuidados:** A eficiência depende da escolha do pivô.

---

## 💻 Implementações

Todas as implementações foram feitas em **C**. O repositório inclui:

- Código separado para cada algoritmo.
- Um menu interativo que permite testar os três métodos.

---

## 🤔 Conclusão

Esses algoritmos são fundamentais na computação. O Quick Sort foi particularmente divertido de implementar, pois utiliza recursão e **faz muito sentido depois de compreendido**! Espero que este repositório seja útil para você. 😊

---

## 📂 Organização do repositório

- `selection_sort.c`: Implementação do Selection Sort.
- `insertion_sort.c`: Implementação do Insertion Sort.
- `quick_sort.c`: Implementação do Quick Sort.
- `menu.c`: Menu interativo para testar os três algoritmos.

---

## 📢 Agradecimento

Obrigado por ler até aqui! Se você gostou, deixe uma ⭐ no repositório!  
Desejo um ótimo fim de ano e até a próxima! 🎄
