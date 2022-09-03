//TODO: SALVAPANTALLES(?)
//TODO: Fer que al gargalls nomes es puguin pillar les rates aixi, a distancia?
//TODO: Fer que al capicua es canvii de direccio al fer punt?

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include "samd21_platform.c"

#include "funcions/aleatorietat.h"

#include "funcions/setup.h"

#include "sprites/imatgeC.c"
#include "sprites/LletresNumeros.c"
#include "sprites/HUDsEspecials.c"
#include "sprites/Serps.c"
#include "sprites/Rates.c"

#include "funcions/funcions_motor.h"
#include "funcions/funcions_menu.h"
#include "funcions/funcions_joc.h"

#include "funcions/funcions_setup.h"

int mode_00_CLASSIC(){
    int final = 0; t = time(NULL) - segons; p.m0.puntuacio = s.length-1;
    gestionarINPUT();
    if (numero_de_fotograma % 10 == 0) {//trucs(controller, s, p);
        int m = moureSERP(); if(m == 1){final = 4;} else if(m==2){final = 5;}
        if (s.cap.x == p.m0.R.x && s.cap.y == p.m0.R.y){s.creixer = 1; ferCREIXERoDECREIXER(); crearRATA();}
    }
    if (pintarhoTOT(0) == 1){final = 3;}

    ++numero_de_fotograma;
    return final;}

#include "modes/modes_control.h"
#include "modes/modes_limits.h"
#include "modes/modes_serp.h"
#include "modes/modes_rata.h"
#include "modes/modes_grafic.h"
#include "modes/modes_objectiu.h"
#include "modes/modes_altres.h"


