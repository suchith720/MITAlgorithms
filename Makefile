CC = g++ -g -std=c++11

OBJDIR = obj
BINDIR = bin
SRCDIR = src
DATDIR = data
TESDIR = test
INCDIR = include
MAKDIR = make

CPPFLAGS = -I./include/
CPPLIBS = -I./lib/

CPP = algorithms.cpp myString.cpp peak.cpp \
      randomProblem.cpp trace.cpp utils.cpp

TEST = main.cpp generate.cpp

TESMAK = $(addprefix $(TESDIR)/, $(TEST:.cpp=.d) )

BIN = $(addprefix $(BINDIR)/, $(TEST:%.cpp=%) )

SCR = $(addprefix $(SRCDIR)/, $(CPP) )

OBJ = $(addprefix $(OBJDIR)/, $(CPP:.cpp=.o) )

MAK = $(addprefix $(MAKDIR)/, $(CPP:.cpp=.d) )

$(MAKDIR)/%.d : $(SRCDIR)/%.cpp $(INCDIR)/%.h
	@set -e; rm -f $@; \
        $(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
        sed 's,\($*\)\.o[ :]*,$(OBJDIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
        rm -f $@.$$$$

$(TESDIR)/%.d : $(TESDIR)/%.cpp
	@set -e; rm -f $@; \
        $(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
        sed 's,\($*\)\.o[ :]*,$(BINDIR)\1 $@ : ,g' < $@.$$$$ > $@; \
	sed -i 's,include/\([[:alpha:]]*\)\.h,$(OBJDIR)/\1\.o,g' $@; \
        rm -f $@.$$$$

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) -c $< $(CPPFLAGS) $(CPPLIBS) -o $@

all : $(BIN)

$(BINDIR)/main : $(TESDIR)/main.d $(TESDIR)/main.cpp $(OBJ)
	$(CC) $(TESDIR)/main.cpp $(OBJ) $(CPPFLAGS) $(CPPLIBS) -o $@

$(BINDIR)/generate : $(TESDIR)/generate.cpp $(OBJDIR)/myString.o $(OBJDIR)/utils.o $(OBJDIR)/randomProblem.o
	$(CC) $^ $(CPPFLAGS) $(CPPLIBS) -o $@

-include $(MAK) $(TESMAK)

$(OBJ) : | $(OBJDIR)

$(OBJDIR) : 
	-mkdir $(OBJDIR)

$(BIN) : | $(BINDIR)

$(BINDIR) :
	-mkdir $(BINDIR)

.PHONY : clean

clean : 
	-rm -f $(OBJDIR)/* $(BINDIR)/*



