/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:04:27 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/31 12:27:13 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_FX_H
# define PRINT_FX_H

# define PFX_PREFIX "\033["
# define PFX_AFFIX "m"

# define PFX_CRED "31"
# define PFX_CGREEN "32"
# define PFX_CYELLOW "33"
# define PFX_CBLUE "34"
# define PFX_CPINK "35"
# define PFX_CTEAL "36"
# define PFX_CWHITE "37"

# define PFX_NORMAL "0"
# define PFX_BOLD "1"
# define PFX_FAINT "2"
# define PFX_ULINE "4"
# define PFX_CROSSED "9"

# define PFX_SET_DEFAULT "\033[0m"
#endif
