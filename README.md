# SQLite Executor em C

Este projeto demonstra como utilizar a biblioteca **SQLite3** em C para abrir um banco de dados, carregar um script SQL de um arquivo externo e executá-lo.

## 📂 Estrutura do Projeto

- `main.c` → Código principal em C que abre o banco e executa o script.
- `sqlite3.c` / `sqlite3.h` → Arquivos da biblioteca SQLite3 (devem estar disponíveis no projeto ou instalados no sistema).
- `script.sql` → Arquivo contendo comandos SQL a serem executados.
- `meubanco.db` → Banco de dados SQLite criado/aberto pelo programa.

## 🔧 Funcionamento do Código

### Passo a passo:

1. **Inclusão de bibliotecas**
   ```c
   #include <stdio.h>
   #include <stdlib.h>
   #include "sqlite3.h"


stdio.h e stdlib.h → Funções básicas de entrada/saída e manipulação de memória.

sqlite3.h → Cabeçalho da biblioteca SQLite.

Abertura do banco de dados

c
sqlite3 *db;
if (sqlite3_open("meubanco.db", &db) != SQLITE_OK) {
    return 1;
}

## Abertura do banco de dados

c
sqlite3 *db;
if (sqlite3_open("meubanco.db", &db) != SQLITE_OK) {
    return 1;
}

## Cria/abre o arquivo meubanco.db.

Se não conseguir abrir, retorna erro.

Leitura do arquivo SQL

FILE *f = fopen("script.sql", "rb");
fseek(f, 0, SEEK_END);
long tamanho = ftell(f);
rewind(f);

char *sql = malloc(tamanho + 1);
fread(sql, 1, tamanho, f);
sql[tamanho] = '\0';
fclose(f);

Abre script.sql.

Lê todo o conteúdo para a memória.

Garante que a string termine com \0.

## Execução do script SQL

char *err_msg = 0;
if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
    fprintf(stderr, "Erro SQL: %s\n", err_msg);
    sqlite3_free(err_msg);
}

Executa os comandos SQL contidos no arquivo.

Caso haja erro, imprime a mensagem.

Finalização

free(sql);
sqlite3_close(db);
return 0;

Libera memória alocada.

Fecha o banco de dados.

## ⚙️ Compilação
Para compilar o programa no Windows usando GCC (MinGW):

## bash
gcc main.c sqlite3.c -o main.exe
No Linux (com SQLite3 instalado via pacote):

bash
gcc main.c -lsqlite3 -o main

▶️ Execução

Crie um arquivo script.sql com comandos SQL, por exemplo:

sql
CREATE TABLE IF NOT EXISTS usuarios (
    id INTEGER PRIMARY KEY,
    nome TEXT NOT NULL,
    idade INTEGER
);

INSERT INTO usuarios (nome, idade) VALUES ('Marco', 30);
INSERT INTO usuarios (nome, idade) VALUES ('Ana', 25);
Execute o programa:

## bash
./main.exe
O banco meubanco.db será criado/atualizado com os comandos do script.sql.

## ✅ Resultado Esperado
Após rodar o programa, o banco meubanco.db conterá a tabela usuarios com os registros inseridos.

Você pode verificar com o cliente SQLite:

bash
sqlite3 meubanco.db
sqlite> SELECT * FROM usuarios;
Saída:

Código
1|Marco|30
2|Ana|25


📂 Estrutura
Código
/src
   main.c
   sqlite3.c
   sqlite3.h
   script.sql
test.bat

