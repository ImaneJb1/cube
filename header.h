#ifndef HEADER_H
#define HEADER_H
#include "libft-project/libft.h"
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
int	ft_strcmp(const char *s1, const char *s2);
textures *init_textures(void);
void	parse_dir(char *line);

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
	char *direction;
	int flag;
	char **texture;
}config;


typedef struct directions
{
	char *no;
	char *so;
	char *we;
	char *ea;
	char *f;
	char *c;
} textures;

#endif