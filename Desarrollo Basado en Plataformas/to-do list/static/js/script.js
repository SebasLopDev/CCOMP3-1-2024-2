function agregarTarea() {
    let nuevaTareaTexto = document.getElementById("newTarea").value.trim();

    // Verifica vacío
    if (nuevaTareaTexto === "") {
        alert("Ingrese una tarea");
        return;
    }

    // Verifica si existe
    if (tareaDuplicada(nuevaTareaTexto)) {
        alert("La tarea ya existe en la lista.");
        return;
    }

    // Crear un nuevo elemento <li> para la tarea
    let nuevaTarea = document.createElement("li");

    // Crear un checkbox
    let checkbox = document.createElement("input");
    checkbox.type = "checkbox";
    
    // Crear un span para el texto de la tarea
    let textoTarea = document.createElement("span");
    textoTarea.textContent = " " + nuevaTareaTexto;

    // Botón de eliminar tarea
    let btnEliminar = document.createElement("button");
    btnEliminar.textContent = "Eliminar";
    btnEliminar.onclick = function() {
        eliminarTarea(nuevaTarea);
    };

    // Botón de editar tarea
    let btnEditar = document.createElement("button");
    btnEditar.textContent = "Editar";
    btnEditar.onclick = function() {
        editarTarea(textoTarea);
    };

    // Añadir el checkbox, el texto, el botón de eliminar y el botón de editar al nuevo <li>
    nuevaTarea.appendChild(checkbox);
    nuevaTarea.appendChild(textoTarea);
    nuevaTarea.appendChild(btnEliminar);
    nuevaTarea.appendChild(btnEditar);

    // Añadir la nueva tarea al <ul>
    document.getElementById("lisTareas").appendChild(nuevaTarea);

    // Limpiar el campo de entrada después de agregar la tarea
    document.getElementById("newTarea").value = "";
}

// Función para verificar si la tarea ya existe en la lista
function tareaDuplicada(nuevaTareaTexto) {
    let tareas = document.querySelectorAll("#lisTareas li span");
    for (let tarea of tareas) {
        if (tarea.textContent.trim() === nuevaTareaTexto) {
            return true; // existe
        }
    }
    return false; //no existe
}

// Función para eliminar una tarea individual
function eliminarTarea(tarea) {
    document.getElementById("lisTareas").removeChild(tarea);
}

// Función para editar el texto de una tarea
function editarTarea(textoTarea) {
    let nuevoTexto = prompt("Edita la tarea:", textoTarea.textContent.trim());
    if (nuevoTexto !== null && nuevoTexto.trim() !== "") {
        if (!tareaDuplicada(nuevoTexto.trim())) {
            textoTarea.textContent = " " + nuevoTexto;
        } else {
            alert("La tarea ya existe.");
        }
    }
}

// Función para seleccionar todas las tareas
function seleccionarTodas() {
    let checkboxes = document.querySelectorAll("#lisTareas input[type='checkbox']");
    checkboxes.forEach(checkbox => {
        checkbox.checked = true;  // Selecciona todas
    });
}

// Función para eliminar todas las tareas
function eliminarTodas() {
    let listaTareas = document.getElementById("lisTareas");

    // Elimina todas las tareas
    while (listaTareas.firstChild) {
        listaTareas.removeChild(listaTareas.firstChild);
    }
}