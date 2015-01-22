#include "pile.h"

int		main(int argc, char **argv)
{
	t_file *list;
	t_file *elem;
	t_hub	e;

	(void)argc;
	list = NULL;
	e.tmp = opendir(argv[1]);
	while ((e.dp = readdir(e.tmp)))
	{
		elem = ft_new_list(list, e);
//		printf("%c", elem->type);
//		printf("%s ", elem->perms);
//		printf("%s ", elem->uid);
//		printf("%s ", elem->gid);
//		printf("%d ", elem->size);
//		printf("%s ", elem->date);
		printf("%s\n", elem->name);
	}
	closedir(e.tmp);
	return (0);
}