r Configuración ZMK de m👀sp

[![Compilar firmware ZMK](https://github.com/m00sp/zmk-config-m00corne/actions/workflows/build.yml/badge.svg)](https://github.com/m00sp/zmk-config-m00corne/actions/workflows/build.yml)
[![en](https://img.shields.io/badge/English-380000?style=for-the-badge&logoColor=white&logo=DocuSign)](https://github.com/m00sp/zmk-config-m00corne/blob/master/README.md) [![es](https://img.shields.io/badge/Español-EB5406?style=for-the-badge&logoColor=white&logo=DocuSign)](https://github.com/m00sp/zmk-config-m00corne/blob/master/README.es.md) [![br](https://img.shields.io/badge/Português-380000?style=for-the-badge&logoColor=white&logo=DocuSign)](https://github.com/m00sp/zmk-config-m00corne/blob/master/README.pt-BR.md)

![Teclado Corne - Frontal](keymap_img/corne1.jpg)
![Teclado Corne - Lateral](keymap_img/corne2.jpg)

Una configuración profesional de firmware ZMK para el teclado Corne de 42 teclas, con **disposición Colemak Mod-DH** y soporte nativo para **portugués (Brasil-ABNT2), español e inglés**. Esta configuración implementa técnicas de escritura avanzadas incluyendo modificadores homerow sin temporizador, capas inteligentes y combinaciones de teclas optimizadas para una experiencia de escritura fluida.

> [!NOTE]
>
> **En desarrollo activo**. Las configuraciones pueden cambiar. Consulta el [Manual del Usuario](docs/reference/README.es.md) para documentación detallada.

## Inicio Rápido

¿Quieres probar esta configuración en tu teclado Corne? Sigue estos pasos:

### 1. Descargar el Firmware

1. Ve a la pestaña [GitHub Actions](https://github.com/m00sp/zmk-config-m00corne/actions/workflows/build.yml)
2. Selecciona la última ejecución de flujo de trabajo exitosa
3. Descarga el artefacto de firmware (archivo `.uf2`) de la sección **Artifacts**
4. Extrae el archivo para acceder a los archivos de firmware

### 2. Flashear a Tu Teclado

Flashea el firmware descargado a tu teclado Corne:

- **Windows/macOS/Linux**: Mantén presionado el botón de reinicio en tu controlador de teclado, conéctalo por USB y copia el archivo `.uf2` a la unidad montada. El teclado se reiniciará automáticamente.
- Para instrucciones de flasheo detalladas, consulta la documentación de tu teclado o la [Guía de Flasheo de ZMK](https://zmk.dev/docs/user-setup/flashing).

### 3. Explora el Mapa de Teclas

Una vez flasheado, consulta la sección [Descripción General del Mapa de Teclas](#descripción-general-del-mapa-de-teclas) a continuación y el [Manual del Usuario](docs/reference/README.md) completo para detalles de capas y comportamientos de teclas.

## Características Destacadas

✅ Localización para portugués (Brasil-ABNT2) usando el módulo [zmk-locales](https://github.com/joelspadin/zmk-locales)  
✅ Puntuación española <kbd>¿</kbd> y <kbd>¡</kbd> (Linux y Windows) a través del módulo [zmk-unicode](https://github.com/urob/zmk-unicode)  
✅ **Modificadores homerow sin temporizador** para teclas modificadoras sin restricciones de temporización  
✅ Capas inteligentes que se desactivan automáticamente (números, navegación, ratón) usando [zmk-auto-layer](https://github.com/urob/zmk-auto-layer)  
✅ Comportamiento inteligente de mayús: repetición/mayús-pegajoso/mayús-bloqueo/magia de mayús  
✅ Sintaxis de configuración simplificada usando macros [zmk-helpers](https://github.com/urob/zmk-helpers)  
✅ Soporte de pantalla OLED vertical con [zmk-oled-nice](https://github.com/mctechnology17/zmk-nice-oled)  
✅ Navegación de capas basada en combos en lugar de mod-tap, reduciendo la sobrecarga del pulgar  

> [!WARNING]
>
> **Usuarios de Linux**: IBus debe estar instalado y configurado en tu sistema para usar la puntuación española (<kbd>¿</kbd> y <kbd>¡</kbd>).

## Descripción General del Mapa de Teclas

Aquí está el mapa de teclas generado por [keyboard-layout-editor](https://github.com/ijprest/keyboard-layout-editor):

<details>
<summary>Disposición Visual (KLE)</summary>

![Editor de Disposición de Teclado](keymap_img/42-keys.png)

</details>

Aquí está el desglose completo del mapa de teclas por capa, generado por [keymap-drawer](https://github.com/caksoylar/keymap-drawer):

<details>
<summary>Desglose de Capas</summary>

![Capas del Mapa de Teclas](keymap_img/keymap.svg)

</details>

## Documentación

Para documentación detallada capa por capa y explicaciones de configuración, consulta el [Manual del Usuario](docs/reference/README.es.md).

## Filosofía de Diseño

Esta configuración se basa en la investigación de técnicas de escritura avanzadas e innovación comunitaria. Las decisiones de diseño clave se explican a continuación:

### Modificadores Homerow Sin Temporizador

**¿Qué son los modificadores homerow?**

Los modificadores homerow (HRM) permiten que las teclas modificadoras (Ctrl, Shift, Alt, Gui) se coloquen en las teclas de la fila de inicio. Cuando se toca, producen letras; cuando se mantienen presionadas, producen modificadores. Esto reduce el movimiento de dedos y mejora la eficiencia de escritura.

**El enfoque "sin temporizador"**

Las implementaciones tradicionales de HRM luchan contra la sensibilidad de temporización: requieren duraciones de retención precisas para distinguir entre un "toque" y una "retención". El enfoque sin temporizador minimiza esta dependencia de temporización a través de:

- **Término de tap grande** (280 ms) para eliminar restricciones de temporización estrictas
- **Sabor balanceado** para reconocer retenciones cuando otra tecla se presiona dentro del término de tap
- **Requerir-inactivo-anterior** para resolver instantáneamente las teclas tocadas inmediatamente después de otra tecla
- **Hold-tap posicional** para evitar mods falsos cuando se ruedan las teclas en la misma mano
- **Hold-trigger-on-release** para permitir combinar múltiples modificadores en la misma mano

El resultado es prácticamente sin errores, escritura fluida y demoras mínimas.

### Capas Inteligentes

Más allá de la conmutación estándar de capas, esta configuración incluye comportamiento de capas inteligente:

- **Numword**: Auto-activa la capa de números mientras escribes números, se desactiva automáticamente en teclas no numéricas
- **Ratón Inteligente**: Capa de ratón rápida a través de combo, se desactiva automáticamente al presionar cualquier tecla
- **Magia de Mayús**: Comportamiento de mayús inteligente: repetición después de letras, mayús-pegajoso para mayúsculas, retención para mayús regular, doble tap para bloqueo de mayús

### ¿Por Qué Combos en Lugar de Mod-Tap?

La navegación de capas usa **combos** (presiones de teclas simultáneas) en lugar de mod-tap, evitando la sobrecarga del pulgar en las teclas de navegación más utilizadas. Esto mantiene los pulgares reservados para la barra espaciadora y controles esenciales.

## Inspiración y Créditos

Esta configuración se basa en los hombros de la comunidad abierta de teclados ergonómicos:

- **[zmk-config de urob](https://github.com/urob/zmk-config/)** – La base para modificadores homerow sin temporizador, capas inteligentes y técnicas avanzadas de ZMK. Esta configuración adapta mucho las excelentes ideas de urob. Altamente recomendado revisar su trabajo.
- **[Configuración ZMK de Kim](https://github.com/infused-kim/zmk-config)** – Refinamientos adicionales y variaciones en el enfoque de modificadores homerow
- **[Miryoku](https://github.com/manna-harbour/miryoku/)** – Inspiración para diseño eficiente de capas y filosofía de colocación de teclas
- **[Publicación de Reddit de Kim](https://www.reddit.com/r/ErgoMechKeyboards/comments/11gejh3/lpt_try_urobs_zmk_timeless_homerow_mods_combos/)** – Excelente explicación de modificadores homerow sin temporizador y consejos prácticos (¡lectura recomendada!)

## Stack y Dependencias

- **ZMK v0.3** – Firmware central
- **[zmk-helpers](https://github.com/urob/zmk-helpers)** – Sintaxis de devicetree simplificada
- **[zmk-auto-layer](https://github.com/urob/zmk-auto-layer)** – Desactivación automática de capas inteligentes
- **[zmk-unicode](https://github.com/urob/zmk-unicode)** – Entrada de Unicode para caracteres especiales
- **[zmk-locales](https://github.com/joelspadin/zmk-locales)** – Soporte de localización portuguesa
- **[zmk-oled-nice](https://github.com/mctechnology17/zmk-nice-oled)** – Widgets de pantalla OLED

Todas las dependencias se encuentran fijadas en el [archivo de manifiesto de west](config/west.yml).

*Traducido usando GitHub Copilot y GPT-4o.*
