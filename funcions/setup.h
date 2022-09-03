long int t;
long int t_pausa;
char *titol_finestra = "Snakest";
int factor_zoom = 6;
time_t segons = 0;

Bitmap bp = {};
Pixel negre = {0};  Pixel blanc = {1};
//Pixel vermell = {255, 0, 0};  Pixel blau = {0, 0, 255};  Pixel croma = {0,255,0};
int numero_de_fotograma = 0;

ControllerState controller;

typedef struct I2{
    int8_t x;
    int8_t y;
    //Byte x;
    //Byte y;
}I2;

static I2 i2(int x, int y){
    I2 v = {x, y};
    return v;
}

I2 posicionsXY(int index){
    int i = 0;
    for (int x = 0; x<20; x++){
        for (int y = 0; y<12; y++){
            if(index == i){return i2(14 + x*5, 2 + y*5);}
            i+=1;
        }
    }
    return i2(109,57);
}  
//int posicionsXY_invers(I2 index){return ((index.x-14)/5)*12+((index.y-2)/5);}  

typedef struct Serp{
    I2 posicions[240*5];
    int length;
    int creixer;
    char dir;
    char dirR;
    char dircua;
    I2 cap;
    int lloc;} Serp;
Serp s;

typedef struct Mode0{
    int HS0;
    int puntuacio;
    I2 R;
    int pausat;}Mode0;
    
static I2 taula_general[240];

typedef struct Mode1{
    int HS1;}Mode1;

typedef struct Mode2{
    int HS2;
    int puc_girar;
    int index_dir;
    char direccions[5];}Mode2;

typedef struct Mode3{
    int HS3;
    I2 mira;
    char dir_mira;
    I2 ordre;
    int distanciaX;
    int distanciaY;
    int ordre_donada;
    char direccio_a_moure_serp;}Mode3;

typedef struct Mode4{
    int HS4;}Mode4;

typedef struct Mode5{
    int HS5;
    int NUMposicionsvisibles;
    I2 *posicionsvisibles;
}Mode5;

typedef struct Mode6{
    int HS6;
    int acabemdecomencar;
    char colorBN;
    char posicionsPINTAR[240];
    int parets;
    int NORATAs;
    int cossosreals;
    I2 origen;
    char dirOri;}Mode6;

typedef struct Mode7{
    int HS7;
    int acabemdecomencar;}Mode7;

typedef struct Mode8{
    int HS8;}Mode8;

typedef struct Mode9{
    int HS9;
    int increment;}Mode9;

typedef struct Mode10{
    int HS10;
    int mode;
    I2 *posicionsaux;
    char diraux;}Mode10;

typedef struct Mode11{
    int HS11;
    I2 P;
    int pitfora;
    char direcciopit;}Mode11;

typedef struct Mode12{
    int HS12;
    char dir1;
    char dir2;
    I2 *posicions12;
    int index12;
    I2 cap12[2];}Mode12;

typedef struct Mode13{
    int HS13;
    int NUMcasellesocupades;
    I2 *casellesocupades;
}Mode13;

typedef struct rosegador{
    I2 origen;
    int durada;
    int quanhaaparegut;
    int caracter;}rosegador;
typedef struct Mode14{
    int HS14;
    rosegador rates[5];}Mode14;

typedef struct Mode15{
    int HS15;
    char dirRATA;
    int ladirecciodelarataescorrecta;}Mode15;

typedef struct Mode16{
    int HS16;}Mode16;

typedef struct Mode17{
    int HS17;
    int sumes[5];}Mode17;

typedef struct Mode18{
    int HS18;
    int difX;
    int difY;
    int distancia;
    int flash;}Mode18;

typedef struct Mode19{
    int HS19;}Mode19;

typedef struct Mode20{
    int HS20;}Mode20;

typedef struct Mode21{
    int HS21;
    I2 forat;}Mode21;

typedef struct Mode22{
    int HS22;
    I2 *posicions22;
    int index22;}Mode22;

typedef struct Mode23{
    int HS23;}Mode23;

typedef struct Mode24{
    int HS24;
    char dirRATA;
    I2 prota;
    I2 capAUX;}Mode24;

typedef struct Mode25{
    int HS25;}Mode25;

typedef struct Partida{
    Mode0 m0; Mode1 m1; Mode2 m2; Mode3 m3; Mode4 m4; Mode5 m5;
              Mode6 m6; Mode7 m7; Mode8 m8; Mode9 m9; Mode10 m10;
              Mode11 m11; Mode12 m12; Mode13 m13; Mode14 m14; Mode15 m15;
              Mode16 m16; Mode17 m17; Mode18 m18; Mode19 m19; Mode20 m20;
              Mode21 m21; Mode22 m22; Mode23 m23; Mode24 m24; Mode25 m25;
}Partida;

Partida p = {
    .m0 =  {.HS0 = 0},                                     
    .m1 =  {.HS1 = 0},                                     
    .m2 =  {.HS2 = 0, .direccions = "NESO"},               
    .m3 =  {.HS3 = 0},                                     
    .m4 =  {.HS4 = 0},                                     
    .m5 =  {.HS5 = 0, .posicionsvisibles = taula_general}, 
    .m6 =  {.HS6 = 0, .dirOri = 'E', .origen = {19,2}},    
    .m7 =  {.HS7 = 0},                                     
    .m8 =  {.HS8 = 0},                                     
    .m9 =  {.HS9 = 0},                                     
    .m10 = {.HS10 = 0, .mode = 0, .posicionsaux = taula_general},     
    .m11 = {.HS11 = 0},                                    
    .m12 = {.HS12 = 0, .posicions12 = taula_general},      
    .m13 = {.HS13 = 0, .casellesocupades = taula_general}, 
    .m14 = {.HS14 = 0},                                    
    .m15 = {.HS15 = 0},                                    
    .m16 = {.HS16 = 0},                                    
    .m17 = {.HS17 = 0, .sumes = {-10,-5,0,5,10}},          
    .m18 = {.HS18 = 0},                                    
    .m19 = {.HS19 = 240},                                    
    .m20 = {.HS20 = 0},                                    
    .m21 = {.HS21 = 0},                                    
    .m22 = {.HS22 = 0, .posicions22 = taula_general},      
    .m23 = {.HS23 = 0},                                    
    .m24 = {.HS24 = 0},                                    
    .m25 = {.HS25 = 0},                                    
};

typedef struct Finestra{
    I2 origen;
    I2 mida;
    Bitmap bitmap;
}Finestra;

Finestra finestra_general = {};  Finestra finestra_record = {};
Finestra finestra_puntuacio = {};  Finestra finestra_joc = {}; 
