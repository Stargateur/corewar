##
## Makefile for Makefile in /home/plasko_a/rendu/CPE_2014_corewar
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.net>
## 
## Started on  Tue Mar 25 13:37:17 2014 Antoine Plaskowski
## Last update Tue May  6 22:43:15 2014 Antoine Plaskowski
##

CC			?=	gcc

DEBUG			?=	0

RM			=	rm -f

ECHO			=	/bin/echo

MKDIR			=	mkdir -p

RMDIR			=	rmdir

CFLAGS			+=	-Wall -Wextra -O3
CFLAGS			+=	-ansi -pedantic
CFLAGS			+=	-I include

ifeq ($(DEBUG), 1)
CFLAGS			+=	-g
LDFLAGS			+=	 -l efence
endif

LDFLAGS			+=	-l X11

ASM			=	asm

DE_ASM			=	de_asm

COREWAR			=	corewar

SRC			+=	src/my_putchar.c
SRC			+=	src/my_strlen.c
SRC			+=	src/my_strcmp.c
SRC			+=	src/my_strncmp.c
SRC			+=	src/my_strcpy.c
SRC			+=	src/my_strncpy.c
SRC			+=	src/my_strdup.c
SRC			+=	src/my_strndup.c
SRC			+=	src/my_putstr.c
SRC			+=	src/my_putnbr.c
SRC			+=	src/my_putnbr_base.c
SRC			+=	src/my_getnbr.c
SRC			+=	src/my_malloc.c
SRC			+=	src/my_char_in_str.c
SRC			+=	src/my_epur_str.c
SRC			+=	src/my_str.c
SRC			+=	src/my_put_error.c

SRC			+=	src/my_open.c
SRC			+=	src/my_rev_oct.c
SRC			+=	src/my_put_oct.c
SRC			+=	src/my_put_oct_modulo.c
SRC			+=	src/my_read_oct.c
SRC			+=	src/my_read_oct_modulo.c
SRC			+=	src/my_write_oct.c
SRC			+=	src/my_get_next_line.c
SRC			+=	src/my_tool_tab.c

SRC			+=	src/op.c


SRC_ASM			+=	src_asm/main.c
SRC_ASM			+=	src_asm/my_ins.c
SRC_ASM			+=	src_asm/my_create_cor.c
SRC_ASM			+=	src_asm/my_write_header.c
SRC_ASM			+=	src_asm/my_write_ins.c
SRC_ASM			+=	src_asm/my_read_file.c
SRC_ASM			+=	src_asm/my_search_label.c
SRC_ASM			+=	src_asm/my_parse_arg.c
SRC_ASM			+=	src_asm/my_parse_line.c
SRC_ASM			+=	src_asm/my_parse_registre.c
SRC_ASM			+=	src_asm/my_parse_direct.c
SRC_ASM			+=	src_asm/my_parse_indirect.c
SRC_ASM			+=	src_asm/my_parse_label.c
SRC_ASM			+=	src_asm/my_sup_comment.c
SRC_ASM			+=	src_asm/my_set_size_ins.c
SRC_ASM			+=	src_asm/my_check_same_label.c

SRC_ASM			+=	src_asm/size_ins/my_set_octect_codage.c
SRC_ASM			+=	src_asm/size_ins/my_size_normal.c
SRC_ASM			+=	src_asm/size_ins/my_size_special.c
SRC_ASM			+=	src_asm/size_ins/my_size_special_no_codage.c
SRC_ASM			+=	src_asm/size_ins/my_size_no_codage.c

SRC_ASM			+=	src_asm/write_ins/my_write_registre.c
SRC_ASM			+=	src_asm/write_ins/my_write_direct.c
SRC_ASM			+=	src_asm/write_ins/my_write_indirect.c
SRC_ASM			+=	src_asm/write_ins/my_write_label.c
SRC_ASM			+=	src_asm/write_ins/my_write_normal.c
SRC_ASM			+=	src_asm/write_ins/my_write_special.c
SRC_ASM			+=	src_asm/write_ins/my_write_no_codage.c
SRC_ASM			+=	src_asm/write_ins/my_write_special_no_codage.c


SRC_DE_ASM		+=	src_de_asm/main.c
SRC_DE_ASM		+=	src_de_asm/my_create_s.c
SRC_DE_ASM		+=	src_de_asm/my_read_champion.c
SRC_DE_ASM		+=	src_de_asm/my_write_header.c
SRC_DE_ASM		+=	src_de_asm/my_write_ins.c

