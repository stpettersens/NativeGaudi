CC= g++
SOURCES= src/NativeGaudiBase.cpp src/NativeGaudiApp.cpp src/NativeGaudiForeman.cpp src/NativeGaudiBuilder.cpp src/NativeGaudiHabitat.cpp src/NativeGaudiCommands.cpp 
TARGET= bin/ngaudi.exe
LFLAGS= -o
INCLUDES= -IC:/Dev/Boost
PLATFORM=$(shell uname -s)

ifeq ($(PLATFORM), Linux)
	TARGET = bin/ngaudi
	INCLUDES= -I/usr/include/boost
endif

make:
	$(CC) $(SOURCES) $(LFLAGS) $(TARGET) $(INCLUDES)
	strip $(TARGET)
clean:
	rm -f $(TARGET)
