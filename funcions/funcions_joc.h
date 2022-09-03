int pintarHUD_mode(int HS, int S, int mode /* = 0 */){
    
    if (S>=0 && HS>=0 && S<999 && HS<999){
        //Pintar vores i números
        ferforma(&finestra_general,i2(0,0),128,64,blanc);
        if(mode == 25){ferforma(&finestra_joc,i2(14,3),100,58,negre);}
        else if (mode == 13){ferforma(&finestra_joc,i2(14,2),100,60,negre);}
        else{ferforma(&finestra_general,i2(13,1),102,62,negre);}
          //else{ferforma(finestra_joc,{14,2},100,60,negre);}
        
        imatgeC numeros[] = {p_zero,p_un,p_dos,p_tres,p_quatre,p_cinc,p_sis,p_set,p_vuit,p_nou};

        int puntuacio = HS;
        int centenes = puntuacio / 100;
        int desenes = (puntuacio - 100*centenes) / 10;
        int unitats = puntuacio - 100*centenes -10*desenes;

        if(mode == 6){ps(&finestra_record,&record_r,i2(4,9));} else{ps(&finestra_record,&record,i2(4,9));}
        ps(&finestra_record,numeros+centenes,i2(4,21));
        ps(&finestra_record,numeros+desenes,i2(4,33));
        ps(&finestra_record,numeros+unitats,i2(4,45));

        puntuacio = S;
        centenes = puntuacio / 100;
        desenes = (puntuacio - 100*centenes) / 10;
        unitats = puntuacio - 100*centenes -10*desenes;

        if(mode == 6){ps(&finestra_puntuacio,&punts_m,i2(118,9));} else {ps(&finestra_puntuacio,&punts,i2(118,9));}
        ps(&finestra_puntuacio,numeros+centenes,i2(118,21));
        ps(&finestra_puntuacio,numeros+desenes,i2(118,33));
        ps(&finestra_puntuacio,numeros+unitats,i2(118,45));
        
        return 0;
    }
    else{return 1;}
}

int pintarHUD(int HS, int S){
    return pintarHUD_mode(HS, S, 0);
}

int pintarSERP(){
    for (int n = 1; n<s.length; n++)
        {ps(&finestra_joc,&cos_,s.posicions[n]);}

        if (s.dirR == 'N'){ ps(&finestra_joc,&capN,s.posicions[0]);}
        if (s.dirR == 'S'){ ps(&finestra_joc,&capS,s.posicions[0]);}
        if (s.dirR == 'E'){ ps(&finestra_joc,&capE,s.posicions[0]);}
        if (s.dirR == 'O'){ ps(&finestra_joc,&capO,s.posicions[0]);}

        if (s.dircua == 'N'){ ps(&finestra_joc,&cuaN,s.posicions[s.length]);}
        if (s.dircua == 'S'){ ps(&finestra_joc,&cuaS,s.posicions[s.length]);}
        if (s.dircua == 'E'){ ps(&finestra_joc,&cuaE,s.posicions[s.length]);}
        if (s.dircua == 'O'){ ps(&finestra_joc,&cuaO,s.posicions[s.length]);}

    return 0;
}

int pintarSERP_FANTASMA(){
    if (s.dircua == 'N'){ ps(&finestra_joc,&cuaNfant,i2(s.posicions[s.length].x-1,s.posicions[s.length].y-1));}
    if (s.dircua == 'S'){ ps(&finestra_joc,&cuaSfant,i2(s.posicions[s.length].x-1,s.posicions[s.length].y-1));}
    if (s.dircua == 'E'){ ps(&finestra_joc,&cuaEfant,i2(s.posicions[s.length].x-1,s.posicions[s.length].y-1));}
    if (s.dircua == 'O'){ ps(&finestra_joc,&cuaOfant,i2(s.posicions[s.length].x-1,s.posicions[s.length].y-1));}

    for (int n = s.length-1; n>0; n--){
        if (s.posicions[n].x > s.posicions[n+1].x && s.posicions[n].y < s.posicions[n-1].y)
            {ps(&finestra_joc,&cosSOfant,i2(s.posicions[n].x-1,s.posicions[n].y-1));}
        else if (s.posicions[n].x > s.posicions[n-1].x && s.posicions[n].y < s.posicions[n+1].y)
            {ps(&finestra_joc,&cosSOfant,i2(s.posicions[n].x-1,s.posicions[n].y-1));}
        else if (s.posicions[n].x > s.posicions[n+1].x && s.posicions[n].y > s.posicions[n-1].y)
            {ps(&finestra_joc,&cosNOfant,i2(s.posicions[n].x-1,s.posicions[n].y-1));}
        else if (s.posicions[n].x > s.posicions[n-1].x && s.posicions[n].y > s.posicions[n+1].y)
            {ps(&finestra_joc,&cosNOfant,i2(s.posicions[n].x-1,s.posicions[n].y-1));}
        else if (s.posicions[n].x != s.posicions[n+1].x && s.posicions[n].y == s.posicions[n-1].y)
            {ps(&finestra_joc,&cosXfant,i2(s.posicions[n].x-1,s.posicions[n].y-1));}
        else if (s.posicions[n].x < s.posicions[n+1].x && s.posicions[n].y < s.posicions[n-1].y)
            {ps(&finestra_joc,&cosSEfant,i2(s.posicions[n].x-1,s.posicions[n].y-1));}
        else if (s.posicions[n].x < s.posicions[n-1].x && s.posicions[n].y < s.posicions[n+1].y)
            {ps(&finestra_joc,&cosSEfant,i2(s.posicions[n].x-1,s.posicions[n].y-1));}
        else if (s.posicions[n].x < s.posicions[n+1].x && s.posicions[n].y > s.posicions[n-1].y)
            {ps(&finestra_joc,&cosNEfant,i2(s.posicions[n].x-1,s.posicions[n].y-1));}
        else if (s.posicions[n].x < s.posicions[n-1].x && s.posicions[n].y > s.posicions[n+1].y)
            {ps(&finestra_joc,&cosNEfant,i2(s.posicions[n].x-1,s.posicions[n].y-1));}
        else if (s.posicions[n].x == s.posicions[n+1].x && s.posicions[n].y != s.posicions[n-1].y)
            {ps(&finestra_joc,&cosYfant,i2(s.posicions[n].x-1,s.posicions[n].y-1));}
    }
    /*
    if(s.posicions[s.length].x == s.posicions[s.length-1].x && s.posicions[s.length].y == s.posicions[s.length-1].y){
        if (s.dircua == 'N'){ ps(&finestra_joc,cuaNfant,{s.posicions[s.length].x-1,s.posicions[s.length].y-1});}
        else if (s.dircua == 'S'){ ps(&finestra_joc,cuaSfant,{s.posicions[s.length].x-1,s.posicions[s.length].y-1});}
        else if (s.dircua == 'E'){ ps(&finestra_joc,cuaEfant,{s.posicions[s.length].x-1,s.posicions[s.length].y-1});}
        else if (s.dircua == 'O'){ ps(&finestra_joc,cuaOfant,{s.posicions[s.length].x-1,s.posicions[s.length].y-1});}
    }
    */
    if (s.dirR == 'N'){ ps(&finestra_joc,&capNfant,i2(s.posicions[0].x-1,s.posicions[0].y-1));}
    if (s.dirR == 'S'){ ps(&finestra_joc,&capSfant,i2(s.posicions[0].x-1,s.posicions[0].y-1));}
    if (s.dirR == 'E'){ ps(&finestra_joc,&capEfant,i2(s.posicions[0].x-1,s.posicions[0].y-1));}
    if (s.dirR == 'O'){ ps(&finestra_joc,&capOfant,i2(s.posicions[0].x-1,s.posicions[0].y-1));}

    return 0;
}

int pintarSERP_CAPICUA(){
    for (int n = 1; n<s.length; n++)
        {ps(&finestra_joc,&cos_,s.posicions[n]);}
        
        if(p.m10.mode == 0){
            if (s.dirR == 'N'){ ps(&finestra_joc,&capN,s.posicions[0]);}
            if (s.dirR == 'S'){ ps(&finestra_joc,&capS,s.posicions[0]);}
            if (s.dirR == 'E'){ ps(&finestra_joc,&capE,s.posicions[0]);}
            if (s.dirR == 'O'){ ps(&finestra_joc,&capO,s.posicions[0]);}

            if (s.dircua == 'N'){ ps(&finestra_joc,&cuaN,s.posicions[s.length]);}
            if (s.dircua == 'S'){ ps(&finestra_joc,&cuaS,s.posicions[s.length]);}
            if (s.dircua == 'E'){ ps(&finestra_joc,&cuaE,s.posicions[s.length]);}
            if (s.dircua == 'O'){ ps(&finestra_joc,&cuaO,s.posicions[s.length]);}}
        else{
            if (s.dirR == 'N'){ ps(&finestra_joc,&cuaN,s.posicions[0]);}
            if (s.dirR == 'S'){ ps(&finestra_joc,&cuaS,s.posicions[0]);}
            if (s.dirR == 'E'){ ps(&finestra_joc,&cuaE,s.posicions[0]);}
            if (s.dirR == 'O'){ ps(&finestra_joc,&cuaO,s.posicions[0]);}

            if (s.dircua == 'N'){ ps(&finestra_joc,&capN,s.posicions[s.length]);}
            if (s.dircua == 'S'){ ps(&finestra_joc,&capS,s.posicions[s.length]);}
            if (s.dircua == 'E'){ ps(&finestra_joc,&capE,s.posicions[s.length]);}
            if (s.dircua == 'O'){ ps(&finestra_joc,&capO,s.posicions[s.length]);}}

    return 0;
}

