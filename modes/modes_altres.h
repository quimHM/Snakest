int mode_25_RETRO(){
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length;
    gestionarINPUT();
    if (numero_de_fotograma % 6 == 0) {//trucs(controller, s, p);
        int m = moureSERP_RETRO(); if(m == 1){final = 4;} else if(m==2){final = 5;}
        if (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y){s.creixer = 1; ferCREIXERoDECREIXER(); crearRATA_mode(25);}
    }
    if (pintarhoTOT(25) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}  
