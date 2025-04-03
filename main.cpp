#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Personel {
private:
	int numara;
	string isim;
	string soyisim;
	string departman;
	char cinsiyet;
public:
	Personel(int num,string name,string sname,string dep,char cins){
		numara = num;
		isim = name;
		soyisim = sname;
		departman = dep;
		cinsiyet = cins;
	}

<<<<<<< HEAD
=======
	int count = 0;

	void setCount(int& count) {
		count++;
	}

>>>>>>> c87bec497b888f494774c7c7be3f73099f7c69dc
	int getNumara() const {
		return numara;
	}

	string getIsim() const {
		return isim;
	}

	string getSoyIsim() const {
		return soyisim;
	}

	string getDepartman () const {
		return departman;
	}

	char getCinsiyet() const {
		return cinsiyet;
	}

	void setNumara(int n) {
		numara = n;
	}

	void setIsim(string i) {
		isim = i;
	}

	void setSoyIsim(string s) {
		soyisim = s;
	}

	void setDepartman(string d) {
		departman = d;
	}

	void setCinsiyet(char c) {
		cinsiyet = c;
	}

	void printPersonel () const {
		cout << numara << " || " << isim << " || " << soyisim << " || " << departman << " || " << cinsiyet << endl;
	}
};

static bool cinsiyetKontrol(char a) {
	if (a != 'E' && a != 'K') {
		cout << "Cinsiyet yalnizca E veya K formatinda girilebilir" << endl;
		return false;
	}
	return true;
}

static bool numaraKontrol(int a) {
	if (a < 0 || a > 1000) {
		cout << "Numara 0 ile 1000 arasinda olmalidir" << endl;
		return false;
	}
	return true;
}

static void addPersonel(vector<Personel>& personel) {
<<<<<<< HEAD
	int no = 0;
=======
	int no=0;
>>>>>>> c87bec497b888f494774c7c7be3f73099f7c69dc
	string isim, soyisim, departman;
	char cinsiyet;

	do {
		cout << "Personel No (0-1000): ";
		cin >> no;
		cin.ignore();
	} while (!numaraKontrol(no));

	cout << "Personel Isim: ";
	cin >> isim;

	cout << "Personel Soyisim: ";
	cin >> soyisim;

	cout << "Personel Departman: ";
	cin >> departman;

	do {
		cout << "Personel Cinsiyet (E/K): ";
		cin >> cinsiyet;
	} while (!cinsiyetKontrol(cinsiyet));

	personel.push_back(Personel(no, isim, soyisim, departman, cinsiyet));
	cout << " Personel Basariyla Eklendi.";
}

static void delPersonel(vector<Personel>& personel) {
	int no = 0;
	cout << "Silmek istediginiz personelin numarasini giriniz";
	cin >> no;

	for (int i = 0; i < personel.size(); i++) {
		if (personel[i].getNumara() == no) {
			cout << "\n Aradiginiz personel listede mevcut \n";
			personel[i].printPersonel();
			cout << no <<" Numarali personel siliniyor...\n";
			personel.erase(personel.begin() + i);
			return;
		}
	}
	cout << "Bu numaraya ait personel bulunamadi\n";
}

static void searchPersonel(const vector<Personel>& personel) {
	int no = 0;
	cout << "Aramak istediginiz personelin numarasini giriniz";
	cin >> no;

	for (int i = 0; i < personel.size(); i++) {
		if (personel[i].getNumara() == no) {
			cout << "\n Aradiginiz personel listede mevcut \n";
			cout << no << " Numarali personel Listeleniyor...\n";
		}
	}
	cout << "Bu numaraya ait personel bulunamadi\n";
}

static void listPersonel(const vector<Personel>& personel)  {
	cout << "\n Personeller Listeleniyor... \n";
	for (int i = 0; i < personel.size(); i++) {
		personel[i].printPersonel();
	}
}

static void sendDatabase(const vector<Personel>& personel) {
	ofstream yaz;
	yaz.open("database.txt", ios::app);
	for (int i = 0; i < personel.size(); i++) {
		yaz << personel[i].getNumara() << " " << personel[i].getIsim() << " "
			<< personel[i].getSoyIsim() << " " << personel[i].getDepartman() << " "
			<< personel[i].getCinsiyet() << endl;
	}
	yaz.close();
	cout << " Adet yeni personel listeye basariyla eklendi. \n";
}