int pintarSERP_DIAGONAL(){
    for (int index = 0; index < p.m12.index12; index++){p.m12.posicions12[index] = i2(0,0);}
    p.m12.index12 = 0; p.m12.cap12[0] = p.m12.cap12[1] = i2(0,0);

    for (int n = s.length; n>0; n--){
        ps(&finestra_joc,&cos_,s.posicions[n]);
        if (s.posicions[n].x != s.posicions[n-1].x && s.posicions[n].y != s.posicions[n-1].y)
        {
            if (s.posicions[n].y>s.posicions[n-1].y && s.posicions[n].x<s.posicions[n-1].x){
               ps(&finestra_joc,&diagonalSE,i2(s.posicions[n].x,s.posicions[n].y-5));
               ps(&finestra_joc,&diagonalNO,i2(s.posicions[n].x+5,s.posicions[n].y));
               if (n>1){p.m12.posicions12[p.m12.index12] = i2(s.posicions[n].x,s.posicions[n].y-5); p.m12.index12 += 1;
                        p.m12.posicions12[p.m12.index12] = i2(s.posicions[n].x+5,s.posicions[n].y); p.m12.index12 += 1;}
               else{
                    p.m12.cap12[0] = i2(s.posicions[n].x,s.posicions[n].y-5);
                    p.m12.cap12[1] = i2(s.posicions[n].x+5,s.posicions[n].y);}}
            else if (s.posicions[n].y<s.posicions[n-1].y && s.posicions[n].x<s.posicions[n-1].x){
                ps(&finestra_joc,&diagonalSO,i2(s.posicions[n].x+5,s.posicions[n].y));
                ps(&finestra_joc,&diagonalNE,i2(s.posicions[n].x,s.posicions[n].y+5));
                if (n>1){p.m12.posicions12[p.m12.index12] = i2(s.posicions[n].x+5,s.posicions[n].y); p.m12.index12 += 1;
                         p.m12.posicions12[p.m12.index12] = i2(s.posicions[n].x,s.posicions[n].y+5); p.m12.index12 += 1;}
                else{
                     p.m12.cap12[0] = i2(s.posicions[n].x+5,s.posicions[n].y);
                     p.m12.cap12[1] = i2(s.posicions[n].x,s.posicions[n].y+5);}}
            else if (s.posicions[n].y>s.posicions[n-1].y && s.posicions[n].x>s.posicions[n-1].x){
                ps(&finestra_joc,&diagonalSO,i2(s.posicions[n].x,s.posicions[n].y-5));
                ps(&finestra_joc,&diagonalNE,i2(s.posicions[n].x-5,s.posicions[n].y));
                if (n>1){p.m12.posicions12[p.m12.index12] = i2(s.posicions[n].x,s.posicions[n].y-5); p.m12.index12 += 1;
                         p.m12.posicions12[p.m12.index12] = i2(s.posicions[n].x-5,s.posicions[n].y); p.m12.index12 += 1;}
                else{
                     p.m12.cap12[0] = i2(s.posicions[n].x,s.posicions[n].y-5);
                     p.m12.cap12[1] = i2(s.posicions[n].x-5,s.posicions[n].y);}}
            else if (s.posicions[n].y<s.posicions[n-1].y && s.posicions[n].x > s.posicions[n-1].x){
                ps(&finestra_joc,&diagonalNO,i2(s.posicions[n].x,s.posicions[n].y+5));
                ps(&finestra_joc,&diagonalSE,i2(s.posicions[n].x-5,s.posicions[n].y));
                if (n>1){p.m12.posicions12[p.m12.index12] = i2(s.posicions[n].x,s.posicions[n].y+5); p.m12.index12 += 1;
                         p.m12.posicions12[p.m12.index12] = i2(s.posicions[n].x-5,s.posicions[n].y); p.m12.index12 += 1;}
                else{
                        p.m12.cap12[0] = i2(s.posicions[n].x,s.posicions[n].y+5);
                        p.m12.cap12[1] = i2(s.posicions[n].x-5,s.posicions[n].y);}}
        }
    }

    if (s.dirR == 'W'){ps(&finestra_joc,&capNE,s.posicions[0]);}
    if (s.dirR == 'Q'){ps(&finestra_joc,&capNO,s.posicions[0]);}
    if (s.dirR == 'D'){ps(&finestra_joc,&capSE,s.posicions[0]);}
    if (s.dirR == 'A'){ps(&finestra_joc,&capSO,s.posicions[0]);}
    if (s.dirR == 'N'){ps(&finestra_joc,&capN,s.posicions[0]);}
    if (s.dirR == 'S'){ps(&finestra_joc,&capS,s.posicions[0]);}
    if (s.dirR == 'E'){ps(&finestra_joc,&capE,s.posicions[0]);}
    if (s.dirR == 'O'){ps(&finestra_joc,&capO,s.posicions[0]);}

    ferforma(&finestra_joc,s.posicions[s.length],5,5,negre);
    if (s.posicions[s.length].y>s.posicions[s.length-1].y && s.posicions[s.length].x<s.posicions[s.length-1].x){
        ps(&finestra_joc,&cuaSO,s.posicions[s.length]);}
    else if (s.posicions[s.length].y<s.posicions[s.length-1].y && s.posicions[s.length].x<s.posicions[s.length-1].x){
        ps(&finestra_joc,&cuaNO,s.posicions[s.length]);}
    else if (s.posicions[s.length].y>s.posicions[s.length-1].y && s.posicions[s.length].x>s.posicions[s.length-1].x){
        ps(&finestra_joc,&cuaSE,s.posicions[s.length]);}
    else if (s.posicions[s.length].y<s.posicions[s.length-1].y && s.posicions[s.length].x > s.posicions[s.length-1].x){
        ps(&finestra_joc,&cuaNE,s.posicions[s.length]);}
    else if (s.dircua == 'N'){ ps(&finestra_joc,&cuaN,s.posicions[s.length]);}
    else if (s.dircua == 'S'){ ps(&finestra_joc,&cuaS,s.posicions[s.length]);}
    else if (s.dircua == 'E'){ ps(&finestra_joc,&cuaE,s.posicions[s.length]);}
    else if (s.dircua == 'O'){ ps(&finestra_joc,&cuaO,s.posicions[s.length]);}

    return 0;
}

int pintarSERP_SMOOTH(){

    for (int n = 1; n<s.length; n++)
    {
        if(n%5==0){
            ps(&finestra_joc,&cosB13,s.posicions[n]);}
        else{
            ps(&finestra_joc,&cosA13,s.posicions[n]);}
    }
    ps(&finestra_joc,&cosB13,s.posicions[s.length-1]);

    if (s.dirR == 'N'){ ps(&finestra_joc,&capN,s.posicions[0]);}
    if (s.dirR == 'S'){ ps(&finestra_joc,&capS,s.posicions[0]);}
    if (s.dirR == 'E'){ ps(&finestra_joc,&capE,s.posicions[0]);}
    if (s.dirR == 'O'){ ps(&finestra_joc,&capO,s.posicions[0]);}

    ps(&finestra_joc,&cercle,s.posicions[s.length]);

    return 0;
}

/*int pintarSERP_GALLINETA_16(){
    for (int cos = 0; cos<=s.length; cos++)
    {
        p.m18.difX = abs(p.m0.R.x - s.posicions[cos].x) / 5;
        p.m18.difY = abs(p.m0.R.y - s.posicions[cos].y) / 5;
        p.m18.distancia = p.m18.difX+p.m18.difY;
        if(p.m18.distancia > 16){p.m18.distancia=16;}
        
        U8 rgb = 255-(255/16)*(p.m18.distancia-1); 
        Pixel color = {rgb,rgb,rgb};
        ferforma(&finestra_joc, s.posicions[cos],5,5,color);
    }
    if (s.dirR == 'N'){ ps(&finestra_joc,puntaN,s.cap);}
    else if (s.dirR == 'S'){ ps(&finestra_joc,puntaS,s.cap);}
    else if (s.dirR == 'E'){ ps(&finestra_joc,puntaE,s.cap);}
    else if (s.dirR == 'O'){ ps(&finestra_joc,puntaO,s.cap);}

    if (s.dircua == 'N'){ ps(&finestra_joc,puntaN,s.posicions[s.length]);}
    else if (s.dircua == 'S'){ ps(&finestra_joc,puntaS,s.posicions[s.length]);}
    else if (s.dircua == 'E'){ ps(&finestra_joc,puntaE,s.posicions[s.length]);}
    else if (s.dircua == 'O'){ ps(&finestra_joc,puntaO,s.posicions[s.length]);}

    return 0;
}*/

int pintarSERP_GALLINETA(){
    for (int cos = 0; cos<=s.length; cos++)
    {
        p.m18.difX = abs(p.m0.R.x - s.posicions[cos].x) / 5;
        p.m18.difY = abs(p.m0.R.y - s.posicions[cos].y) / 5;
        p.m18.distancia = p.m18.difX+p.m18.difY;

        ferforma_mode(&finestra_joc,s.posicions[cos],5,5,negre,1000 + (p.m18.distancia-1)*(p.m18.distancia+5));
    }

    if (s.dirR == 'N'){ ps(&finestra_joc,&puntaN,s.cap);}
    if (s.dirR == 'S'){ ps(&finestra_joc,&puntaS,s.cap);}
    if (s.dirR == 'E'){ ps(&finestra_joc,&puntaE,s.cap);}
    if (s.dirR == 'O'){ ps(&finestra_joc,&puntaO,s.cap);}

    if (s.dircua == 'N'){ ps(&finestra_joc,&puntaN,s.posicions[s.length]);}
    if (s.dircua == 'S'){ ps(&finestra_joc,&puntaS,s.posicions[s.length]);}
    if (s.dircua == 'E'){ ps(&finestra_joc,&puntaE,s.posicions[s.length]);}
    if (s.dircua == 'O'){ ps(&finestra_joc,&puntaO,s.posicions[s.length]);}

    return 0;
}

