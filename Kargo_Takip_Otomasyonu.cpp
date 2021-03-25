
#include <iostream>//cin,cout komutlarýnýn tanýmlý olduðu kütüphane
#include <locale.h>//Türkçe karakter kullanmak için gerekli kütüphane
#include <string>//string tanýmlý deðiþkenler için gerekli kütüphane
#include <fstream>//Dosyalama iþlemleri için gerekli kütüphane
using namespace std;//isim uzayý

void Menu();//Aþaðýda yazdýðým Menu fonksiyonunun çalýþmasý için yukarýda tanýmladým

//Kargo bilgisi deðiþkenlerinin oludðu class 
class Kargo {
public:
	string fatura_no;//Kayýt bulma,yazma,güncelleme,görüntüleme için baz aldýðým temel deðiþken bunu kullanarak iþlemleri gerçekleþtireceðiz
	string gonderen_ad;
	string gonderen_soyad;
	string alici_ad;
	string alici_soyad;
	string gonderen_adres;
	string alici_adres;
	string gonderen_tel;
	string alici_tel;
	string gonderen_bayi;
	string alici_bayi;
	string gonderen_tarih;
	string teslimat_tarih;
	string kargo_adet;
	string kargo_kg;
	string kargo_cins;
	string kargo_bedel;

	//Dosyalam iþlemleri fonksiyonlarý
	void KargoYaz();
	void KargoOku();
	void KargoGuncelle();
	void KargoSil();

}k;

//Kargo durumu deðiþkenlerinin olduðu class
class KargoNerede {
public:
	string nerede;
	string teslim;

	//Dosyalama iþlemleri fonksiyonlarý
	void KargoNeredeYaz();
	void KargoNeredeOku();
	void KargoNeredeGuncelle();

}kn;

//Kargo bilgisi kayýt girme fonksiyonu
void Kargo::KargoYaz() {

	ofstream yaz("Kargo.txt", ios::app);//Kayýt dosyasýný Kargo.txt adýnda oluþturacak komut
	cout << "-----------------------------------------------------------" << endl;
	cout << "Fatura No.........:";
	cin >> k.fatura_no;
	cout << "Gönderen Ad.......:";
	cin >> k.gonderen_ad;
	cout << "Gönderen Soyad....:";
	cin >> k.gonderen_soyad;
	cout << "Alýcý Ad..........:";
	cin >> k.alici_ad;
	cout << "Alýcý Soyad.......:";
	cin >> k.alici_soyad;
	cout << "Gönderen Adres....:";
	cin >> k.gonderen_adres;
	cout << "Alýcý Adres.......:";
	cin >> k.alici_adres;
	cout << "Gönderen Telefon..:";
	cin >> k.gonderen_tel;
	cout << "Alýcý Telefon.....:";
	cin >> k.alici_tel;
	cout << "Gönderen Bayi.....:";
	cin >> k.gonderen_bayi;
	cout << "Alýcý Bayi........:";
	cin >> k.alici_bayi;
	cout << "Gönderme Tarihi...:";
	cin >> k.gonderen_tarih;
	cout << "Teslimat Tarihi...:";
	cin >> k.teslimat_tarih;
	cout << "Kargo Adet........:";
	cin >> k.kargo_adet;
	cout << "Kargo Aðýrlýðý(KG):";
	cin >> k.kargo_kg;
	cout << "Kargo Cinsi.......:";
	cin >> k.kargo_cins;
	cout << "Kargo Bedeli......:";
	cin >> k.kargo_bedel;
	yaz << k.fatura_no << " " << k.gonderen_ad << " " << k.gonderen_soyad << " " << k.alici_ad << " " << k.alici_soyad << " " << k.gonderen_adres << " " << k.alici_adres << " " << k.gonderen_tel << " " << k.alici_tel << " " << k.gonderen_bayi << " " << k.alici_bayi << " " << k.gonderen_tarih << " " << k.teslimat_tarih << " " << k.kargo_adet << " " << k.kargo_kg << " " << k.kargo_cins << " " << k.kargo_bedel << endl;//Girdiðim verileri Kargo.txt dosyasýna yazdýrdýðým komut
	yaz.close();//Kayýt yapýlan dosyayý kapatan komut
	kn.KargoNeredeYaz();//Burada kargo durumu gireceðimiz fonksiyona devam ediyoruz ikisi bir birine baðlantýlý olduðu için farklý zamanda yazmak hata yaratabilir

}

