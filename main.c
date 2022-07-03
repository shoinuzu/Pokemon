#include "pokemon.h"

// Função para lidar com inputs invalidos
int	string_check(char *str)
{
	int	i = 0;
	while (str[i])
	{
		str[i] = toupper(str[i]);
		i++;
	}
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if ((str[i] != 'N') && (str[i] != 'S') && (str[i] != 'E') && (str[i] != 'O'))
			return (1);
		i++;
	}
	str[i] = '\0';
	return (0);
}

int main(void)
{
	char	*mov_str = NULL;
	size_t	mov_len;
	
	inputget:	
	printf("Movimentos-> ");
	getline(&mov_str, &mov_len, stdin);
	if (string_check(mov_str))
	{
		printf("Conjunto de movimentos invalido, por favor use apenas: N, S, E, O. Ou pressione ctrl + C para sair.\n");
		goto inputget;
	}
	printf("\n O numero de pokemons que o Ash apanhou foi -> %d\n", pokemon(mov_str));
	free(mov_str);
	return (0);
}