int pintarSERP_1D(){

    pintarSERP_DIAGONAL();
    if (s.dirR == 'N')
    {
        ferforma(&finestra_joc,s.posicions[0],5,5,negre);
        ferforma(&finestra_joc,i2(s.posicions[0].x+3,s.posicions[0].y+1),1,5,negre);
        ps(&finestra_joc,&capN,i2(s.posicions[0].x-2,s.posicions[0].y));
    }
    else if (s.dirR == 'S')
    {
        ferforma(&finestra_joc,s.posicions[0],5,5,negre);
        ferforma(&finestra_joc,i2(s.posicions[0].x+3,s.posicions[0].y-1),1,5,negre);
        ps(&finestra_joc,&capS,i2(s.posicions[0].x-2,s.posicions[0].y));
    }
    else
    {ps(&finestra_joc,&capE,s.posicions[0]);}
    
    return 0;
}

int pintarSERP_RETRO(){
    for (int n = 0; n<=s.length; n++)
        {ferforma(&finestra_joc,s.posicions[n],2,2,blanc);}

    return 0;
}

int pintarhoTOT(int mode){
    if (mode == 0){
        if (p.m0.HS0 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m0.HS0 = p.m0.puntuacio*5;} 
        if (pintarHUD(p.m0.HS0, p.m0.puntuacio*5) == 1){return 1;}
        pintarSERP(); ps(&finestra_joc,&rata,p.m0.R);}
    if (mode == 1){
        if (p.m1.HS1 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m1.HS1 = p.m0.puntuacio*5;}
        if (pintarHUD(p.m1.HS1, p.m0.puntuacio*5) == 1){return 1;}
        pintarSERP(); ps(&finestra_joc,&rata,p.m0.R);}
    if (mode == 2){
        if (p.m2.HS2 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m2.HS2 = p.m0.puntuacio*5;}
        if (pintarHUD(p.m2.HS2, p.m0.puntuacio*5) == 1){return 1;}
        pintarSERP(); ps(&finestra_joc,&rata,p.m0.R);}
    if (mode == 3){
        if (p.m3.HS3 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m3.HS3 = p.m0.puntuacio*5;}
        if (pintarHUD(p.m3.HS3, p.m0.puntuacio*5) == 1){return 1;}
        pintarSERP(); ps(&finestra_joc,&rata,p.m0.R);
        int pinto_la_mira = 1;
        if (p.m3.mira.x == p.m0.R.x && p.m3.mira.y == p.m0.R.y){pinto_la_mira = 0;}
        else{
            for (int n = 0; n<=s.length; n+=1){
                if (s.posicions[n].x == p.m3.mira.x && s.posicions[n].y == p.m3.mira.y){
                    pinto_la_mira = 0; break;}
            }
        }
        if(p.m3.ordre_donada == 1){
            if (p.m3.ordre.x == p.m0.R.x && p.m3.ordre.y == p.m0.R.y){ferforma(&finestra_joc,p.m0.R,5,5,negre); ps(&finestra_joc,&rataN,p.m0.R);}
            else{ps(&finestra_joc,&creuC,p.m3.ordre);}
        }
        if(pinto_la_mira == 1){ps(&finestra_joc,&mira,p.m3.mira);}
        else{ferforma_mode(&finestra_joc,p.m3.mira,5,5,blanc,2);}}
    if (mode == 4){
        if (p.m4.HS4 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m4.HS4 = p.m0.puntuacio*5;} 
        if (pintarHUD(p.m4.HS4, p.m0.puntuacio*5) == 1){return 1;}
        pintarSERP(); ps(&finestra_joc,&rata,p.m0.R);}
    if (mode == 5){
        if (p.m5.HS5 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m5.HS5 = p.m0.puntuacio*5;} 
        if (pintarHUD(p.m5.HS5, p.m0.puntuacio*5) == 1){return 1;}
        pintarSERP_FANTASMA(); ps(&finestra_joc,&rata,p.m0.R);}
    if (mode == 6){
        if (pintarHUD_mode(240-p.m6.parets-p.m6.NORATAs,p.m6.parets+p.m6.NORATAs,6) == 1){return 1;}
        //ps(finestra_general, marc, {13,1});
        for (int i = 0; i<240; i++){
            if(p.m6.posicionsPINTAR[i] == 'b'){ferforma(&finestra_joc,posicionsXY(i),5,5,blanc);}
            else if(p.m6.posicionsPINTAR[i] == 'r'){ps(&finestra_joc,&rataNEG,posicionsXY(i));}
        }
        if(p.m6.dirOri == 'N'){ps(&finestra_joc,&Nord,p.m6.origen);}
        else if(p.m6.dirOri == 'E'){ps(&finestra_joc,&Est,p.m6.origen);}
        else if(p.m6.dirOri == 'S'){ps(&finestra_joc,&Sud,p.m6.origen);}
        else if(p.m6.dirOri == 'O'){ps(&finestra_joc,&Oest,p.m6.origen);}
        ps_mode(&finestra_joc, &cercleNEG, s.cap, 2);}
    if (mode == 66){
        if (p.m6.HS6 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m6.HS6 = p.m0.puntuacio*5;}
        if (pintarHUD(p.m6.HS6, p.m0.puntuacio*5) == 1){return 1;}
        for (int i = 0; i<240; i++){if(p.m6.posicionsPINTAR[i] == 'b'){ferforma(&finestra_joc,posicionsXY(i),5,5,blanc);}}
        pintarSERP(); ps(&finestra_joc,&rata,p.m0.R);}
    if (mode == 7){
        if (p.m7.HS7 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m7.HS7 = p.m0.puntuacio*5;} 
        if (pintarHUD(p.m7.HS7, p.m0.puntuacio*5) == 1){return 1;}
        pintarSERP(); ps(&finestra_joc,&rata,p.m0.R);}
    if (mode == 8){
        if (p.m8.HS8 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m8.HS8 = p.m0.puntuacio*5;} 
        if (pintarHUD(p.m8.HS8, p.m0.puntuacio*5) == 1){return 1;}
        pintarSERP(); ps(&finestra_joc,&rata,p.m0.R);}
    if (mode == 9){
        if (p.m9.HS9 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m9.HS9 = p.m0.puntuacio*5;} 
        if (pintarHUD(p.m9.HS9, p.m0.puntuacio*5) == 1){return 1;}
        pintarSERP(); ps(&finestra_joc,&rata,p.m0.R);}
    if (mode == 10){
        if (p.m10.HS10 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m10.HS10 = p.m0.puntuacio*5;} 
        if (pintarHUD(p.m10.HS10, p.m0.puntuacio*5) == 1){return 1;}
        pintarSERP_CAPICUA(); ps(&finestra_joc,&rata,p.m0.R);}
    if (mode == 11){
        if (p.m11.HS11 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m11.HS11 = p.m0.puntuacio*5;}
        if (pintarHUD(p.m11.HS11, p.m0.puntuacio*5) == 1){return 1;}
        if (p.m11.pitfora == 1){ps(&finestra_joc,&cercle,p.m11.P);}
        pintarSERP(); ps(&finestra_joc,&rata,p.m0.R);}
    if (mode == 12){
        if (p.m12.HS12 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m12.HS12 = p.m0.puntuacio*5;} 
        if (pintarHUD(p.m12.HS12, p.m0.puntuacio*5) == 1){return 1;}
        pintarSERP_DIAGONAL(); ps(&finestra_joc,&rata,p.m0.R);}
    if (mode == 13){
        if (p.m13.HS13 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m13.HS13 = p.m0.puntuacio*5;} 
        if (pintarHUD_mode(p.m13.HS13, p.m0.puntuacio*5, 13) == 1){return 1;}
        //for(int i = 0; i < p.m13.NUMcasellesocupades; i++){ps(&finestra_joc,&rata,p.m13.casellesocupades[i]);}
        pintarSERP_SMOOTH(); ps(&finestra_joc,&rata,p.m0.R);}
    if (mode == 14){
        if (p.m14.HS14 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m14.HS14 = p.m0.puntuacio*5;} 
        if (pintarHUD(p.m14.HS14, p.m0.puntuacio*5) == 1){return 1;}
        pintarSERP();
        for(int r=0; r<5; r+=1){
            if (p.m14.rates[r].caracter == 1){ps(&finestra_joc,&rata,p.m14.rates[r].origen);}
            else{ps(&finestra_joc,&rataFALSA,p.m14.rates[r].origen);}
        }}
    if (mode == 15){
        if (p.m15.HS15 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m15.HS15 = p.m0.puntuacio*5;} 
        if (pintarHUD(p.m15.HS15, p.m0.puntuacio*5) == 1){return 1;}
        pintarSERP();
        if (p.m15.dirRATA == 'N'){ps(&finestra_joc,&rataS,p.m0.R);}
        if (p.m15.dirRATA == 'S'){ps(&finestra_joc,&rataN,p.m0.R);}
        if (p.m15.dirRATA == 'E'){ps(&finestra_joc,&rataO,p.m0.R);}
        if (p.m15.dirRATA == 'O'){ps(&finestra_joc,&rataE,p.m0.R);}}
    if (mode == 16){
        if (p.m16.HS16 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m16.HS16 = p.m0.puntuacio*5;} 
        if (pintarHUD(p.m16.HS16, p.m0.puntuacio*5) == 1){return 1;}
        pintarSERP(); ps(&finestra_joc,&rata,p.m0.R);}
    if (mode == 17 || mode == 177){
        if (mode == 17) {
            if (p.m17.HS17 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m17.HS17 = p.m0.puntuacio*5;}
            if (pintarHUD_mode(p.m17.HS17, p.m0.puntuacio*5, 17) == 1){return 1;}
            //ps(finestra_general, marc, {13,1});
            pintarSERP();
            int rataalavista = 0;
            I2 top_left = {s.cap.x+p.m17.sumes[0],s.cap.y+p.m17.sumes[0]};
            I2 bottom_right = {s.cap.x+p.m17.sumes[4],s.cap.y+p.m17.sumes[4]};
            for (int index = 0; index<240; index++){
                I2 i = posicionsXY(index);
                if (i.x < top_left.x || i.y < top_left.y || i.x > bottom_right.x || i.y > bottom_right.y)
                    {ferforma(&finestra_joc, i,5,5,blanc);}
                else{if (i.x == p.m0.R.x && i.y == p.m0.R.y) {rataalavista = 1;}}
            }
            ps(&finestra_joc,&rata,p.m0.R);
            if (rataalavista == 0){ferforma_mode(&finestra_joc,p.m0.R,5,5,negre,2);}
            ps(&finestra_joc,&focus,i2(s.cap.x+p.m17.sumes[0],s.cap.y+p.m17.sumes[0]));
        }
        else{pintarHUD(p.m17.HS17, p.m0.puntuacio*5); pintarSERP(); ps(&finestra_joc,&rata,p.m0.R);}
    }
    if (mode == 18){
        if (p.m18.HS18 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m18.HS18 = p.m0.puntuacio*5;} 
        if (pintarHUD(p.m18.HS18, p.m0.puntuacio*5) == 1){return 1;}
        pintarSERP_GALLINETA();
        if(p.m18.flash >= 1){//GUARRADA NECESSARIA FLAIX 18
            if(p.m18.flash<=5){p.m18.flash++;} else{p.m18.flash = 0;} 
            ferforma(&finestra_joc,i2(14,2),100,60,blanc); ps(&finestra_joc,&rataNEG,p.m0.R);}}
    if (mode == 19){
        if (p.m19.HS19 > p.m0.puntuacio){p.m19.HS19 = p.m0.puntuacio;}
        if (pintarHUD(p.m19.HS19, p.m0.puntuacio) == 1){return 1;}
        pintarSERP();}
    if(mode == 20){
        if (p.m20.HS20 < t){p.m20.HS20 = t;} if (pintarHUD(p.m20.HS20, t) == 1){return 1;}
        pintarSERP(); ps(&finestra_joc,&rata,p.m0.R);}
    if (mode == 21){
        if (p.m21.HS21 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m21.HS21 = p.m0.puntuacio*5;} 
        if (pintarHUD(p.m21.HS21, p.m0.puntuacio*5) == 1){return 1;}
        ps(&finestra_joc,&cercle,p.m21.forat); pintarSERP(); ps(&finestra_joc,&rata,p.m0.R);}
    if (mode == 22){
        if (p.m22.HS22 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m22.HS22 = p.m0.puntuacio*5;} 
        if (pintarHUD(p.m22.HS22, p.m0.puntuacio*5) == 1){return 1;}
        pintarSERP(); ps(&finestra_joc,&rata,p.m0.R);}
    if(mode == 23){
        if (p.m23.HS23 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m23.HS23 = p.m0.puntuacio*5;} 
        if (pintarHUD(p.m23.HS23, p.m0.puntuacio*5) == 1){return 1;}
        pintarSERP_1D(); ps(&finestra_joc,&rata,p.m0.R);}
    if(mode == 24){
        if (p.m24.HS24 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m24.HS24 = p.m0.puntuacio*5;} 
        if (pintarHUD(p.m24.HS24, p.m0.puntuacio*5) == 1){return 1;}
        pintarSERP_FANTASMA(); ps(&finestra_joc,&rata,p.m24.prota); ps(&finestra_joc,&rataNEG,p.m0.R);}
    if (mode == 25){
        if (p.m25.HS25 < p.m0.puntuacio*5 && p.m0.puntuacio*5 < 999){p.m25.HS25 = p.m0.puntuacio*5;} 
        if (pintarHUD_mode(p.m25.HS25, p.m0.puntuacio*5, 25) == 1){return 1;}
        pintarSERP_RETRO(); ferforma(&finestra_joc,p.m0.R,2,2,blanc);}

    return 0;
}

