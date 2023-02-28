#include <iomanip> // for setw and setfill stream manipulators
#include <stdexcept> // for invalid_argument exception class
#include <sstream> // for ostringstream class
#include <string>
#include "biblioteka.h"
#include <iostream>



// funksionet per klasen biblioteka:

Biblioteka::Biblioteka(string a[40]){
    set_Biblioteka(a);
    set_ID_table();
    set_tabela_Librave_marre();



}

int Biblioteka::saLibra() const {
    return libra_gjithsej;
}

void Biblioteka::set_Biblioteka(string a[40]) {

    for(int i = 0; i < 40; i++) {  //inicializimi i tabeles se librave ne biblioteke
        librat[i] = "0";
    }

    bool k = true;
    int i = 0;

    while(k==true) { //plotesimi i tabeles me librat i marre input nga perdoruesi

        cout << "Vendos titullin e librit: " << endl;
        string x;
        cin >> x;
        a[i] = x;
        i++;
        cout << "Ka me libra? 1-po, 0-jo:" << endl;
        int j;
        cin>> j;
        k = (j==1)? true:false;
    }
    for(int j = 0; j < i; j++) {
        cout << a[j] << " ";
    }
    cout << endl;
    for(int j = 0; j < i; j++) {
        librat[j] = a[j];
    }
    libra_gjithsej = i;

}

int Biblioteka::searchLiber(array<string,40> a, string k) {
    for(int i = 0; i < 40; i++) {
        if(a[i] == k) {
            return i;
        }
    }
    return -1;
}



int Biblioteka::vende_Bosh() { //kthen indeksin e vendit bosh nese ekziston, dhe -1 nese nuk ka vende bosh
    
    for (int i = 0; i < 10; i++) {
        if (vendet[i] == 0) {
            return i;
        }   
    }
    return -1;
}

array<int, 10> Biblioteka::get_vendet() {
    array<int, 10> k;
    for (int i = 0; i < 10; i++) {
        k[i] = vendet[i];
    }                                         //kthen tabelen e vendeve
    return k;
}
void Biblioteka::printo_Vendet() {
    for(int i =0; i < 10; i++) {
        cout << vendet[i] << "  ";
    }
    cout << endl;
}


array<string, 40> Biblioteka::get_librat() { //fun qe kthen tabelen e librave
    array<string, 40> k;
    for(int i = 0; i< 40; i++) {
        k[i] = librat[i];
    }
    return k;
}
void Biblioteka::printoLibrat() {
    for (int i = 0; i < libra_gjithsej; i++) {
        cout << librat[i] <<"  ";
    }
    cout << endl;
}

string Biblioteka::get_Liber(string l) { //shikon nese nje liber i caktuar gjendet ne biblioteke

    for(int i=0; i < libra_gjithsej; i++) {
        if(librat[i] == l) {
            librat[i] = "0";
            libra_gjithsej--;
            return "Libri i kerkuar gjendet ketu! ";
        }
        
    }
    return "Libri i kerkuar nuk gjendet! ";
}

void Biblioteka::set_Liber(string a) { //shton nje liber ne biblioteke
  
    for(int i = 0; i < 40; i++) {
        if(librat[i] == "0") {
            librat[i] = a;
            libra_gjithsej++;
            break;   
        }   
    }
    cout << "Libri u shtua ne biblioteke! " << endl;

}

void Biblioteka::set_libra_0(int a) {
    librat[a] = "0";
}

int Biblioteka::get_id_total() const {
    return id_pa_kthyerLibra_gjith;
}

int Biblioteka::get_ID(int id) {        //kthen vendin ku ndodhet id e kerkuar dhe ate vend e markon 0
    for(int i = 0; i < 40; i++) {
        if(id == id_pa_kthyerLibra[i]) {
            id_pa_kthyerLibra[i] = 0;
            id_pa_kthyerLibra_gjith--;
            return i;
        }
    }
    return -1;
}

void Biblioteka::set_id_0(int a) {
    id_pa_kthyerLibra[a] = 0;
}

