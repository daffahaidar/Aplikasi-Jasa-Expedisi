// kalo tampilannya outputnya acak acakan coba maximize output cmd nya 

#include <iostream> // untuk cin dan cout
#include <conio.h>  // untuk getch
#include <string>   // untuk manipulasi string
#include <string.h> // sama untuk manipulasi string cuma pake library bahasa C
#include <ctime>    // untuk mengambil waktu dipakai dalam fungsi random
#include <cstdlib> // kalo di devc++ harus pake library ini (kalo di visual studio code hapus aja soalnya vscode udh pake c++ versi terbaru)

using namespace std; // biar gk usah ngetik std:: nantinya

// struktur data
struct node // aku kasih aja namanya node
{
    char id[7];       // untuk menyimpan resi expedisi
    char nama[50];    // untuk menyimpan nama expedisi
    char alamat[100]; // untuk menyimpan alamat expedisi
    char no_hp[16];   // untuk menyimpan nomor hp expedisi
    char date[50];    // untuk menyimpan tanggal expedisi
    int biaya;        // untuk menyimpan biaya expedisi
    node *next;       // untuk menyimpan alamat node berikutnya
};

node *head = NULL;   // inisialisasi head dengan NULL
node *position;      // deklarasi pointer position untuk pengambilan posisi node
string randomString; // deklarasi randomString untuk pembuatan nomor resi
int option = 0;      // deklarasi option untuk pilihan menu
char id[7];          // deklarasi id untuk menyimpan nomor resi sementara
int digitResi = 5;   // deklarasi digitResi untuk menyimpan jumlah digit nomor resi

// prototype function
void save();                // deklarasi fungsi save untuk menyimpan data ke struct
void createdata();          // deklarasi fungsi createdata untuk membuat beberapa data
void addData();             // deklarasi fungsi addData untuk menambah data
void insertfirst();         // deklarasi fungsi insertfirst untuk menambah data di awal list
void insertlast();          // deklarasi fungsi insertlast untuk menambah data di akhir list
void insertpos();           // deklarasi fungsi insertpos untuk menambah data di posisi tertentu
void updatedata();          // deklarasi fungsi updatedata untuk mengupdate data
void updatefirst();         // deklarasi fungsi updatefirst untuk mengupdate data di awal list
void updatelast();          // deklarasi fungsi updatelast untuk mengupdate data di akhir list
void updatepos();           // deklarasi fungsi updatepos untuk mengupdate data di posisi tertentu
void deletedata();          // deklarasi fungsi deletedata untuk menghapus data
void deletefirst();         // deklarasi fungsi deletefirst untuk menghapus data di awal list
void deletelast();          // deklarasi fungsi deletelast untuk menghapus data di akhir list
void deletepos();           // deklarasi fungsi deletepos untuk menghapus data di posisi tertentu
void tampilkanData();       // deklarasi fungsi tampilkanData untuk menampilkan data
void line();                // deklarasi fungsi line untuk menampilkan garis tabel
void search();              // deklarasi fungsi search untuk mencari data
void searchid();            // deklarasi fungsi searchid untuk mencari data berdasarkan resi
void searchname();          // deklarasi fungsi searchname untuk mencari data berdasarkan nama
void sorting();             // deklarasi fungsi sorting untuk mengurutkan data
void ascending();           // deklarasi fungsi ascending untuk mengurutkan data secara ascending [A-Z]
void descending();          // deklarasi fungsi descending untuk mengurutkan data secara descending [Z-A]
string generateResi(int n); // deklarasi fungsi generateResi untuk mengambil dan membuat nomor resi

// function main (utama)
int main()
{

    do
    {
        system("cls"); // untuk membersihkan layar
        cout << "-----------------------------------------------------------" << endl;
        cout << "|                   APLIKASI JASA EXPEDISI                |" << endl;
        cout << "-----------------------------------------------------------" << endl;
        // Pilihan menu aplikasi
        cout << "PILIHAN MENU: " << endl;
        cout << "1. Create Data" << endl;
        cout << "2. Insert Data" << endl;
        cout << "3. View Data" << endl;
        cout << "4. Update Data" << endl;
        cout << "5. Delete Data" << endl;
        cout << "6. Search Data" << endl;
        cout << "7. Sort Data" << endl;
        cout << "0. Exit" << endl;
        cout << endl
             << " Pilihan >> ";
        cin >> option;

        // aku gunain percabangan switch case
        switch (option)
        {
        case 1:
            createdata();
            break;
        case 2:
            addData();
            break;
        case 3:
            tampilkanData();
            break;
        case 4:
            updatedata();
            break;
        case 5:
            deletedata();
            break;
        case 6:
            search();
            break;
        case 7:
            sorting();
            break;
        }
    } while (option != 0); // jika user input 0 maka program akan berhenti (0 bisa diganti dengan angka lain juga)
}

