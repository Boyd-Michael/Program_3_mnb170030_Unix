# Makefile
# March 1 2020
# Michael Boyd
# mnb270030@utdallas.edu
# CS 3377.501 Spring 2020
# Version 1.0
# Copyright 2020, All Rights Reserved
#
# A file to make the program
#

CXX = g++
CPPFLAGS =
CXXFLAGS = -Werror
LDFLAGS =
SRCS = HW3.cc
OBJS = $(SRCS:.cc=.o)
PROJECTNAME = HomeWork3
EXEC = prog3

.PHONEY:all clean

%o:%cc
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) -O$<-o$@

all: $(EXEC)

clean:
	rm -f $(OBJS) *.d *~ $(EXEC)

#%d:%.cc
#	@echo Updating .d Dependency File
#	@set -e rm -f $@; \
#	$(CXX) -MM $(CPPFLAGS) $< > $@.$$$$; \
#	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
#	rm -f $@.$$$$

$(EXEC):$(OBJS)
	$(CXX) -o $(EXEC) $(LDFLAGS) $(OBJS)

#Makefile:$(SRCS:.cc=.d)

backup: clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := $(shell basename 'pwd'))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H:%M:%S').tar.gz
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME) ../$(CURDIRNAME)
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!


-include $(SRCS:.cc=.d)

