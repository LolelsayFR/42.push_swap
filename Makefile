NAME			=	push_swap


SRC				=	script/main.c\

LIBFT_PATH		=	./modules/42.libft
LIBFT			=	$(LIBFT_PATH)/libft.a

FTPRINTF_PATH	=	./modules/42.ft_printf
FTPRINTF		=	$(FTPRINTF_PATH)/libftprintf.a

CFLAGS			=	-lXext -lX11 -Wall -Werror -Wextra -g

all:	hello $(NAME)

hello:
	@echo "\e[48;2;100;0;100;1m Welcome to PushSwap Makefile !\e[0m\n"

info: hello
	@echo "\e[48;2;70;70;70;1m PushSwap usage : \e[0m\n"
	@echo "./push_swap <Numbers>\n"

lib: hello $(LIBFT) $(FTPRINTF)

$(NAME): ${LIBFT} ${FTPRINTF} ${SRC}
	@echo "\e[48;2;0;155;0;1m Compile Push_Swap \e[0m\n"
	cc ${SRC} ${GNL} ${LIBFT} ${FTPRINTF} ${CFLAGS} -o $(NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

$(LIBFT):
	@echo "\e[48;2;0;155;0;1m Make LIBFT \e[0m\n"
	@$(MAKE) --no-print-directory bonus -C $(LIBFT_PATH)
	@$(MAKE) --no-print-directory  clean  -C $(LIBFT_PATH)
	@echo "\e[48;2;0;0;155;1m Done for LIBFT \e[0m\n"

$(FTPRINTF):
	@echo "\e[48;2;0;155;0;1m Make FT_PRINTF \e[0m\n"
	@$(MAKE) --no-print-directory -C $(FTPRINTF_PATH)
	@$(MAKE) --no-print-directory clean -C $(FTPRINTF_PATH)
	@echo "\e[48;2;0;0;155;1m Done for FT_PRINTF \e[0m\n"

fclean: hello clean
	@echo "\e[48;2;155;100;0;1m Uninstall SoLong \e[0m\n"
	@$(RM) $(NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

re:	fclean all

.PHONY: all clean fclean re lib
