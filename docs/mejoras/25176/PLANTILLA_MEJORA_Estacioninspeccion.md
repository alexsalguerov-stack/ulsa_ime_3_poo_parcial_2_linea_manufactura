# Propuesta de mejora: [Inserta aquí el título de tu propuesta]

> Crea una carpeta dentro de `docs/mejoras/` con tu número de matrícula como nombre, copia este archivo ahí como `mejora.md` y llena tu copia. No modifiques la plantilla.
>
> La propuesta es solo diseño: no se programa.

**Propuesta de mejora elaborada por:** Dannia Ximena Plata Palos

## 1. Impacto

**¿Es una mejora o una corrección?**

[Es una mejora: la estación hoy mide cada pieza, pero no guarda el resultado.]

**¿Qué observaste en la solución del equipo que dio origen a la propuesta?**

[En nuestra solución, inspeccionarCalidad() solo imprime si la pieza pasó o no. No se guarda ni se cuenta. El reporte dice cuántas piezas se terminaron, pero no cuántas estaban fuera de tolerancia.]

**¿Qué mejora o qué corrige, y por qué vale la pena?**

[La estación guardaría el resultado de cada medición y contaría las piezas rechazadas. Así el reporte puede decir cuántas piezas salieron buenas y cuántas malas.]

## 2. Qué implica

**Clases nuevas:**

[• ResultadoInspeccion: guarda una medición. Tiene numeroPieza, desviacion y aprobada, y un método mostrar().]

**Comportamiento nuevo en clases existentes:**

[EstacionInspeccion tendrá un vector<ResultadoInspeccion> historial y un contador piezasRechazadas. En inspeccionarCalidad() guarda el resultado de cada pieza. Métodos nuevos: getPiezasRechazadas() y mostrarHistorial(). Además, mostrarEstado() también muestra las rechazadas.]

**Interacciones nuevas entre objetos:**

[EstacionInspeccion crea un ResultadoInspeccion por cada pieza y lo guarda. Las demás clases no cambian.]

**Relaciones nuevas (herencia, composición o agregación) y por qué son de ese tipo:**

[• Composición EstacionInspeccion – ResultadoInspeccion: los resultados se crean dentro de la estación y desaparecen con ella.
• No hay herencia nueva.]

## 3. Diagrama de clases

Diagrama hecho en draw.io que muestre la solución con la mejora incorporada. Distingue lo nuevo de lo existente, por ejemplo con otro color. Guarda la imagen en esta misma carpeta y enlázala aquí.

[Inserta aquí tu diagrama]
