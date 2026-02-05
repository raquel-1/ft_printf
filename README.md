# ft_printf

*Este proyecto ha sido creado como parte del currículo de 42 por raqroca-.*

## Descripción

`ft_printf` es una reimplementación de la función `printf()` de la biblioteca estándar de C. El objetivo principal es comprender y dominar el uso de funciones variádicas en C, así como desarrollar habilidades en el manejo de conversiones de formato y gestión de memoria.

Este proyecto permite crear una librería personalizada que imita el comportamiento del `printf()` original, implementando las conversiones más comunes y devolviendo el número de caracteres impresos.

## Instrucciones

### Compilación

Para compilar la librería, ejecuta:

```bash
make
```

```bash
cc -Wall -Wextra -Werror ft_printf.c libftprintf.a -o delete
```

```bash
./delete
```

```bash
make fclean
```

```bash
rm -f delete
```

### Comandos del Makefile

- `make` o `make all`: Compila la librería
- `make clean`: Elimina los archivos objeto (.o)
- `make fclean`: Elimina los archivos objeto y la librería
- `make re`: Recompila todo desde cero
- `make bonus`: Compila la parte bonus

### Uso

1. Incluye el header en tu código:

```c
#include "ft_printf.h"
```

## Conversiones Implementadas

La función ft_printf soporta las siguientes conversiones:

- `%c` - Imprime un carácter
- `%s` - Imprime una cadena de caracteres
- `%p` - Imprime un puntero en formato hexadecimal
- `%d` - Imprime un número decimal (base 10)
- `%i` - Imprime un entero en base 10
- `%u` - Imprime un número decimal sin signo
- `%x` - Imprime un número hexadecimal en minúsculas
- `%X` - Imprime un número hexadecimal en mayúsculas
- `%%` - Imprime el símbolo de porcentaje

## Algoritmo y Estructura de Datos

### Elección del Algoritmo

La función `ft_printf` procesa la cadena de formato de manera secuencial, recorriéndola carácter por carácter. Cuando encuentra el símbolo `%`, identifica el tipo de conversión que debe aplicar y obtiene el argumento correspondiente usando las funciones variádicas de C (`va_start`, `va_arg` y `va_end`).

**Justificación**: Este enfoque es simple y eficiente, ya que no requiere estructuras complejas ni uso extra de memoria. Además, permite un control claro del flujo del programa y facilita añadir nuevas conversiones o funcionalidades en el futuro.

### Estructura de Datos

El proyecto utiliza una arquitectura modular con las siguientes componentes:

1. **Función principal (ft_printf)**: Gestiona la inicialización de `va_list` y coordina el parsing
2. **Parser de formato**: Identifica los especificadores de conversión
3. **Funciones de conversión**: Una función dedicada para cada tipo de conversión (`%c`, `%s`, `%d`, etc.)
4. **Funciones auxiliares**: Para conversión de bases numéricas, manejo de signos, etc.

**Justificación**: La separación en funciones especializadas permite:

- Código más limpio y mantenible
- Facilita el testing de cada conversión de forma independiente
- Permite reutilizar código (por ejemplo, `%d` e `%i` comparten lógica)

## Recursos

### Documentación Técnica

- [Manual de printf](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Funciones variádicas en C](https://en.cppreference.com/w/c/variadic)
- [stdarg.h reference](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stdarg.h.html)

### Tutorial

- [Variadic functions in C](https://www.geeksforgeeks.org/variadic-functions-in-c/)

### Uso de IA

Durante el desarrollo del proyecto se siguieron las normas de 42 sobre el uso de IA, utilizándola solo como apoyo para aclarar conceptos teóricos, comprobar sintaxis específica de C y entender situaciones límite que pueden provocar errores en ciertas conversiones. Todo el código fue escrito y comprendido de forma autónoma, sin pedir implementaciones directas a la IA.


---

**Escuela**: 42 MADRID
