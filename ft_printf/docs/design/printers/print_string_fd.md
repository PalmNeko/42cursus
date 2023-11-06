
# print_string_fd

## prototype

```c
int	print_string_fd(int fd, t_conv_specification *cs, va_list args);
```

## return value

成功時: 出力した文字数
失敗時: 負の値

## description

* `%s`用の出力関数。
* fdに文字列として出力する。
* `+`と` `フラグは無視される。
* 精度が指定されている場合は、出力文字数が減る。
