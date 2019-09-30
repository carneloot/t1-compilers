# ------------------------------------------------
# Generic Makefile
#
# Author: yanick.rochon@gmail.com
# Date  : 2011-08-10
#
# Changelog :
#   2010-11-05 - first version
#   2011-08-10 - added structure : sources, objects, binaries
#                thanks to http://stackoverflow.com/users/128940/beta
#   2017-04-24 - changed order of linker params
# ------------------------------------------------

# project name (generate executable with this name)
TARGET = regalloc


# Diretorios de cada coisa
SRCDIR = src
OBJDIR = build
BINDIR = bin
INCDIR = include

# Debug mode: Coloque o valor para 1 para habilitar o modo debug
DEBUG = 1

# Flags do professor...?
PFLAGS = -std=c++11

CC     = g++
CFLAGS = -lm -I $(INCDIR) $(PFLAGS)

LINKER = g++
LFLAGS = -I $(INCDIR) -lm

# Extensão do arquivo
EXT = cpp

ifeq ($(DEBUG), 1)
	CFLAGS += -g -Wall -D DEBUG
	LFLAGS += -g -Wall
endif

SOURCES  := $(shell find $(SRCDIR) -type f -name "*.$(EXT)" | sort -k 1nr | cut -f2-)
INCLUDES := $(shell find $(INCDIR) -type f -name "*.h*")
OBJECTS  := $(SOURCES:$(SRCDIR)/%.$(EXT)=$(OBJDIR)/%.o)
rm       = rm -rf

test:
	@echo $(SOURCES)
	@echo $(INCLUDES)
	@echo $(OBJECTS)

$(BINDIR)/$(TARGET): $(OBJECTS) $(INCLUDES)
	@mkdir -p $(dir $@)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled \"$<\" successfully!"

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"

remake: remove $(BINDIR)/$(TARGET)
	@echo "Remaked!"
