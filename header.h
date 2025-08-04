#ifndef HEADER_H
# define HEADER_H
# include "get_next_line/get_next_line.h"
# include "libft-project/libft.h"
# include <fcntl.h>


// typedef struct flags
// {
	// 	int no;
	// 	int so;
	// 	int we;
	// 	int ea;
	// 	int f;
	// 	int c;
	// }dir_flags;
	
	typedef struct config
	{
		char	*direction;
		int		flag;
		char	**texture;
	}			config;
	
	typedef struct directions
	{
		char	*no;
		char	*so;
		char	*we;
		char	*ea;
		char	*f;
		char	*c;
	}			textures;
	
	// parsing
	void		parse_floor_ceiling(char *line, textures *text);
	textures	*init_textures(void);
	int			check_textures(char *file_name);
	
	int			ft_strcmp(const char *s1, const char *s2);
	void		parse_dir(char *line, textures *text);
	int			check_argv(int argc, char **argv);
#endif