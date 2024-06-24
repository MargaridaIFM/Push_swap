/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 10:33:41 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/24 11:23:46 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2 || (argc > 2 && argv[1][0] == '\0'))
		return (0);
	null_initialization_s_data(&data);
	ft_parsing(argv, &data);
	data.a_size = argc - 1;
	if (check_is_sorted(&data) == 0)
		free_exit(&data, "");
	sorting(&data, data.a_size);
	if (check_is_sorted(&data) == 0)
		free_exit(&data, "");
	return (0);
}

/*
	[x] Iniciate the data with NULL;

	[x] PARSING

	[x] size da list a and b

	[x] OPERATIONS
		[x]  Swap
		[x]  Push
		[x]  Reverse
		[x]  Rotate

	[x] check if its sorted

[] sorting algorithm
	[] SORTING
		[x]sort_two
			[x] 1 2 is_sorted
			[x] 2 1 sa

		[x]sort_three
			[x] 1 2 4 is_sorted
			[x] 1 4 2 rra sa
			[x] 2 4 1 rra
			[x] 2 1 4 sa
			[x] 4 1 2 ra
			[x] 4 2 1 ra sa

		[x] sort 4
		[x] sort 5
		[] sort bigger than 5 - algoritm

	[]check if its sorted

	[] FREE
		[] free_exit(data, NULL);
		[] free lista toda;
 */

/*Pseudocode:
dois pointer p as stacks a e	b;
pointer incial em null			*a_head;
se nao existirem parametros  ou a string tiver vazia return (1);
//se o argc for superior nao precisamos do split porque ja vamos ter varios 
argumentos criacao do stack com os valores dados no comando
	- funcao void inicial_stack(stack a, argv) ?
   // funcao atol para converter uma string num long int ?
	Mensagem “Error” em caso de duplicados,
		maior ou menor que o integer (INT_MAX e INT_MIN), nao ser um integer
	funcao para anexar um node
		- ligar a head com o primeiro node e depois os seguintes pelo last node
		(ver funcao append new node e findlastnode)
	free de matrix inicial

IMPLEMENTACAO:
fazer funcoes pb , pb, ra rb, etc..
verificar se os numeros estao ordenados ou nao
algoritmo para 2, 3 , 4 e 5 numeros ?
				caso espeficicos 3 numeros usar so o stack a,
					passar o numero maior p o fim e depois verificar se os outros
					 dois estao ordenados
algoritmo > 5  ---> 1. puxar todos os elementos p b ate ter apenas 5 na stack a;
					2. e depois usar a funcao para se tiver 5 numeros;
					3. encontrar o BBF de cada numero da stack a com cada da 
					stack b (Nr A tem de ser > que o da B);
					4. ver qual o custo (numero de comandos p o BBF topo da 
					stack A e B e depois p a outra);
					5. o que tiver menor custo usa pa.
					6. repetir ate nao existir elementos na stack B;
					7. rotate de stack A ate o ultimo elemento ser o maior


verificar se os numeros estao ordenados
libertar memoria do pointer	a(retorno que queremos)

output - lista de operaccoes realizadas
*/
