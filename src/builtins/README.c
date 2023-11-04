/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   README.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:58:14 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/04 19:39:43 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*__NOTAS PARA ALBERT____________________

Every builtin must have the prototype:										  */

int	function_name(char **args, char ***env);

/*
*	'args' being a NULL-terminated array of strings, representing the arguments
*	passed to the builting (including its name).
*	The function must return the Return Value of executing the builtin.
*	Incorrect arguments or errors on execution must be handled by the builtin
*	function, printing the error message and returning the expected value.
*/


// OR EVEN BETTER: there could be a general function to execute
// builtins, that recieves the args (including the builtin name) and executes
// the appropriate builtin function.

int	exec_builtin(char **args, char ***env);