//Kargo bilgisi kayýtý okuma fonksiyonu
void Kargo::KargoOku() {
	int kontrol = 0;//Girilen fatura numarasýnýn eþitliðini kontrol eden deðiþken ve ilk deðeri
	char secim;//Menüye geçmek için kullandýðým deðiþken
	ifstream oku("Kargo.txt");//Kayýtý okumak için gerekli olan kayýt okuma komutu
	string temp;//temp girilen fatura numarasýný eþitlemek için kullanýlan deðiþken
	cout << "-----------------------------------------------------------" << endl;
	cout << "Görüntülemek Ýstediðiniz Kayýtýn Fatura No:";
	cin >> temp;
	while (!oku.eof())//Kargo.txt dosyasýný açýk olduðu süre boyunca gerçekleþecek iþlemler
	{
		oku >> k.fatura_no >> k.gonderen_ad >> k.gonderen_soyad >> k.alici_ad >> k.alici_soyad >> k.gonderen_adres >> k.alici_adres >> k.gonderen_tel >> k.alici_tel >> k.gonderen_bayi >> k.alici_bayi >> k.gonderen_tarih >> k.teslimat_tarih >> k.kargo_adet >> k.kargo_kg >> k.kargo_cins >> k.kargo_bedel;//Kargo.txt'deki kayýtlarý okuyan komut
		if (temp == k.fatura_no)//temp ile fatura numarasý eþit ise gerçekleþecek iþlem
		{
			kontrol = 1;//temp ile fatura numarasý eþit ise kontrol deðiþkeninin deðerini deðiþtiriyorum
			cout << "-----------------------------------------------------------" << endl;
			cout << "Aradýðýnýz Kayýt" << endl;
			cout << "-----------------------------------------------------------" << endl;
			cout << "Gönderen Ad.......:" << k.gonderen_ad << endl;
			cout << "Gönderen Soyad....." << k.gonderen_soyad << endl;
			cout << "Alýcý Ad..........:" << k.alici_ad << endl;
			cout << "Alýcý Soyad.......:" << k.alici_soyad << endl;
			cout << "Gönderen Adres....:" << k.gonderen_adres << endl;
			cout << "Alýcý Adres.......:" << k.alici_adres << endl;
			cout << "Gönderen Telefon..:" << k.gonderen_tel << endl;
			cout << "Alýcý Telefon.....:" << k.alici_tel << endl;
			cout << "Gönderen Bayi.....:" << k.gonderen_bayi << endl;
			cout << "Alýcý Bayi........:" << k.alici_bayi << endl;
			cout << "Gönderme Tarihi...:" << k.gonderen_tarih << endl;
			cout << "Teslimat Tarihi...:" << k.teslimat_tarih << endl;
			cout << "Kargo Adet........:" << k.kargo_adet << endl;
			cout << "Kargo Aðýrlýðý(KG):" << k.kargo_kg << endl;
			cout << "Kargo Cinsi.......:" << k.kargo_cins << endl;
			cout << "Kargo Bedeli......:" << k.kargo_bedel << endl;
			break;
		}
	}
	if (kontrol == 0)//temp ile fatura numarasý eþit deðilse gerçekleþecek iþlem
	{
		cout << "-----------------------------------------------------------";
		cout << endl << "Kayýt Bulunamadý" << endl;
	}
	oku.close();//Okunan dosyayý kapatýyor
	cout << "-----------------------------------------------------------" << endl;
	cout << "Baþka bir iþlem yapmak ister misiniz?(E/H)--->";
	cin >> secim;
	if (secim == 'e' || secim == 'E') Menu();//Menüye devam etmek için gerekli yapý
	else exit(0);//Hazýr fonksiyon uygulamadan çýkýyor
}