// function save
void save(char id[7], char nama[50], char alamat[100], char no_hp[16], char date[50], int biaya)
{
    node *newnode = new node;        // deklarasi newnode untuk menyimpan alamat node baru
    strcpy(newnode->id, id);         // menyimpan id ke dalam node baru
    strcpy(newnode->nama, nama);     // menyimpan nama ke dalam node baru
    strcpy(newnode->alamat, alamat); // menyimpan alamat ke dalam node baru
    strcpy(newnode->no_hp, no_hp);   // menyimpan no_hp ke dalam node baru
    strcpy(newnode->date, date);     // menyimpan date ke dalam node baru
    newnode->biaya = biaya;          // menyimpan biaya ke dalam node baru
    newnode->next = NULL;            // menyimpan alamat node berikutnya ke dalam node baru

    // jika head kosong maka newnode akan menjadi head
    if (head == NULL)
    {
        head = newnode;
    }
    // jika head tidak kosong maka newnode akan menjadi node berikutnya dari head
    else
    {
        node *current = head; // deklarasi current untuk menyimpan alamat node saat ini
        // looping untuk mencari node berikutnya dari head (aku gunain while loop karena looping ini tidak akan berhenti)
        while (current->next != NULL)
        {
            current = current->next; // current akan menjadi node berikutnya
        }
        current->next = newnode; // node berikutnya dari current akan menjadi newnode
    }
}

void createdata()
{
    // variabel bantu
    int jumlah;
    char nama[50];
    char alamat[100];
    char no_hp[16];
    char date[50];
    int biaya;
    int i;

    cout << "-----------------------------------------------------------" << endl;
    cout << "|                         BUAT DATA                       |" << endl;
    cout << "-----------------------------------------------------------" << endl;

    system("cls");
    cout << "Berapa data yang ingin ditambahkan?: "; // menanyakan berapa data yang ingin ditambahkan
    cin >> jumlah;

    for (i = 1; i <= jumlah; i++)
    {
        cin.ignore(1, '\n'); // menghilangkan enter (agar bisa pake spasi buat misahin inputan)
        system("cls");
        cout << "\nMasukan Data ke " << i << "!" << endl;
        cout << "Masukan Nama: ";
        cin.getline(nama, 50); // mengambil inputan nama (aku pake getline karena inputan nama bisa berisi spasi)
        cout << "Masukan Alamat: ";
        cin.getline(alamat, 100); // mengambil inputan alamat
        cout << "Masukan No HP: ";
        cin.getline(no_hp, 16); // mengambil inputan no hp
        cout << "Masukan Tanggal: ";
        cin.getline(date, 50); // mengambil inputan tanggal
        cout << "Masukan Ongkos Kirim: ";
        cin >> biaya;                               // mengambil inputan biaya (kalo biaya pake cin aja soalnya gk akan ada spasi kalo angka(int))
        srand(time(NULL));                          // untuk mengacak nomor resi
        randomString = generateResi(digitResi);     // buat id resi secara random
        strcpy(id, randomString.c_str());           // menyimpan id resi ke dalam variabel id
        save(id, nama, alamat, no_hp, date, biaya); // memanggil fungsi save untuk memasukan semua data ke dalam linked list
    }

    cout << i - 1 << " data berhasil ditambahkan!" << endl;
    getch(); // untuk menunggu user menekan tombol apapun
}

// function insert data di awal
void insertfirst(char id[7], char nama[50], char alamat[100], char no_hp[16], char date[50], int biaya)
{
    node *newnode = new node;        // deklarasi newnode untuk menyimpan alamat node baru
    strcpy(newnode->id, id);         // menyimpan id ke dalam node baru
    strcpy(newnode->nama, nama);     // menyimpan nama ke dalam node baru
    strcpy(newnode->alamat, alamat); // menyimpan alamat ke dalam node baru
    strcpy(newnode->no_hp, no_hp);   // menyimpan no_hp ke dalam node baru
    strcpy(newnode->date, date);     // menyimpan date ke dalam node baru
    newnode->biaya = biaya;          // menyimpan biaya ke dalam node baru
    newnode->next = head;            // menyimpan alamat node berikutnya ke dalam node baru
    head = newnode;                  // head menjadi node baru
}

