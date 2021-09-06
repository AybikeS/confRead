Version = 0.1
Prefix = /usr/local
CC = gcc
CFLAGS = -Wall -Wextra -O3 -fPIC
LDFLAGS = -lm

all: yapilandirma_okuyucu.so test.out

yapilandirma_okuyucu.so: yapilandirma_okuyucu.o
	$(CC) $(CFLAGS) $(LDFLAGS) -shared yapilandirma_okuyucu.o -o libyapilandirma_okuyucu.so

yapilandirma_okuyucu.o: src/yapilandirma_okuyucu.c src/yapilandirma_okuyucu.h
	$(CC) $(CFLAGS) -c src/yapilandirma_okuyucu.c -o yapilandirma_okuyucu.o


test.out: test.o
	$(CC) $(CFLAGS) test.o libyapilandirma_okuyucu.so -o test.out

test.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o test.o


install: uninstall
	cp src/yapilandirma_okuyucu.h $(Prefix)/include

	cp libyapilandirma_okuyucu.so $(Prefix)/lib/libyapilandirma_okuyucu.so.$(Version)
	@cd $(Prefix)/lib/ ; ln -s libyapilandirma_okuyucu.so.$(Version) libyapilandirma_okuyucu.so

	@rm -f libyapilandirma_okuyucu.pc
	@echo "Name: libyapilandirma_okuyucu" >> libyapilandirma_okuyucu.pc
	@echo "Description: stj2021" >> libyapilandirma_okuyucu.pc
	@echo "Version: $(Version)" >> libyapilandirma_okuyucu.pc
	@echo "Libs: -L$(Prefix)/lib -lyapilandirma_okuyucu" >> libyapilandirma_okuyucu.pc
	@echo "Cflags: -I$(Prefix)/include" >> libyapilandirma_okuyucu.pc

	cp libyapilandirma_okuyucu.pc $(Prefix)/lib/pkgconfig


uninstall:
	rm -f $(Prefix)/include/yapilandirma_okuyucu.h
	rm -f $(Prefix)/lib/libyapilandirma_okuyucu.so*
	rm -f $(Prefix)/lib/pkgconfig/libyapilandirma_okuyucu.pc

clean:
	rm -f *.o *.out *.so *.pc
