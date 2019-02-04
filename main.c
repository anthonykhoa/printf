#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	/*long long i = -23;
	ft_printf("%.5llda\n", i);
	printf("%.5llda\n", i);
	ft_printf("%+2lldb\n", i);
	printf("%+2lldb\n", i);
	ft_printf("%06lldc\n", i);
	printf("%06lldc\n", i);
	ft_printf("%-6lldd\n", i);
	printf("%-6lldd\n", i);
	ft_printf("%5lldf\n", i);
	printf("%5lldf\n", i);
	ft_printf("%-+5.4llde\n", i);
	printf("%-+5.4llde\n", i);
	ft_printf("%0+6lldg\n", i);
	printf("%0+6lldg\n", i);
	ft_printf("%lldh\n", i);
	printf("%lldh\n", i);
	ft_printf("%-7.3lldp\n", i);
	printf("%-7.3lldp\n", i);*/

	unsigned  long long u = 15;
	ft_printf("%-.5llx\n", u);
	printf("%-.5llx\n", u);
	ft_printf("%07llX\n", u);
	printf("%07llX\n", u);
	ft_printf("%0llo\n", u);
	printf("%0llo\n", u);
	ft_printf("%#llx\n", u);
	printf("%#llx", u);
}