int gestionarINPUT(){
    if (controller.left.pressed && s.dirR != 'E'){s.dir = 'O';}
    if (controller.right.pressed && s.dirR != 'O'){s.dir = 'E';}
    if (controller.down.pressed && s.dirR != 'N'){s.dir = 'S';}
    if (controller.up.pressed && s.dirR != 'S'){s.dir = 'N';}
    return 0;
}

int gestionarINPUT_INVERS(){
    if (controller.right.pressed && s.dirR != 'E'){s.dir = 'O';}
    if (controller.left.pressed && s.dirR != 'O'){s.dir = 'E';}
    if (controller.down.pressed && s.dirR != 'S'){s.dir = 'N';}
    if (controller.up.pressed && s.dirR != 'N'){s.dir = 'S';}
    return 0;
}

int gestionarINPUT_EGO(){
    if (controller.left.half_transition_count && controller.left.pressed && p.m2.puc_girar == 1){
        p.m2.puc_girar = 0;
        p.m2.index_dir -= 1;
        if (p.m2.index_dir < 0){p.m2.index_dir = 3;}}
    if (controller.right.half_transition_count && controller.right.pressed && p.m2.puc_girar == 1){
        p.m2.puc_girar = 0;
        p.m2.index_dir += 1;
        if (p.m2.index_dir > 3){p.m2.index_dir = 0;}}
    s.dir = p.m2.direccions[p.m2.index_dir];
    return 0;
}

int gestionarINPUT_STRA(){
    
    if (controller.left.pressed){p.m3.dir_mira='O';}
    if (controller.right.pressed){p.m3.dir_mira='E';};
    if (controller.down.pressed){p.m3.dir_mira='S';}
    if (controller.up.pressed){p.m3.dir_mira='N';}

    if (controller.A.pressed && controller.A.half_transition_count){p.m3.ordre = p.m3.mira; p.m3.ordre_donada = 1;}
    if (controller.B.pressed && controller.B.half_transition_count){p.m3.ordre_donada = 0;}
    return 0;
}

int gestionarINPUT_PINTAR(){

    if (controller.left.pressed){s.dir = 'O';}
    if (controller.right.pressed){s.dir = 'E';}
    if (controller.down.pressed){s.dir = 'S';}
    if (controller.up.pressed){s.dir = 'N';}

    if(p.m6.acabemdecomencar == 0){
        if (controller.A.pressed && controller.B.pressed == true){p.m6.colorBN = 'r'; p.m6.HS6 = 0;}
        else if (controller.A.pressed){p.m6.colorBN = 'b'; p.m6.HS6 = 0;}
        else if (controller.B.pressed){p.m6.colorBN = 'n'; p.m6.HS6 = 0;}
        else{p.m6.colorBN = 'i';}
    }
    else{
        if (controller.A.half_transition_count){p.m6.acabemdecomencar = 0;}}
    return 0;
}

int gestionarINPUT_MANUAL(){
    s.dir = ' ';
    if (controller.left.pressed && controller.left.half_transition_count && s.dirR != 'E'){s.dir = 'O';}
    if (controller.right.pressed && controller.right.half_transition_count && s.dirR != 'O'){s.dir = 'E';}
    if (controller.down.pressed && controller.down.half_transition_count && s.dirR != 'N'){s.dir = 'S';}
    if (controller.up.pressed && controller.up.half_transition_count && s.dirR != 'S'){s.dir = 'N';}
    return 0;
}

int capicua(){

    for(int pos = 0; pos <=s.length; pos++){p.m10.posicionsaux[pos] = s.posicions[s.length-pos];}
    for(int pos = 0; pos <=s.length; pos++){s.posicions[pos] = p.m10.posicionsaux[pos];}
    s.cap.x = s.posicions[0].x; s.cap.y = s.posicions[0].y;

    if(p.m10.mode==0){p.m10.mode=1;} else{p.m10.mode=0;} 
    p.m10.diraux = s.dircua;
    s.dircua = s.dirR;
    s.dir = p.m10.diraux;
    s.dirR = s.dir;
    
    return 0;
}

int gestionarINPUT_CAPICUA(){
    
    if (controller.left.pressed && s.dirR != 'E' && controller.left.half_transition_count){s.dir = 'O';}
    if (controller.right.pressed && s.dirR != 'O' && controller.right.half_transition_count){s.dir = 'E';}
    if (controller.down.pressed && s.dirR != 'N' && controller.down.half_transition_count){s.dir = 'S';}
    if (controller.up.pressed && s.dirR != 'S' && controller.up.half_transition_count){s.dir = 'N';}
    
    if (controller.left.pressed && controller.left.half_transition_count){
        if(s.dirR != 'E'){s.dir = 'O';}else{capicua();}}
    if (controller.right.pressed && controller.right.half_transition_count){
        if(s.dirR != 'O'){s.dir = 'E';}else{capicua();}}
    if (controller.down.pressed && controller.down.half_transition_count){
        if(s.dirR != 'N'){s.dir = 'S';}else{capicua();}}
    if (controller.up.pressed && controller.up.half_transition_count){
        if(s.dirR != 'S'){s.dir = 'N';}else{capicua();}}
    if (controller.A.pressed && controller.A.half_transition_count){capicua();}
    return 0;
}

