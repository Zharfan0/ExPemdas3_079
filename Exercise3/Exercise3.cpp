#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pengarang; // Deklarasi sebelum kelas Penerbit

class Penerbit {
public:
    Penerbit(const string& nama) : namaPenerbit(nama) {}

    string getNamaPenerbit() const {
        return namaPenerbit;
    }

    void tambahkanPengarang(Pengarang* pengarang) {
        pengarangDinaungi.push_back(pengarang);
    }

    vector<Pengarang*> getPengarangDinaungi() const {
        return pengarangDinaungi;
    }

private:
    string namaPenerbit;
    vector<Pengarang*> pengarangDinaungi;
};

class Pengarang {
public:
    Pengarang(const string& nama) : namaPengarang(nama) {}

    string getNamaPengarang() const {
        return namaPengarang;
    }

    void tambahkanPenerbit(Penerbit* penerbit) {
        penerbitDinaungi.push_back(penerbit);
    }

    void tambahkanBuku(const string& judul) {
        bukuDikarang.push_back(judul);
    }

    vector<Penerbit*> getPenerbitDinaungi() const {
        return penerbitDinaungi;
    }

    vector<string> getBukuDikarang() const {
        return bukuDikarang;
    }

private:
    string namaPengarang;
    vector<Penerbit*> penerbitDinaungi;
    vector<string> bukuDikarang;
};

int main() {
    Penerbit gamaPress("Gama Press");
    Penerbit intanPariwara("Intan Pariwara");

    Pengarang joko("Joko");
    Pengarang lia("Lia");
    Pengarang giga("Giga");
    Pengarang asroni("Asroni");

    gamaPress.tambahkanPengarang(&joko);
    gamaPress.tambahkanPengarang(&lia);
    gamaPress.tambahkanPengarang(&giga);

    intanPariwara.tambahkanPengarang(&giga);
    intanPariwara.tambahkanPengarang(&asroni);

    joko.tambahkanPenerbit(&gamaPress);
    joko.tambahkanBuku("Fisika");
    joko.tambahkanBuku("Algoritma");

    lia.tambahkanPenerbit(&gamaPress);
    lia.tambahkanBuku("Basisdata");

    giga.tambahkanPenerbit(&gamaPress);
    giga.tambahkanPenerbit(&intanPariwara);
    giga.tambahkanBuku("Matematika");
    giga.tambahkanBuku("Multimedia 1");

    asroni.tambahkanPenerbit(&intanPariwara);
    asroni.tambahkanBuku("Dasar Pemrograman");

    // Menampilkan daftar pengarang pada penerbit "Gama Press"
    cout << "Daftar pengarang pada penerbit \"Gama Press\":" << endl;
    for (const auto& pengarang : gamaPress.getPengarangDinaungi()) {
        cout << pengarang->getNamaPengarang() << endl;
    }
    cout << endl;

    // Menampilkan daftar pengarang pada penerbit "Intan Pariwara"
    cout << "Daftar pengarang pada penerbit \"Intan Pariwara\":" << endl;
    for (const auto& pengarang : intanPariwara.getPengarangDinaungi()) {
        cout << pengarang->getNamaPengarang() << endl;
    }
    cout << endl;

    // Menampilkan daftar penerbit yang diikuti "Giga"
    cout << "Daftar penerbit yang diikuti \"Giga\":" << endl;
    for (const auto& penerbit : giga.getPenerbitDinaungi()) {
        cout << penerbit->getNamaPenerbit() << endl;
    }
    cout << endl;

    // Menampilkan daftar buku yang dikarang "Joko"
    cout << "Daftar buku yang dikarang \"Joko\":" << endl;
    for (const auto& buku : joko.getBukuDikarang()) {
        cout << buku << endl;
    }
    cout << endl;

    // Menampilkan daftar buku yang dikarang "Lia"
    cout << "Daftar buku yang dikarang \"Lia\":" << endl;
    for (const auto& buku : lia.getBukuDikarang()) {
        cout << buku << endl;
    }
    cout << endl;

    // Menampilkan daftar buku yang dikarang "Asroni"
    cout << "Daftar buku yang dikarang \"Asroni\":" << endl;
    for (const auto& buku : asroni.getBukuDikarang()) {
        cout << buku << endl;
    }
    cout << endl;

    // Menampilkan daftar buku yang dikarang "Giga"
    cout << "Daftar buku yang dikarang \"Giga\":" << endl;
    for (const auto& buku : giga.getBukuDikarang()) {
        cout << buku << endl;
    }
    cout << endl;

    return 0;
}
