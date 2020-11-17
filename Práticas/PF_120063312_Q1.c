void rep_char (char string[]) {
    int i, j;
    int vezes = 0;
    short int cond = 0;

    for (i=0; (string[i] != '\0'); i++) {
        for (j=0; (string[j] != '\0'); j++) {
            if ((string[j] >= 'A' && string[j] <= 'Z') || 
            (string[j] >= 'a' && string[j] <= 'z') || string[j] == ' ') {
                cond = 1;
                vezes++;
            }
            
            else if ((string[j] >= '0' && string[j] <= '9') && cond != 1)
                vezes++;
        }

        printf("%c - %d\n", string[i], vezes);
        cond = 0;
    }
}