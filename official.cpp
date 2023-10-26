#include <string>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

int stt, kq1, kq2, kq3, kq4, kq5, kq6,
    TT1, TT2, TT3, TT4, TT5;
bool check[1000];

struct congviec{
    string trang_thai, tieu_de, do_uu_tien, bat_dau, ket_thuc, note;
    int mark, stt, month = 0, day = 0, year = 0;

    void muc_do_hoan_thanh(string s){ //Phan loai trang thai de dung cho sap xep/loc/tim kiem
        if (s == "Chua_hoan_thanh"){
            stt = 1;
        }
        else if (s == "Dang_lam"){
            stt = 2;
        }
        else if (s == "Hoan_thanh"){
            stt = 3;
        }
        else if (s == "Bi_huy"){
            stt = 4;
        }
        else if (s == "Qua_han"){
            stt = 5;
        }
    }

    void danh_dau_quan_trong(string s){//Phan loai do uu tien de dung cho sap xep/loc/tim kiem
        if (s == "Trong_ngay"){
            mark = 1;
        }
        else if (s == "Trong_ba_ngay"){
            mark = 2;
        }
        else if (s == "Trong_tuan"){
            mark = 3;
        }
        else if (s == "Trong_hai_tuan"){
            mark = 4;
        }
        else if (s == "Trong_thang"){
            mark = 5;
        }
    }

    void them_thong_tin(){
        cout <<"===================================\n";
        cout << "Nhap trang thai: "; cin >> trang_thai;
        cout << "Nhap tieu de: "; //cin.ignore(); getline(cin, tieu_de);
        cin >> tieu_de;
        cout << "Nhap muc do quan trong: "; cin >> do_uu_tien;
        muc_do_hoan_thanh(trang_thai); //Phan loai trang thai de dung cho sap xep/loc/tim kiem
        danh_dau_quan_trong(do_uu_tien);//Phan loai trang thai de dung cho sap xep/loc/tim kiem
        cout << "Nhap ngay bat dau: "; cin >> bat_dau;
        cout << "Nhap ngay ket thuc: "; cin >> ket_thuc;
        cout << "Nhap ghi chu: "; //cin.ignore(); getline(cin, note);
        cin >>  note;
        cout <<"===================================\n";
    }

    void in_thong_tin(){
        cout << "-----------------------------------\n";
        cout << "Trang thai: " << trang_thai << '\n';
        cout << "Tieu de: " << tieu_de << '\n';
        cout << "Muc do quan trong: " << do_uu_tien << '\n';
        cout << "Ngay bat dau: " << bat_dau << '\n';
        cout << "Ngay ket thuc: " << ket_thuc << '\n';
        cout << "Ghi chu: " << note << '\n';
    }

    void phan_tich(){ //chuyen tu string -> int de sap xep ngay thang nam
        int i = 0;
        while (ket_thuc[i] != '/'){
            day = day * 10 + (ket_thuc[i] - '0'); 
            i++;
        }
        i++;
        while (ket_thuc[i] != '/'){
            month = month * 10 + (ket_thuc[i] - '0'); 
            i++;
        }
        i++;
        int j = i;
        for (int j = i; j < ket_thuc.length(); j++){
            year = year * 10 + (ket_thuc[j] - '0'); 
        }        
    }
};

void in_danh_sach(congviec a[], int n){
    cout <<"===================================\n";
    cout << "Thong tin danh sach cong viec:\n";
    for (int i = 0; i < n; i++){
        cout <<"-----------------------------------\n";
        cout << "STT: " << i + 1 << "\n";
        a[i].in_thong_tin();
    }
}

void xoa(congviec a[], int &n, int stt){
    for (int i = stt + 1; i < n; i++){
        a[i - 1] = a[i];
    }
    n -= 1;
}

