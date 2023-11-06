#include <iostream>
#include <vector>
#include <string>
#include <list>


using namespace std;

typedef enum{
    NAM,
    NU
}TypeGioiTinh;

typedef enum{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
}TypeHocLuc;

typedef enum{
    THEO_TEN,
    THEO_MSSV,
    THEO_DIEM_TRUNG_BINH
}TypeSapXep;

class student{
    private:
        string name;
        int age;
        TypeGioiTinh sex;
        int id;
        float math;
        float physics;
        float chemistry;        
    public:
        student(string ten = "", int tuoi = 0, TypeGioiTinh gioiTinh = NAM, int mssv = 0, float toan = 0, float ly = 0, float hoa =0 ) 
                :   name(ten), age(tuoi), sex(gioiTinh), id(mssv),
                    math(toan), physics(ly),chemistry(hoa)
                   {
                        /* static int id = 1000;
                        mssv = id;
                        id++;
                        cout << "MSSV: " << mssv << endl; */
                    }
        
        void settenSv(string ten) ;
        void settuoiSv(int tuoi) ;
        void setgt (TypeGioiTinh gioiTinh);
        void setmssv(int mssv);
        void setDiemToan(float toan);     
        void setDiemLy(float ly) ; 
        void setDiemHoa(float hoa);


        string gettenSv ();
        int gettuoiSv();
        TypeGioiTinh getgt();
        int getmssv();
        float getDiemToan();               
        float getDiemLy();               
        float getDiemHoa();        
        float getDiemTrungBinh();
        TypeHocLuc getHocLuc();

};

void student::settenSv(string ten)    {name = ten;}
void student::settuoiSv(int tuoi)      {age = tuoi;} 
void student::setgt (TypeGioiTinh gioiTinh) {sex = gioiTinh;}
void student:: setmssv (int mssv)     {id = mssv;}
void student::setDiemToan(float toan){ math = toan;}
void student::setDiemLy(float ly){ physics = ly;}
void student::setDiemHoa(float hoa){ chemistry = hoa;}



string student::gettenSv () {return name;}
int  student::gettuoiSv() {return age;}
TypeGioiTinh student::getgt() {return sex;}    
int student::getmssv() {return id;}
float student::getDiemToan() { return  math; } 
float student::getDiemLy(){ return physics; }  
float student::getDiemHoa(){ return chemistry; }
float student::getDiemTrungBinh() {return (math + physics +chemistry) / 3;}
TypeHocLuc student::getHocLuc(){
            if(getDiemTrungBinh() >= 8.0){
                return GIOI;
            }else if(getDiemTrungBinh()>= 7.0){
                return KHA;
            }else if(getDiemTrungBinh() >= 5.0){
                return TRUNG_BINH;
            }else{ return YEU; }
        };

class Menu{
    private:
        list <student> Database;
    public:
        void themSinhVien(student sv);        
        void suaSinhVien(int mssv);
        int xoaSinhVien(int mssv);
        list <student> danhSachSinhVien();
        void sapXepSinhVien(TypeSapXep sapXep);
};

void Menu::themSinhVien(student sv){
    Database.push_back(sv);
};

void Menu:: suaSinhVien(int mssv){
    int  tuoi,gt,in,id;
    float toan, ly, hoa;
    string ten;
    TypeGioiTinh gt1;     
    for (list <student> :: iterator i = Database.begin(); i != Database.end(); i++ ){
         if ( mssv ==  i -> getmssv()){
            cout << "Nhap ten: "; cin >> ten;  
            i->settenSv(ten) ;

        back4:      
             cout << "Nhap tuoi: " ; cin >> tuoi;
             if (tuoi < 0 || tuoi > 50)
                  {  cout << "Tuoi khong hop le !!" << endl;;
                     goto back4;
                     }  
             i->settuoiSv(tuoi);
 
             cout << "Chon gioi tinh (0 NAM/ 1 NU): "; cin >> gt;
             if(gt == 0){ 
                 gt1 = NAM;            
                 }
              else if(gt == 1) gt1 = NU; 
              i-> setgt(gt1);

             cout << "Nhap mssv: " ; cin >> id;
              i-> setmssv(id);

         back1:
             cout << "Nhap diem Toan: ";  cin >> toan;  
             if (toan < 0 || toan > 10)
                  {  cout << "Diem khong thoa man nhap lai !!" << endl;
                     goto back1;
                     }  
             i-> setDiemToan(toan);

         back2:     
              cout << "Nhap diem Ly: "; cin >> ly;;
             if (ly < 0 || ly > 10)
                  {  cout << "Diem khong thoa man nhap lai !!" << endl;
                     goto back2;
                     } 
              i-> setDiemLy(ly);

         back3:  
             cout << "Nhap diem Hoa: "; cin >> hoa;
             if (hoa < 0 || hoa > 10)
                  {  cout << "Diem khong thoa man nhap lai !!" << endl;
                     goto back3;
                     } 
             i-> setDiemHoa(hoa); 
             //return 1;          
         }        
}
          cout << " Khong tim thay MSSV !!" << endl;
}

