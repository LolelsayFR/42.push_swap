NAME			=	push_swap
D_NAME			=	d_push_swap
B_NAME			=	checker

SRC				=	script/ps_a.c\
					script/ps_b.c\
					script/ps_both.c\
					script/ps_spacer_split_lst.c\
					script/ps_atol.c\

PS_SRC				=	script/ps/main.c\
					script/ps/ps_utils.c\
					script/ps/ps_utils_2.c\
					script/ps/ps_utils_3.c\
					script/ps/ps_algo.c\
					script/ps/ps_sort.c\
					script/ps/ps_sort_2.c\

B_SRC				=	script/check/main.c\

LIBFT_PATH		=	./modules/42.libft
LIBFT			=	$(LIBFT_PATH)/libft.a

CFLAGS			=	-Wall -Werror -Wextra -g -Ofast

all:	$(NAME) info

debug:	$(D_NAME) d_info

bonus:	$(B_NAME) b_info

hello:
	@echo "\e[48;2;100;0;100;1m Welcome to PushSwap Makefile !\e[0m\n"

info: hello
	@echo "\e[48;2;70;70;70;1m PushSwap usage : \e[0m\n"
	@echo "./push_swap <Numbers>\n"

d_info: hello
	@echo "\e[48;2;70;70;70;1m PushSwap usage : \e[0m\n"
	@echo "./d_push_swap <Numbers>\n"

b_info: hello
	@echo "\e[48;2;70;70;70;1m PushSwap usage : \e[0m\n"
	@echo "./push_swap <Numbers> | ./push_swap <Same Numbers>\n"

lib: hello $(LIBFT)

$(NAME): ${LIBFT} ${SRC} ${PS_SRC}
	@echo "\e[48;2;0;155;0;1m Compile Push_Swap \e[0m\n"
	cc ${SRC} ${PS_SRC} ${LIBFT} ${CFLAGS} -o $(NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

$(D_NAME): ${LIBFT} ${FTPRINTF} ${MINILIBX} ${GNL} ${SRC} ${PS_SRC}
	@echo "\e[48;2;0;155;0;1m Compile D_Push_Swap \e[0m\n"
	cc ${SRC} ${PS_SRC} -D PS_DEBUG=1  ${LIBFT} ${CFLAGS} -o $(D_NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

$(B_NAME): ${LIBFT} ${FTPRINTF} ${MINILIBX} ${GNL} ${SRC} ${B_SRC}
	@echo "\e[48;2;0;155;0;1m Compile D_Push_Swap \e[0m\n"
	cc ${SRC} ${B_SRC} -D PS_CHECKER=1 ${LIBFT} ${CFLAGS} -o $(B_NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

$(LIBFT):
	git submodule update --init --recursive
	@echo "\e[48;2;0;155;0;1m Make LIBFT \e[0m\n"
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
	@$(MAKE) --no-print-directory  clean  -C $(LIBFT_PATH)
	@echo "\e[48;2;0;0;155;1m Done for LIBFT \e[0m\n"

fclean: hello clean
	@echo "\e[48;2;155;100;0;1m Uninstall PushSwap \e[0m\n"
	$(RM) $(NAME)
	$(RM) $(D_NAME)
	$(RM) $(B_NAME)
	$(RM) $(LIBFT)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"
re:	fclean all

.PHONY: all clean fclean re lib