void Biblioteka::set_ID(int id) {  //shton nje id ne tabelen id ne vendin e pare qe eshte bosh
    for(int i = 0; i < 40; i++) {
        if (id_pa_kthyerLibra[i] == 0) {

            id_pa_kthyerLibra[i] = id;
            id_pa_kthyerLibra_gjith++;
            break;
        }  
    }
}

void Biblioteka::set_ID_table() {            //inicializimi i tabeles se id qe nuk kane kthyer librat. si fillim eshte 0.
    for(int i=0; i < 40; i++) {
        id_pa_kthyerLibra[i] = 0;
    }
}

void Biblioteka::printo_ID() {
    for (int i =0; i < id_pa_kthyerLibra_gjith; i++) {
        cout << id_pa_kthyerLibra[i] << " ";
    }
    cout << endl;
}


int Biblioteka::search_liber_marre(string a) {
    for(int i = 0; i < libra_marre_gjith; i++) {
        if(a==librat_marre[i]) {
            return i;
        }

    }
    return -1;
}

void Biblioteka::set_libra_marre_0(int a) {
    librat_marre[a] = "0";

}
int Biblioteka::get_libra_marre_total() const{
    return libra_marre_gjith;
}
void Biblioteka::printo_libra_marre() {
    for (int i = 0; i < get_libra_marre_total(); i++) {
        cout << librat_marre[i] << "  ";
    }
    cout << endl;
}

void Biblioteka::set_tabela_Librave_marre() {
    for (int i = 0; i < 40; i++) {
        librat_marre[i] = "0";
    }
    
}



int Biblioteka::get_Liber_marre(string k) { //kthen indeksin ku ndodhet libri ne tabelen e librave te marre nese libri gjendet aty dhe -1 nese libri nuk eshte aty.
    for(int i=0; i < 40; i++) {
        if(k == librat_marre[i]) {
            librat_marre[i] = "0";
            libra_marre_gjith--;
            cout << "Heqja e elementit: " << k <<" u be me sukses ne tabelen e librave te marre!" << endl;
            set_Liber(k); //gjithashtu librin e hequr nga aty e shton ne tabelen e librave te bibliotekes
            
            return i;
        }   
    }
    return -1;
}

string Biblioteka::set_Liber_marre(string a) {
    for(int i = 0; i < 40; i++) { //shtimi i librit ne tabelen e librave te marre ne vendin e pare bosh
        if(librat_marre[i] == "0") {
            librat_marre[i] = a;
            libra_marre_gjith++;
            

            for (int i = 0; i < libra_gjithsej; i++) { //heqja e librit nga tabela e librave te disponueshem

                if (librat[i] == a) {
                   librat[i] = "0";
                   libra_gjithsej--;
                    break;
                }  
            } 
            return "Shtimi i librit ne tabelen e librave te marre u krye me sukses! ";
        }
        
    }
    return "Nuk ka me vend per te shtuar librin ose dicka ka shkuar gabim! ";
    
}

void Biblioteka::set_vend() { // markon vendin e pare bosh si te zene nese nje klente ulet per te lexuar
    int k = vende_Bosh();
    vendet[k] = 1;

}

void Biblioteka::print_biblioteka() {
    cout << "Librat e pranishem ne biblioteke jane: ";
    printoLibrat();
    cout << endl;

    cout << "Librat e marre nga biblioteka jane: ";
    printo_libra_marre();
    cout << endl;

    cout << "Vendet ne biblioteke te zene dhe jo te zene jane te paraqitur: ";
    printo_Vendet();
    cout << endl;

    cout << "ID qe kane marre libra jane: ";
    printo_ID();
    cout << endl;

    cout << "Libra te disponueshem ne biblioteke gjithsej jane: "<< saLibra() << endl;
    cout << "Libra te marre nga biblioteka gjithsej jane: " << get_libra_marre_total() << endl;
    cout <<"ID pa kthyer librat gjithsej jane: " << get_id_total() << endl;
}
//***********************************************************************************************************************************
//implementimi i klases se klientit


Klienti::Klienti(int a) {
    setID(a);
    
}

