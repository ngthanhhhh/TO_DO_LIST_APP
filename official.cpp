#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

bool check[10000];
const int oo = -1e9;
int ind, res1, res2, res3, res4, res5, res6,
    TT1, TT2, TT3, TT4, TT5;

struct task{
    string status, title, priority, beginningDay, endingDay, note;
    int mark, stt, day, month, year;

    void correspondingStatus(){ //Phân loại số thành trạng thái tương ứng
        if (stt == 1){
            status = "Chua hoan thanh";
        }
        else if (stt == 2){
            status = "Dang lam";
        }
        else if (stt == 3){
            status = "Hoan thanh";
        }
        else if (stt == 4){
            status = "Bi huy";
        }
        else if (stt == 5){
            status = "Qua han";
        }
    }

    void correspondingPrio(){//Phân loại số thành độ ưu tiên tương ứng
        if (mark == 1){
            priority = "Trong ngay";
        }
        else if (mark == 2){
            priority = "Trong ba ngay";
        }
        else if (mark == 3){
            priority = "Trong tuan";
        }
        else if (mark == 4){
            priority = "Trong hai tuan";
        }
        else if (mark == 5){
            priority = "Trong thang";
        }
    }

    void addData(){ // Thêm dữ liệu (Nhập tay)
        cout <<"================================================\n";
        
        cout << "Hay chon trang thai cua cong viec: \n";
        cout << "[1]: Chua hoan thanh\n";
        cout << "[2]: Dang lam\n";
        cout << "[3]: Hoan thanh\n";
        cout << "[4]: Bi huy\n";
        cout << "[5]: Qua han\n";
        cout << "Nhap lua chon cho trang thai: "; 
        cin >> stt;

        cout << "Nhap tieu de: "; cin.ignore(); getline(cin, title);

        cout << "Hay chon muc do quan trong cua cong viec: \n";
        cout << "[1]: Trong ngay\n";
        cout << "[2]: Trong ba ngay\n";
        cout << "[3]: Trong tuan\n";
        cout << "[4]: Trong hai tuan\n";
        cout << "[5]: Trong thang\n";
        cout << "Nhap muc do quan trong: "; cin >> mark;

        correspondingStatus(); //Phan loai trang thai de dung cho sap xep/loc/tim kiem
        correspondingPrio();//Phan loai trang thai de dung cho sap xep/loc/tim kiem

        cout << "Nhap ngay bat dau: "; cin >> beginningDay;
        cout << "Nhap ngay ket thuc: "; cin >> endingDay;
        cout << "Nhap ghi chu: "; cin.ignore(); getline(cin, note);
        //cin >>  note;
        cout << "================================================\n";
    }

    void printData(){ //Xuất dữ liệu (Màn hình)
        cout << "-----------------------------------\n";
        cout << "Trang thai: " << status << '\n';
        cout << "Tieu de: " << title << '\n';
        cout << "Muc do quan trong: " << priority << '\n';
        cout << "Ngay bat dau: " << beginningDay << '\n';
        cout << "Ngay ket thuc: " << endingDay << '\n';
        cout << "Ghi chu: " << note << '\n';
    }

    void dateAnalysis(){ //chuyen tu string -> int de sap xep ngay thang nam
        int i = 0;
        day = 0, month = 0, year = 0;
        while (endingDay[i] != '/'){
            day = day * 10 + (endingDay[i] - '0'); 
            i++;
        }
        i++;
        while (endingDay[i] != '/'){
            month = month * 10 + (endingDay[i] - '0'); 
            i++;
        }
        i++;
        int j = i;
        for (int j = i; j < endingDay.length(); j++){
            year = year * 10 + (endingDay[j] - '0'); 
        }        
    }
};

void printList(task a[], int n){ //In danh sách (Màn hình)
    cout <<"================================================\n";
    cout << "Thong tin danh sach cong viec:\n";
    for (int i = 0; i < n; i++){
        cout <<"-----------------------------------\n";
        cout << "STT: " << i + 1 << "\n";
        a[i].printData();
    }
}

