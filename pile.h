#ifndef PILE_H
# define PILE_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <locale.h>
#include <stdint.h>
#include <string.h>
#include "libft/libft.h"

typedef struct		s_hub
{
	struct dirent	*dp;
	struct stat		statbuf;
	struct passwd	*pwd;
	struct group	*grp;
	char			*date;
	DIR				*tmp;
}					t_hub;

typedef struct		s_file
{
	char			type; // file type
	char const		*perms; // file perms
	char			*iud; // file owners name
	char			*gid; // file group name
	int				size; // file size
	char			*date; // file date of modification
	char const		*name; // file name
	struct s_file	*next;
}					t_file;

char			ft_type(mode_t mode);
char const		*ft_perms(mode_t mode);
char			*ft_owners_name(uid_t uid);
char			*ft_group_name(gid_t gid);
int 			ft_file_size(off_t size);
char			*ft_date(__darwin_time_t *time);
char const		*ft_file_name(char const *s);
t_file			*ft_new_list(t_file *list, t_hub e);
void			ft_fill_list(t_file *elem, t_hub e);

#endif