SRC_DE_ASM		+=	src_de_asm/write_ins/my_check_octect_codage.c
SRC_DE_ASM		+=	src_de_asm/write_ins/my_write_registre.c
SRC_DE_ASM		+=	src_de_asm/write_ins/my_write_direct.c
SRC_DE_ASM		+=	src_de_asm/write_ins/my_write_indirect.c
SRC_DE_ASM		+=	src_de_asm/write_ins/my_write_normal.c
SRC_DE_ASM		+=	src_de_asm/write_ins/my_write_special.c
SRC_DE_ASM		+=	src_de_asm/write_ins/my_write_3.c
SRC_DE_ASM		+=	src_de_asm/write_ins/my_write_5.c


SRC_COREWAR		+=	src_corewar/main.c

SRC_COREWAR		+=	src_corewar/my_core/my_core.c
SRC_COREWAR		+=	src_corewar/my_core/my_do_one_cycle.c
SRC_COREWAR		+=	src_corewar/my_core/my_dump_memory.c
SRC_COREWAR		+=	src_corewar/my_core/my_give_type_codage.c
SRC_COREWAR		+=	src_corewar/my_core/my_parse_arg.c
SRC_COREWAR		+=	src_corewar/my_core/my_parse_arg_special.c
SRC_COREWAR		+=	src_corewar/my_core/my_load_in_mem.c
SRC_COREWAR		+=	src_corewar/my_core/my_value_if_reg.c

SRC_COREWAR		+=	src_corewar/my_core/my_ins/my_live.c
SRC_COREWAR		+=	src_corewar/my_core/my_ins/my_ld.c
SRC_COREWAR		+=	src_corewar/my_core/my_ins/my_st.c
SRC_COREWAR		+=	src_corewar/my_core/my_ins/my_add.c
SRC_COREWAR		+=	src_corewar/my_core/my_ins/my_sub.c
SRC_COREWAR		+=	src_corewar/my_core/my_ins/my_and.c
SRC_COREWAR		+=	src_corewar/my_core/my_ins/my_or.c
SRC_COREWAR		+=	src_corewar/my_core/my_ins/my_xor.c
SRC_COREWAR		+=	src_corewar/my_core/my_ins/my_zjmp.c
SRC_COREWAR		+=	src_corewar/my_core/my_ins/my_ldi.c
SRC_COREWAR		+=	src_corewar/my_core/my_ins/my_sti.c
SRC_COREWAR		+=	src_corewar/my_core/my_ins/my_fork.c
SRC_COREWAR		+=	src_corewar/my_core/my_ins/my_lld.c
SRC_COREWAR		+=	src_corewar/my_core/my_ins/my_lldi.c
SRC_COREWAR		+=	src_corewar/my_core/my_ins/my_lfork.c
SRC_COREWAR		+=	src_corewar/my_core/my_ins/my_aff.c


SRC_COREWAR		+=	src_corewar/my_prepare_corewar/my_create_champ.c
SRC_COREWAR		+=	src_corewar/my_prepare_corewar/my_create_proc.c
SRC_COREWAR		+=	src_corewar/my_prepare_corewar/my_define_id_champ.c
SRC_COREWAR		+=	src_corewar/my_prepare_corewar/my_dump_option.c
SRC_COREWAR		+=	src_corewar/my_prepare_corewar/my_prepare_vm.c
SRC_COREWAR		+=	src_corewar/my_prepare_corewar/my_read_header.c
SRC_COREWAR		+=	src_corewar/my_prepare_corewar/my_size_total_champ.c
SRC_COREWAR		+=	src_corewar/my_prepare_corewar/my_spread_champ.c

SRC_COREWAR		+=	src_corewar/my_champ/my_free_champ.c
SRC_COREWAR		+=	src_corewar/my_champ/my_new_champ.c
SRC_COREWAR		+=	src_corewar/my_champ/my_put_champ.c
SRC_COREWAR		+=	src_corewar/my_champ/my_tool_champ.c

SRC_COREWAR		+=	src_corewar/my_proc/my_cpy_proc.c
SRC_COREWAR		+=	src_corewar/my_proc/my_free_proc.c
SRC_COREWAR		+=	src_corewar/my_proc/my_new_proc.c
SRC_COREWAR		+=	src_corewar/my_proc/my_put_proc.c
SRC_COREWAR		+=	src_corewar/my_proc/my_sup_proc.c
SRC_COREWAR		+=	src_corewar/my_proc/my_tool_proc.c

