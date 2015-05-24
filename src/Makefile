
NAME=hydrogen

#######################################################
###################   DIRECTORIES   ###################
#######################################################
BANG-DIR=~/neo-human/programs/vanity-fair
PROG-DIR=$(BANG-DIR)/hydrogen
#UTILS-DIR=$(PROG-DIR)/utils
#MATLABROOT=`sh getMatlabRootDir.sh`

#######################################################
###################       SRC       ###################
#######################################################
#SRC=descriptors descriptor folders interest_regions interest_region parameters component components descfile
SRC=graph
SRC-CC=$(foreach src,$(SRC), $(src).cc)
SRC-HH =$(foreach src,$(SRC-CC),$(src:.cc=.hh))
SRC-OBJ=$(foreach src,$(SRC-CC),$(src:.cc=.o))
SRC-OBJ-DOT=$(foreach obj,$(SRC-OBJ),.$(obj))

#######################################################
###################    UTILITIES    ###################
#######################################################
#UTILS_GEN=$(UTILS-DIR)/gfaGenUtils.cpp
#UTILS_CV=$(UTILS-DIR)/cvutilities.cpp
#UTILS-CPP=$(UTILS_GEN) $(UTILS_CV)
#UTILS-HH=$(foreach src,$(UTILS-CPP),$(src:.cpp=.hh))
#UTILS-OBJ=$(foreach util,$(UTILS-CPP),$(notdir $(util:.cpp=.o)))
#UTILS-OBJ-DOT=$(foreach obj,$(UTILS-OBJ),.$(obj))

#######################################################
###################   OBJECT FILES  ###################
#######################################################
#OBJS=eval_helper_2.o $(SRC-OBJ) $(UTILS-OBJ)
#OBJS-DOT:= $(foreach obj,$(OBJS),.$(obj))

#######################################################
###################      FLAGS      ###################
#######################################################
#IPATH=-Iutils `pkg-config opencv --cflags` -I /usr/include/boost
#LPATH=-lboost_system -lboost_filesystem `pkg-config opencv --libs`

CFLAGS=-Wall
IPATH=-I/usr/local/include `pkg-config --cflags eigen3`
LPATH=-L/usr/local/lib
LLIBS=-lgsl -lgslcblas -lm
CC=clang++

# # archiving shit
# COMP=tar --create --xz --file
# DATE = `date +%F.%H%M`

#######################################################
###################  COMPILE,BUILD  ###################
#######################################################
COMPILE=-c $(IPATH)
COMPILE_FILE = $(CC) $(COMPILE) $(basename $(1)).cc -o .$(basename $(notdir $(1))).o
BUILD=$(CC) $(LPATH) $(LLIBS) -o $(NAME)

all: $(NAME)

mem: test
	valgrind --leak-check=full ./$(NAME)

$(NAME): $(SRC-OBJ-DOT)
	$(BUILD) 

tags: $(SRC-CPP) $(SRC-HH)
	find . -type f -regex ".*\.\(cc\|hh\)" | xargs etags -a

test: .test.o $(SRC-OBJ-DOT)
	$(CC) $(LPATH) $(LLIBS) $(SRC-OBJ-DOT) .test.o -o test

.test.o: test.cc
	$(call COMPILE_FILE,$<)

init:

.graph.o: graph.cc graph.hh
	$(call COMPILE_FILE,$<)

# playground: playground.cpp
# 	$(CPP) playground.cpp $(IPATH) $(LPATH) -o playground

# .eval_helper_2.o: eval_helper_2.cpp $(SRC-OBJS-DOT) $(UTILS-OBJS-DOT)
# 	$(call COMPILE_FILE,$<)

# .$(NAME).o: $(NAME).cc $(NAME).hh
# 	$(call COMPILE_FILE,$<)

# .parameters.o: parameters.cpp parameters.hh
# 	$(call COMPILE_FILE,$<)

# .descriptor.o: descriptor.cpp descriptor.hh
# 	$(call COMPILE_FILE,$<)

# .descriptors.o: descriptors.cpp descriptors.hh
# 	$(call COMPILE_FILE,$<)

# .folders.o: folders.cpp folders.hh
# 	$(call COMPILE_FILE,$<)

# .interest_region.o: interest_region.cpp interest_region.hh
# 	$(call COMPILE_FILE,$<)

# .interest_regions.o: interest_regions.cpp interest_regions.hh
# 	$(call COMPILE_FILE,$<)

# .components.o: components.cpp components.hh
# 	$(call COMPILE_FILE,$<)

# .component.o: component.cpp component.hh
# 	$(call COMPILE_FILE,$<)

# .descfile.o: descfile.cpp descfile.hh
# 	$(call COMPILE_FILE,$<)

# .$(notdir $(UTILS_GEN:.cpp=.o)): $(UTILS_GEN) $(UTILS_GEN:.cpp=.hh)
# 	$(call COMPILE_FILE,$<)

# .$(notdir $(UTILS_CV:.cpp=.o)): $(UTILS_CV) $(UTILS_CV:.cpp=.hh)
# 	$(call COMPILE_FILE,$<)


clean:
#	@echo $(DOT_OBJS)
	rm -rf $(NAME) $(SRC-OBJ-DOT) .test.o *log*

# comp: clean
# 	$(COMP) $(ARCH-DIR)/$(NAME).`date +%F.%H%M`.tar.xz ../$(NAME)/ $(UTILS-DIR)



