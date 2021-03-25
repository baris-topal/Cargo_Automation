
#include <iostream>//cin,cout komutlar�n�n tan�ml� oldu�u k�t�phane
#include <locale.h>//T�rk�e karakter kullanmak i�in gerekli k�t�phane
#include <string>//string tan�ml� de�i�kenler i�in gerekli k�t�phane
#include <fstream>//Dosyalama i�lemleri i�in gerekli k�t�phane
using namespace std;//isim uzay�

void Menu();//A�a��da yazd���m Menu fonksiyonunun �al��mas� i�in yukar�da tan�mlad�m

//Kargo bilgisi de�i�kenlerinin olud�u class 
class Kargo {
public:
	string fatura_no;//Kay�t bulma,yazma,g�ncelleme,g�r�nt�leme i�in baz ald���m temel de�i�ken bunu kullanarak i�lemleri ger�ekle�tirece�iz
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

	//Dosyalam i�lemleri fonksiyonlar�
	void KargoYaz();
	void KargoOku();
	void KargoGuncelle();
	void KargoSil();

}k;

//Kargo durumu de�i�kenlerinin oldu�u class
class KargoNerede {
public:
	string nerede;
	string teslim;

	//Dosyalama i�lemleri fonksiyonlar�
	void KargoNeredeYaz();
	void KargoNeredeOku();
	void KargoNeredeGuncelle();

}kn;

//Kargo bilgisi kay�t girme fonksiyonu
void Kargo::KargoYaz() {

	ofstream yaz("Kargo.txt", ios::app);//Kay�t dosyas�n� Kargo.txt ad�nda olu�turacak komut
	cout << "-----------------------------------------------------------" << endl;
	cout << "Fatura No.........:";
	cin >> k.fatura_no;
	cout << "G�nderen Ad.......:";
	cin >> k.gonderen_ad;
	cout << "G�nderen Soyad....:";
	cin >> k.gonderen_soyad;
	cout << "Al�c� Ad..........:";
	cin >> k.alici_ad;
	cout << "Al�c� Soyad.......:";
	cin >> k.alici_soyad;
	cout << "G�nderen Adres....:";
	cin >> k.gonderen_adres;
	cout << "Al�c� Adres.......:";
	cin >> k.alici_adres;
	cout << "G�nderen Telefon..:";
	cin >> k.gonderen_tel;
	cout << "Al�c� Telefon.....:";
	cin >> k.alici_tel;
	cout << "G�nderen Bayi.....:";
	cin >> k.gonderen_bayi;
	cout << "Al�c� Bayi........:";
	cin >> k.alici_bayi;
	cout << "G�nderme Tarihi...:";
	cin >> k.gonderen_tarih;
	cout << "Teslimat Tarihi...:";
	cin >> k.teslimat_tarih;
	cout << "Kargo Adet........:";
	cin >> k.kargo_adet;
	cout << "Kargo A��rl���(KG):";
	cin >> k.kargo_kg;
	cout << "Kargo Cinsi.......:";
	cin >> k.kargo_cins;
	cout << "Kargo Bedeli......:";
	cin >> k.kargo_bedel;
	yaz << k.fatura_no << " " << k.gonderen_ad << " " << k.gonderen_soyad << " " << k.alici_ad << " " << k.alici_soyad << " " << k.gonderen_adres << " " << k.alici_adres << " " << k.gonderen_tel << " " << k.alici_tel << " " << k.gonderen_bayi << " " << k.alici_bayi << " " << k.gonderen_tarih << " " << k.teslimat_tarih << " " << k.kargo_adet << " " << k.kargo_kg << " " << k.kargo_cins << " " << k.kargo_bedel << endl;//Girdi�im verileri Kargo.txt dosyas�na yazd�rd���m komut
	yaz.close();//Kay�t yap�lan dosyay� kapatan komut
	kn.KargoNeredeYaz();//Burada kargo durumu girece�imiz fonksiyona devam ediyoruz ikisi bir birine ba�lant�l� oldu�u i�in farkl� zamanda yazmak hata yaratabilir

}