// function insert data di akhir
void insertlast(char id[7], char nama[50], char alamat[100], char no_hp[16], char date[50], int biaya)
{
    node *newnode = new node;        // deklarasi newnode untuk menyimpan alamat node baru
    strcpy(newnode->id, id);         // menyimpan id ke dalam node baru
    strcpy(newnode->nama, nama);     // menyimpan nama ke dalam node baru
    strcpy(newnode->alamat, alamat); // menyimpan alamat ke dalam node baru
    strcpy(newnode->no_hp, no_hp);   // menyimpan no_hp ke dalam node baru
    strcpy(newnode->date, date);     // menyimpan date ke dalam node baru
    newnode->biaya = biaya;          // menyimpan biaya ke dalam node baru
    newnode->next = NULL;            // menyimpan alamat node berikutnya ke dalam node baru

    // jika head kosong maka newnode akan menjadi head
    if (head == NULL)
    {
        head = newnode; // head menjadi node baru
    }

    // jika head tidak kosong maka newnode akan menjadi node berikutnya dari head
    else
    {
        node *current = head; // deklarasi current untuk menyimpan alamat node saat ini
        // looping untuk mencari node berikutnya dari head
        while (current->next != NULL)
        {
            current = current->next; // current akan menjadi node berikutnya
        }
        current->next = newnode; // node berikutnya dari current akan menjadi newnode
    }
}

// function insert data di tengah
void insertpos()
{
    // variabel bantu
    int pos;
    char nama[50];
    char alamat[100];
    char no_hp[16];
    char date[50];
    int biaya;

    system("cls");
    cout << "Tambahkan data pada posisi ke: "; // menanyakan posisi data yang ingin ditambahkan
    cin >> pos;

    cin.ignore(1, '\n'); // menghilangkan enter (agar bisa pake spasi buat misahin inputan)
    system("cls");
    cout << "Masukan data pada posisi ke " << pos << "!" << endl;
    cout << "Masukan Nama: ";
    cin.getline(nama, 50); // mengambil inputan nama
    cout << "Masukan Alamat: ";
    cin.getline(alamat, 100); // mengambil inputan alamat
    cout << "Masukan No HP: ";
    cin.getline(no_hp, 16); // mengambil inputan no hp
    cout << "Masukan Tanggal: ";
    cin.getline(date, 50); // mengambil inputan tanggal
    cout << "Masukan Ongkos Kirim: ";
    cin >> biaya;                           // mengambil inputan biaya
    srand(time(NULL));                      // untuk mengacak nomor resi
    randomString = generateResi(digitResi); // buat id resi secara random
    strcpy(id, randomString.c_str());       // menyimpan id resi ke dalam variabel id

    // jika posisi yang ingin ditambahkan di awal
    if (pos == 1)
    {
        insertfirst(id, nama, alamat, no_hp, date, biaya); // memanggil fungsi insertfirst untuk menambahkan data di awal
        cout << "Data berhasil ditambahkan pada posisi pertama!" << endl;
        getch(); // untuk menunggu user menekan tombol apapun
    }
    else
    {
        node *current = head;  // deklarasi current untuk menyimpan alamat node saat ini
        node *previous = NULL; // deklarasi previous untuk menyimpan alamat node sebelumnya
        int count = 1;         // deklarasi count untuk menghitung posisi node saat ini

        // looping untuk mencari posisi node yang ingin ditambahkan
        while (current != NULL && count != pos)
        {
            previous = current;      // previous menjadi node sebelumnya
            current = current->next; // current menjadi node berikutnya
            count++;                 // count bertambah
        }

        // jika posisi yang ingin ditambahkan tidak ada di dalam linked list
        if (current == NULL)
        {
            cout << "Mohon maaf posisi tidak ditemukan!" << endl;
            getch();
        }
        else
        {
            node *newnode = new node;        // deklarasi newnode untuk menyimpan alamat node baru
            strcpy(newnode->id, id);         // menyimpan id ke dalam node baru
            strcpy(newnode->nama, nama);     // menyimpan nama ke dalam node baru
            strcpy(newnode->alamat, alamat); // menyimpan alamat ke dalam node baru
            strcpy(newnode->no_hp, no_hp);   // menyimpan no_hp ke dalam node baru
            strcpy(newnode->date, date);     // menyimpan date ke dalam node baru
            newnode->biaya = biaya;          // menyimpan biaya ke dalam node baru
            newnode->next = current;         // menyimpan alamat node berikutnya ke dalam node baru
            previous->next = newnode;        // node sebelumnya menjadi node baru
            cout << "Data berhasil ditambahkan pada posisi ke " << pos << "!" << endl;
            getch();
        }
    }
}

