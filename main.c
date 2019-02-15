#include <stdio.h>
#include "ft_printf.h"

int	main()
{
    ft_printf("{LP}%%{BB}%d\n", ft_printf("{LR}%s\n", "0123456789"));
	// c
	char c = 'b';

	ft_printf("%ca\n", 'b');
	printf("%ca\n", 'b');
	ft_printf("%7cb\n", c);
	printf("%7cb\n", c);
	ft_printf("%-7cc\n", c);
	printf("%-7cc\n", c);
	
	// s
	char	*str;
	str = "012345";

	ft_printf("%sd\n", str);
	printf("%sd\n", str);
	ft_printf("%7se\n", str);
	printf("%7se\n", str);
	ft_printf("%-7sf\n", str);
	printf("%-7sf\n", str);
	ft_printf("%7.2sg\n", str);
	printf("%7.2sg\n", str);
	ft_printf("%-7.2sh\n", str);
	printf("%-7.2sh\n", str);
	ft_printf("%.2si\n", str);
	printf("%.2si\n", str);
	ft_printf("%.7sj\n", str);
	printf("%.7sj\n", str);

	// p
	ft_printf("%p\n", str);
	printf("%p\n", str);
	ft_printf("%7p\n", str);
	printf("%7p\n", str);
	ft_printf("%-7p\n", str);
	printf("%-7p\n", str);


	// oux
	long long x = 23;
	ft_printf("%.5lld\n", x);
	printf("%.5lld\n", x);
	ft_printf("%-.5llda\n", x);
	printf("%-.5llda\n", x);
	ft_printf("%+2lldb\n", x);
	printf("%+2lldb\n", x);
	ft_printf("%06lldc\n", x);
	printf("%06lldc\n", x);
	ft_printf("%-6lldd\n", x);
	printf("%-6lldd\n", x);
	ft_printf("%5lldf\n", x);
	printf("%5lldf\n", x);
	ft_printf("%-+5.4llde\n", x);
	printf("%-+5.4llde\n", x);
	ft_printf("%0+6lldg\n", x);
	printf("%0+6lldg\n", x);
	ft_printf("%lldh\n", x);
	printf("%lldh\n", x);
	ft_printf("%-7.3lldp\n", x);
	printf("%-7.3lldp\n", x);
	ft_printf("% lldpenetration\n", x);
	printf("% lldpenetration\n", x);
	ft_printf("% 5.3llddoublepenetration\n", x);
	printf("% 5.3llddoublepenetration\n", x);

	unsigned  long long p = 255;
	ft_printf("%llx\n", p);
	printf("%llx\n", p);
	ft_printf("%llX\n", p);
	printf("%llX\n", p);
	ft_printf("%llo\n", p);
	printf("%llo\n", p);
	ft_printf("%llu\n", p);
	printf("%llu\n", p);
	
	unsigned  long long u = 15;
	ft_printf("%-7.5llxa\n", u);
	printf("%-7.5llxa\n", u);
	ft_printf("%07llX\n", u);
	printf("%07llX\n", u);
	ft_printf("%0llo\n", u);
	printf("%0llo\n", u);
	ft_printf("%#llx\n", u);
	printf("%#llx\n", u);
    ft_printf("%-#.6llx\n", u);
    printf("%-#.6llx\n", u);
    ft_printf("%#0.8llx\n", u);
    printf("%#0.8llx\n", u);
    ft_printf("%#0.8llo\n", u);
    printf("%#0.8llo\n", u);
    ft_printf("%#.8llx\n", u);
    printf("%#.8llx\n", u);
    ft_printf("%#0.8llo\n", u);
    printf("%#0.8llo\n", u);
    ft_printf("%#llo\n", u);
    printf("%#llo\n", u);
    ft_printf("%8llx\n", u);
    printf("%8llx\n", u);
    ft_printf("%#8llo\n", u);
    printf("%#8llo\n", u);
    ft_printf("%#8llx\n", u);
    printf("%#8llx\n", u);
    ft_printf("%#8llo\n", u);
    printf("%#8llo\n", u);

	// f
	long double i = 234.666666;
    ft_printf("%#-.5Lfa\n", i);
    printf("%#-.5Lfa\n", i);
    ft_printf("%#+2Lfb\n", i);
    printf("%#+2Lfb\n", i);
    ft_printf("%#06Lfc\n", i);
    printf("%#06Lfc\n", i);
    ft_printf("%#-6Lfd\n", i);
    printf("%#-6Lfd\n", i);
    ft_printf("%#5Lff\n", i);
    printf("%#5Lff\n", i);
    ft_printf("%#-+5.4Lfe\n", i);
    printf("%#-+5.4Lfe\n", i);
    ft_printf("%#0+6Lfg\n", i);
    printf("%#0+6Lfg\n", i);
    ft_printf("%#Lfh\n", i);
    printf("%#Lfh\n", i);
    ft_printf("%#-7.3Lfp\n", i);
    printf("%#-7.3Lfp\n", i);
    ft_printf("%-.5Lfa\n", i);
    printf("%-.5Lfa\n", i);
    ft_printf("%+2Lfb\n", i);
    printf("%+2Lfb\n", i);
    ft_printf("%06Lfc\n", i);
    printf("%06Lfc\n", i);
    ft_printf("%-6Lfd\n", i);
    printf("%-6Lfd\n", i);
    ft_printf("%5Lff\n", i);
    printf("%5Lff\n", i);
    ft_printf("%-+5.4Lfe\n", i);
    printf("%-+5.4Lfe\n", i);
    ft_printf("%0+6Lfg\n", i);
    printf("%0+6Lfg\n", i);
    ft_printf("%Lfh\n", i);
    printf("%Lfdh\n", i);
    ft_printf("%-7.3Lfp\n", i);
    printf("%-7.3Lfp\n", i);
	ft_printf("% -.3Lfqq\n", i);
	printf("% -.3Lfqq\n", i);
	ft_printf("% Lfqqqq\n", i);
	printf("% Lfqqqq\n", i);
	ft_printf("%+Lfprincess\n", i);
	printf("%+Lfprincess\n", i);
 
}
