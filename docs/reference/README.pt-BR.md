# m👀corne Manual do Usuário

Bem-vindo ao seu teclado! Este guia explica cada camada e como usá-las. Imagens do mapa de teclado fornecidas por [keymap-drawer](https://github.com/caksoylar/keymap-drawer).

## Índice

- [Como as Camadas Funcionam](#como-as-camadas-funcionam)
- [Camada BASE](#camada-base)
- [Camada NAV](#camada-nav-navegação--edição)
- [Camada NUM](#camada-num-números)
- [Camada SYMBOLS](#camada-symbols-símbolos-com-shift)
- [Camada MOUSE](#camada-mouse)
- [Camada WM](#camada-wm-gerenciamento-de-janelas)
- [Camada MEDIA](#camada-media-mídia--bluetooth)
- [Camada FUNC](#camada-func-teclas-de-função)

---

## Como as Camadas Funcionam

Seu teclado tem múltiplas camadas. Você muda entre elas **mantendo pressionadas as teclas do polegar**:

- **Polegar esquerdo, linha inferior**: Mantenha pressionado para ativar camadas
- **Polegar direito, linha inferior**: Mantenha pressionado para ativar camadas
- **Toque** a tecla para sua função primária (ex: `ESPAÇO`, `ENTER`, `ESC`)
- **Mantenha pressionada** a tecla para ativar a camada designada

**Mapa de ativação rápida:**
- Mantenha pressionado `ESC` esquerdo → **Camada MEDIA** (mais importante para acesso rápido)
- Mantenha pressionadas outras combinações de polegar → acesse outras camadas
- Você também pode manter pressionadas as teclas de camada enquanto mantém modificadores (Shift, Ctrl, Alt, Cmd)

---

## Camada BASE

![my_keymap](../../keymap_img/keymap_base.svg)

Sua camada de digitação principal. Usa o layout **Colemak-MOD DH** para digitação eficiente.

| Grupo de Teclas | Teclas |
|-----------------|--------|
| **Letras** | Q W F P B / J L U Y (layout Colemak) |
| **Caracteres Especiais** | ` (acento grave), ~ (til), ´ (agudo), Ç, " (aspas), ' (apóstrofo) |
| **Modificadores** | Mantenha pressionado A, R, S, T para Ctrl, Alt, Shift, GUI (lado esquerdo) |
| **Teclas do Polegar** | `ESPAÇO` (toque) / Camada (mantenha), `TAB` (toque), `ESC` (toque / MEDIA mantenha) |
| **Polegar Direito** | `ENTER` (toque), `BACKSPACE` (toque), `DEL` (toque) |

---

## Camada NAV (Navegação e Edição)

![my_keymap](../../keymap_img/keymap_nav.svg)

Ativada mantendo pressionada a tecla do polegar esquerdo. Use para movimento do cursor e edição sem deixar a linha inicial.

| Posição | Função |
|---------|--------|
| **Linha inicial (área ASDF)** | ← (Esquerda), ↓ (Baixo), → (Direita), mais modificadores |
| **Acima da linha inicial** | Page Up, Page Down, Home, End |
| **Linha inferior** | Teclas de camada base duplicadas para fluxo de edição fácil |
| **Teclas de números** | Acesso rápido a números enquanto navega |

**Caso de uso:** Selecione texto ou mova-se pelo seu documento mantendo as mãos em posição.

---

## Camada NUM (Números)

![my_keymap](../../keymap_img/keymap_num.svg)

Ativada mantendo pressionada a tecla do polegar direito. Fornece layout de teclado numérico com auxiliares de edição.

| Posição | Teclas |
|---------|--------|
| **Linha superior** | 7, 8, 9 |
| **Linha do meio** | 4, 5, 6 |
| **Linha inferior** | 1, 2, 3 |
| **Polegar direito** | 0 (zero) |
| **Extra** | . (ponto) para decimais |

**Modificadores disponíveis:** Shift, Alt, Ctrl no lado esquerdo para combinações rápidas de teclas enquanto digita números.

---

## Camada SYMBOLS (Símbolos com Shift)

![my_keymap](../../keymap_img/keymap_sym.svg)

Acesse símbolos comuns de programação e escrita sem usar Shift.

| Símbolo | Uso |
|---------|-----|
| `!`, `@`, `#`, `$`, `%` | Símbolos comuns (linha superior) |
| `-`, `=`, `[`, `]`, `\` | Colchetes de matemática e código |
| `_`, `+`, `{`, `}`, `\|` | Mais símbolos de código |
| `(`, `)` | Parênteses |
| `^`, `&`, `*` | Operadores matemáticos |

**Dica:** Esses já são versões com "shift", então você não precisa manter Shift pressionado enquanto digita.

---

## Camada MOUSE

![my_keymap](../../keymap_img/keymap_mouse.svg)

Controle seu mouse sem tocar no touchpad. Passe o mouse sobre as teclas para ver as funções do mouse.

| Posição | Função |
|---------|--------|
| **Linha inicial** | Movimento do mouse: ← ↓ ↑ → |
| **Abaixo da linha inicial** | Rolagem: Esquerda, Baixo, Cima, Direita |
| **Polegar direito** | Clique esquerdo, clique do meio, clique direito |
| **Com modificadores** | Mantenha Shift/Ctrl/Alt para movimento mais rápido/lento |

**Caso de uso:** Controle preciso do mouse para cliques precisos ou quando o touchpad não está disponível.

---

## Camada WM (Gerenciamento de Janelas)

![my_keymap](../../keymap_img/keymap_wm.svg)

Acesso rápido a atalhos de gerenciamento de janelas (projetado para macOS com tecla Command).

| Tecla | Função |
|-------|--------|
| **Cantos (linha superior)** | Encaixe janelas nos cantos da tela |
| **Lados (linha do meio)** | Encaixe janelas nas metades da tela |
| **Centro (linha inferior)** | Centraliza a janela |
| **Mantenha Shift pressionado** | Posições alternativas de janelas |

**Nota:** Os atalhos usam combinações `Cmd+Número` comuns em aplicativos de gerenciamento de janelas.

---

## Camada MEDIA (Mídia e Bluetooth)

![my_keymap](../../keymap_img/keymap_med.svg)

Controle a reprodução de mídia e conexões Bluetooth. Ativada por **manter pressionado `ESC` esquerdo**.

| Posição | Função |
|---------|--------|
| **Linha superior** | Diminuir Brilho, Aumentar Brilho |
| **Linha do meio** | Reproduzir/Pausar, Anterior, Diminuir Volume, Aumentar Volume, Próximo |
| **Linha inferior** | Bluetooth: BT 0, BT 1, BT 2, BT 3, BT 4 |
| **Extra** | Limpar BT (inferior esquerda), Mudo |

**Como trocar perfis Bluetooth:**
1. Mantenha pressionado `ESC` esquerdo para ativar a camada MEDIA
2. Toque em um dos botões BT (0-4) para conectar a esse perfil
3. Mantenha pressionado Shift + botão BT para limpar esse perfil

---

## Camada FUNC (Teclas de Função)

![my_keymap](../../keymap_img/keymap_func.svg)

Acesse teclas de função F1-F12 e versões com shift para atalhos de aplicativos.

| Posição | Função |
|---------|--------|
| **Linha superior** | F7, F8, F9, F10 |
| **Linha do meio** | F4, F5, F6, F11 |
| **Linha inferior** | F1, F2, F3, F12 |
| **Mantenha Shift pressionado** | Versões com shift: Shift+F1, Shift+F2, etc. |

**Caso de uso:** Atalhos de aplicativos, funções do sistema (Volume, Brilho se não estiver na camada MEDIA), ou macros para jogos.

---

## Começando

1. **Comece com a camada BASE** - Pratique o layout Colemak
2. **Aprenda a camada NUM** - Adicione entrada de números ao seu fluxo de trabalho
3. **Explore a camada NAV** - Uma vez confortável com navegação, a velocidade aumenta dramaticamente
4. **Adicione a camada MEDIA** - Para usuários de laptop (Brilho, Volume, Bluetooth)
5. **Domine o resto** - Adicione SYMBOLS, MOUSE, WM, e FUNC conforme necessário

**Dicas:**
- Todas as camadas preservam as teclas modificadoras da camada base (Shift, Ctrl, Alt, Cmd)
- As teclas do polegar podem ser mantidas pressionadas enquanto usa outras teclas para troca rápida de camada
- Pratique uma camada de cada vez para desenvolver memória muscular

*Traduzido usando GitHub Copilot e GPT-4o.*
