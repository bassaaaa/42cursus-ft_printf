# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/27 19:00:55 by tsito             #+#    #+#              #
#    Updated: 2026/05/01 13:39:05 by tsito            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf
NAME_A		:= $(NAME).a

CFLAGS		:= -Wall -Wextra -Werror
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

all: $(NAME_A)

$(NAME_A): $(OBJS)
	@$(MAKE) -C $(LIBFT)
	@cp $(LIBFT)/$(LIBFT).a $@
	$(AR) $(ARFLAGS) $@ $^

$(OUTDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT) clean
	$(RM) -r $(OUTDIR)

fclean: clean
	@$(MAKE) -C $(LIBFT) fclean
	$(RM) $(NAME_A)

re: fclean all

.PHONY: all clean fclean re test
