typedef struct Menu{
    char* titol;
    int opcions;
    char* noms[7];
    unsigned char llargades_pix[7];
    short int xifres[3];
}Menu;

Menu menu_inici = {
    .titol = "inici",
    .opcions = 2,
    };
Menu menu_principal = {
    .titol = "modes",
    .opcions = 7,
    };
Menu menu_control = {
    .titol = "control",
    .opcions = 3,
    };
    
Menu menu_limits = {
    .titol = "limits",
    .opcions = 3,
    };
Menu menu_editor = {
    .titol = "editor",
    .opcions = 2,
    };
    
Menu menu_serp = {
    .titol = "snake",
    .opcions = 7,
    };
Menu menu_rata = {
    .titol = "rat",
    .opcions = 3,
    };
Menu menu_grafic = {
    .titol = "graphics",
    .opcions = 2,
    };
Menu menu_objectiu = {
    .titol = "goal",
    .opcions = 6,
    };
Menu menu_altres = {
    .titol = "other",
    .opcions = 2,
    };

imatgeC lletres[41] = {
      {8, 10, lletra_a_data},
      {8, 10, lletra_b_data},
      {6, 10, lletra_c_data},
      {8, 10, lletra_d_data},
      {6, 10, lletra_e_data},
      {6, 10, lletra_f_data},
      {8, 10, lletra_g_data},
      {8, 10, lletra_h_data},
      {2, 10, lletra_i_data},
      {6, 10, lletra_j_data},
      {8, 10, lletra_k_data},
      {6, 10, lletra_l_data},
      {9, 10, lletra_m_data},
      {8, 10, lletra_n_data},
      {8, 10, lletra_o_data},
      {8, 10, lletra_p_data},
      {8, 10, lletra_q_data},
      {8, 10, lletra_r_data},
      {8, 10, lletra_s_data},
      {8, 10, lletra_t_data},
      {8, 10, lletra_u_data},
      {9, 10, lletra_v_data},
      {9, 10, lletra_w_data},
      {9, 10, lletra_x_data},
      {9, 10, lletra_y_data},
      {8, 10, lletra_z_data},
      {2, 10, punt_data},
      {2, 10, dospunts_data},
      {8, 10, percent_data},
      {1, 10, espai_data},
      {8, 10, zero_data},
      {4, 10, un_data},
      {8, 10, dos_data},
      {8, 10, tres_data},
      {8, 10, quatre_data},
      {8, 10, cinc_data},
      {8, 10, sis_data},
      {8, 10, set_data},
      {8, 10, vuit_data},
      {8, 10, nou_data}
};
char abc[41] = "abcdefghijklmnopqrstuvwxyz.:% 0123456789";
I2 posicions_op_inici[] = {{4,32},{4,44}};
I2 posicions_op[] = {{4,14},{4,26},{4,38},{4,50}};

int comptar_llargada_pix(char* paraula){
    int llargadaOPCIO = 0;
    for(int c = 0; c < (int)strlen(paraula); c+=1){
        for(int ll = 0; ll < 41; ll+=1){
            if (paraula[c] == abc[ll]){
                llargadaOPCIO += lletres[ll].width+2;
            }
        }
    }
    return llargadaOPCIO;
}

int pintar_paraula(char* paraula, I2 pos){
    int x = pos.x; int y = pos.y;
    for(int c = 0; c < (int)strlen(paraula); c+=1){
        for(int ll = 0; ll < 40; ll+=1){
            if (paraula[c] == abc[ll]){
                ps(&finestra_general, lletres+ll,i2(x,y));
                x += lletres[ll].width+2;
            }
        }
    }
    return x;
}

int pintar_puntuacio(char* nom, I2 pos, int puntuacioINT){
    int centenes = puntuacioINT / 100;
    int desenes = (puntuacioINT - 100*centenes) / 10;
    int unitats = puntuacioINT - 100*centenes -10*desenes;
    char puntuacioCHAR[] = {abc[30+centenes],abc[30+desenes],abc[30+unitats]};

    pintar_paraula(nom,pos);
    pintar_paraula(puntuacioCHAR,i2(59,pos.y));

    return comptar_llargada_pix(puntuacioCHAR);
}

void inicialitzar_menu(Menu *me, char* noms_de_les_opcions[], int xifres_de_les_opcions[] /*= {}*/, char mode /*= 'o'*/){
    for(int i = 0; i<me->opcions; i+=1){
        me->noms[i] = noms_de_les_opcions[i];
        me->llargades_pix[i] = comptar_llargada_pix(noms_de_les_opcions[i]);
        if(mode == 'x'){me->xifres[i] = xifres_de_les_opcions[i];}
    }
}

