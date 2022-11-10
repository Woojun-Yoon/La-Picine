#include <stdio.h>
#include "ex01/ft_strncpy.c"
#include "ex10/ft_strlcpy.c"

int main()
{
	char	*src = "hello";
	char	dest[100];
	printf("함수 출격~\n");
	printf("%s\n", ft_strncpy(dest, src, 3));	
	printf("여기까지 버스에러 안남\n");
	printf("%u\n", ft_strlcpy(dest, src, 3));	
	return 0;

}
