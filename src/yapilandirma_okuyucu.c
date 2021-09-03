#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "yapilandirma_okuyucu.h"

int
dosyayi_oku_ve_icerigini_ekrana_bas(const char* dosya_ismi)
{
	char satir[256];
	FILE *config;

        config = fopen(dosya_ismi, "r");
        if(config != NULL)
	{
                while(fgets(satir, sizeof(satir), config) != NULL)
		{
                        printf("%s(): %s\n", __func__, satir);
                }
        }
        else
	{
                printf("%s(): Config dosyasi acilamadi. \n", __func__);

                return -1;
        }

        fclose(config);

	return 0;
}

static int
dosyadan_degisken_al(char *str, char *ad, char *veri)
{
	char* satir  = strtok(str, "=");

	strcpy(ad, satir);
	printf("Degisken al fonk. %s\n",ad);
	satir = strtok(NULL, "\n");
	strcpy(veri, satir);
	printf("Degisken al fonk. %s\n",veri);
	return 0;

}


int
dosyadaki_verileri_al(const char* dosya_ismi, struct veri_tutucu** dosyadaki_veriler_ptr, int* veri_tutucu_boyutu)
{
	char satir[256];
	FILE *config;
	
	char ad[128];
	char veri[128];

	int veri_indeksi = 0;

        config = fopen(dosya_ismi, "r");
        if(config != NULL)
	{
                while(fgets(satir, sizeof(satir), config) != NULL)
		{
			
			*dosyadaki_veriler_ptr = realloc(*dosyadaki_veriler_ptr, (veri_indeksi+1) * sizeof(struct veri_tutucu));	
			dosyadan_degisken_al(satir, ad, veri);
			
			struct veri_tutucu* ara_degisken_ptr = *dosyadaki_veriler_ptr + veri_indeksi;

			strcpy(ara_degisken_ptr->ad, ad);
			strcpy(ara_degisken_ptr->veri, veri);
			
			veri_indeksi++;	
			printf("%d\n", veri_indeksi);
		}

		*veri_tutucu_boyutu = veri_indeksi;
        }
        
	else
	{
                printf("%s(): Config dosyasi acilamadi. \n", __func__);
                return -1;
        }

        fclose(config);

	return 0;
}

int
veriyi_degere_cevir_int(const char* veri_ismi, const struct veri_tutucu* dosyadaki_veriler_ptr, int veri_tutucu_boyutu) {
	
	for(int i = 0; i < veri_tutucu_boyutu; ++i) {
		if (!strcmp(dosyadaki_veriler_ptr[i].ad, veri_ismi)) {
			return atoi(dosyadaki_veriler_ptr[i].veri);
		}	
	}
	return -1;
}

char*
veriyi_degere_cevir_str(const char* veri_ismi, const struct veri_tutucu* dosyadaki_veriler_ptr, int veri_tutucu_boyutu) {
	
	for(int i = 0; i < veri_tutucu_boyutu; ++i) {
		if (!strcmp(dosyadaki_veriler_ptr[i].ad, veri_ismi)) {
			return (char*)dosyadaki_veriler_ptr[i].veri;
		}	
	}
	return NULL;
}
