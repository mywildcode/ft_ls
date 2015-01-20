#include "pile.h"

int		main(void)
{
	t_file *list;
	t_file *elem;
	t_hub	e;

	list = NULL;
	e.tmp = opendir(".");
	while ((e.dp = readdir(e.tmp)))
		elem = ft_new_list(list, e), printf("%s ", elem->perms);
//	printf("%c", elem->type);
//	printf("%s ", elem->perms);
//	printf("%s ", elem->iud);
//	printf("%s ", elem->gid);
//	printf("%d ", elem->size);
//	printf("%s ", elem->date);
//	printf("%s\n", elem->name);
	closedir(e.tmp);
	return (0);
}