void removeData(task a[], int &n, int stt){ //Xóa dữ liệu
    for (int i = stt + 1; i < n; i++){
        a[i - 1] = a[i];
    }
    n -= 1;
}

void edit(task a[], int stt){ //Chỉnh sửa
    int tmp;
    cout << "[1]: Chinh sua trang thai\n";
    cout << "[2]: Chinh sua tieu de\n";
    cout << "[3]: Chinh sua muc do quan trong\n";
    cout << "[4]: Chinh sua ngay bat dau\n";
    cout << "[5]: Chinh sua ngay ket thuc\n";
    cout << "[6]: Chinh sua ghi chu\n";
    cout << "Hay nhap so: ";
    cin >> tmp;
    if (tmp == 1){
        cout << "\nHay chinh sua trang thai cua cong viec!!! \n";
        cout << "[1]: Chua hoan thanh\n";
        cout << "[2]: Dang lam\n";
        cout << "[3]: Hoan thanh\n";
        cout << "[4]: Bi huy\n";
        cout << "[5]: Qua han\n";
        cout << "Xin moi chinh sua trang thai: ";
        cin >> a[stt].stt;
        a[stt].correspondingStatus();
        cout << "\nThao tac thanh cong. <3\n"; 
        cout << "\nVui long an 1 trong 2 phim sau de xem ket qua:\n";
        cout << "[2]: In danh sach cong viec ra man hinh\n";
        cout << "[6]: In danh sach cong viec ra FILE TXT\n";
    }
    if (tmp == 2){
        cout << "\nXin moi chinh sua tieu de: ";
        cin.ignore(); getline(cin, a[stt].title);
        cout << "\nThao tac thanh cong. <3\n"; 
        cout << "\nVui long an 1 trong 2 phim sau de xem ket qua:\n";
        cout << "[2]: In danh sach cong viec ra man hinh\n";
        cout << "[6]: In danh sach cong viec ra FILE TXT\n";
    }
    if (tmp == 3){        
        cout << "\nHay chinh sua muc do quan trong cua cong viec: \n";
        cout << "[1]: Trong ngay\n";
        cout << "[2]: Trong ba ngay\n";
        cout << "[3]: Trong tuan\n";
        cout << "[4]: Trong hai tuan\n";
        cout << "[5]: Trong thang\n";
        cout << "\nXin moi chinh sua muc do quan trong: "; 
        cin >> a[stt].mark;
        a[stt].correspondingPrio();
        cout << "\nThao tac thanh cong. <3\n"; 
        cout << "\nVui long an 1 trong 2 phim sau de xem ket qua:\n";
        cout << "[2]: In danh sach cong viec ra man hinh\n";
        cout << "[6]: In danh sach cong viec ra FILE TXT\n";
    }
    if (tmp == 4){
        cout << "\nXin moi chinh sua ngay bat dau cong viec: ";
        cin >> a[stt].beginningDay;
        cout << "\nThao tac thanh cong. <3\n"; 
        cout << "\nVui long an 1 trong 2 phim sau de xem ket qua:\n";
        cout << "[2]: In danh sach cong viec ra man hinh\n";
        cout << "[6]: In danh sach cong viec ra FILE TXT\n";
    }
    if (tmp == 5){
        cout << "\nXin moi chinh sua ngay ket thuc cong viec: ";
        cin >> a[stt].endingDay;
        cout << "\nThao tac thanh cong. <3\n"; 
        cout << "\nVui long an 1 trong 2 phim sau de xem ket qua:\n";
        cout << "[2]: In danh sach cong viec ra man hinh\n";
        cout << "[6]: In danh sach cong viec ra FILE TXT\n";
    }
    if (tmp == 6){
        cout << "\nXin moi chinh sua ghi chu: ";
        cin.ignore(); getline(cin, a[stt].note);
        cout << "\nThao tac thanh cong. <3\n"; 
        cout << "\nVui long an 1 trong 2 phim sau de xem ket qua:\n";
        cout << "[2]: In danh sach cong viec ra man hinh\n";
        cout << "[6]: In danh sach cong viec ra FILE TXT\n";
    }
}