//TODO: SEGUIR BUSCANT ELSE IFs
int gestionarINPUT_REMOT(){
    int shadefer = 0;
    
    if (controller.left.pressed && s.dirR != 'E'){s.dir = 'O';}
    if (controller.right.pressed && s.dirR != 'O'){s.dir = 'E';}
    if (controller.down.pressed && s.dirR != 'N'){s.dir = 'S';}
    if (controller.up.pressed && s.dirR != 'S'){s.dir = 'N';}

    if (controller.up.pressed && controller.up.half_transition_count && s.dirR != 'S'){
        if (s.dirR != 'N'){s.dir = 'N';}
        else{if (p.m11.pitfora == 0){shadefer = 1;}}}
    else if (controller.down.pressed && controller.down.half_transition_count && s.dirR != 'N'){
        if(s.dirR != 'S'){s.dir = 'S';}
        else{if (p.m11.pitfora == 0){shadefer = 1;}}}
    else if (controller.left.pressed && controller.left.half_transition_count && s.dirR != 'E'){
        if(s.dirR != 'O'){s.dir = 'O';}
        else{if (p.m11.pitfora == 0){shadefer = 1;}}}
    else if (controller.right.pressed && controller.right.half_transition_count && s.dirR != 'O'){
        if(s.dirR != 'E'){s.dir = 'E';}
        else{if (p.m11.pitfora == 0){shadefer = 1;}}}
    if (controller.A.pressed && controller.A.half_transition_count){if (p.m11.pitfora == 0){shadefer = 1;}}

    if(shadefer == 1 && s.length >1){p.m11.pitfora = 1; p.m11.direcciopit = s.dirR; s.length -= 1;}
    return 0;
}

int gestionarINPUT_DIAGONAL(){
    if (controller.up.pressed){p.m12.dir1 = 'N';}
    else if (controller.down.pressed){p.m12.dir1 = 'S';}
    else{p.m12.dir1 = ' ';}

    if (controller.left.pressed){p.m12.dir2 = 'O';}
    else if (controller.right.pressed){p.m12.dir2 = 'E';}
    else{p.m12.dir2 = ' ';}
    return 0;
}

int gestionarINPUT_1D(){
    
    if (controller.down.pressed){s.dir = 'S';}
    if (controller.up.pressed){s.dir = 'N';}
    if (controller.right.pressed){s.dir = 'E';}
    return 0;
}

int gestionarINPUT_IA(){

    if (controller.left.pressed){p.m24.dirRATA = 'O';}
    if (controller.right.pressed){p.m24.dirRATA = 'E';}
    if (controller.down.pressed){p.m24.dirRATA = 'S';}
    if (controller.up.pressed){p.m24.dirRATA = 'N';}
    return 0;
}

int ferCREIXERoDECREIXER_mode(int mode /*= 0 */){
    if (mode == 0){mode = s.creixer;}

    if (mode == 1){
        s.length += 1; s.posicions[s.length] = s.posicions[s.length-1];}

    if (mode == -1){s.length -= 1;}

    s.creixer = 0;
    return 0;
}

int ferCREIXERoDECREIXER(){
    return ferCREIXERoDECREIXER_mode(0);
}

int ferCREIXERoDECREIXER_1D(){
    if (s.creixer == 1)
    {
        p.m0.puntuacio += 1; s.creixer = 0;
        if(s.length < 8)
        {   
            s.length += 1; 
            s.posicions[s.length] = i2(s.posicions[s.length-1].x-5, s.posicions[s.length-1].y);
        }        
    }
    return 0;
}

int moureSERP_dir_mode(char dir_obligada /*= 'X'*/, int mode /*= 0 */){
    I2 posicio_al_inici;
    posicio_al_inici = s.cap;
    char direccio_a_moures; direccio_a_moures = s.dir;
    if (dir_obligada != 'X'){direccio_a_moures = dir_obligada;}
    //printf("%i ",s.lloc);
    if (direccio_a_moures == 'N'){s.cap.y -= 5; s.dirR = 'N'; s.lloc -= 1;}
    if (direccio_a_moures == 'S'){s.cap.y += 5; s.dirR = 'S'; s.lloc += 1;}
    if (direccio_a_moures == 'O'){s.cap.x -= 5; s.dirR = 'O'; s.lloc -= 12;}
    if (direccio_a_moures == 'E'){s.cap.x += 5; s.dirR = 'E'; s.lloc += 12;}
    //printf("%i\n",s.lloc);

    //Detectar sortida dels limits
    if (s.cap.x < 14 || s.cap.x > 109 || s.cap.y < 2 || s.cap.y > 57)
    {s.cap = posicio_al_inici; return 1;}
    if (mode == 66 && p.m6.posicionsPINTAR[s.lloc] == 'b')
    {s.cap = posicio_al_inici; return 1;}

    //Detectar trompada amb ell mateix
    for (int n = 1; n<s.length; n+=1)
    {
        if (s.cap.x == s.posicions[n].x && s.cap.y == s.posicions[n].y)
        {s.cap = posicio_al_inici; return 2;}
    }

    //Moure les posicions
    for (int n = s.length; n>0; n-=1)
    {s.posicions[n] = s.posicions [n-1];}
    s.posicions[0].x = s.cap.x;
    s.posicions[0].y = s.cap.y;

    //Canviar direcció de la cua
    if (s.posicions[s.length].x > s.posicions[s.length-1].x)
    {s.dircua = 'E';}
    if (s.posicions[s.length].x < s.posicions[s.length-1].x)
    {s.dircua = 'O';}
    if (s.posicions[s.length].y > s.posicions[s.length-1].y)
    {s.dircua = 'S';}
    if (s.posicions[s.length].y < s.posicions[s.length-1].y)
    {s.dircua = 'N';}

    return 0;
}

int moureSERP_dir(char dir_obligada){
    return moureSERP_dir_mode(dir_obligada, 0);
}

int moureSERP(){
    return moureSERP_dir_mode('X', 0);
}

int moureSERP_VORES(){

    I2 posicio_al_inici = s.cap;
    
    //printf("%i ",s.lloc);
    if (s.dir == 'N'){s.cap.y -= 5; s.dirR = 'N'; s.lloc -= 1;}
    if (s.dir == 'S'){s.cap.y += 5; s.dirR = 'S'; s.lloc += 1;}
    if (s.dir == 'O'){s.cap.x -= 5; s.dirR = 'O'; s.lloc -= 12;}
    if (s.dir == 'E'){s.cap.x += 5; s.dirR = 'E'; s.lloc += 12;}
    //printf("%i\n",s.lloc);

    //Detectar sortida dels limits
    if (s.cap.x < 14) {s.cap.x = 109; s.lloc+=20*12;}// s.length-=1;}
    if (s.cap.x > 109){s.cap.x = 14; s.lloc-=20*12;}// s.length-=1;}
    if (s.cap.y < 2)  {s.cap.y = 57; s.lloc+=12;}// s.length-=1;}
    if (s.cap.y > 57) {s.cap.y = 2; s.lloc-=12;}// s.length-=1;}   
    
    //Detectar trompada amb ell mateix
    for (int n = 1; n<s.length; n+=1)
    {
        if (s.cap.x == s.posicions[n].x && s.cap.y == s.posicions[n].y)
        {s.cap = posicio_al_inici; return 2;}
    }

    //Moure les posicions
    for (int n = s.length; n>0; n-=1)
    {s.posicions[n] = s.posicions [n-1];}
    s.posicions[0].x = s.cap.x;
    s.posicions[0].y = s.cap.y;

    //Canviar direcció de la cua
    if (s.posicions[s.length].x > s.posicions[s.length-1].x)
    {s.dircua = 'E';}
    if (s.posicions[s.length].x < s.posicions[s.length-1].x)
    {s.dircua = 'O';}
    if (s.posicions[s.length].y > s.posicions[s.length-1].y)
    {s.dircua = 'S';}
    if (s.posicions[s.length].y < s.posicions[s.length-1].y)
    {s.dircua = 'N';}

    if (s.posicions[s.length].x == 109 && s.posicions[s.length-1].x == 14) {s.dircua = 'O';}
    if (s.posicions[s.length].x == 14 && s.posicions[s.length-1].x == 109) {s.dircua = 'E';}
    if (s.posicions[s.length].y == 57 && s.posicions[s.length-1].y == 2) {s.dircua = 'N';}
    if (s.posicions[s.length].y == 2 && s.posicions[s.length-1].y == 57) {s.dircua = 'S';}

    return 0;
}

int moureSERP_FANTASMA_dir_mode(char dir_obligada /*= 'X' */, char mode /*= 0*/){

    I2 posicio_al_inici;
    posicio_al_inici = s.cap;
    char direccio_a_moures; direccio_a_moures = s.dir;
    if (dir_obligada != 'X'){direccio_a_moures = dir_obligada;}
    //printf("%i ",s.lloc);
    if (direccio_a_moures == 'N'){s.cap.y -= 5; s.dirR = 'N'; s.lloc -= 20;}
    if (direccio_a_moures == 'S'){s.cap.y += 5; s.dirR = 'S'; s.lloc += 20;}
    if (direccio_a_moures == 'O'){s.cap.x -= 5; s.dirR = 'O'; s.lloc -= 1;}
    if (direccio_a_moures == 'E'){s.cap.x += 5; s.dirR = 'E'; s.lloc += 1;}
    //printf("%i\n",s.lloc);

    //Detectar sortida dels limits
    if (s.cap.x < 14 || s.cap.x > 109|| s.cap.y < 2 || s.cap.y > 57)
    {return 1;}

    //Moure les posicions
    for (int n = s.length; n>0; n-=1)
    {s.posicions[n] = s.posicions [n-1];}
    s.posicions[0].x = s.cap.x;
    s.posicions[0].y = s.cap.y;
    
    if (s.length >=5 && mode == 0){
        for (int n = 3; n<s.length; n+=1){
            if (s.posicions[0].x == s.posicions[n].x && s.posicions[0].y == s.posicions[n].y){
                if((s.posicions[1].x == s.posicions[n-1].x && s.posicions[1].y == s.posicions[n-1].y)||
                   (s.posicions[1].x == s.posicions[n+1].x && s.posicions[1].y == s.posicions[n+1].y)){return 2;}
            }
        }
    }
    
    //Canviar direcció de la cua
    if (s.posicions[s.length].x > s.posicions[s.length-1].x)
    {s.dircua = 'E';}
    if (s.posicions[s.length].x < s.posicions[s.length-1].x)
    {s.dircua = 'O';}
    if (s.posicions[s.length].y > s.posicions[s.length-1].y)
    {s.dircua = 'S';}
    if (s.posicions[s.length].y < s.posicions[s.length-1].y)
    {s.dircua = 'N';}

    return 0;
}

