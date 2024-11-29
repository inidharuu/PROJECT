#include <bits/stdc++.h>
using namespace std;

class Pasien;
class Antrian;
class Dokter;
class Pendaftaran;
class Penyakit;
class Pembayaran;
class Kefokusan;
class Spesialisasi;

class MainApp
{
private:
    vector<shared_ptr<Pasien>> dataPasien;
    vector<shared_ptr<Pendaftaran>> Daftar;
    vector<shared_ptr<Penyakit>> dataPenyakit;
    vector<shared_ptr<Pembayaran>> Payment;
    vector<shared_ptr<Dokter>> dataDokter;
    vector<shared_ptr<Kefokusan>> keFokusan;
    vector<shared_ptr<Spesialisasi>> Spesialis;

public:
    MainApp();
    void addPasien(const string &name, int age, const string tempatTinggal, const string gender);
    void addPendaftaran(const time_t &tanggalDaftar, string const &keperluan, string const &tanggalDatang);
    void addPenyakit(const string &penyakit);
    void addPembayaran(const string &payment, const string &bank, int noRek, const string &namaPemilik, int noBPJS);
    void addDokter(const string &nama, const string &jabatan, int NIP);
    void addSpesialis(const string &spesialis);
    void addKefokusan(const string &kefokusan);
    void inputPasien();
    void inputPendaftaran();
    void inputPenyakit();
    void inputPembayaran();
    void inputDokter();
    void inputSpesialis();
    void inputKefokusan();
    void displayPasien() const;
    void displayPendaftaran() const;
    void displayPenyakit() const;
    void displayPembayaran() const;
    void displayDokter() const;
    void displayKefokusan() const;
    void displaySpesialis() const;
    void getData(string &Data);
};

MainApp::MainApp() : dataPasien(), Daftar(), dataDokter(), dataPenyakit(), Payment(), keFokusan(), Spesialis() {}

/*========== CLASS PASIEN ==========*/
class Pasien
{
private:
    string Nama;
    int Umur;
    string TempatTinggal;
    string Kelamin;

public:
    Pasien(const string name, int age, const string tempatTinggal, const string gender);

    void displayPasien() const;
};

/*========== MAIN PASIEN ==========*/

void MainApp::addPasien(const string &name, int age, const string tempatTinggal, const string gender)
{
    dataPasien.push_back(make_shared<Pasien>(name, age, tempatTinggal, gender));
}

void MainApp::inputPasien()
{
    string name, tempatTinggal, gender;
    int age;

    cout << "Masukkan nama pasien: ";
    getline(cin, name);
    cout << "Masukkan umur pasien: ";
    cin >> age;
    cin.ignore();
    cout << "Masukkan tempat tinggal pasien: ";
    getline(cin, tempatTinggal);
    cout << "Masukkan jenis kelamin pasien: ";
    getline(cin, gender);

    addPasien(name, age, tempatTinggal, gender);
}

void MainApp::displayPasien() const
{
    for (const auto &pasien : dataPasien)
    {
        pasien->displayPasien();
    }
}

Pasien::Pasien(const string name, int age, const string tempatTinggal, const string gender)
    : Nama(name), Umur(age), TempatTinggal(tempatTinggal), Kelamin(gender) {}

void Pasien::displayPasien() const
{
    ofstream dataBase;

    dataBase.open("daBasePasien.txt", ios::app);

    dataBase << "Nama\t\t\t: " << Nama << endl;
    dataBase << "Umur\t\t\t: " << Umur << endl;
    dataBase << "Tempat tinggal\t: " << TempatTinggal << endl;
    dataBase << "Kelamin\t\t\t: " << Kelamin << endl;
    dataBase.close();
}

/*========== CLASS PENDAFTARAN ==========*/
class Pendaftaran
{
private:
    time_t TanggalDaftar;
    string Keperluan;
    string TanggalDatang;

public:
    Pendaftaran(time_t tanggalDaftar, string const &keperluan, string const &tanggalDatang);
    void displayPendaftaran() const;
};

