/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   README.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:58:14 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/04 13:06:46 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*__NOTAS PARA ALBERT____________________

Every builtin must have the prototype:										  */

int	nombre_builtin(char **args);

/*
*	'args' being a NULL-terminated array of strings, representing the arguments
*	passed to the builting (excluding its name).
*	The function must return the Return Value of executing the builtin.
*	Incorrect arguments or errors on execution must be handled by the builtin
*	function, printing the error message and returning the expected value.
*/