int Menu :: xoaSinhVien(int mssv){    
    for (list <student> :: iterator i = Database.begin(); i != Database.end(); i++ ){
        if ( mssv ==  i -> getmssv()){
             Database.erase(i);
             cout << "DONE !!" << endl;
             return 1;
        }        
    }
    cout << " Khong tim thay MSSV !!" << endl;
}

list<student> Menu::danhSachSinhVien(){   
    return Database;
};
bool compare_id(list<student>::iterator i1, list<student>::iterator i2){
    if(i1->getmssv() > i2->getmssv() )
    return true;
    else return false;
}

bool compare_name (list<student>::iterator i1, list<student>::iterator i2){
    int i=0;   
    while(i1->gettenSv()[i] == i2->gettenSv()[i] && i1->gettenSv()[i] != '\0' && i2->gettenSv()[i] != '\0'){
        i++;
    }

    if ((int)i1->gettenSv()[i] - (int)i2->gettenSv()[i] > 0){
        return true;
    } else
    return false;
}

bool compare_diem (list<student>::iterator i1, list<student>::iterator i2){
    if(i1->getDiemTrungBinh() < i2->getDiemTrungBinh())
    return true;
    else return false;
}

void sort(list <student> *menuu, bool (*compare)(list<student>::iterator i1,list<student>::iterator i2)){
    
     for(list<student>::iterator i = menuu->begin(); i != menuu->end(); i++){
        for(list<student>::iterator j = menuu->begin(); j != menuu->end(); j++){
            if(compare(j,i)){
            student temp = *i;
            *i = *j;
            *j = temp;
        }
      }      
    }
    cout << "DONE !!" << endl;
}  

void Menu:: sapXepSinhVien(TypeSapXep sapXep){
    switch (sapXep)
    {
    case THEO_TEN:
        sort(&Database,compare_name);
        break;
    case THEO_MSSV:
        sort(&Database,compare_id);
        break;
    case THEO_DIEM_TRUNG_BINH:
        sort(&Database,compare_diem);
        break; 
    default:
        break;
    }
}
  
void add_infor(Menu *mn){
    //Menu mn;
    int  tuoi,gt, mssv,in;
    float toan, ly, hoa;
    string ten;
    TypeGioiTinh gt1;     
    back:
    cout << "-----------------------------------" << endl;
    cout <<"         THONG TIN SINH VIEN " << endl;
    cout << "-----------------------------------" << endl;
        cout << "Nhap ten: "; cin >> ten;  
        back4:      
        cout << "Nhap tuoi: " ; cin >> tuoi;
             if (tuoi < 0 || tuoi > 50)
                  {  cout << "Tuoi khong hop le !!" << endl;;
                     goto back4;
                     }   
        cout << "Chon gioi tinh (0 NAM/ 1 NU): "; cin >> gt;
        if(gt == 0){ 
            gt1 = NAM;            
            }
        else if(gt == 1) gt1 = NU; 
         cout << "Nhap mssv: " ; cin >> mssv;
         back1:
         cout << "Nhap diem Toan: ";  cin >> toan;  
             if (toan < 0 || toan > 10)
                  {  cout << "Diem khong thoa man nhap lai !!" << endl;
                     goto back1;
                     }               
         back2:     
         cout << "Nhap diem Ly: "; cin >> ly;;
             if (ly < 0 || ly > 10)
                  {  cout << "Diem khong thoa man nhap lai !!" << endl;
                     goto back2;
                     } 
         back3:  
         cout << "Nhap diem Hoa: "; cin >> hoa;
            if (hoa < 0 || hoa > 10)
                  {  cout << "Diem khong thoa man nhap lai !!" << endl;
                     goto back3;
                     }   
         student sv (ten,tuoi,gt1,mssv,toan,ly,hoa);        
         mn->themSinhVien(sv);
         cout << "------------------------------------" << endl;
         cout << "Ban co muon tiep tuc (0 Quay lai / 1 Tiep tuc): ";
         cin >> in;
         if (in == 1) 
         goto back;
         else if (in == 0) ;
};

