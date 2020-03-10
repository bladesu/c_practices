# directory for source code ,customized library and built objects.
IDIR=./include
LDIR_STATIC=./library/static/
LDIR_DYNAMIC=./library/dynamic/
ODIR=./object

# OS properties
TOEXPORT=
ifeq ($(OS),Windows_NT)
    TOEXPORT ?= PATH="$$PATH:/$LDIR_DYNAMIC"
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        TOEXPORT ?= LD_LIBRARY_PATH="$$LD_LIBRARY_PATH:/$LDIR_DYNAMIC"
    endif
endif


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
executable_static_link_program=static_main
executable_dynamic_link_program=dynamic_main
_customized_lib_name=others
customized_slib_fullname=$(LDIR_STATIC)/$(strip $(patsubst %, lib%.a, $(_customized_lib_name))) 
customized_dlib_fullname=$(LDIR_DYNAMIC)/$(strip $(patsubst %, lib%.so, $(_customized_lib_name))) 

# build all object files.
$(OBJ_LIST): $(ODIR)/%.o: %.c $(DEPS_LIST)
	@mkdir -p $(ODIR)
	$(CC) -fPIC -c -o  $@ $< $(CFLAGS)

# archive customized static link library
$(customized_slib_fullname): $(OBJ_LIST_OTHERS)
	@mkdir -p $(LDIR_STATIC)
	$(AR) -rcs $@ $^

# archive customized static link library
$(customized_dlib_fullname): $(OBJ_LIST_OTHERS)
	@mkdir -p $(LDIR_DYNAMIC)
	$(CC) -shared -o $@ $^

# build executable program witch static link
$(executable_static_link_program): $(OBJ_LIST_MAIN) $(customized_slib_fullname)
	$(CC) -o $@ $< $(CFLAGS) -L$(LDIR_STATIC) -l$(_customized_lib_name) 

# build executable program witch static link
$(executable_dynamic_link_program): $(OBJ_LIST_MAIN) $(customized_dlib_fullname)
	$(CC) -o $@ $< $(CFLAGS) -L$(LDIR_DYNAMIC) -l$(_customized_lib_name)

.PHONY: build_static
build_static:
	mkdir -p $(LDIR_STATIC) $(ODIR)
	$(MAKE) -f $(this_file_name) $(executable_static_link_program)

.PHONY: build_dynamic
build_dynamic:
	@mkdir -p $(LDIR_DYNAMIC) $(ODIR)
	export $(TOEXPORT)
	$(MAKE) -f $(this_file_name) $(executable_dynamic_link_program)

.PHONY: build
build:
	$(MAKE) build_static
	$(MAKE) build_dynamic

.PHONY: run_static_exec
run_static_exec: $(executable_static_link_program)
	./$(executable_static_link_program)

.PHONY: run_dynamic_exec
run_dynamic_exec: $(executable_dynamic_link_program) $(customized_dlib_fullname)
	./$(executable_dynamic_link_program)
.PHONY: clean
clean:
	rm -f $(ODIR)/*.o
	rm -f ./*.o
	rm -f $(LDIR_STATIC)/*
	rm -f $(LDIR_DYNAMIC)/*
	rm -f ./$(executable_static_link_program) 
	rm -f ./$(executable_dynamic_link_program) 
