CC= g++
SOURCES= src/NativeGaudiBase.cpp src/NativeGaudiApp.cpp src/NativeGaudiForeman.cpp src/NativeGaudiBuilder.cpp src/NativeGaudiHabitat.cpp src/NativeGaudiCommands.cpp 
TARGET= bin/ngaudi.exe
LFLAGS= -o
INCLUDES= -IC:/Dev/boost_1_55_0
BOOST_REGEX= libboost_regex.a
PLATFORM=$(shell uname -s)

#ifeq ($(PLATFORM), Linux)
	#TARGET = bin/ngaudi
	#INCLUDES= -I/usr/include/boost
#endif

make:
	$(CC) $(SOURCES) $(BOOST_REGEX) $(LFLAGS) $(TARGET) $(INCLUDES)
	strip $(TARGET)
clean:
	rm -f $(TARGET)
