#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "yapilandirma_okuyucu.h"

int
main(int argc, char **argv)
{
	int debug;
	char* IP;
	char* sifre;
        struct veri_tutucu* dosyadaki_veriler_ptr = NULL;
	int veri_tutucu_boyutu = 0;

	dosyadaki_verileri_al(argv[1], &dosyadaki_veriler_ptr, &veri_tutucu_boyutu);

	debug = veriyi_degere_cevir_int("debug", dosyadaki_veriler_ptr, veri_tutucu_boyutu);
	IP = veriyi_degere_cevir_str("IP", dosyadaki_veriler_ptr, veri_tutucu_boyutu);
	sifre = veriyi_degere_cevir_str("sifre", dosyadaki_veriler_ptr, veri_tutucu_boyutu);

	printf("Debug: [%d], Sifre: [%s], IP:[%s]\n", debug, sifre, IP);

	free(dosyadaki_veriler_ptr);

	return 0;
}
