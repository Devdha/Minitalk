# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 19:42:00 by dha               #+#    #+#              #
#    Updated: 2022/02/22 16:00:48 by dha              ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = CC
#CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
NAME = minitalk
SERVER = server
CLIENT = client

LIBFT_DIR = ./libft
LIBFT_NAME = ft
LIBFT = $(LIBFT_DIR)/lib$(LIBFT_NAME).a

OBJ_DIR = ./obj

SERVER_SRCS = server.c \
				talk_utils.c
SERVER_INCS = minitalk.h
SERVER_OBJS = $(addprefix $(OBJ_DIR)/, $(SERVER_SRCS:.c=.o))

CLIENT_SRCS = client.c \
				talk_utils.c
CLIENT_INCS = minitalk.h
CLIENT_OBJS = $(addprefix $(OBJ_DIR)/, $(CLIENT_SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(SERVER) $(CLIENT)

$(SERVER) : $(LIBFT) $(SERVER_OBJS) $(SERVER_INCS)
	@$(CC) $(CFLAGS) -I ./ $(SERVER_OBJS) -L $(LIBFT_DIR) -l$(LIBFT_NAME) -o $@
	@printf "💡 Make $(SERVER) Done\n"

$(CLIENT) : $(LIBFT) $(CLIENT_OBJS) $(CLIENT_INCS)
	@$(CC) $(CFLAGS) -I ./ $(CLIENT_OBJS) -L $(LIBFT_DIR) -l$(LIBFT_NAME) -o $@
	@printf "💡 Make $(CLIENT) Done\n"

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@ -g

clean :
	@$(RM) $(OBJ_DIR)
	@echo "🗑 Remove $(NAME)'s OBJs Done"

fclean : clean
	@$(RM) $(SERVER)
	@$(RM) $(CLIENT)
	@echo "🗑 Remove $(NAME) Done"

wclean : fclean $(LIBFT_NAME)_fclean

re : fclean all

rr : wclean all

.PHONY : all clean fclean wclean re rr $(LIBFT_NAME)_clean $(LIBFT_NAME)_fclean

$(LIBFT) :
	@make -C $(LIBFT_DIR)

$(LIBFT_NAME)_clean :
	@make -C $(LIBFT_DIR) clean

$(LIBFT_NAME)_fclean :
	@make -C $(LIBFT_DIR) fclean