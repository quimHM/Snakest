unsigned char SNAKEST_data[] = 
  "\x96\x59\x65\xAA\x5A\xAA\x96\xA9\x65\x96\x5A\xA5\xAA\xAA\xAA\x96\x59\x6A\x96\x59\x65\xAA\x59\x65\x96\x65\x96\x59\x69\x96\xAA\x65\xA6\x59\x65\x96\x99\x6A\xA5\xAA\x65\x96\x5A\x65\x96\x59\x69\x96\x59\x65\x59\x65\x96\x69\x66\xAA\x59\xA5\x96\x59\x66\x96\x6A\x99\x6A\x59\x65\x9A\x59\x65\x96\x69\x65\x96\x59\x96\x59\x65\xAA\x59\x6A\x96\xA9\x65\x96\x5A\xA5\xAA\x56\x6A\x96\x59\x6A\x96\x59\x65\xAA\x59\x65\x96\x65\xAA\xAA\xA9\x96\x5A\x65\xA6\x5A\xA9\x96\x99\x69\x95\xAA\x65\xAA\xAA\x65\xAA\xAA\xAA\xAA\x59\xAA\x59\xAA\xAA\xA9\x65\x9A\x59\xA5\x9A\xA9\x66\x96\x69\x66\xAA\x59\xAA\xAA\x59\xAA\xAA\xAA\xAA\x96\xAA\x96\x59\x65\xAA\x59\x65\x96\xA9\x65\x96\x5A\xA5\x96\x5A\xAA\x96\x59\x6A\x96\x59\x65\xAA\xAA\x65\xAA\x65\x96\x59\x69\x96\x99\x65\xA6\x59\x65\x96\x99\x65\xAA\xAA\x65\x96\x5A\x65\x96\x59\x6A\xAA\x59\xAA\x59\x65\x96\x69\x66\x96\x59\xA5\x96\x59\x66\x96\x59\xAA\xAA\x59\x65\x9A\x59\x65\x96\x6A\xAA\x96\xAA\x96\x59\x65\xAA\x5A\xA5\x96\xA9\x65\x96\x5A\xA5\x96\x5A\xAA\x96\x59\x6A\x96\x59\x65\xAA\xAA\x65\xAA\xAA\xAA\x99\x69\x96\xAA\x65\xA6\x5A\xA9\x96\x99\x69\x96\xAA\x65\xAA\xAA\xAA\xAA\x99\x6A\xAA\x59\xAA\xAA\xAA\x96\x69\x66\xAA\x59\xA5\x9A\xA9\x66\x96\x69\x65\xAA\x59\xAA\xAA\xAA\xAA\x96\x6A\xAA\x96\xAA\x96\x59\x65\xAA\x5A\xAA\x96\xA9\x6A\xAA\x5A\xA5\xAA\x59\x6A\x96\x59\x6A\x96\x59\x65\xAA\xAA\x65\xAA\x65\x96\x59\x69\x96\xAA\x65\xA6\x5A\xA9\x96\x99\x6A\x96\x5A\x65\x96\x5A\x65\x96\x59\x6A\xAA\x59\xAA\x59\x65\x96\x69\x66\xAA\x59\xA5\x9A\xA9\x66\x96\x6A\xA5\x9A\x59\x65\x9A\x59\x65\x96\x6A\xAA\x55\xAA\x96\x59\x65\xAA\x5A\xAA\x96\xA9\x6A\xAA\x5A\xA5\xAA\xA9\x6A\x96\x59\x6A\x96\x59\x65\xAA\xAA\x96\xAA" ;
imatgeC SNAKEST = {
  100, 16, SNAKEST_data
};

unsigned char pausa_P_data[] = 
  "\x80\x0\x2\xA8\x14\x51\x42\xA1\x14\x51\x4A\x85\x14\x51\x2\x5\x14\x51\x40\x45\x0\x11\x41\x44\x0\x51\x1\x45\x14\x50\x11\x45\x14\x50\x51\x45\x14\x40\x51\x45\x14\x4\x50\x0\x2\x14\x4A\xAA\xA8\x14\x2A\xAA\xA1\x14\xAA\xAA\x85\x12\xAA\xAA\x5\xA\xAA\xAA\x0\xAA\xAA\xA0";
imatgeC pausa_P = {
  15, 18, pausa_P_data
};

unsigned char pausa_A_data[] = 
  "\x80\x0\x0\x8\x14\x51\x45\x1\x14\x51\x45\x5\x14\x51\x44\x5\x14\x51\x40\x45\x0\x11\x41\x44\x0\x51\x1\x45\x14\x50\x11\x45\x14\x50\x51\x45\x14\x40\x51\x45\x14\x4\x50\x1\x14\x14\x4A\x85\x10\x14\x2A\x5\x1\x14\xA8\x45\x5\x12\xA1\x44\x5\xA\x81\x42\x0\xAA\x80\x20";
imatgeC pausa_A = {
  15, 18, pausa_A_data
};

