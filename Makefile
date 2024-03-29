# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dieggonz <dieggonz@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 16:22:18 by dieggonz          #+#    #+#              #
#    Updated: 2024/02/20 16:22:31 by dieggonz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# <-- Library's Name --> #
NAME = libft.a

# <-- Compilation Command --> #
CC = gcc

# <-- Compilation Flags --> #
CFLAGS = -Wall -Werror -Wextra

# <-- Remove Command -->#
RM = rm -f

# <-- AR --> #
AR = ar -rcs

# <-- Files --> #
SRC_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_strtrim.c ft_split.c ft_itoa.c

# <-- Objects --> #
OBJS = $(SRC_FILES:.c=.o)

# <-- Main Target --> #
all: $(NAME)

# <--Library Creation--> #
$(NAME): $(OBJS)
	$(AR) $@ $(OBJS)

# <-- Objects Creation --> #
%.o: %.c  libft.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

# <-- Objects Destruction --> #
clean:
	$(RM) $(OBJS)

# <-- Clean Execution + libft.a Destruction --> #
fclean: clean
	$(RM) $(NAME)

# <-- Fclean Execution -->
re: fclean all

# <-- Targets Declaration --> #
.PHONY : all clean fclean re
