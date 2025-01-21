NAME			=	push_swap


SRC				=	script/main.c\
					script/ft_spacer_split_lst.c\
					script/ft_ps_atol.c\
					script/ps_a.c\
					script/ps_b.c\
					script/ps_both.c\
					script/ps_utils.c\
					script/ps_algo.c\

LIBFT_PATH		=	./modules/42.libft
LIBFT			=	$(LIBFT_PATH)/libft.a

CFLAGS			=	-Wall -Werror -Wextra -g

all:	hello $(NAME)

hello:
	@echo "\e[48;2;100;0;100;1m Welcome to PushSwap Makefile !\e[0m\n"

info: hello
	@echo "\e[48;2;70;70;70;1m PushSwap usage : \e[0m\n"
	@echo "./push_swap <Numbers>\n"

lib: hello $(LIBFT)

$(NAME): ${LIBFT} ${SRC}
	@echo "\e[48;2;0;155;0;1m Compile Push_Swap \e[0m\n"
	cc ${SRC} -D PS_DEBUG=0  ${LIBFT} ${CFLAGS} -o $(NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

$(LIBFT):
	git submodule update --init --recursive
	@echo "\e[48;2;0;155;0;1m Make LIBFT \e[0m\n"
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
	@$(MAKE) --no-print-directory  clean  -C $(LIBFT_PATH)
	@echo "\e[48;2;0;0;155;1m Done for LIBFT \e[0m\n"

fclean: hello clean
	@echo "\e[48;2;155;100;0;1m Uninstall PushSwap \e[0m\n"
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

debug: hello ${LIBFT} ${FTPRINTF} ${MINILIBX} ${GNL} ${SRC}
	cc ${SRC} -D PS_DEBUG=1  ${LIBFT} ${CFLAGS} -o $(NAME)

re:	fclean all

.PHONY: all clean fclean re lib