//Kargo kayýtý silme fonksiyonu
void Kargo::KargoSil() {
	int kontrol = 0;//Girilen fatura numarasýnýn eþitliðini kontrol eden deðiþken ve ilk deðeri
	char secim;//Menüye geçmek için kullandýðým deðiþken
	string temp, temp1;//temp girilen fatura numarasýný eþitlemek için kullanýlan deðiþken, temp1 iki kere okumayý engellemek için kullanýlan deðiþken
	cout << "-----------------------------------------------------------" << endl;
	cout << "Silmek Ýstediðiniz Kayýtýn Fatura No:";
	cin >> temp;
	ofstream gecici("gecici.txt");//Kargo.txt'nin bilgilerini aktarmak için gecici.txt olarak oluþturduðum dosya ve yazdýrma komutu
	ofstream gecici2("gecici2.txt");//Kargonerede.txt bilgilerini aktarmak için gecici2.txt olarak oluþturduðum dosya ve yazdýrma komutu
	ifstream oku("Kargo.txt");//Kargo.txt'yi okumak için gerekli komut
	ifstream oku2("KargoNerde.txt");//KargoNerede.txt'yi okumak için gerekli komut
	while (!oku.eof())//Kargo.txt ve KargoNerede.txt açýk olduðu süre boyunca gerçekleþecek iþlemler
	{
		oku >> k.fatura_no >> k.gonderen_ad >> k.gonderen_soyad >> k.alici_ad >> k.alici_soyad >> k.gonderen_adres >> k.alici_adres >> k.gonderen_tel >> k.alici_tel >> k.gonderen_bayi >> k.alici_bayi >> k.gonderen_tarih >> k.teslimat_tarih >> k.kargo_adet >> k.kargo_kg >> k.kargo_cins >> k.kargo_bedel;//Kargo.txt'deki kayýtlarý okuyan komut
		oku2 >> kn.nerede >> kn.teslim >> k.fatura_no;//KargoNerede.txt'deki kayýtlarý okuyan komut
		if (temp1 != k.fatura_no)//temp1 ve fatura numarasý farklýysa içerdeki iþlemi gerçekleþtirecek bunun amacý iki kere okumayý engelleme
		{
			if (temp == k.fatura_no)//temp ve fatura numarasý eþit ise gerçekleþecek iþlem
			{
				kontrol = 1;//temp ile fatura numarasý eþit ise kontrol deðiþkeninin deðerini deðiþtiriyorum
				cout << "-----------------------------------------------------------" << endl;
				cout << "Silmek Ýstediginiz Kayýt" << endl;
				cout << "-----------------------------------------------------------" << endl;
				cout << "Gönderen Ad.......:" << k.gonderen_ad << endl;
				cout << "Gönderen Soyad....:" << k.gonderen_soyad << endl;
				cout << "Alýcý Ad..........:" << k.alici_ad << endl;
				cout << "Alýcý Soyad.......:" << k.alici_soyad << endl;
				cout << "Gönderen Adres....:" << k.gonderen_adres << endl;
				cout << "Alýcý Adres.......:" << k.alici_adres << endl;
				cout << "Gönderen Telefon..:" << k.gonderen_tel << endl;
				cout << "Alýcý Telefon.....:" << k.alici_tel << endl;
				cout << "Gönderen Bayi.....:" << k.gonderen_bayi << endl;
				cout << "Alýcý Bayi........:" << k.alici_bayi << endl;
				cout << "Gönderme Tarihi...:" << k.gonderen_tarih << endl;
				cout << "Teslimat Tarihi...:" << k.teslimat_tarih << endl;
				cout << "Kargo Adet........:" << k.kargo_adet << endl;
				cout << "Kargo Aðýrlýðý(KG):" << k.kargo_kg << endl;
				cout << "Kargo Cinsi.......:" << k.kargo_cins << endl;
				cout << "Kargo Bedeli......:" << k.kargo_bedel << endl;
				cout << "Kargo Nerede......:" << kn.nerede << endl;
				cout << "Teslimat Durumu...:" << kn.teslim << endl;

			}
			else//temp ve fatura numarasý eþit deðilse gerçekleþecek iþlem,burada Kargo.txt-KargoNerede.txt'deki diðer kayýtlarý gecici.txt-gecici2.txt olarak açtýðýmýz diðer dosyalara yazacaðýz
			{

				gecici << k.fatura_no << " " << k.gonderen_ad << " " << k.gonderen_soyad << " " << k.alici_ad << " " << k.alici_soyad << " " << k.gonderen_adres << " " << k.alici_adres << " " << k.gonderen_tel << " " << k.alici_tel << " " << k.gonderen_bayi << " " << k.alici_bayi << " " << k.gonderen_tarih << " " << k.teslimat_tarih << " " << k.kargo_adet << " " << k.kargo_kg << " " << k.kargo_cins << " " << k.kargo_bedel << endl;//Kargo.txt dosyasýndaki kayýtlarý gecici.txt dosyaný yazýyoruz
				gecici2 << k.fatura_no << " " << kn.nerede << " " << kn.teslim << endl;//KargoNerede.txt dosyasýndaki kayýtlarý gecici2.txt dosyasýna yazýyoruz

			}

			if (kontrol == 0)//Kontrol deðiþkeni deðiþmiþ ise yapýlacak iþlem
			{

				cout << "-----------------------------------------------------------" << endl;
				cout << "Kayýt Bulunamadý" << endl;
			}
			else//Kontrol deðiþkeni deðiþmemiþ ise yapýlacak iþlem
			{

				cout << "-----------------------------------------------------------" << endl;
				cout << "Kayýt Silindi" << endl;

			}

		}

		temp1 = k.fatura_no;//Bir kere eþitlenme olunca eþitlenen fatura numarasýný temp1'e aktarýyorum

	}//Yaptýðým bu iþlem sonucu fatura numarasý eþitlenen kayýt yeni açtýðýmýz gecici.txt-gecici2.txt dosyalarýna aktarýlmýyor diðer kayýtlar aktarýlýyor

	gecici.close();//Kargo.txt aktarmak için açtýðým gecici.txt dosyayý kapatýyorum
	oku.close();//Okunan Kargo.txt dosyasýný kapatýyorum
	gecici2.close();//KargoNerede.txt aktarmak için açtýðým gecici2.txt dosyayý kapatýyorum
	oku2.close();//Okunan KargoNerede.txt dosyasýný kapatýyorum
	remove("Kargo.txt");//Kargo.txt dosyasýný siliyorum
	remove("KargoNerede.txt");//KargoNerede.txt dosyasýný siliyorum
	rename("gecici.txt", "Kargo.txt");//Kargo.txt aktarmak için oluþturdugum gecici.txt dosyasýnýn adýný Kargo.txt yapýyorum
	rename("gecici2.txt", "KargoNerede.txt");//KargoNerede.txt aktarmak için oluþturdugum gecici2.txt dosyanýn adýný KargoNerede.txt yapýyorum
	cout << "-----------------------------------------------------------" << endl;
	cout << "Baþka Bir Ýþlem Yapmak Ýstermisiniz?(E/H)--->";
	cin >> secim;
	if (secim == 'e' || secim == 'E') Menu();//Menüye devam etmek için gerekli yapý
	else exit(0);//Hazýr fonksiyon uygulamadan çýkýyor
}

