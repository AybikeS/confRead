#ifndef YAPILANDIRMA_OKUYUCU_H
#define YAPILANDIRMA_OKUYUCU_H

struct veri_tutucu
{
	char ad[128];
	char veri[128];
};

int dosyayi_oku_ve_icerigini_ekrana_bas(const char* dosya_ismi);

int dosyadaki_verileri_al(const char* dosya_ismi, struct veri_tutucu** dosyadaki_veriler_ptr, int* veri_tutucu_boyutu);

int veriyi_degere_cevir_int(const char* veri_ismi, const struct veri_tutucu* dosyadaki_veriler_ptr, int veri_tutucu_boyutu);

char* veriyi_degere_cevir_str(const char* veri_ismi, const struct veri_tutucu* dosyadaki_veriler_ptr, int veri_tutucu_boyutu);

#endif
