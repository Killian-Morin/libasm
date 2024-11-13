NAME = libasm.a

NASM = nasm
NASM_FLAGS =

SRC_PATH = ./srcs/
SRC_FILES = ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_strdup.s \
			ft_write.s \
			ft_read.s \

# Source and object files
OBJ_PATH = ./objs/
OBJ_FILES = ${patsubst ${SRC_PATH}/%.s, ${OBJ_PATH}/%.o, ${SRC_FILES}}

all: ${NAME}

# Create the library from object files
${NAME}: ${OBJ_FILES}
	@ar rc ${NAME}

# Compile assembly files to object files
${OBJ_PATH}/%.o: ${SRC_PATH}/%.s | ${OBJ_PATH}
	${NASM} ${NASM_FLAGS} -o $@ $<

# Ensure ./objs/ exists
${OBJ_PATH}:-o
	mkdir -p ${OBJ_PATH}

# Compile test.c and link it with the library
test: all
	@gcc -Wall -Werror -Wextra test.c ${NAME}

# Clean ./objs that holds object files
clean:
	@rm -rf ${OBJ_PATH}

# Remove the library and the file from test.c
fclean: clean
	@rm -f ${NAME}
	@rm -f test.o
	@rm -f ./a.out

# Rebuild everything
re: fclean all

.PHONE: all clean fclean re
