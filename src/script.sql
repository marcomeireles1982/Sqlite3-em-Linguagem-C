CREATE TABLE IF NOT EXISTS materiais (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    type VARCHAR(15),
    descricao VARCHAR(20),
    name VARCHAR(12),
    d_tecn VARCHAR(15),
    quant INTEGER,
    endereco VARCHAR(10)
);

INSERT INTO materiais (type, descricao, name, d_tecn, quant, endereco)
VALUES ('metal', 'parafuso', 'M6', 'inox', 100, 'A1');

INSERT INTO materiais (type, descricao, name, d_tecn, quant, endereco)
VALUES ('plastico', 'tubo', 'PVC', '25mm', 50, 'B2');