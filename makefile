CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = app.bin

SRCDIR = src
BUILDDIR = build
TARGETDIR = bin

SRCEXT = cpp
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
DEPS = $(OBJECTS:.o=.d)

# Regra principal: compilar, executar e limpar
all: $(TARGET)
	@echo "Executando o programa..."
	$(TARGETDIR)/$(TARGET)
	@echo "Limpando arquivos compilados..."
	$(MAKE) clean

# Regra para compilar o programa
$(TARGET): $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	$(CXX) $(CXXFLAGS) -o $(TARGETDIR)/$(TARGET) $^

# Regra para compilar os objetos
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)  # Garante que os diretórios de destino existem
	$(CXX) $(CXXFLAGS) -MMD -c -o $@ $<

# Limpeza dos arquivos compilados
clean:
	@rm -rf $(BUILDDIR) $(TARGETDIR)

# Inclui arquivos de dependência
-include $(DEPS)

.PHONY: clean all