void readFILE(task a[], int &n){ //ĐỌC từ FILE INP
    ifstream input_file;
    input_file.open("official.inp", ios::in);
    while (!input_file.eof()){
        string s, add[10], tmp;
       // cin.ignore();
         getline(input_file, s);
    //    cout << s << '\n';
        stringstream ss(s);
        getline(ss, tmp, ',');
        add[0] = tmp;
        int size = 1;
        while (getline(ss, tmp, ',')){
            add[size] = tmp.erase(0,1);
            size++;
        }
        a[n].stt = add[0][0] - '0';
        a[n].correspondingStatus();
        a[n].title = add[1];
        a[n].mark = add[2][0] - '0';
        a[n].correspondingPrio();
        a[n].beginningDay = add[3];
        a[n].endingDay = add[4];
        a[n].note = add[5];
        n++;
    }
    input_file.close();
}

void printFILE(task a[], int n){ //Xuất ra FILE TXT
    ofstream output_file;
    output_file.open("OFFICIAL.txt", ios::trunc);
    output_file << "Thong tin danh sach cong viec:\n";
    for (int i = 0; i < n; i++){
        output_file << "-----------------------------------\n";
        output_file << "STT: " << i + 1 << "\n";
        output_file << "Trang thai: " << a[i].status << '\n';
        output_file << "Tieu de: " << a[i].title << '\n';
        output_file << "Muc do quan trong: " << a[i].priority << '\n';
        output_file << "Ngay hien tai: " << a[i].beginningDay << '\n';
        output_file << "Ngay ket thuc: " << a[i].endingDay << '\n';
        output_file << "Ghi chu: " << a[i].note << '\n';
    }
    output_file.close();
}
//nó sẽ cout cái dòng này ra file TXT:)) 
void titleFILE(){
    ofstream output_file;
    output_file.open("OFFICIAL.txt", ios::trunc);
    output_file << "Thong tin danh sach cong viec:\n";
    output_file.close();
}

//xử lí in từng thành phần của công việc ra file TXT
void avaiDataFILE(task a[], int i){
    ofstream output_file;
    output_file.open("OFFICIAL.txt", ios::app);
    output_file << "-----------------------------------\n";
    output_file << "STT: " << i + 1 << "\n";
    output_file << "Trang thai: " << a[i].status << '\n';
    output_file << "Tieu de: " << a[i].title << '\n';
    output_file << "Muc do quan trong: " << a[i].priority << '\n';
    output_file << "Ngay hien tai: " << a[i].beginningDay << '\n';
    output_file << "Ngay ket thuc: " << a[i].endingDay << '\n';
    output_file << "Ghi chu: " << a[i].note << '\n';    
    output_file.close();
}

//sẽ in ra file TXT nếu ko có kết quả
void noResFILE(){
    ofstream output_file;
    output_file.open("OFFICIAL.txt", ios::app);                
    output_file << "-----------------------------------\n";
    output_file << "Khong co ket qua ma ban muon tim kiem!!!\n";
    output_file.close();
}

//====================Chuc nang TIM KIEM THEO YEU CAU================
void sttSearch(task a[], string tmp, int n, bool check[], int choice){
    res1 = -1;
    for (int i = 0; i < n; i++){
        if (a[i].status.find(tmp) != string::npos){
            res1 = i;
            check[i] = true;
            if (choice == 2) a[i].printData();
        }
    }
}

void titleSearch(task a[], string tmp, int n, bool check[], int choice){
    res2 = -1;
    for (int i = 0; i < n; i++){
        if ((check[i] == false) && (a[i].title.find(tmp) != string::npos)){
            res2 = i;
            check[i] = true;
            if (choice == 2) a[i].printData();
        }
    }
}

