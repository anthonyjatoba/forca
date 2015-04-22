/*
 * Forca.c
 *
 *  Created on: Apr 14, 2015
 *      Author: anthony
 */

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>

int main() {
	//Constante do número de ítens por tema. Usada para randomizar um tema.
	const NUM_ITENS = 20;

	//Vetores com as palavras possíveis. A declaração do tamanho deve ser manual, pois C não permite que a constante seja declarada como dimensão do array.
	char animal[20][12] = { "AVESTRUZ", "BORBOLETA", "CARANGUEJO",
			"ORANGOTANGO", "CROCODILO", "DROMEDARIO", "ROUXINOL", "CENTOPEIA",
			"GAFANHOTO", "PINTASSILGO", "HIPOPOTAMO", "LEOPARDO", "GUAXINIM",
			"JAGUATIRICA", "OSTRA", "MICO", "CHIMPANZE", "CARNEIRO", "GOLFINHO",
			"MINHOCA" };
	char comida[20][12] = { "EMPADA", "FARINHA", "FEIJOADA", "COXINHA",
			"BRIGADEIRO", "CHURRASCO", "LASANHA", "MACARRONADA", "TORTA",
			"TORRADA", "PIZZA", "PANQUECA", "PIPOCA", "PAMONHA", "OVO",
			"ACARAJE", "CROISSANT", "HAMBURGUER", "BISCOITO", "BOLO" };
	char fruta[20][12] = { "ABACATE", "BANANA", "CARAMBOLA", "DAMASCO", "FIGO",
			"GOIABA", "JABUTICABA", "KIWI", "LARANJA", "MELANCIA", "MANGA",
			"MARACUJA", "PESSEGO", "PITOMBA", "ROMA", "TANGERINA", "TOMATE",
			"TAMARINDO", "UVA", "UMBU" };
	char profissao[20][12] = { "ADVOGADO", "BOMBEIRO", "CARPINTEIRO",
			"DESENHISTA", "ENGENHEIRO", "ESCRITOR", "FERREIRO", "GUARDA",
			"HISTORIADOR", "JORNALISTA", "LEILOEIRO", "MARINHEIRO", "OURIVES",
			"PROGRAMADOR", "PADEIRO", "RELOJOEIRO", "SILVICULTOR", "TRADUTOR",
			"VETERINARIO", "ZOOLOGO" };
	char informatica[20][12] = { "LINUX", "WINDOWS", "C", "PROCESSADOR",
			"TECLADO", "MOUSE", "PROGRAMA", "ALGORITMO", "HACKER", "DEBUG",
			"ASCII", "JAVA", "JAVASCRIPT", "PROGRAMADOR", "PYTHON", "INTERNET",
			"ROTEADOR", "SERVIDOR", "GOOGLE", "APPLE" };

	//Iterador para uso geral.
	int i;

	//APAGAR
	char teste;

	//Dica da palavra para o jogador.
	char dica[20];
	//Palavra que o jogador deve acertar. Pode ser uma da lista acima ou personalizada.
	char palavra[12];
	//Variável usada para controle dos acertos do usuário. Cada letra acertada é colocada em sua posição nessa string. Quando <acertos> == <palavra>, o jogador acertou.
	char acertos[12];

	//Palpite do jogador.
	char palpite;

	//Variável de controle; 0 = não contem o
	int contemPalpite = 0;

	//Variáveis de opção dos menus de jogo e de tema.
	int opc = 0;
	int tema = 0;

	//O programa é executado enquanto opc != 3 (sair no menu);
	while (opc != 3) {

		//Letras usadas pelo usuário e contador de letras usadas para repetições.
			char letrasUsadas[26];
			int numLetrasUsadas = 0;
			int usada;

			//Variável de controle do fim do jogo.
			int fim = 1;
			//Contador de erros. 6 erros = derrota;
			int erros = 0;

		do {

			for (i = 0; i < strlen(letrasUsadas); i++) {
				letrasUsadas[i] = '*';
			}

			system("clear");

			//Menu
			printf("#################################### Forca #####################################");
			printf("\n\n Escolha o modo de jogo: ");
			printf("\n\n 1 - Palavras pré-definidas: ");
			printf("\n\n 2 - Palavra personalizada: ");
			printf("\n\n 3 - Sair: ");
			printf("\n\n Opção escolhida: ");
			scanf("%d", &opc);

			switch (opc) {
			do {

				case 1:
				system("clear");

				printf("#################################### Forca #####################################");
				printf("\n\n Escolha o tema para jogar: ");
				printf("\n\n 1 - Animais: ");
				printf("\n\n 2 - Comida: ");
				printf("\n\n 3 - Frutas: ");
				printf("\n\n 4 - Profissao: ");
				printf("\n\n 5 - Informatica: ");
				printf("\n\n Tema escolhido: ");
				scanf(" %d", &tema);

			} while (tema < 1 || tema > 5);

			switch (tema) {
			case 1:
				strcpy(dica, "Animal");
				//Seleciona uma palavra aleatória
				srand(time(NULL));
				strcpy(palavra, animal[rand() % NUM_ITENS]);
				break;
			case 2:
				strcpy(dica, "Comida");
				//Seleciona uma palavra aleatória
				srand(time(NULL));
				strcpy(palavra, comida[rand() % NUM_ITENS]);
				break;
			case 3:
				strcpy(dica, "Fruta");
				//Seleciona uma palavra aleatória
				srand(time(NULL));
				strcpy(palavra, fruta[rand() % NUM_ITENS]);
				break;
			case 4:
				strcpy(dica, "Profissao");
				//Seleciona uma palavra aleatória
				srand(time(NULL));
				strcpy(palavra, profissao[rand() % NUM_ITENS]);
				break;
			case 5:
				strcpy(dica, "Informatica");
				//Seleciona uma palavra aleatória
				srand(time(NULL));
				strcpy(palavra, informatica[rand() % NUM_ITENS]);
				break;
			default:

				break;
			}
			break;

		case 2:
			printf("\n Digite a dica: ");
			scanf(" %[^\n]", dica);
			printf("\n Digite a palavra a ser adivinhada: ");
			scanf(" %[^\n]", palavra);

			for (i = 0; i < strlen(palavra); i++) {
				palavra[i] = toupper(palavra[i]);
			}
			break;
		case 3:
			fim = 1;
			break;
			}
		} while (opc != 1 && opc != 2 && opc != 3);

		if (opc != 3) {

			//Preenche a variável acertos com asteriscos, que representam caracteres desconhecidos
			for (i = 0; i < strlen(palavra); i++) {
				acertos[i] = '*';
			}

			acertos[strlen(palavra)] = '\0';

			do {
				fim = 0;

				system("clear");

				printf("#################################### Forca #####################################");
				printf("\n\n  Dica: %s   Letras usadas: ", dica);

				for (i = 0; i < numLetrasUsadas; i++) {
					printf("%c ", letrasUsadas[i]);

				}

				//Só pra facilitar os testes
				//int tamanho3 = strlen(acertos);
				//printf("  %s (%d) / %s (%d)\n\n", palavra, (int) strlen(palavra),
				//		acertos, tamanho3);

				switch (erros) {
				case 0:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####            \n");
					printf("  ####            \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					break;
				case 1:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *o o*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					break;
				case 2:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *o o*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					break;
				case 3:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *o o*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##         |    \n");
					printf("  ##        /|    \n");
					printf("  ##       / |    \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					break;
				case 4:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *o o*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##         |    \n");
					printf("  ##        /|\\  \n");
					printf("  ##       / | \\ \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					break;
				case 5:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *o o*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##         |    \n");
					printf("  ##        /|\\  \n");
					printf("  ##       / | \\ \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##        /     \n");
					printf("  ##       /      \n");
					printf("  ##               \n");
					break;
				case 6:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *X X*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##         |    \n");
					printf("  ##        /|\\   \n");
					printf("  ##       / | \\  \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##        / \\   \n");
					printf("  ##       /   \\  \n");
					printf("  ##               \n");
					fim = 1;
					break;
				}
				printf("  #######################\n\n  ");

				//verifica se o usuário ganhou
				if (strcmp(palavra, acertos) == 0) {
					fim = 1;
				}

				//Desenha os espaços para as letras
				for (i = 0; i < strlen(palavra); i++) {
					if (acertos[i] == '*') {
						printf("_ ");
					} else {
						printf("%c ", acertos[i]);
					}
				}

				if (fim != 1) {

					usada = 0;

					printf("\n\n  Digite seu palpite: ");
					scanf(" %c", &palpite);
					palpite = toupper(palpite);

					//checa se a letra já foi usada
					for (i = 0; i < 26; i++) {
						if (letrasUsadas[i] == palpite) {
							usada = 1;
						}
					}

					if (usada == 0) {
						letrasUsadas[numLetrasUsadas] = palpite;
						numLetrasUsadas++;
						contemPalpite = 0;
						//Verifica se a palavra contém o palpite do usuário
						//Caso tenha, a letra é colocada no seu respectivo lugar na String acertos
						//A variável contemPalpite é usada para o controle dos erros
						for (i = 0; i < strlen(palavra); i++) {
							if (palpite == palavra[i]) {
								acertos[i] = palpite;
								contemPalpite = 1;
							}
						}

						if (contemPalpite == 0) {
							erros++;
						}
					}

				}

			} while (fim != 1);

			if (erros == 6) {
				printf("\n\n  Você perdeu! =(");
			} else {
				printf("\n\n  Você ganhou! :D");
			}

			printf("\n\n  Digite alguma coisa para voltar ao menu!");
			scanf(" %c", &teste);
		}

	}

	return 0;
}
