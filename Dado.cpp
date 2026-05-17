/* compatibilidade de sleep entre Windows e Unix */
#ifdef _WIN32
    #include <windows.h>
    #define pausa(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define pausa(ms) usleep((ms) * 1000)
#endif

/* bibliotecas padrão */
#include <stdio.h>  /* printf, scanf, fflush */
#include <stdlib.h> /* rand, srand           */
#include <time.h>   /* time                  */

/* códigos ANSI para o terminal */
#define RESET   "\x1b[0m"  /* volta ao estilo padrão  */
#define BOLD    "\x1b[1m"  /* texto em negrito        */
#define LIMPAR  "\x1b[2J\x1b[H" /* limpa tela e move cursor para (0,0) */

/* tempo entre frames da animação em ms — aumente para deixar mais lento */
#define DELAY_MS 180

/* retorna a cor ANSI correspondente ao valor do dado */
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

/* faces do dado em ASCII, indexadas de 1 a 6 */
const char *faces[7][5] = {
    {0},
    {"+-------+","|       |","|   *   |","|       |","+-------+"},
    {"+-------+","| *     |","|       |","|     * |","+-------+"},
    {"+-------+","| *     |","|   *   |","|     * |","+-------+"},
    {"+-------+","| *   * |","|       |","| *   * |","+-------+"},
    {"+-------+","| *   * |","|   *   |","| *   * |","+-------+"},
    {"+-------+","| *   * |","| *   * |","| *   * |","+-------+"},
};

/* imprime a face do dado com a cor ANSI do valor */
void desenhar_dado(int v) {
    const char *c = cor_dado(v);
    for (int i = 0; i < 5; i++)
        printf("  %s%s%s\n", c, faces[v][i], RESET);
}

/* exibe frames aleatórios em sequência simulando o dado girando */
void animar_dado() {
    for (int i = 0; i < 12; i++) {
        printf(LIMPAR);
        printf("  \x1b[33mRolando...\x1b[0m\n\n");
        desenhar_dado(rand() % 6 + 1);
        fflush(stdout); /* força exibição imediata antes da pausa */
        pausa(DELAY_MS);
    }
}

/* gera um número aleatório de 1 a 6 */
int rolar_dado() { return rand() % 6 + 1; }

int rolar_dado_animado()
{
    int r;

    animar_dado();

    r = rand() % 6 + 1;

    printf(LIMPAR);

    printf("Resultado: %d\n\n", r);

    desenhar_dado(r);

    return r;
}