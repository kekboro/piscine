struct s_my_group
{
	int a;
	char c1;
	char c2;
	long l;
};

struct s_my_s1
{
	int a;
	char c[5];
	int p;
};

struct s_my_s2
{
	int b;
	struct s_my_s1 s1;
	struct s_my_s2 *s2;
};

int main()
{
	struct s_my_group	my_element;
	int a;
	struct s_my_group	*structpointer;
	
	my_element.c1 = 1;
	a = 2 * my_element.a + 8;
	structpointer = &my_element;
	(*structpointer).c2 = 42;
	a = 21 + (*structpointer).a;
}

/*https://www.youtube.com/playlist?list=PLxeKVrYoZO6C_4IgEopWvNCYMI1Po3dVY*/