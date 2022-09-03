int mode_19_EASY(){
    int final = 0; t = time(NULL) - segons; //p.m0.puntuacio = 239-s.length;
    gestionarINPUT();
    if (numero_de_fotograma % 10 == 0){//trucs(controller, s, p);
        ferCREIXERoDECREIXER_mode(1);
        int m = moureSERP(); if(m == 1){final = 4;} else if(m==2){final = 5;}
    }
    p.m0.puntuacio = 239-s.length; if(p.m0.puntuacio == 0){final = 8;} 
    if (pintarhoTOT(19) == 1){final = 3;}
    
    ++numero_de_fotograma;
    return final;}

int mode_20_SelNat(){
    int final = 0; t = time(NULL) - segons;
    gestionarINPUT();
    if (numero_de_fotograma % 10 == 0) {//trucs(controller, s, p);
        if (numero_de_fotograma % 130 == 0){if (s.length > 1){ferCREIXERoDECREIXER_mode(-1);} else{final = 8;}}
        int m = moureSERP(); if(m == 1){final = 4;} else if(m==2){final = 5;}
        if (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y){s.creixer = 1; ferCREIXERoDECREIXER(); p.m0.puntuacio+=1; crearRATA();}
    }
    if (pintarhoTOT(20) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}

int mode_21_BASQUET(){
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length-1;
    gestionarINPUT();
    if (numero_de_fotograma % 10 == 0) {//trucs(controller, s, p);
        I2 posicio_al_inici = s.cap;
        int m = moureSERP(); if(m == 1){final = 4;} else if(m==2){final = 5;}
        if(s.cap.x == p.m21.forat.x && s.cap.y == p.m21.forat.y){s.posicions[0] = s.cap = posicio_al_inici; final = 8;}
        int n = moureRATA_BASQUET();
        if(n == 1){if(s.length > 1){s.length -= 1; crearRATA_mode(22);} else{final = 8;}} 
        else if(n==2){final = 8;}
        else if(p.m0.R.x == p.m21.forat.x && p.m0.R.y == p.m21.forat.y){s.creixer = 1; ferCREIXERoDECREIXER(); crearRATA_mode(22);}
    }
    if (pintarhoTOT(21) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}

int mode_22_LOOPS(){
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length-6;
    gestionarINPUT();
    if (numero_de_fotograma % 10 == 0) {//trucs(controller, s, p);
        I2 posicio_al_inici = s.cap;
        int m = moureSERP(); if(m == 1){final = 4;} else if(m==2){final = 5;}
        if (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y){s.posicions[0] = s.cap = posicio_al_inici; final = 8;}
        else{
            p.m22.index22 = 0;
            if (toca_paret(p.m0.R,0)==0){s.creixer = 1; ferCREIXERoDECREIXER(); crearRATA_mode(22);}//printf("\n");
        }
    }
    if (pintarhoTOT(22) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}

int mode_23_1D(){
    int final = 0; t = time(NULL) - segons;
    gestionarINPUT_1D();
    if (numero_de_fotograma % 5 == 0) {//trucs(controller, s, p);
        I2 posicio_aux = p.m0.R;
        p.m0.R.x -= 5;
        if (p.m0.R.x < 14){crearRATA(); while(s.cap.y == p.m0.R.y){crearRATA();} p.m0.R.x = 109;}
        if (numero_de_fotograma % 10 == 0){
            ferCREIXERoDECREIXER_1D();
            int m = moureSERP_1D(); if(m == 1){final = 4;} else if(m==2){p.m0.R = posicio_aux; final = 8;}
        }
        if (s.cap.x-5 <= p.m0.R.x && s.cap.x >= p.m0.R.x && s.cap.y == p.m0.R.y){
            s.creixer = 1; crearRATA(); while(s.cap.y == p.m0.R.y){crearRATA();} p.m0.R.x = 109;}
    }
    if (pintarhoTOT(23) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}

int mode_24_IA(){
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length-1;
    gestionarINPUT_IA();
    if (numero_de_fotograma % 5 == 0){//trucs(controller, s, p);
        if (numero_de_fotograma % 10 == 0) {
            int r = moureRATA_IA(); if(r==1){final = 4;} else if(r==2){final = 5;}
        }
        if (numero_de_fotograma % 15 == 0) {
            ferCREIXERoDECREIXER();
            p.m3.ordre = p.m24.prota;
            p.m24.capAUX = s.cap; moureSERP_FANTASMA_dir_mode(donarlordre(),1);
            recompteCOSSOS_5();
        }
        if ((p.m24.prota.x == p.m0.R.x && p.m24.prota.y == p.m0.R.y) ||
                        (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y)){s.creixer = 1; crearRATA_5i13(24);}
        else if (p.m24.prota.x == s.cap.x && p.m24.prota.y == s.cap.y){final = 8; s.cap = s.posicions[0] = p.m24.capAUX;}
    }
    if (pintarhoTOT(24) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}