// function add data
void addData()
{
    // variabel bantu
    char nama[50];
    char alamat[100];
    char no_hp[16];
    char date[50];
    int biaya;

    system("cls");
    cout << "TAMBAH DATA" << endl;
    cout << "1. Tambahkan di awal list" << endl;
    cout << "2. Tambahkan di tengah list" << endl;
    cout << "3. Tambahkan di akhir list" << endl;
    cout << "\nPilihan >> ";
    cin >> option;

    switch (option)
    {
    case 1:                  // jika pilihan user adalah 1 (tambahkan di awal)
        cin.ignore(1, '\n'); // menghilangkan enter
        system("cls");       // membersihkan layar
        cout << "Masukan Nama: ";
        cin.getline(nama, 50); // mengambil inputan nama
        cout << "Masukan Alamat: ";
        cin.getline(alamat, 100); // mengambil inputan alamat
        cout << "Masukan No HP: ";
        cin.getline(no_hp, 16); // mengambil inputan no hp
        cout << "Masukan Tanggal: ";
        cin.getline(date, 50); // mengambil inputan tanggal
        cout << "Masukan Ongkos Kirim: ";
        cin >> biaya;                                      // mengambil inputan biaya
        srand(time(NULL));                                 // untuk mengacak nomor resi
        randomString = generateResi(digitResi);            // buat id resi secara random
        strcpy(id, randomString.c_str());                  // menyimpan id resi ke dalam variabel id
        insertfirst(id, nama, alamat, no_hp, date, biaya); // memanggil fungsi insertfirst untuk menambahkan data di awal
        cout << "\nData berhasil ditambahkan di awal list!" << endl;
        getch(); // untuk menunggu user menekan tombol apapun
        break;

    case 2:          // jika pilihan user adalah 2 (tambahkan di tengah)
        insertpos(); // memanggil fungsi insertpos untuk menambahkan data di tengah
        break;

    case 3:                  // jika pilihan user adalah 3 (tambahkan di akhir)
        cin.ignore(1, '\n'); // menghilangkan enter
        system("cls");       // membersihkan layar
        cout << "Masukan Nama: ";
        cin.getline(nama, 50); // mengambil inputan nama
        cout << "Masukan Alamat: ";
        cin.getline(alamat, 100); // mengambil inputan alamat
        cout << "Masukan No HP: ";
        cin.getline(no_hp, 16); // mengambil inputan no hp
        cout << "Masukan Tanggal: ";
        cin.getline(date, 50); // mengambil inputan tanggal
        cout << "Masukan Ongkos Kirim: ";
        cin >> biaya;                                     // mengambil inputan biaya
        srand(time(NULL));                                // untuk mengacak nomor resi
        randomString = generateResi(digitResi);           // buat id resi secara random
        strcpy(id, randomString.c_str());                 // menyimpan id resi ke dalam variabel id
        insertlast(id, nama, alamat, no_hp, date, biaya); // memanggil fungsi insertlast untuk menambahkan data di akhir
        cout << "\nData berhasil ditambahkan di akhir list!" << endl;
        getch(); // untuk menunggu user menekan tombol apapun
        break;
    }
}

// function delete data
void deletedata()
{

    system("cls");
    cout << "HAPUS DATA" << endl;
    cout << "1. Hapus data di awal list" << endl;
    cout << "2. Hapus data di tengah list" << endl;
    cout << "3. Hapus data di akhir list" << endl;
    cout << "4. Hapus semua data" << endl;
    cout << "\nPilihan >> ";
    cin >> option;

    switch (option)
    {
    case 1:            // jika pilihan user adalah 1 (hapus data di awal)
        deletefirst(); // memanggil fungsi deletefirst untuk menghapus data di awal
        break;

    case 2:          // jika pilihan user adalah 2 (hapus data di tengah)
        deletepos(); // memanggil fungsi deletepos untuk menghapus data di tengah
        break;

    case 3:           // jika pilihan user adalah 3 (hapus data di akhir)
        deletelast(); // memanggil fungsi deletelast untuk menghapus data di akhir
        break;
    case 4: // jika pilihan user adalah 4 (hapus semua data)

        // jika list kosong
        if (head == NULL)
        {
            cout << "List kosong!" << endl;
            getch();
        }
        else
        {
            node *current = head;  // inisialisasi current dengan head
            node *previous = NULL; // inisialisasi previous dengan NULL

            // looping untuk mencari data yang akan dihapus
            while (current != NULL)
            {
                previous = current;      // menyimpan current ke dalam variabel previous
                current = current->next; // mengubah current menjadi next
                delete previous;         // menghapus data yang ada di variabel previous
            }
            head = NULL; // mengubah head menjadi NULL
            cout << "Semua data berhasil dihapus!" << endl;
            getch();
        }
        break;
    }
}