void list_infor(Menu *mn){    
    list<student> result ;
    result = mn->danhSachSinhVien();
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                             DANH SACH SINH VIEN " << endl;
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;
    for (list <student> :: iterator i = result.begin(); i != result.end(); i++){
       cout <<"| Ten: " << i->gettenSv();
       cout <<" | Tuoi: " <<i->gettuoiSv() ;
       cout << " | Gioi tinh: ";
    if (i->getgt() == NAM ) cout << "Nam ";
        else cout << "Nu ";
       cout << " | MSSV: " <<i->getmssv();
       cout << " | Toan: "<< i->getDiemToan();
       cout << " | Ly: " << i->getDiemLy();
       cout << " | Hoa: " << i->getDiemHoa();
       printf( " | DTB: %.2f",  i->getDiemTrungBinh());
       cout << " | Hoc luc: " ;
         if (i->getHocLuc() == GIOI) cout << " Gioi\n" ;
             else  if (i->getHocLuc() == KHA) cout << " Kha |\n" ; 
             else if (i->getHocLuc() == TRUNG_BINH) cout << " TB |\n" ;
             else if (i->getHocLuc() == YEU) cout << "Yeu |\n" ; 
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;
} 
}

void modify_infor(Menu *mn){    
    int mssv;
    cout << "-----------------------------------" << endl;
    cout <<"            SUA SINH VIEN " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Nhap MSSV: ";
    cin >> mssv;
    mn->suaSinhVien(mssv);
}

void delete_infor(Menu *mn){
    int mssv;
    cout << "-----------------------------------" << endl;
    cout <<"            XOA SINH VIEN " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Nhap MSSV: ";
    cin >> mssv;
    mn->xoaSinhVien(mssv);
}

void arrange_infor(Menu *mn){
    int type;
    TypeSapXep typei;
    cout << "-------------------------------------------------------------------" << endl;
    cout <<"                         SAP XEP SINH VIEN " << endl;
    cout << "-------------------------------------------------------------------" << endl;
    back:
    cout << "Nhap doi tuong sap xep (0 Theo ten/ 1 Theo mssv/ 2 Theo DTB): "; 
    cin >> type;
    if (type != 0 && type != 1 && type != 2 ){
        cout << "Khong thoa man !!" << endl;
        goto back;
    }
    typei = (TypeSapXep)type;
    //cout << "ahihi !!" << endl;
    mn->sapXepSinhVien(typei);
}

int main(int argc, char const *argv[])
{   Menu mn;
    int chon;
    backk:
    cout << "----------------------" << endl;
    cout << "    MENU SINH VIEN " << endl;
    cout << "----------------------" << endl;
    cout << " 1. Them sinh vien. \n " << "2. Sua sinh vien. \n" << " 3. Xoa sinh vien. \n " << "4. Danh sach sinh vien. \n " 
    << "5. Sap xep sinh vien. \n " << "0. Thoat." << endl;   
    cout << "---------------------" << endl;
    cout << " Nhap lua chon:";
    cin >> chon;   
    switch (chon)
    {
    case 1:
        add_infor(&mn);
        goto backk;
        break;
    case 2:
        modify_infor(&mn);
        goto backk;
        break;
    case 3:
        delete_infor(&mn);
        goto backk;
        break;
    case 4: 
        list_infor(&mn);
        goto backk;
        break;
    case 5: 
        arrange_infor(&mn);
        goto backk;
        break;
    case 0:
        break;   
    default:
        cout << " Lua chon khong ton tai !!" << endl;
        goto backk;
        break;
    }
    //mn.themSinhVien(sv);
    return 0;
}
