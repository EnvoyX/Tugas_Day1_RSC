#include <iostream>
#include <string>

using namespace std;

class Departemen{
    public:
        Departemen(string nameDept, string nameChief, int total_member) : nama_dept(nameDept), nama_ketua(nameChief), jml_anggota(total_member){

        }


        string getNameDept(){
            return nama_dept;
        }

        string getNameChief(){
            return nama_ketua;
        }

        int getTotalMember(){
            return jml_anggota;
        }

    private:
        string nama_dept;
        string nama_ketua;
        int jml_anggota;
};

class UKM : public Departemen{
    public:
        UKM (string chiefUKM, string nameDept, string nameChief, int total_member ) : Departemen(nameDept, nameChief, total_member), ketua_ukm(chiefUKM), jml_anggota_ukm(1 + total_member)  {
        }

        void display(){
            cout << "Ketua UKM: " << ketua_ukm <<  ", Jumlah total: " << jml_anggota_ukm << ", Depratemen1: " << getNameDept() << '\n';
        }

    private:
        string ketua_ukm;
        int jml_anggota_ukm;
};



int main(){
    UKM Aksantara("Brenda", "RSC", "Yudha", 100);

    Aksantara.display();

    return 0;
}