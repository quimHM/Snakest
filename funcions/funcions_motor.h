#define invertir(x) (!(x))

/*
int ps_mode_orig(Finestra *f, imatgeC *sprite, I2 pos, int mode){
    int pintar = 1;

    Pixel* pixels_origen = (Pixel *) sprite->pixel_data;

    int ample = sprite->width;
    int abs;
    int alcada = sprite->height;
    int ord;

    int pixel = 0;
    int posicioBP;

    while (pixel < ample*alcada){

        if (mode == 0) //Surt d'una banda i entra per l'oposada
        {
            abs = f->origen.x+(((pixel % ample) + pos.x) % (f->mida.x));
            if (abs < f->origen.x){abs = f->mida.x + abs;}

            ord = f->origen.y+(((pixel / ample) + pos.y) % (f->mida.y));
            if (ord < f->origen.y){ord = f->mida.y + ord;}
        }
        else //if(mode == 1) //Desapareix per les 4 bandes
        {
            pintar = 0;
            abs = (pixel % ample) + pos.x;
            ord = (pixel / ample) + pos.y;
            if (mode != 2){
                if (abs >= f->origen.x+f->mida.x || abs < f->origen.x || ord >= f->origen.y+f->mida.y || ord < f->origen.y)
                {}//El pixel és fora de la pantalla
                else {pintar = 1;}
            }
        }
        //else{printf("Mode no vàlid: %i",mode); break;}

        Pixel foto;
        foto = (( pixels_origen[pixel/4] & (0x3<<(6-2*(pixel%4))) ) >> (6-2*(pixel%4)));
        if(foto == 2){
            pintar = 0;
            if(mode == 2){pintar = 2;}
        }

        posicioBP = (ord*bp.width)+abs;
        if (pintar == 1){f->bitmap.pixels[posicioBP] = foto;}
        else if (pintar == 2){f->bitmap.pixels[posicioBP] = invertir(f->bitmap.pixels[posicioBP]);}

        pixel += 1;
    }

    return 0;
}
*/

int ps_mode(Finestra *f, imatgeC *sprite, I2 pos, int mode){
    BEG_TIMER(ps_mode);

    Pixel* pixels_origen = (Pixel *) sprite->pixel_data;

    int ample = sprite->width;
    int abs;
    int alcada = sprite->height;
    int ord;

#if 1
    I2 top_left = pos;                                  // NOTE: Respecte a la finestra
    I2 top_left_sprite = {0, 0};

    if(top_left.x < f->origen.x){
        U32 diff = f->origen.x - top_left.x;
        ample -= diff;
        top_left.x = f->origen.x;
        top_left_sprite.x = diff;
    }
    if(top_left.y < f->origen.y){ 
        U32 diff = f->origen.y - top_left.y; 
        alcada -= diff;
        top_left.y = f->origen.y;
        top_left_sprite.y = diff;
    }

    I2 bottom_right = {pos.x + ample, pos.y + alcada};  // NOTE: Respeste a la finestra

    if(bottom_right.x > f->origen.x + f->mida.x){
        ample -= bottom_right.x - (f->origen.x + f->mida.x);
        bottom_right.x = f->origen.x + f->mida.x;
    }
    if(bottom_right.y > f->origen.y + f->mida.y){ 
        alcada -= bottom_right.y - (f->origen.y + f->mida.y);
        bottom_right.y = f->origen.y + f->mida.y;
    }

    I2 bottom_right_sprite = {top_left_sprite.x + ample, top_left_sprite.y + alcada};

#endif

    int pixel = 0;
    int posicioBP;

    if(mode == 2){
        // TODO: Aquesta branca encara s'ha d'arreglar
        while (pixel < ample*alcada){
            Pixel foto = (( pixels_origen[pixel/4] & (0x3<<(6-2*(pixel%4))) ) >> (6-2*(pixel%4)));
            if(foto == 2){
                abs = (pixel % ample) + pos.x;
                ord = (pixel / ample) + pos.y;
                posicioBP = (ord*bp.width)+abs;
                f->bitmap.pixels[posicioBP] = invertir(f->bitmap.pixels[posicioBP]);
            }
            pixel += 1;
        }
    }
    else{
        // NOTE: He deixat dues opcions per aquesta branca
#if 1
        for(int ord = 0; ord < alcada; ++ord){      // NOTE: Un 30% mes rapida que l'altra opcio, pero s'enten pitjor
            pixel = (ord+top_left_sprite.y)*sprite->width + top_left_sprite.x;
            posicioBP = (ord+top_left.y)*bp.width + top_left.x;

            int abs = 0;
            while(abs < ample){
                Pixel pixel_sprite = pixels_origen[pixel/4];

                switch(pixel%4){
                  case 0:
                    if(!(pixel_sprite & 0x80)){
                        f->bitmap.pixels[posicioBP] = pixel_sprite>>6 & 0x1;
                    }
                    ++posicioBP; ++abs;
                    if(abs == ample) break;
                  case 1:
                    if(!(pixel_sprite & 0x20)){
                        f->bitmap.pixels[posicioBP] = pixel_sprite>>4 & 0x1;
                    }
                    ++posicioBP; ++abs;
                    if(abs == ample) break;
                  case 2:
                    if(!(pixel_sprite & 0x08)){
                        f->bitmap.pixels[posicioBP] = pixel_sprite>>2 & 0x1;
                    }
                    ++posicioBP; ++abs;
                    if(abs == ample) break;
                  case 3:
                    if(!(pixel_sprite & 0x02)){
                        f->bitmap.pixels[posicioBP] = pixel_sprite & 0x1;
                    }
                    
                    ++posicioBP; ++abs;
                    if(abs == ample) break;
                    break;
                }
                pixel += 4 - (pixel%4);
            }
        }
#else
        for(int ord = 0; ord < alcada; ++ord){
            pixel = (ord+top_left_sprite.y)*sprite->width + top_left_sprite.x;
            posicioBP = (ord+top_left.y)*bp.width + top_left.x;

            for(int abs = 0; abs < ample; ++abs){
                Pixel pixel_sprite = ( pixels_origen[pixel/4] >> (6-2*(pixel%4) )) & 0x3;
                if(pixel_sprite != 2){
                    f->bitmap.pixels[posicioBP] = pixel_sprite;
                }
                ++pixel; ++posicioBP;
            }
        }
#endif
    }

    END_TIMER(ps_mode);

    return 0;
}

