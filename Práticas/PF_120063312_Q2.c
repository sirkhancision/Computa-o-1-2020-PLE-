void media (NOTA_ALUNO *lista, int quant) {
    float med;
    int i;
    for (i=0; i < quant; i++) {
        fprintf(notas, "Aluno: ");
        fputs((lista+i)->aluno, notas);
        fprintf(notas, "\n");

        med = (((lista+i)->nota1) + ((lista+i)->nota2)) / 2;
        fprintf(notas, "Media do aluno: %.1f\n", med);

        if (med >= 5.0) fprintf(notas, "Aluno aprovado\n");
        else fprintf(notas, "Aluno reprovado\n");
    }
}