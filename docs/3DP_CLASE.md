# Documentación de la clase: Impresora_3D


**Elaborada por:** Alejandro Salguero Vega
**Matrícula:** 26011
**Bloque:** 3

## 1. Propósito

**¿Qué máquina representa tu clase y qué operación hace sobre la pieza?**

Impresora 3D - Imprime el chasis y las llantas del carrito de juguete.

**¿Cuál es su componente y por qué no existe sin la máquina?**

La función del extrusor es mover el material a traves de la boquilla caliente por lo que necesita una forma de moverse en los tres ejes de movimiento y una base en la cual depositar el movimiento.

## 2. Decisiones de diseño

**Atributos propios de tu clase y validación de cada uno:**

- `tempBoquilla` (float): Temperatura de la boquilla; se valida que sea mayor a 0 y no exceda el límite del material (ej. 260°C).
- `tempExtrusor` (float): Temperatura de control del bloque; validada para evitar sobrecalentamiento.
- `velocidadImpresion` (float): Velocidad de avance; validada para que sea positiva, ya que define el tiempo de procesamiento.

**Métodos propios (los que la clase base no tiene):**

- `calentarBoquilla(float temp)`: Setea la temperatura necesaria para iniciar la impresión.
- `fabricarPieza(string id)`: Lógica específica para coordinar la creación del chasis o llantas.

**Método de la base que redefines, y cómo reutilizas la versión de la base:**

Redefino el método `procesarPieza()`. Reutilizo la versión de la base llamando a los métodos protegidos `registrarPieza()` y `agregarTiempo(segundos)` una vez que se ha validado que el componente (Extrusor) no ha fallado.

**¿Cómo modelaste el desgaste del componente y por qué así?**

Modelé el desgaste mediante una clase `Extrusor` con un atributo `vidaUtil` (int). En cada ciclo de `procesarPieza()`, se llama a `reducirVida()`. Cuando este llega a cero, se dispara el método `reportarFalla()` de la base. Se hizo así para separar la lógica de "salud" del componente de la lógica de "estado" de la máquina.

**¿Qué usa tu clase de `Maquina` y qué agrega?**

Usa de `Maquina` toda la infraestructura de control (id, nombre, encendido/apagado y contadores de producción). Agrega la gestión térmica y la dependencia directa de la salud del Extrusor para determinar si puede seguir operando.

## 3. Diagrama

Diagrama de tu clase y su componente, hecho en draw.io. Debe mostrar la relación de herencia con `Maquina` y la de composición con tu componente. Guarda la imagen en `docs/` y enlázala aquí.

![Diagrama de la clase](3DP_Diagrama.png)

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**



**Errores que encontraste y cómo los corregiste:**


