#include <array>
#include <string>
#include <iostream>

using namespace std;

#ifndef BIBLIOTEKA_H
#define BIBLIOTEKA_H

class Data; //ketu behet deklarimi paraprak i klasave ne menyre qe ato te regjistrohen si friends te klases biblioteka
class Klienti;

class Biblioteka{

    friend class Klienti;
    friend class Data;
    friend void marrja_librit(Biblioteka&, Klienti&, Data&);

    public:
    Biblioteka(string []);
    void set_Biblioteka(string []);


    array<string, 40> get_librat();
    void printoLibrat();
    int searchLiber(array<string,40>, string); //kthen 1 nese nje liber gjendet ne biblioteke dhe 0 nese jo
    

    int vende_Bosh(); // nese ka vende bosh, do te kthehet indexi i pare bosh, perndryshe do te kthehet -1
    void set_vend(); // markon vendin e pare bosh si (1-te zene)
    array<int, 10> get_vendet(); //kthen tabelen e vendeve
    void printo_Vendet();
    

    string get_Liber(string); //kthen indeksin ku ndodhet libri dhe -1 nese libri nuk ekziston
    int saLibra() const;
    void set_Liber(string); //vendos librin e kthyer ne tabelen e librave
    void set_libra_0(int); //markon nje indeks ne tabelen e librave me "0" per te treguar qe libri atje eshte marre

    int search_liber_marre(string); //kthen indeksin e librit ne tabelen e librave te marre nese libri eshte, perkundrazi kthen -1
    int get_Liber_marre(string); //rikthen pozicionin e librit nese eshte marre, e markon pozicionin 0, ul librat e marre gjithsej dhe shton librin te librat e disponueshem.
    string set_Liber_marre(string); //vendos librin e marre ne tabelen e librave te marre, rrit librat e marre gjithsej, heq librin nga tabela e librave te disponueshem
    void set_tabela_Librave_marre(); //inicializimi i tabeles se librave te marre me vleren 0
    void set_libra_marre_0(int); //markon me 0 nje pozicion te dhene si indeks ne funksion
    int get_libra_marre_total() const;
    void printo_libra_marre();
     
    
    
    void set_ID_table(); //inicializimi i tabeles se id
    int get_ID(int); //kthen pozicionin nese id gjendet ne tabelen e id, e ben pozicionin 0, zbret nr e id gjithsej.
    void set_ID(int); //vendosja e nje id ne tabelen e id ne vendin e pare bosh
    void set_id_0(int); //vendos id si argument ne vendin e pare bosh dhe rrit id gjithsej me 1
    int get_id_total() const;
    void printo_ID();


    void print_biblioteka();//printon gjithcka qe ka kjo klase


    private:
    string librat[40]; //librat total
    int libra_gjithsej = 0;

    string librat_marre[40];  //librat e marre
    int libra_marre_gjith = 0;

    int vendet[10] = {0, 0, 0, 0, 0, 0, 0,0 , 0, 0}; //vendet per te lexuar ne biblioteke
    int vende_gjith = 10;

    int id_pa_kthyerLibra[40]; //id e njerzve qe u ka kaluar afati per te kthyer libra
    int id_pa_kthyerLibra_gjith = 0; // sa njerez nuk kane kthyer libra
    
};

class Klienti{
    friend class Biblioteka;
    friend class Data;
    friend void marrja_librit(Biblioteka& , Klienti& , Data& );

    public:
    Klienti(int); //konstruktori merr id
    ~Klienti();

    string get_Libri_Deshiron() const;
    void set_Libri_Deshiron(string);
    string get_Libri_Dorezon() const;
    void set_Libri_Dorezon(string);

    bool lexim_biblioteke();
    int libra_paDorezuar();

    int getID() const;
    void setID(int);

    int get_libra_paDorezuar() const;
    void set_libra_paDorezuar(int); //modifikon sasin e librave pa dorezuar qe ka klienti

    void print_Klienti();
    

    private:
    string libri_qeDeshiron = "0"; //supozojme qe nje kliente vjen vetem per te marre ose dorezuar liber
    string libri_qeDorezon = "0"; //libri qe klienti ka ne perdorim dhe qe duhet dorezuar pas nje kohe
    int libra_pa_dorezuar=0; // supozojme se nje kliente nuk mund te kete me shume se nje liber pa dorezuar
    int id=0;
    
    

};

class Data{

    friend class Klienti;
    friend class Biblioteka;
    friend void marrja_librit(Biblioteka& , Klienti& , Data& );

    

    public:
    Data(int, int, int);
    ~Data();
    int get_dita_marrjes() const;
    int get_muaji_marrjes() const;
    int get_viti_marrjes() const;

    void set_dita_marrjes(int);
    void set_muaji_marrjes(int);
    void set_viti_marrjes(int);

    void set_data_marrjes(int, int, int);

    int get_dita_dorezimit() const;
    int get_muaji_dorezimit() const;
    int get_viti_dorezimit() const;
    
    void set_dita_dorezimit(int);
    void set_muaji_dorezimit(int);
    void set_viti_dorezimit(int);

    void set_data_dorezimit(int, int, int);

    int koha_mbajtjes_librit();

    void print_Datat();

    private:
    int dita_marrjes=0;
    int muaji_marrjes=0;
    int viti_marrjes=0;

    int dita_dorezimit=0;
    int muaji_dorezimit=0;
    int viti_dorezimit=0;
    
        

};
#endif