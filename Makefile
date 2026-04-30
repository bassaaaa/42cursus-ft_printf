# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/27 19:00:55 by tsito             #+#    #+#              #
#    Updated: 2026/05/01 01:03:36 by tsito            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf
NAME_A		:= $(NAME).a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
AR			:= ar
ARFLAGS		:= rcs

SRCS		:= ft_printf.c \
			   ft_putchar_pf.c \
			   ft_putstr_pf.c \
			   ft_putptr_pf.c \
			   ft_putnbr_pf.c \
			   ft_putuint_pf.c \
			   ft_puthex_pf.c
LIBFT		:= libft
INCDIR		:= .
OUTDIR		:= .out
OBJS 		:= $(addprefix $(OUTDIR)/, $(SRCS:.c=.o))
TEST_BIN	:= $(OUTDIR)/test

all: $(NAME_A)

$(NAME_A): $(OBJS)
	@$(MAKE) -C $(LIBFT)
	@cp $(LIBFT)/$(LIBFT).a $@
	$(AR) $(ARFLAGS) $@ $^

$(OUTDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

test: $(NAME_A)
	$(CC) $(CFLAGS) -DTEST -I$(INCDIR) $(SRCS) $(NAME_A) -o $(TEST_BIN)
	./$(TEST_BIN)

clean:
	@$(MAKE) -C $(LIBFT) clean
	$(RM) -r $(OUTDIR)

fclean: clean
	@$(MAKE) -C $(LIBFT) fclean
	$(RM) $(NAME_A)

re: fclean all

.PHONY: all clean fclean re test
