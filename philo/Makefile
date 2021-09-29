CC	=				gcc
CFLAGS =			-Wall -Werror -Wextra
RM =				rm -rf

NAME =				philo
INCLUDE =			include

SRCS_DIR = 			srcs
OBJS_DIR =			objs

SRCS =				$(wildcard $(SRCS_DIR)/*.c)
OBJS =				$(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

$(NAME):			CFLAGS:= $(CFLAGS) -D BONUS=0
bonus:				CFLAGS:= $(CFLAGS) -D BONUS=1

all:				$(NAME)

$(NAME):			$(OBJS)
						@$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) -I $(INCLUDE) $(LIBS) $(OBJS)
						@echo "$(NAME) mandatory successfully compiled!"

bonus:				$(OBJS)
						@$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) -I $(INCLUDE) $(LIBS) $(OBJS)
						@echo "$(NAME) bonus successfully compiled!"

$(OBJS_DIR)/%.o:	%.c
						@mkdir -p $(dir $@)
						@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
						@$(RM) $(OBJS_DIR)
						@echo "Successfuly cleaned all object files of $(NAME)!"

fclean:				clean
						@$(RM) $(NAME)
						@echo "Successfuly cleaned all executable files of $(NAME)!"

re:					fclean	all

rebonus:			fclean	bonus

.PHONY:				all	clean	fclean	re