void chinhsua(congviec a[], int stt){
    int tmp;
    cout << "1: Chinh sua trang thai\n";
    cout << "2: Chinh sua tieu de\n";
    cout << "3: Chinh sua muc do quan trong\n";
    cout << "4: Chinh sua ngay bat dau\n";
    cout << "5: Chinh sua ngay ket thuc\n";
    cout << "6: Chinh sua ghi chu\n";
    cout << "Hay nhap so: ";
    cin >> tmp;
    if (tmp == 1){
        cin >> a[stt].trang_thai;
    }
    if (tmp == 2){
        cin.ignore(); getline(cin, a[stt].tieu_de);
    }
    if (tmp == 3){
        cin >> a[stt].do_uu_tien;
    }
    if (tmp == 4){
        cin >> a[stt].bat_dau;
    }
    if (tmp == 5){
        cin >> a[stt].ket_thuc;
    }
    if (tmp == 6){
         cin.ignore(); getline(cin, a[stt].note);
    }
}

void doc_du_lieu(congviec a[], int &n){
    ifstream input_file;
    input_file.open("official.inp", ios::in);
    while (!input_file.eof()){
        input_file >> a[n].trang_thai;
        a[n].muc_do_hoan_thanh(a[n].trang_thai); 
//        input_file.ignore(); getline(input_file, a[n].tieu_de);
        input_file >> a[n].tieu_de;
        input_file >> a[n].do_uu_tien;
        a[n].danh_dau_quan_trong(a[n].do_uu_tien);
        input_file >> a[n].bat_dau;
        input_file >> a[n].ket_thuc;
        input_file >> a[n].note;
        n++;
    }
    input_file.close();
}

void xuat_du_lieu(congviec a[], int n){
    ofstream output_file;
    output_file.open("OFFICIAL.txt", ios::trunc);
    output_file << "Thong tin danh sach cong viec:\n";
    for (int i = 0; i < n; i++){
        output_file << "-----------------------------------\n";
        output_file << "STT: " << i + 1 << "\n";
        output_file << "Trang thai: " << a[i].trang_thai << '\n';
        output_file << "Tieu de: " << a[i].tieu_de << '\n';
        output_file << "Muc do quan trong: " << a[i].do_uu_tien << '\n';
        output_file << "Ngay hien tai: " << a[i].bat_dau << '\n';
        output_file << "Ngay ket thuc: " << a[i].ket_thuc << '\n';
        output_file << "Ghi chu: " << a[i].note << '\n';
    }
    output_file.close();
}

//====================Chuc nang TIM KIEM THEO YEU CAU================
void tk_theo_trang_thai(congviec a[], string tmp, int n, bool check[], int choice){
    kq1 = -1;
    for (int i = 0; i < n; i++){
        if (a[i].trang_thai.find(tmp) != string::npos){
            kq1 = i;
            check[i] = true;
            if (choice == 2) a[i].in_thong_tin();
        }
    }
}

void tk_theo_tieu_de(congviec a[], string tmp, int n, bool check[], int choice){
    kq2 = -1;
    for (int i = 0; i < n; i++){
        if ((check[i] == false) && (a[i].tieu_de.find(tmp) != string::npos)){
            kq2 = i;
            check[i] = true;
            if (choice == 2) a[i].in_thong_tin();
        }
    }
}

void tk_theo_do_uu_tien(congviec a[], string tmp, int n, bool check[], int choice){
    kq3 = -1;
    for (int i = 0; i < n; i++){
        if ((check[i] == false) && (a[i].do_uu_tien.find(tmp) != string::npos)){
            kq3 = i;
            check[i] = true;
            if (choice == 2) a[i].in_thong_tin();
        }
    }
}

void tk_theo_ngay_BD(congviec a[], string tmp, int n, bool check[], int choice){
    kq4 = -1;
    for (int i = 0; i < n; i++){
        if ((check[i] == false) && (a[i].bat_dau.find(tmp) != string::npos)){
            kq4 = i;
            check[i] = true;
            if (choice == 2) a[i].in_thong_tin();
        }
    }
}