int moureSERP_FANTASMA(){
    return moureSERP_FANTASMA_dir_mode('X', 0);
}

//TODO: BUSCAR ELSE IFS
int moureSERP_DIAGONAL(){

    //TODO: (o no) No permetre que les direccions diagonals siguin acessibles si no s'estan pulsant les tecles corresponents
    if (p.m12.dir1 == 'N'){
        if (p.m12.dir2 == 'E' && s.dirR != 'A'){s.dirR = 'W';}
        else if (p.m12.dir2 == 'O' && s.dirR != 'D'){s.dirR = 'Q';}
        else{if(s.dirR != 'S'){s.dirR = 'N';}}
    }
    else if (p.m12.dir1 == 'S'){
        if (p.m12.dir2 == 'E' && s.dirR != 'Q'){s.dirR = 'D';}
        else if (p.m12.dir2 == 'O' && s.dirR != 'W'){s.dirR = 'A';}
        else{if(s.dirR != 'N'){s.dirR = 'S';}}
    }
    else{
        if (p.m12.dir2 == 'E' && s.dirR != 'O'){s.dirR = 'E';}
        else if (p.m12.dir2 == 'O' && s.dirR != 'E'){s.dirR = 'O';}
    }

    if (s.dirR == 'W'){s.cap.y -= 5; s.cap.x += 5;}
    if (s.dirR == 'Q'){s.cap.y -= 5; s.cap.x -= 5;}
    if (s.dirR == 'D'){s.cap.y += 5; s.cap.x += 5;}
    if (s.dirR == 'A'){s.cap.y += 5; s.cap.x -= 5;}
    if (s.dirR == 'N'){s.cap.y -= 5;}
    if (s.dirR == 'S'){s.cap.y += 5;}
    if (s.dirR == 'E'){s.cap.x += 5;}
    if (s.dirR == 'O'){s.cap.x -= 5;}

    if (s.cap.x < 14 || s.cap.x > 109|| s.cap.y < 2 || s.cap.y > 57)
    {return 1;}//{printf("Sóc fora del ring"); return 1;}

    //Detectar trompada amb ell mateix
    for (int n = 1; n<s.length; n+=1)
    {
        if (s.cap.x == s.posicions[n].x && s.cap.y == s.posicions[n].y)
        {return 2;}//{printf("He xocat"); return 1;}
    }
    for (int i = 0; i<p.m12.index12; i+=1)
    {
        if (s.cap.x == p.m12.posicions12[i].x && s.cap.y == p.m12.posicions12[i].y)
        {return 2;}//{printf("He xocat"); return 1;}
    }

    //Moure les posicions
    for (int n = s.length; n>0; n-=1)
    {s.posicions[n] = s.posicions [n-1];}
    s.posicions[0].x = s.cap.x;
    s.posicions[0].y = s.cap.y;

    //Canviar direcció de la cua
    if (s.posicions[s.length].x > s.posicions[s.length-1].x)
    {s.dircua = 'E';}
    if (s.posicions[s.length].x < s.posicions[s.length-1].x)
    {s.dircua = 'O';}
    if (s.posicions[s.length].y > s.posicions[s.length-1].y)
    {s.dircua = 'S';}
    if (s.posicions[s.length].y < s.posicions[s.length-1].y)
    {s.dircua = 'N';}

    return 0;
}

int moureSERP_SMOOTH(){

    I2 posicio_al_inici = s.cap;
    //printf("%i ",s.lloc);
    if (s.dir == 'N'){s.cap.y -= 1; s.dirR = 'N'; s.lloc -= 1;}
    if (s.dir == 'S'){s.cap.y += 1; s.dirR = 'S'; s.lloc += 1;}
    if (s.dir == 'O'){s.cap.x -= 1; s.dirR = 'O'; s.lloc -= 12;}
    if (s.dir == 'E'){s.cap.x += 1; s.dirR = 'E'; s.lloc += 12;}
    //printf("%i\n",s.lloc);

    //Detectar sortida dels limits
    if (s.cap.x < 14 || s.cap.x > 109 || s.cap.y < 2 || s.cap.y > 57)
    {s.cap = posicio_al_inici; return 1;}
    //Detectar trompada amb ell mateix
    for (int n = 8; n<s.length; n+=1)
    {
        for(int x = -4; x < 5; x++){
            for(int y = -4; y < 5; y++){
                if (s.posicions[n].x+x == s.cap.x && s.posicions[n].y+y == s.cap.y){return 2;}
            }
        }
    }

    //Moure les posicions
    for (int n = s.length; n>0; n-=1)
    {s.posicions[n] = s.posicions [n-1];}
    s.posicions[0].x = s.cap.x;
    s.posicions[0].y = s.cap.y;

    //Canviar direcció de la cua
    if (s.posicions[s.length].x > s.posicions[s.length-1].x)
    {s.dircua = 'E';}
    if (s.posicions[s.length].x < s.posicions[s.length-1].x)
    {s.dircua = 'O';}
    if (s.posicions[s.length].y > s.posicions[s.length-1].y)
    {s.dircua = 'S';}
    if (s.posicions[s.length].y < s.posicions[s.length-1].y)
    {s.dircua = 'N';}

    return 0;
}

int moureSERP_1D(){

    I2 posicio_al_inici = s.cap;
    //printf("%i ",s.lloc);
    if (s.dir == 'N'){s.cap.y -= 5; s.dirR = 'N'; s.lloc -= 1;}
    if (s.dir == 'S'){s.cap.y += 5; s.dirR = 'S'; s.lloc += 1;}
    if (s.dir == 'E'){s.dirR = 'E';}

    //Detectar sortida dels limits
    if (s.cap.y < 2 || s.cap.y > 57)
    {s.cap = posicio_al_inici; return 1;}

    //Detectar trompada amb una rata
    for (int n = s.length; n>0; n-=1)
    {
        if (s.posicions[n].x-5 <= p.m0.R.x && s.posicions[n].x >= p.m0.R.x && s.posicions[n].y == p.m0.R.y){return 2;}
        s.posicions[n].y = s.posicions[n-1].y;
    }
    s.posicions[0].x = s.cap.x;
    s.posicions[0].y = s.cap.y;

    //Canviar direcció de la cua
    if (s.posicions[s.length].x > s.posicions[s.length-1].x)
    {s.dircua = 'E';}
    if (s.posicions[s.length].x < s.posicions[s.length-1].x)
    {s.dircua = 'O';}
    if (s.posicions[s.length].y > s.posicions[s.length-1].y)
    {s.dircua = 'S';}
    if (s.posicions[s.length].y < s.posicions[s.length-1].y)
    {s.dircua = 'N';}
    return 0;
}

int moureSERP_RETRO(){

    I2 posicio_al_inici = s.cap;
    //printf("%i ",s.lloc);
    if (s.dir == 'N'){s.cap.y -= 3; s.dirR = 'N'; s.lloc -= 1;}
    if (s.dir == 'S'){s.cap.y += 3; s.dirR = 'S'; s.lloc += 1;}
    if (s.dir == 'O'){s.cap.x -= 3; s.dirR = 'O'; s.lloc -= 12;}
    if (s.dir == 'E'){s.cap.x += 3; s.dirR = 'E'; s.lloc += 12;}
    //printf("%i\n",s.lloc);

    //Detectar sortida dels limits
    if (s.cap.x < 15 || s.cap.x > 111 || s.cap.y < 3 || s.cap.y > 60)
        {s.cap = posicio_al_inici; return 1;}
    //Detectar trompada amb ell mateix
    for (int n = 1; n<s.length; n+=1)
    {
        if (s.cap.x == s.posicions[n].x && s.cap.y == s.posicions[n].y)
        {s.cap = posicio_al_inici; return 2;}
    }

    //Moure les posicions
    for (int n = s.length; n>0; n-=1)
    {s.posicions[n] = s.posicions [n-1];}
    s.posicions[0].x = s.cap.x;
    s.posicions[0].y = s.cap.y;

    //Canviar direcció de la cua
    if (s.posicions[s.length].x > s.posicions[s.length-1].x)
    {s.dircua = 'E';}
    if (s.posicions[s.length].x < s.posicions[s.length-1].x)
    {s.dircua = 'O';}
    if (s.posicions[s.length].y > s.posicions[s.length-1].y)
    {s.dircua = 'S';}
    if (s.posicions[s.length].y < s.posicions[s.length-1].y)
    {s.dircua = 'N';}

    return 0;
}

int moureSERP_FINAL(){
    for (int n = s.length; n>0; n-=1)
    {s.posicions[n] = s.posicions[n-1];}

    //Canviar direcció de la cua
    if (s.posicions[s.length].x > s.posicions[s.length-1].x)
    {s.dircua = 'E';}
    if (s.posicions[s.length].x < s.posicions[s.length-1].x)
    {s.dircua = 'O';}
    if (s.posicions[s.length].y > s.posicions[s.length-1].y)
    {s.dircua = 'S';}
    if (s.posicions[s.length].y < s.posicions[s.length-1].y)
    {s.dircua = 'N';}

    if((s.posicions[s.length].x==s.posicions[1].x && s.posicions[s.length].y==s.posicions[1].y)||(s.length <= 0)){return 1;}

    return 0;
}