int ps(Finestra *f, imatgeC *sprite, I2 pos){
    return ps_mode(f, sprite, pos, 1);
}
/*
int ferforma_mode_orig(Finestra *f, I2 pos, int ample, int alcada, Pixel *color, int mode){
    BEG_TIMER(ps_mode);
    int pintar = 1;
    int abs;
    int ord;

    int pixel = 0;
    int posicioBP;

    while (pixel < ample*alcada){

        if (mode == 0)
        {
            abs = f->origen.x+(((pixel % ample) + pos.x) % (f->mida.x));
            if (abs < f->origen.x){abs = f->mida.x + abs;}

            ord = f->origen.y+(((pixel / ample) + pos.y) % (f->mida.y));
            if (ord < f->origen.y){ord = f->mida.y + ord;}
        }
        else
        {
            pintar = 0;
            abs = (pixel % ample) + pos.x;
            ord = (pixel / ample) + pos.y;
            if (abs >= f->origen.x+f->mida.x || abs < f->origen.x || ord >= f->origen.y+f->mida.y || ord < f->origen.y) //El pixel és fora de la pantalla
            {}
            else {pintar = 1;}
        }
        //else{printf("Mode no vàlid: %i",mode); break;}

        if(pintar == 1)
        {
            posicioBP = (ord*bp.width)+abs;
            if (mode == 2)
            {f->bitmap.pixels[posicioBP] = invertir(f->bitmap.pixels[posicioBP]);}
            else if (mode >= 1000)
            {
                int possibilitatpercent = mode-1000;
                int tiradadedaus = aleat(0,1000);
                if (tiradadedaus > possibilitatpercent)
                    {f->bitmap.pixels[posicioBP] = blanc;}
                else{f->bitmap.pixels[posicioBP] = negre;}
            }
            else{f->bitmap.pixels[posicioBP] = *color;}
        }
        pixel += 1;
    }

    END_TIMER(ps_mode);

    return 0;
}
*/

int ferforma_mode(Finestra *f, I2 pos, int ample, int alcada, Pixel color, int mode /*= 1 */){
    BEG_TIMER(ferforma_mode);
    int posicioBP;

    I2 top_left = pos;
    if(top_left.x < f->origen.x){
        ample -= f->origen.x - top_left.x;
        top_left.x = f->origen.x;
    }
    if(top_left.y < f->origen.y){ 
        alcada -= f->origen.y - top_left.y;
        top_left.y = f->origen.y;
    }
    I2 bottom_right = {pos.x + ample-1, pos.y + alcada-1};
    // IMPORTANT: Si fas servir alcada, amplada, corregeix-los
    if(bottom_right.x > f->origen.x + f->mida.x) bottom_right.x = f->origen.x + f->mida.x;
    if(bottom_right.y > f->origen.y + f->mida.y) bottom_right.y = f->origen.y + f->mida.y;

    if (mode == 2){
        for(U32 ord = top_left.y; ord <= (U32)bottom_right.y; ++ord){
            posicioBP = ord * bp.width + top_left.x;
            for(U32 abs = top_left.x; abs <= (U32)bottom_right.x; ++abs){
                f->bitmap.pixels[posicioBP] = invertir(f->bitmap.pixels[posicioBP]);
                ++posicioBP;
            }
        }
    }
    else if (mode >= 1000){
        for(U32 ord = top_left.y; ord <= (U32)bottom_right.y; ++ord){
            posicioBP = ord * bp.width + top_left.x;
            for(U32 abs = top_left.x; abs <= (U32)bottom_right.x; ++abs){
                int possibilitatpercent = mode-1000;
                int tiradadedaus = aleat(0,1000);
                f->bitmap.pixels[posicioBP] = (tiradadedaus > possibilitatpercent);
                ++posicioBP;
            }
        }
    }
    else{
        for(U32 ord = top_left.y; ord <= (U32)bottom_right.y; ++ord){
            posicioBP = ord * bp.width + top_left.x;
            for(U32 abs = top_left.x; abs <= (U32)bottom_right.x; ++abs){
                f->bitmap.pixels[posicioBP] = color;
                ++posicioBP;
            }
        }
    }
    END_TIMER(ferforma_mode);
    return 0;
}

int ferforma(Finestra *f, I2 pos, int ample, int alcada, Pixel color){
    return ferforma_mode(f, pos, ample, alcada, color, 1);
}
