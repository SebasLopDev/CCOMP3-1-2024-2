CREATE TABLE usuarios (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100),    
    email VARCHAR(100)
    
);

CREATE TABLE experiencia (
    id INT AUTO_INCREMENT PRIMARY KEY,
    usuario_id INT,
    puesto VARCHAR(100),
    empresa VARCHAR(100),
    FOREIGN KEY (usuario_id) REFERENCES usuarios(id)
);

CREATE TABLE idiomas (
    id INT AUTO_INCREMENT PRIMARY KEY,
    usuario_id INT,
    idioma VARCHAR(50),
    nivel VARCHAR(50),
    FOREIGN KEY (usuario_id) REFERENCES usuarios(id)
);

CREATE TABLE aptitudes (
    id INT AUTO_INCREMENT PRIMARY KEY,
    usuario_id INT,
    aptitud VARCHAR(100),
    FOREIGN KEY (usuario_id) REFERENCES usuarios(id)
);