int crearRATA_mode(int mode /*= 0*/){

    //Crear nova rata
    int posicioReal = 0;
    int posicioIrreal;

    int xinicial;
    int yinicial;
    int ycaselles;
    int xcaselles;
    int desplasament;

    if (mode == 22){
        xinicial = 19; yinicial = 7;
        xcaselles = 18; ycaselles = 10;
        desplasament = 5;
    }
    if(mode == 25){
        xinicial = 15; yinicial = 4;
        xcaselles = 33; ycaselles = 19;
        desplasament = 3;
    }
    if(mode != 22 && mode != 25){
        xinicial = 14; yinicial = 2;
        xcaselles = 20; ycaselles = 12;
        desplasament = 5;
    }

    posicioIrreal = aleat(1, (xcaselles * ycaselles - (s.length+1)));

    for(int y = 0; y < ycaselles; y+=1){
        for(int x = 0; x < xcaselles; x+=1){
            int augmenta = 1;
            for(int cos = 0; cos <= s.length; ++cos)
            {
                if(s.posicions[cos].x == xinicial+x*desplasament && s.posicions[cos].y == yinicial+y*desplasament)
                {
                    augmenta = 0; break;
                }
            }

            if(augmenta == 1){++posicioReal;}

            if(posicioReal >= posicioIrreal)
            {
                p.m0.R = i2(xinicial+x*desplasament, yinicial+y*desplasament);
                //printf("I%i R%i X%i Y%i\n",posicioIrreal, posicioReal, p.m0.R.x, p.m0.R.y);
                return 0;                
            }
        }
    }
    return 1;
}

int crearRATA(){
    return crearRATA_mode(0);
}

int recomptePOSICIONS_6(){
    int cossosirreals = 0;
    for (int i = 0; i<240; i++){
        if(p.m6.posicionsPINTAR[i] == 'r'){
            for (int n = 0; n<=s.length; n+=1){
                if (posicionsXY(i).x == s.posicions[n].x && posicionsXY(i).y == s.posicions[n].y){
                    cossosirreals += 1; break;
                }
            }
        }
    }
    p.m6.cossosreals = s.length+1 - cossosirreals;
    return 0;
}

int crearRATA_BARRERES(){

    //Crear nova rata
    int posicioReal = 0;
    int posicioIrreal;

    recomptePOSICIONS_6(); if(p.m6.cossosreals!=0){p.m6.cossosreals-=1;}
    if (p.m6.cossosreals+p.m6.parets+p.m6.NORATAs >= 20*12){return 1;}
    posicioIrreal = aleat(1, (20 * 12 - (p.m6.cossosreals+p.m6.parets+p.m6.NORATAs)));

    for(int y = 0; y < 12; y+=1){
        for(int x = 0; x < 20; x+=1){
            int augmenta = 1;
            for(int cos = 0; cos <= s.length; ++cos)
            {
                if(s.posicions[cos].x == 14+x*5 && s.posicions[cos].y == 2+y*5)
                {augmenta = 0; break;}
            }
            if(p.m6.posicionsPINTAR[x*12+y] != 'n'){augmenta = 0;}
            if(p.m0.R.x == 14+x*5 && p.m0.R.y == 2+y*5){augmenta = 0;}
            
            if(augmenta == 1){++posicioReal;}

            if(posicioReal >= posicioIrreal)
            {
                p.m0.R = i2(14+x*5, 2+y*5);
                //printf("I%i R%i X%i Y%i\n",posicioIrreal, posicioReal, p.m0.R.x, p.m0.R.y);
                return 0;                
            }
        }
    }
    return 1;
}

int crearRATA_5i13(int mode /*= 0*/){

    //Crear nova rata
    int posicioReal = 0;
    int posicioIrreal;

    if (mode == 5){posicioIrreal = aleat(1, (20 * 12 - (p.m5.NUMposicionsvisibles)));}
    if (mode == 13){posicioIrreal = aleat(1, (20 * 12 - (p.m13.NUMcasellesocupades)));}
    if (mode == 24){posicioIrreal = aleat(1, (20 * 12 - (p.m5.NUMposicionsvisibles+1)));}

    for(int y = 0; y < 12; y+=1){
        for(int x = 0; x < 20; x+=1){
            int augmenta = 1;
            if (mode == 5 || mode == 24){
                for(int posicio = 0; posicio <= p.m5.NUMposicionsvisibles; ++posicio)
                {
                    if(p.m5.posicionsvisibles[posicio].x == 14+x*5 &&
                       p.m5.posicionsvisibles[posicio].y == 2+y*5)
                    {
                        augmenta = 0; break;
                    }
                }
                if (mode == 24){if (p.m24.prota.x == 14+x*5 &&
                                    p.m24.prota.y == 2+y*5)
                                {
                                    augmenta = 0;
                                }
                }
            }
            else if (mode == 13){
                for(int casella = 0; casella <= p.m13.NUMcasellesocupades; ++casella)
                {
                    if(p.m13.casellesocupades[casella].x == 14+x*5 &&
                       p.m13.casellesocupades[casella].y == 2+y*5)
                    {
                        augmenta = 0; break;
                    }
                }
            }
            if(p.m0.R.x == 14+x*5 && p.m0.R.y == 2+y*5){augmenta = 0;}
            
            if(augmenta == 1){++posicioReal;}

            if(posicioReal >= posicioIrreal)
            {
                p.m0.R = i2(14+x*5, 2+y*5);
                //printf("I%i R%i X%i Y%i\n",posicioIrreal, posicioReal, p.m0.R.x, p.m0.R.y);
                return 0;                
            }
        }
    }
    return 1;
}

int crearRATA_DIAGONAL(){

    //Crear nova rata
    int posicioReal = 0;
    int posicioIrreal;

    posicioIrreal = aleat(1, (20 * 12 - (s.length+1+p.m12.index12)));

    for(int y = 0; y < 12; y+=1){
        for(int x = 0; x < 20; x+=1){
            int augmenta = 1;
            for(int cos = 0; cos <= s.length; ++cos)
            {
                if(s.posicions[cos].x == 14+x*5 && s.posicions[cos].y == 2+y*5)
                {augmenta = 0; break;}
            }
            for(int i12 = 0; i12 < p.m12.index12; ++i12)
            {
                if(p.m12.posicions12[i12].x == 14+x*5 && p.m12.posicions12[i12].y == 2+y*5)
                {augmenta = 0; break;}
            }
            if(p.m0.R.x == 14+x*5 && p.m0.R.y == 2+y*5){augmenta = 0;}
           
            if(augmenta == 1){++posicioReal;}

            if(posicioReal >= posicioIrreal)
            {
                p.m0.R = i2(14+x*5, 2+y*5);
                //printf("I%i R%i X%i Y%i\n",posicioIrreal, posicioReal, p.m0.R.x, p.m0.R.y);
                return 0;                
            }
        }
    }
    return 1;
}

int moureMIRA(){

    if (p.m3.dir_mira == 'N'){p.m3.mira.y -= 5;}
    if (p.m3.dir_mira == 'S'){p.m3.mira.y += 5;}
    if (p.m3.dir_mira == 'O'){p.m3.mira.x -= 5;}
    if (p.m3.dir_mira == 'E'){p.m3.mira.x += 5;}

    if (p.m3.mira.x < 14) {p.m3.mira.x = 109;}
    if (p.m3.mira.x > 109) {p.m3.mira.x = 14;}
    if (p.m3.mira.y < 2) {p.m3.mira.y = 57;}
    if (p.m3.mira.y > 57) {p.m3.mira.y = 2;}

    return 0;
}

int moureORIGEN_EDITOR(){

    if (s.cap.x == p.m6.origen.x && s.cap.y == p.m6.origen.y){
        if (s.dirR == 'N'){p.m6.origen.y -= 5;} else if (s.dirR == 'S'){p.m6.origen.y += 5;}
        else if (s.dirR == 'O'){p.m6.origen.x -= 5;} else if (s.dirR == 'E'){p.m6.origen.x += 5;}
    }

    if (p.m6.origen.x < 14){p.m6.origen.x=109; p.m6.dirOri = 'O';}
    if (p.m6.origen.x > 109){p.m6.origen.x=14; p.m6.dirOri = 'E';}
    if (p.m6.origen.y < 2){p.m6.origen.y=57; p.m6.dirOri = 'N';}
    if (p.m6.origen.y > 57){p.m6.origen.y=2; p.m6.dirOri = 'S';}
    
    return 0;
}

int moureRATA_MOBILS(){
    int xy = aleat(0,3);
    for (int i = 0; i <= s.length; ++i)
    {
        if (
            ((xy == 0) && ((p.m0.R.x+5 == s.posicions[i].x && p.m0.R.y == s.posicions[i].y) || (p.m0.R.x == 109))) ||
            ((xy == 1) && ((p.m0.R.x-5 == s.posicions[i].x && p.m0.R.y == s.posicions[i].y) || (p.m0.R.x == 14 ))) ||
            ((xy == 2) && ((p.m0.R.y+5 == s.posicions[i].y && p.m0.R.x == s.posicions[i].x) || (p.m0.R.y == 57 ))) ||
            ((xy == 3) && ((p.m0.R.y-5 == s.posicions[i].y && p.m0.R.x == s.posicions[i].x) || (p.m0.R.y == 2  )))
            )
            {return 0;}
    }
    if (xy == 0){p.m0.R.x += 5;} if (xy == 1){p.m0.R.x -= 5;} if (xy == 2){p.m0.R.y += 5;} if (xy == 3){p.m0.R.y -= 5;}

    return 0;
}

int moureRATA_BASQUET(){
    if (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y){
        if (s.dirR == 'N'){p.m0.R.y -= 5;} if (s.dirR == 'S'){p.m0.R.y += 5;}
        if (s.dirR == 'O'){p.m0.R.x -= 5;} if (s.dirR == 'E'){p.m0.R.x += 5;}
    }

    if (p.m0.R.x < 14 || p.m0.R.x > 109|| p.m0.R.y < 2 || p.m0.R.y > 57){return 1;}

    for (int n = 0; n<=s.length; n++)
    {
        if (s.posicions[n].x == p.m0.R.x && s.posicions[n].y == p.m0.R.y)
        {return 2;}
    }

    return 0;
}

