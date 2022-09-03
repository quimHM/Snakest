void inicialitzar_finestres(){
    
    finestra_general.origen = i2(0, 0);
    finestra_general.mida = i2(127, 63);
    finestra_general.bitmap = bp;

    finestra_record.origen = i2(0, 0);
    finestra_record.mida = i2(14, 64);
    finestra_record.bitmap = bp;

    finestra_puntuacio.origen = i2(114,0);
    finestra_puntuacio.mida = i2(14, 64);
    finestra_puntuacio.bitmap = bp;

    finestra_joc.origen = i2(14, 2);
    finestra_joc.mida = i2(100, 60);
    finestra_joc.bitmap = bp;
}

int iniciar_modes_i_serp(int mode){
    
    numero_de_fotograma = 0;
        
    s.length = 1;
    s.creixer = 0;
    s.dir = 'E';
    s.dirR = 'E';
    s.dircua = 'O';
    s.cap = i2(19,2);
    s.lloc = 12;
    s.posicions[0] = s.cap;
    s.posicions[1] = i2(14, 2);

    memset((void *)taula_general, 0, 240 * sizeof(I2)); // NOTE: Reset de tots els bytes de taula_general
    // NOTE: Equivalent a:
    // for(int i=0; i < 240; ++i){
    //     taula_general[i].x = 0;
    //     taula_general[i].y = 0;
    // }

    crearRATA_mode(22);
    //mo0
        p.m0.pausat = 0;
        p.m0.puntuacio = 0;
        
    //mo1
    if(mode == 2){//mo2
        p.m2.index_dir = 1;}
    if(mode == 3){//mo3
        p.m3.mira = i2(109, 57);
        p.m3.ordre_donada = 0;}
    //mo4
    //mo5
    if(mode == 6){//mo6
        s.posicions[0] = s.cap = i2(109,57);
        s.lloc = 239;
        s.dir = 'O';
        p.m0.R = p.m6.origen;
        p.m6.acabemdecomencar = 1;
        p.m6.colorBN = 'i';}
    if(mode == 66){//mo66
        s.posicions[0] = s.cap = p.m6.origen;
        s.lloc = ((s.cap.x-14)/5)*12+((s.cap.y-2)/5);
        s.dir = p.m6.dirOri;
        if(s.dir == 'N'){s.posicions[1] = i2(s.posicions[0].x,s.posicions[0].y+5);}
        else if(s.dir == 'S'){s.posicions[1] = i2(s.posicions[0].x,s.posicions[0].y-5);}
        else if(s.dir == 'E'){s.posicions[1] = i2(s.posicions[0].x-5,s.posicions[0].y);}
        else if(s.dir == 'O'){s.posicions[1] = i2(s.posicions[0].x+5,s.posicions[0].y);}
        crearRATA_BARRERES();}
    if(mode == 7){//mo7
        p.m7.acabemdecomencar = 1;}
    //mo8
    if(mode == 9){//mo9
        p.m9.increment = 1000;}
    if(mode == 10){//mo11
        p.m10.mode = 0;}
    if(mode == 11){//mo11
        p.m11.pitfora = 0;}
    //mo12
    if(mode == 13){//mo13
        s.length = 10;
        s.cap.x = 24; s.posicions[0] = s.cap;
        for(int i=1;i<=10;i++){s.posicions[i] = i2(s.cap.x-1*i, 2);}}
    if(mode == 14){//mo14
        gestionarRATES_mode(1);}
    if(mode == 15){//mo15
        p.m15.dirRATA = 'S';}
    //mo16
    //mo17
    if(mode == 18){//mo18
        p.m18.flash = 0;}
    //mo19
    //mo20
    if(mode == 20){
        s.length = 4;
        s.posicions[4]=s.posicions[3]=s.posicions[2]=s.posicions[1];}
    if(mode == 21){//mo22
        p.m21.forat = p.m0.R; crearRATA_mode(22);}
    if(mode == 22){//mo21
        s.length = 6;
        s.posicions[6]=s.posicions[5]=s.posicions[4]=s.posicions[3]=s.posicions[2]=s.posicions[1];}
    if(mode == 23){//mo23
        s.length = 2;
        s.cap = i2(49,32);
        s.posicions[0] = s.cap; s.posicions[1] = i2(44,32); s.posicions[2] = i2(39, 32);
        p.m0.R.x = 109;}
    if(mode == 24){//mo24
        p.m24.dirRATA = 'O';
        p.m24.prota = i2(109,57);}
    if(mode == 25){//mo25
        s.length = 0;
        s.cap = i2(15,4); s.posicions[0] = s.cap;
        crearRATA_mode(25);}

    return 0;
}
