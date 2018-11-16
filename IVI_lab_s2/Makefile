DIROBJ := obj/
DIREXE := exec/
DIRHEA := include/
DIRSRC := src/
MKDIR_P := mkdir -p

CC := gcc
CFLAGS := -I$(DIRHEA) -c -Wall -ansi
LDFLAGS := -lglut -lGLU -lGL
LDLIBS := `pkg-config --libs-only-l glu` -lglut

all: dirs helloOpenGL tetera planetario ejercicio1 ejercicio3 ejercicio4 ejercicio5 ejercicio6 ejercicio7 ejercicio8

dirs:
	$(MKDIR_P) $(DIROBJ) $(DIREXE)

helloOpenGL: $(DIROBJ)helloOpenGL.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

tetera: $(DIROBJ)tetera.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

planetario: $(DIROBJ)planetario.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

ejercicio1: $(DIROBJ)ejercicio1.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)
	
ejercicio3: $(DIROBJ)ejercicio3.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

ejercicio4: $(DIROBJ)ejercicio4.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

ejercicio5: $(DIROBJ)ejercicio5.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

ejercicio6: $(DIROBJ)ejercicio6.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

ejercicio7: $(DIROBJ)ejercicio7.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

ejercicio8: $(DIROBJ)ejercicio8.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)	

$(DIROBJ)%.o: $(DIRSRC)%.c
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	$(RM) -rf *~ core $(DIROBJ) $(DIREXE) $(DIRHEA)*~ $(DIRSRC)*~
