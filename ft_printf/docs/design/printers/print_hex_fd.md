
# print_hex_fd

## prototype

```c
int	print_hex_fd(int fd, t_conv_specification *cs, va_list args);
```

## return value

成功時: 出力した文字数
失敗時: 負の値

## description

* `%x`用の出力関数。
* fdに16進数として出力する。
* 内部的に`unsigned int`に変換される。
* 文字は小文字
* 精度が指定されている場合は、`0`フラグは無視される。
