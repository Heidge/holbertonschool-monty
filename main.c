#include "monty.h"

int main (int argc, char *argv[])
{
	FILE *fp;

	if (argc != 2)
	usage_error(); /* appel de la fonction usage_error si utilisateur n'a pas rentré exactement deux arguments **/

	fp = fopen(argv[1], "r"); /** "r" pour read -> mode d'utilisation */

	if (fp == NULL)
	open_file_failure();

	fclose(fp); /** fermeture du fichier mentionné en argument du programme */

}
