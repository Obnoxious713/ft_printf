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

NAME =  ft_printf

print = -Wall -Werror -Wextra -g

CC = gcc

NORM = norminette -R CheckForbiddenSourceHeader

SRC = main.c \
		parser.c \
		
OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

LIBFT = ./libft/libft.a
LIBFTINC = -I./libft
LINK_FT = -L./libft -lft

LIBPF = ./libpf/libpf.a
LIBPFINC = -I./libpf/include
LINK_PF = -L./libpf -lpf

SRCDIR = ./src/
INCDIR = ./include/
OBJDIR = ./obj/

all: obj libft libpf $(NAME)

lib: fclean
	@make -C ./libpf fclean
	@make

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(print) $(LIBFTINC) $(LIBPFINC) -I $(INCDIR) -o $@ -c $<

libpf: $(LIBPF)

libft: $(LIBFT)

$(LIBPF):
	@make -C ./libpf

$(LIBFT):
	@make -C ./libft

$(NAME): $(OBJ)
	@echo "-> Compiling $(NAME)..."
	@$(CC) -o $(NAME) $(OBJ) $(LINK_PF) $(LINK_FT)
	@echo "\n   ******* Done *******"

clean:
	@echo "-> Cleaning $(NAME) object files..."
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "-> Cleaning $(NAME)...\n "
	@rm -rf $(NAME)
	@make -C ./libft fclean
	@make -C ./libpf fclean

re: fclean all

norm:
	$(NORM)

love: all #credit to notoriousgtw

.PHONY: all clean fclean re
