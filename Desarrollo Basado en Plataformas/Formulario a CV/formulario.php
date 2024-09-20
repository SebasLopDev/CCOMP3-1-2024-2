<!DOCTYPE html>
<html>
<head>
  <title>Formulario Completo</title>
  <style>
    
    body {
     
      background-color: #f4f4f9;
      color: #333;
      margin: 0;
      padding: 0;
    }

    h1 {
      font-size: 36px;
      color: #c6cfd8;
    }

    .container {
      display: flex;
      justify-content: center;
      align-items: center;
      flex-direction: column;
      margin: 32px auto;
      width: 50%;      
      background-color: #ffffff;      
      border-radius: 15px;
    }

    .container-up {
      text-align: center;
      background-color: #2c3e50;
      padding: 32px 48px;
      border-radius: 10px;
      color: #ffffff;
      width: 90%;
      margin: 0;
    }

    .container-dowm {
      width: 90%;
      padding: 2rem 3rem;
      background-color: #edeff0;      
    }

    .container-input {
      margin-bottom: 1px;
      width: 100%;
    }

    .container-input > input,
    select,
    textarea {
      padding: 10px;
      border: 1px solid #acaaaa;
      border-radius: 10px;
      width: 100%;
      font-size: 1rem;
      background-color: #faf4f4;
      margin-top: 0.5rem;
      
    }    

    label {
      color: #303942;      
      margin-bottom: 5px;
      display: inline-block;
      
    }

    .btn {
      padding: 10px 20px;
      border-radius: 15px;
      background-color: #3498db;
      color: #ffffff;
    
      
      
    }

    

    select {
      padding: 0.8rem;      
    }   
    

    textarea {
      width: 100%;      
      height: 100px;
    }

    
    
  </style>
  
</head>
<body>
    <div class="container">
      <div class="container-up">
        <h1>Modificar CV</h1>

      </div>

      <div class="container-dowm">

          <form method="post" action="curriculum.php">

            <!-- Nombre y Apellidos -->
             <div class="container-input">
               <label for="nombre">Nombre y Apellidos:</label>
               <input type="text" id="nombre" name="nombre"><br><br>
           

             </div>
            <!-- Fecha de Nacimiento -->
             <div class="container-input">

               <label for="fecha_nacimiento">Fecha de Nacimiento:</label>
               <input type="date" id="fecha_nacimiento" name="fecha_nacimiento" required><br><br>
             </div>
        
            <!-- Ocupación -->
             <div class="container-input">

               <label for="ocupacion">Ocupación:</label>
               <input type="text" id="ocupacion" name="ocupacion" required><br><br>
             </div>
        
            <!-- Contacto 
            <label for="contacto">Contacto:</label><br>-->
            <div class="container-input">

              <label for="contacto">Teléfono:</label>
              <input type="tel" id="contacto" name="telefono" required><br><br>
              <label for="contacto">Email:</label>
              <input type="email" id="contacto" name="email" required><br><br>
            </div>
        
            <!-- Nacionalidad(select option) -->
             <div class="container-input">

               <label for="nacionalidad">Nacionalidad:</label>
               <select class="btn" id="nacionalidad" name="nacionalidad" required>
                 <option value="Perú">Perú</option>
                 <option value="España">España</option>
                 <option value="EE.UU">Estados Unidos</option>
                 <option value="Argentina">Argentina</option>                 
               </select><br><br>
             </div>
        
            <!-- inglés(select radio) -->
             <div>

               <label for="basico">Nivel de Inglés:</label><br>
               <input type="radio" id="basico" name="ingles" value="Básico">
               <label for="basico">Básico</label><br>
               <input type="radio" id="intermedio" name="ingles" value="Intermedio">
               <label for="intermedio">Intermedio</label><br>
               <input type="radio" id="avanzado" name="ingles" value="Avanzado">
               <label for="avanzado">Avanzado</label><br>
               <input type="radio" id="fluido" name="ingles" value="Fluido">
               <label for="fluido">Fluido</label><br><br>
             </div>
        
            <!-- Lenguajes(select multiple) -->
             <div>

               <label for="lenguajes">Lenguajes de Programación:</label><br><br>
               <select id="lenguajes" name="lenguajes[]" multiple required>
                 <option value="Python">Python</option>
                 <option value="Java">Java</option>
                 <option value="C++">C++</option>
                 <option value="PHP">PHP</option>
                 <option value="Javascript">JavaScript</option>
               </select><br><br>
             </div>
        
            <!-- Aptitudes(datalist) -->
             <div class="container-input">
             <label for="aptitudes">Aptitud 1:</label>
               <input list="aptitudes-list" id="aptitudes" name="aptitudes[]">
               <datalist id="aptitudes-list">
                 <option value="Liderazgo">
                 <option value="Trabajo en equipo">
                 <option value="Comunicación">
                 <option value="Resolución de problemas">
               </datalist><br><br>
               <label for="aptitudes">Aptitud 2:</label>
               <input list="aptitudes-list" id="aptitudes" name="aptitudes[]">
               <datalist id="aptitudes-list">
                 <option value="Liderazgo">
                 <option value="Trabajo en equipo">
                 <option value="Comunicación">
                 <option value="Resolución de problemas">
               </datalist><br><br>
               <label for="aptitudes">Aptitud 3:</label>
               <input list="aptitudes-list" id="aptitudes" name="aptitudes[]">
               <datalist id="aptitudes-list">
                 <option value="Liderazgo">
                 <option value="Trabajo en equipo">
                 <option value="Comunicación">
                 <option value="Resolución de problemas">
               </datalist><br><br>

             </div>
        
            <!-- Habilidades(checkbox) -->
            <label>Habilidades:</label><br>
            <input type="checkbox" id="html" name="habilidades[]" value="Html">
            <label for="html">HTML</label><br>
            <input type="checkbox" id="css" name="habilidades[]" value="Css">
            <label for="css">CSS</label><br>
            <input type="checkbox" id="javascript" name="habilidades[]" value="Javascript">
            <label for="javascript">JavaScript</label><br><br>
        
            <!-- Perfil(textarea) -->
            <label for="perfil">Perfil:</label><br>
            <textarea id="perfil" name="perfil" rows="5" cols="40" required></textarea><br>
        
            <!--Enviar -->
            <input class="btn" type="submit" value="Enviar">
        
          </form>
          
      </div>
      
    </div>

</body>
</html>