//Kargo bilgisi güncelleme fonksiyonu
void Kargo::KargoGuncelle() {
	int kontrol = 0;//Girilen fatura numarasýnýn eþitliðini kontrol eden deðiþken ve ilk deðeri
	char secim;//Menüye geçmek için kullandýðým deðiþken
	string temp, temp1;//temp fatura numarasýný eþlemek için kullanýlan deðiþken, temp1 iki kere okumayý engellemek için kullanýlan deðiþken
	cout << "-----------------------------------------------------------" << endl;
	cout << "Güncellemek Ýstediðiniz Kayýtýn Fatura No:";
	cin >> temp;
	ofstream gecici("gecici.txt");//Kargo.txt nin bilgilerini aktarmak için gecici.txt olarak oluþturduðum dosya ve yazdýrma komutu
	ifstream oku("Kargo.txt");//Kargo.txt'yi okumak için gerekli komut
	while (!oku.eof())//Kargo.txt dosyasý açýk olduðu süre boyunca gerçekleþecek iþlem
	{
		oku >> k.fatura_no >> k.gonderen_ad >> k.gonderen_soyad >> k.alici_ad >> k.alici_soyad >> k.gonderen_adres >> k.alici_adres >> k.gonderen_tel >> k.alici_tel >> k.gonderen_bayi >> k.alici_bayi >> k.gonderen_tarih >> k.teslimat_tarih >> k.kargo_adet >> k.kargo_kg >> k.kargo_cins >> k.kargo_bedel;//Kargo.txt dosyasýndaki kayýtlarý okuyan komut
		if (temp1 != k.fatura_no)// temp1 ve fatura numarasý farklýysa içerdeki iþlemi gerçekleþtirecek bunun amacý iki kere bu iþlemin gerçekleþmesini engelleme
		{
			if (k.fatura_no == temp)//temp ve fatura numarasý eþit ise gerçekleþecek iþlem
			{
				kontrol = 1;//temp ile fatura numarasý eþit ise kontrol deðiþkeninin deðerini deðiþtiriyorum
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kayýttaki Bilgileriniz" << endl;
				cout << "-----------------------------------------------------------" << endl;
				cout << "Gonderen Ad.......:" << k.gonderen_ad << endl;
				cout << "Gonderen Soyad....:" << k.gonderen_soyad << endl;
				cout << "Alici Ad..........:" << k.alici_ad << endl;
				cout << "Alici Soyad.......:" << k.alici_soyad << endl;
				cout << "Gonderen Adres....:" << k.gonderen_adres << endl;
				cout << "Alici Adres.......:" << k.alici_adres << endl;
				cout << "Gonderen Telefon..:" << k.gonderen_tel << endl;
				cout << "Alici Telefon.....:" << k.alici_tel << endl;
				cout << "Gonderen Bayi.....:" << k.gonderen_bayi << endl;
				cout << "Alici Bayi........:" << k.alici_bayi << endl;
				cout << "Gonderme Tarihi...:" << k.gonderen_tarih << endl;
				cout << "Teslimat Tarihi...:" << k.teslimat_tarih << endl;
				cout << "Kargo Adet........:" << k.kargo_adet << endl;
				cout << "Kargo Kilogram....:" << k.kargo_kg << endl;
				cout << "Kargo Cinsi.......:" << k.kargo_cins << endl;
				cout << "Kargo Bedeli......:" << k.kargo_bedel << endl;
				cout << "-----------------------------------------------------------" << endl;
				cout << "Yeni Bilgileri Giriniz" << endl;
				cout << "-----------------------------------------------------------" << endl;
				cout << "Gonderen Ad.......:";
				cin >> k.gonderen_ad;
				cout << "Gonderen Soyad....:";
				cin >> k.gonderen_soyad;
				cout << "Alici Ad..........:";
				cin >> k.alici_ad;
				cout << "Alici Soyad.......:";
				cin >> k.alici_soyad;
				cout << "Gonderen Adres....:";
				cin >> k.gonderen_adres;
				cout << "Alici Adres.......:";
				cin >> k.alici_adres;
				cout << "Gonderen Telefon..:";
				cin >> k.gonderen_tel;
				cout << "Alici Telefon.....:";
				cin >> k.alici_tel;
				cout << "Gonderen Bayi.....:";
				cin >> k.gonderen_bayi;
				cout << "Alici Bayi........:";
				cin >> k.alici_bayi;
				cout << "Gonderme Tarihi...:";
				cin >> k.gonderen_tarih;
				cout << "Teslimat Tarihi...:";
				cin >> k.teslimat_tarih;
				cout << "Kargo Adet........:";
				cin >> k.kargo_adet;
				cout << "Kargo Kilogram....:";
				cin >> k.kargo_kg;
				cout << "Kargo Cinsi.......:";
				cin >> k.kargo_cins;
				cout << "Kargo Bedeli......:";
				cin >> k.kargo_bedel;
				gecici << k.fatura_no << " " << k.gonderen_ad << " " << k.gonderen_soyad << " " << k.alici_ad << " " << k.alici_soyad << " " << k.gonderen_adres << " " << k.alici_adres << " " << k.gonderen_tel << " " << k.alici_tel << " " << k.gonderen_bayi << " " << k.alici_bayi << " " << k.gonderen_tarih << " " << k.teslimat_tarih << " " << k.kargo_adet << " " << k.kargo_kg << " " << k.kargo_cins << " " << k.kargo_bedel << endl;//Yeni bilgileri gecici.txt dosyasýna yazdýrýyorum
			}
			else//temp ile fatura numarasý eþit olmayan yani diðer kayýtlarý gecici.txt dosyasýna yazdýrýyorum
			{
				gecici << k.fatura_no << " " << k.gonderen_ad << " " << k.gonderen_soyad << " " << k.alici_ad << " " << k.alici_soyad << " " << k.gonderen_adres << " " << k.alici_adres << " " << k.gonderen_tel << " " << k.alici_tel << " " << k.gonderen_bayi << " " << k.alici_bayi << " " << k.gonderen_tarih << " " << k.teslimat_tarih << " " << k.kargo_adet << " " << k.kargo_kg << " " << k.kargo_cins << " " << k.kargo_bedel << endl;
			}
			if (kontrol == 0)//Kontrol deðiþkeni deðiþmemiþ ise gerçekleþecek iþlem
			{
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kayýt Bulunamadý" << endl;
			}
			else //Kontrol deðiþkeni deðiþmiþ ise gerçekleþecek iþlem
			{
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kayýt Güncellendi" << endl;
			}
		}
		temp1 = k.fatura_no;//Bir kere eþitlenme olup iþlemler gerçekleþince temp1'e fatura numarasýný aktarýyorum
	}//Burada gerçekleþtirdiðim iþlem fatura numarasý eþitlenen kayýtýn mevcut bilgilerini görüntülüyor ve yeni bilgileri girerek gecici.txt dosyasýna yazdýrýyoruz.Eþitlenme olmayan yani diðer kayýtlar direk gecici.txt dosyasýna yazdýrýlýyor

	gecici.close();//Kargo.txt kayýtlarýný aktarmak için açtýðým gecici.txt dosyayý kapatýyorum
	oku.close();//Okunan Kargo.txt dosyasýný kapatýyorum
	remove("Kargo.txt");//Kargo.txt dosyasýný siliyorum
	rename("gecici.txt", "Kargo.txt");//Kargo.txt yerine açtýðým gecici.txt dosyasýnýn adýný Kargo.txt yapýyorum
	cout << "-----------------------------------------------------------" << endl;
	cout << "Baþka Bir Ýþlem Yapmak Ýstermisiniz?(E/H)--->";
	cin >> secim;
	if (secim == 'e' || secim == 'E') Menu();//Menüye devam etmek için gerekli yapý
	else exit(0);//Hazýr fonksiyon uygulamadan çýkýyor
}

