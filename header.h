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

typedef struct textures
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}			textures;

// *************** parsing ***************

void		parse_floor_ceiling(char *line, config *arr);
void		parse_dir(char *line, config *arr);
textures	*init_textures(void);
int			fill_textures_map(char *file_name);
config		*init_dir_arr(textures *text);
config		*init_fc_arr(textures *text);
void		check_textures(void);
int			ft_strcmp(const char *s1, const char *s2);
void		create_map_arr(char *string);
int			check_argv(int argc, char **argv);
void		collect_the_map(char *line, int fd);
void		parse_map(void);
void		free_and_exit(int status);
int			open_file(char *file_name);
// global
textures	**text_func(void);
char		***the_map(void);
// garbage collector
void 		free_all(void);
void		*gc_calloc(size_t count, size_t size);
void		*gc_malloc(size_t size);
#endif