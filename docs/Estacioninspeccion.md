# Documentación de la clase: Estacioninspeccion


**Elaborada por:** [Dannia Ximena Plata Palos]
**Matrícula:** [25176]
**Bloque:** [5]

## 1. Propósito

**¿Qué máquina representa tu clase y qué operación hace sobre la pieza?**

[Es la estación de inspección. Mide la pieza y revisa que esté dentro de la tolerancia. Tarda 10 segundos por pieza.]

**¿Cuál es su componente y por qué no existe sin la máquina?**

[Su componente es el Sensor. Se va descalibrando con cada pieza que mide. Es composición porque el sensor se crea dentro de la estación y se borra cuando la estación se borra.]

## 2. Decisiones de diseño

**Atributos propios de tu clase y validación de cada uno:**

[Atributos propios de tu clase y validación de cada uno:
• Sensor sensor: el componente. Si su límite es 0 o menos, se usa 1.
• float toleranciaError: error máximo aceptado. Si es 0 o menos, se usa 0.05.
• int medicionesRealizadas: cuenta las piezas medidas. Empieza en 0.
• int segundosPorPieza: tiempo por pieza. Si es 0 o menos, se usa 10.]

**Métodos propios (los que la clase base no tiene):**

[Métodos propios (los que la clase base no tiene):

medirTolerancia(float valor): dice si el error medido está dentro de la tolerancia.
inspeccionarCalidad(): hace una medición. Como no se pueden usar números aleatorios, el error sigue un ciclo fijo: 0.00, 0.01, 0.02 y 0.03 mm.
procesarPieza(): mide una pieza, suma la pieza y el tiempo, y gasta el sensor.
realizarMantenimiento(): recalibra el sensor y quita la falla.]

**Método de la base que redefines, y cómo reutilizas la versión de la base:**

[Redefino mostrarEstado(). Primero llamo a Maquina::mostrarEstado(), que imprime los datos generales (id, nombre, piezas, tiempo y paros). Después imprimo los datos de mi estación y de mi sensor.]

**¿Cómo modelaste el desgaste del componente y por qué así?**

[El sensor tiene una vida que baja de 1 en 1 con cada pieza. Al llegar a 0, la máquina entra en falla. Lo hice con un número entero para poder calcular a mano cuándo falla: con límite 30 y un lote de 20 piezas, el sensor no falla y termina con 10 de vida. El mantenimiento regresa la vida al límite.]

**¿Qué usa tu clase de `Maquina` y qué agrega?**

[Usa el constructor, puedeProcesar(), registrarPieza(), agregarTiempo(), reportarFalla(), registrarMantenimiento() y mostrarEstado(). Agrega el sensor, la tolerancia y la inspección de calidad.]

## 3. Diagrama

Diagrama de tu clase y su componente, hecho en draw.io. Debe mostrar la relación de herencia con `Maquina` y la de composición con tu componente. Guarda la imagen en `docs/` y enlázala aquí.

[Inserta aquí tu diagrama]

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

[• ¿Importa el límite del sensor si el lote es de 20 piezas? Sí, porque se compara con el tamaño del lote. Con límite 30 y 20 piezas el sensor no falla; si el límite fuera igual al lote, fallaría en la última pieza.]

**Errores que encontraste y cómo los corregiste:**

[VS Code marcaba que Sensor no estaba definido. Los archivos no estaban guardados y los nombres tenían mayúsculas distintas. Los guardé y corregí los nombres.]
