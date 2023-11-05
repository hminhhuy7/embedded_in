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

class SinhVien{
    private:
        string tenSinhVien;
        int tuoiSinhVien;
        TypeGioiTinh gioiTinhSinhVien;
        int mssv;
        float monToan;
        float monLy;
        float monHoa;        
    public:
        SinhVien(string ten, int tuoi, TypeGioiTinh gioiTinh,int mssv, float toan, float ly, float hoa  ) 
                :   tenSinhVien(ten), tuoiSinhVien(tuoi), gioiTinhSinhVien(gioiTinh), mssv(mssv),
                    monToan(toan), monLy(ly), monHoa(hoa)
                   {
                        /* static int id = 1000;
                        mssv = id;
                        id++;
                        cout << "MSSV: " << mssv << endl; */
                    }
        int getMSSV(){  return mssv; }
        string tenSv() {return tenSinhVien;}
        int tuoiSv() {return tuoiSinhVien;} 

        TypeGioiTinh gt (TypeGioiTinh gioiTinh){
            if (gioiTinh == NAM) return NAM;
            else return NU;
        }  

        void setDiemToan(float toan){ monToan = toan; }         
        float getDiemToan(){ return   monToan; }    

        void setDiemLy(float ly){ monLy = ly; }         
        float getDiemLy(){ return monLy; } 

        void setDiemHoa(float hoa){ monHoa = hoa; }         
        float getDiemHoa(){ return monHoa; }   
        
        float getDiemTrungBinh(){ return (monToan + monLy + monHoa)/3; }

        TypeHocLuc getHocLuc(){
            if(getDiemTrungBinh() >= 8.0){
                return GIOI;
            }else if(getDiemTrungBinh()>= 7.0){
                return KHA;
            }else if(getDiemTrungBinh() >= 5.0){
                return TRUNG_BINH;
            }else{ return YEU;  }
        }

};

class Menu{
    private:
        list <SinhVien> Database;
    public:
        void themSinhVien(SinhVien sv);
        void xoaSinhVien(int mssv);
        void suaSinhVien(int mssv);
        list <SinhVien> danhSachSinhVien();    
        void dislay();
        void sapXepSinhVien(TypeSapXep sapXep);
};

void Menu::themSinhVien(SinhVien sv){
    Database.push_back(sv);
}

list<SinhVien> Menu::danhSachSinhVien(){
    list<SinhVien> result;
       for(list <SinhVien> :: iterator i = Database.begin(); i != Database.end(); i++){
        result.push_back(*i);
        i->
    }  
    /* for(auto i : Database){
        cout << i << endl;
    } */

   
    //return result;
}
  
  

int main(int argc, char const *argv[])
{
    int chon, tuoi,gt, mssv;
    float toan, ly, hoa;
    string ten;
    TypeGioiTinh gt1;  

   // SinhVien sv;
    Menu mn;    
    cout << " THONG TIN SINH VIEN " << endl;
    cout << "----------------------" << endl;
    cout << " 1. Them sinh vien. \n " << "2. Sua sinh vien. \n" << " 3. Xoa sinh vien. \n " << "4. Danh sach sinh vien. \n " 
    << "5. Sap xep sinh vien. \n " << "0. Thoat." << endl;   
    cout << "---------------------" << endl;
    cout << " Nhap lua chon:";
    cin >> chon;
    


    if (chon == 1){       
        back:
        cout << "----------------------" << endl;
        cout << "Nhap ten: "; cin >> ten;        
        cout << "Nhap tuoi: " ; cin >> tuoi;
        cout << "Chon gioi tinh (0 NAM/ 1 NU)"; cin >> gt;
        if(gt == 0){ 
            gt1 = NAM;            
            }
        else if(gt == 1) gt1 = NU; 
         cout << "Nhap mssv: " ; cin >> mssv;
         cout << "Nhap diem Toan: "; cin >> toan;
         cout << "Nhap diem Ly: ";  cin >> ly;
         cout << "Nhap diem Hoa: "; cin >> hoa;
         SinhVien sv(ten,tuoi,gt1,mssv,toan,ly,hoa);                             
         mn.themSinhVien(sv);    
         mn.danhSachSinhVien();
        
         //goto back;        
    }


    else if (chon == 4){        
     mn.danhSachSinhVien();
    
    }




    
    

    //mn.themSinhVien(sv);
    return 0;
}
