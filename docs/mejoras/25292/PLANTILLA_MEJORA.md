# Propuesta de mejora: Mantenimiento preventivo de la pinza del robot ensamblador

> Crea una carpeta dentro de `docs/mejoras/` con tu número de matrícula como nombre, copia este archivo ahí como `mejora.md` y llena tu copia. No modifiques la plantilla.
>
> La propuesta es solo diseño: no se programa.

**Propuesta de mejora elaborada por:** Yurik David Alarcon Gtz.

## 1. Impacto

**¿Es una mejora o una corrección?**

Es una mejora, porque agrega una función nueva a la planta.

**¿Qué observaste en la solución del equipo que dio origen a la propuesta?**

Observé que la pinza del robot ensamblador solo provoca una falla cuando se agota su vida útil, por lo que el robot debe detenerse para recibir mantenimiento.

**¿Qué mejora o qué corrige, y por qué vale la pena?**

Propongo implementar un aviso cuando a la pinza le queden dos unidades de vida útil. Así, la planta podría programar el mantenimiento preventivo antes de que el robot falle y evitar interrupciones inesperadas.

## 2. Qué implica

**Clases nuevas:**

No sería necesario crear clases nuevas, ya que se pueden utilizar las clases RobotEnsamblador, Pinza, Maquina y Planta que ya existen en el proyecto.

**Comportamiento nuevo en clases existentes:**

La clase Pinza permitiría identificar cuándo está cerca de agotarse. El robot podría avisar que necesita mantenimiento preventivo y la planta podría programarlo antes de que ocurra una falla.

**Interacciones nuevas entre objetos:**

El robot consultaría la vida útil de su pinza y comunicaría a la planta cuando sea necesario realizar mantenimiento preventivo. La planta organizaría la atención de esa máquina.

**Relaciones nuevas (herencia, composición o agregación) y por qué son de ese tipo:**

No sería necesario agregar nuevas relaciones de herencia ni de composición. Se conservaría la composición entre RobotEnsamblador y Pinza, porque la pinza es un componente del robot, y la agregación entre Planta y las máquinas, porque la planta organiza máquinas creadas fuera de ella. La mejora agregaría una interacción de mantenimiento preventivo entre estos objetos.

## 3. Diagrama de clases

Diagrama hecho en draw.io que muestre la solución con la mejora incorporada. Distingue lo nuevo de lo existente, por ejemplo con otro color. Guarda la imagen en esta misma carpeta y enlázala aquí.

<img src="PROPUESTA DE MEJORA DE ROBOT ENSAMBLADOR.drawio (1).png">
[![Inserta aquí tu diagrama](docs/PROPUESTA DE MEJORA DE ROBOT ENSAMBLADOR.drawio (1).png)]
