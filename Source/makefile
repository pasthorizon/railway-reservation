# ***** Author: Seemant Achari
# ***** Roll No. 19CS10055
# ***** Date: 07-Mar-2021
# ***** Version: 1.0
# ***** Known bugs: None

BUILD_DIR ?= ./.out

CXX := g++
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' ! -name '_*.cpp')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

application: Application
	./Application  

Application: $(OBJS) _Application.cpp Statics.h makefile
	$(CXX) $(OBJS) _Application.cpp -o $@  

unit-test: UnitTestApplication
	./UnitTestApplication 

UnitTestApplication: $(OBJS) _UnitTesting.cpp _UnitTestFunctions.cpp Statics.h makefile
	$(CXX) $(OBJS) _UnitTesting.cpp _UnitTestFunctions.cpp -o $@

myapplication: MyApplication
	./MyApplication 

MyApplication: $(OBJS) _MyApplication.cpp Statics.h makefile
	$(CXX) $(OBJS) _MyApplication.cpp -o $@ 	

$(BUILD_DIR)/%.cpp.o: %.cpp %.h
	$(MKDIR_P) $(dir $@)
	$(CXX) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)
	rm Application
	rm UnitTestApplication
	rm MyApplication

MKDIR_P ?= mkdir -p