# OS properties

# directory for source code ,customized library and built objects.
IDIR=./include
LDIR=./library
ODIR=./object

# library installed in OS
LIBS=

# compiler
CC=gcc
AR=ar
CFLAGS=

## Add directory $(IDIR) to include search path
ifneq ($(strip $(IDIR)),)
CFLAGS=-I$(IDIR)
endif

# Dependencies, $(IDIR) should contains all the files.
_DEPS_LIST=checksum.h encrypt.h
DEPS_LIST=$(patsubst %, $(IDIR)/%, $(_DEPS_LIST))

# all needed object files
_OBJ_LIST_OTHERS=encrypt.o checksum.o
_OBJ_LIST_MAIN=main.o
OBJ_LIST_OTHERS=$(patsubst %, $(ODIR)/%, $(_OBJ_LIST_OTHERS))
OBJ_LIST_MAIN=$(patsubst %, $(ODIR)/%, $(_OBJ_LIST_MAIN))
OBJ_LIST=$(OBJ_LIST_OTHERS)
OBJ_LIST+= $(OBJ_LIST_MAIN)

# other contants
this_file_name=Makefile
executable_main_name=main
_customized_lib_name=others
customized_lib_fullname=$(LDIR)/$(strip $(patsubst %, lib%.a, $(_customized_lib_name))) 

# build all object files.
$(OBJ_LIST): $(ODIR)/%.o: %.c $(DEPS_LIST)
	@mkdir -p $(ODIR)
	$(CC) -c -o  $@ $< $(CFLAGS)

# archive customized library
$(customized_lib_fullname): $(OBJ_LIST_OTHERS)
	$(AR) -rcs $@ $^

# build executable program.
$(executable_main_name): $(OBJ_LIST_MAIN) $(customized_lib_fullname)
	$(CC) -o $@ $< $(CFLAGS) -L$(LDIR) -l$(_customized_lib_name) 


.PHONY: build
build:
	mkdir -p $(LDIR) $(ODIR)
	$(MAKE) -f $(this_file_name) main

run:
	./main

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o
	rm -f ./*.o
	rm -f $(LDIR)/*
	rm ./main
