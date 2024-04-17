#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

char	*get_start(char *start, char *res, int *nl);
size_t	ft_my_strlen(char *s);
char	*ft_my_strdup(char *s);
int		ft_my_strchr(char *s, int c);
char	*ft_my_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_my_substr(char *s, unsigned int start, size_t len);
char	*ft_my_strdup(char *str);

#endif
