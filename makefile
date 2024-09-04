CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = knowledge_agent_system

SRCDIR = src
BUILDDIR = build
TARGETDIR = bin

SRCEXT = cpp
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
DEPS = $(OBJECTS:.o=.d)

# Regra principal
$(TARGET): $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	$(CXX) $(CXXFLAGS) -o $(TARGETDIR)/$(TARGET) $^

# Regra para compilar os objetos
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)  # Garante que os diretórios de destino existem
	$(CXX) $(CXXFLAGS) -MMD -c -o $@ $<

# Limpeza
clean:
	@rm -rf $(BUILDDIR) $(TARGETDIR)

# Inclui arquivos de dependência
-include $(DEPS)

.PHONY: clean
