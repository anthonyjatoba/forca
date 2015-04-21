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
	//Eu estava repetindo muito essa linha, o que poluía bastante o código
	char cabecalho[81] =
			"#################################### Forca #####################################";
	//Constante de número máximo de itens por array
	const ITENS = 20;
	//Vetor de 20 strings de até 12 caracteres
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

	char palavra[12];
	char acertos[12];
	char dica[20];
	char palpite;

	int fim = 0;
	int i;

	int ganhou = 0;
	int contem = 0;
	int erros = 0;

	char teste;

	//Variáveis de opção dos menus
	int opc = 0;
	int tema = 0;

	while (opc != 3) {

		//Reseta as variáveis
		ganhou = 0;
		fim = 0;
		erros = 0;

		char letrasUsadas[26];
		char l = 0;
		int usada = 0;

		do {

			char letrasUsadas[26];

			for (i = 0; i < 26; i++) {
				letrasUsadas[i] = '*';
			}

			system("clear");

			//Menu
			printf("%s", cabecalho);
			printf("\n\n Escolha o modo de jogo: ");
			printf("\n\n 1 - Palavras pré-definidas: ");
			printf("\n\n 2 - Palavra personalizada: ");
			printf("\n\n 3 - Sair: ");
			printf("\n\n Opção escolhida: ");
			scanf("%d", &opc);

			switch (opc) {
			case 1:
				system("clear");

				printf("%s", cabecalho);
				printf("\n\n Escolha o tema para jogar: ");
				printf("\n\n 1 - Animais: ");
				printf("\n\n 2 - Comida: ");
				printf("\n\n 3 - Frutas: ");
				printf("\n\n 4 - Profissao: ");
				printf("\n\n 5 - Informatica: ");
				printf("\n\n Tema escolhido: ");
				scanf(" %d", &tema);
				switch (tema) {
				case 1:
					strcpy(dica, "Animal");
					//Seleciona uma palavra aleatória
					srand(time(NULL));
					strcpy(palavra, animal[rand() % ITENS]);
					break;
				case 2:
					strcpy(dica, "Comida");
					//Seleciona uma palavra aleatória
					srand(time(NULL));
					strcpy(palavra, comida[rand() % ITENS]);
					break;
				case 3:
					strcpy(dica, "Fruta");
					//Seleciona uma palavra aleatória
					srand(time(NULL));
					strcpy(palavra, fruta[rand() % ITENS]);
					break;
				case 4:
					strcpy(dica, "Profissao");
					//Seleciona uma palavra aleatória
					srand(time(NULL));
					strcpy(palavra, profissao[rand() % ITENS]);
					break;
				case 5:
					strcpy(dica, "Animal");
					//Seleciona uma palavra aleatória
					srand(time(NULL));
					strcpy(palavra, informatica[rand() % ITENS]);
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

				printf("%s", cabecalho);
				printf("\n\n  Dica: %s   Letras usadas: ", dica);

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
				printf("  #######################\n\n ");

				//verifica se o usuário ganhou
				if (strcmp(palavra, acertos) == 0) {
					fim = 1;
					ganhou = 1;
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
						letrasUsadas[l] = palpite;
						l++;
						contem = 0;
						//Verifica se a palavra contém o palpite do usuário
						//Caso tenha, a letra é colocada no seu respectivo lugar na String acertos
						//A variável contem é usada para o controle dos erros
						for (i = 0; i < strlen(palavra); i++) {
							if (palpite == palavra[i]) {
								acertos[i] = palpite;
								contem = 1;
							}
						}

						if (contem == 0) {
							erros++;
						}
					}

				}

			} while (fim != 1 || usada == 1);

			if (ganhou == 0) {
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
