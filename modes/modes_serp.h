int mode_07_REGULABLE(){
    int final = 0; t = time(NULL) - segons;
    gestionarINPUT();
    if(p.m7.acabemdecomencar == 0){
        if (controller.A.pressed){s.creixer = 1;} if (controller.B.pressed && s.length > 1){s.creixer = -1;}}
    else{
        if (controller.A.half_transition_count){p.m7.acabemdecomencar = 0;}}
    if (numero_de_fotograma % 10 == 0) {//trucs(controller, s, p);
        ferCREIXERoDECREIXER();
        int m = moureSERP(); if(m == 1){final = 4;} else if(m==2){final = 5;}
        if (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y){p.m0.puntuacio += 1; crearRATA();}
    }
    if (pintarhoTOT(7) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}

int mode_08_MANUAL(){
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length-1;
    gestionarINPUT_MANUAL();
    if(s.dir != ' '){
        int m = moureSERP(); if(m == 1){final = 4;} else if(m==2){final = 5;}
        if (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y){s.creixer = 1; ferCREIXERoDECREIXER(); crearRATA();}
    }
    if (pintarhoTOT(8) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}

int mode_09_INCRE(){
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length-1;
    gestionarINPUT();
    if (numero_de_fotograma >= 10000) {//trucs(controller, s, p);
        numero_de_fotograma = 0; p.m9.increment += 1;
        int m = moureSERP(); if(m == 1){final = 4;} else if(m==2){final = 5;}
        if (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y){s.creixer = 1; ferCREIXERoDECREIXER(); crearRATA();}
    }
    if (pintarhoTOT(9) == 1){final = 3;}

    numero_de_fotograma += p.m9.increment;
    return final;}

int mode_10_CAPICUA(){
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length-1;
    gestionarINPUT_CAPICUA();
    if (numero_de_fotograma % 10 == 0) {//trucs(controller, s, p);
        int m = moureSERP(); if(m == 1){final = 4;} else if(m==2){final = 5;}
        if (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y){s.creixer = 1; ferCREIXERoDECREIXER(); crearRATA();}
    }
    if (pintarhoTOT(10) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}

int mode_11_REMOT(){
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length-1;
    gestionarINPUT_REMOT();
    if (numero_de_fotograma % 5 == 0) {
        int n = mourePIT(); if(n == 1){final = 8;}
        if (numero_de_fotograma % 10 == 0){//trucs(controller, s, p);
            int m = moureSERP(); if(m == 1){final = 4;} else if(m==2){final = 5;}
        }
        if (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y){s.creixer = 1; crearRATA();}
        ferCREIXERoDECREIXER();
    }
    if (pintarhoTOT(11) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}

int mode_12_DIAGONAL(){
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length-1;
    gestionarINPUT_DIAGONAL(); //TODO: POTSER UNIR TOTS DOS IFs?
    if (numero_de_fotograma % 7 == 0) {//trucs(controller, s, p);
        ferCREIXERoDECREIXER(); int m = moureSERP_DIAGONAL();
        if(m == 1){final = 4;} else if(m==2){final = 5;}}
    if (numero_de_fotograma % 7 == 1) {
        if ((s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y)||
            (p.m12.cap12[0].x == p.m0.R.x && p.m12.cap12[0].y == p.m0.R.y)||
            (p.m12.cap12[1].x == p.m0.R.x && p.m12.cap12[1].y == p.m0.R.y)){
                s.creixer = 1; crearRATA_DIAGONAL();}
    }
    if (pintarhoTOT(12) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}

int mode_13_SMOOTH(){
    int final = 0; t = time(NULL) - segons;
    gestionarINPUT();
    if (numero_de_fotograma % 2 == 0){//trucs();
        int m = moureSERP_SMOOTH(); if(m == 1){final = 4;} else if(m==2){final = 5;}
        for(int i = 0; i < 4; i++){
            if(casellesocupades(s.cap)[i].x == p.m0.R.x && casellesocupades(s.cap)[i].y == p.m0.R.y)
            {
                recompteCASELLES_13();
                crearRATA_5i13(13);
                for(int i=0;i<5;i++){ferCREIXERoDECREIXER_mode(1);}
                p.m0.puntuacio+=1; 
            }
        }
        if (pintarhoTOT(13) == 1){final = 3;}
    }
 
    ++numero_de_fotograma;
    return final;}
