cmake_minimum_required(VERSION 3.10)

project(JogoDamas C)

# Adiciona os arquivos fonte ao executável
add_executable(jogo_damas main.c tabuleiro.c peca.c)

# Define a versão do C
set_property(TARGET jogo_damas PROPERTY C_STANDARD 11)