/*========== MAIN PENDAFTARAN ==========*/

/*========== CLASS PENYAKIT ==========*/
class Penyakit
{
private:
    string penyakit;

public:
    Penyakit(const string &disease);

    void displayPenyakit() const;
};

/*========== MAIN PENYAKIT ==========*/

void MainApp::addPenyakit(const string &penyakit)
{
    dataPenyakit.push_back(make_shared<Penyakit>(penyakit));
}

void MainApp::inputPenyakit()
{
    string penyakit;

    cout << "\n=> Umum" << endl;
    cout << "=> Internis" << endl;
    cout << "Pilih penyakit anda: ";
    cin >> penyakit;
    cin.ignore();

    if (penyakit != "Umum" && penyakit != "umum" && penyakit != "Internis" && penyakit != "internis")
    {
        cout << "\nPenyakit tidak ditemukan" << endl;
        terminate();
    }
    else
    {
    }

    addPenyakit(penyakit);
}

void MainApp::displayPenyakit() const
{

    for (const auto &penyakit : dataPenyakit)
    {
        penyakit->displayPenyakit();
    }
}

Penyakit::Penyakit(const string &disease)
    : penyakit(disease) {}

void Penyakit::displayPenyakit() const
{
    ofstream dataBase;

    dataBase.open("daBasePasien.txt", ios::app);
    dataBase << "Penyakit\t\t: " << penyakit << endl;
    dataBase.close();
}

/*========== CLASS PEMBAYARAN ==========*/
class Pembayaran
{
private:
    string jenisPembayaran;
    string bank;
    int NoRek;
    string NamaPemilik;
    int NoBPJS;

public:
    Pembayaran(const string &payment, const string &bank, int noRek, const string &namaPemilik, int noBPJS);

    void displayPembayaran() const;
};

/*========== MAIN PEMBAYARAN ==========*/

void MainApp::addPembayaran(const string &pembayaran, const string &bank, int noRek, const string &namaPemilik, int noBPJS)
{
    Payment.push_back(make_shared<Pembayaran>(pembayaran, bank, noRek, namaPemilik, noBPJS));
}

void MainApp::inputPembayaran()
{
    string payment, Bank, namaPemilik;
    int noRek, noBPJS;

    cout << "\n=> Pribadi" << endl;
    cout << "=> Asuransi" << endl;
    cout << "Pilih jenis pembayaran anda: ";
    cin >> payment;
    cin.ignore();

    if (payment == "Pribadi" || payment == "pribadi")
    {
        cout << "Masukkan Bank: ";
        getline(cin, Bank);
        cout << "Masukkan Nomor Rekening: ";
        cin >> noRek;
        cin.ignore();
        cout << "Masukkan Nama Pemilik Rekening: ";
        getline(cin, namaPemilik);
    }
    else if (payment == "Asuransi" || payment == "asuransi")
    {
        cout << "Masukkan Nomor BPJS: ";
        cin >> noBPJS;
        cin.ignore();
    }
    else
    {
        cout << "Opsi pembayaran tidak tersedia";
    }
    addPembayaran(payment, Bank, noRek, namaPemilik, noBPJS);
}

void MainApp::displayPembayaran() const
{
    for (const auto &pembayaran : Payment)
    {
        pembayaran->displayPembayaran();
    }
}

Pembayaran::Pembayaran(const string &payment, const string &Bank, int noRek, const string &namaPemilik, int noBPJS)
    : jenisPembayaran(payment), bank(Bank), NoRek(noRek), NamaPemilik(namaPemilik), NoBPJS(noBPJS) {}