//Kargo bilgisi kay�t� okuma fonksiyonu
void Kargo::KargoOku() {
	int kontrol = 0;//Girilen fatura numaras�n�n e�itli�ini kontrol eden de�i�ken ve ilk de�eri
	char secim;//Men�ye ge�mek i�in kulland���m de�i�ken
	ifstream oku("Kargo.txt");//Kay�t� okumak i�in gerekli olan kay�t okuma komutu
	string temp;//temp girilen fatura numaras�n� e�itlemek i�in kullan�lan de�i�ken
	cout << "-----------------------------------------------------------" << endl;
	cout << "G�r�nt�lemek �stedi�iniz Kay�t�n Fatura No:";
	cin >> temp;
	while (!oku.eof())//Kargo.txt dosyas�n� a��k oldu�u s�re boyunca ger�ekle�ecek i�lemler
	{
		oku >> k.fatura_no >> k.gonderen_ad >> k.gonderen_soyad >> k.alici_ad >> k.alici_soyad >> k.gonderen_adres >> k.alici_adres >> k.gonderen_tel >> k.alici_tel >> k.gonderen_bayi >> k.alici_bayi >> k.gonderen_tarih >> k.teslimat_tarih >> k.kargo_adet >> k.kargo_kg >> k.kargo_cins >> k.kargo_bedel;//Kargo.txt'deki kay�tlar� okuyan komut
		if (temp == k.fatura_no)//temp ile fatura numaras� e�it ise ger�ekle�ecek i�lem
		{
			kontrol = 1;//temp ile fatura numaras� e�it ise kontrol de�i�keninin de�erini de�i�tiriyorum
			cout << "-----------------------------------------------------------" << endl;
			cout << "Arad���n�z Kay�t" << endl;
			cout << "-----------------------------------------------------------" << endl;
			cout << "G�nderen Ad.......:" << k.gonderen_ad << endl;
			cout << "G�nderen Soyad....." << k.gonderen_soyad << endl;
			cout << "Al�c� Ad..........:" << k.alici_ad << endl;
			cout << "Al�c� Soyad.......:" << k.alici_soyad << endl;
			cout << "G�nderen Adres....:" << k.gonderen_adres << endl;
			cout << "Al�c� Adres.......:" << k.alici_adres << endl;
			cout << "G�nderen Telefon..:" << k.gonderen_tel << endl;
			cout << "Al�c� Telefon.....:" << k.alici_tel << endl;
			cout << "G�nderen Bayi.....:" << k.gonderen_bayi << endl;
			cout << "Al�c� Bayi........:" << k.alici_bayi << endl;
			cout << "G�nderme Tarihi...:" << k.gonderen_tarih << endl;
			cout << "Teslimat Tarihi...:" << k.teslimat_tarih << endl;
			cout << "Kargo Adet........:" << k.kargo_adet << endl;
			cout << "Kargo A��rl���(KG):" << k.kargo_kg << endl;
			cout << "Kargo Cinsi.......:" << k.kargo_cins << endl;
			cout << "Kargo Bedeli......:" << k.kargo_bedel << endl;
			break;
		}
	}
	if (kontrol == 0)//temp ile fatura numaras� e�it de�ilse ger�ekle�ecek i�lem
	{
		cout << "-----------------------------------------------------------";
		cout << endl << "Kay�t Bulunamad�" << endl;
	}
	oku.close();//Okunan dosyay� kapat�yor
	cout << "-----------------------------------------------------------" << endl;
	cout << "Ba�ka bir i�lem yapmak ister misiniz?(E/H)--->";
	cin >> secim;
	if (secim == 'e' || secim == 'E') Menu();//Men�ye devam etmek i�in gerekli yap�
	else exit(0);//Haz�r fonksiyon uygulamadan ��k�yor
}