void prioSearch(task a[], string tmp, int n, bool check[], int choice){
    res3 = -1;
    for (int i = 0; i < n; i++){
        if ((check[i] == false) && (a[i].priority.find(tmp) != string::npos)){
            res3 = i;
            check[i] = true;
            if (choice == 2) a[i].printData();
        }
    }
}

void beginningDaySearch(task a[], string tmp, int n, bool check[], int choice){
    res4 = -1;
    for (int i = 0; i < n; i++){
        if ((check[i] == false) && (a[i].beginningDay.find(tmp) != string::npos)){
            res4 = i;
            check[i] = true;
            if (choice == 2) a[i].printData();
        }
    }
}

void endingDaySearch(task a[], string tmp, int n, bool check[], int choice){
    res5 = -1;
    for (int i = 0; i < n; i++){
        if ((check[i] == false) && (a[i].endingDay.find(tmp) != string::npos)){
            res5 = i;
            check[i] = true;
            if (choice == 2) a[i].printData();
        }
    }
}

void noteSearch(task a[], string tmp, int n, bool check[], int choice){
    res6 = -1;
    for (int i = 0; i < n; i++){
        if ((check[i] == false) && (a[i].note.find(tmp) != string::npos)){
            res6 = i;
            check[i] = true;
            if (choice == 2) a[i].printData();
        }
    }
}


//Tính năng tìm kiếm nè
void firstFeature(task a[], string tmp, int n, int choice){
    for (int i = 0; i < n; i++){
        check[i] = false;
    }

    sttSearch(a, tmp, n, check, choice);
    titleSearch(a, tmp, n, check, choice);
    prioSearch(a, tmp, n, check, choice);
    beginningDaySearch(a, tmp, n, check, choice);
    endingDaySearch(a, tmp, n, check, choice);
    noteSearch(a, tmp, n, check, choice);

    if (choice == 1){
        ofstream output_file;
        titleFILE();
        for (int i = 0; i < n; i++){
            //cout << check[i] << " ";
            if (check[i] == 1) {
                avaiDataFILE(a, i);
            }
        }
        if (res1 == -1 && res2 == -1 && res3 == -1 && res4 == -1 && res5 == -1 && res6 == -1){
            noResFILE();
        }
    }
    else if (choice == 2){
        if (res1 == -1 && res2 == -1 && res3 == -1 && res4 == -1 && res5 == -1 && res6 == -1){
            cout << "-----------------------------------\n";
            cout << "Khong co ket qua ma ban muon tim kiem!!!\n";
        }
    }
}
//=============================================================

