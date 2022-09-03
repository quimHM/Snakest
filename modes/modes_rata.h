int mode_14_PLUS(){
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length-1;
    gestionarINPUT();
    if (numero_de_fotograma % 10 == 0) {//trucs(controller, s, p);
        I2 posicio_al_inici = s.cap;
        int m = moureSERP(); if(m == 1){final = 4;} else if(m==2){final = 5;}
        if (gestionarRATES()==1){s.posicions[0] = s.cap = posicio_al_inici; final = 8;};
    }
    if (pintarhoTOT(14) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}

int mode_15_DIRECCIONALS(){
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length-1;
    gestionarINPUT();
    if (numero_de_fotograma % 10 == 0) {//trucs(controller, s, p);
        I2 posicio_al_inici = s.cap;
        int m = moureSERP(); if(m == 1){final = 4;} else if(m==2){final = 5;}
        if (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y){
            if(s.dirR == p.m15.dirRATA){
                s.creixer = 1; ferCREIXERoDECREIXER(); crearRATA();
                p.m15.ladirecciodelarataescorrecta = 0;
                while(p.m15.ladirecciodelarataescorrecta != 1){
                    p.m15.ladirecciodelarataescorrecta = 1;
                    p.m15.dirRATA = p.m2.direccions[aleat(0,3)];
                    if (p.m0.R.y == 2 && p.m15.dirRATA == 'S'){p.m15.ladirecciodelarataescorrecta = 0;}
                    else if (p.m0.R.y == 57 && p.m15.dirRATA == 'N'){p.m15.ladirecciodelarataescorrecta = 0;}
                    if (p.m0.R.x == 14 && p.m15.dirRATA == 'E'){p.m15.ladirecciodelarataescorrecta = 0;}
                    else if (p.m0.R.x == 109 && p.m15.dirRATA == 'O'){p.m15.ladirecciodelarataescorrecta = 0;}
                }
            }
            else{s.posicions[0] = s.cap = posicio_al_inici; final = 8;}
        }
    }
    if (pintarhoTOT(15) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}

int mode_16_RATESMOBILS(){
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length-1;
    gestionarINPUT();
    if (numero_de_fotograma % 10 == 0) {//trucs(controller, s, p);
        int m = moureSERP(); if(m == 1){final = 4;} else if(m==2){final = 5;}
        if (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y){s.creixer = 1; ferCREIXERoDECREIXER(); crearRATA();}
        moureRATA_MOBILS();
    }
    if (pintarhoTOT(16) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}
