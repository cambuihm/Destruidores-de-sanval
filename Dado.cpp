/* dado.c — com \x1b ANSI */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RESET   "\x1b[0m"
#define BOLD    "\x1b[1m"
#define LIMPAR  "\x1b[2J\x1b[H"

const char *cor_dado(int v) {
    switch (v) {
        case 1: return "\x1b[33m"; /* amarelo  */
        case 2: return "\x1b[36m"; /* ciano    */
        case 3: return "\x1b[34m"; /* azul     */
        case 4: return "\x1b[32m"; /* verde    */
        case 5: return "\x1b[35m"; /* magenta  */
        case 6: return "\x1b[31m"; /* vermelho */
        default: return RESET;
    }
}

const char *faces[7][5] = {
    {0},
    {"+-------+","|       |","|   *   |","|       |","+-------+"},
    {"+-------+","| *     |","|       |","|     * |","+-------+"},
    {"+-------+","| *     |","|   *   |","|     * |","+-------+"},
    {"+-------+","| *   * |","|       |","| *   * |","+-------+"},
    {"+-------+","| *   * |","|   *   |","| *   * |","+-------+"},
    {"+-------+","| *   * |","| *   * |","| *   * |","+-------+"},
};

void desenhar_dado(int v) {
    const char *c = cor_dado(v);
    for (int i = 0; i < 5; i++)
        printf("  %s%s%s\n", c, faces[v][i], RESET);
}

void animar_dado() {
    int frames = 12;
    for (int i = 0; i < frames; i++) {
        printf(LIMPAR);
        printf("  \x1b[33mRolando...\x1b[0m\n\n");
        int tmp = rand() % 6 + 1;
        desenhar_dado(tmp);
        volatile long j;
        for (j = 0; j < 50000000L; j++);
    }
}

int rolar_dado() { return rand() % 6 + 1; }

int main() {
    srand((unsigned)time(NULL));
    char op = 's';

    while (op == 's' || op == 'S') {
        animar_dado();
        int r = rolar_dado();
        printf(LIMPAR);
        printf("  " BOLD "Resultado: %s%d%s\n\n" RESET,
               cor_dado(r), r, RESET);
        desenhar_dado(r);
        printf("\n  Jogar novamente? (s/n): ");
        scanf(" %c", &op);
    }

    printf("  \x1b[36mAte logo!\x1b[0m\n");
    return 0;
}