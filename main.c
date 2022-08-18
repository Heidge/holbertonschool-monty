#include "monty.h"

int main (int argc, char *argv[])
{
	FILE *fp;

	if (argc != 2)
	usage_error(); /* appel de la fonction usage_error si utilisateur n'a pas rentré exactement deux arguments **/

	fp = fopen(argv[1], "r"); /** "r" pour read -> mode d'utilisation - Ici on veut lire le contenu du fichier .m */

	if (fp == NULL)
	open_file_failure();

	monty_interpreter(fp); /**fonction qui permet de sélectionner la bonne fonction le contenu du fichier */

	fclose(fp); /** fermeture du fichier mentionné en argument du programme */

	exit(EXIT_SUCCESS);
}