int main(){
    inicia_generador_aleatoris();

    int ample_finestra = 128;   int alcada_finestra = 64;
    bp = alloc_bitmap_memory(ample_finestra, alcada_finestra);
    graphics_init(ample_finestra, alcada_finestra, titol_finestra, factor_zoom);
    
    /*U32 i = 0;
    bool pin_state = true;
    while(i < 256){
        //port_pin_set_output_level(LED_0_PIN, pin_state);
        //pin_state = !pin_state;
        //delay_ms(1000/64.f);
        //
        if(port_pin_get_input_level(PIN_PA02)){
            port_pin_set_output_level(LED_0_PIN, HIGH);
        }
        else{
            port_pin_set_output_level(LED_0_PIN, LOW);
        }

        graphics_render(bp);

        bp.pixels[i] = 1;
        i = (i+1)%(128*64);

        ControllerState controller_state = get_controller_state();
    }*/

    inicialitzar_finestres();
    for (int i=0; i<240; i++){p.m6.posicionsPINTAR[i] = 'n';}
    
    inicialitzar_TOTS_menus();
    Menu menu_a_mostrar = menu_inici;
    int op = 0;
    int op_pri = 0; //principal
    int op_esp = 0; //especifica
            
    printf("\nCOMENÇO\n\n");
    while(!user_requested_exit()){
        int he_triat = 0;
        int falsa_alarma = 0;
        int mode = -1;
        while(he_triat == 0){
            /* //NOTE: visualize refresh rate using LED
              {
                port_pin_set_output_level(LED_0_PIN, pin_state);
                pin_state = !pin_state;
                //delay_ms(1000/64.f);
              } */

            controller = get_controller_state();
            op = pintar_menus(&menu_a_mostrar, op);
            if (controller.A.pressed && controller.A.half_transition_count){
                falsa_alarma = 0;
                if(menu_a_mostrar.titol == menu_inici.titol){ //Inici
                    if (op == 0){mode = 0;}
                    if(op==1){
                        menu_a_mostrar = menu_principal;
                        op = 0;
                        falsa_alarma = 1;
                    }
                }
                else if(menu_a_mostrar.titol == menu_principal.titol){
                    op_pri = op;
                         if(op==0){menu_a_mostrar = menu_control;}
                    else if(op==1){menu_a_mostrar = menu_limits;}
                    else if(op==2){menu_a_mostrar = menu_serp;}
                    else if(op==3){menu_a_mostrar = menu_rata;}
                    else if(op==4){menu_a_mostrar = menu_grafic;}
                    else if(op==5){menu_a_mostrar = menu_objectiu;}
                    else if(op==6){menu_a_mostrar = menu_altres;}
                    op = 0;
                    falsa_alarma = 1;
                }
                else if(menu_a_mostrar.titol == menu_control.titol){ //Control
                    if (op == 0){mode = 1;}
                    else if (op == 1){mode = 2;}
                    else if (op == 2){mode = 3;}
                }
                else if(menu_a_mostrar.titol == menu_limits.titol){ //Límits
                    if (op == 0){mode = 4;}
                    else if (op == 1){mode = 5;}
                    else if (op == 2){menu_a_mostrar = menu_editor; op = 0; falsa_alarma = 1;}
                }
                else if(menu_a_mostrar.titol == menu_editor.titol){ //Menu especial: Editor
                    if (op == 0){mode = 6;}
                    else if (op == 1){mode = 66;}
                }
                else if(menu_a_mostrar.titol == menu_serp.titol){ //Serp
                    if (op == 0){mode = 7;}
                    else if (op == 1){mode = 8;}
                    else if (op == 2){mode = 9;}
                    else if (op == 3){mode = 10;}
                    else if (op == 4){mode = 11;}
                    else if (op == 5){mode = 12;}
                    else if (op == 6){mode = 13;}
                }
                else if(menu_a_mostrar.titol == menu_rata.titol){ //Rata
                    if (op == 0){mode = 14;}
                    else if (op == 1){mode = 15;}
                    else if (op == 2){mode = 16;}
                }
                else if(menu_a_mostrar.titol == menu_grafic.titol){ //Gràfic
                    if (op == 0){mode = 17;}
                    else if (op == 1){mode = 18;}
                }
                else if(menu_a_mostrar.titol == menu_objectiu.titol){ //Objectiu
                    if (op == 0){mode = 19;}
                    else if (op == 1){mode = 20;}
                    else if (op == 2){mode = 21;}
                    else if (op == 3){mode = 22;}
                    else if (op == 4){mode = 23;}
                    else if (op == 5){mode = 24;}
                }
                else if(menu_a_mostrar.titol == menu_altres.titol){ //Altres
                    if (op == 0){mode = 25;}
                    else if (op == 1){falsa_alarma = 1;}
                }
                if(falsa_alarma != 1){he_triat = 1; op_esp = op;}
            }
            else if(controller.B.pressed && controller.B.half_transition_count){
                if (menu_a_mostrar.titol == menu_inici.titol){}
                else if(menu_a_mostrar.titol == menu_principal.titol){menu_a_mostrar = menu_inici; op = 1;}
                else if(menu_a_mostrar.titol == menu_editor.titol){menu_a_mostrar = menu_limits; op = 2;}
                else{menu_a_mostrar = menu_principal; op = op_pri;}
            }
            graphics_render(bp);
            ++numero_de_fotograma;
            if(user_requested_exit()){break;} // ANTIGA GUARRADA SUPREMA
        }
        
        int again = -1;
        while (again != 0){
            iniciar_modes_i_serp(mode);
            segons = time(NULL);
            int fi = 0;
            while(fi == 0)
            {   
                controller = get_controller_state();
                if (controller.start.half_transition_count && controller.start.pressed){
                    if (p.m0.pausat == 0){p.m0.pausat = 1; indexA = 0; indexB = -2;}
                    else{p.m0.pausat = 0; segons += t_pausa;}
                }
                if(p.m0.pausat == 0){
                    if(mode == 0){     fi = mode_00_CLASSIC();}
                    else if(mode == 1){fi = mode_01_INVERTIT();}
                    else if(mode == 2){fi = mode_02_EGO();}
                    else if(mode == 3){fi = mode_03_ESTRATEGIC();}
                    else if(mode == 4){fi = mode_04_VORES();}
                    else if(mode == 5){fi = mode_05_FANTASMA();}
                    else if(mode == 6){     mode_06_PINTAR();} 
                    else if(mode == 66){fi= mode_66_BARRERES();}
                    else if(mode == 7){fi = mode_07_REGULABLE();}
                    else if(mode == 8){fi = mode_08_MANUAL();}
                    else if(mode == 9){fi = mode_09_INCRE();}
                    else if(mode == 10){fi = mode_10_CAPICUA();}
                    else if(mode == 11){fi = mode_11_REMOT();}
                    else if(mode == 12){fi = mode_12_DIAGONAL();}
                    else if(mode == 13){fi = mode_13_SMOOTH();}
                    else if(mode == 14){fi = mode_14_PLUS();}
                    else if(mode == 15){fi = mode_15_DIRECCIONALS();}
                    else if(mode == 16){fi = mode_16_RATESMOBILS();}
                    else if(mode == 17){fi = mode_17_SURVIVAL();}
                    else if(mode == 18){fi = mode_18_GALLINETA();}
                    else if(mode == 19){fi = mode_19_EASY();}
                    else if(mode == 20){fi = mode_20_SelNat();}
                    else if(mode == 21){fi = mode_21_BASQUET();}
                    else if(mode == 22){fi = mode_22_LOOPS();}
                    else if(mode == 23){fi = mode_23_1D();}
                    else if(mode == 24){fi = mode_24_IA();}
                    else if(mode == 25){fi = mode_25_RETRO();}
                    else{fi = 7;}
                }
                else{
                    t_pausa = time(NULL) - segons - t;
                    pintarhoTOT(mode);
                    for(int i = 0; i<5; i++){
                        if (i==indexA){ps(&finestra_joc, lletresPAUSA+i, i2(posicionsPAUSA[i].x, posicionsPAUSA[i].y+2));}
                        else if (i==indexB){ps(&finestra_joc, lletresPAUSA+i, i2(posicionsPAUSA[i].x, posicionsPAUSA[i].y-2));}
                        else{ps(&finestra_joc, lletresPAUSA+i, posicionsPAUSA[i]);}
                    }                    
                    if(numero_de_fotograma % 10 == 0){
                        if (indexB < 5){indexA+=1; indexB = indexA-2;}
                        else{indexA=0; indexB = -2;}
                    }
                    ++numero_de_fotograma;
                    if(controller.B.pressed){fi = 1;}
                }
                if(user_requested_exit()){break;}  // ANTIGA GUARRADA SUPREMA
                graphics_render(bp);
            }
            
            if(fi == 1){printf("M'he pirat de la pausa");}
            //else if(fi == 2){printf("He clicat la creueta");}
            else if(fi == 3){printf("Màxima puntuació!(kindof)");}
            else if(fi == 4){printf("Estic fora del ring");}
            else if(fi == 5){printf("He xocat amb mi mateix");}
            //else if(fi == 6){printf("El temps s'ha acabat");}
            else if(fi == 7){printf("No me'l sé aquest mode");}
            else if(fi == 8){printf("Mort específica del mode");}
            else{printf("Que parezca un accidente");}
              
            printf(" i per tant\n\nACABO\n");
            if (mode == 6){
                printf("Has modificat %i caselles i n'has deixat %i sense tocar\n",p.m6.parets+p.m6.NORATAs, 240-p.m6.parets-p.m6.NORATAs);
                printf("TEMPS: %li segons\n",t);
                printf("mod/reg: %f percent\n",((p.m6.parets+p.m6.NORATAs)/(float)240)*100);
                printf("FOTO: %i fotogrames\n\n",numero_de_fotograma);
            }
            else if (mode == 19){
                printf("PUNTUACIÓ: T'han faltat %i caselles -> tens %i punts de 1200 possibles\n",240-s.length, (s.length)*5);
                printf("TEMPS: %li segons\n",t);
                printf("full/total: %f percent\n",(s.length/(float)240)*100);
                printf("FOTO: %i fotogrames\n\n",numero_de_fotograma);
            }
            else{
                printf("PUNTUACIÓ: %i rates -> %i punts\n",p.m0.puntuacio, p.m0.puntuacio*5);
                printf("TEMPS: %li segons\n",t);
                printf("PUNTUACIO/TEMPS: %f percent\n",(p.m0.puntuacio/(float)t)*100);
                printf("FOTO: %i fotogrames\n\n",numero_de_fotograma);
            }
            
            if(mode == 66 && p.m6.acabemdecomencar==2){ //GUARRADA NECESSARIA PEL FLAIX 66
                ferforma(&finestra_general,i2(0,0),128,64,blanc);
                for(int i = 0; i<10; i++){
                    ++numero_de_fotograma;
                    graphics_render(bp);
                }
            }
            
            int num;
                 if(mode == 9 && 10000/p.m9.increment<5){num = 10000/p.m9.increment;}
            else if(mode == 13){num = 1;}
            else if(mode == 19){num = 2;}
            else if(mode == 25){num = 3;}
            else if(mode == 23){num = 4;}
            else{num = 5;}
            fi = 0;
            while(fi == 0)
            {
                if(numero_de_fotograma % num == 0){
                    pintarhoTOT(mode);
                    if(mode == 66 && p.m6.acabemdecomencar==2){ferforma(&finestra_general,i2(0,0),128,64,blanc);}
                    else if(mode == 17){pintarhoTOT(177);}
                    fi = moureSERP_FINAL();
                }
                if (mode == 18){pintarhoTOT(mode);}
                ++numero_de_fotograma;
                graphics_render(bp);
                controller = get_controller_state();
                if((controller.A.pressed && controller.A.half_transition_count)||
                   (controller.B.pressed && controller.B.half_transition_count)||
                   (controller.start.pressed && controller.start.half_transition_count)){fi = 1;}
                if(user_requested_exit()){break;} // ANTIGA GUARRADA SUPREMA
            }
            
            Menu menu_resultats = {
            .titol = "results",
            .opcions = 5,
            };
            char* noms_resultats[5];
            int xifres_resultats[3];
            if(mode == 6){
                noms_resultats[0]="mod:"; noms_resultats[1]="reg:"; noms_resultats[2]="div:";
                noms_resultats[3]="play"; noms_resultats[4]="exit";
                xifres_resultats[0]=p.m6.parets+p.m6.NORATAs; xifres_resultats[1]=240-xifres_resultats[0];
                xifres_resultats[2]=(xifres_resultats[0]/(float)240)*100;
            }
            else if(mode == 66 && p.m6.acabemdecomencar==2){
                noms_resultats[0]="invalid"; noms_resultats[1]="starting"; noms_resultats[2]="position";
                noms_resultats[3]="edit"; noms_resultats[4]="exit";
            }
            else if(mode == 19){
                noms_resultats[0]="full:"; noms_resultats[1]="empty:"; noms_resultats[2]="div:";
                noms_resultats[3]="again"; noms_resultats[4]="exit";
                xifres_resultats[0]=s.length; xifres_resultats[1]=p.m0.puntuacio; xifres_resultats[2]=(s.length/(float)240)*100;
            }
            else{
                noms_resultats[0]="rats:"; noms_resultats[1]="time:"; noms_resultats[2]="div:";
                noms_resultats[3]="again"; noms_resultats[4]="exit";
                xifres_resultats[0]=p.m0.puntuacio; xifres_resultats[1]=(int)t;
                if(t != 0){xifres_resultats[2]=(p.m0.puntuacio/(float)t)*100;} else{xifres_resultats[2]=0;}
            }
            
            inicialitzar_menu(&menu_resultats, noms_resultats, xifres_resultats, 'x');
            op = 0;
            he_triat = 0;
            while(he_triat == 0){
                controller = get_controller_state();
                if(mode != 66 || p.m6.acabemdecomencar!=2){op = pintar_menu_XIFRES(&menu_resultats, op, 'x');}
                else{op = pintar_menu_XIFRES(&menu_resultats, op, 'o');}
                
                if (controller.A.pressed && controller.A.half_transition_count){
                    if(op==0){again = 1; he_triat = 1; 
                              if(mode == 6){mode = 66; op_esp = 1;}
                              else if(mode == 66 && p.m6.acabemdecomencar==2){mode = 6; op_esp = 0;}
                    }
                    else if(op==1){again = 0; he_triat = 1;}}
                graphics_render(bp);
                ++numero_de_fotograma;
                if(user_requested_exit()){break;} // ANTIGA GUARRADA SUPREMA
            }
            op = op_esp;

            if(user_requested_exit()){break;}
        }
    }

    graphics_end();
    return 0;
}
