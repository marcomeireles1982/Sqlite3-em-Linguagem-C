#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

int main() {
    sqlite3 *db;
    char *err_msg = 0;

    if (sqlite3_open("meubanco.db", &db) != SQLITE_OK) {
        return 1;
    }

    // Abre o arquivo .sql
    FILE *f = fopen("script.sql", "rb");
    if (!f) return 1;

    fseek(f, 0, SEEK_END);
    long tamanho = ftell(f);
    rewind(f);

    char *sql = malloc(tamanho + 1);
    fread(sql, 1, tamanho, f);
    sql[tamanho] = '\0';
    fclose(f);

    // Executa o conteúdo do arquivo
    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "Erro SQL: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    free(sql);
    sqlite3_close(db);
    return 0;
}

// gcc main.c sqlite3.c -o main.exe