//Kargo durumu kayýt girme  fonksiyonu
void KargoNerede::KargoNeredeYaz() {
	char secim;//Menüye dönmek için kullandýðým deðiþken
	ofstream yaz("KargoNerede.txt", ios::app);//Kayýt dosyasýný KargoNerede.txt adýnda oluþturacak komut
	cout << "Kargo Nerede......:";
	cin >> kn.nerede;
	cout << "Teslimat Durumu...:";
	cin >> kn.teslim;
	yaz << kn.nerede << " " << kn.teslim << " " << k.fatura_no << endl;//Girdiðim bilgileri KargoNerede.txt dosyasýna yazan komut
	yaz.close();//Kayýt yapýlan dosyayý kapatýyor
	cout << "-----------------------------------------------------------" << endl;
	cout << "Kayýt Yazýldý" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "Baþka Bir Ýþlem Yapmak Ýstermisiniz?(E/H)--->";
	cin >> secim;
	if (secim == 'e' || secim == 'E') Menu();//Menüye devam etmek için gerekli yapý
	else exit(0);//Hazýr fonksiyon uygulamadan çýkýyor
}

//Kargo durumu kayýtý okuma fonksiyonu
void KargoNerede::KargoNeredeOku() {
	int kontrol = 0;//Girilen fatura numarasýnýn eþitliðini kontrol eden deðiþken ve ilk deðeri
	char secim;//Menüye dönmek için kullandýðým deðiþken
	ifstream oku("KargoNerede.txt");//KargoNerede.txt dosyasýný okumak için gerekli komut
	string temp;//temp fatura numarasýný eþlemek için kullanýlan deðiþken
	cout << "-----------------------------------------------------------" << endl;
	cout << "Görüntülemek Ýstediginiz Kargo Durumunun Fatura No:";
	cin >> temp;
	while (!oku.eof())//KargoNerede.txt dosyasý açýk olduðu süre boyunca blok içerisindeki iþlemler gerçekleþecek
	{
		oku >> kn.nerede >> kn.teslim >> k.fatura_no;//KargoNerede.txt dosyasýndaki kayýtlarý okuyan komut
		if (temp == k.fatura_no)//temp ve fatura numarasý eþit ise gerçekleþecek iþlem
		{
			kontrol = 1;//temp ile fatura numarasý eþit ise kontrol deðiþkeninin deðerini deðiþtiriyorum
			cout << "-----------------------------------------------------------" << endl;
			cout << "Aradýðýnýz Kayýt" << endl;
			cout << "-----------------------------------------------------------" << endl;
			cout << "Kargo Nerede......:" << kn.nerede << endl;
			cout << "Teslimat Durumu...:" << kn.teslim << endl;
			break;
		}
	}
	if (kontrol == 0) //Kontrol deðiþkeni deðiþmemiþ ise gerçekleþecek iþlem
	{
		cout << "------------------------------------------------------" << endl;
		cout << "Kayýt Bulunamadý" << endl;
	}

	oku.close();//Okunan dosyayý kapatýyorum
	cout << "------------------------------------------------------" << endl;
	cout << "Baþka Bir Ýþlem Yapmak Ýstermisiniz?(E/H)" << "--->";
	cin >> secim;
	if (secim == 'e' || secim == 'E') Menu();//Menüye devam etmek için gerekli yapý
	else exit(0);//Hazýr fonksiyon uygulamadan çýkýyor
}

