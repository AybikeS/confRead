Version = 0.1
Prefix = /usr/local
CC = gcc
CFLAGS = -Wall -Wextra -O3 -fPIC
LDFLAGS = -lm

all: confRead.so 

confRead.so: confRead.o
	$(CC) $(CFLAGS) $(LDFLAGS) -shared confRead.o -o libconfRead.so

confRead.o: src/confRead.c src/confRead.h
	$(CC) $(CFLAGS) -c src/confRead.c -o confRead.o


install: uninstall
	cp src/confRead.h $(Prefix)/include

	cp libconfRead.so $(Prefix)/lib/libconfRead.so.$(Version)
	@cd $(Prefix)/lib/ ; ln -s libconfRead.so.$(Version) libconfRead.so

	@rm -f libconfRead.pc
	@echo "Name: libconfRead" >> libconfRead.pc
	@echo "Description: This is a library developed by Narin Yaren Coşkun, Efe Yılmaz, Aybike Sena Şahin and Ali Yiğit Ergen during their internship at Ford Otosan." >> libconfRead.pc
	@echo "Version: $(Version)" >> libconfRead.pc
	@echo "Libs: -L$(Prefix)/lib -lconfRead" >> libconfRead.pc
	@echo "Cflags: -I$(Prefix)/include" >> libconfRead.pc

	cp libconfRead.pc $(Prefix)/lib/pkgconfig


uninstall:
	rm -f $(Prefix)/include/confRead.h
	rm -f $(Prefix)/lib/libconfRead.so*
	rm -f $(Prefix)/lib/pkgconfig/libconfRead.pc

clean:
	rm -f *.o *.out *.so *.pc
