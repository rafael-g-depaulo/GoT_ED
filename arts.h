/**
 * @file arts.h
 * @author Luthiery C. Cavalcante
 * @date 03/12/17
 * 
 * @brief Implementação das mensagens bonitinhas que o usuário recebe no jogo.
 */

#ifndef _ARTES__H_
#define _ARTES__H_

#include <stdio.h>

/**
 * @brief imprime a arte do menu
 * 
 * printf simples que introduz o player ao jogo
 */
void print_ArtMenu();

/**
 * @brief imprime a arte de vitória
 * 
 * printf simples que mostra que o player venceu
 */
void print_ArtWin();

/**
 * @brief imprime a arte de derrota
 * 
 * printf simples que mostra que o player perdeu
 */
void print_ArtLose();

#endif /* _ARTES__H_ */