//========================Chuc nang THONG KE====================
void secFeature(task a[], int n){
    TT1 = 0; TT2 = 0; TT3 = 0; TT4 = 0; TT5 = 0;
    for (int i = 0; i < n; i++){
        if (a[i].status == "Chua hoan thanh"){
            TT1 += 1;
        }
        if (a[i].status == "Dang lam"){
            TT2 += 1;
        }
        if (a[i].status == "Hoan thanh"){
            TT3 += 1;
        }
        if (a[i].status == "Bi huy"){
            TT4 += 1;
        }
        if (a[i].status == "Qua han"){
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
bool cmp1(task a, task b){
    return (a.mark < b.mark);
}

void thirdFeature(task a[], int n){
    sort(a, a + n, cmp1);
}
//================================================

//===================LOC THEO TRANG THAI====================
bool cmp2(task a, task b){
    return a.stt < b.stt;
}

int findPos1(int d, int c, int tmp, task a[]){
    if (d <= c){
        int mid = d + (c - d) / 2;
        if (a[mid].stt == tmp){
            while (mid - 1 >= 0 && a[mid - 1].stt == a[mid].stt){
                mid--;
            }
            return mid;
        }
        else if (a[mid].stt < tmp) return (findPos1(mid + 1, c, tmp, a));
        else if (a[mid].stt > tmp) return (findPos1(d, mid - 1, tmp, a));
    }
    return oo;
}

void filterStt(task a[], int tmp, int n, int choice){
    sort(a, a + n, cmp2);
    int pos = findPos1(0, n - 1, tmp, a);
    if (pos != oo) {
        if (choice == 2) {
            a[pos].printData();
        }
        else if (choice == 1) {
            titleFILE();
            avaiDataFILE(a, pos);
        }

        pos += 1;
        while (a[pos].stt == a[pos - 1].stt){
            if (choice == 2){
                a[pos].printData();
            }
            else if (choice == 1){
                avaiDataFILE(a, pos);
            }
            pos += 1;
        }
    }
    else {
        if (choice == 1){
            titleFILE();
            noResFILE();
        }
        else if (choice == 2){ 
            cout << "Khong co ket qua can tim!!!\n";
        }
    }
}
//==================================================

//================LOC THEO NGAY=====================
int day1 = 0, month1 = 0, year1 = 0;

void analInp(string s1){ // Tách keyword ngày tháng năm đã nhập từ bàn phím thành số:))
    day1 = 0, month1 = 0, year1 = 0;
    int i = 0;
    while (s1[i] != '/'){
        day1 = day1 * 10 + (s1[i] - '0'); 
        i++;
    }
    i++;
    while (s1[i] != '/'){
        month1 = month1 * 10 + (s1[i] - '0'); 
        i++;
    }
    i++;
    int j = i;
    for (int j = i; j < s1.length(); j++){
        year1 = year1 * 10 + (s1[j] - '0'); 
    }        
}

bool cmp3(task a, task b){
    if (a.year != b.year) {
        return a.year < b.year;
    }
    else if (a.month != b.month){
        return a.month < b.month;
    }
    else return a.day < b.day;
}

bool cmp4(task a){
    if (a.year != year1) {
        return a.year < year1;
    }
    else if (a.month != month1){
        return a.month < month1;
    }
    else return a.day < day1;
}

bool cmp5(task a){
    if (a.year != year1) {
        return a.year > year1;
    }
    else if (a.month != month1){
        return a.month > month1;
    }
    else return a.day > day1;
}

int findPos2(int d, int c, string tmp, task a[]){
    if (d <= c){
        int mid = d + (c - d) / 2;
        if (a[mid].day == day1 && a[mid].month == month1 && a[mid].year == year1){
          //  cout << "COOO\n";
            while (mid - 1 >= 0 && a[mid - 1].endingDay == a[mid].endingDay){
                mid--;
            }
            return mid;
        }
        else if (cmp4(a[mid])) return (findPos2(mid + 1, c, tmp, a));
        else if (cmp5(a[mid])) return (findPos2(d, mid - 1, tmp, a));
    }
    return oo;
}



void filterDay(task a[], string tmp, int n, int choice){
   // int test = -1;
    sort(a, a + n, cmp3);
    int pos = findPos2(0, n - 1, tmp, a);
    //cout << pos << " === ";
    if (pos != oo) {

        if (choice == 2) {
            a[pos].printData();
        }
        else if (choice == 1) {
            titleFILE();
//            cout << pos << " ";
  //          cout << "\n";
            avaiDataFILE(a, pos);
        }

    pos += 1;
    while (a[pos].endingDay == a[pos - 1].endingDay){       
        if (choice == 2){
            a[pos].printData();
        }
        else if (choice == 1){
            avaiDataFILE(a, pos);
        }

        pos += 1;
        }
    }
    else {
        if (choice == 1){
            titleFILE();
            noResFILE();
        }
        else if (choice == 2){ 
            cout << "Khong co ket qua can tim!!!\n";
        }
    }
}
//==================================================

//=============LOC THEO DO QUAN TRONG================
int findPos3(int d, int c, int tmp, task a[]){
    if (d <= c){
        int mid = d + (c - d) / 2;
        if (a[mid].mark == tmp){
            while (mid - 1 >= 0 && a[mid - 1].mark == a[mid].mark){
                mid--;
            }
            return mid;
        }
        else if (a[mid].mark < tmp) return (findPos3(mid + 1, c, tmp, a));
        else if (a[mid].mark > tmp) return (findPos3(d, mid - 1, tmp, a));
    }
    return oo;
}

void filterPrio(task a[], int tmp, int n, int choice){
    sort(a, a + n, cmp1);
    int pos = findPos3(0, n - 1, tmp, a);
    if (pos != oo) {
        
        if (choice == 2) {
            a[pos].printData();
        }
        else if (choice == 1) {
            titleFILE();
//            cout << pos << " ";
  //          cout << "\n";
            avaiDataFILE(a, pos);
        }

        pos += 1;
        while (a[pos].mark == a[pos - 1].mark){
            if (choice == 2){
                a[pos].printData();
            }
            else if (choice == 1){
                avaiDataFILE(a, pos);
            }
            pos += 1;
        }
    }
    else {
        if (choice == 1){
            titleFILE();
            noResFILE();
        }
        else if (choice == 2){ 
            cout << "Khong co ket qua can tim!!!\n";
        }
    }
}
//=============================================

int printMenu() {
    cout << "*=============================MENU=============================*\n";
    cout << "| [1]: Them thong tin cong viec tu ban phim                    |\n";
    cout << "| [2]: In danh sach cong viec ra man hinh                      |\n";
    cout << "| [3]: Xoa 1 cong viec                                         |\n";
    cout << "| [4]: Chinh sua 1 cong viec                                   |\n";
    cout << "| [5]: Them cong viec tu file INP                              |\n";
    cout << "| [6]: In danh sach cong viec ra file TXT                      |\n";
    cout << "| [7]: Tim kiem                                                |\n";
    cout << "| [8]: Thong ke                                                |\n";
    cout << "| [9]: Sap xep theo muc do quan trong                          |\n";
    cout << "| [10]: Loc theo trang thai                                    |\n";
    cout << "| [11]: Loc ra nhung cong viec phai xong trong ngay ban nhap   |\n";
    cout << "| [12]: Loc theo muc do quan trong                             |\n";
    cout << "| [0]: Thoat                                                   |\n";
    cout << "*==============================================================*\n";
    cout << "\n";
    int choice = 0;
    do {
        cout << "Hay nhap lua chon: ";
        cin >> choice;
        if (choice < 0 || choice > 12) {
            cout << "Lua chon khong hop le! Xin vui long nhap lai!!\n";
        }
        else {
            break;
        }
    } while (true);

    return choice;
}

// Trời ơi fix tới int main() lần nữa rồi T^T Kéo xuống tới đây lần thứ n rồi T_T
int main(){
    task a[10000];
    int n = 0;

    int userOption = 0;
    bool mainLoopStop = false;
    while (!mainLoopStop) {
        userOption = printMenu();

        switch (userOption) {
            case (1): {
                a[n].addData();
                n++;
                break;
            }
            case (2): {
                cout <<"================================================\n";
                printList(a, n);
                break;
            }
            case (3): {
                printList(a, n);
                cout << "\nNhap STT cua cong viec ma ban muon xoa: "; cin >> ind;
                ind -= 1;
                removeData(a, n, ind);
                cout << "\nThao tac thanh cong. <3\n"; 
                cout << "\nVui long an 1 trong 2 phim sau de xem ket qua:\n";
                cout << "[2]: In danh sach cong viec ra man hinh\n";
                cout << "[6]: In danh sach cong viec ra FILE TXT\n";
                break;
            }
            case (4): {
                printList(a, n);
                //xu li
                cout << "\nNhap STT cua cong viec ma ban muon chinh sua: "; cin >> ind;
                ind -= 1;
                edit(a, ind);
                break;
            }
            case (5): {            
                readFILE(a, n);
                break;
            }
            case (6): {
                printFILE(a, n);
                break;
            }
            case (7): { // chỉ cần nhập từ khóa, tìm gì cũng có miễn là nó có trong INP:)))
                string keyword;
                cout << "Nhap tu khoa ban muon tim kiem: "; cin.ignore(); getline(cin, keyword);
                cout << "Ban muon xuat ket qua ra file TXT hay ra man hinh?\n";
                cout << "[1]: File TXT\n";
                cout << "[2]: Man hinh\n";
                cout << "Moi nhap lua chon: "; int choice; cin >> choice;
                firstFeature(a, keyword, n, choice);
                break;
            }
            case (8): {
                secFeature(a, n);
                break;
            }
            case (9): {
                thirdFeature(a, n);                
                cout << "\nBan muon xuat ket qua ra file TXT hay ra man hinh?\n";
                cout << "[1]: File TXT\n";
                cout << "[2]: Man hinh\n";
                cout << "Moi nhap lua chon: "; int choice; cin >> choice;
                if (choice == 2) printList(a, n);
                else if (choice == 1) printFILE(a,n);
                break;
            }
            case (10): {
                cout << "\nLoc theo trang thai\n";
                cout << "[1]: Chua hoan thanh\n";
                cout << "[2]: Dang lam\n";
                cout << "[3]: Hoan thanh\n";
                cout << "[4]: Bi huy\n";
                cout << "[5]: Qua han\n";
                cout << "\nHay nhap so: ";
                int tmp;
                cin >> tmp;
                cout << "\nBan muon xuat ket qua ra file TXT hay ra man hinh?\n";
                cout << "[1]: File TXT\n";
                cout << "[2]: Man hinh\n";
                cout << "Moi nhap lua chon: "; int choice; cin >> choice;
                filterStt(a, tmp, n, choice); //xuli
                break;
            }
            case (11): {//loc theo ngay bat ki
                string s;
                do {
                    cout << "Nhap ngay ket thuc ban muon loc (DD/MM/YYYY): "; 
                    cin >> s;
                    analInp(s);
                    if (day1 <= 0 || day1 >= 32 || month1 <= 0 || month1 >= 13 || year1 <= 0){
                        cout << "\nDinh dang khong hop le! Xin vui long nhap dung dinh dang ngay/thang/nam!!\n";
                    }
                    else {
                        break;
                    }
                } while (true);
                for (int i = 0; i < n; i++){
                    a[i].dateAnalysis();
                }
                cout << "\nBan muon xuat ket qua ra file TXT hay ra man hinh?\n";
                cout << "[1]: File TXT\n";
                cout << "[2]: Man hinh\n";
                cout << "Moi nhap lua chon: "; int choice; cin >> choice;
                
                filterDay(a, s, n, choice);
                break;
            }
            case (12): {//Loc theo muc do quan trong
                cout << "\nLoc theo muc do quan trong\n";
                cout << "[1]: Cong viec phai xong trong ngay\n";
                cout << "[2]: Cong viec phai xong trong ba ngay\n";
                cout << "[3]: Cong viec phai xong trong tuan\n";
                cout << "[4]: Cong viec phai xong trong hai tuan\n";
                cout << "[5]: Cong viec phai xong trong thang\n";
                cout << "Xin moi nhap lua chon: ";
                int tmp;
                cin >> tmp;
                cout << "\nBan muon xuat ket qua ra file TXT hay ra man hinh?\n";
                cout << "[1]: File TXT\n";
                cout << "[2]: Man hinh\n";
                cout << "Moi nhap lua chon: "; int choice; cin >> choice;
                filterPrio(a, tmp, n, choice);
                break;
            }

            default: {
                mainLoopStop = true;
                break;
            }
        }
    }
    return 0;
}