Klienti::~Klienti() {
    cout << "Destruktori per klasen e klientit u aktivizua" << endl;
}

void Klienti::setID(int a) {
    id = a;
}

int Klienti::getID() const {
    return id;
}

void Klienti::set_Libri_Deshiron(string a) {
    libri_qeDeshiron = a;
}

string Klienti::get_Libri_Deshiron() const{
    return libri_qeDeshiron;
}

void Klienti::set_Libri_Dorezon(string a) {
    libri_qeDorezon = a;
}

string Klienti::get_Libri_Dorezon() const {
    return libri_qeDorezon;
}


int Klienti::get_libra_paDorezuar() const {
    return libra_pa_dorezuar;
}
void Klienti::set_libra_paDorezuar(int a) {
    libra_pa_dorezuar = a;
}

void Klienti::print_Klienti() {
    cout << "ID e Klientit eshte: " << getID() << endl;

    cout <<"Sa libra ka klienti pa dorezuar: " << get_libra_paDorezuar() << endl;
    cout << "Libri qe deshiron klienti eshte: " <<get_Libri_Deshiron() << endl;
    cout << "Libri qe dorezon klienti: " << get_Libri_Dorezon () << endl;

}

bool Klienti::lexim_biblioteke() {
    cout << "Deshirone te lexoni ne biblioteke: " << endl;
    int k;
    cout << "Shkruani 1-po, 0-jo: " << endl;
    cin >> k;
    if(k==1) {
        return true;
    } else {
        return false;
    }
}


//*********************************************************************************
//klasa datat

void Data::print_Datat() {
    cout << "Data e marrjes se librit: " << get_dita_marrjes() <<":" <<get_muaji_marrjes() <<":" << get_viti_marrjes() << endl;
    cout << "Data e dorezimit te librit: "<< get_dita_dorezimit() <<":" <<get_muaji_dorezimit() <<":" << get_viti_dorezimit() << endl;

    cout <<"Koha e mbajtjes se librit: " << koha_mbajtjes_librit() << endl;
}
Data::Data(int a, int b, int c) {
    set_data_marrjes(a,b,c);

}

Data::~Data() {
    cout << "Destruktori per klasen data u ekzekutua! " << endl;
}

void Data::set_data_marrjes(int a, int b, int c) {
    set_dita_marrjes(a);
    set_muaji_marrjes(b);
    set_viti_marrjes(c);
}

void Data::set_dita_marrjes(int a) {
    dita_marrjes = a;
}
void Data::set_muaji_marrjes(int a) {
    muaji_marrjes = a;
}
void Data::set_viti_marrjes(int a) {
    viti_marrjes = a;
}

int Data::get_dita_marrjes() const{
    return dita_marrjes;
}
int Data::get_muaji_marrjes() const{
    return muaji_marrjes;
}
int Data::get_viti_marrjes() const{
    return viti_marrjes;
}


void Data::set_data_dorezimit(int a, int b, int c) {
    set_dita_dorezimit(a);
    set_muaji_dorezimit(b);
    set_viti_dorezimit(c);
}

void Data::set_dita_dorezimit(int a) {
    dita_dorezimit = a;
}
void Data::set_muaji_dorezimit(int a) {
    muaji_dorezimit = a;
}
void Data::set_viti_dorezimit(int a) {
    viti_dorezimit = a;
}


int Data::get_dita_dorezimit() const{
    return dita_dorezimit;
}

int Data::get_muaji_dorezimit() const{
    return muaji_dorezimit;
}
int Data::get_viti_dorezimit() const{
    return viti_dorezimit;
}

int Data::koha_mbajtjes_librit() {
    int v = get_viti_dorezimit() - get_viti_marrjes();
    int m = get_muaji_dorezimit() - get_muaji_marrjes();
    int d = get_dita_dorezimit() - get_dita_marrjes();

    return v*365 + m * 30 +d;
}


//lidhja e klasave

