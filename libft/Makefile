# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/27 19:00:55 by tsito             #+#    #+#              #
#    Updated: 2026/05/01 13:43:08 by tsito            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft
NAME_A		:= $(NAME).a

CFLAGS		:= -Wall -Wextra -Werror
ARFLAGS		:= rcs

SRCS		:= $(wildcard *.c)
INCDIR		:= .
OUTDIR		:= .out
OBJS 		:= $(addprefix $(OUTDIR)/, $(SRCS:.c=.o))

all: $(NAME_A)

$(NAME_A): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OUTDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	$(RM) -r $(OUTDIR)

fclean: clean
	$(RM) $(NAME_A)

re: fclean all

.PHONY: all clean fclean re
