# Documentación de la clase: [Inserta aquí el nombre de tu clase]

> Copia este archivo como `docs/<Clase>.md` (por ejemplo, con el nombre de tu máquina) y llena tu copia. No modifiques la plantilla.

**Elaborada por:** César Leonardo Garrido González
**Matrícula:** 25173
**Bloque:** 2

## 1. Propósito

**¿Qué máquina representa tu clase y qué operación hace sobre la pieza?**

Representa la Cortadora laser, su operación es hacer cortes de diseño sobre el carrito.

**¿Cuál es su componente y por qué no existe sin la máquina?**

El componente es lente, ya que el lente solo no serviría si el resto de la máquina, si desaparece maquina desaparece lente

## 2. Decisiones de diseño

**Atributos propios de tu clase y validación de cada uno:**

potenciaLaser (float): representa la potencia del láser utilizada para realizar los cortes. Debe ser un valor positivo.

velocidadCorte (float): representa la velocidad con la que se realiza el corte. Debe ser un valor positivo.

lente (Lente): componente encargado de controlar el desgaste del sistema de corte.

**Métodos propios (los que la clase base no tiene):**

ajustarPotencia(float p): permite modificar la potencia del láser.

grabarDetalle(string patron): simula el grabado de detalles específicos sobre una pieza.

**Método de la base que redefines, y cómo reutilizas la versión de la base:**

Se redefine el método mostrarEstado(). Primero se utiliza el método mostrarEstado() de la clase Maquina para mostrar la información general heredada. 

Después se agregan los datos específicos de la Cortadora Láser, como la potencia, la velocidad de corte y la vida útil restante del lent e

**¿Cómo modelaste el desgaste del componente y por qué así?**

El desgaste se modeló mediante una variable llamada vidaUtil dentro de la clase Lente. Cada vez que la Cortadora Láser procesa una pieza, la vida útil disminuye en una unidad. Cuando la vida útil llega a cero, la máquina entra en estado de falla y requiere mantenimiento. Se eligió este método porque es sencillo de implementar y permite representar claramente el desgaste progresivo del componente.

**¿Qué usa tu clase de `Maquina` y qué agrega?**

Mi clase utiliza las funcionalidades heredadas de Maquina, como encender, apagar, verificar si puede procesar piezas, registrar piezas procesadas, acumular tiempo trabajado, reportar fallas y mostrar el estado general.

Además agrega atributos propios relacionados con el corte láser, un componente de tipo Lente, el desgaste del componente, el mantenimiento del lente y operaciones específicas como ajustar la potencia y grabar detalles en las piezas.

## 3. Diagrama

Diagrama de tu clase y su componente, hecho en draw.io. Debe mostrar la relación de herencia con `Maquina` y la de composición con tu componente. Guarda la imagen en `docs/` y enlázala aquí.
DiagramaCortadoraLaser.png 

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

[Inserta aquí tu respuesta]

**Errores que encontraste y cómo los corregiste:**

[Inserta aquí tu respuesta]