// function delete data di awal
void deletefirst()
{
    // jika list kosong
    if (head == NULL)
    {
        cout << "List kosong!" << endl;
        getch();
    }
    else
    {
        node *temp = head; // inisialisasi temp dengan head
        head = head->next; // mengubah head menjadi next
        delete temp;       // menghapus data yang ada di variabel temp
        cout << "Data pada urutan pertama berhasil dihapus!" << endl;
        getch();
    }
}

// function delete data di akhir
void deletelast()
{
    // jika list kosong
    if (head == NULL)
    {
        cout << "List kosong!" << endl;
        getch();
    }
    else
    {
        node *current = head;  // inisialisasi current dengan head
        node *previous = NULL; // inisialisasi previous dengan NULL

        // looping untuk mencari data yang akan dihapus
        while (current->next != NULL)
        {
            previous = current;      // menyimpan current ke dalam variabel previous
            current = current->next; // mengubah current menjadi next
        }
        previous->next = NULL; // mengubah next dari previous menjadi NULL
        delete current;        // menghapus data yang ada di variabel current
        cout << "Data pada urutan terakhir berhasil dihapus!" << endl;
        getch();
    }
}

// function delete data di tengah
void deletepos()
{
    int pos;

    // jika list kosong
    if (head == NULL)
    {
        cout << "List kosong!" << endl;
        getch();
    }
    else
    {
        system("cls");
        cout << "Masukan posisi yang akan dihapus: ";
        cin >> pos;          // mengambil inputan posisi yang akan dihapus
        cin.ignore(1, '\n'); // menghilangkan enter
        if (pos == 1)        // jika posisi yang diinputkan 1
        {
            deletefirst(); // panggil fungsi deletefirst
        }
        // jika tidak
        else
        {
            node *current = head;  // inisialisasi current dengan head
            node *previous = NULL; // inisialisasi previous dengan NULL
            int count = 1;         // inisialisasi count dengan 1

            // looping untuk mencari data yang akan dihapus
            while (current != NULL && count != pos)
            {
                previous = current;      // menyimpan current ke dalam variabel previous
                current = current->next; // mengubah current menjadi next
                count++;                 // menambahkan count dengan 1
            }
            // jika posisi yang diinputkan lebih dari jumlah data
            if (current == NULL)
            {
                cout << "Mohon maaf posisi tidak ditemukan!" << endl;
                getch();
            }
            // jika tidak
            else
            {
                previous->next = current->next; // mengubah next dari previous menjadi next
                delete current;                 // menghapus data yang ada di variabel current
                cout << "Data pada urutan ke " << pos << " berhasil dihapus!" << endl;
                getch();
            }
        }
    }
}

// update data
void updatedata()
{
    system("cls");
    cout << "UPDATE DATA" << endl;
    cout << "1. Update data di awal list" << endl;
    cout << "2. Update data di tengah list" << endl;
    cout << "3. Update data di akhir list" << endl;
    cout << "\nPilihan >> ";
    cin >> option;

    switch (option)
    {
    case 1:
        updatefirst();
        break;

    case 2:
        updatepos();
        break;

    case 3:
        updatelast();
        break;
    }
}

// update data di awal list
void updatefirst()
{
    // jika list kosong
    if (head == NULL)
    {
        cout << "List kosong!" << endl;
        getch();
    }
    else
    {
        system("cls");
        cout << "Update data di awal list" << endl;
        cout << "Masukan Nama: ";
        cin.ignore(1, '\n');         // menghilangkan enter
        cin.getline(head->nama, 50); // mengambil inputan nama
        cout << "Masukan Alamat: ";
        cin.getline(head->alamat, 100); // mengambil inputan alamat
        cout << "Masukan No HP: ";
        cin.getline(head->no_hp, 16); // mengambil inputan no hp
        cout << "Masukan Tanggal: ";
        cin.getline(head->date, 50); // mengambil inputan tanggal
        cout << "Masukan Ongkos Kirim: ";
        cin >> head->biaya; // mengambil inputan biaya
        cout << "\nData berhasil diupdate!" << endl;
        getch();
    }
}