void inicialitzar_TOTS_menus(){
    char* noms_inici[] = {"original snake","modes"};
    char* noms_principal[] = {"control","limits","snake","rat","graphics","goal","other"};
    char* noms_control[] = {"inverted","egocentric","strategic"};
    
    char* noms_limits[] = {"edges","ghost","editor"};
    char* noms_editor[] = {"edit","play"};
    
    char* noms_serp[] = {"adjustable","manual","accelerating","capicua","spitting","diagonal","smooth"};
    char* noms_rata[] = {"too many","directional","mobile"};
    char* noms_grafic[] = {"survival","blind hen"};
    char* noms_objectiu[] = {"everything","hunger","basket","loops","1d","ai"};
    char* noms_altres[] = {"retro","multiplayer"};

    inicialitzar_menu(&menu_inici, noms_inici, 0, 'o');
    inicialitzar_menu(&menu_principal, noms_principal, 0, 'o');
    inicialitzar_menu(&menu_control, noms_control, 0, 'o');
    
    inicialitzar_menu(&menu_limits, noms_limits, 0, 'o');
    inicialitzar_menu(&menu_editor, noms_editor, 0, 'o');
    
    inicialitzar_menu(&menu_serp, noms_serp, 0, 'o');
    inicialitzar_menu(&menu_rata, noms_rata, 0, 'o');
    inicialitzar_menu(&menu_grafic, noms_grafic, 0, 'o');
    inicialitzar_menu(&menu_objectiu, noms_objectiu, 0, 'o');
    inicialitzar_menu(&menu_altres, noms_altres, 0, 'o');
}

int pintar_menus(Menu *menu, int op){
    ferforma(&finestra_general,i2(0,0),128,64,negre);
    int x; int y;
    if (menu->titol == menu_inici.titol){
        x = 64-50; y=7;
        ps(&finestra_general, &SNAKEST,i2(x,y));
        x = 5; y = 7+16+10;
    }
    else{
        int llargadaTITOL = comptar_llargada_pix(menu->titol);
        x = 64-llargadaTITOL/2; y = 2;
        pintar_paraula(menu->titol,i2(x,y));
        x = 5; y = 15;
    }
    int o_inicial; int o_final;
    if(op/4 == 0){o_inicial = 0; o_final = 4;}
    else{o_inicial = 4; o_final = menu->opcions;}
    for (int o = o_inicial; o<o_final && o<menu->opcions; o+=1){
        pintar_paraula(menu->noms[o],i2(x,y));
        y+=12;}
    if (controller.up.pressed && controller.up.half_transition_count && op>0){op-=1;}
    if (controller.down.pressed && controller.down.half_transition_count && op<menu->opcions-1){op+=1;}
    if(numero_de_fotograma % 20 < 10){
        if (menu->titol == menu_inici.titol){ferforma_mode(&finestra_general, posicions_op_inici[op], menu->llargades_pix[op], 12, blanc, 2);}
        else{ferforma_mode(&finestra_general, posicions_op[op%4], menu->llargades_pix[op], 12, blanc, 2);}
    }

    return op;
}

int pintar_menu_XIFRES(Menu *menu, int op, char mode /* = 'x' */){
    ferforma(&finestra_general,i2(0,0),128,64,negre);
    int llargadaTITOL = comptar_llargada_pix(menu->titol);
    int x = 64-llargadaTITOL/2; int y = 2;
    pintar_paraula(menu->titol,i2(x,y));
    x = 5; y = 15;
    int o_inicial; int o_final;
    int llargada_xi;
    for (int o = 0; o<3; o+=1){
        if(mode == 'x'){llargada_xi = pintar_puntuacio(menu->noms[o],i2(x,y),menu->xifres[o]);}
        else{pintar_paraula(menu->noms[o],i2(x,y));}
        x=5; y+=12;
    }
    if(mode == 'x'){ps(&finestra_general, &percent, i2(59+llargada_xi,y-12));}
    pintar_paraula(menu->noms[3],i2(20,y)); pintar_paraula(menu->noms[4],i2(77,y));

    if (controller.left.pressed && controller.left.half_transition_count && op>0){op-=1;}
    if (controller.right.pressed && controller.right.half_transition_count && op<1){op+=1;}
    if(numero_de_fotograma % 20 < 10)
    {
        if(op==0){ferforma_mode(&finestra_general, i2(19,50), menu->llargades_pix[3], 12, blanc, 2);}
        else     {ferforma_mode(&finestra_general, i2(76,50), menu->llargades_pix[4], 12, blanc, 2);}
        //ferforma(finestra_general, {79+33,50}, menu->llargades_pix[4], 12, vermell);
    }
    return op;
}