void tk_theo_ngay_KT(congviec a[], string tmp, int n, bool check[], int choice){
    kq5 = -1;
    for (int i = 0; i < n; i++){
        if ((check[i] == false) && (a[i].ket_thuc.find(tmp) != string::npos)){
            kq5 = i;
            check[i] = true;
            if (choice == 2) a[i].in_thong_tin();
        }
    }
}

void tk_theo_note(congviec a[], string tmp, int n, bool check[], int choice){
    kq6 = -1;
    for (int i = 0; i < n; i++){
        if ((check[i] == false) && (a[i].note.find(tmp) != string::npos)){
            kq6 = i;
            check[i] = true;
            if (choice == 2) a[i].in_thong_tin();
        }
    }
}

//nó sẽ cout cái tìm kiếm tạm thời ra file TXT:))
void cout_tieu_de(){
    ofstream output_file;
    output_file.open("OFFICIAL.txt", ios::trunc);
    output_file << "Thong tin danh sach cong viec:\n";
    output_file.close();
}

void cout_co_noi_dung(congviec a[], int i){
    ofstream output_file;
    output_file.open("OFFICIAL.txt", ios::app);
//    for (int i = 0; i < n; i++){
    output_file << "-----------------------------------\n";
    output_file << "STT: " << i + 1 << "\n";
    output_file << "Trang thai: " << a[i].trang_thai << '\n';
    output_file << "Tieu de: " << a[i].tieu_de << '\n';
    output_file << "Muc do quan trong: " << a[i].do_uu_tien << '\n';
    output_file << "Ngay hien tai: " << a[i].bat_dau << '\n';
    output_file << "Ngay ket thuc: " << a[i].ket_thuc << '\n';
    output_file << "Ghi chu: " << a[i].note << '\n';    
    output_file.close();
}

void cout_Khong_KQ(){
    ofstream output_file;
    output_file.open("OFFICIAL.txt", ios::app);                
    output_file << "-----------------------------------\n";
    output_file << "Khong co ket qua ma ban muon tim kiem!!!\n";
    output_file.close();
}

void CN_1(congviec a[], string tmp, int n, int choice){
    for (int i = 0; i < n; i++){
        check[i] = false;
    }

    tk_theo_trang_thai(a, tmp, n, check, choice);

    tk_theo_tieu_de(a, tmp, n, check, choice);

    tk_theo_do_uu_tien(a, tmp, n, check, choice);

    tk_theo_ngay_BD(a, tmp, n, check, choice);

    tk_theo_ngay_KT(a, tmp, n, check, choice);

    tk_theo_note(a, tmp, n, check, choice);
    if (choice == 1){
        ofstream output_file;
   //     output_file.open("OFFICIAL.txt", ios::trunc);
   //     output_file << "Thong tin danh sach cong viec:\n";
    //    output_file.close();
        cout_tieu_de();
        for (int i = 0; i < n; i++){
            cout << check[i] << " ";
            if (check[i] == 1) {
                
        //        output_file.open("OFFICIAL.txt", ios::app);
        //    for (int i = 0; i < n; i++){
/*                output_file << "-----------------------------------\n";
                output_file << "STT: " << i + 1 << "\n";
                output_file << "Trang thai: " << a[i].trang_thai << '\n';
                output_file << "Tieu de: " << a[i].tieu_de << '\n';
                output_file << "Muc do quan trong: " << a[i].do_uu_tien << '\n';
                output_file << "Ngay hien tai: " << a[i].bat_dau << '\n';
                output_file << "Ngay ket thuc: " << a[i].ket_thuc << '\n';
                output_file << "Ghi chu: " << a[i].note << '\n';    
                output_file.close();*/
                cout_co_noi_dung(a, i);
            }
        }
        if (kq1 == -1 && kq2 == -1 && kq3 == -1 && kq4 == -1 && kq5 == -1 && kq6 == -1){
/*                output_file.open("OFFICIAL.txt", ios::app);                
                output_file << "-----------------------------------\n";
                output_file << "Khong co ket qua ma ban muon tim kiem!!!\n";
                output_file.close();*/
            cout_Khong_KQ();
        }
    }
    else if (choice == 2){
        if (kq1 == -1 && kq2 == -1 && kq3 == -1 && kq4 == -1 && kq5 == -1 && kq6 == -1){
            cout << "-----------------------------------\n";
            cout << "Khong co ket qua ma ban muon tim kiem!!!\n";
        }
    }
}
//=============================================================