//Kargo kay�t� silme fonksiyonu
void Kargo::KargoSil() {
	int kontrol = 0;//Girilen fatura numaras�n�n e�itli�ini kontrol eden de�i�ken ve ilk de�eri
	char secim;//Men�ye ge�mek i�in kulland���m de�i�ken
	string temp, temp1;//temp girilen fatura numaras�n� e�itlemek i�in kullan�lan de�i�ken, temp1 iki kere okumay� engellemek i�in kullan�lan de�i�ken
	cout << "-----------------------------------------------------------" << endl;
	cout << "Silmek �stedi�iniz Kay�t�n Fatura No:";
	cin >> temp;
	ofstream gecici("gecici.txt");//Kargo.txt'nin bilgilerini aktarmak i�in gecici.txt olarak olu�turdu�um dosya ve yazd�rma komutu
	ofstream gecici2("gecici2.txt");//Kargonerede.txt bilgilerini aktarmak i�in gecici2.txt olarak olu�turdu�um dosya ve yazd�rma komutu
	ifstream oku("Kargo.txt");//Kargo.txt'yi okumak i�in gerekli komut
	ifstream oku2("KargoNerde.txt");//KargoNerede.txt'yi okumak i�in gerekli komut
	while (!oku.eof())//Kargo.txt ve KargoNerede.txt a��k oldu�u s�re boyunca ger�ekle�ecek i�lemler
	{
		oku >> k.fatura_no >> k.gonderen_ad >> k.gonderen_soyad >> k.alici_ad >> k.alici_soyad >> k.gonderen_adres >> k.alici_adres >> k.gonderen_tel >> k.alici_tel >> k.gonderen_bayi >> k.alici_bayi >> k.gonderen_tarih >> k.teslimat_tarih >> k.kargo_adet >> k.kargo_kg >> k.kargo_cins >> k.kargo_bedel;//Kargo.txt'deki kay�tlar� okuyan komut
		oku2 >> kn.nerede >> kn.teslim >> k.fatura_no;//KargoNerede.txt'deki kay�tlar� okuyan komut
		if (temp1 != k.fatura_no)//temp1 ve fatura numaras� farkl�ysa i�erdeki i�lemi ger�ekle�tirecek bunun amac� iki kere okumay� engelleme
		{
			if (temp == k.fatura_no)//temp ve fatura numaras� e�it ise ger�ekle�ecek i�lem
			{
				kontrol = 1;//temp ile fatura numaras� e�it ise kontrol de�i�keninin de�erini de�i�tiriyorum
				cout << "-----------------------------------------------------------" << endl;
				cout << "Silmek �stediginiz Kay�t" << endl;
				cout << "-----------------------------------------------------------" << endl;
				cout << "G�nderen Ad.......:" << k.gonderen_ad << endl;
				cout << "G�nderen Soyad....:" << k.gonderen_soyad << endl;
				cout << "Al�c� Ad..........:" << k.alici_ad << endl;
				cout << "Al�c� Soyad.......:" << k.alici_soyad << endl;
				cout << "G�nderen Adres....:" << k.gonderen_adres << endl;
				cout << "Al�c� Adres.......:" << k.alici_adres << endl;
				cout << "G�nderen Telefon..:" << k.gonderen_tel << endl;
				cout << "Al�c� Telefon.....:" << k.alici_tel << endl;
				cout << "G�nderen Bayi.....:" << k.gonderen_bayi << endl;
				cout << "Al�c� Bayi........:" << k.alici_bayi << endl;
				cout << "G�nderme Tarihi...:" << k.gonderen_tarih << endl;
				cout << "Teslimat Tarihi...:" << k.teslimat_tarih << endl;
				cout << "Kargo Adet........:" << k.kargo_adet << endl;
				cout << "Kargo A��rl���(KG):" << k.kargo_kg << endl;
				cout << "Kargo Cinsi.......:" << k.kargo_cins << endl;
				cout << "Kargo Bedeli......:" << k.kargo_bedel << endl;
				cout << "Kargo Nerede......:" << kn.nerede << endl;
				cout << "Teslimat Durumu...:" << kn.teslim << endl;

			}
			else//temp ve fatura numaras� e�it de�ilse ger�ekle�ecek i�lem,burada Kargo.txt-KargoNerede.txt'deki di�er kay�tlar� gecici.txt-gecici2.txt olarak a�t���m�z di�er dosyalara yazaca��z
			{

				gecici << k.fatura_no << " " << k.gonderen_ad << " " << k.gonderen_soyad << " " << k.alici_ad << " " << k.alici_soyad << " " << k.gonderen_adres << " " << k.alici_adres << " " << k.gonderen_tel << " " << k.alici_tel << " " << k.gonderen_bayi << " " << k.alici_bayi << " " << k.gonderen_tarih << " " << k.teslimat_tarih << " " << k.kargo_adet << " " << k.kargo_kg << " " << k.kargo_cins << " " << k.kargo_bedel << endl;//Kargo.txt dosyas�ndaki kay�tlar� gecici.txt dosyan� yaz�yoruz
				gecici2 << k.fatura_no << " " << kn.nerede << " " << kn.teslim << endl;//KargoNerede.txt dosyas�ndaki kay�tlar� gecici2.txt dosyas�na yaz�yoruz

			}

			if (kontrol == 0)//Kontrol de�i�keni de�i�mi� ise yap�lacak i�lem
			{

				cout << "-----------------------------------------------------------" << endl;
				cout << "Kay�t Bulunamad�" << endl;
			}
			else//Kontrol de�i�keni de�i�memi� ise yap�lacak i�lem
			{

				cout << "-----------------------------------------------------------" << endl;
				cout << "Kay�t Silindi" << endl;

			}

		}

		temp1 = k.fatura_no;//Bir kere e�itlenme olunca e�itlenen fatura numaras�n� temp1'e aktar�yorum

	}//Yapt���m bu i�lem sonucu fatura numaras� e�itlenen kay�t yeni a�t���m�z gecici.txt-gecici2.txt dosyalar�na aktar�lm�yor di�er kay�tlar aktar�l�yor

	gecici.close();//Kargo.txt aktarmak i�in a�t���m gecici.txt dosyay� kapat�yorum
	oku.close();//Okunan Kargo.txt dosyas�n� kapat�yorum
	gecici2.close();//KargoNerede.txt aktarmak i�in a�t���m gecici2.txt dosyay� kapat�yorum
	oku2.close();//Okunan KargoNerede.txt dosyas�n� kapat�yorum
	remove("Kargo.txt");//Kargo.txt dosyas�n� siliyorum
	remove("KargoNerede.txt");//KargoNerede.txt dosyas�n� siliyorum
	rename("gecici.txt", "Kargo.txt");//Kargo.txt aktarmak i�in olu�turdugum gecici.txt dosyas�n�n ad�n� Kargo.txt yap�yorum
	rename("gecici2.txt", "KargoNerede.txt");//KargoNerede.txt aktarmak i�in olu�turdugum gecici2.txt dosyan�n ad�n� KargoNerede.txt yap�yorum
	cout << "-----------------------------------------------------------" << endl;
	cout << "Ba�ka Bir ��lem Yapmak �stermisiniz?(E/H)--->";
	cin >> secim;
	if (secim == 'e' || secim == 'E') Menu();//Men�ye devam etmek i�in gerekli yap�
	else exit(0);//Haz�r fonksiyon uygulamadan ��k�yor
}

