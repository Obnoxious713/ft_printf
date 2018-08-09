# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/08 14:57:21 by jfleisch          #+#    #+#              #
#    Updated: 2018/08/08 14:57:22 by jfleisch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

FLAGS = -Wall -Werror -Wextra -g

CC = gcc

NORM = norminette -R CheckForbiddenSourceHeader

SRC = main.c \
		parser.c

OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

LIBFT = ./libft/libft.a
LIBFTINC = -I./libft
LINK_FT = -L./libft -lft

LIBPF = ./libftprintf/libftprintf.a
LIBPFINC = -I./libftprintf
LINK_PF = -L./libftprintf -lftprintf

SRCDIR = ./src/
INCDIR = ./includes/
OBJDIR = ./obj/

all: obj libftprintf libft $(NAME)

libpf:
	@rm -rf $(NAME)
	@rm -rf $(OBJDIR)
	@make -C ./libftprintf fclean
	@make

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(FLAGS) $(LIBPFINC) $(LIBFTINC) -I $(INCDIR) -o $@ -c $<

libftprintf: $(LIBPF)

libft: $(LIBFT)

$(LIBPF):
	@make -C ./libftprintf

$(LIBFT):
	@make -C ./libft

$(NAME): $(OBJ)
	@echo "-> Compiling $(NAME)..."
	@$(CC) -o $(NAME) $(OBJ) $(LINK_PF) $(LINK_FT)
	@echo "...Done"

clean:
	@echo "-> Cleaning $(NAME) object files..."
	@rm -rf $(OBJDIR)
	@make -C ./libft clean

fclean: clean
	@echo "-> Cleaning $(NAME)...\n "
	@rm -rf $(NAME)
	@make -C ./libft fclean

re: fclean all

norm:
	$(NORM)

love: all #credit to notoriousgtw

.PHONY: all clean fclean re