//========================Chuc nang THONG KE====================
void CN_2(congviec a[], int n){
    TT1 = 0; TT2 = 0; TT3 = 0; TT4 = 0; TT5 = 0;
    for (int i = 0; i < n; i++){
        if (a[i].trang_thai == "Chua_hoan_thanh"){
            TT1 += 1;
        }
        if (a[i].trang_thai == "Dang_lam"){
            TT2 += 1;
        }
        if (a[i].trang_thai == "Hoan_thanh"){
            TT3 += 1;
        }
        if (a[i].trang_thai == "Bi_huy"){
            TT4 += 1;
        }
        if (a[i].trang_thai == "Qua_han"){
            TT5 += 1;
        }
    }
    cout << "\nThong ke: \n";
    cout << setprecision(2) << fixed << (((double) TT1 / (double) n) * 100) << "% chua hoan thanh\n";
    cout << setprecision(2) << fixed << (((double) TT2 / (double) n) * 100) << "% dang lam\n";
    cout << setprecision(2) << fixed << (((double) TT3 / (double) n) * 100) << "% hoan thanh\n";
    cout << setprecision(2) << fixed << (((double) TT4 / (double) n) * 100) << "% bi huy\n";
    cout << setprecision(2) << fixed << (((double) TT5 / (double) n) * 100) << "% qua han\n";
}   
//==================================================

//================SAP XEP THEO DO QUAN TRONG=======
bool cmp1(congviec a, congviec b){
    return (a.mark < b.mark);
}

void CN_3(congviec a[], int n){
    sort(a, a + n, cmp1);
}
//================================================

//===================LOC THEO TRANG THAI====================
bool cmp2(congviec a, congviec b){
    return a.stt < b.stt;
}

int tknp_stt(int d, int c, int tmp, congviec a[]){
    if (d <= c){
        int mid = d + (c - d) / 2;
        if (a[mid].stt == tmp){
            while (mid - 1 >= 0 && a[mid - 1].stt == a[mid].stt){
                mid--;
            }
            return mid;
        }
        else if (a[mid].stt < tmp) return (tknp_stt(mid + 1, c, tmp, a));
        else if (a[mid].stt > tmp) return (tknp_stt(d, mid - 1, tmp, a));
    }
    return -100;
}

void CN_5_1(congviec a[], int tmp, int n, int choice){
    sort(a, a + n, cmp2);
    int pos = tknp_stt(0, n - 1, tmp, a);
    if (pos != -100) {
        if (choice == 2) {
            a[pos].in_thong_tin();
        }
        else if (choice == 1) {
            cout_tieu_de();
//            cout << pos << " ";
  //          cout << "\n";
            cout_co_noi_dung(a, pos);
        }

        pos += 1;
        while (a[pos].stt == a[pos - 1].stt){
            if (choice == 2){
                a[pos].in_thong_tin();
            }
            else if (choice == 1){
                cout_co_noi_dung(a, pos);
            }
            pos += 1;
        }
    }
    else {
        if (choice == 1){
            cout_Khong_KQ();
        }
        else if (choice == 2){ 
            cout << "Khong co ket qua can tim!!!\n";
        }
    }
}
//==================================================

//================LOC THEO NGAY=====================
bool cmp3(congviec a, congviec b){
    if (a.year != b.year) {
        return a.year < b.year;
    }
    else if (a.month != b.month){
        return a.month < b.month;
    }
    else return a.day < b.day;
}