SRC_COREWAR		+=	src_corewar/my_x/my_x.c
SRC_COREWAR		+=	src_corewar/my_x/my_event_expose.c

OBJ			=	$(SRC:.c=.o)

OBJ_ASM			+=	$(OBJ)
OBJ_ASM			+=	$(SRC_ASM:.c=.o)

OBJ_DE_ASM		+=	$(OBJ)
OBJ_DE_ASM		+=	$(SRC_DE_ASM:.c=.o)

OBJ_COREWAR		+=	$(OBJ)
OBJ_COREWAR		+=	$(SRC_COREWAR:.c=.o)

CODE_ASM		=	$(SRC:.c=.s)

CODE_ASM_ASM		+=	$(CODE_ASM)
CODE_ASM_ASM		+=	$(SRC_ASM:.c=.s)

CODE_ASM_DE_ASM		+=	$(CODE_ASM)
CODE_ASM_DE_ASM		+=	$(SRC_DE_ASM:.c=.s)

CODE_ASM_COREWAR	+=	$(CODE_ASM)
CODE_ASM_COREWAR	+=	$(SRC_COREWAR:.c=.s)

all			:	$(ASM)/$(ASM) $(DE_ASM)/$(DE_ASM) $(COREWAR)/$(COREWAR)

$(ASM)/$(ASM)		:	$(OBJ_ASM)
				@$(ECHO) -ne "\e[36m"
				$(MKDIR) $(ASM)
				@$(ECHO) -ne "\e[34m"
				$(CC) $(OBJ_ASM) -o $(ASM)/$(ASM) $(LDFLAGS)
				@$(ECHO) -ne "\e[31m"
				@$(ECHO) "SUCCESS ASM"
				@$(ECHO) -ne "\e[0m"

$(DE_ASM)/$(DE_ASM)	:	$(OBJ_DE_ASM)
				@$(ECHO) -ne "\e[36m"
				$(MKDIR) $(DE_ASM)
				@$(ECHO) -ne "\e[34m"
				$(CC) $(OBJ_DE_ASM) -o $(DE_ASM)/$(DE_ASM) $(LDFLAGS)
				@$(ECHO) -ne "\e[31m"
				@$(ECHO) "SUCCESS DE_ASM"
				@$(ECHO) -ne "\e[0m"

$(COREWAR)/$(COREWAR)	:	$(OBJ_COREWAR)
				@$(ECHO) -ne "\e[36m"
				$(MKDIR) $(COREWAR)
				@$(ECHO) -ne "\e[34m"
				$(CC) $(OBJ_COREWAR) -o $(COREWAR)/$(COREWAR) $(LDFLAGS)
				@$(ECHO) -ne "\e[31m"
				@$(ECHO) "SUCCESS COREWAR"
				@$(ECHO) -ne "\e[0m"

code_asm		:	$(CODE_ASM_ASM) $(CODE_ASM_DE_ASM) $(CODE_ASM_COREWAR)

$(ASM)			:	$(ASM)/$(ASM)

$(DE_ASM)		:	$(DE_ASM)/$(DE_ASM)

$(COREWAR)		:	$(COREWAR)/$(COREWAR)

clean			:
				@$(ECHO) -ne "\e[33m"
				$(RM) $(OBJ) $(OBJ_ASM) $(OBJ_DE_ASM) $(OBJ_COREWAR) $(CODE_ASM_ASM) $(CODE_ASM_DE_ASM) $(CODE_ASM_COREWAR)
				@$(ECHO) -ne "\e[0m"

fclean			:	clean
				@$(ECHO) -ne "\e[35m"
				$(RM) $(ASM)/$(ASM) $(DE_ASM)/$(DE_ASM) $(COREWAR)/$(COREWAR)
				@$(ECHO) -ne "\e[32m"
				-$(RMDIR) $(ASM) $(DE_ASM) $(COREWAR)
				@$(ECHO) -ne "\e[0m"

re			:	fclean all

%.o			:	%.c
				@$(ECHO) -ne "\e[37m"
				$(CC) -c $(CFLAGS) $< -o $@
				@$(ECHO) -ne "\e[0m"

%.s			:	%.c
				@$(ECHO) -ne "\e[37m"
				$(CC) -S $(CFLAGS) $< -o $@
				@$(ECHO) -ne "\e[0m"

.PHONY			:	all clean fclean re %.o %.s

.SUFFIXES		:	.o.c .s.c
