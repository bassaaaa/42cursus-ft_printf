*This project has been created as part of the 42 curriculum by tsito.*

# ft_printf

## Description

`ft_printf` is a 42 Common Core C project whose goal is to recode a simplified
version of the standard C `printf()` function.

The project builds a static library named `libftprintf.a` containing:

```c
int	ft_printf(const char *format, ...);
```

The function writes formatted output to standard output and returns the number
of characters printed. Its behavior is compared against the original libc
`printf()` for the required conversions, but it does not implement the original
`printf()` buffer management.

This project focuses on:

- parsing a format string,
- using variadic arguments with `stdarg.h`,
- converting integers and pointers to textual representations,
- writing reusable C code that follows the 42 Norm.

### Mandatory Requirements

The library must support the following conversions:

| Conversion | Behavior |
| --- | --- |
| `%c` | Print a single character. |
| `%s` | Print a string, following the common C string convention. |
| `%p` | Print a `void *` pointer in hexadecimal format. |
| `%d` | Print a signed decimal integer. |
| `%i` | Print a signed base-10 integer. |
| `%u` | Print an unsigned decimal integer. |
| `%x` | Print an unsigned hexadecimal integer using lowercase digits. |
| `%X` | Print an unsigned hexadecimal integer using uppercase digits. |
| `%%` | Print a percent sign. |

Subject constraints:

- the project must be written in C,
- the code must follow the 42 Norm,
- the project must compile with `cc -Wall -Wextra -Werror`,
- the Makefile must provide at least `$(NAME)`, `all`, `clean`, `fclean`, and
  `re`,
- the archive must be created with `ar`; `libtool` is forbidden,
- `libftprintf.a` must be created at the repository root,
- the public header must be named `ft_printf.h`,
- allowed external functions are `malloc`, `free`, `write`, `va_start`,
  `va_arg`, `va_copy`, and `va_end`,
- libft is authorized if it is included in a `libft/` directory and compiled by
  this project's Makefile.

### Bonus Requirements

The bonus part is optional and is evaluated only if the mandatory part is
perfect.

The subject lists support for:

- any combination of the `-`, `0`, `.`, and minimum field width options under
  all conversions,
- all of the flags `#`, space, and `+`.

Bonus files should follow the subject convention, usually by using
`_bonus.c` and `_bonus.h` filenames.

## Instructions

### Build

From the repository root, run:

```sh
make
```

This should produce:

```text
libftprintf.a
```

### Clean

Remove object files:

```sh
make clean
```

Remove object files and the static library:

```sh
make fclean
```

Rebuild from scratch:

```sh
make re
```

### Use in another C file

Include the header:

```c
#include "ft_printf.h"
```

Example:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("answer: %d, hex: %x, string: %s\n", 42, 42, "hello");
	return (0);
}
```

Compile with the library:

```sh
cc -Wall -Wextra -Werror main.c libftprintf.a
```

## Algorithm and Data Structures

The chosen algorithm is a single left-to-right scan of the format string.

For each character:

1. If the character is not `%`, write it directly to standard output and
   increment the printed character count.
2. If the character is `%`, inspect the next character as a conversion
   specifier.
3. Fetch the next variadic argument with `va_arg` using the type required by
   the conversion.
4. Dispatch the value to a small conversion-specific printing function.
5. Add the number of characters written by that function to the total count.

This algorithm is appropriate because the mandatory subject does not require
full libc-style buffering, positional parameters, locale handling, or complex
format grammar. A linear parser keeps the behavior predictable, makes error
handling simpler, and avoids unnecessary memory allocation.

The main data structures are deliberately simple:

- `va_list` stores the current position in the variadic argument list.
- The input `const char *format` acts as the parsing stream.
- Small helper functions handle each conversion independently.
- Integer conversion helpers use recursive printing or a small fixed local
  buffer to emit digits in the correct order.
- Hexadecimal conversion uses constant digit strings:
  `"0123456789abcdef"` and `"0123456789ABCDEF"`.

This design is justified by the project constraints. It keeps the mandatory
implementation compact, avoids dynamic data structures for conversions that can
be printed directly, and makes it easy to extend the parser later for bonus
flags, width, and precision.

## Resources

Classic references used for this topic:

- `man 3 printf`
- `man 3 stdarg`
- `man 2 write`
- The C standard library documentation for `printf` formatting rules
- 42 ft_printf subject: `Downloads/en.subject.pdf`

AI usage:

- AI was used to draft and organize this README according to the subject
  requirements.
- AI was used to summarize the project goal, mandatory conversions, build
  instructions, and the algorithm/data-structure explanation.
- AI was not used here to implement, test, or validate the C source code.

---

## Description

`ft_printf` は、標準 C ライブラリの `printf()` 関数を簡易的に再実装する
42 Common Core の C 課題である。

このプロジェクトでは、次の関数を含む静的ライブラリ `libftprintf.a` を作成する。

```c
int	ft_printf(const char *format, ...);
```

この関数は、整形した文字列を標準出力へ書き込み、出力した文字数を返す。
必須変換については libc の `printf()` と比較されるが、元の `printf()` が持つ
バッファ管理までは実装しない。

この課題では主に次の内容を学ぶ。

- フォーマット文字列の解析
- `stdarg.h` を使った可変長引数の扱い
- 整数やポインタの文字列表現への変換
- 42 Norm に従った再利用しやすい C コードの設計

### 必須要件

ライブラリは次の変換指定子に対応する必要がある。

| 変換 | 動作 |
| --- | --- |
| `%c` | 1 文字を出力する。 |
| `%s` | C の一般的な文字列として文字列を出力する。 |
| `%p` | `void *` ポインタを 16 進数形式で出力する。 |
| `%d` | 符号付き 10 進整数を出力する。 |
| `%i` | 符号付き 10 進整数を出力する。 |
| `%u` | 符号なし 10 進整数を出力する。 |
| `%x` | 符号なし整数を小文字の 16 進数で出力する。 |
| `%X` | 符号なし整数を大文字の 16 進数で出力する。 |
| `%%` | パーセント記号を出力する。 |

subject 上の制約は次のとおりである。

- プロジェクトは C で書くこと
- コードは 42 Norm に従うこと
- `cc -Wall -Wextra -Werror` でコンパイルできること
- Makefile には少なくとも `$(NAME)`, `all`, `clean`, `fclean`, `re` を含めること
- 静的ライブラリは `ar` で作成すること。`libtool` は禁止
- `libftprintf.a` をリポジトリのルートに作成すること
- 公開ヘッダーファイル名は `ft_printf.h` にすること
- 使用可能な外部関数は `malloc`, `free`, `write`, `va_start`, `va_arg`,
  `va_copy`, `va_end`
- libft は、`libft/` ディレクトリにソースと Makefile を置き、このプロジェクトの
  Makefile からコンパイルする場合に使用可能

### ボーナス要件

ボーナスは任意である。必須部分が完全に正しく実装されている場合のみ評価される。

subject では次の対応がボーナスとして挙げられている。

- すべての変換における `-`, `0`, `.`, 最小フィールド幅の任意の組み合わせ
- `#`, スペース, `+` の各フラグ

