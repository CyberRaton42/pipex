SRCS = srcs/pipex.c \
		srcs/mem.c \
		srcs/errors.c \
		srcs/cmdexec.c \
		utils/ft_putstr_fd.c \
		utils/ft_split.c \
		utils/ft_strdup.c \
		utils/ft_strjoin.c \
		utils/ft_strlen.c \
		utils/ft_strnstr.c \

SRCSBONUS = bonus/pipex_bonus.c \
				bonus/mem_bonus.c \
				bonus/errors_bonus.c \
				bonus/cmdexec_bonus.c \
				bonus/here_doc_bonus.c \
				utils/ft_putstr_fd.c \
				utils/ft_split.c \
				utils/ft_strdup.c \
				utils/ft_strjoin.c \
				utils/ft_strlen.c \
				utils/ft_strnstr.c \

CFLAGS = -Wall -Wextra -Werror

OBJ = ${SRCS:.c=.o}

OBJBONUS = ${SRCSBONUS:.c=.o}

NAME = pipex

BONUSNAME = pipex_bonus

CC = gcc

all: ${NAME}

nb:=1

n:=0

a:=0

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 2>>error.log
	$(eval n=$(shell echo $$(($(nb)/15 * 35))))
	$(eval a=$(shell echo $$((202 - $(n)))))
	@if [ ${nb} = "1" ]; then\
		printf "\033[1;0f\033[?25l~~~~~~~~~~PIPEX COMPILATION~~~~~~~~~~\033[J";\
	fi 2> error.log
	@printf "\033[0;38;5;%dm" "${a}"
	@echo -n "\033[2;0fCompilation de l'objet" ${nb} "terminee\033[0m\n"
	$(eval nb=$(shell echo $$(($(nb)+1))))

${NAME}: rm_log ${OBJ}
	@${CC} ${OBJ} ${CFLAGS} -o ${NAME} 2>>error.log
	@echo "\033[1;92m\033[6;0fpipex pret!\033[0m\033[?25h"
	@cat error.log 2>/dev/null

bonus: rm_log ${OBJBONUS}
	@${CC} ${OBJBONUS} ${CFLAGS} -o ${BONUSNAME} 2>>error.log
	@echo "\033[1;92m\033[6;0fpipex pret!\033[0m\033[?25h"
	@cat error.log 2>/dev/null

clean:
	@rm -f ${OBJ} ${OBJBONUS}
	@echo "clean ok!"

fclean:
	@rm -f ${OBJ} ${OBJBONUS} ${NAME} ${BONUSNAME}
	@echo "fclean ok!"

re: fclean all

error:
	@printf "\033[0;0H\033[1;31m\033[JAn error as occured:\033[J\033[0m\n"
	@cat error.log 2>/dev/null
	@echo "\033[?25h"

rm_log:
	@rm -rf error.log

.PHONY: all clean fclean re error rm_log