//Kargo bilgisi g�ncelleme fonksiyonu
void Kargo::KargoGuncelle() {
	int kontrol = 0;//Girilen fatura numaras�n�n e�itli�ini kontrol eden de�i�ken ve ilk de�eri
	char secim;//Men�ye ge�mek i�in kulland���m de�i�ken
	string temp, temp1;//temp fatura numaras�n� e�lemek i�in kullan�lan de�i�ken, temp1 iki kere okumay� engellemek i�in kullan�lan de�i�ken
	cout << "-----------------------------------------------------------" << endl;
	cout << "G�ncellemek �stedi�iniz Kay�t�n Fatura No:";
	cin >> temp;
	ofstream gecici("gecici.txt");//Kargo.txt nin bilgilerini aktarmak i�in gecici.txt olarak olu�turdu�um dosya ve yazd�rma komutu
	ifstream oku("Kargo.txt");//Kargo.txt'yi okumak i�in gerekli komut
	while (!oku.eof())//Kargo.txt dosyas� a��k oldu�u s�re boyunca ger�ekle�ecek i�lem
	{
		oku >> k.fatura_no >> k.gonderen_ad >> k.gonderen_soyad >> k.alici_ad >> k.alici_soyad >> k.gonderen_adres >> k.alici_adres >> k.gonderen_tel >> k.alici_tel >> k.gonderen_bayi >> k.alici_bayi >> k.gonderen_tarih >> k.teslimat_tarih >> k.kargo_adet >> k.kargo_kg >> k.kargo_cins >> k.kargo_bedel;//Kargo.txt dosyas�ndaki kay�tlar� okuyan komut
		if (temp1 != k.fatura_no)// temp1 ve fatura numaras� farkl�ysa i�erdeki i�lemi ger�ekle�tirecek bunun amac� iki kere bu i�lemin ger�ekle�mesini engelleme
		{
			if (k.fatura_no == temp)//temp ve fatura numaras� e�it ise ger�ekle�ecek i�lem
			{
				kontrol = 1;//temp ile fatura numaras� e�it ise kontrol de�i�keninin de�erini de�i�tiriyorum
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kay�ttaki Bilgileriniz" << endl;
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
				gecici << k.fatura_no << " " << k.gonderen_ad << " " << k.gonderen_soyad << " " << k.alici_ad << " " << k.alici_soyad << " " << k.gonderen_adres << " " << k.alici_adres << " " << k.gonderen_tel << " " << k.alici_tel << " " << k.gonderen_bayi << " " << k.alici_bayi << " " << k.gonderen_tarih << " " << k.teslimat_tarih << " " << k.kargo_adet << " " << k.kargo_kg << " " << k.kargo_cins << " " << k.kargo_bedel << endl;//Yeni bilgileri gecici.txt dosyas�na yazd�r�yorum
			}
			else//temp ile fatura numaras� e�it olmayan yani di�er kay�tlar� gecici.txt dosyas�na yazd�r�yorum
			{
				gecici << k.fatura_no << " " << k.gonderen_ad << " " << k.gonderen_soyad << " " << k.alici_ad << " " << k.alici_soyad << " " << k.gonderen_adres << " " << k.alici_adres << " " << k.gonderen_tel << " " << k.alici_tel << " " << k.gonderen_bayi << " " << k.alici_bayi << " " << k.gonderen_tarih << " " << k.teslimat_tarih << " " << k.kargo_adet << " " << k.kargo_kg << " " << k.kargo_cins << " " << k.kargo_bedel << endl;
			}
			if (kontrol == 0)//Kontrol de�i�keni de�i�memi� ise ger�ekle�ecek i�lem
			{
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kay�t Bulunamad�" << endl;
			}
			else //Kontrol de�i�keni de�i�mi� ise ger�ekle�ecek i�lem
			{
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kay�t G�ncellendi" << endl;
			}
		}
		temp1 = k.fatura_no;//Bir kere e�itlenme olup i�lemler ger�ekle�ince temp1'e fatura numaras�n� aktar�yorum
	}//Burada ger�ekle�tirdi�im i�lem fatura numaras� e�itlenen kay�t�n mevcut bilgilerini g�r�nt�l�yor ve yeni bilgileri girerek gecici.txt dosyas�na yazd�r�yoruz.E�itlenme olmayan yani di�er kay�tlar direk gecici.txt dosyas�na yazd�r�l�yor

	gecici.close();//Kargo.txt kay�tlar�n� aktarmak i�in a�t���m gecici.txt dosyay� kapat�yorum
	oku.close();//Okunan Kargo.txt dosyas�n� kapat�yorum
	remove("Kargo.txt");//Kargo.txt dosyas�n� siliyorum
	rename("gecici.txt", "Kargo.txt");//Kargo.txt yerine a�t���m gecici.txt dosyas�n�n ad�n� Kargo.txt yap�yorum
	cout << "-----------------------------------------------------------" << endl;
	cout << "Ba�ka Bir ��lem Yapmak �stermisiniz?(E/H)--->";
	cin >> secim;
	if (secim == 'e' || secim == 'E') Menu();//Men�ye devam etmek i�in gerekli yap�
	else exit(0);//Haz�r fonksiyon uygulamadan ��k�yor
}

