#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// #include <

int  ft_strlen(char *str)
{
  int  i;

  i = -1;
  while (str[++i])
    ;
  return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] && i < n - 1
			&& s1[i] && s2[i])
		i++;
	if (n)
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*steroids;
	unsigned int	i[2];

	i[0] = 0;
	i[1] = len;
	if (!s)
		return (0);
	if (ft_strlen(s) < len)
		i[1] = ft_strlen(s);
	steroids = (char *)malloc(sizeof(*steroids) * (i[1] + 1));
	if (!steroids)
		return (0);
	if (start >= ft_strlen(s))
		while (i[0] < i[1])
			steroids[i[0]++] = '\0';
	while (i[0] < i[1])
		steroids[i[0]++] = s[start++];
	steroids[i[0]++] = '\0';
	return (steroids);
}

void	ft_spit(char const *s, char c, char **strr, int *i)
{
	while (++i[2] < i[1])
	{
		i[4] = 0;
		i[5] = -1;
		while (s[++i[3]] == c && s[i[3]])
			;
		while (s[i[3]] != c && s[i[3]])
		{
			i[4]++;
			i[3]++;
		}
		strr[i[2]] = (char *)malloc(sizeof(*strr[i[2]]) * (i[4] + 1));
		i[3] -= i[4];
		while (s[i[3]] != c && s[i[3]])
		{
			strr[i[2]][++i[5]] = s[i[3]];
			i[3]++;
		}
		strr[i[2]][++i[5]] = '\0';
	}
	strr[i[2]] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**strr;
	int		i[6];
	int		j;

	if (!s)
		return (0);
	j = -1;
	while (++j < 6)
		i[j] = -1;
	i[1] = 0;
	while (s[++i[0]])
	{
		if (i[0] == 0 && s[i[0]] != c && s[i[0]])
			i[1]++;
		if (s[i[0]] == c && s[i[0] + 1] != c && s[i[0] + 1])
			i[1]++;
	}
	strr = (char **)malloc(sizeof(*strr) * (i[1] + 1));
	if (!strr)
		return (0);
	ft_spit(s, c, strr, i);
	return (strr);
}

int main(int c, char **v, char **e)
{
  int i;
  char *pth;
  char **pths;  
  char **mycmdargs;

  i = 0;
  while (ft_strncmp("PATH", e[i], 4) && e[i])
    i++;
  // if (ft_strncmp("PATH", e[i], 4) || !e[i])
    // errs(); //gotta giv this an error no.
  pth = ft_substr(e[i], 5, (ft_strlen(e[i]) - 5));
  // ft_substr(char *s, unsigned int start, size_t len)
  // printf("%d\n", (ft_strlen(e[i]) - 5));
  // printf("%s\n", e[i]);
  pths = ft_split(pth, ':');
  while (*pths) {
    printf("%s\n", *pths);
    pths++;
  }
  // printf("%s\n", pth);
}