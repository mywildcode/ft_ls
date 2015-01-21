#include "pile.h"

char	ft_type(mode_t mode)
{
	if ((mode & S_IFIFO) == S_IFIFO)
		return('p');
	if ((mode & S_IFCHR) == S_IFCHR)
		return('c');
	if ((mode & S_IFDIR) == S_IFDIR)
		return('d');
	if ((mode & S_IFBLK) == S_IFBLK)
		return('b');
	if ((mode & S_IFREG) == S_IFREG)
		return('-');
	if ((mode & S_IFLNK) == S_IFLNK)
		return('l');
	if ((mode & S_IFSOCK) == S_IFSOCK)
		return('s');
	return('\0');
}

char const	*ft_perms(mode_t mode) 
{
    static char 	buff[16];
    int 			i;

	i = 0;
    ((mode & S_IRUSR) == S_IRUSR) ? (buff[i] = 'r') : (buff[i] = '-');
    i++;
    ((mode & S_IWUSR) == S_IWUSR) ? (buff[i] = 'w') : (buff[i] = '-');
    i++;
    ((mode & S_IXUSR) == S_IXUSR) ? (buff[i] = 'x') : (buff[i] = '-');
    i++;
    ((mode & S_IRGRP) == S_IRGRP) ? (buff[i] = 'r') : (buff[i] = '-');
    i++;
    ((mode & S_IWGRP) == S_IWGRP) ? (buff[i] = 'w') : (buff[i] = '-');
    i++;
    ((mode & S_IXGRP) == S_IXGRP) ? (buff[i] = 'x') : (buff[i] = '-');
    i++;
    ((mode & S_IROTH) == S_IROTH) ? (buff[i] = 'r') : (buff[i] = '-');
    i++;
    ((mode & S_IWOTH) == S_IWOTH) ? (buff[i] = 'w') : (buff[i] = '-');
    i++;
    ((mode & S_IXOTH) == S_IXOTH) ? (buff[i] = 'x') : (buff[i] = '-');
    return (buff);
}

char	*ft_owners_name(uid_t uid)
{
	t_hub	e;

	if ((e.pwd = getpwuid(uid)) != NULL)
		return(e.pwd->pw_name);
	else
		return(ft_itoa(uid));
	return(NULL);
}

char	*ft_group_name(gid_t gid)
{
	t_hub	e;

	if ((e.grp = getgrgid(gid)) != NULL)
		return(e.grp->gr_name);
	else
		return(ft_itoa(gid));
	return(NULL);
}

int 	ft_file_size(off_t size)
{
	return(size);
}

char	*ft_date(__darwin_time_t *time)
{
	char	*date;

	date = (char *)(ft_strsub(ctime(time), 4, 12));
	return(date);
}

char const	*ft_file_name(char const *s)
{
	return(s);
}

t_file	*ft_new_list(t_file *list, t_hub e)
{
	t_file *elem;
	t_file *tmp;

	tmp = (t_file *)malloc(sizeof(tmp));
	ft_fill_list(tmp, e);
	elem = tmp;
	free(tmp);
	elem->next = list;
	return(elem);
}

void	ft_fill_list(t_file *tmp, t_hub e)
{
	tmp->uid = (char *)malloc(sizeof(tmp->uid) * strlen(ft_owners_name(e.statbuf.st_uid)) + 1);
	tmp->gid = (char *)malloc(sizeof(tmp->gid) * strlen(ft_group_name(e.statbuf.st_gid)) + 1);
	tmp->name = (char *)malloc(sizeof(tmp->name) * strlen(ft_file_name(e.dp->d_name)) + 1);
	stat(e.dp->d_name, &e.statbuf);
//	tmp->type = ft_type(e.statbuf.st_mode);
	tmp->perms = ft_perms(e.statbuf.st_mode);
	tmp->uid = ft_owners_name(e.statbuf.st_uid);
	tmp->gid = ft_group_name(e.statbuf.st_gid);
//	tmp->size = ft_file_size((intmax_t)e.statbuf.st_size);
//	tmp->date = strdup(ft_date(&e.statbuf.st_mtime));
	tmp->name = ft_file_name(e.dp->d_name);
}






















