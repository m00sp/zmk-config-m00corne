# m👀corne Manual del Usuario

¡Bienvenido a tu teclado! Esta guía explica cada capa y cómo usarlas. Imágenes del mapa de teclado generadas por [keymap-drawer](https://github.com/caksoylar/keymap-drawer).

## Tabla de Contenidos

- [Cómo Funcionan las Capas](#cómo-funcionan-las-capas)
- [Capa BASE](#capa-base)
- [Capa NAV](#capa-nav-navegación--edición)
- [Capa NUM](#capa-num-números)
- [Capa SYMBOLS](#capa-symbols-símbolos-desplazados)
- [Capa MOUSE](#capa-mouse)
- [Capa WM](#capa-wm-gestión-de-ventanas)
- [Capa MEDIA](#capa-media-multimedia--bluetooth)
- [Capa FUNC](#capa-func-teclas-de-función)

---

## Cómo Funcionan las Capas

Tu teclado tiene múltiples capas. Cambias entre ellas **manteniendo presionadas las teclas del pulgar**:

- **Pulgar izquierdo, fila inferior**: Mantén presionado para activar capas
- **Pulgar derecho, fila inferior**: Mantén presionado para activar capas
- **Pulsa** la tecla para su función primaria (ej: `ESPACIO`, `ENTER`, `ESCAPE`)
- **Mantén presionada** la tecla para activar la capa asignada

**Mapa de activación rápida:**
- Mantén presionado `ESC` izquierdo → **Capa MEDIA** (más importante para acceso rápido)
- Mantén presionadas otras combinaciones de pulgar → accede a otras capas
- También puedes mantener presionadas las teclas de capa mientras mantienes modificadores (Mayús, Ctrl, Alt, Cmd)

---

## Capa BASE

![my_keymap](../../keymap_img/keymap_base.svg)

Tu capa de mecanografía principal. Usa el diseño **Colemak-MOD DH** para mecanografía eficiente.

| Grupo de Teclas | Teclas |
|-----------------|--------|
| **Letras** | Q W F P B / J L U Y (diseño Colemak) |
| **Caracteres Especiales** | ` (acento grave), ~ (tilde), ´ (agudo), Ç, " (comillas), ' (apóstrofo) |
| **Modificadores** | Mantén presionado A, R, S, T para Ctrl, Alt, Mayús, GUI (lado izquierdo) |
| **Teclas del Pulgar** | `ESPACIO` (pulsa) / Capa (mantén), `TABULADOR` (pulsa), `ESC` (pulsa / MEDIA mantén) |
| **Pulgar Derecho** | `ENTER` (pulsa), `RETROCESO` (pulsa), `SUPR` (pulsa) |

---

## Capa NAV (Navegación y Edición)

![my_keymap](../../keymap_img/keymap_nav.svg)

Activada manteniendo presionada la tecla del pulgar izquierdo. Úsala para movimiento del cursor y edición sin abandonar la fila de inicio.

| Posición | Función |
|----------|---------|
| **Fila de inicio (área ASDF)** | ← (Izquierda), ↓ (Abajo), → (Derecha), más modificadores |
| **Encima de la fila de inicio** | Re Pág, Av Pág, Inicio, Fin |
| **Fila inferior** | Teclas de capa base duplicadas para flujo de edición fácil |
| **Teclas de números** | Acceso rápido a números mientras navegas |

**Caso de uso:** Selecciona texto o muévete por tu documento manteniendo tus manos en posición.

---

## Capa NUM (Números)

![my_keymap](../../keymap_img/keymap_num.svg)

Activada manteniendo presionada la tecla del pulgar derecho. Proporciona diseño de teclado numérico con ayudantes de edición.

| Posición | Teclas |
|----------|--------|
| **Fila superior** | 7, 8, 9 |
| **Fila media** | 4, 5, 6 |
| **Fila inferior** | 1, 2, 3 |
| **Pulgar derecho** | 0 (cero) |
| **Extra** | . (punto) para decimales |

**Modificadores disponibles:** Mayús, Alt, Ctrl en lado izquierdo para combinaciones rápidas de teclas mientras escribes números.

---

## Capa SYMBOLS (Símbolos Desplazados)

![my_keymap](../../keymap_img/keymap_sym.svg)

Accede a símbolos comunes de programación y escritura sin presionar Mayús.

| Símbolo | Uso |
|---------|-----|
| `!`, `@`, `#`, `$`, `%` | Símbolos comunes (fila superior) |
| `-`, `=`, `[`, `]`, `\` | Corchetes de matemáticas y código |
| `_`, `+`, `{`, `}`, `\|` | Más símbolos de código |
| `(`, `)` | Paréntesis |
| `^`, `&`, `*` | Operadores matemáticos |

**Consejo:** Estos son versiones ya "desplazadas", así que no necesitas mantener presionado Mayús mientras escribes.

---

## Capa MOUSE

![my_keymap](../../keymap_img/keymap_mouse.svg)

Controla tu ratón sin tocar el panel táctil. Pasa el ratón sobre las teclas para ver funciones del ratón.

| Posición | Función |
|----------|---------|
| **Fila de inicio** | Movimiento del ratón: ← ↓ ↑ → |
| **Debajo de la fila de inicio** | Desplazamiento: Izquierda, Abajo, Arriba, Derecha |
| **Pulgar derecho** | Clic izquierdo, clic central, clic derecho |
| **Con modificadores** | Mantén presionado Mayús/Ctrl/Alt para movimiento más rápido/lento |

**Caso de uso:** Control preciso del ratón para clics precisos o cuando el panel táctil no está disponible.

---

## Capa WM (Gestión de Ventanas)

![my_keymap](../../keymap_img/keymap_wm.svg)

Acceso rápido a atajos de gestión de ventanas (diseñado para macOS con tecla Comando).

| Tecla | Función |
|-------|---------|
| **Esquinas (fila superior)** | Ajusta ventanas a esquinas de pantalla |
| **Lados (fila media)** | Ajusta ventanas a mitades de pantalla |
| **Centro (fila inferior)** | Centra la ventana |
| **Mantén presionado Mayús** | Posiciones alternativas de ventana |

**Nota:** Los atajos usan combinaciones `Cmd+Número` comunes en aplicaciones de gestión de ventanas.

---

## Capa MEDIA (Multimedia y Bluetooth)

![my_keymap](../../keymap_img/keymap_med.svg)

Controla reproducción multimedia y conexiones Bluetooth. Activada por **mantener presionado `ESC` izquierdo**.

| Posición | Función |
|----------|---------|
| **Fila superior** | Brillo Abajo, Brillo Arriba |
| **Fila media** | Reproducir/Pausa, Anterior, Volumen Abajo, Volumen Arriba, Siguiente |
| **Fila inferior** | Bluetooth: BT 0, BT 1, BT 2, BT 3, BT 4 |
| **Extra** | Limpiar BT (abajo a la izquierda), Silenciar |

**Cómo cambiar perfiles Bluetooth:**
1. Mantén presionado `ESC` izquierdo para activar la capa MEDIA
2. Pulsa uno de los botones BT (0-4) para conectar a ese perfil
3. Mantén presionado Mayús + botón BT para limpiar ese perfil

---

## Capa FUNC (Teclas de Función)

![my_keymap](../../keymap_img/keymap_func.svg)

Accede a teclas de función F1-F12 y versiones desplazadas para atajos de aplicación.

| Posición | Función |
|----------|---------|
| **Fila superior** | F7, F8, F9, F10 |
| **Fila media** | F4, F5, F6, F11 |
| **Fila inferior** | F1, F2, F3, F12 |
| **Mantén presionado Mayús** | Versiones desplazadas: Mayús+F1, Mayús+F2, etc. |

**Caso de uso:** Atajos de aplicación, funciones del sistema (Volumen, Brillo si no están en capa MEDIA), o macros para juegos.

---

## Comenzar

1. **Comienza con la capa BASE** - Practica el diseño Colemak
2. **Aprende la capa NUM** - Añade entrada de números a tu flujo de trabajo
3. **Explora la capa NAV** - Una vez cómodo con la navegación, la velocidad aumenta dramáticamente
4. **Añade la capa MEDIA** - Para usuarios de portátil (Brillo, Volumen, Bluetooth)
5. **Domina el resto** - Añade SYMBOLS, MOUSE, WM, y FUNC según sea necesario

**Consejos:**
- Todas las capas preservan las teclas modificadoras de la capa base (Mayús, Ctrl, Alt, Cmd)
- Las teclas del pulgar se pueden mantener presionadas mientras se usan otras teclas para cambio rápido de capa
- Practica una capa a la vez para desarrollar memoria muscular

*Traducido usando GitHub Copilot y GPT-4o.*
