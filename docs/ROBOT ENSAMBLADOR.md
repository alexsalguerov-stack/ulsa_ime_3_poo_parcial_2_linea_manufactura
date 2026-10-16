# Documentación de la clase: [Inserta aquí el nombre de tu clase]

> Copia este archivo como `docs/<Clase>.md` (por ejemplo, con el nombre de tu máquina) y llena tu copia. No modifiques la plantilla.

**Elaborada por:** Yurik David Alarcon Gtz.
**Matrícula:** 25292
**Bloque:** 3

## 1. Propósito

**¿Qué máquina representa tu clase y qué operación hace sobre la pieza?**

Representa un robot ensamblador que une componentes de una pieza.

**¿Cuál es su componente y por qué no existe sin la máquina?**

 Su componente es una pinza, que forma parte del robot mediante composición y está diseñada para trabajar con él.

## 2. Decisiones de diseño

**Atributos propios de tu clase y validación de cada uno:**

precisionPosicion: debe estar entre 1 y 100.

fuerzaPrensado: debe ser mayor que 0 y no superar los 5000 N.

**Métodos propios (los que la clase base no tiene):**

ajustarPrecision(), ajustarFuerzaPrensado(), ensamblarPiezas().

**Método de la base que redefines, y cómo reutilizas la versión de la base:**

mostrarEstado(). Dentro de mi método llamo a Maquina::mostrarEstado() para mostrar los datos generales y después agrego la información propia del robot. Actualmente, como el método de la base no es virtual, técnicamente se oculta en la clase derivada.

**¿Cómo modelaste el desgaste del componente y por qué así?**

La pinza pierde una unidad de vida útil por cada pieza procesada. Cuando llega a cero, el robot entra en falla y necesita mantenimiento para restaurarla. Así podemos simular fallas de manera predecible.

**¿Qué usa tu clase de `Maquina` y qué agrega?**

Usa el identificador, el nombre, el estado, los contadores de piezas, el tiempo trabajado y los paros. Agrega la precisión, la fuerza de prensado, la pinza y las operaciones de ensamblaje y mantenimiento.

## 3. Diagrama

Diagrama de tu clase y su componente, hecho en draw.io. Debe mostrar la relación de herencia con `Maquina` y la de composición con tu componente. Guarda la imagen en `docs/` y enlázala aquí.

[![Inserta aquí tu diagrama](<DISEÑO CLASE ROBOT ENSAMBLADOR.drawio.png>)]

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

Tenia la duda de como en equipo ibamos a lograr que el codigo fuera compatible entre si y con las variables y funciones de otras partes del codigo, lo respondi preguntando a varios compañeros sobre como lo iban a hacer ellos.

**Errores que encontraste y cómo los corregiste:**

[Inserta aquí tu respuesta]