// update data di tengah list
void updatepos()
{
    int pos;

    // jika list kosong
    if (head == NULL)
    {
        cout << "List kosong!" << endl;
        getch();
    }
    else
    {
        system("cls");
        cout << "Update data di tengah list" << endl;
        cout << "Masukan posisi yang akan diupdate: ";
        cin >> pos;          // mengambil inputan posisi yang akan diupdate
        cin.ignore(1, '\n'); // menghilangkan enter
        if (pos == 1)        // jika posisi yang diinputkan 1
        {
            updatefirst(); // panggil fungsi updatefirst
        }
        else
        {
            node *current = head;  // inisialisasi current dengan head
            node *previous = NULL; // inisialisasi previous dengan NULL
            int count = 1;         // inisialisasi count dengan 1

            // looping untuk mencari data yang akan diupdate
            while (current != NULL && count != pos)
            {
                previous = current;      // menyimpan current ke dalam variabel previous
                current = current->next; // mengubah current menjadi next
                count++;                 // menambahkan count dengan 1
            }
            // jika posisi yang diinputkan lebih dari jumlah data
            if (current == NULL)
            {
                cout << "Mohon maaf posisi tidak ditemukan!" << endl;
                getch();
            }
            // jika tidak
            else
            {
                system("cls");
                cout << "Update data di tengah list" << endl;
                cout << "Masukan Nama: ";
                cin.ignore(1, '\n');            // menghilangkan enter
                cin.getline(current->nama, 50); // mengambil inputan nama
                cout << "Masukan Alamat: ";
                cin.getline(current->alamat, 100); // mengambil inputan alamat
                cout << "Masukan No HP: ";
                cin.getline(current->no_hp, 16); // mengambil inputan no hp
                cout << "Masukan Tanggal: ";
                cin.getline(current->date, 50); // mengambil inputan tanggal
                cout << "Masukan Ongkos Kirim: ";
                cin >> current->biaya; // mengambil inputan biaya
                cout << "\nData berhasil diupdate!" << endl;
                getch();
            }
        }
    }
}

// function update data di akhir list
void updatelast()
{

    // jika list kosong
    if (head == NULL)
    {
        cout << "List kosong!" << endl;
        getch();
    }
    else
    {
        node *current = head;  // inisialisasi current dengan head
        node *previous = NULL; // inisialisasi previous dengan NULL

        // looping untuk mencari data yang akan diupdate
        while (current->next != NULL)
        {
            previous = current;      // menyimpan current ke dalam variabel previous
            current = current->next; // mengubah current menjadi next
        }
        system("cls");
        cout << "Update data di akhir list" << endl;
        cout << "Masukan Nama: ";
        cin.ignore(1, '\n');            // menghilangkan enter
        cin.getline(current->nama, 50); // mengambil inputan nama
        cout << "Masukan Alamat: ";
        cin.getline(current->alamat, 100); // mengambil inputan alamat
        cout << "Masukan No HP: ";
        cin.getline(current->no_hp, 16); // mengambil inputan no hp
        cout << "Masukan Tanggal: ";
        cin.getline(current->date, 50); // mengambil inputan tanggal
        cout << "Masukan Ongkos Kirim: ";
        cin >> current->biaya;
        cout << "\nData berhasil diupdate!" << endl;
        getch();
    }
}

// function search data
void search()
{

    system("cls");
    cout << "CARI DATA" << endl;
    cout << "1. Cari data berdasarkan No Resi" << endl;
    cout << "2. Cari data berdasarkan Nama" << endl;
    cout << "\nPilihan >> ";
    cin >> option;

    switch (option)
    {
    case 1: // jika pilihan 1 (cari data berdasarkan no resi)
        searchid();
        break;

    case 2: // jika pilihan 2 (cari data berdasarkan nama)
        searchname();
        break;
    }
}

// function search data berdasarkan no resi
void searchid()
{
    char id[7];    // inisialisasi variabel id dengan 7 karakter (untuk inputan pencarian)
    int found = 0; // inisialisasi variabel found dengan 0 (untuk mengecek apakah data ditemukan)

    // jika list kosong
    if (head == NULL)
    {
        cout << "List kosong!" << endl;
        getch();
    }
    // jika tidak
    else
    {
        system("cls");
        cin.ignore(1, '\n'); // menghilangkan enter
        cout << "Masukan No Resi yang akan dicari: ";
        cin.getline(id, 7);   // mengambil inputan no resi
        node *current = head; // inisialisasi current dengan head

        // looping untuk mencari data yang akan dicari
        while (current != NULL && found == 0)
        {
            // jika data yang dicari sama dengan data yang ada di list
            if (strcmp(current->id, id) == 0)
            {
                found = 1; // ubah found menjadi 1
            }
            else
            {
                current = current->next; // mengubah current menjadi next
            }
        }

        // jika data yang dicari ditemukan
        if (found == 1)
        {
            cout << "\nData dengan No Resi " << id << " ditemukan!" << endl;
            // print data
            cout << "No Resi: " << current->id << endl;
            cout << "Nama: " << current->nama << endl;
            cout << "Alamat: " << current->alamat << endl;
            cout << "No HP: " << current->no_hp << endl;
            cout << "Tanggal: " << current->date << endl;
            cout << "Ongkos Kirim: " << current->biaya << endl;
            getch();
        }
        // jika data yang dicari tidak ditemukan
        else
        {
            cout << "Data dengan No Resi " << id << " tidak ditemukan!" << endl;
            getch();
        }
    }
}