int moureRATA_IA(){

    I2 posicio_al_inici = p.m24.prota;
    //printf("%i ",s.lloc);
    if (p.m24.dirRATA == 'N'){p.m24.prota.y -= 5;}
    if (p.m24.dirRATA == 'S'){p.m24.prota.y += 5;}
    if (p.m24.dirRATA == 'O'){p.m24.prota.x -= 5;}
    if (p.m24.dirRATA == 'E'){p.m24.prota.x += 5;}
    //printf("%i\n",s.lloc);

    //Detectar sortida dels limits
    if (p.m24.prota.x < 14 || p.m24.prota.x > 109 || p.m24.prota.y < 2 || p.m24.prota.y > 57)
    {p.m24.prota = posicio_al_inici; return 1;}

    //Detectar trompada amb ell mateix
    for (int n = 1; n<=s.length; n+=1)
    {
        if (p.m24.prota.x == s.posicions[n].x && p.m24.prota.y == s.posicions[n].y)
        {p.m24.prota = posicio_al_inici; return 2;}
    }

    return 0;
}

int mourePIT(){
    if (p.m11.pitfora == 0){p.m11.P = s.cap;}
    else {
        if (p.m11.P.x < 14 || p.m11.P.x > 109|| p.m11.P.y < 2 || p.m11.P.y > 57)
        {p.m11.pitfora = 0;}

        else{
            if (p.m11.direcciopit == 'E'){p.m11.P.x += 5;}
            if (p.m11.direcciopit == 'O'){p.m11.P.x -= 5;}
            if (p.m11.direcciopit == 'N'){p.m11.P.y -= 5;}
            if (p.m11.direcciopit == 'S'){p.m11.P.y += 5;}

            for (int n = 2; n<=s.length; n+=1)
            {
                if (p.m11.P.x == s.posicions[n].x && p.m11.P.y == s.posicions[n].y)
                {p.m11.pitfora = 0; return 1;} //printf("M'ha entrat un mugró a l'ull");
            }
            if (p.m11.P.x == p.m0.R.x && p.m11.P.y == p.m0.R.y){
                p.m11.pitfora = 0; ferCREIXERoDECREIXER_mode(1); s.creixer = 1; crearRATA();
            }//printf("pit tocant rata\n");}
        }
    }
    return 0;
}

char donarlordre(){
    p.m3.distanciaX = p.m3.ordre.x-s.cap.x;
    p.m3.distanciaY = p.m3.ordre.y-s.cap.y;
    if(abs(p.m3.distanciaX)>abs(p.m3.distanciaY)){
        if (p.m3.distanciaX < 0 && s.dirR != 'E'){return 'O';}
        else if (p.m3.distanciaX > 0 && s.dirR != 'O'){return 'E';}
        else{
            if (p.m3.distanciaY < 0){return 'N';}
            else if (p.m3.distanciaY > 0){return 'S';}
            else{
                if (s.cap.y == 2){return 'S';}   else if (s.cap.y == 57){return 'N';}
                else{if(aleat(0,1) == 0){return 'N';} else{return 'S';}}}
        }
    }
    else{
        if (p.m3.distanciaY < 0 && s.dirR != 'S'){return 'N';}
        else if (p.m3.distanciaY > 0 && s.dirR != 'N'){return 'S';}
        else{
            if (p.m3.distanciaX < 0){return 'O';}
            else if (p.m3.distanciaX > 0){return 'E';}
            else{
                if (s.cap.x == 19){return 'E';}   else if (s.cap.x == 109){return 'O';}
                else{if(aleat(0,1) == 0){return 'O';} else{return 'E';}}}
        }
    }
    return 'X';
}

int recompteCOSSOS_5(){
    int sumo;
    p.m5.posicionsvisibles[0] = s.posicions[0];
    p.m5.NUMposicionsvisibles = 1;
    for (int n = 1; n<=s.length; n+=1){
        sumo = 1;
        for (int m = n-1; m>=0; m-=1){
            if (s.posicions[n].x == s.posicions[m].x && s.posicions[n].y == s.posicions[m].y){sumo = 0; break;}
        }
        if (sumo == 1){p.m5.posicionsvisibles[p.m5.NUMposicionsvisibles] = s.posicions[n];}
        p.m5.NUMposicionsvisibles+=sumo;
    }
    return 0;
}

I2 * casellesocupades(I2 pos){
    static I2 caselles[4];
    if (pos.x-14 % 5 == 0 && pos.x-2 % 5 == 0)
    {
        caselles[0] = pos;
    }
    else if (pos.x-14 % 5 != 0 && pos.x-2 % 5 == 0)
    {
        caselles[0] = i2((pos.x-14)/5*5+14,pos.y);
        caselles[1] = i2(((pos.x-14)/5+1)*5+14,pos.y);
    }
    else if (pos.x-14 % 5 == 0 && pos.x-2 % 5 != 0)
    {
        caselles[0] = i2(pos.x,(pos.y-2)/5*5+2);
        caselles[1] = i2(pos.x,((pos.y-2)/5+1)*5+2);
    }
    else if (pos.x-14 % 5 != 0 && pos.x-2 % 5 != 0)
    {
        caselles[0] = i2((pos.x-14)/5*5+14,(pos.y-2)/5*5+2);
        caselles[1] = i2(((pos.x-14)/5+1)*5+14,((pos.y-2)/5+1)*5+2);
        caselles[2] = i2((pos.x-14)/5*5+14,((pos.y-2)/5+1)*5+2);
        caselles[3] = i2(((pos.x-14)/5+1)*5+14,(pos.y-2)/5*5+2);
    }
    return caselles;
}

int recompteCASELLES_13(){
    int augmenta;
    I2 *casellesfuncio;
    p.m13.NUMcasellesocupades = 0;
    //int n = 0;
    for(int cos = 0; cos <= s.length; ++cos)
    {   
        casellesfuncio = casellesocupades(s.posicions[cos]);
        for(int i = 0; i < 4; i++){
            augmenta = 1;
            for(int casocu = 0; casocu < p.m13.NUMcasellesocupades; casocu++)
            {   
                //n++;
                if (casellesfuncio[i].x == p.m13.casellesocupades[casocu].x && casellesfuncio[i].y == p.m13.casellesocupades[casocu].y)
                {augmenta = 0; break;}
            }
            if (augmenta == 1){
                p.m13.casellesocupades[p.m13.NUMcasellesocupades] = casellesfuncio[i];
                p.m13.NUMcasellesocupades+=augmenta;
            }
        }
    }
    //printf("%i\n",n);
    return 0;
}

int gestionarRATES_mode(int mode /*= 0 */){
    for(int r=0; r<5; r+=1){
        int mha_pillat = 0;
        if (s.posicions[0].x == p.m14.rates[r].origen.x && s.posicions[0].y == p.m14.rates[r].origen.y){
            if(p.m14.rates[r].caracter == 1){mha_pillat = 1;}
            else{return 1;}
        }
        
        if (mha_pillat == 1 || p.m14.rates[r].quanhaaparegut + p.m14.rates[r].durada*5 <= numero_de_fotograma || mode == 1){
            if(mha_pillat == 1){s.creixer = 1; ferCREIXERoDECREIXER();}
            int surto = 0;
            while (surto == 0){
                surto = 1;
                p.m14.rates[r].origen.x = 14+aleat(0,19)*5;
                p.m14.rates[r].origen.y = 2+aleat(0,11)*5;
                for(int i = 0; i<=s.length; ++i){
                    if (s.posicions[i].x == p.m14.rates[r].origen.x && s.posicions[i].y == p.m14.rates[r].origen.y)
                    {surto = 0; break;}
                }
                int aux = 0;
                for(int rr=0; rr<5; rr+=1){
                    if (p.m14.rates[rr].origen.x == p.m14.rates[r].origen.x && p.m14.rates[rr].origen.y == p.m14.rates[r].origen.y)
                    {aux += 1;}
                }
                if(aux > 1){surto = 0;}
            }
            p.m14.rates[r].quanhaaparegut = numero_de_fotograma;
            p.m14.rates[r].durada = aleat(15,50);
            p.m14.rates[r].caracter = aleat(0,1);
        }
    }
    return 0;
}

int gestionarRATES(){
    return gestionarRATES_mode(0);
}

int toca_paret(I2 pos, int mode){
    int ustontodelavariablemode = mode;//printf("%i",mode);
    if (pos.x < 14 || pos.x > 109 || pos.y < 2 || pos.y > 57){
        return 1; }
    
    if (p.m22.index22 != 0){
        for (int i = 0; i<p.m22.index22; i+=1){
            if (p.m22.posicions22[i].x == pos.x && p.m22.posicions22[i].y == pos.y){return 0;} } }
    
    for (int c = 0; c<=s.length; c+=1){
        if (s.posicions[c].x == pos.x && s.posicions[c].y == pos.y){return 0;} }
    
    p.m22.posicions22[p.m22.index22] = pos; p.m22.index22 += 1;
    if (toca_paret(i2(pos.x,   pos.y-5),1) ||      //north
        toca_paret(i2(pos.x,   pos.y+5),2) ||      //south
        toca_paret(i2(pos.x+5, pos.y  ),3) ||      //east
        toca_paret(i2(pos.x-5, pos.y  ),4)){       //west
         return 1; }
    else{return 0;}
}

/*
int trucs(){
    if (controller.A.pressed){ferCREIXERoDECREIXER();}
    if (controller.B.pressed && s.length > 1){ferCREIXERoDECREIXER();}
    if (controller.C.pressed){recompteCASELLES_13(); crearRATA_5i13(13);}
    if (controller.UP.pressed && controller.UP.half_transition_count){p.m0.R.y -= 5;}
    else if (controller.DOWN.pressed && controller.DOWN.half_transition_count){p.m0.R.y += 5;}
    else if (controller.LEFT.pressed && controller.LEFT.half_transition_count){p.m0.R.x -= 5;}
    else if (controller.RIGHT.pressed && controller.RIGHT.half_transition_count){p.m0.R.x += 5;}
    return 0;
}
*/