void Pembayaran::displayPembayaran() const
{
    ofstream dataBase;

    dataBase.open("daBasePasien.txt", ios::app);

    dataBase << "Pembayaran\t\t: " << jenisPembayaran << endl;
    dataBase << "Bank\t\t\t: " << bank << endl;
    dataBase << "Nomor Rekening\t: " << NoRek << endl;
    dataBase << "Nama Pemilik\t: " << NamaPemilik << endl;
    dataBase << "Nomor BPJS\t\t: " << NoBPJS << endl
             << endl;
}

/*========== CLASS DOKTER ==========*/
class Dokter
{
private:
    string Nama;
    string Pangkat;
    int NIP;

public:
    Dokter(const string nama, const string jabatan, int NIP);

    void displayDokter() const;
};

/*========== MAIN DOKTER ==========*/

void MainApp::addDokter(const string &nama, const string &jabatan, int NIP)
{
    dataDokter.push_back(make_shared<Dokter>(nama, jabatan, NIP));
}

void MainApp::inputDokter()
{
    string Nama, Jabatan;
    int NIP;

    cout << "Masukkan nama Dokter: ";
    getline(cin, Nama);
    cout << "Masukkan pangkat Dokter: ";
    getline(cin, Jabatan);
    cout << "Masukkan NIP Dokter: ";
    cin >> NIP;
    cin.ignore();

    addDokter(Nama, Jabatan, NIP);
}

void MainApp::displayDokter() const
{
    cout << "\nCurrent Doctors: " << endl;
    for (const auto &dokter : dataDokter)
    {
        dokter->displayDokter();
    }
}

Dokter::Dokter(const string nama, const string jabatan, int NIP)
    : Nama(nama), Pangkat(jabatan), NIP(NIP) {}

void Dokter::displayDokter() const
{
    ofstream dataBase;

    dataBase.open("daBaseDokter.txt", ios::app);
    dataBase << "Nama\t\t: " << Nama << endl;
    dataBase << "Pangkat\t\t: " << Pangkat << endl;
    dataBase << "NIP\t\t: " << NIP << endl;
}

/*========== CLASS SPESIALISASI ==========*/
class Spesialisasi
{
private:
    string spesialisasi;

public:
    Spesialisasi(const string &spesialis);
    void displaySpesialis() const;
};

/*========== MAIN SPESIALISASI ==========*/
void MainApp::addSpesialis(const string &spesialis)
{
    Spesialis.push_back(make_shared<Spesialisasi>(spesialis));
}

void MainApp::inputSpesialis()
{
    string spesialis;
    cout << "Masukkan Spesialisasi: ";
    getline(cin, spesialis);

    addSpesialis(spesialis);
}

void MainApp::displaySpesialis() const
{
    cout << "\nCurrent Specialization: " << endl;
    for (const auto &spesialis : Spesialis)
    {
        spesialis->displaySpesialis();
    }
}

Spesialisasi::Spesialisasi(const string &spesialis)
    : spesialisasi(spesialis) {}

void Spesialisasi::displaySpesialis() const
{
    ofstream dataBase;

    dataBase.open("daBaseDokter.txt", ios::app);
    dataBase << "Spesialis\t: " << spesialisasi << endl;
}

/*========== CLASS KEFOKUSAN ==========*/
class Kefokusan
{
private:
    string keFokusan;

public:
    Kefokusan(const string &kefokusan);
    void displayKefokusan() const;
};

/*========== MAIN KEFOKUSAN ==========*/
void MainApp::addKefokusan(const string &kefokusan)
{
    keFokusan.push_back(make_shared<Kefokusan>(kefokusan));
}

void MainApp::inputKefokusan()
{
    string kefokusan;

    cout << "\n=> Umum" << endl;
    cout << "=> Spesialis" << endl;
    cout << "Masukkan Kefokusan: ";
    getline(cin, kefokusan);

    if (kefokusan == "Umum" || kefokusan == "umum")
    {
        cout << "Status: Dokter Umum" << endl;
    }
    else if (kefokusan == "Spesialis" || kefokusan == "spesialis")
    {
        inputSpesialis();
    }
    else
    {
        cout << "\nKefokusan tidak ditemukan" << endl;
        terminate();
    }

    addKefokusan(kefokusan);
}

