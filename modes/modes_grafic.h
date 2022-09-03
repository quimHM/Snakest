int mode_17_SURVIVAL(){ 
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length-1;
    gestionarINPUT(); 
    if (numero_de_fotograma % 10 == 0) {//trucs(controller, s, p); 
        int m = moureSERP(); if(m == 1){final = 4;} else if(m==2){final = 5;}
        if (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y){s.creixer = 1; ferCREIXERoDECREIXER(); crearRATA();}
        pintarhoTOT(17);
    }
     
    ++numero_de_fotograma;
    return final;}
    
int mode_18_GALLINETA(){
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length-1;
    gestionarINPUT();       
    if (numero_de_fotograma % 10 == 0) {//trucs(controller, s, p);  
        int m = moureSERP(); if(m == 1){final = 4;} else if(m==2){final = 5;}
        if (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y){s.creixer = 1; ferCREIXERoDECREIXER(); crearRATA(); p.m18.flash = 1;}
    }
    pintarhoTOT(18);
     
    ++numero_de_fotograma; 
    return final;}

