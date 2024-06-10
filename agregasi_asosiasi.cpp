#include <iostream>
#include <vector>
using namespace std;

class Proyek;
class Karyawan {
public:
	string nama;
	vector<Proyek*> daftar_proyek;
	Karyawan(string pNama) :nama(pNama) {
		cout << "Karyawan\"" << nama << "\" ada\n";
	}
	~Karyawan() {
		cout << "Karyawan\"" << nama << "\" tidak ada\n";
	}
	void tambahProyek(Proyek*);
	void cetakProyek();
};
class Proyek {
public:
	string nama;
	vector<Karyawan*> daftar_karyawan;
	Proyek(string pNama) :nama(pNama) {
		cout << "Proyek\"" << nama << "\" ada\n";
	}
	~Proyek() {
		cout << "Proyek \"" << nama << "\" tidak ada\n";
	}
	void tambahKaryawan(Karyawan*);
	void cetakKaryawan();

};

void Karyawan::tambahProyek(Proyek* pProyek) {
	daftar_proyek.push_back(pProyek);
}

void Karyawan::cetakProyek() {
	cout << "Daftar Proyek\"" << this->nama << "\":\n";
	for (auto& a : daftar_proyek) { 
		cout << a->nama << "\n";
	}
	cout << endl;
}

void Proyek::tambahKaryawan(Karyawan* pKaryawan) {
	daftar_karyawan.push_back(pKaryawan);
	pKaryawan->tambahProyek(this);
}

void Proyek::cetakKaryawan() {
	cout << "Daftar Karyawan\"" << this->nama << "\":\n";
	for (auto& a : daftar_karyawan) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

int main() {
	Proyek* varProyek1 = new Proyek("Sistem Informasi");
	Proyek* varProyek2 = new Proyek("Sistem Keamanan");
	Karyawan* varKaryawan1 = new Karyawan("Fachri");
	Karyawan* varKaryawan2 = new Karyawan("Ryan");

	varProyek1->tambahKaryawan(varKaryawan1);
	varProyek1->tambahKaryawan(varKaryawan2);
	varProyek2->tambahKaryawan(varKaryawan1);

	varProyek1->cetakKaryawan();
	varProyek2->cetakKaryawan();
	varKaryawan1->cetakProyek();
	varKaryawan2->cetakProyek();

	delete varKaryawan1;
	delete varKaryawan2;
	delete varProyek1;
	delete varProyek2;

	return 0;
}