//Kargo durumu kay�t girme  fonksiyonu
void KargoNerede::KargoNeredeYaz() {
	char secim;//Men�ye d�nmek i�in kulland���m de�i�ken
	ofstream yaz("KargoNerede.txt", ios::app);//Kay�t dosyas�n� KargoNerede.txt ad�nda olu�turacak komut
	cout << "Kargo Nerede......:";
	cin >> kn.nerede;
	cout << "Teslimat Durumu...:";
	cin >> kn.teslim;
	yaz << kn.nerede << " " << kn.teslim << " " << k.fatura_no << endl;//Girdi�im bilgileri KargoNerede.txt dosyas�na yazan komut
	yaz.close();//Kay�t yap�lan dosyay� kapat�yor
	cout << "-----------------------------------------------------------" << endl;
	cout << "Kay�t Yaz�ld�" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "Ba�ka Bir ��lem Yapmak �stermisiniz?(E/H)--->";
	cin >> secim;
	if (secim == 'e' || secim == 'E') Menu();//Men�ye devam etmek i�in gerekli yap�
	else exit(0);//Haz�r fonksiyon uygulamadan ��k�yor
}

//Kargo durumu kay�t� okuma fonksiyonu
void KargoNerede::KargoNeredeOku() {
	int kontrol = 0;//Girilen fatura numaras�n�n e�itli�ini kontrol eden de�i�ken ve ilk de�eri
	char secim;//Men�ye d�nmek i�in kulland���m de�i�ken
	ifstream oku("KargoNerede.txt");//KargoNerede.txt dosyas�n� okumak i�in gerekli komut
	string temp;//temp fatura numaras�n� e�lemek i�in kullan�lan de�i�ken
	cout << "-----------------------------------------------------------" << endl;
	cout << "G�r�nt�lemek �stediginiz Kargo Durumunun Fatura No:";
	cin >> temp;
	while (!oku.eof())//KargoNerede.txt dosyas� a��k oldu�u s�re boyunca blok i�erisindeki i�lemler ger�ekle�ecek
	{
		oku >> kn.nerede >> kn.teslim >> k.fatura_no;//KargoNerede.txt dosyas�ndaki kay�tlar� okuyan komut
		if (temp == k.fatura_no)//temp ve fatura numaras� e�it ise ger�ekle�ecek i�lem
		{
			kontrol = 1;//temp ile fatura numaras� e�it ise kontrol de�i�keninin de�erini de�i�tiriyorum
			cout << "-----------------------------------------------------------" << endl;
			cout << "Arad���n�z Kay�t" << endl;
			cout << "-----------------------------------------------------------" << endl;
			cout << "Kargo Nerede......:" << kn.nerede << endl;
			cout << "Teslimat Durumu...:" << kn.teslim << endl;
			break;
		}
	}
	if (kontrol == 0) //Kontrol de�i�keni de�i�memi� ise ger�ekle�ecek i�lem
	{
		cout << "------------------------------------------------------" << endl;
		cout << "Kay�t Bulunamad�" << endl;
	}

	oku.close();//Okunan dosyay� kapat�yorum
	cout << "------------------------------------------------------" << endl;
	cout << "Ba�ka Bir ��lem Yapmak �stermisiniz?(E/H)" << "--->";
	cin >> secim;
	if (secim == 'e' || secim == 'E') Menu();//Men�ye devam etmek i�in gerekli yap�
	else exit(0);//Haz�r fonksiyon uygulamadan ��k�yor
}

