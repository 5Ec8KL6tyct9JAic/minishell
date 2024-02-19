#include "minishell.h"


// // func pour prendre l'input (à faire)
static char	*get_input(int status)
{
    char    *input;
    char     *path;
    t_parser parser;
    
    while(status)
    {
        path = get_pwd();
        input = readline(path);
        if(!input)
            //EOF, EXIT
            break;
        add_history(input);
        parser.input = input;
        ft_printf("%s\n", parser.input);
        free(path);
        free(input);
    }
    return(0);
}

// // fonction à faire (relier toutes les fonction parse pour le checking) en gros elle va tout mettre a null pour pas de leaks
// static void	parse_checked(t_statement **statement_list, t_data *data)
// {

// }

// // main à finir + fonctions du main à créer
//int	main(int ac, char **av, char **envp)
// {
// 	t_data		data;
// 	t_statement	*statement_list;
// 	char		*input;

// 	if (av && ac > 1)
// 		// fonction a faire pour check si les av et ac sont sup à 1 et si oui display error (free la data du coup)
// 	setup_shell();// fonction pas encore faite mais à faire
// 	while (1); // rentrer dans la boucle elle va checker les param de input, l'historique du shell, doit return EXIT_SUCESS

// 	return (EXIT_SUCCESS);
//}
int main (void)
{
   get_input(1);
    return 0;
}
