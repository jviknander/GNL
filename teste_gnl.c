/*

char *get_next_line(int fd)
{
	static char *storage;
	char *line;
	char buf[1024];
	int ret;

	ret = read(fd, buf, 42);
	while (ret > 0)
	{
		// Alocar memoria para o storage
		// Se o storage for igual a NULL, aloca se memoria
		if (storage == NULL)
			storage = ft_strdup("");
		buf[ret] = '\0';

		// Meter coisas para o storage
		// Ver se o storage ou buf tem \n
		// Quando o buf tiver o \n, break
		read(fd, buf, 42);
	}
	// Quando e que ele sai do loop?
	// Nao tiver nada para ler (storage tem um '\0')
	// Quando encontra o '\n'
	// tamanho da string
	// O conteudo -> storage (Que vai ter o \n)
}	

*/

char	





char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			r;
	int 		until_n;


	line = NULL;
	if (fd > 1024 || BUFFER_SIZE < 0)
		return (NULL) ;
	r = read (fd, buf, BUFFER_SIZE);
	while (r > 0)
	{
		if (storage == NULL)
			 storage = ft_strdup(""); // caso nao tenha nada, manda nada para a alocacao do storage
		buf[r] = '\0';
		storage = ft_strjoin(storage, buf);
		if (ft_strchr(buf, '\n') != -1)
				break;
		r = read(fd, buf, BUFFER_SIZE);
	}
	until_n = ft_strchr(storage, '\n');
	line = ft_substr(storage, 0, until_n);
	storage = ft_substr(storage, until_n + 1, ft_strlen(storage) - until_n);
	return (line);
}}