static void listFromDatabase(vector<Personel>& personel) {
	int no = 0;
	string isim, soyisim, departman;
	char cinsiyet = 0;
	ifstream oku;
	oku.open("database.txt", ios::app);
	while (oku >> no >> isim >> soyisim >> departman >> cinsiyet) {
		cout << no << " " << isim << " " << soyisim << " " << departman << " " << cinsiyet << endl;
	}
	oku.close();
}

static void searchFromDatabase(vector<Personel>& personel) {
	int no = 0;
	bool flag = false;
	cout << "Aramak istediginiz personelin numarasini giriniz: ";
	cin >> no;
	int checkno=0;
	string isim, soyisim, departman;
	char cinsiyet = 0;
	ifstream oku;
	oku.open("database.txt", ios::app);
	while (oku >> checkno >> isim >> soyisim >> departman >> cinsiyet) {
		if (no == checkno) {
			cout << "Aradiginiz personel bulundu \n";
			cout << checkno << " " << isim << " " << soyisim << " " << departman << " " << cinsiyet << endl;
			flag = true;
			break;
		}
	}
	if (flag == false) {
		cout << "Aradiginiz personel bulunamadi\n";
	}
	oku.close();
}

static void deleteFromDatabase(vector<Personel>& personel) {
	int no = 0;
	cout << "Silmek istediginiz personelin numarasini giriniz: ";
	cin >> no;

	ifstream oku("database.txt");
	ofstream gecici("gecici.txt");

	int checkno;
	string isim, soyisim, departman;
	char cinsiyet;
	bool bulundu = false;

	while (oku >> checkno >> isim >> soyisim >> departman >> cinsiyet) {
		if (checkno == no) {
			bulundu = true;
			cout << "Personel siliniyor: " << checkno << " " << isim << " " << soyisim << " " << departman << " " << cinsiyet << endl;
		} else {
			gecici << checkno << " " << isim << " " << soyisim << " " << departman << " " << cinsiyet << endl;
		}
	}

	oku.close();
	gecici.close();

	remove("database.txt");
	if (rename("gecici.txt", "database.txt") != 0) {
		perror("Dosya yeniden adlandirilamadi");
	}

	if (!bulundu) {
		cout << "Bu numaraya ait personel bulunamadi\n";
	}
}
	


int main() {
	vector<Personel> vPersonel;
	int secim = 0;
<<<<<<< HEAD
	int count = 0;
=======
>>>>>>> c87bec497b888f494774c7c7be3f73099f7c69dc

	do {
		cout << "\n ---- Personel Yonetim Sistemi ---- \n";
		cout << "1. Yeni Personel Ekle \n";
		cout << "2. Yeni Eklenen Personelleri Listele \n";
		cout << "3. Yeni Eklenen Personel Ara \n";
		cout << "4. Yeni Eklenen Personel Sil \n";
		cout << "5. Degisiklikleri Veritabanina Aktar \n";
		cout << "6. Veritabanindaki Personelleri Listele \n";
		cout << "7. Veritabaninda Personel Ara \n";
		cout << "8. Veritabanindan Personel Sil \n";
<<<<<<< HEAD
		cout << count << " Adet yeni personel kaydi veritabanina gitmeyi bekliyor \n";
=======
>>>>>>> c87bec497b888f494774c7c7be3f73099f7c69dc
		cout << "Seciminizi Yapin: ";
		cin >> secim;

		switch (secim) {
		case 1:
			addPersonel(vPersonel);
<<<<<<< HEAD
			count++;
=======
>>>>>>> c87bec497b888f494774c7c7be3f73099f7c69dc
			break;
		case 2:
			listPersonel(vPersonel);
			break;
		case 3:
			searchPersonel(vPersonel);
			break;
		case 4:
			delPersonel(vPersonel);
			break;
		case 5:
			sendDatabase(vPersonel);
<<<<<<< HEAD
			count = 0;
=======
>>>>>>> c87bec497b888f494774c7c7be3f73099f7c69dc
			break;
		case 6:
			listFromDatabase(vPersonel);
			break;
		case 7:
			searchFromDatabase(vPersonel);
			break;
		case 8:
			deleteFromDatabase(vPersonel);
			break;
		}
	} while (secim != 9);

	return 0;
}
