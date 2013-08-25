# BEGIN CONFIG
TARGET=libartemis.a

SRCDIR=src
OBJDIR=obj
LIBDIR=lib
INCDIR=include

INSTALL_PREFIX=/usr/local
INSTALL_INCDIR=include/Artemis
INSTALL_LIBDIR=lib
# END CONFIG

CXXFLAGS:=-I./$(INCDIR)

SOURCES=$(wildcard $(SRCDIR)/*.cpp)
HEADERS=$(wildcard include/*.h)
OBJS=$(subst $(SRCDIR),$(OBJDIR),$(subst .cpp,.o,$(SOURCES)))

OUTPUT=$(LIBDIR)/$(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OUTPUT): $(OBJDIR) $(OBJS)
	ar rcs $(OUTPUT) $(OBJS)

$(OBJDIR):
	mkdir $(OBJDIR)

all: $(TARGET)

.PHONY: clean install uninstall

clean:
	rm -r $(OBJDIR)
	rm $(OUTPUT)

install:
	cp $(OUTPUT) $(INSTALL_PREFIX)/$(INSTALL_LIBDIR)/$(TARGET)
	mkdir -p $(INSTALL_PREFIX)/$(INSTALL_INCDIR)
	cp $(INCDIR)/*.h $(INSTALL_PREFIX)/$(INSTALL_INCDIR)

uninstall:
	rm $(INSTALL_PREFIX)/$(INSTALL_LIBDIR)/$(TARGET)
	rm -r $(INSTALL_PREFIX)/$(INSTALL_INCDIR)
