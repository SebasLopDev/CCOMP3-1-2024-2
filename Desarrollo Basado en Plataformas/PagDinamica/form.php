<?php
// Conexión a la base de datos
$servername = "localhost";
$username = "root";
$password = ""; 
$dbname = "Cv_database";

//conexión
$conn = new mysqli($servername, $username, $password, $dbname);

// Verificar conexión
if ($conn->connect_error) {
    die("Error de conexión: " . $conn->connect_error);
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    
    $nombre = $conn->real_escape_string($_POST['nombre']);    
    $email = $conn->real_escape_string($_POST['email']);
    
    // Verificar si el correo
    $checkEmail = "SELECT * FROM usuarios WHERE email = '$email'";
    $result = $conn->query($checkEmail);

    if ($result->num_rows > 0) {
        // El correo ya está en uso            
        echo "<script>alert('El correo ingresado ya está registrado. Por favor, ingresa uno diferente');</script>";
    } else {
        // Insertar
        $sql = "INSERT INTO usuarios (nombre, email) VALUES ('$nombre','$email')";
        
        if ($conn->query($sql) === TRUE) {
            $usuario_id = $conn->insert_id; // Obtener el ID del usuario

            // Datos dinámicos
            $puestos = isset($_POST['puesto']) ? $_POST['puesto'] : [];
            $empresas = isset($_POST['empresa']) ? $_POST['empresa'] : [];
            $idiomas = isset($_POST['idioma']) ? $_POST['idioma'] : [];
            $niveles = isset($_POST['nivel']) ? $_POST['nivel'] : [];
            $aptitudes = isset($_POST['aptitudes']) ? $_POST['aptitudes'] : [];

            // Procesar experiencia laboral
            foreach ($puestos as $index => $puesto) {
                $empresa = $conn->real_escape_string($empresas[$index]);
                $puesto = $conn->real_escape_string($puesto);
                $sql = "INSERT INTO experiencia (usuario_id, puesto, empresa) VALUES ('$usuario_id', '$puesto', '$empresa')";
                $conn->query($sql);
            }

            // Procesar cada idioma
            foreach ($idiomas as $index => $idioma) {
                $nivel = $conn->real_escape_string($niveles[$index]);
                $idioma = $conn->real_escape_string($idioma);
                $sql = "INSERT INTO idiomas (usuario_id, idioma, nivel) VALUES ('$usuario_id', '$idioma', '$nivel')";
                $conn->query($sql);
            }

            // Procesar cada aptitud
            foreach ($aptitudes as $aptitud) {
                $aptitud = $conn->real_escape_string($aptitud);
                $sql = "INSERT INTO aptitudes (usuario_id, aptitud) VALUES ('$usuario_id', '$aptitud')";
                $conn->query($sql);
            }

            echo "<script>alert('Datos guardados correctamente.');</script>";
        } else {
            echo "<script>alert('Error: " . $conn->error . "');</script>";
        }
    }
}

$conn->close();
?>
