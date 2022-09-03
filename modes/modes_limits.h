int mode_04_VORES(){
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length-1;
    gestionarINPUT();
    if (numero_de_fotograma % 10 == 0) {//trucs(controller, s, p);
        int m = moureSERP_VORES(); if(m == 1){final = 4;} else if(m==2){final = 5;}
        if (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y){s.creixer = 1; ferCREIXERoDECREIXER(); crearRATA();}
    }
    if (pintarhoTOT(4) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}

int mode_05_FANTASMA(){
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length-1;
    gestionarINPUT();
    if (numero_de_fotograma % 10 == 0) {//trucs(controller, s, p);
        ferCREIXERoDECREIXER();
        int m = moureSERP_FANTASMA(); if(m == 1){final = 4;} if(m == 2){final = 8;}
        recompteCOSSOS_5();
        if (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y){s.creixer = 1; crearRATA_5i13(5);}
    }
    if (pintarhoTOT(5) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}

int mode_06_PINTAR(){
    int final = 0; t = time(NULL) - segons;
    gestionarINPUT_PINTAR();
    if (numero_de_fotograma % 10 == 0){
        moureSERP_VORES();
        int n = moureORIGEN_EDITOR();
    }
    if(p.m6.colorBN != 'i'){p.m6.posicionsPINTAR[s.lloc] = p.m6.colorBN;}
    p.m6.parets = p.m6.NORATAs = 0;
    for (int i = 0; i<240; i++){
        if(p.m6.posicionsPINTAR[i] == 'b'){p.m6.parets+=1;}
        else if(p.m6.posicionsPINTAR[i] == 'r'){p.m6.NORATAs+=1;}}

    //if(controller.C.pressed){final = 6;}
    if (pintarhoTOT(6) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}

int mode_66_BARRERES(){
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length-1; 
    if(p.m6.posicionsPINTAR[s.lloc] == 'b'){p.m6.acabemdecomencar = 2; return 8;}
    gestionarINPUT();
    if (numero_de_fotograma % 10 == 0) {//trucs(controller, s, p);
        I2 posicio_al_inici = s.cap;
        int m = moureSERP_dir_mode('X',66); if(m == 1){final = 4;} else if(m==2){final = 5;}
        if (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y){
            s.creixer = 1; ferCREIXERoDECREIXER();
            if(crearRATA_BARRERES()==1){s.posicions[0] = s.cap = posicio_al_inici; final = 8;}}
    }
    if (pintarhoTOT(66) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}