//Kargo durumu kayýtý güncelleme fonksiyonu
void KargoNerede::KargoNeredeGuncelle() {
	int kontrol = 0;//Girilen fatura numarasýnýn eþitliðini kontrol eden deðiþken ve ilk deðeri
	char secim;//Menüye dönmek için kullandýðým deðiþken
	string temp, temp1;//temp fatura numarasýný eþlemek için kullanýlan deðiþken, temp1 iki kere iþlemin gerçekleþmesini engellemek için kullanýlan deðiþken
	cout << "-----------------------------------------------------------" << endl;
	cout << "Güncellemek Ýstediðiniz Kargo Durumunun Fatura No:";
	cin >> temp;
	ofstream gecici("gecici.txt");//KargoNerede.txt nin bilgilerini aktarmak için gecici.txt olarak oluþturdugum dosya ve yazdýrma komutu
	ifstream oku("KargoNerede.txt");//KargoNerede.txt dosyasýndaki kayýtlarý okumak için gerekli komut
	while (!oku.eof()) //KargoNerede.txt dosyasý açýk olduðu süre boyunca gerçeklþecek iþlem
	{
		oku >> kn.nerede >> kn.teslim >> k.fatura_no;//KargoNerede.txt dosyasýndaki kayýtlarý okuyan komut
		if (temp1 != k.fatura_no)// temp1 ve fatura numarasý farklýysa içerdeki iþlemi gerçekleþtirecek bunun amacý iki kere bu iþlemin gerçekleþmesini engelleme
		{
			if (k.fatura_no == temp) //temp ve fatura no eþleþirse bu blok içindeki iþlem gerçekeleþecek 
			{
				kontrol = 1;//Kontrol deðiþkeninin deðerini deðiþtiriyorum
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kayýttaki Bilgileriniz" << endl;
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kargo Nerede......:" << kn.nerede << endl;
				cout << "Teslimat Durumu...:" << kn.teslim << endl;
				cout << "-----------------------------------------------------------" << endl;
				cout << "Yeni Bilgileri Giriniz" << endl;
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kargo Nerede......:";
				cin >> kn.nerede;
				cout << "Teslimat Durumu...:";
				cin >> kn.teslim;
				gecici << kn.nerede << " " << kn.teslim << " " << k.fatura_no << endl;//Yeni bilgileri dosyaya yazýyor
			}
			else {
				gecici << k.fatura_no << " " << kn.nerede << " " << kn.teslim << endl;//Dosyadaki diðer kayýtlarý gecici.txt dosyasýna yazdýrýyor
			}
			if (kontrol == 1) //Kontrol deðiþkeninin deðeri deðiþmiþse gerçekleþecek iþlem
			{
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kayýt Güncellendi" << endl;
				cout << "-----------------------------------------------------------" << endl;
			}
			else //Kontrol deðiþkeninin deðeri deðiþmezse gerçekleþecek iþlem
			{
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kayýt Bulunamadý" << endl;
				cout << "-----------------------------------------------------------" << endl;
			}
		}
		temp1 = k.fatura_no;//Bir kere eþitlenme olup iþlemler gerçekleþince temp1'e fatura numarasýný aktarýyorum
	}//Burada gerçekleþtirdiðim iþlem fatura numarasý eþitlenen kayýtýn mevcut bilgilerini görüntülüyor ve yeni bilgileri girerek gecici.txt dosyasýna yazdýrýyorum.Eþitlenme olmayan yani diðer kayýtlar direk gecici.txt dosyasýna yazdýrýlýyor

	gecici.close();//KargoNerede.txt'deki kayýtlarý aktarmak için açtýðým gecici.txt adlý dosyayý kapatýyorum
	oku.close();//Okunan KargoNerede.txt adlý dosyayý kapatýyorum 
	remove("KargoNerede.txt");//KargoNerede.txt dosyasýný siliyorum
	rename("gecici.txt", "KargoNerede.txt");//KargoNerede.txt yerine açtýðým gecici.txt dosyasýnýn adýný KargoNerede.txt yapýyorum
	cout << "Baþka Bir Ýþlem Yapmak Ýstermisiniz?(E/H)" << "--->";
	cin >> secim;
	if (secim == 'e' || secim == 'E') Menu();//Menüye devam etmek için gerekli yapý
	else exit(0);//Hazýr fonksiyon uygulamadan çýkýyor
}

