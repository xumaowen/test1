SHELL = /bin/bash

AllDirs := $(shell ls -R | grep '^\./.*:$$' | awk '{gsub(":","");print}') .  
SourcesCXX := $(foreach n,$(AllDirs) , $(wildcard $(n)/*.cpp))
SourcesCC := $(foreach n,$(AllDirs) , $(wildcard $(n)/*.c))
ObjsCXX := $(patsubst %.cpp,%.o, $(SourcesCXX))
ObjsCC := $(patsubst %.c,%.o, $(SourcesCC))

# 需要删除的依赖文件
DEL_1 := $(patsubst %.c,%.d, $(SourcesCC))
DEL_2 := $(patsubst %.cpp,%.d, $(SourcesCXX))

Bin := qtsys 
LIBSX86 = 
LIBSARM = 

CCARM = /usr/local/arm/4.4.6/bin/arm-linux-gcc 
CXXARM = /usr/local/arm/4.4.6/bin/arm-linux-g++
CCX86 = gcc 
CXXX86 = g++

# 编译方式  make PP=X86   make PP=ARM   make 
PP = X86 

AllQtsys : $(Bin)
ifeq ($(PP), ARM)
LIBS = $(LIBSARM)
CC = $(CCARM)
CXX = $(CXXARM)
else
LIBS = $(LIBSX86)
CC = $(CCX86)
CXX = $(CXXX86)
endif

RM = rm -f
#CXXFLAGS = -g -O2 -fPIC -Wall
CXXFLAGS = -g -Wall -DNO_QT_MODE
CPPFLAGS = $(foreach n,$(AllDirs) , -I$(n))  
LDFLAGS = -lstdc++

SVNDEF := -D'SVN_REV="$(shell svnversion -n . ./)"'
TIMDEF := -D'COMPILE_TIME="$(shell date +"%Y-%m-%d %H:%M:%S")"'
CXXFLAGS += $(SVNDEF) $(TIMDEF)
CPPFLAGS += $(SVNDEF) $(TIMDEF)

$(Bin) : $(ObjsCXX) $(ObjsCC)  
	$(CXX) $(ObjsCXX) $(ObjsCC) -o $@ $(LIBS)

%.d : %.cpp %.c  
	$(CXX) -MT"$(<:.cpp=.o) -MT"$(<:.c=.o) $@" -MM $(CXXFLAGS) $(CPPFLAGS) $< > $@ $(LIBS)

clean:   
	$(RM) $(ObjsCXX) $(ObjsCC) $(Bin) $(DEL_1) $(DEL_2)

.PHONY : clean
