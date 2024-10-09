.data
    prompt_degree:    .asciiz "Ingrese el grado del polinomio: "
    prompt_coeff:     .asciiz "Ingrese el coeficiente a%d: "
    prompt_x:         .asciiz "Ingrese el valor de x (float): "
    result_msg:       .asciiz "El resultado de P(x) es: "
    zero_float:       .float 0.0  # Valor inicial para P(x)
    one_float:        .float 1.0  # Valor inicial para x^0

.text
main:
    # Pedir el grado del polinomio
    li $v0, 4                     # syscall para imprimir string
    la $a0, prompt_degree         # cargar dirección del mensaje
    syscall

    li $v0, 5                     # syscall para leer entero
    syscall
    move $t0, $v0                 # grado del polinomio (n)

    # Reservar memoria para coeficientes (n + 1) enteros
    addi $t1, $t0, 1              # t1 = n + 1
    sll $t1, $t1, 2               # t1 = (n + 1) * 4 (bytes)
    li $v0, 9                     # syscall para reservar memoria
    move $a0, $t1                 # tamaño en bytes
    syscall
    move $t2, $v0                 # dirección de los coeficientes

    # Ciclo para ingresar los coeficientes
    li $t3, 0                     # índice del coeficiente

input_coeff:
    bge $t3, $t0, input_x        # si t3 >= n, salir del bucle

    # Pedir coeficiente
    li $v0, 4                     # syscall para imprimir string
    la $a0, prompt_coeff          # dirección del mensaje
    move $a1, $t3                 # índice para imprimir
    jal print_index               # imprimir índice

    li $v0, 5                     # syscall para leer entero
    syscall
    sw $v0, 0($t2)                # almacenar coeficiente en memoria

    addi $t2, $t2, 4              # mover dirección al siguiente coeficiente
    addi $t3, $t3, 1              # incrementar índice
    j input_coeff                 # volver al bucle

input_x:
    # Pedir el valor de x
    li $v0, 4                     # syscall para imprimir string
    la $a0, prompt_x              # dirección del mensaje
    syscall

    li $v0, 7                     # syscall para leer float
    syscall
    mov.s $f1, $f0                # guardar x en $f1

    # Evaluar el polinomio
    li $t3, 0                     # reiniciar índice
    l.s $f2, zero_float           # resultado inicial P(x) = 0.0
    l.s $f3, one_float            # inicializar x^0 = 1.0

evaluate_poly:
    bge $t3, $t0, print_result    # si t3 >= n, salir del bucle

    lw $t4, 0($t2)                # cargar coeficiente
    mtc1 $t4, $f0                 # mover coeficiente a $f0
    cvt.s.w $f0, $f0              # convertir a float

    # Calcular x^t3
    li $t5, 0                     # exponente

power_loop:
    bgt $t5, $t3, multiply        # si t5 > t3, ir a multiplicar
    mul.s $f3, $f3, $f1           # x^t5 = x^(t5-1) * x
    addi $t5, $t5, 1              # incrementar exponente
    j power_loop                  # volver al bucle

multiply:
    mul.s $f0, $f0, $f3           # coeficiente * x^t3
    add.s $f2, $f2, $f0           # P(x) = P(x) + coeficiente * x^t3

    addi $t2, $t2, -4             # mover dirección al coeficiente anterior
    addi $t3, $t3, 1              # incrementar índice
    j evaluate_poly               # volver al bucle

print_result:
    # Imprimir el resultado
    li $v0, 4                     # syscall para imprimir string
    la $a0, result_msg            # dirección del mensaje
    syscall

    li $v0, 2                     # syscall para imprimir float
    mov.s $f12, $f2               # mover resultado a $f12
    syscall

    # Salir del programa
    li $v0, 10                    # syscall para salir
    syscall

# Función para imprimir el índice
print_index:
    li $v0, 1                     # syscall para imprimir entero
    move $a0, $a1                 # pasar índice a imprimir
    syscall
    jr $ra                        # volver a la función que llamó
