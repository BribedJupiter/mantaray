# Makefile Mantary
# Only supports Windows
# Look at old-makefile.mak to see what the more complicated makefile this is based off of is like
# Also NOTE that the lib/*.dll files are not used at all at the moment. (libgxx_s_sw2-1.dll and libstdc++6.dll)

# Define the project name
PROJECT_NAME ?= Mantaray

# Debug mode - TRUE or FALSE
DEBUG = TRUE

# Directories
SRC_DIR := src
OBJ_DIR := obj

# Compiler and flags
CC := g++ # Use the c++ compiler
CFLAGS := -std=c++14 -Wall # Compiler flags

# Library flags
LDFLAGS := -L. 
LDLIBS := -lraylib -lopengl32 -lgdi32 -lwinmm # Libraries we need

# Additional debug flags - need to compile with -g in order to allow breakpoints and other debug functionality
ifeq ($(DEBUG), TRUE)
 DEBUG_FLAGS := -g # Compiler flags
endif

# Source files
# MAIN_SRC --> our main file
# GAME_DIRS --> Any other subdirectory of src that contains relevant cpp files
MAIN_SRC := $(SRC_DIR)/main.cpp
GAME_DIRS := $(wildcard $(SRC_DIR)/*/)

# Object files
MAIN_OBJ := $(OBJ_DIR)/main.o
GAME_OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(wildcard $(SRC_DIR)/*.cpp))

# Automatically detect game source files and generate object file rules
define generate_rules
    GAME_SRC := $(wildcard $(1)*.cpp)
    GAME_OBJS += $$(patsubst $(1)%.cpp,$(OBJ_DIR)/%.o,$$(GAME_SRC))

    $$(OBJ_DIR)/%.o: $(1)%.cpp
	$(CC) -c $$< -o $$@ $(CFLAGS)
endef

# Generate rules for each game directory
$(foreach dir,$(GAME_DIRS),$(eval $(call generate_rules,$(dir))))

# Build target
$(PROJECT_NAME): $(MAIN_OBJ) $(GAME_OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS) ${DEBUG_FLAGS}

# Compile main source file
$(MAIN_OBJ): $(MAIN_SRC)
	$(CC) -c $< -o $@ $(CFLAGS) ${DEBUG_FLAGS}

# Phony targets
.PHONY: all clean

all: $(PROJECT_NAME)

clean:
	rm -f $(PROJECT_NAME) $(MAIN_OBJ) $(GAME_OBJS)