unsigned char pausa_U_data[] = 
  "\x80\x2A\xA0\x8\x14\x2A\x5\x1\x14\xA8\x45\x5\x12\xA1\x44\x5\xA\x81\x40\x45\x2A\x11\x41\x44\xA8\x51\x1\x42\xA0\x50\x11\x4A\x84\x50\x51\x2A\x14\x40\x50\xA8\x14\x4\x52\xA1\x14\x14\x40\x5\x10\x14\x51\x45\x1\x14\x51\x45\x5\x14\x51\x44\x5\x14\x51\x42\x0\x0\x0\x20";
imatgeC pausa_U = {
  15, 18, pausa_U_data
};

unsigned char pausa_S_data[] = 
  "\x80\x0\x0\x8\x14\x51\x45\x1\x14\x51\x45\x5\x14\x51\x44\x5\x14\x51\x40\x45\x0\x0\x21\x44\x0\x0\x81\x45\x14\x50\x11\x45\x14\x50\x51\x45\x14\x40\x51\x45\x14\x20\x0\x1\x14\x80\x0\x5\x10\x14\x51\x45\x1\x14\x51\x45\x5\x14\x51\x44\x5\x14\x51\x42\x0\x0\x0\x20";
imatgeC pausa_S = {
  15, 18, pausa_S_data
};

unsigned char pausa_E_data[] = 
  "\x80\x0\x0\x8\x14\x51\x45\x1\x14\x51\x45\x5\x14\x51\x44\x5\x14\x51\x40\x45\x0\x0\x21\x44\x0\x0\x81\x45\x14\x50\x11\x45\x14\x50\x51\x45\x14\x40\x51\x45\x14\x4\x50\x0\x2\x14\x40\x0\x8\x14\x51\x45\x1\x14\x51\x45\x5\x14\x51\x44\x5\x14\x51\x42\x0\x0\x0\x20";
imatgeC pausa_E = {
  15, 18, pausa_E_data
};

imatgeC lletresPAUSA[] = {
      {15, 18, pausa_P_data},
      {15, 18, pausa_A_data},
      {15, 18, pausa_U_data},
      {15, 18, pausa_S_data},
      {15, 18, pausa_E_data},
};
I2 posicionsPAUSA[] = {{28,24},{43,24},{58,24},{73,24},{88,24}};
int indexA; int indexB;

unsigned char mira_data[] = 
  "\x59\x5A\x9A\xA9\xA9\x59\x40";
imatgeC mira = {
  5, 5, mira_data
};

unsigned char creuA_data[] = 
  "\xAA\xA6\x6A\x6A\x66\xAA\x80";
imatgeC creuA = {
  5, 5, creuA_data
};

unsigned char creuB_data[] = 
  "\xAA\xAA\xAA\x6A\xAA\xAA\x80";
imatgeC creuB = {
  5, 5, creuB_data
};

unsigned char creuC_data[] = 
  "\xAA\xA9\xA9\x9A\x9A\xAA\x80";
imatgeC creuC = {
  5, 5, creuC_data
};

unsigned char cercle_data[] = 
  "\x15\x15\x55\x55\x55\x15\x0";
imatgeC cercle = {
  5, 5, cercle_data
};

unsigned char cercleNEG_data[] = 
  "\x6A\x6A\xAA\xAA\xAA\x6A\x40";
imatgeC cercleNEG = {
  5, 5, cercleNEG_data
};

unsigned char Nord_data[] = 
  "\x4\x5\x44\x44\x10\x4\x0";
imatgeC Nord = {
  5, 5, Nord_data
};

unsigned char Sud_data[] = 
  "\x4\x1\x4\x44\x54\x4\x0";
imatgeC Sud = {
  5, 5, Sud_data
};

unsigned char Est_data[] = 
  "\x4\x0\x45\x54\x4\x4\x0";
imatgeC Est = {
  5, 5, Est_data
};

unsigned char Oest_data[] = 
  "\x4\x4\x5\x54\x40\x4\x0";
imatgeC Oest = {
  5, 5, Oest_data
};

unsigned char focus_data[] = 
  "\x55\x55\xAA\xAA\x95\x55\x55\x56\xAA\xAA\xAA\x55\x55\x5A\xAA\xAA\xAA\xA9\x55\x5A\xAA\xAA\xAA\xAA\x95\x5A\xAA\xAA\xAA\xAA\xA9\x56\xAA\xAA\xAA\xAA\xAA\x56\xAA\xAA\xAA\xAA\xAA\xA5\xAA\xAA\xAA\xAA\xAA\xA9\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\x9A\xAA\xAA\xAA\xAA\xAA\x96\xAA\xAA\xAA\xAA\xAA\xA5\x6A\xAA\xAA\xAA\xAA\xA5\x5A\xAA\xAA\xAA\xAA\xA9\x55\xAA\xAA\xAA\xAA\xA9\x55\x5A\xAA\xAA\xAA\xA9\x55\x55\x6A\xAA\xAA\xA5\x55\x55\x55\xAA\xAA\x95\x55\x40";
imatgeC focus = {
  25, 25, focus_data
};

unsigned char cau_data[] = 
  "\x15\x15\x55\x55\x55\x15\x0";
imatgeC cau = {
  5, 5, cau_data
};