void searchname()
{

    char nama[50]; // inisialisasi variabel nama dengan 50 karakter (untuk inputan pencarian)
    int found = 0; // inisialisasi variabel found dengan 0 (untuk mengecek apakah data ditemukan)

    // jika list kosong
    if (head == NULL)
    {
        cout << "List kosong!" << endl;
        getch();
    }
    // jika tidak
    else
    {
        system("cls");
        cin.ignore(1, '\n'); // menghilangkan enter
        cout << "Masukan Nama yang akan dicari: ";
        cin.getline(nama, 50); // mengambil inputan nama
        node *current = head;  // inisialisasi current dengan head

        // looping untuk mencari data yang akan dicari
        while (current != NULL && found == 0)
        {
            // jika data yang dicari sama dengan data yang ada di list
            if (strcmp(current->nama, nama) == 0)
            {
                found = 1; // ubah found menjadi 1
            }
            else
            {
                current = current->next; // mengubah current menjadi next
            }
        }

        // jika data yang dicari ditemukan
        if (found == 1)
        {
            cout << "\nData dengan Nama " << nama << " ditemukan!" << endl;
            // print data
            cout << "No. Resi: " << current->id << endl;
            cout << "Nama: " << current->nama << endl;
            cout << "Alamat: " << current->alamat << endl;
            cout << "No HP: " << current->no_hp << endl;
            cout << "Tanggal: " << current->date << endl;
            cout << "Ongkos Kirim: " << current->biaya << endl;

            getch();
        }
        // jika data yang dicari tidak ditemukan
        else
        {
            cout << "Data dengan Nama " << nama << " tidak ditemukan!" << endl;
            getch();
        }
    }
}

// function sort data
void sorting()
{
    system("cls");
    cout << "SORTING DATA" << endl;
    cout << "1. Urutkan Nama [A - Z]" << endl;
    cout << "2. Urutkan Nama [Z - A]" << endl;
    cout << "\nPilihan >> ";
    cin >> option;

    switch (option)
    {
    case 1: // jika pilihan 1 (sort data berdasarkan nama [A - Z])
        ascending();
        break;

    case 2: // jika pilihan 2 (sort data berdasarkan nama [Z - A])
        descending();
        break;
    }
}

// function sort data berdasarkan nama [A - Z]
void ascending()
{
    // jika list kosong
    if (head == NULL)
    {
        cout << "List kosong!" << endl;
        getch();
    }
    else
    {
        node *current = head;  // inisialisasi current dengan head
        node *previous = NULL; // inisialisasi previous dengan NULL
        node *next = NULL;     // inisialisasi next dengan NULL

        // looping untuk mengurutkan data
        while (current != NULL)
        {
            next = current->next; // mengubah next menjadi next dari current

            // selama next tidak kosong
            while (next != NULL)
            {
                // jika nama current lebih kecil dari nama next
                if (strcmp(current->nama, next->nama) > 0)
                {
                    // swap data nama, alamat, no hp, tanggal, biaya, dan id
                    char temp[50];                     // inisialisasi variabel temp dengan 50 karakter
                    strcpy(temp, current->nama);       // mengcopy nama current ke temp
                    strcpy(current->nama, next->nama); // mengcopy nama next ke current
                    strcpy(next->nama, temp);          // mengcopy temp ke nama next

                    char temp2[100];                       // inisialisasi variabel temp2 dengan 100 karakter
                    strcpy(temp2, current->alamat);        // mengcopy alamat current ke temp2
                    strcpy(current->alamat, next->alamat); // mengcopy alamat next ke current
                    strcpy(next->alamat, temp2);           // mengcopy temp2 ke alamat next

                    char temp3[16];                      // inisialisasi variabel temp3 dengan 16 karakter
                    strcpy(temp3, current->no_hp);       // mengcopy no hp current ke temp3
                    strcpy(current->no_hp, next->no_hp); // mengcopy no hp next ke current
                    strcpy(next->no_hp, temp3);          // mengcopy temp3 ke no hp next

                    char temp4[50];                    // inisialisasi variabel temp4 dengan 50 karakter
                    strcpy(temp4, current->date);      // mengcopy tanggal current ke temp4
                    strcpy(current->date, next->date); // mengcopy tanggal next ke current
                    strcpy(next->date, temp4);         // mengcopy temp4 ke tanggal next

                    int temp5 = current->biaya;   // inisialisasi variabel temp5 dengan tipe data integer
                    current->biaya = next->biaya; // mengcopy biaya next ke current
                    next->biaya = temp5;          // mengcopy temp5 ke biaya next

                    char temp6[7];                 // inisialisasi variabel temp6 dengan 7 karakter
                    strcpy(temp6, current->id);    // mengcopy id current ke temp6
                    strcpy(current->id, next->id); // mengcopy id next ke current
                    strcpy(next->id, temp6);       // mengcopy temp6 ke id next
                }
                next = next->next; // mengubah next menjadi next dari next
            }
            current = current->next; // mengubah current menjadi next dari current
        }
        cout << "\nData berhasil diurutkan secara ascending!" << endl;
        getch();
    }
}

