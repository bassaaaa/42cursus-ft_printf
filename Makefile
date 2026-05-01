# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/27 19:00:55 by tsito             #+#    #+#              #
#    Updated: 2026/05/01 13:01:30 by tsito            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf
NAME_A		:= $(NAME).a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
AR			:= ar
ARFLAGS		:= rcs

SRCS		:= ft_printf.c \
			   ft_print_char.c \
			   ft_print_str.c \
			   ft_print_ptr.c \
			   ft_print_nbr.c \
			   ft_print_uint.c \
			   ft_print_hex.c
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
