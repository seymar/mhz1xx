CC := gcc
LD := gcc

linkables := \
	build/mhz1xx_packet.o \
	build/mhz1xx.o \
	build/test.o \

CPPUTEST_HOME ?= /Users/seymar/dev/checkouts/cpputest
CPPFLAGS += -I$(CPPUTEST_HOME)/include
CXXFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorNewMacros.h
CFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorMallocMacros.h
LD_LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt
LDFLAGS += $(LD_LIBRARIES)

build/test.out: $(linkables)
	$(LD) $(LDFLAGS) $^ -o $@

build/%.o:
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $<

build/mhz1xx_packet.o: ../mhz1xx_packet.c
build/mhz1xx.o: ../mhz1xx.c
build/test.o: test.cpp

clean:
	rm -f build/*
run:
	./build/test.out