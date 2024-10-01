NAME		:=	cpplibft.a

CC			:=	c++
CXXFLAGS	:=	-Wall -Werror -Wextra
CXXFLAGS	+=	-g
# CXXFLAGS	+=	-Wno-unused-variable -Wno-unused-parameter -Wno-unused-function
ifdef SAN
CXXFLAGS	+=	-fsanitize=address -g -D SAN=1
endif

SRC_DIR		:=	srcs
SRCS		:=	$(shell find ${SRC_DIR} -name "*.cpp") $(shell find ${SRC_DIR} -name "*.cpp")

INCLUDE		:=	include
HEADER		:=	$(shell find ${INCLUDE} -name "*.hpp")
CFLAGS		:=	-I${INCLUDE}

OBJ_DIR		:=	objs
OBJS 		:=	$(patsubst ${SRC_DIR}%.cpp, ${OBJ_DIR}%.o, ${SRCS})

GREY		:=	\033[30m
RED			:=	\033[31m
CYAN		:=	\033[36m
LIGHT_CYAN	:=	\033[1;36m
RESET		:=	\033[0m

all: ${NAME}

${OBJ_DIR}:
	@command="mkdir $@" \
	&& printf "${GREY}$$command${RESET}\n" \
	&& $$command

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp ${HEADER} | ${OBJ_DIR}
	@mkdir -p ${@D}
	@command="${CC} ${CXXFLAGS} ${CFLAGS} -c $< -o $@" \
	&& printf "${CYAN}$$command${RESET}\n" \
	&& $$command

${NAME}: ${OBJS} ${LIBFT}
	@${AR} -rcs $@ $^ \
	&& printf "${LIGHT_CYAN}Library Made: $@${RESET}\n"

clean:
	@command="${RM} -r ${OBJ_DIR} $$(find . -name "*.dSYM")" \
	&& printf "${RED}$$command${RESET}\n" \
	&& $$command

fclean: clean
	@command="${RM} ${NAME}" \
	&& printf "${RED}$$command${RESET}\n" \
	&& $$command

re:	fclean all

.PHONY: test pft
