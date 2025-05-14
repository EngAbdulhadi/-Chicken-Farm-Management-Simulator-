/****************************************************************************
**				       	            SAKARYA ÜNİVERSİTESİ
**			                BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				                    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				                      PROGRAMLAMAYA GİRİŞİ DERSİ
**
**			                       	ÖDEV NUMARASI…: 2.ödev
**			                  	ÖĞRENCİ ADI:Abdulhadi krımesh
**			                  	ÖĞRENCİ NUMARASI.:G231210577
**			                       	DERS GRUBU…:2.A
****************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <locale.h>

using namespace std;

class Tavuk {
private:
    int yas; // Tavuğun yaşı (gün olarak)
    int toplamYumurta; // Toplam yumurta sayısı
    int ustUsteYumurtlamamaGunu; // Üst üste yumurtlamama gün sayısı
    int geldigiGun; // Çiftliğe geliş günü

public:
    Tavuk(int gun)
        : yas(0), toplamYumurta(0), ustUsteYumurtlamamaGunu(0), geldigiGun(gun) {}

    void yumurtla(int gun) {
        if (gun - geldigiGun >= 3) {
            int yumurta = rand() % 3; // 0, 1 veya 2 yumurta
            toplamYumurta += yumurta;
            if (yumurta == 0) {
                ustUsteYumurtlamamaGunu++;
            }
            else {
                ustUsteYumurtlamamaGunu = 0;
            }
        }
        yas++;
    }

    double yemYe() {
        return 100 + rand() % 21; // 100 ile 120 gram arası yem tüketimi
    }

    bool kesimlikMi() const {
        return ustUsteYumurtlamamaGunu >= 3 || toplamYumurta >= 100;
    }

    void yeniTavuk(int gun) {
        yas = 0;
        toplamYumurta = 0;
        ustUsteYumurtlamamaGunu = 0;
        geldigiGun = gun;
    }

    int getToplamYumurta() const {
        return toplamYumurta;
    }
};

class Ciftlik {
private:
    double baslangicSermayesi;
    int tavukSayisi;
    double yemKgFiyati;
    double yumurtaSatisFiyati;
    double tavukAlisFiyati;
    double kalanPara;
    double yemMiktari;
    Tavuk** tavuklar;

public:
    Ciftlik(double sermaye, int tavukSayi, double yemFiyati, double yumurtaFiyati, double tavukFiyati)
        : baslangicSermayesi(sermaye), tavukSayisi(tavukSayi), yemKgFiyati(yemFiyati), yumurtaSatisFiyati(yumurtaFiyati),
        tavukAlisFiyati(tavukFiyati), kalanPara(sermaye), yemMiktari(700) {
        tavuklar = new Tavuk * [tavukSayi];
        for (int i = 0; i < tavukSayi; ++i) {
            tavuklar[i] = new Tavuk(0);
            kalanPara -= tavukAlisFiyati;
        }
        kalanPara -= yemMiktari * yemKgFiyati;
    }

    ~Ciftlik() {
        for (int i = 0; i < tavukSayisi; ++i) {
            delete tavuklar[i];
        }
        delete[] tavuklar;
    }

    void simulasyonYap(int gunSayisi) {
        cout << fixed << setprecision(2);
        cout << "Gün\tYem Tüketimi (kg)\tYumurta\tKesilen Tavuk\tGünlük Gelir (TL)\tGünlük Gider (TL)\tKalan Yem (kg)\tKalan Para (TL)\n";
        cout << "--------------------------------------------------------------------------------------------------------------\n";

        for (int gun = 1; gun <= gunSayisi; ++gun) {
            int toplamYumurta = 0;
            double gunlukYemTuketimi = 0;
            int kesilenTavuk = 0;
            double gunlukGelir = 0;
            double gunlukGider = 0;

            for (int i = 0; i < tavukSayisi; ++i) {
                gunlukYemTuketimi += tavuklar[i]->yemYe() / 1000.0; // Kilogram olarak
                tavuklar[i]->yumurtla(gun);
                toplamYumurta += tavuklar[i]->getToplamYumurta();

                if (tavuklar[i]->kesimlikMi()) {
                    kalanPara += tavukAlisFiyati / 2; // Kesim geliri
                    gunlukGelir += tavukAlisFiyati / 2;
                    delete tavuklar[i];
                    tavuklar[i] = new Tavuk(gun);
                    kalanPara -= tavukAlisFiyati;
                    gunlukGider += tavukAlisFiyati;
                    kesilenTavuk++;
                }
            }

            yemMiktari -= gunlukYemTuketimi;
            if (yemMiktari < 0) {
                cout << "Yeterli yem yok, iflas ettiniz..." << endl;
                return;
            }

            double yumurtaGeliri = toplamYumurta * yumurtaSatisFiyati;
            kalanPara += yumurtaGeliri;
            gunlukGelir += yumurtaGeliri;

            if (yemMiktari < 70) {
                yemMiktari += 700;
                kalanPara -= 700 * yemKgFiyati;
                gunlukGider += 700 * yemKgFiyati;
                if (kalanPara < 0) {
                    cout << "Yeterli sermayeniz yok, iflas ettiniz..." << endl;
                    return;
                }
            }

            cout << gun << "\t" << gunlukYemTuketimi << "\t\t" << toplamYumurta << "\t" << kesilenTavuk << "\t\t"
                << gunlukGelir << "\t\t" << gunlukGider << "\t\t" << yemMiktari << "\t\t" << kalanPara << "\n";

            // Kalan para kontrolü: 0'ın altına düşerse iflas
            if (kalanPara < 0) {
                cout << "İflas ettiniz..." << endl;
                return;
            }
        }

        cout << "Simülasyon başarıyla tamamlandı!" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Turkish"); // Türkçe karakter desteğini ayarla
    srand(static_cast<unsigned>(time(0)));

    double baslangicSermayesi;
    int tavukSayisi;
    double yemKgFiyati;
    double yumurtaSatisFiyati;
    double tavukAlisFiyati;
    int gunSayisi;

    cout << "Başlangıç sermayesini giriniz: ";
    cin >> baslangicSermayesi;

    cout << "Çiftlikte kaç tavuk olacak (en fazla 500): ";
    cin >> tavukSayisi;
    if (tavukSayisi > 500) {
        cout << "Maksimum tavuk sayısı 500 olabilir." << endl;
        return 1;
    }

    cout << "Tavuk yeminin kilogram fiyatını giriniz: ";
    cin >> yemKgFiyati;

    cout << "Yumurtanın satış fiyatını giriniz: ";
    cin >> yumurtaSatisFiyati;

    cout << "Tavuk alım fiyatını giriniz: ";
    cin >> tavukAlisFiyati;

    cout << "Simülasyon yapılacak gün sayısını giriniz: ";
    cin >> gunSayisi;

    Ciftlik ciftlik(baslangicSermayesi, tavukSayisi, yemKgFiyati, yumurtaSatisFiyati, tavukAlisFiyati);
    ciftlik.simulasyonYap(gunSayisi);

    return 0;
}
