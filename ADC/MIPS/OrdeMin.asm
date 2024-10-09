    .data
lista:  .word 5, 3, 8, 1, 9, 2  # Ejemplo de lista a ordenar
tamano: .word 6                # Tamaño de la lista
newline: .asciiz "\n"          # Para imprimir una nueva línea después de cada número

    .text
    .globl main
main:
    # Inicializamos los punteros
    la   $a0, lista            # $a0 apunta al inicio de la lista
    lw   $t1, tamano           # Cargamos el tamaño de la lista
    sll  $t1, $t1, 2           # Multiplicamos tamaño por 4 (cada elemento son 4 bytes)
    add  $a1, $a0, $t1         # $a1 apunta al final de la lista (después del último elemento)
    addi $a1, $a1, -4          # Ajustamos $a1 para que apunte al último elemento real

    # Llamamos a la rutina de ordenamiento
sort:
    beq  $a0, $a1, done        # Si solo queda un elemento, terminamos
    jal  max                   # Llamamos a la subrutina max para encontrar el valor máximo

    # Intercambiamos el valor máximo con el primer elemento de la sublista
    lw   $t0, 0($a0)           # Cargamos el primer elemento en $t0
    sw   $t0, 0($v0)           # Guardamos el primer elemento en la posición del máximo
    sw   $v1, 0($a0)           # Guardamos el máximo en la primera posición

    # Preparamos para la siguiente iteración con una lista más pequeña
    addi $a0, $a0, 4           # Mover puntero $a0 una posición hacia adelante
    j    sort                  # Repetimos el ciclo para la lista más pequeña

done:
    # Una vez ordenada la lista, imprimimos los elementos
    la   $a0, lista            # $a0 vuelve a apuntar al inicio de la lista
    lw   $t1, tamano           # Cargamos el tamaño de la lista
    jal  imprimir_lista         # Llamamos a la subrutina para imprimir la lista

    li   $v0, 10               # Llamada para terminar el programa
    syscall

# Subrutina max: encuentra el valor máximo en la sublista [$a0, $a1]
max:
    move $t2, $a0              # $t2 es el puntero que recorre la lista
    lw   $v1, 0($t2)           # Inicializamos $v1 con el primer valor (máximo provisional)
    move $v0, $t2              # Guardamos la posición del máximo provisional

max_loop:
    addi $t2, $t2, 4           # Avanzamos el puntero al siguiente elemento
    bgt  $t2, $a1, max_done    # Si llegamos al final de la sublista, terminamos

    lw   $t3, 0($t2)           # Cargamos el valor actual de la lista
    ble  $t3, $v1, max_loop    # Si no es mayor que el actual máximo, seguimos

    # Si encontramos un nuevo máximo
    move $v1, $t3              # Actualizamos el máximo
    move $v0, $t2              # Guardamos la posición del nuevo máximo
    j    max_loop              # Repetimos el ciclo

max_done:
    jr   $ra                   # Retornamos a la rutina sort

# Subrutina para imprimir la lista
imprimir_lista:
    move $t2, $a0              # Usamos $t2 para recorrer la lista
    li   $t0, 0                # Inicializamos el índice en 0

imprimir_loop:
    lw   $t3, 0($t2)           # Cargamos el valor actual de la lista

    # Imprimir valor actual
    li   $v0, 1                # Syscall para imprimir entero
    move $a0, $t3              # Mover el valor a $a0 para imprimirlo
    syscall

    # Imprimir salto de línea
    li   $v0, 4                # Syscall para imprimir string
    la   $a0, newline          # Imprimir el salto de línea
    syscall

    addi $t2, $t2, 4           # Avanzar al siguiente elemento de la lista
    addi $t0, $t0, 1           # Incrementar el índice
    lw   $t1, tamano           # Cargar el tamaño de la lista
    bge  $t0, $t1, imprimir_done  # Si hemos terminado de imprimir, salir

    j    imprimir_loop         # Repetimos el ciclo de impresión

imprimir_done:
    jr   $ra                   # Retornar al programa principal