//Menü fonksiyonu
void Menu() {
	system("cls");//Ekran temizleme komutu her menüye geldiðimde ekraný temizliyor
	int secim;//Menüdeki iþlemlerde seçim yapmak için tanýmladðým deðiþken
	cout << "--------------------------------" << endl;
	cout << "-----Kargo Takip Otomasyonu-----" << endl;
	cout << "--------------------------------" << endl;
	cout << "Yapmak Ýstediðiniz Ýþlemi Seçin" << endl;
	cout << "--------------------------------" << endl;
	cout << "1-Kargo Kayýt Giriþi" << endl;
	cout << "2-Kargo Bilgisi Görüntüleme" << endl;
	cout << "3-Kargo Bilgisi Güncelleme" << endl;
	cout << "4-Kargo Durumu Görüntüleme" << endl;
	cout << "5-Kargo Durumu Güncelleme" << endl;
	cout << "6-Kargo Kayýtý Silme" << endl;
	cout << "7-Uygulamadan Çýkýþ" << endl;
	cout << "--------------------------------" << endl;
	cout << "Seçiminiz:";
	cin >> secim;
	system("cls");//ekran temizleme komutu
	switch (secim)//Menüdeki seçim için swcith case yapýsýný kullandým
	{
	case 1: k.KargoYaz(); break;
	case 2: k.KargoOku(); break;
	case 3: k.KargoGuncelle(); break;
	case 4: kn.KargoNeredeOku(); break;
	case 5: kn.KargoNeredeGuncelle(); break;
	case 6: k.KargoSil(); break;
	case 7:exit(0); break;
	default:cout << "Yanlis secim yaptiniz listeden secim yapiniz" << endl; Menu();
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Turkish");//Türkçe karakter için yaptýðým tanýmlama

	Kargo k;//kargo class'ýný tanýmasý için yaptýðým tanýmlama
	KargoNerede kn;//kargonerede class'ýný tanýmasý için yaptýðým tanýmlama
	Menu();//Menu fonksiyonunun çalýþmasý için yaptðým tanýmlama

	system("pause");
	return 0;
}

