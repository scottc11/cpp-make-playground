TARGET = nanoleaf-challenge

CXX = g++

FILE_PATH ?= ./lb-challenge.inputs

BUILD_DIR = ./build
SOURCE_DIR = ./src

all: build run

run:
	${BUILD_DIR}/${TARGET} ${FILE_PATH}

build: clean
	mkdir -p $(BUILD_DIR)
	${CXX} -Wall -v $(wildcard ${SOURCE_DIR}/*.cpp) -o ${BUILD_DIR}/${TARGET}

clean:
	rm -r $(BUILD_DIR)