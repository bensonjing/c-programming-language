debug ?= 1
NAME := linsorting
SRC_DIR := src
BUILD_DIR := build
TEST_DIR := test
BIN_DIR := bin

CC = gcc
CFLAGS = -Wall -Wextra -pedantic
LDFLAGS = -lm

ifeq ($(debug), 1) 
	CFLAGS := $(CFLAGS) -g -O0 
else 
	CFLAGS := $(CFLAGS) -g -Oz 
endif

OBJS := $(patsubst %.c, %.o, $(wildcard $(SRC_DIR)/*.c))
TEST_SRC_FILE := $(filter-out $(SRC_DIR)/main.c, $(wildcard $(SRC_DIR)/*.c))

$(NAME): dir ${OBJS} 
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $(BIN_DIR)/$@ $(patsubst %, build/%, $(OBJS)) 
	@$(BIN_DIR)/$(NAME)

$(OBJS): dir 
	@mkdir -p $(BUILD_DIR)/$(@D)
	@$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ -c $*.c

test: dir $(OBJS)
	@$(CC) $(CFLAGS) -o $(BIN_DIR)/$(NAME)_test $(TEST_DIR)/*.c $(TEST_SRC_FILE)
	@$(BIN_DIR)/$(NAME)_test

dir: 
	@mkdir -p $(BUILD_DIR) $(BIN_DIR) 

clean: 
	@rm -rf $(BUILD_DIR) $(BIN_DIR) 

.PHONY: dir clean