// function sort data berdasarkan nama [Z - A]
void descending()
{
    // penjelasannya sama kaya ascending
    if (head == NULL)
    {
        cout << "List kosong!" << endl;
        getch();
    }
    else
    {
        node *current = head;
        node *previous = NULL;
        node *next = NULL;
        while (current != NULL)
        {
            next = current->next;
            while (next != NULL)
            {
                if (strcmp(current->nama, next->nama) < 0) // sama aja kaya ascending cuma beda tanda " < " aja
                {
                    // swap data
                    char temp[50];
                    strcpy(temp, current->nama);
                    strcpy(current->nama, next->nama);
                    strcpy(next->nama, temp);

                    char temp2[100];
                    strcpy(temp2, current->alamat);
                    strcpy(current->alamat, next->alamat);
                    strcpy(next->alamat, temp2);

                    char temp3[16];
                    strcpy(temp3, current->no_hp);
                    strcpy(current->no_hp, next->no_hp);
                    strcpy(next->no_hp, temp3);

                    char temp4[50];
                    strcpy(temp4, current->date);
                    strcpy(current->date, next->date);
                    strcpy(next->date, temp4);

                    int temp5 = current->biaya;
                    current->biaya = next->biaya;
                    next->biaya = temp5;

                    char temp6[7];
                    strcpy(temp6, current->id);
                    strcpy(current->id, next->id);
                    strcpy(next->id, temp6);
                }
                next = next->next;
            }
            current = current->next;
        }
        cout << "\nData berhasil diurutkan secara descending!" << endl;
        getch();
    }
}

// function untuk menampilkan data
void tampilkanData()
{
    node *current = head; // inisialisasi current dengan head
    int no = 0;           // inisialisasi no dengan 0 (untuk menampilkan nomor urutan)

    system("cls"); // membersihkan layar
    line();        // memanggil function line untuk membuat tabel
    // aku pake printf karena kalo pake cout, susah bikin tabelnya
    printf("|%-3s|%-8s|%-15s|%-15s|%-15s|%-15s|%-10s|\n", "No ", "No Resi", "Nama", "Alamat", "Phone", "Tanggal", "Ongkir");
    line();

    // jika list kosong
    if (head == NULL)
    {
        cout << "Data masih kosong!" << endl;
        getch();
    }
    // jika list tidak kosong
    else
    {
        // tampilkan semua datanya menggunakan looping
        while (current != NULL)
        {
            no++; // jangan lupa urutannya juga ditambahkan
            printf("|%-3d|%-8s|%-15s|%-15s|%-15s|%-15s|Rp. %-10d|\n", no, current->id, current->nama, current->alamat, current->no_hp, current->date, current->biaya);
            line();
            current = current->next; // mengubah current menjadi next dari current
        }
        getch();
    }
}

// function untuk membuat resi secara otomatis
string generateResi(int n)
{
    // pilihan karakter yang digunakan untuk membuat resi
    char kode[37] = {'A', '1', 'B', '2', 'C', '3', 'D', '4', 'E', '5', 'F', '6', 'G', '7', 'H', '8', 'I', '9', 'J', '0', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    string res = ""; // inisialisasi res dengan string kosong

    // looping untuk membuat resi
    for (int i = 0; i < digitResi; i++)
    {
        res = res + kode[rand() % 37]; // menambahkan karakter random dari kode ke res
    }
    return res;
}

// function untuk membuat garis tabel
void line()
{
    for (int i = 0; i < 89; i++) // garisnya aku set panjangnya 89 (kalo kepanjangan/kependekan ganti aja)
    {
        cout << "-"; // bisa diganti tandanya menjadi "*", "=", atau terserah:v
    }
    cout << endl;
}

// END
