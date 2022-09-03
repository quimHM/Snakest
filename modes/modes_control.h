int mode_01_INVERTIT(){
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length-1;
    gestionarINPUT_INVERS();
    if (numero_de_fotograma % 10 == 0) {//trucs(controller, s, p);
        int m = moureSERP(); if(m == 1){final = 4;} else if(m==2){final = 5;}
        if (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y){s.creixer = 1; ferCREIXERoDECREIXER(); crearRATA();}
    }
    if (pintarhoTOT(1) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}

int mode_02_EGO(){
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length-1;
    gestionarINPUT_EGO();
    if (numero_de_fotograma % 10 == 0) {//trucs(controller, s, p);
        int m = moureSERP(); if(m == 1){final = 4;} else if(m==2){final = 5;}
        if (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y){s.creixer = 1; ferCREIXERoDECREIXER(); crearRATA();}
        p.m2.puc_girar = 1;
    }
    if (pintarhoTOT(2) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}

int mode_03_ESTRATEGIC(){
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length-1;
    p.m3.dir_mira = 'X';
    gestionarINPUT_STRA();
    if (s.cap.x == p.m3.ordre.x && s.cap.y == p.m3.ordre.y){p.m3.ordre_donada = 0;}
    if (numero_de_fotograma % 15 == 0){//trucs(controller, s, p);
        if(p.m3.ordre_donada == 1){p.m3.direccio_a_moure_serp = donarlordre();}
        else{p.m3.direccio_a_moure_serp = s.dir = s.dirR;}
        int m = moureSERP_dir(p.m3.direccio_a_moure_serp);
        if(m == 1){final = 4;} else if(m == 2){final = 5;}
        if (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y){s.creixer = 1; ferCREIXERoDECREIXER(); crearRATA();}
    }
    if (numero_de_fotograma % 5 == 0){moureMIRA();}
    if (pintarhoTOT(3) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}