//Kargo durumu kay�t� g�ncelleme fonksiyonu
void KargoNerede::KargoNeredeGuncelle() {
	int kontrol = 0;//Girilen fatura numaras�n�n e�itli�ini kontrol eden de�i�ken ve ilk de�eri
	char secim;//Men�ye d�nmek i�in kulland���m de�i�ken
	string temp, temp1;//temp fatura numaras�n� e�lemek i�in kullan�lan de�i�ken, temp1 iki kere i�lemin ger�ekle�mesini engellemek i�in kullan�lan de�i�ken
	cout << "-----------------------------------------------------------" << endl;
	cout << "G�ncellemek �stedi�iniz Kargo Durumunun Fatura No:";
	cin >> temp;
	ofstream gecici("gecici.txt");//KargoNerede.txt nin bilgilerini aktarmak i�in gecici.txt olarak olu�turdugum dosya ve yazd�rma komutu
	ifstream oku("KargoNerede.txt");//KargoNerede.txt dosyas�ndaki kay�tlar� okumak i�in gerekli komut
	while (!oku.eof()) //KargoNerede.txt dosyas� a��k oldu�u s�re boyunca ger�ekl�ecek i�lem
	{
		oku >> kn.nerede >> kn.teslim >> k.fatura_no;//KargoNerede.txt dosyas�ndaki kay�tlar� okuyan komut
		if (temp1 != k.fatura_no)// temp1 ve fatura numaras� farkl�ysa i�erdeki i�lemi ger�ekle�tirecek bunun amac� iki kere bu i�lemin ger�ekle�mesini engelleme
		{
			if (k.fatura_no == temp) //temp ve fatura no e�le�irse bu blok i�indeki i�lem ger�ekele�ecek 
			{
				kontrol = 1;//Kontrol de�i�keninin de�erini de�i�tiriyorum
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kay�ttaki Bilgileriniz" << endl;
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
				gecici << kn.nerede << " " << kn.teslim << " " << k.fatura_no << endl;//Yeni bilgileri dosyaya yaz�yor
			}
			else {
				gecici << k.fatura_no << " " << kn.nerede << " " << kn.teslim << endl;//Dosyadaki di�er kay�tlar� gecici.txt dosyas�na yazd�r�yor
			}
			if (kontrol == 1) //Kontrol de�i�keninin de�eri de�i�mi�se ger�ekle�ecek i�lem
			{
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kay�t G�ncellendi" << endl;
				cout << "-----------------------------------------------------------" << endl;
			}
			else //Kontrol de�i�keninin de�eri de�i�mezse ger�ekle�ecek i�lem
			{
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kay�t Bulunamad�" << endl;
				cout << "-----------------------------------------------------------" << endl;
			}
		}
		temp1 = k.fatura_no;//Bir kere e�itlenme olup i�lemler ger�ekle�ince temp1'e fatura numaras�n� aktar�yorum
	}//Burada ger�ekle�tirdi�im i�lem fatura numaras� e�itlenen kay�t�n mevcut bilgilerini g�r�nt�l�yor ve yeni bilgileri girerek gecici.txt dosyas�na yazd�r�yorum.E�itlenme olmayan yani di�er kay�tlar direk gecici.txt dosyas�na yazd�r�l�yor

	gecici.close();//KargoNerede.txt'deki kay�tlar� aktarmak i�in a�t���m gecici.txt adl� dosyay� kapat�yorum
	oku.close();//Okunan KargoNerede.txt adl� dosyay� kapat�yorum 
	remove("KargoNerede.txt");//KargoNerede.txt dosyas�n� siliyorum
	rename("gecici.txt", "KargoNerede.txt");//KargoNerede.txt yerine a�t���m gecici.txt dosyas�n�n ad�n� KargoNerede.txt yap�yorum
	cout << "Ba�ka Bir ��lem Yapmak �stermisiniz?(E/H)" << "--->";
	cin >> secim;
	if (secim == 'e' || secim == 'E') Menu();//Men�ye devam etmek i�in gerekli yap�
	else exit(0);//Haz�r fonksiyon uygulamadan ��k�yor
}

