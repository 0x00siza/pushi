#include "push_swap_bonus.h"

static int	is_valid(char *line)
{
	if (!ft_strcmp(line, "sa\n")
		|| !ft_strcmp(line, "sb\n")
		|| !ft_strcmp(line, "ss\n")
		|| !ft_strcmp(line, "pa\n")
		|| !ft_strcmp(line, "pb\n")
		|| !ft_strcmp(line, "ra\n")
		|| !ft_strcmp(line, "rb\n")
		|| !ft_strcmp(line, "rr\n")
		|| !ft_strcmp(line, "rra\n")
		|| !ft_strcmp(line, "rrb\n")
		|| !ft_strcmp(line, "rrr\n"))
		return (1);
	return (0);
}

static void	do_command_1(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strcmp(line, "sa")))
		swap(stack_a);
	if (!(ft_strcmp(line, "sb")))
		swap(stack_b);
	if (!(ft_strcmp(line, "ss")))
	{
		swap(stack_a);
		swap(stack_b);
	}
	if (!(ft_strcmp(line, "pa")))
		push(stack_a, stack_b);
	if (!(ft_strcmp(line, "pb")))
		push(stack_b, stack_a);
}

static void	do_command_2(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strcmp(line, "ra")))
		rotate(stack_a);
	if (!(ft_strcmp(line, "rb")))
		rotate(stack_b);
	if (!(ft_strcmp(line, "rr")))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	if (!(ft_strcmp(line, "rra")))
		reverse_rotate(stack_a);
	if (!(ft_strcmp(line, "rrb")))
		reverse_rotate(stack_b);
	if (!(ft_strcmp(line, "rrr")))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
}

void	print_checker_res(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(stack_a))
		ft_putendl_fd("OK\n", 1);
	else
		ft_putendl_fd("KO\n", 1);
	if (*stack_a)
		free_stack(stack_a);
	if (*stack_b)
		free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_check_args(argc, argv);
	init_stack(stack_a, argc, argv);
    line = get_next_line(0);
	while (line)
	{
		if (is_valid(line))
		{
			do_command_1(line, stack_a, stack_b);
            do_command_2(line, stack_a, stack_b);
		}
        else
        {
            ft_error("Error");
            return -1;
        }
		line = get_next_line(0);
	}
	print_checker_res(stack_a, stack_b);
	return (0);
}
