# -Chicken-Farm-Management-Simulator-
SAKARYA ÜNİVERSİTESİ
BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
PROGRAMLAMAYA GİRİŞİ DERSİ

ÖDEV NUMARASI…: 2.ödev
ÖĞRENCİ ADI: Abdulhadi krımesh
ÖĞRENCİ NUMARASI.: G231210577
DERS GRUBU…:2.A
Tavuk Çiftliği Simülasyonu Raporu
Bu C++ programı, kullanıcıdan aldığı başlangıç bilgilerine göre bir tavuk çiftliği simülasyonu yapar. Programın işleyişi ve gerçekleştirdiği işlemler aşağıdaki gibidir:
Başlangıçta Kullanıcıdan Alınan Bilgiler:
•	Başlangıç sermayesi
•	Çiftlikteki tavuk sayısı (en fazla 500)
•	Tavuk yeminin kilogram fiyatı
•	Yumurtanın satış fiyatı
•	Tavuk alım fiyatı
•	Simülasyon yapılacak gün sayısı
Programın İşleyişi:
1.	Kurucu Fonksiyon (Ciftlik Sınıfı):
o	Kullanıcıdan alınan bilgiler doğrultusunda başlangıç sermayesinden tavuk alım giderleri ve 700 kilogram yem gideri düşülerek çiftlik kurulumu yapılır.
o	Tavuklar, Tavuk sınıfının nesneleri olarak dizi şeklinde saklanır.
2.	Günlük İşlemler:
o	Yem Tüketimi: Her tavuk, günlük rastgele olarak 100 ile 120 gram arasında yem tüketir.
o	Yumurta Üretimi: Her tavuk, günlük rastgele olarak 0, 1 veya 2 yumurta yumurtlar. Ancak çiftliğe yeni gelen tavuklar ilk 3 gün yumurtlamaz.
o	Kesim: Üst üste 3 gün yumurtlamayan veya toplamda 100 yumurta üreten tavuklar kesime gönderilir ve yerlerine yeni tavuklar alınır.
o	Gelir ve Gider: Günlük toplanan yumurtaların satışı ve kesime gönderilen tavukların yerine yenilerinin alınması ile çiftliğin günlük gelir ve giderleri hesaplanır.
o	Yem Stoku Kontrolü: Yem miktarı 70 kilogramın altına düştüğünde, 700 kilogram yem satın alınır ve sermayeden düşülür.
3.	Simülasyon Sonuçları:
o	Gün sonunda kalan para 0'ın altına düştüğünde, "İflas ettiniz..." mesajı gösterilir ve simülasyon sonlandırılır.
o	Simülasyon tamamlandığında, günlük yem tüketimi, yumurta sayısı, kesilen tavuk sayısı, günlük gelir ve gider, kalan yem ve kalan para bilgileri tablo halinde raporlanır.
