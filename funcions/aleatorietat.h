void inicia_generador_aleatoris(){
    time_t t;
    srand((unsigned) time(&t));
}

int aleat(int min, int max){
    int rang = max-min + 1;
    int r = (rand() % rang) + min;
    return r;
}       // TODO: Change to xorshift? https://en.wikipedia.org/wiki/Xorshift
