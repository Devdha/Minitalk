# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 20:59:53 by dha               #+#    #+#              #
#    Updated: 2022/02/22 15:49:18 by dha              ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/bash
SP = -\|
IDX = 0

SRCS = ft_isascii.c ft_putchar_fd.c ft_strchr.c ft_strlen.c ft_substr.c ft_atoi.c \
	ft_isdigit.c ft_memchr.c ft_strdup.c ft_strmapi.c ft_tolower.c ft_bzero.c ft_isprint.c \
	ft_memcmp.c ft_putendl_fd.c  ft_striteri.c ft_strncmp.c ft_toupper.c ft_calloc.c \
	ft_itoa.c ft_memcpy.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c ft_isalnum.c ft_memmove.c \
	ft_putstr_fd.c ft_strlcat.c ft_strrchr.c ft_isalpha.c ft_memset.c ft_split.c \
	ft_strlcpy.c ft_strtrim.c get_next_line.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	ft_lstdel_back.c ft_lstdel_front.c ft_lst_beforelast.c ft_atol.c ft_numlen.c ft_isnum.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $@ $^
	@printf "\b✅ \n💡 Make $(NAME) Done\n"

%.o : %.c
	$(eval IDX = $(shell expr $(IDX) + 1))
	$(eval T_IDX = $(shell expr $(IDX) % 2 + 1))
	$(eval CHR = $(shell echo -n $(SP) | cut -c $(T_IDX)))
	@if [ $(IDX) = 1 ]; then echo -n "🛠 Compiling ...  "; fi
	@printf "\b$(CHR)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJS)
	@echo "🗑 Remove $(NAME)'s OBJs Done"

fclean : clean
	@$(RM) $(NAME)
	@echo "🗑 Remove $(NAME) Done"

$(OBJS) : $(SRCS) libft.h

re : fclean all

.PHONY : clean fclean re all