//Men� fonksiyonu
void Menu() {
	system("cls");//Ekran temizleme komutu her men�ye geldi�imde ekran� temizliyor
	int secim;//Men�deki i�lemlerde se�im yapmak i�in tan�mlad��m de�i�ken
	cout << "--------------------------------" << endl;
	cout << "-----Kargo Takip Otomasyonu-----" << endl;
	cout << "--------------------------------" << endl;
	cout << "Yapmak �stedi�iniz ��lemi Se�in" << endl;
	cout << "--------------------------------" << endl;
	cout << "1-Kargo Kay�t Giri�i" << endl;
	cout << "2-Kargo Bilgisi G�r�nt�leme" << endl;
	cout << "3-Kargo Bilgisi G�ncelleme" << endl;
	cout << "4-Kargo Durumu G�r�nt�leme" << endl;
	cout << "5-Kargo Durumu G�ncelleme" << endl;
	cout << "6-Kargo Kay�t� Silme" << endl;
	cout << "7-Uygulamadan ��k��" << endl;
	cout << "--------------------------------" << endl;
	cout << "Se�iminiz:";
	cin >> secim;
	system("cls");//ekran temizleme komutu
	switch (secim)//Men�deki se�im i�in swcith case yap�s�n� kulland�m
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
	setlocale(LC_ALL, "Turkish");//T�rk�e karakter i�in yapt���m tan�mlama

	Kargo k;//kargo class'�n� tan�mas� i�in yapt���m tan�mlama
	KargoNerede kn;//kargonerede class'�n� tan�mas� i�in yapt���m tan�mlama
	Menu();//Menu fonksiyonunun �al��mas� i�in yapt��m tan�mlama

	system("pause");
	return 0;
}