ボーナス用ファイルは、通常 subject の慣例に従って `_bonus.c` や `_bonus.h` を
使う。

## INstruction

### ビルド

リポジトリのルートで次を実行する。

```sh
make
```

成功すると次のファイルが作成される。

```text
libftprintf.a
```

### クリーン

オブジェクトファイルを削除する。

```sh
make clean
```

オブジェクトファイルと静的ライブラリを削除する。

```sh
make fclean
```

最初からビルドし直す。

```sh
make re
```

### 他の C ファイルから使う例

ヘッダーを include する。

```c
#include "ft_printf.h"
```

使用例:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("answer: %d, hex: %x, string: %s\n", 42, 42, "hello");
	return (0);
}
```

ライブラリと一緒にコンパイルする。

```sh
cc -Wall -Wextra -Werror main.c libftprintf.a
```

### Algorithm and Data Structures

採用するアルゴリズムは、フォーマット文字列を左から右へ 1 回走査する方式である。

各文字に対して次の処理を行う。

1. 文字が `%` でなければ、そのまま標準出力へ書き込み、出力文字数を増やす。
2. 文字が `%` であれば、次の文字を変換指定子として確認する。
3. 変換指定子に応じた型で `va_arg` を使い、次の可変長引数を取り出す。
4. 値を変換指定子ごとの小さな出力関数へ渡す。
5. その関数が出力した文字数を合計に加える。

この方式を選ぶ理由は、必須課題では libc の完全なバッファ管理、位置指定引数、
ロケール処理、複雑なフォーマット文法を扱う必要がないためである。線形に解析する
ことで挙動が追いやすくなり、エラー処理も単純になり、不要なメモリ確保も避けられる。

主なデータ構造は意図的に単純にする。

- `va_list` は可変長引数リストの現在位置を保持する。
- 入力の `const char *format` は解析対象のストリームとして扱う。
- 変換指定子ごとに小さなヘルパー関数を用意する。
- 整数変換では、再帰出力または固定長のローカルバッファを使って正しい順序で数字を出力する。
- 16 進数変換では `"0123456789abcdef"` と `"0123456789ABCDEF"` の定数文字列を使う。

この設計は、課題の制約に合っている。必須実装を小さく保てるうえ、直接出力できる
変換に対して不要な動的データ構造を使わずに済む。また、後からボーナスのフラグ、
幅、精度を追加しやすい構成になる。

### 参考資料

このトピックに関する基本的な参考資料:

- `man 3 printf`
- `man 3 stdarg`
- `man 2 write`
- `printf` のフォーマット規則に関する C 標準ライブラリのドキュメント
- 42 ft_printf subject: `Downloads/en.subject.pdf`

AI の使用について:

- AI は、この README を subject 要件に沿って作成、整理するために使用した。
- AI は、プロジェクトの目的、必須変換、ビルド手順、アルゴリズムとデータ構造の説明を
  要約するために使用した。
- この README 作成時点では、C ソースコードの実装、テスト、検証には AI を使用していない。
