/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:09:34 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/12 12:49:21 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void validate_argument (int ac, char **av, char **envp)
{
	check_envp(envp);

	//check ac

	//check av
		// check here_doc
		
}

void check_envp(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH= ", 5) && *envp[6] != 0)
			return;
	}
	
}