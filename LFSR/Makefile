CC := gcc -m32# This is the main compiler
# CC := clang --analyze # and comment out the linker last line for sanity
SRCDIR := src
BUILDDIR := build
TARGET := bin/main

SRCEXT := c
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -F stabs
LIB := -lm
INC := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo "$(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ build/lfsr_nasm.o -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	nasm -f elf32 assembly/lfsr_nasm.asm -o build/lfsr_nasm.o
	@echo "$(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<


clean:
	@echo "Cleaning...";
	@echo "$(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean
