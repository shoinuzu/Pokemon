#include "pokemon.h"

// função para executar um movimento correspondente a uma das 4 direções numa posição, 
//ambos passados como parâmetros, 
//retorna a posição após o movimento de ash
t_mov	ash_move(char m, t_mov ash_pos)
{
	if (m == 'N')
		ash_pos.y++;
	else if (m == 'S')
		ash_pos.y--;
	else if (m == 'O')
		ash_pos.x--;
	else
		ash_pos.x++;
	return (ash_pos);
}

// função para verificar a existencia de um pokemon na casa passado como parametro
// verifica se primeiro se o Ash já esteve em determinada coluna
// caso ja tenha estado
// procede a verificar se naquela instante a sua posição corresponde também ao atual
// valor do eixo y
int	poke_check(int *x_values, int *y_values, t_mov ash_pos, int index)
{
	int i = 0;
	while (i < index)
	{
		if (ash_pos.x == x_values[i])
		{
			if(ash_pos.y == y_values[i])
				return (0);
		}
		i++;
	}
	return (1);
}
// função principal
int	pokemon(char *str)
{
	int	it = 0; // iterado para percorrer a string de movimentos
	int	to_return = 1; // valor a ser retornado, iniciado para 1, o pokemon da primeira casa
	int	*x_values = NULL;
	int	*y_values = NULL; // duas listas para guardar as posições do Ash
	t_mov	position; // posição para guardar a posição atual do Ash
	
	x_values = (int *)malloc(sizeof(int) * (strlen(str) + 1));
	y_values = (int *)malloc(sizeof(int) * (strlen(str) + 1));

	x_values[0] = x_values[strlen(str)] = position.x = 0;
	y_values[0] = y_values[strlen(str)] = position.y = 0;
	// loop que percorre a string de movimentos
	while (str[it])
	{
		position = ash_move(str[it], position); // aplica o movimento à posição atual
		it++;
		x_values[it] = position.x; 
		y_values[it] = position.y; // guarda as coordenadas da posição
		to_return+= poke_check(x_values, y_values, position, it); // verifica a existencia de pokemon
		// na casa e em caso de haver incrementa o valor a retornar
	}
	free(x_values);
	free(y_values);
	return (to_return);
}