void MainApp::displayKefokusan() const
{
    for (const auto &focus : keFokusan)
    {
        focus->displayKefokusan();
    }
}

Kefokusan::Kefokusan(const string &kefokusan)
    : keFokusan(kefokusan) {}

void Kefokusan::displayKefokusan() const
{
    ofstream dataBase;

    dataBase.open("daBaseDokter.txt", ios::app);
    dataBase << "Kefokusan\t: " << keFokusan << endl;
}

/*========== FUNGSI FORMULIR ==========*/
void MainApp::getData(string &Data)
{
    ifstream daBasePasien(Data);
    MainApp klinik;
    
    string line, name, tempatTinggal, gender, penyakit, payment, bank, namaPemilik;
    int age, noRek, noBPJS;

    while (getline(daBasePasien, line))
    {
        if (line.find("Nama") == 0)
        {
            name = line.substr(line.find(":") + 2);
        }
        else if (line.find("Umur") == 0)
        {
            age = stoi(line.substr(line.find(":") + 2));
        }
        else if (line.find("Tempat tinggal") == 0)
        {
            tempatTinggal = line.substr(line.find(":") + 2);
        }
        else if (line.find("Kelamin") == 0)
        {
            gender = line.substr(line.find(":") + 2);
        }
        else if (line.find("Penyakit") == 0)
        {
            penyakit = line.substr(line.find(":") + 2);
        }
        else if (line.find("Pembayaran") == 0)
        {
            payment = line.substr(line.find(":") + 2);
        }
        else if (line.find("Bank") == 0)
        {
            bank = line.substr(line.find(":") + 2);
        }
        else if (line.find("No Rekening") == 0)
        {
            noRek = stoi(line.substr(line.find(":") + 2));
        }
        else if (line.find("Nama Pemilik") == 0)
        {
            namaPemilik = line.substr(line.find(":") + 2);
        }
        else if (line.find("No BPJS") == 0)
        {
            noBPJS = stoi(line.substr(line.find(":") + 2));
        }
        if (!name.empty())
        {
            addPasien(name, age, tempatTinggal, gender);
            addPenyakit(penyakit);
            addPembayaran(payment, bank, noRek, namaPemilik, noBPJS);
        }

        daBasePasien.close();

        cout << Data << endl;

        klinik.getData(Data);
        klinik.displayPasien();
        klinik.displayPenyakit();
        klinik.displayPembayaran();
    }
}

int main(int argc, char const *argv[])
{
    MainApp klinik;
    char pilut, pildok;
    string passwordAdmin, passwordDokter;
    passwordAdmin = "KlinikSehat24%";
    string GetData;

    cout << "=========== SELAMAT DATANG =========" << endl;
    cout << "===== DI APLIKASI KLINIK SEHAT =====" << endl;
    cout << "\nA. Pasien" << endl;
    cout << "B. Dokter" << endl;
    cout << "Anda sebagai: ";
    cin >> pilut;
    cin.ignore();

    if (pilut == 'A')
    {
        klinik.inputPasien();
        klinik.inputPenyakit();
        klinik.inputPembayaran();
        klinik.displayPasien();
        klinik.displayPenyakit();
        klinik.displayPembayaran();
        klinik.getData(GetData);
    }
    else if (pilut == 'B')
    {
        cout << "Masukkan Password: ";
        cin >> passwordDokter;
        cin.ignore();
        if (passwordDokter == passwordAdmin)
        {
            do
            {
                klinik.inputDokter();
                klinik.inputKefokusan();
                cout << "\nApakah ingin menambahkan Dokter lagi? (Y/N): ";
                cin >> pildok;
                cin.ignore();
            } while (pildok == 'Y');

            klinik.displayDokter();
            klinik.displayKefokusan();
        }
        else
        {
            cout << "Password anda salah!" << endl;
        }
    }

    return 0;
};
