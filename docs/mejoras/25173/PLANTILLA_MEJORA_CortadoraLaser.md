# Propuesta de mejora: [Inserta aquí el título de tu propuesta]

> Crea una carpeta dentro de `docs/mejoras/` con tu número de matrícula como nombre, copia este archivo ahí como `mejora.md` y llena tu copia. No modifiques la plantilla.
>
> La propuesta es solo diseño: no se programa.

**Propuesta de mejora elaborada por:** César Leonardo Garrido González

## 1. Impacto

**¿Es una mejora o una corrección?**
Es una mejora
**¿Qué observaste en la solución del equipo que dio origen a la propuesta?**

En este programa cuando el lente llega al fin de su vida util la maquina entra en falla y en mantenimiento, pero no se lleva un registro del desgaste para el componente que falla ni tampoco un historial de cambios de lente

**¿Qué mejora o qué corrige, y por qué vale la pena?**

Esta mejora ayuda llevar un historial de fallas y de cambios de lente, cada que se realice el mantenimiento queda guardado en una bitacora. Esto permite conocer cuantas veces ha fallado la máquina    y cuanto lentes se han utilizado

## 2. Qué implica

**Clases nuevas:**
Podría ser (creo):
HistorialMantenimiento

**Comportamiento nuevo en clases existentes:**

La clase CortadoraLaser registrará cada mantemiento a la máquina y modificara a HistorialMantenimiento

**Interacciones nuevas entre objetos:**
1.- El lente se desgasta
2.- La maquina entra en mantenimento
3.- El historial de mantenimiento guarda el evento
4.- El reporte final muestra cuantas veces entro en mantenimiento

**Relaciones nuevas (herencia, composición o agregación) y por qué son de ese tipo:**
Podría ser una relación de composición, porque el historial solo sirve para registrar las fallas y mantenimientos, en caso de que CortadoraLaser deje de existir el historial tambien dejaria de exisitir


## 3. Diagrama de clases

Diagrama hecho en draw.io que muestre la solución con la mejora incorporada. Distingue lo nuevo de lo existente, por ejemplo con otro color. Guarda la imagen en esta misma carpeta y enlázala aquí.

[Diagrama de mejora](DiagramaMejora-1.png)