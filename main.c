#include "monty.h"

int main (int argc, char *argv[])
{
	FILE *fp;

	if (argc != 2)
	errors(1, " ", 1);

	fp = fopen(argv[1], "r"); /** "r" pour read -> mode d'utilisation - Ici on veut lire le contenu du fichier .m */

	if (fp == NULL)
	errors(2, argv[1], 1);

	monty_interpreter(fp); /**fonction qui permet de sélectionner la bonne fonction le contenu du fichier */

	fclose(fp); /** fermeture du fichier mentionné en argument du programme */

	exit(EXIT_SUCCESS);
}