int tknp_DMY(int d, int c, string tmp, congviec a[]){
    if (d <= c){
        int mid = d + (c - d) / 2;
        if (a[mid].ket_thuc == tmp){
            while (mid - 1 >= 0 && a[mid - 1].ket_thuc == a[mid].ket_thuc){
                mid--;
            }
            return mid;
        }
        else if (a[mid].ket_thuc < tmp) return (tknp_DMY(mid + 1, c, tmp, a));
        else if (a[mid].ket_thuc > tmp) return (tknp_DMY(d, mid - 1, tmp, a));
    }
    return -100;
}

void loc_theo_ngay(congviec a[], string tmp, int n, int choice){
    int test = -1;
    sort(a, a + n, cmp3);
    int pos = tknp_DMY(0, n - 1, tmp, a);
    if (pos != -100) {

        if (choice == 2) {
            a[pos].in_thong_tin();
        }
        else if (choice == 1) {
            cout_tieu_de();
//            cout << pos << " ";
  //          cout << "\n";
            cout_co_noi_dung(a, pos);
        }

    pos += 1;
    while (a[pos].ket_thuc == a[pos - 1].ket_thuc){       
        if (choice == 2){
            a[pos].in_thong_tin();
        }
        else if (choice == 1){
            cout_co_noi_dung(a, pos);
        }

        pos += 1;
        }
    }
    else {
        if (choice == 1){
            cout_Khong_KQ();
        }
        else if (choice == 2){ 
            cout << "Khong co ket qua can tim!!!\n";
        }
    }
}
//==================================================

//=============LOC THEO DO QUAN TRONG================
int tknp_mark(int d, int c, int tmp, congviec a[]){
    if (d <= c){
        int mid = d + (c - d) / 2;
        if (a[mid].mark == tmp){
            while (mid - 1 >= 0 && a[mid - 1].mark == a[mid].mark){
                mid--;
            }
            return mid;
        }
        else if (a[mid].mark < tmp) return (tknp_mark(mid + 1, c, tmp, a));
        else if (a[mid].mark > tmp) return (tknp_mark(d, mid - 1, tmp, a));
    }
    return -100;
}

void loc_theo_muc_do_qtrong(congviec a[], int tmp, int n, int choice){
    sort(a, a + n, cmp1);
    int pos = tknp_mark(0, n - 1, tmp, a);
    if (pos != -100) {
        
        if (choice == 2) {
            a[pos].in_thong_tin();
        }
        else if (choice == 1) {
            cout_tieu_de();
//            cout << pos << " ";
  //          cout << "\n";
            cout_co_noi_dung(a, pos);
        }

        pos += 1;
        while (a[pos].mark == a[pos - 1].mark){
            if (choice == 2){
                a[pos].in_thong_tin();
            }
            else if (choice == 1){
                cout_co_noi_dung(a, pos);
            }
            pos += 1;
        }
    }
    else {
        if (choice == 1){
            cout_Khong_KQ();
        }
        else if (choice == 2){ 
            cout << "Khong co ket qua can tim!!!\n";
        }
    }
}
//=============================================

