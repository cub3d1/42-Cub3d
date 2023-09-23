COLOR_OFF = \e[0;0;0m

BY_FB = \e[1;90;103m
BG_FW = \e[1;97;42m
BR_FW = \e[1;97;101m

MDIR = src/mandatory/
BDIR = src/bonus/
ADIR = src/additional/
GNLDIR = src/get_next_line/

MSRCFILES = ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c

BSRCFILES = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

ASRCFILES = ft_btox.c \
			ft_print_memory.c \
			ft_uitoa.c \
			ft_abs.c \
			ft_min_i.c \
			ft_max_i.c \
			ft_str_is_int.c \
			ft_free_split.c \
			ft_strreplace.c

GNLSRCFILES = get_next_line.c \
			get_next_line_utils.c


MSRCS = $(addprefix $(MDIR),$(MSRCFILES))
BSRCS = $(addprefix $(BDIR),$(BSRCFILES))
ASRCS = $(addprefix $(ADIR),$(ASRCFILES))
GNLSRCS = $(addprefix $(GNLDIR),$(GNLSRCFILES))


MOBJS = ft_atoi.o \
	        ft_bzero.o \
	        ft_calloc.o \
	        ft_isalnum.o \
	        ft_isalpha.o \
	        ft_isascii.o \
	        ft_isdigit.o \
	        ft_isprint.o \
	        ft_itoa.o \
	        ft_memchr.o \
	        ft_memcmp.o \
	        ft_memcpy.o \
	        ft_memmove.o \
	        ft_memset.o \
	        ft_putchar_fd.o \
	        ft_putendl_fd.o \
	        ft_putnbr_fd.o \
	        ft_putstr_fd.o \
	        ft_split.o \
	        ft_strchr.o \
	        ft_strdup.o \
	        ft_striteri.o \
	        ft_strjoin.o \
	        ft_strlcat.o \
	        ft_strlcpy.o \
	        ft_strlen.o \
	        ft_strmapi.o \
	        ft_strncmp.o \
	        ft_strnstr.o \
	        ft_strrchr.o \
	        ft_strtrim.o \
	        ft_substr.o \
	        ft_tolower.o \
	        ft_toupper.o

BOBJS = ft_lstnew.o \
			ft_lstadd_front.o \
			ft_lstsize.o \
			ft_lstlast.o \
			ft_lstadd_back.o \
			ft_lstdelone.o \
			ft_lstclear.o \
			ft_lstiter.o \
			ft_lstmap.o

AOBJS = ft_btox.o \
			ft_print_memory.o \
			ft_uitoa.o \
			ft_abs.o \
			ft_min_i.o \
			ft_max_i.o \
			ft_str_is_int.o \
			ft_free_split.o \
			ft_strreplace.o

GNLOBJS = get_next_line.o \
			get_next_line_utils.o

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -c


all: $(NAME)
	@echo -e "\n$(BG_FW)libft compiled.$(COLOR_OFF)"


$(NAME): $(MOBJS) $(BOBJS) $(AOBJS) $(GNLOBJS)
	@echo -e "\n$(BY_FB)Linking object files...$(COLOR_OFF)\n"
	ar rcs $(NAME) $(MOBJS) $(BOBJS) $(AOBJS) $(GNLOBJS)
	@echo -e "\n$(BG_FW)Object files successfully linked.$(COLOR_OFF)\n"


$(MOBJS): $(MSRCS)
	@echo -e "\n$(BY_FB)Compiling mandatory source files...$(COLOR_OFF)\n"
	$(CC) $(CFLAGS) $(MSRCS)
	@echo -e "\n$(BG_FW)Mandatory source files successfully compiled.$(COLOR_OFF)\n"


$(BOBJS): $(BSRCS)
	@echo -e "\n$(BY_FB)Compiling bonus source files...$(COLOR_OFF)\n"
	$(CC) $(CFLAGS) $(BSRCS)
	@echo -e "\n$(BG_FW)Bonus source files successfully compiled.$(COLOR_OFF)\n"


$(AOBJS): $(ASRCS)
	@echo -e "\n$(BY_FB)Compiling additional source files...$(COLOR_OFF)\n"
	$(CC) $(CFLAGS) $(ASRCS)
	@echo -e "\n$(BG_FW)Additional source files successfully compiled.$(COLOR_OFF)\n"


$(GNLOBJS): $(GNLSRCS)
	@echo -e "\n$(BY_FB)Compiling nget_next_line source files...$(COLOR_OFF)\n"
	$(CC) $(CFLAGS) $(GNLSRCS)
	@echo -e "\n$(BG_FW)get_next_line source files successfully compiled.$(COLOR_OFF)\n"


clean:
	@echo -e "\n$(BR_FW)Removing object files...$(COLOR_OFF)\n"
	rm -f $(MOBJS) $(BOBJS) $(AOBJS) $(GNLOBJS)
	@echo -e "\n$(BG_FW)Object files removed.$(COLOR_OFF)\n"


fclean: clean
	@echo -e "\n$(BR_FW)Removing archive file...$(COLOR_OFF)\n"
	rm -f $(NAME)
	@echo -e "\n$(BG_FW)Archive file removed.$(COLOR_OFF)\n"


re: fclean all


.PHONY: clean fclean all re

