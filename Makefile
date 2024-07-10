# If you move this project you can change the directory
# to match your GBDK root directory (ex: GBDK_HOME = "C:/GBDK/"
ifndef GBDK_HOME
	GBDK_HOME = ../../../
endif

LCC = $(GBDK_HOME)bin/lcc -Wa-l -Wl-m -Wl-j

BINS = lifecounter.gb

# GBDK_DEBUG = ON
ifdef GBDK_DEBUG
	LCCFLAGS += -debug -v
endif

all: $(BINS)

# Compile the sprite.c file to an object file
sprite.o: sprite.c
	$(LCC) -c sprite.c

# Compile the main lifecounter.c file to an object file
lifecounter.o: lifecounter.c
	$(LCC) -c lifecounter.c

# Link the object files to create the final .gb file
lifecounter.gb: lifecounter.o sprite.o
	$(LCC) -o lifecounter.gb lifecounter.o sprite.o

compile.bat: Makefile
	@echo "REM Automatically generated from Makefile" > compile.bat
	@make -sn | sed y/\\//\\\\/ | sed s/mkdir\ -p\/mkdir\/ | grep -v make >> compile.bat

clean:
	rm -f *.o *.lst *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm *.noi *.rst *.sav