//=====qua int main() roi ne T^T
int main(){
    congviec a[1000];
    int n = 0;
    while(1){
        cout <<"===============MENU================\n";
        cout << "1: Them thong tin cong viec\n";
        cout << "2: In danh sach cong viec\n";
        cout << "3: Xoa 1 cong viec\n";
        cout << "4: Chinh sua 1 cong viec\n";
        cout << "5: Doc file txt\n";
        cout << "6: Xuat file txt\n";
        cout << "7: Tim kiem\n";
        cout << "8: Thong ke\n";
        cout << "9: Sap xep theo muc do quan trong\n";
        cout << "10: CHUC NANG 5 - LOC THU 1\n";
        cout << "11: CHUC NANG 5 - LOC THU 2\n";
        cout << "12: CHUC NANG 5 - LOC THU 3\n";
        cout << "0: Thoat\n";
        cout <<"===================================\n";
        cout << "Nhap lua chon: "; int chon; cin >> chon;

        if (chon == 1){
            a[n].them_thong_tin();
            n++;
        }
        if (chon == 2){
        cout <<"===================================\n";
            in_danh_sach(a, n);
        }
        if (chon == 3){
            in_danh_sach(a, n);
            cout << "\nNhap STT cua cong viec ma ban muon xoa: "; cin >> stt;
            stt -= 1;
            xoa(a, n, stt);
        }
        if (chon == 4){
            //in danh sach de cho nguoi ta coi ne'
            in_danh_sach(a, n);
            //xu li
            cout << "\nNhap STT cua cong viec ma ban muon chinh sua: "; cin >> stt;
            stt -= 1;
            chinhsua(a, stt);
        }
        if (chon == 5){//doc file
            doc_du_lieu(a, n);
        }
        if (chon == 6){//xuat file
            xuat_du_lieu(a, n);
        }
        if (chon == 7){//tim kiem theo keyword, nhap gi cx dc, kiem gi cx co'
            string keyword;
            cout << "Nhap tu khoa ban muon tim kiem: "; cin >> keyword;
            cout << "Ban co muon xuat ket qua ra file TXT khong?\n";
            cout << "1. Co\n";
            cout << "2. Khong\n";
            cout << "Moi nhap lua chon: "; int choice; cin >> choice;
            CN_1(a, keyword, n, choice);
        }
        if (chon == 8){//Thong ke TRANG THAI
            CN_2(a, n);
        }
        if (chon == 9){//sap xep theo muc do quan trong
            CN_3(a, n);
            in_danh_sach(a, n);
        }
        if (chon == 10){
            cout << "\nLoc theo trang thai\n";
            cout << "1: Chua hoan thanh\n";
            cout << "2: Dang lam\n";
            cout << "3: Hoan thanh\n";
            cout << "4: Bi huy\n";
            cout << "5: Qua han\n";
            cout << "\nHay nhap so: ";
            int tmp;
            cin >> tmp;
            cout << "\nBan co muon xuat ket qua ra file TXT khong?\n";
            cout << "1. Co\n";
            cout << "2. Khong\n";
            cout << "Moi nhap lua chon: "; int choice; cin >> choice;
            CN_5_1(a, tmp, n, choice); //xuli

        }
        if (chon == 11){//loc theo ngay bat ki
            string s;
            cout << "Nhap ngay ket thuc ban muon loc (DD/MM/YYYY): "; cin >> s;
            for (int i = 0; i < n; i++){
                a[i].phan_tich();
            }
            cout << "\nBan co muon xuat ket qua ra file TXT khong?\n";
            cout << "1. Co\n";
            cout << "2. Khong\n";
            cout << "Moi nhap lua chon: "; int choice; cin >> choice;
            
            //YEU CAU NHAP DUNG DINH DANG DD/MM/YYYY
            loc_theo_ngay(a, s, n, choice);
        }
        if (chon == 12){//Loc theo muc do quan trong
            cout << "\nLoc theo muc do quan trong\n";
            cout << "1: Cong viec phai xong trong ngay\n";
            cout << "2: Cong viec phai xong trong ba ngay\n";
            cout << "3: Cong viec phai xong trong tuan\n";
            cout << "4: Cong viec phai xong trong hai tuan\n";
            cout << "5: Cong viec phai xong trong thang\n";
            cout << "Xin moi nhap lua chon: ";
            int tmp;
            cin >> tmp;
            cout << "\nBan co muon xuat ket qua ra file TXT khong?\n";
            cout << "1. Co\n";
            cout << "2. Khong\n";
            cout << "Moi nhap lua chon: "; int choice; cin >> choice;
            loc_theo_muc_do_qtrong(a, tmp, n, choice);
        }
        else if (chon == 0){
            break;
        }
    }
    return 0;
}
