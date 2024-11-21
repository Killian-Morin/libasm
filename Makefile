NAME = libasm.a

NASM = nasm
NASM_FLAGS = -f elf64

SRC_PATH = ./srcs/
SRC_FILES = ft_strlen.s \
			ft_strcmp.s \
			ft_strcpy.s \
			ft_write.s \
			ft_read.s \
			ft_strdup.s \

SRC = ${addprefix ${SRC_PATH}, ${SRC_FILES}}

# Source and object files
OBJ_PATH = ./objs/
OBJ_FILES = ${SRC_FILES:.s=.o}
OBJ = ${addprefix ${OBJ_PATH}, ${OBJ_FILES}}

all: ${OBJ} ${NAME}

# Ensure ./objs/ exists
${OBJ_PATH}:
	mkdir -p ${OBJ_PATH}

# Compile assembly files to object files
${OBJ_PATH}%.o: ${SRC_PATH}%.s | ${OBJ_PATH}
	${NASM} ${NASM_FLAGS} -o $@ $<

# Create the library from object files
${NAME}:
	@ar rc ${NAME} ${OBJ}

# Compile test.c and link it with the library
test: all
	@gcc -Wall -Werror -Wextra -o test test.c -L. -lasm
	@echo "Linked test file with the library"

# Clean ./objs that holds object files
clean:
	@rm -rf ${OBJ_PATH}

# Remove the library, test executable and files
fclean: clean
	@rm -f ${NAME}
	@rm -f ./test
	@rm -f *.txt

# Rebuild everything
re: fclean all

.PHONE: all clean fclean re test