void marrja_librit(Biblioteka& b, Klienti& k, Data& d) {
    
    

    if (k.get_libra_paDorezuar() != 0) {
        cout << "Klienti  " << k.getID() << "nuk mund te marri nje liber sepse ka nje tjeter pa dorezuar! " << endl; 
    } else {
        cout << "Vendosni nje liber qe deshironi te lexoni: " << endl;
        string libri;
        cin >> libri;
        k.set_Libri_Deshiron(libri);
        string l = k.get_Libri_Deshiron();
        k.set_Libri_Deshiron("0");
        int ndodhet = b.searchLiber(b.get_librat(),l);
        if (ndodhet != -1) {
            k.set_Libri_Dorezon(l); //paraqitja e librit ne librat qe klienti ka
            b.set_Liber_marre(l); //shenimi i librit ne tabelen e librave te marre

            cout << "Shenoni daten e marrjes se librit: " << endl;
            cout << "Dita: ";
            int dita;
            cin >> dita;
            cout << "Muaji: ";
            int muaji;
            cin >> muaji;
            cout << "Viti: ";
            int viti;
            cin >> viti;
            cout << endl;
            d.set_data_marrjes(dita, muaji, viti); //shenimi i dates se marrjes
            b.set_ID(k.getID()); //shtimi i id ne tabelen e id

            bool vend = k.lexim_biblioteke();
            if (vend==true) {
                cout << "Klienti pelqen te lexoje ne biblioteke!" << endl;
                int i = b.vende_Bosh();
                if(i==-1) {
                   cout << "Ne biblioteke nuk ka vende te lira! " << endl;
                } else {
                    cout << "Klienti mund te ulet ne pozicionin: " << b.vende_Bosh() << endl;
                    b.set_vend();
                }
                cout << "Sherbimi i marrjes se librit u krye me sukses! " << endl << endl << endl;
                k.set_libra_paDorezuar(k.get_libra_paDorezuar() - 1);
            }else {
                
                cout << "Sherbimi i marrjes se librit u krye me sukses! " << endl << endl << endl;
                k.set_libra_paDorezuar(k.get_libra_paDorezuar() - 1);

            }
        } else {
            int y = b.search_liber_marre(l);
            if(y == -1) {
                cout <<"Biblioteka nuk ka nje liber te tille!" << endl << endl << endl;
            } else {
                cout << "Libri per momentin eshte duke u lexuar!" << endl << endl << endl;
            }
        }
    }
    
    
}

void dorezimi_librit(Biblioteka& b, Klienti& k, Data& d) {

    cout <<"******************************************************************************" << endl;

    if(k.get_libra_paDorezuar() != 0) {
        cout << "Klienti ka liber pa dorezuar! " << endl;
        cout << endl;
        cout << "Vendosni daten qe klienti ka ardhur per te dorezuar librin: " << endl;
        cout <<"Dita: ";
        int dita;
        cin >> dita;
        cout <<"Muaji: ";
        int muaji;
        cin >> muaji;
        cout << "Viti: ";
        int viti;
        cin >> viti;
        d.set_data_dorezimit(dita,muaji,viti);
        string l = k.get_Libri_Dorezon();

        if(b.search_liber_marre(l) == -1) {
           cout << "Libri nuk eshte marre ne biblioteken tone!" << endl << endl;

        } else {
            
            if(d.koha_mbajtjes_librit() > 14) {

               cout << "Ju nuk mund ta dorezoni librin pa paguar nje gjobe sepse ju ka kaluar afati! " <<endl <<endl;
            
            } else {
                k.set_Libri_Dorezon("0");
                b.get_Liber_marre(l);
                b.get_ID(k.getID());
                cout << "Libri u dorezua me sukses! " << endl << endl;
                k.set_libra_paDorezuar(k.get_libra_paDorezuar() - 1);
            }

        }
        
    }else {
        cout << "Klienti nuk ka liber per te dorezuar! " << endl;
    }
    
}


int main() {
    string a[40];
    Biblioteka b(a);
    Klienti k(125);
    Data d(0,0,0);
    {
        marrja_librit(b,k,d);
        dorezimi_librit(b,k,d);//do gjetur nje menyre si te modifikojme tabelen e vendeve kur dikush dorezon librin
    

    }
    



    

}